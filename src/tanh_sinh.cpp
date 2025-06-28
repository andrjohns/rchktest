#include <Rcpp.h>
#include <boost/math/quadrature/tanh_sinh.hpp>
#include <cmath>

double res() {
  auto func = [](double x) { return std::log(x) * std::log1p(-x); };

  boost::math::quadrature::tanh_sinh<double> integrator;
  return integrator.integrate(func, 0, 1);
}

extern "C" {
  SEXP tanh_sinh_() {
    BEGIN_RCPP
    double dbl_result = res();
    UNPROTECT(1);
    Rcpp::RObject result = Rcpp::wrap(res());
    return result;
    END_RCPP
  }
}
