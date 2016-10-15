create_callback_environment <- function(names, fun_payload, parent) {
  create_environment(names, callback, fun_payload, parent = parent)
}

create_environment <- function(names, fun, ..., parent = parent.frame()) {
  env <- new.env(parent = parent, size = length(names))
  lapply(names, function(name) {
    makeActiveBinding(as.name(name), new_active_binding_fun(name, fun, ...), env)
  })

  env
}

new_active_binding_fun <- function(name, fun, ...) {
  force(name)
  list(...)
  eval(bquote(function(value) {
    if (!missing(value)) {
      stop("Binding is read-only.", call. = FALSE)
    }
    fun(.(name), ...)
  }))
}
