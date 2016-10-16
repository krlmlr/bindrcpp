#include <Rcpp.h>

#include <bindrcpp.h>

#include <plogr.h>

using namespace bindrcpp;

namespace Rcpp {

  template <> SEXP wrap(const PAYLOAD& payload) {
    LOG_VERBOSE;
    return XPtr<PAYLOAD>(new PAYLOAD(payload));
  }
  template <> SEXP wrap(const GETTER_FUNC_STRING& fun) {
    LOG_VERBOSE;
    return XPtr<GETTER_FUNC_STRING>(new GETTER_FUNC_STRING(fun));
  }
  template <> SEXP wrap(const GETTER_FUNC_SYMBOL& fun) {
    LOG_VERBOSE;
    return XPtr<GETTER_FUNC_SYMBOL>(new GETTER_FUNC_SYMBOL(fun));
  }
  template <> PAYLOAD as(SEXP x) {
    LOG_VERBOSE << type2name(x);
    XPtr<PAYLOAD> xpayload(x);
    return *xpayload.get();
  }
  template <> GETTER_FUNC_STRING as(SEXP x) {
    LOG_VERBOSE << type2name(x);
    XPtr<GETTER_FUNC_STRING> xfun(x);
    return *xfun.get();
  }
  template <> GETTER_FUNC_SYMBOL as(SEXP x) {
    LOG_VERBOSE << type2name(x);
    XPtr<GETTER_FUNC_SYMBOL> xfun(x);
    return *xfun.get();
  }

}
