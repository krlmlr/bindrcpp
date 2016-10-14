## RcppActiveBinding 0.0-2 (2016-10-15)

- Now also works when package is loaded by R and not `devtools`.

## RcppActiveBinding 0.0-1 (2016-10-15)

- Initial release
- No R functions exported
- Exporting C++ function `create_environment()` that populates an environment with active bindings that link back to a C++ function (given as function pointer with payload).

