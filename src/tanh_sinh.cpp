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
    double result = res();

    Rcpp::RObject result = Rcpp::wrap(result);

    return result;
    END_RCPP
  }
}
