## bindrcpp 0.0-7 (2016-10-16)

- Conversion functions `as()` and `wrap()` are available in the included files.
- Use AppVeyor.
- Update README.


## bindrcpp 0.0-6 (2016-10-16)

- Provide callbacks for both `String` and `Symbol`.


## bindrcpp 0.0-5 (2016-10-16)

- Reexport functions from `bindr`.
- Place C++ types in namespace.
- Simplify interfaces, provide `as()` and `wrap()` for types.


## bindrcpp 0.0-4 (2016-10-16)

- Rename to `bindrcpp`.
- New `populate_env()`.


## bindrcpp 0.0-3 (2016-10-16)

- Use new `bindr` package.
- Function is called `create_env()`.


## bindrcpp 0.0-2 (2016-10-15)

- Now also works when package is loaded by R and not `devtools`.
 

## bindrcpp 0.0-1 (2016-10-15)

- Initial release
- No R functions exported
- Exporting C++ function `create_environment()` that populates an environment with active bindings that link back to a C++ function (given as function pointer with payload).

