#' @details Use `LinkingTo: bindrcpp` in `DESCRIPTION` and
#' `#include <bindrcpp.h>` in your C++ headers and/or modules to access the
#' C++ functions provided by this package:
#'
#' - `create_env_string()` creates an environment with active bindings, with
#'    names given as a character vector.  Access of these bindings triggers a
#'    call to a C++ function with a fixed signature (`GETTER_FUNC_STRING`);
#'    this call contains the name of the binding (as character) and an arbitrary
#'    payload (`PAYLOAD`, essentially a wrapped `void*`).
#' - `create_env_symbol()` is similar, the callback function accepts the name of
#'   the binding as symbol instead of character (`GETTER_FUNC_SYMBOL`).
#' - `populate_env_string()` and `populate_env_symbol()` populate an existing
#'   environment instead of creating a new one.
"_PACKAGE"

#' @useDynLib bindrcpp
#' @importFrom Rcpp sourceCpp
#' @importFrom bindr create_env populate_env
NULL
