#include <Rcpp.h>

#include <bindrcpp.h>

#include <plogr.h>

using namespace Rcpp;

Environment pkg_env = Environment::namespace_env("bindrcpp");
Function R_create_env("create_env", pkg_env);
Function R_populate_env("populate_env", pkg_env);
Function R_callback("callback", pkg_env);

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export(create_env)]]
Environment create_env_imp(CharacterVector names, bindrcpp::GETTER_FUNC fun, bindrcpp::PAYLOAD payload, Environment enclos) {
  using namespace bindrcpp;

  LOG_VERBOSE << payload.p;
  return R_create_env(names, R_callback, wrap(fun), wrap(payload), _[".enclos"] = enclos);
}

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export(populate_env)]]
Environment populate_env_imp(Environment env, CharacterVector names, bindrcpp::GETTER_FUNC fun, bindrcpp::PAYLOAD payload) {
  using namespace bindrcpp;

  LOG_VERBOSE << payload.p;
  return R_populate_env(env, names, R_callback, wrap(fun), wrap(payload));
}
