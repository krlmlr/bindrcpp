#ifndef _bindrcpp_bindrcpp_types_H_
#define _bindrcpp_bindrcpp_types_H_

#include <RcppCommon.h>

#include <Rcpp.h>

namespace bindrcpp {

struct PAYLOAD { void* p; explicit PAYLOAD(void* p_) : p(p_) { std::cerr << "PAYLOAD()\n"; }; ~PAYLOAD() { std::cerr << "~PAYLOAD()\n"; } };
typedef SEXP (*GETTER_FUNC_STRING)(const Rcpp::String& name, bindrcpp::PAYLOAD payload);
typedef SEXP (*GETTER_FUNC_SYMBOL)(const Rcpp::Symbol& name, bindrcpp::PAYLOAD payload);

}

namespace Rcpp {
  using namespace bindrcpp;

  template <> inline SEXP wrap(const PAYLOAD& payload) {
    std::cerr << "wrap(PAYLOAD)\n";
    return List::create(XPtr<PAYLOAD>(new PAYLOAD(payload)));
  }
  template <> inline SEXP wrap(const GETTER_FUNC_STRING& fun) {
    std::cerr << "wrap(GETTER_FUNC_STRING)\n";
    return List::create(XPtr<GETTER_FUNC_STRING>(new GETTER_FUNC_STRING(fun)));
  }
  template <> inline SEXP wrap(const GETTER_FUNC_SYMBOL& fun) {
    std::cerr << "wrap(GETTER_FUNC_SYMBOL)\n";
    return List::create(XPtr<GETTER_FUNC_SYMBOL>(new GETTER_FUNC_SYMBOL(fun)));
  }
  template <> inline PAYLOAD as(SEXP x) {
    List xl = x;
    std::cerr << "PAYLOAD as()\n";
    return *(PAYLOAD*)R_ExternalPtrAddr(xl[0]);
  }
  template <> inline GETTER_FUNC_STRING as(SEXP x) {
    List xl = x;
    std::cerr << "GETTER_FUNC_STRING as()\n";
    return *(GETTER_FUNC_STRING*)R_ExternalPtrAddr(xl[0]);
  }
  template <> inline GETTER_FUNC_SYMBOL as(SEXP x) {
    List xl = x;
    std::cerr << "GETTER_FUNC_SYMBOL as()\n";
    return *(GETTER_FUNC_SYMBOL*)R_ExternalPtrAddr(xl[0]);
  }
}

#endif
