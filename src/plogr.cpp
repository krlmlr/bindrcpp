#include <plogr.h>

//' Enable internal logging
//'
//' Log entries, depending on the log level, will be printed to the standard
//' error stream.
//'
//' @param log_level A character value, one of "WARN", "INFO", "DEBUG", "VERB",
//'   or "NONE".
//'
//' @keywords internal
// [[Rcpp::export]]
void init_logging(const std::string& log_level) {
  plog::init_r(log_level);
}
