#include <Rcpp.h>

#include <bindrcpp.h>

#include <plogr.h>

using namespace Rcpp;

Environment pkg_env = Environment::namespace_env("bindrcpp");
Function R_create_env("create_env", pkg_env);
Function R_populate_env("populate_env", pkg_env);
Function R_callback_string_typed("callback_string_typed", pkg_env);
Function R_callback_symbol_typed("callback_symbol_typed", pkg_env);
Function R_callback_string_wrapped("callback_string_wrapped", pkg_env);
Function R_callback_symbol_wrapped("callback_symbol_wrapped", pkg_env);

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export(create_env_string_typed)]]
Environment create_env_string_typed_imp(CharacterVector names, bindrcpp::GETTER_FUNC_STRING_TYPED fun, bindrcpp::PAYLOAD payload, Environment enclos) {
  using namespace bindrcpp;

  LOG_VERBOSE << payload.p;
  return R_create_env(names, R_callback_string_typed, fun, payload, _[".enclos"] = enclos);
}

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export(populate_env_string_typed)]]
Environment populate_env_string_typed_imp(Environment env, CharacterVector names, bindrcpp::GETTER_FUNC_STRING_TYPED fun, bindrcpp::PAYLOAD payload) {
  using namespace bindrcpp;

  LOG_VERBOSE << payload.p;
  return R_populate_env(env, names, R_callback_string_typed, fun, payload);
}

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export(create_env_symbol_typed)]]
Environment create_env_symbol_typed_imp(CharacterVector names, bindrcpp::GETTER_FUNC_SYMBOL_TYPED fun, bindrcpp::PAYLOAD payload, Environment enclos) {
  using namespace bindrcpp;

  LOG_VERBOSE << payload.p;
  return R_create_env(names, R_callback_symbol_typed, fun, payload, _[".enclos"] = enclos);
}

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export(populate_env_symbol_typed)]]
Environment populate_env_symbol_typed_imp(Environment env, CharacterVector names, bindrcpp::GETTER_FUNC_SYMBOL_TYPED fun, bindrcpp::PAYLOAD payload) {
  using namespace bindrcpp;

  LOG_VERBOSE << payload.p;
  return R_populate_env(env, names, R_callback_symbol_typed, fun, payload);
}

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export(create_env_string_wrapped)]]
Environment create_env_string_wrapped_imp(CharacterVector names, bindrcpp::GETTER_FUNC_STRING_WRAPPED fun, List payload, Environment enclos) {
  using namespace bindrcpp;

  return R_create_env(names, R_callback_string_wrapped, fun, payload, _[".enclos"] = enclos);
}

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export(populate_env_string_wrapped)]]
Environment populate_env_string_wrapped_imp(Environment env, CharacterVector names, bindrcpp::GETTER_FUNC_STRING_WRAPPED fun, List payload) {
  using namespace bindrcpp;

  return R_populate_env(env, names, R_callback_string_wrapped, fun, payload);
}

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export(create_env_symbol_wrapped)]]
Environment create_env_symbol_wrapped_imp(CharacterVector names, bindrcpp::GETTER_FUNC_SYMBOL_WRAPPED fun, List payload, Environment enclos) {
  using namespace bindrcpp;

  return R_create_env(names, R_callback_symbol_wrapped, fun, payload, _[".enclos"] = enclos);
}

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export(populate_env_symbol_wrapped)]]
Environment populate_env_symbol_wrapped_imp(Environment env, CharacterVector names, bindrcpp::GETTER_FUNC_SYMBOL_WRAPPED fun, List payload) {
  using namespace bindrcpp;

  return R_populate_env(env, names, R_callback_symbol_wrapped, fun, payload);
}
// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export(create_env_string)]]
Environment create_env_string_imp(CharacterVector names, bindrcpp::GETTER_FUNC_STRING fun, bindrcpp::PAYLOAD payload, Environment enclos) {
  return create_env_string_typed_imp(names, fun, payload, enclos);
}

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export(populate_env_string)]]
Environment populate_env_string_imp(Environment env, CharacterVector names, bindrcpp::GETTER_FUNC_STRING fun, bindrcpp::PAYLOAD payload) {
  return populate_env_string_typed_imp(env, names, fun, payload);
}

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export(create_env_symbol)]]
Environment create_env_symbol_imp(CharacterVector names, bindrcpp::GETTER_FUNC_SYMBOL fun, bindrcpp::PAYLOAD payload, Environment enclos) {
  return create_env_symbol_typed_imp(names, fun, payload, enclos);
}

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export(populate_env_symbol)]]
Environment populate_env_symbol_imp(Environment env, CharacterVector names, bindrcpp::GETTER_FUNC_SYMBOL fun, bindrcpp::PAYLOAD payload) {
  return populate_env_symbol_typed_imp(env, names, fun, payload);
}
