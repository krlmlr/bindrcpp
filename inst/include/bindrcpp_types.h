#ifndef _bindrcpp_bindrcpp_types_H_
#define _bindrcpp_bindrcpp_types_H_

#include <RcppCommon.h>

namespace Rcpp {
  class String;
}

namespace bindrcpp {

struct PAYLOAD { void* p; explicit PAYLOAD(void* p_) : p(p_) {}; };
typedef SEXP (*GETTER_FUNC)(const Rcpp::String& name, bindrcpp::PAYLOAD payload);

}

namespace Rcpp {
  template <> SEXP wrap(const bindrcpp::PAYLOAD& payload);
  template <> SEXP wrap(const bindrcpp::GETTER_FUNC&);
  template <> bindrcpp::PAYLOAD as(SEXP);
  template <> bindrcpp::GETTER_FUNC as(SEXP);
}

#include <Rcpp.h>

#endif
