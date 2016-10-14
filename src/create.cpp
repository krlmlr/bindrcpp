#include <Rcpp.h>

#include <RcppActiveBinding.h>

using namespace Rcpp;

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
SEXP create_environment(CharacterVector names, XPtr<GETTER_FUNC> fun, XPtr<void*> payload, Environment parent) {
  List fun_payload(2);
  fun_payload[0] = fun;
  fun_payload[1] = payload;
  fun_payload.names() = CharacterVector("fun", "payload");

  Environment package("package:RcppActiveBinding");
  Function create_callback_environment = package["create_callback_environment"];

  return create_callback_environment(names, fun_payload, parent);
}

// [[Rcpp::interfaces(r)]]
// [[Rcpp::export]]
SEXP callback(String name, List fun_payload) {
  XPtr<GETTER_FUNC> funx = fun_payload["fun"];
  XPtr<void*> payload = fun_payload["payload"];

  GETTER_FUNC fun = reinterpret_cast<GETTER_FUNC>(funx.get());
  return fun(name, payload);
}
