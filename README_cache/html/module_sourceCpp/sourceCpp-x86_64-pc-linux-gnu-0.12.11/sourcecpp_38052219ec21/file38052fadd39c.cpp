#include <Rcpp.h>

// [[Rcpp::depends(bindrcpp)]]
#include <bindrcpp.h>

#include <algorithm>
#include <string>

using namespace Rcpp;

using namespace bindrcpp;

SEXP tolower_callback(const String& name, PAYLOAD) {
  std::string name_string = name;
  std::transform(name_string.begin(), name_string.end(), name_string.begin(), ::tolower);
  return CharacterVector(name_string);
}

// [[Rcpp::export]]
SEXP test_tolower_bindings(CharacterVector names, Environment parent) {
  // We don't pass any payload here
  return bindrcpp::create_env_string(
    names, &tolower_callback, PAYLOAD(NULL), parent);
}


#include <Rcpp.h>
// test_tolower_bindings
SEXP test_tolower_bindings(CharacterVector names, Environment parent);
RcppExport SEXP sourceCpp_1_test_tolower_bindings(SEXP namesSEXP, SEXP parentSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type names(namesSEXP);
    Rcpp::traits::input_parameter< Environment >::type parent(parentSEXP);
    rcpp_result_gen = Rcpp::wrap(test_tolower_bindings(names, parent));
    return rcpp_result_gen;
END_RCPP
}
