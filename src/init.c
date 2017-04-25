#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME: 
Check these declarations against the C/Fortran source code.
*/

/* .Call calls */
extern SEXP cIRT_center_matrix(SEXP);
extern SEXP cIRT_cIRT(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP cIRT_direct_sum(SEXP);
extern SEXP cIRT_Generate_Choice(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP cIRT_probitHLM(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP cIRT_riwishart(SEXP, SEXP);
extern SEXP cIRT_rmvnorm(SEXP, SEXP, SEXP);
extern SEXP cIRT_rwishart(SEXP, SEXP);
extern SEXP cIRT_Total_Tabulate(SEXP, SEXP, SEXP);
extern SEXP cIRT_TwoPLChoicemcmc(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);

static const R_CallMethodDef CallEntries[] = {
  {"cIRT_center_matrix",   (DL_FUNC) &cIRT_center_matrix,    1},
  {"cIRT_cIRT",            (DL_FUNC) &cIRT_cIRT,             8},
  {"cIRT_direct_sum",      (DL_FUNC) &cIRT_direct_sum,       1},
  {"cIRT_Generate_Choice", (DL_FUNC) &cIRT_Generate_Choice, 12},
  {"cIRT_probitHLM",       (DL_FUNC) &cIRT_probitHLM,       19},
  {"cIRT_riwishart",       (DL_FUNC) &cIRT_riwishart,        2},
  {"cIRT_rmvnorm",         (DL_FUNC) &cIRT_rmvnorm,          3},
  {"cIRT_rwishart",        (DL_FUNC) &cIRT_rwishart,         2},
  {"cIRT_Total_Tabulate",  (DL_FUNC) &cIRT_Total_Tabulate,   3},
  {"cIRT_TwoPLChoicemcmc", (DL_FUNC) &cIRT_TwoPLChoicemcmc, 16},
  {NULL, NULL, 0}
};

void R_init_cIRT(DllInfo *dll)
{
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}