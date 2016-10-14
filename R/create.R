create_environment <- function(names, fun, parent = parent.frame()) {
  env <- new.env(parent = parent, size = length(names))
  lapply(names, function(name) {
    makeActiveBinding(as.name(name), new_active_binding_fun(name, fun), env)
  })

  env
}

new_active_binding_fun <- function(name, fun) {
  force(name)
  eval(bquote(function(value) {
    if (!missing(value)) {
      stop("Binding is read-only.")
    }
    fun(.(name))
  }))
}
