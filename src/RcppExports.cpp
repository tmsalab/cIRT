// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// direct_sum
arma::mat direct_sum(arma::field<arma::mat> x);
RcppExport SEXP _cIRT_direct_sum(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::field<arma::mat> >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(direct_sum(x));
    return rcpp_result_gen;
END_RCPP
}
// center_matrix
arma::mat center_matrix(const arma::mat& x);
RcppExport SEXP _cIRT_center_matrix(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(center_matrix(x));
    return rcpp_result_gen;
END_RCPP
}
// TwoPLChoicemcmc
Rcpp::List TwoPLChoicemcmc(/* New Parameters */ const arma::vec& unique_subject_ids, const arma::vec& subject_ids, const arma::vec& choices_nk, const arma::mat& fixed_effects, const arma::vec& B, const arma::mat& rv_effects_design, const arma::vec& gamma, const arma::vec& beta, const arma::mat& zeta_rv, const arma::mat& Sigma_zeta_inv, /* Old Parameters */ const arma::mat& Y, const arma::vec& theta0, const arma::vec& a0, const arma::vec& b0, const arma::vec& mu_xi0, const arma::mat& Sig_xi0);
RcppExport SEXP _cIRT_TwoPLChoicemcmc(SEXP unique_subject_idsSEXP, SEXP subject_idsSEXP, SEXP choices_nkSEXP, SEXP fixed_effectsSEXP, SEXP BSEXP, SEXP rv_effects_designSEXP, SEXP gammaSEXP, SEXP betaSEXP, SEXP zeta_rvSEXP, SEXP Sigma_zeta_invSEXP, SEXP YSEXP, SEXP theta0SEXP, SEXP a0SEXP, SEXP b0SEXP, SEXP mu_xi0SEXP, SEXP Sig_xi0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< /* New Parameters */ const arma::vec& >::type unique_subject_ids(unique_subject_idsSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type subject_ids(subject_idsSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type choices_nk(choices_nkSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type fixed_effects(fixed_effectsSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type B(BSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type rv_effects_design(rv_effects_designSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type zeta_rv(zeta_rvSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type Sigma_zeta_inv(Sigma_zeta_invSEXP);
    Rcpp::traits::input_parameter< /* Old Parameters */ const arma::mat& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type theta0(theta0SEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type a0(a0SEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type b0(b0SEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type mu_xi0(mu_xi0SEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type Sig_xi0(Sig_xi0SEXP);
    rcpp_result_gen = Rcpp::wrap(TwoPLChoicemcmc(unique_subject_ids, subject_ids, choices_nk, fixed_effects, B, rv_effects_design, gamma, beta, zeta_rv, Sigma_zeta_inv, Y, theta0, a0, b0, mu_xi0, Sig_xi0));
    return rcpp_result_gen;
END_RCPP
}
// probitHLM
Rcpp::List probitHLM(const arma::vec& unique_subject_ids, const arma::vec& subject_ids, const arma::vec& choices_nk, const arma::mat& fixed_effects_design, const arma::mat& rv_effects_design, const arma::uvec& B_elem_plus1, const arma::mat& gamma, const arma::vec& beta, const arma::vec& theta, const arma::mat& zeta_rv, /* Trading Memory for Speed */                      const arma::field<arma::mat>& WtW, const arma::vec Z_c, const arma::vec Wzeta_0, /* Bunch of priors */                      const arma::mat& inv_Sigma_gamma, const arma::mat& mu_gamma, const arma::mat& Sigma_zeta_inv, const arma::mat& S0, const arma::vec& mu_beta, const arma::mat& sigma_beta_inv);
RcppExport SEXP _cIRT_probitHLM(SEXP unique_subject_idsSEXP, SEXP subject_idsSEXP, SEXP choices_nkSEXP, SEXP fixed_effects_designSEXP, SEXP rv_effects_designSEXP, SEXP B_elem_plus1SEXP, SEXP gammaSEXP, SEXP betaSEXP, SEXP thetaSEXP, SEXP zeta_rvSEXP, SEXP WtWSEXP, SEXP Z_cSEXP, SEXP Wzeta_0SEXP, SEXP inv_Sigma_gammaSEXP, SEXP mu_gammaSEXP, SEXP Sigma_zeta_invSEXP, SEXP S0SEXP, SEXP mu_betaSEXP, SEXP sigma_beta_invSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::vec& >::type unique_subject_ids(unique_subject_idsSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type subject_ids(subject_idsSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type choices_nk(choices_nkSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type fixed_effects_design(fixed_effects_designSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type rv_effects_design(rv_effects_designSEXP);
    Rcpp::traits::input_parameter< const arma::uvec& >::type B_elem_plus1(B_elem_plus1SEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type theta(thetaSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type zeta_rv(zeta_rvSEXP);
    Rcpp::traits::input_parameter< /* Trading Memory for Speed */                      const arma::field<arma::mat>& >::type WtW(WtWSEXP);
    Rcpp::traits::input_parameter< const arma::vec >::type Z_c(Z_cSEXP);
    Rcpp::traits::input_parameter< const arma::vec >::type Wzeta_0(Wzeta_0SEXP);
    Rcpp::traits::input_parameter< /* Bunch of priors */                      const arma::mat& >::type inv_Sigma_gamma(inv_Sigma_gammaSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type mu_gamma(mu_gammaSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type Sigma_zeta_inv(Sigma_zeta_invSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type S0(S0SEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type mu_beta(mu_betaSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type sigma_beta_inv(sigma_beta_invSEXP);
    rcpp_result_gen = Rcpp::wrap(probitHLM(unique_subject_ids, subject_ids, choices_nk, fixed_effects_design, rv_effects_design, B_elem_plus1, gamma, beta, theta, zeta_rv, WtW, Z_c, Wzeta_0, inv_Sigma_gamma, mu_gamma, Sigma_zeta_inv, S0, mu_beta, sigma_beta_inv));
    return rcpp_result_gen;
END_RCPP
}
// cIRT
Rcpp::List cIRT(arma::vec subject_ids, arma::mat fixed_effects, arma::uvec B_elem_plus1, arma::mat rv_effects, arma::mat trial_matrix, arma::vec choices_nk, unsigned int burnit, unsigned int chain_length);
RcppExport SEXP _cIRT_cIRT(SEXP subject_idsSEXP, SEXP fixed_effectsSEXP, SEXP B_elem_plus1SEXP, SEXP rv_effectsSEXP, SEXP trial_matrixSEXP, SEXP choices_nkSEXP, SEXP burnitSEXP, SEXP chain_lengthSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type subject_ids(subject_idsSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type fixed_effects(fixed_effectsSEXP);
    Rcpp::traits::input_parameter< arma::uvec >::type B_elem_plus1(B_elem_plus1SEXP);
    Rcpp::traits::input_parameter< arma::mat >::type rv_effects(rv_effectsSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type trial_matrix(trial_matrixSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type choices_nk(choices_nkSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type burnit(burnitSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type chain_length(chain_lengthSEXP);
    rcpp_result_gen = Rcpp::wrap(cIRT(subject_ids, fixed_effects, B_elem_plus1, rv_effects, trial_matrix, choices_nk, burnit, chain_length));
    return rcpp_result_gen;
END_RCPP
}
// rmvnorm
arma::mat rmvnorm(unsigned int n, const arma::vec& mu, const arma::mat& S);
RcppExport SEXP _cIRT_rmvnorm(SEXP nSEXP, SEXP muSEXP, SEXP SSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type mu(muSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type S(SSEXP);
    rcpp_result_gen = Rcpp::wrap(rmvnorm(n, mu, S));
    return rcpp_result_gen;
END_RCPP
}
// rwishart
arma::mat rwishart(unsigned int df, const arma::mat& S);
RcppExport SEXP _cIRT_rwishart(SEXP dfSEXP, SEXP SSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned int >::type df(dfSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type S(SSEXP);
    rcpp_result_gen = Rcpp::wrap(rwishart(df, S));
    return rcpp_result_gen;
END_RCPP
}
// riwishart
arma::mat riwishart(unsigned int df, const arma::mat& S);
RcppExport SEXP _cIRT_riwishart(SEXP dfSEXP, SEXP SSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned int >::type df(dfSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type S(SSEXP);
    rcpp_result_gen = Rcpp::wrap(riwishart(df, S));
    return rcpp_result_gen;
END_RCPP
}
// Total_Tabulate
arma::uvec Total_Tabulate(unsigned int N, unsigned int J, const arma::mat Y);
RcppExport SEXP _cIRT_Total_Tabulate(SEXP NSEXP, SEXP JSEXP, SEXP YSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned int >::type N(NSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type J(JSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type Y(YSEXP);
    rcpp_result_gen = Rcpp::wrap(Total_Tabulate(N, J, Y));
    return rcpp_result_gen;
END_RCPP
}
// Generate_Choice
Rcpp::List Generate_Choice(unsigned int N, unsigned int J, unsigned int K, const arma::vec& theta, const arma::vec& as, const arma::vec& bs, const arma::mat& zeta, const arma::vec& gamma, const arma::mat& X, const arma::mat& W, const arma::vec& subject_ids, const arma::vec& unique_subject_ids);
RcppExport SEXP _cIRT_Generate_Choice(SEXP NSEXP, SEXP JSEXP, SEXP KSEXP, SEXP thetaSEXP, SEXP asSEXP, SEXP bsSEXP, SEXP zetaSEXP, SEXP gammaSEXP, SEXP XSEXP, SEXP WSEXP, SEXP subject_idsSEXP, SEXP unique_subject_idsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned int >::type N(NSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type J(JSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type K(KSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type theta(thetaSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type as(asSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type bs(bsSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type zeta(zetaSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type W(WSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type subject_ids(subject_idsSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type unique_subject_ids(unique_subject_idsSEXP);
    rcpp_result_gen = Rcpp::wrap(Generate_Choice(N, J, K, theta, as, bs, zeta, gamma, X, W, subject_ids, unique_subject_ids));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_cIRT_direct_sum", (DL_FUNC) &_cIRT_direct_sum, 1},
    {"_cIRT_center_matrix", (DL_FUNC) &_cIRT_center_matrix, 1},
    {"_cIRT_TwoPLChoicemcmc", (DL_FUNC) &_cIRT_TwoPLChoicemcmc, 16},
    {"_cIRT_probitHLM", (DL_FUNC) &_cIRT_probitHLM, 19},
    {"_cIRT_cIRT", (DL_FUNC) &_cIRT_cIRT, 8},
    {"_cIRT_rmvnorm", (DL_FUNC) &_cIRT_rmvnorm, 3},
    {"_cIRT_rwishart", (DL_FUNC) &_cIRT_rwishart, 2},
    {"_cIRT_riwishart", (DL_FUNC) &_cIRT_riwishart, 2},
    {"_cIRT_Total_Tabulate", (DL_FUNC) &_cIRT_Total_Tabulate, 3},
    {"_cIRT_Generate_Choice", (DL_FUNC) &_cIRT_Generate_Choice, 12},
    {NULL, NULL, 0}
};

RcppExport void R_init_cIRT(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
