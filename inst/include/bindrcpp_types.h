#ifndef _bindrcpp_bindrcpp_types_H_
#define _bindrcpp_bindrcpp_types_H_

#include <RcppCommon.h>

#include <Rcpp.h>

#include <plogr.h>

namespace bindrcpp {

struct PAYLOAD {
  void* p;
  PAYLOAD() {
    LOG_VERBOSE;
  }
  explicit PAYLOAD(void* p_) : p(p_) {
    LOG_VERBOSE << "PAYLOAD()\n";
  }
  ~PAYLOAD() {
    LOG_VERBOSE << "~PAYLOAD()\n";
  }
};
typedef SEXP (*GETTER_FUNC_STRING)(const Rcpp::String& name, bindrcpp::PAYLOAD payload);
typedef SEXP (*GETTER_FUNC_SYMBOL)(const Rcpp::Symbol& name, bindrcpp::PAYLOAD payload);

}

namespace Rcpp {
  using namespace bindrcpp;

  template <> inline SEXP wrap(const PAYLOAD& payload) {
    LOG_VERBOSE << "wrap(PAYLOAD)\n";
    return List::create(XPtr<PAYLOAD>(new PAYLOAD(payload)));
  }
  template <> inline SEXP wrap(const GETTER_FUNC_STRING& fun) {
    LOG_VERBOSE << "wrap(GETTER_FUNC_STRING)\n";
    return List::create(XPtr<GETTER_FUNC_STRING>(new GETTER_FUNC_STRING(fun)));
  }
  template <> inline SEXP wrap(const GETTER_FUNC_SYMBOL& fun) {
    LOG_VERBOSE << "wrap(GETTER_FUNC_SYMBOL)\n";
    return List::create(XPtr<GETTER_FUNC_SYMBOL>(new GETTER_FUNC_SYMBOL(fun)));
  }
  template <> inline PAYLOAD as(SEXP x) {
    LOG_VERBOSE << "PAYLOAD as()\n";
    SEXP x0 = VECTOR_ELT(x, 0);
    return *(PAYLOAD*)R_ExternalPtrAddr(x0);
  }
  template <> inline GETTER_FUNC_STRING as(SEXP x) {
    LOG_VERBOSE << "GETTER_FUNC_STRING as()\n";
    SEXP x0 = VECTOR_ELT(x, 0);
    return *(GETTER_FUNC_STRING*)R_ExternalPtrAddr(x0);
  }
  template <> inline GETTER_FUNC_SYMBOL as(SEXP x) {
    LOG_VERBOSE << "GETTER_FUNC_SYMBOL as()\n";
    SEXP x0 = VECTOR_ELT(x, 0);
    return *(GETTER_FUNC_SYMBOL*)R_ExternalPtrAddr(x0);
  }
}

#endif
