#ifndef _bindrcpp_bindrcpp_types_H_
#define _bindrcpp_bindrcpp_types_H_

#include <Rcpp.h>

namespace bindrcpp {

typedef void* PAYLOAD;
typedef SEXP (*GETTER_FUNC)(Rcpp::String name, bindrcpp::PAYLOAD payload);

}

#endif
