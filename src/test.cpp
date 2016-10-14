#include <Rcpp.h>

#include <RcppActiveBinding.h>

#include <plogr.h>

#include <algorithm>
#include <string>

using namespace Rcpp;

// [[Rcpp::export]]
SEXP callback(String name, List fun_payload) {
  XPtr<GETTER_FUNC> xfun = fun_payload["fun"];
  XPtr<PAYLOAD> xpayload = fun_payload["payload"];

  GETTER_FUNC* pfun = xfun.get();
  PAYLOAD* payload = xpayload.get();

  LOG_VERBOSE << payload;

  return (*pfun)(name, *payload);
}

class CallbackTester {
  enum { MAGIC = 20161014 };
  const int magic;

public:
  CallbackTester() : magic(MAGIC) { LOG_VERBOSE; }
  ~CallbackTester() { LOG_VERBOSE; }

  static SEXP tolower_static(Rcpp::String name, PAYLOAD payload) {
    LOG_VERBOSE << payload;
    CallbackTester* this_ = reinterpret_cast<CallbackTester*>(payload);
    return this_->tolower(name);
  }

  static SEXP toupper_static(Rcpp::String name, PAYLOAD payload) {
    LOG_VERBOSE << payload;
    CallbackTester* this_ = reinterpret_cast<CallbackTester*>(payload);
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
    PAYLOAD* ppayload = new PAYLOAD(&c);
    LOG_VERBOSE << ppayload;

    return RcppActiveBinding::create_environment(
      names, XPtr<GETTER_FUNC>(new GETTER_FUNC(&CallbackTester::tolower_static)),
      XPtr<PAYLOAD>(ppayload), parent);
  }
  else if (xform == "toupper") {
    PAYLOAD* ppayload = new PAYLOAD(&c);
    LOG_VERBOSE << ppayload;

    return RcppActiveBinding::create_environment(
      names, XPtr<GETTER_FUNC>(new GETTER_FUNC(&CallbackTester::toupper_static)),
      XPtr<PAYLOAD>(ppayload), parent);
  }
  else
    stop("unknown xform");
}
