#include <Rcpp.h>

#include <bindrcpp.h>

#include <plogr.h>

#include <algorithm>
#include <string>

using namespace Rcpp;

using namespace bindrcpp;

// [[Rcpp::export(rng = FALSE)]]
SEXP callback_string(Symbol name, bindrcpp::GETTER_FUNC_STRING fun, bindrcpp::PAYLOAD payload) {
  LOG_VERBOSE << type2name(name);
  LOG_VERBOSE << payload.p;

  String name_string = name.c_str();
  name_string.set_encoding(CE_NATIVE);

  return fun(name_string, payload);
}

// [[Rcpp::export(rng = FALSE)]]
SEXP callback_symbol(Symbol name, bindrcpp::GETTER_FUNC_SYMBOL fun, bindrcpp::PAYLOAD payload) {
  LOG_VERBOSE << type2name(name);
  LOG_VERBOSE << payload.p;

  return fun(name, payload);
}

class CallbackTester {
  enum { MAGIC = 20161014 };
  const int magic;

public:
  CallbackTester() : magic(MAGIC) { LOG_VERBOSE; }
  ~CallbackTester() { LOG_VERBOSE; }

  static SEXP tolower_static(const Rcpp::String& name, PAYLOAD payload) {
    LOG_VERBOSE << payload.p;
    CallbackTester* this_ = reinterpret_cast<CallbackTester*>(payload.p);
    return this_->tolower(name);
  }

  static SEXP toupper_static(const Rcpp::String& name, PAYLOAD payload) {
    LOG_VERBOSE << payload.p;
    CallbackTester* this_ = reinterpret_cast<CallbackTester*>(payload.p);
    return this_->toupper(name);
  }

private:
  SEXP tolower(Rcpp::String name) {
    LOG_VERBOSE << magic;
    if (magic != MAGIC)
      stop("payload lost");
    std::string name_string = name;
    std::transform(name_string.begin(), name_string.end(), name_string.begin(), ::tolower);
    return CharacterVector(name_string);
  }

  SEXP toupper(Rcpp::String name) {
    LOG_VERBOSE << magic;
    if (magic != MAGIC)
      stop("payload lost");
    std::string name_string = name;
    std::transform(name_string.begin(), name_string.end(), name_string.begin(), ::toupper);
    return CharacterVector(name_string);
  }
};

// [[Rcpp::export]]
List do_test_create_environment(CharacterVector names, String xform, Environment parent) {
  CallbackTester* pc = new CallbackTester;

  List ret = List::create(_["callback"] = XPtr<CallbackTester>(pc));

  if (xform == "tolower") {
    ret["env"] = bindrcpp::create_env_string(
      names, &CallbackTester::tolower_static, PAYLOAD(pc), parent);
  }
  else if (xform == "toupper") {
    ret["env"] = bindrcpp::create_env_string(
      names, &CallbackTester::toupper_static, PAYLOAD(pc), parent);
  }
  else
    stop("unknown xform");

  return ret;
}
