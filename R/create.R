create_callback_environment <- function(names, fun_payload, parent) {
  force(fun_payload)
  callback_fun <- function(name) callback(name, fun_payload)
  create_environment(names, callback_fun, parent = parent)
}

create_environment <- function(names, fun, ..., parent = parent.frame()) {
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
      stop("Binding is read-only.", call. = FALSE)
    }
    fun(.(name))
  }))
}
