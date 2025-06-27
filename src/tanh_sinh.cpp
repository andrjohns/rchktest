#include <cpp11.hpp>
#include <cpp11/declarations.hpp>
#include <boost/math/quadrature/tanh_sinh.hpp>
#include <cmath>

extern "C" {
  SEXP tanh_sinh_() {
    BEGIN_CPP11
      auto func = [](double x) {
        return std::log(x)*std::log1p(-x);
      };

      boost::math::quadrature::tanh_sinh<double> integrator;
      double result = integrator.integrate(func, 0, 1);

      return cpp11::as_sexp(result);
    END_CPP11
  }
}
