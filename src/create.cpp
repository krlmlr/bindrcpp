#include <Rcpp.h>

#include <RcppActiveBinding.h>

using namespace Rcpp;

typedef SEXP (*GETTER_FUNC)(String name, void* payload);

// [Rcpp::export]
// [[Rcpp::interfaces(cpp)]]
SEXP create_environment(CharacterVector names, GETTER_FUNC fun, void* payload, Environment parent) {
  return R_NilValue;
}
