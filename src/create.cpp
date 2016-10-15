#include <Rcpp.h>

#include <RcppActiveBinding.h>

#include <plogr.h>

using namespace Rcpp;

Function getNamespace = Function("getNamespace", Environment("package:base"));
Function R_create_environment = Environment(getNamespace("RcppActiveBinding"))["create_environment"];
Function R_callback = Environment(getNamespace("RcppActiveBinding"))["callback"];

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
SEXP create_environment(CharacterVector names, XPtr<GETTER_FUNC> fun, XPtr<PAYLOAD> payload, Environment parent) {
  List fun_payload = List::create(_["fun"] = fun, _["payload"] = payload);
  LOG_VERBOSE << payload.get();

  return R_create_environment(names, R_callback, fun_payload, _["parent"] = parent);
}
