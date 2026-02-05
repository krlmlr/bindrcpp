#include <Rcpp.h>

#include <bindrcpp.h>

#include <algorithm>
#include <string>

using namespace Rcpp;

using namespace bindrcpp;

// [[Rcpp::export(rng = FALSE)]]
SEXP callback_string_typed(
  Symbol name,
  bindrcpp::GETTER_FUNC_STRING_TYPED fun,
  bindrcpp::PAYLOAD payload
) {
  String name_string = name.c_str();
  name_string.set_encoding(CE_NATIVE);

  return fun(name_string, payload);
}

// [[Rcpp::export(rng = FALSE)]]
SEXP callback_symbol_typed(
  Symbol name,
  bindrcpp::GETTER_FUNC_SYMBOL_TYPED fun,
  bindrcpp::PAYLOAD payload
) {
  return fun(name, payload);
}

// [[Rcpp::export(rng = FALSE)]]
SEXP callback_string_wrapped(
  Symbol name,
  bindrcpp::GETTER_FUNC_STRING_WRAPPED fun,
  List payload
) {
  String name_string = name.c_str();
  name_string.set_encoding(CE_NATIVE);

  return fun(name_string, payload);
}

// [[Rcpp::export(rng = FALSE)]]
SEXP callback_symbol_wrapped(
  Symbol name,
  bindrcpp::GETTER_FUNC_SYMBOL_WRAPPED fun,
  List payload
) {
  return fun(name, payload);
}

class CallbackTester {
  enum { MAGIC = 20161014 };
  const int magic;

public:
  CallbackTester() : magic(MAGIC) {}
  ~CallbackTester() {}

  static SEXP tolower_static(const Rcpp::String& name, List payload) {
    XPtr<CallbackTester> p = payload[0];
    CallbackTester* this_ = p.get();
    return this_->tolower(name);
  }

  static SEXP toupper_static(const Rcpp::String& name, List payload) {
    XPtr<CallbackTester> p = payload[0];
    CallbackTester* this_ = p.get();
    return this_->toupper(name);
  }

private:
  SEXP tolower(Rcpp::String name) {
    if (magic != MAGIC) {
      stop("payload lost");
    }
    std::string name_string = name;
    std::transform(
      name_string.begin(),
      name_string.end(),
      name_string.begin(),
      ::tolower
    );
    return CharacterVector(name_string);
  }

  SEXP toupper(Rcpp::String name) {
    if (magic != MAGIC) {
      stop("payload lost");
    }
    std::string name_string = name;
    std::transform(
      name_string.begin(),
      name_string.end(),
      name_string.begin(),
      ::toupper
    );
    return CharacterVector(name_string);
  }
};

// [[Rcpp::export]]
Environment do_test_create_environment(
  CharacterVector names,
  String xform,
  Environment parent
) {
  List payload =
    List::create(_["callback"] = XPtr<CallbackTester>(new CallbackTester));

  if (xform == "tolower") {
    return bindrcpp::create_env_string_wrapped(
      names,
      &CallbackTester::tolower_static,
      payload,
      parent
    );
  } else if (xform == "toupper") {
    return bindrcpp::create_env_string_wrapped(
      names,
      &CallbackTester::toupper_static,
      payload,
      parent
    );
  } else {
    stop("unknown xform");
  }
}
