#include <Rcpp.h>

#include <bindrcpp.h>

#include <plogr.h>

using namespace Rcpp;

Environment pkg_env = Environment::namespace_env("bindrcpp");
Function R_create_env("create_env", pkg_env);
Function R_populate_env("populate_env", pkg_env);
Function R_callback("callback", pkg_env);

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
SEXP create_env(CharacterVector names, XPtr<GETTER_FUNC> fun, XPtr<PAYLOAD> payload, Environment enclos) {
  LOG_VERBOSE << payload.get();
  return R_create_env(names, R_callback, fun, payload, _[".enclos"] = enclos);
}

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
SEXP populate_env(Environment env, CharacterVector names, XPtr<GETTER_FUNC> fun, XPtr<PAYLOAD> payload) {
  LOG_VERBOSE << payload.get();
  return R_populate_env(env, names, R_callback, fun, payload);
}
