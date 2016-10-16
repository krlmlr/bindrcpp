#ifndef _bindrcpp_bindrcpp_types_H_
#define _bindrcpp_bindrcpp_types_H_

#include <RcppCommon.h>

#include <Rcpp.h>

namespace bindrcpp {

struct PAYLOAD { void* p; explicit PAYLOAD(void* p_) : p(p_) {}; };
typedef SEXP (*GETTER_FUNC_STRING)(const Rcpp::String& name, bindrcpp::PAYLOAD payload);
typedef SEXP (*GETTER_FUNC_SYMBOL)(const Rcpp::Symbol& name, bindrcpp::PAYLOAD payload);

}

namespace Rcpp {
  template <> SEXP wrap(const bindrcpp::PAYLOAD&);
  template <> SEXP wrap(const bindrcpp::GETTER_FUNC_STRING&);
  template <> SEXP wrap(const bindrcpp::GETTER_FUNC_SYMBOL&);
  template <> bindrcpp::PAYLOAD as(SEXP);
  template <> bindrcpp::GETTER_FUNC_STRING as(SEXP);
  template <> bindrcpp::GETTER_FUNC_SYMBOL as(SEXP);
}

#endif
