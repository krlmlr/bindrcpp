#include <Rcpp.h>

#include <bindrcpp.h>

#include <plogr.h>

using namespace bindrcpp;

namespace Rcpp {

  template <> SEXP wrap(const PAYLOAD& payload) {
    LOG_VERBOSE;
    return XPtr<PAYLOAD>(new PAYLOAD(payload));
  }
  template <> SEXP wrap(const GETTER_FUNC& fun) {
    LOG_VERBOSE;
    return XPtr<GETTER_FUNC>(new GETTER_FUNC(fun));
  }
  template <> PAYLOAD as(SEXP x) {
    LOG_VERBOSE << type2name(x);
    XPtr<PAYLOAD> xpayload(x);
    return *xpayload.get();
  }
  template <> GETTER_FUNC as(SEXP x) {
    LOG_VERBOSE << type2name(x);
    XPtr<GETTER_FUNC> xfun(x);
    return *xfun.get();
  }

}
