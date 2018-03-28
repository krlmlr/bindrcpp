
<!-- README.md is generated from README.Rmd. Please edit that file -->
bindrcpp
========

[![Travis-CI Build Status](https://travis-ci.org/krlmlr/bindrcpp.svg?branch=master)](https://travis-ci.org/krlmlr/bindrcpp) [![AppVeyor Build Status](https://ci.appveyor.com/api/projects/status/github/krlmlr/bindrcpp?branch=master&svg=true)](https://ci.appveyor.com/project/krlmlr/bindrcpp) [![CRAN\_Status\_Badge](http://www.r-pkg.org/badges/version/bindrcpp)](https://cran.r-project.org/package=bindrcpp)

It's easy to create active bindings in R via [`makeActiveBinding()`](https://www.rdocumentation.org/packages/base/versions/3.3.1/topics/bindenv). This package faciliates the creation of active bindings that link back to C++ code. It provides an interface that allows binding several identifiers in an environment to the same C++ function, which is then called with the name (and a payload) as argument.

It is recommended to use the newer `_wrapped` functions that support passing an arbitrary `Rcpp::List` as payload. This allows to store an `Rcpp::XPtr` to a C++ object in that list. The `XPtr` then will be released when the payload is garbage-collected, and the C++ object will be destroyed.

Installation
------------

You can install bindrcpp from github with:

``` r
# install.packages("devtools")
devtools::install_github("krlmlr/bindrcpp")
```

Example
-------

The following C++ module exports a function `test_tolower_bindings()` that creates active bindings that return the binding name in lowercase.

``` cpp
#include <Rcpp.h>

// [[Rcpp::depends(bindrcpp)]]
#include <bindrcpp.h>

#include <algorithm>
#include <string>

using namespace Rcpp;

using namespace bindrcpp;

SEXP tolower_callback(const String& name, PAYLOAD) {
  std::string name_string = name;
  std::transform(name_string.begin(), name_string.end(), name_string.begin(), ::tolower);
  return CharacterVector(name_string);
}

// [[Rcpp::export]]
SEXP test_tolower_bindings(CharacterVector names, Environment parent) {
  // We don't pass any payload here
  return bindrcpp::create_env_string(
    names, &tolower_callback, PAYLOAD(NULL), parent);
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
