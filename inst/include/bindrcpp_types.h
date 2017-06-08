#ifndef _bindrcpp_bindrcpp_types_H_
#define _bindrcpp_bindrcpp_types_H_

#include <RcppCommon.h>

#include <Rcpp.h>

#include <plogr.h>

namespace bindrcpp {

struct PAYLOAD { void* p; explicit PAYLOAD(void* p_) : p(p_) {}; };
typedef SEXP (*GETTER_FUNC_STRING)(const Rcpp::String& name, bindrcpp::PAYLOAD payload);
typedef SEXP (*GETTER_FUNC_SYMBOL)(const Rcpp::Symbol& name, bindrcpp::PAYLOAD payload);

namespace internal {

struct GETTER_FUNC_STRING_WRAP {
  GETTER_FUNC_STRING p;

  explicit GETTER_FUNC_STRING_WRAP(GETTER_FUNC_STRING p_) : p(p_) {
    LOG_VERBOSE;
  }

  GETTER_FUNC_STRING_WRAP(const GETTER_FUNC_STRING_WRAP& p_) : p(p_.p) {
    LOG_VERBOSE;
  }

  ~GETTER_FUNC_STRING_WRAP() {
    LOG_VERBOSE;
  }
};

struct GETTER_FUNC_SYMBOL_WRAP {
  GETTER_FUNC_SYMBOL p;

  explicit GETTER_FUNC_SYMBOL_WRAP(GETTER_FUNC_SYMBOL p_) : p(p_) {
    LOG_VERBOSE;
  }

  GETTER_FUNC_SYMBOL_WRAP(const GETTER_FUNC_SYMBOL_WRAP& p_) : p(p_.p) {
    LOG_VERBOSE;
  }

  ~GETTER_FUNC_SYMBOL_WRAP() {
    LOG_VERBOSE;
  }
};

} // namespace internal

} // namespace bindrcpp

namespace Rcpp {
  using namespace bindrcpp;

  using namespace bindrcpp::internal;

  template <> inline SEXP wrap(const PAYLOAD& payload) {
    LOG_VERBOSE << "wrap(PAYLOAD)\n";
    return List::create(XPtr<PAYLOAD>(new PAYLOAD(payload)));
  }
  template <> inline SEXP wrap(const GETTER_FUNC_STRING& fun) {
    LOG_VERBOSE << "wrap(GETTER_FUNC_STRING)\n";
    SEXP ret = List::create(XPtr<GETTER_FUNC_STRING_WRAP>(new GETTER_FUNC_STRING_WRAP(fun)));
    LOG_VERBOSE << "wrap(GETTER_FUNC_STRING) done\n";
    return ret;
  }
  template <> inline SEXP wrap(const GETTER_FUNC_SYMBOL& fun) {
    LOG_VERBOSE << "wrap(GETTER_FUNC_SYMBOL)\n";
    SEXP ret = List::create(XPtr<GETTER_FUNC_SYMBOL_WRAP>(new GETTER_FUNC_SYMBOL_WRAP(fun)));
    LOG_VERBOSE << "wrap(GETTER_FUNC_SYMBOL) done\n";
    return ret;
  }
  template <> inline PAYLOAD as(SEXP x) {
    List xl = x;
    XPtr<PAYLOAD> xpayload(static_cast<SEXP>(xl[0]));
    return *xpayload.get();
  }
  template <> inline GETTER_FUNC_STRING as(SEXP x) {
    LOG_VERBOSE << "GETTER_FUNC_STRING as()\n";
    SEXP x0 = VECTOR_ELT(x, 0);
    GETTER_FUNC_STRING_WRAP* p = (GETTER_FUNC_STRING_WRAP*)R_ExternalPtrAddr(x0);
    return p->p;
  }
  template <> inline GETTER_FUNC_SYMBOL as(SEXP x) {
    LOG_VERBOSE << "GETTER_FUNC_SYMBOL as()\n";
    SEXP x0 = VECTOR_ELT(x, 0);
    GETTER_FUNC_SYMBOL_WRAP* p = (GETTER_FUNC_SYMBOL_WRAP*)R_ExternalPtrAddr(x0);
    return p->p;
  }
}

#endif
