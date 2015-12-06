#include <RcppArmadillo.h>
#include "total_cpp.h"
// [[Rcpp::depends(RcppArmadillo)]]
using namespace Rcpp;

//' @title Calculate Tabulated Total Scores 
//' @description Internal function to -2LL
//' @param N An \code{int}, which gives the number of observations.  (> 0)
//' @param J An \code{int}, which gives the number of items.  (> 0)
//' @param Y A N by J \code{matrix} of item responses.
//' @return A vector of tabulated total scores.
//' @author Steven Andrew Culpepper
// [[Rcpp::export]]
arma::uvec Total_Tabulate(unsigned int N,unsigned int J,const arma::mat Y){  
  arma::vec T(N);
  T = sum(Y,1);
  arma::uvec H = arma::hist(T,arma::linspace<arma::vec>(0,J,J+1));
  return H;
}

//' @title Generate Observed Data from choice model
//' @description Generates observed cognitive and choice data from the IRT-Thurstone model. 
//' @param N An \code{integer} for the number of observations.
//' @param J An \code{integer} for the number of items.
//' @param K An \code{integer} for the number of paired comparisons.
//' @param theta A \code{vector} of latent cognitive variables.
//' @param as item discriminations, a \code{vector} of length J
//' @param bs item locations, a \code{vector} of length J
//' @param zeta A \code{matrix} with dimensions N x V containing random parameter estimates.
//' @param gamma A \code{vector} with dimensions P x 1 containing fixed parameter estimates, where \eqn{P = P_1 + P_2}
//' @param X A \code{matrix} with dimensions N*K x P_1 containing fixed effect design matrix without theta.
//' @param W A \code{matrix} with dimensions N*K x V containing random effect variables.
//' @param subject_ids A \code{vector} with length NK x 1 containing subject-choice IDs.
//' @param unique_subject_ids A \code{vector} with length N x 1 containing unique subject IDs.
//' @return A \code{list} that contains:
//' \describe{
//'   \item{\code{Y}}{A \code{matrix} of dimension N by J}
//'   \item{\code{C}}{A \code{vector} of length NK}
//' }
//' @author Steven Culpepper and James J Balamuta
// [[Rcpp::export]]
Rcpp::List Generate_Choice(
    unsigned int N,
    unsigned int J,
    unsigned int K,
    const arma::vec& theta,
    const arma::vec& as,
    const arma::vec& bs,
    const arma::mat& zeta,
    const arma::vec& gamma,
    const arma::mat& X,
    const arma::mat& W,
    const arma::vec& subject_ids,
    const arma::vec& unique_subject_ids){
  
  //Generate Y matrix
  arma::mat Y = arma::zeros<arma::mat>(N,J);
  arma::vec oneN = arma::ones<arma::vec>(N);
  arma::vec oneK = arma::ones<arma::vec>(K);
  arma::vec oneJ = arma::ones<arma::vec>(J);
  arma::mat etaY = theta*as.t() - oneN*bs.t();
  arma::mat ZY = arma::randn<arma::mat>(N,J);
  //generating Y
  Y.elem( find(etaY > ZY) ).ones();
  
  //Generate choice vector,Cs
  //# of cases and choices
  unsigned int nk = X.n_rows;
  //  arma::vec Cs= arma::zeros<arma::vec>(nk);
  arma::mat Cs= arma::zeros<arma::mat>(N,K);
  //random z's for c
  //  arma::vec ZC = arma::randn<arma::vec>(nk);
  arma::mat ZC = arma::randn<arma::mat>(N,K);
  arma::vec Wzeta_0(nk);
  arma::mat etaC_mat(N,K);
  
  for(unsigned int i=0;i<<N;i++){
    arma::uvec current_subject = find(subject_ids == unique_subject_ids(i));
    arma::mat Wi = W.rows(current_subject);
    arma::mat Xi = X.rows(current_subject);
    Wzeta_0.elem(current_subject) = Wi*trans(zeta.row(i)); //nk x 1
    etaC_mat.row(i) = gamma.t()*X.t() + zeta.row(i)*Wi.t();
  }
  arma::vec etaC = X*gamma + Wzeta_0;
  Cs.elem( find(etaC_mat > ZC) ).ones();
  
  //  arma::vec nC = Cs*oneK;
  //  arma::vec nY = Y*oneJ;
  arma::uvec nC = Total_Tabulate(N,K,Cs);
  arma::uvec nY = Total_Tabulate(N,J,Y);
  
  return Rcpp::List::create(Rcpp::Named("nC",nC),
                            Rcpp::Named("nY",nY),
                            Rcpp::Named("Cs",Cs)
  );
}
