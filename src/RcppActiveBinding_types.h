#ifndef _RcppActiveBinding_RcppActiveBinding_types_H_
#define _RcppActiveBinding_RcppActiveBinding_types_H_

#include <Rcpp.h>

typedef SEXP (*GETTER_FUNC)(Rcpp::String name, void* payload);

#endif
