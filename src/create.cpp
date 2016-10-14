#include <Rcpp.h>

#include <RcppActiveBinding.h>

#include <plogr.h>

using namespace Rcpp;

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
SEXP create_environment(CharacterVector names, XPtr<GETTER_FUNC> fun, XPtr<PAYLOAD> payload, Environment parent) {
  List fun_payload = List::create(_["fun"] = fun, _["payload"] = payload);
  LOG_VERBOSE << payload.get();

  Environment package("package:RcppActiveBinding");
  Function create_callback_environment = package["create_callback_environment"];

  return create_callback_environment(names, fun_payload, parent);
}
