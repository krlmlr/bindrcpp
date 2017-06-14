#include <Rcpp.h>

#include <bindrcpp.h>

#include <plogr.h>

using namespace Rcpp;

Environment pkg_env = Environment::namespace_env("bindrcpp");
Function R_create_env("create_env", pkg_env);
Function R_populate_env("populate_env", pkg_env);
Function R_callback_string("callback_string", pkg_env);
Function R_callback_symbol("callback_symbol", pkg_env);

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export(create_env_string)]]
Environment create_env_string_imp(CharacterVector names, List fun_and_payload, Environment enclos) {
  using namespace bindrcpp;

  return R_create_env(names, R_callback_string, fun_and_payload, _[".enclos"] = enclos);
}

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export(populate_env_string)]]
Environment populate_env_string_imp(Environment env, CharacterVector names, List fun_and_payload) {
  using namespace bindrcpp;

  return R_populate_env(env, names, R_callback_string, fun_and_payload);
}

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export(create_env_symbol)]]
Environment create_env_symbol_imp(CharacterVector names, List fun_and_payload, Environment enclos) {
  using namespace bindrcpp;

  return R_create_env(names, R_callback_symbol, fun_and_payload, _[".enclos"] = enclos);
}

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export(populate_env_symbol)]]
Environment populate_env_symbol_imp(Environment env, CharacterVector names, List fun_and_payload) {
  using namespace bindrcpp;

  return R_populate_env(env, names, R_callback_symbol, fun_and_payload);
}
