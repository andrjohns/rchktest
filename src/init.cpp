#include <Rinternals.h>
#include <R_ext/Visibility.h>

extern "C" {
  SEXP tanh_sinh_();

  static const R_CallMethodDef CallEntries[] = {
    {"tanh_sinh_", (DL_FUNC) &tanh_sinh_, 0},
    {NULL, NULL, 0}
  };

  attribute_visible void R_init_rchktest(DllInfo* dll){
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
    R_forceSymbols(dll, TRUE);
  }
}
