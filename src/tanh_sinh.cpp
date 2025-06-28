#include <Rcpp.h>
#include <boost/math/quadrature/tanh_sinh.hpp>
#include <cmath>

extern "C" {
  SEXP tanh_sinh_() {
    BEGIN_RCPP

    auto func = [](double x) { return std::log(x)*std::log1p(-x); };

    boost::math::quadrature::tanh_sinh<double> integrator;
    double result = integrator.integrate(func, 0, 1);

    return Rcpp::wrap(result);

    END_RCPP
  }
}
