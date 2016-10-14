#include <Rcpp.h>

#include <RcppActiveBinding.h>

#include <plogr.h>

using namespace Rcpp;

Function getNamespace = Function("getNamespace", Environment("package:base"));
Function create_callback_environment = Environment(getNamespace("RcppActiveBinding"))["create_callback_environment"];

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
SEXP create_environment(CharacterVector names, XPtr<GETTER_FUNC> fun, XPtr<PAYLOAD> payload, Environment parent) {
  List fun_payload = List::create(_["fun"] = fun, _["payload"] = payload);
  LOG_VERBOSE << payload.get();

  return create_callback_environment(names, fun_payload, parent);
}
