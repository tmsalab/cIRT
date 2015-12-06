#include <RcppArmadillo.h>
#include "armadillo_manipulations.h"
using namespace Rcpp;


//' @title Direct Sum of Matrices
//' 
//' @description Computes the direct sum of all matrices passed in via the list.
//' 
//' @details
//' Consider matrix A (mxn) and B (k x p).
//' A direct sum is a diagonal matrix A (+) B with dimensions (m + k) x (n + p).
//' 
//' @param x list containing matrices
//' @return ds_matrix matrix containing the direct sum in list.
//' @author James J Balamuta
//' @examples
//' 
//' x = list(matrix(0,nrow=5,ncol=3),
//'          matrix(1,nrow=5,ncol=3))
//' direct_sum(x)
//' 
//' x = list(matrix(rnorm(15),nrow=5,ncol=3),
//'          matrix(rnorm(30),nrow=5,ncol=6),
//'          matrix(rnorm(18),nrow=2,ncol=9))
//' direct_sum(x)
// [[Rcpp::export]]
arma::mat direct_sum(arma::field<arma::mat> x) {
  
  // Get the length of the list
  unsigned int bin = x.n_elem;
  
  // Obtain matrix size for each element
  arma::mat storage(bin,2);
  // Temporary storage that does not need to be created each time
  arma::rowvec cur_elem_dims(2);
  for(unsigned int i=0; i<bin; i++){
    // Get dimensions */
    cur_elem_dims(0) = x(i).n_rows; 
    cur_elem_dims(1) = x(i).n_cols;
    // Store dimensions
    storage.row(i) = cur_elem_dims;
  }
  
  // Sum the columns of storage to get final total
  arma::rowvec dims = arma::sum(storage,0);
  
  // Create a matrix to combine
  arma::mat ds_matrix = arma::zeros<arma::mat>(dims(0), dims(1));
  
  // C++ matrices start at (0,0) not (1,1)
  arma::rowvec start_loc = "0 0";
  for(unsigned int i=0; i<bin; i++){
    // End Loc needs to be one less than matrix size due to us counting | instead of ^ in |^|^| 
    arma::rowvec end_loc = start_loc + storage.row(i) - 1;
    
    // Obtain a subset of the matrix and fill it with list element
    ds_matrix.submat(start_loc(0),start_loc(1),end_loc(0),end_loc(1)) = x(i);
    
    // Move start_loc up for next matrix dimension
    start_loc = end_loc+1;
  }
  
  // Return direct sum matrix
  return ds_matrix;
}

//' @title Center a Matrix
//' @description Obtains the mean of each column of the matrix and subtracts it from the given matrix in a centering operation.
//' @param x A \code{matrix} with any dimensions
//' @return centered_matrix A \code{matrix} with the same dimensions of X that has been centered.
//' @details The application of this function to a matrix mimics the use of a centering matrix
//'  given by: \eqn{{C_n} = {I_n} - \frac{1}{n}{11^T}}
//' @seealso \code{\link{cIRT}}
//' @author James J Balamuta
//' @examples 
//' nobs = 500
//' nvars = 20
//' x = matrix(rnorm(nobs*nvars),nrow=nobs,ncol=nvars)
//' r_centered = scale(x)
//' arma_centered1 = center_matrix(x)
// [[Rcpp::export]]
arma::mat center_matrix(const arma::mat& x){
  arma::rowvec col_means = arma::mean(x, 0);
  arma::mat centered_matrix(x.n_rows, x.n_cols);
  
  for(unsigned int i=0; i<x.n_cols; i++){
    centered_matrix.col(i) = x.col(i) - col_means(i);
  }
  
  return centered_matrix; 
}
