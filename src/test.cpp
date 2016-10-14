#include <Rcpp.h>

#include <RcppActiveBinding.h>

#include <algorithm>
#include <string>

using namespace Rcpp;

// [[Rcpp::export]]
SEXP callback(String name, List fun_payload) {
  XPtr<GETTER_FUNC> funx = fun_payload["fun"];
  XPtr<void*> payload = fun_payload["payload"];

  GETTER_FUNC* fun = funx.get();
  return (*fun)(name, payload);
}

// [[Rcpp::export]]
SEXP test_create_environment(CharacterVector names, Environment parent, String xform) {
  class callback {
    enum { MAGIC = 20161014 };

  public:
    callback() : magic(MAGIC) {}

    static SEXP tolower_static(Rcpp::String name, void* payload) {
      callback* this_ = reinterpret_cast<callback*>(payload);
      return this_->tolower(name);
    }

    static SEXP toupper_static(Rcpp::String name, void* payload) {
      callback* this_ = reinterpret_cast<callback*>(payload);
      return this_->toupper(name);
    }

  private:
    SEXP tolower(Rcpp::String name) {
      if (magic != MAGIC)
        stop("payload lost");
      std::string name_string = name;
      std::transform(name_string.begin(), name_string.end(), name_string.begin(), ::tolower);
      return CharacterVector(name);
    }

    SEXP toupper(Rcpp::String name) {
      if (magic != MAGIC)
        stop("payload lost");
      std::string name_string = name;
      std::transform(name_string.begin(), name_string.end(), name_string.begin(), ::toupper);
      return CharacterVector(name);
    }

  private:
    int magic;
  };

  callback c;

  if (xform == "lower") {
    return RcppActiveBinding::create_environment(
      names, XPtr<GETTER_FUNC>(new GETTER_FUNC(&callback::tolower_static)),
      XPtr<void*>(new void*(&c)), parent);
  }
  else if (xform == "upper") {
    return RcppActiveBinding::create_environment(
      names, XPtr<GETTER_FUNC>(new GETTER_FUNC(&callback::toupper_static)),
      XPtr<void*>(new void*(&c)), parent);
  }
  else
    stop("unknown xform");
}
