#include <Rcpp.h>

#include <bindrcpp.h>

#include <plogr.h>

#include <algorithm>
#include <string>

using namespace Rcpp;

using namespace bindrcpp;

// [[Rcpp::export(rng = FALSE)]]
SEXP callback(Symbol name, bindrcpp::GETTER_FUNC fun, bindrcpp::PAYLOAD payload) {
  LOG_VERBOSE << payload.p;

  String name_string = name.c_str();
  name_string.set_encoding(CE_NATIVE);

  return fun(name_string, payload);
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
SEXP do_test_create_environment(CharacterVector names, String xform, Environment parent) {
  CallbackTester* pc = new CallbackTester;

  // HACK: Insert into parent environment to avoid early destruction or memory leaks.
  // A real application would probably store this object elsewhere
  parent["__CALLBACK_STORAGE__"] = XPtr<CallbackTester>(pc);

  CallbackTester& c = *pc;

  if (xform == "tolower") {
    return bindrcpp::create_env(
      names, &CallbackTester::tolower_static, PAYLOAD(&c), parent);
  }
  else if (xform == "toupper") {
    return bindrcpp::create_env(
      names, &CallbackTester::toupper_static, PAYLOAD(&c), parent);
  }
  else
    stop("unknown xform");
}
