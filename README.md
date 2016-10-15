
<!-- README.md is generated from README.Rmd. Please edit that file -->
RcppActiveBinding [![Travis-CI Build Status](https://travis-ci.org/krlmlr/RcppActiveBinding.svg?branch=master)](https://travis-ci.org/krlmlr/RcppActiveBinding)
===============================================================================================================================================================

It's easy to create active bindings in R via [`makeActiveBinding()`](https://www.rdocumentation.org/packages/base/versions/3.3.1/topics/bindenv). This package faciliates the creation of active bindings that link back to C++ code. It provides an interface that allows binding several identifiers in an environment to the same C++ function, which is then called with the name (and a payload) as argument.

Installation
------------

You can install RcppActiveBinding from github with:

``` r
# install.packages("devtools")
devtools::install_github("krlmlr/RcppActiveBinding")
```

Example
-------

The following C++ module exports a function `test_tolower_bindings()` that creates active bindings that return the binding name in lowercase.

``` cpp
#include <Rcpp.h>

// [[Rcpp::depends(RcppActiveBinding)]]
#include <RcppActiveBinding.h>

#include <algorithm>
#include <string>

using namespace Rcpp;

SEXP tolower_callback(String name, PAYLOAD) {
  std::string name_string = name;
  std::transform(name_string.begin(), name_string.end(), name_string.begin(), ::tolower);
  return CharacterVector(name_string);
}

// [[Rcpp::export]]
SEXP test_tolower_bindings(CharacterVector names, Environment parent) {
  // A void* can be passed here, but we don't use this functionality here
  PAYLOAD* payload = new PAYLOAD();
  
  return RcppActiveBinding::create_environment(
    names, XPtr<GETTER_FUNC>(new GETTER_FUNC(&tolower_callback)),
    XPtr<PAYLOAD>(payload), parent);
}
```

This function can be called from R:

``` r
env <- test_tolower_bindings(c("Converting", "to", "LOWERCASE"), .GlobalEnv)
ls(env)
#> [1] "Converting" "LOWERCASE"  "to"
env$Converting
#> [1] "converting"
env$to
#> [1] "to"
env$LOWERCASE
#> [1] "lowercase"
env$y
#> NULL
```

The bindings are read-only:

``` r
env$Converting <- "CONVERTING"
#> Error: Binding is read-only.
```
