# Functions

# E[theta] - theta 
bias = function(theta.star, theta.true){
  matrix(mean(theta.star) - theta.true,ncol=1)
}

bias2 = function(theta.star, theta.true){
  matrix(theta.star - theta.true,ncol=1)
}

# sqrt ( 1/n * sum( (y_i - y.hat_i)^2 )
RMSE = function(y,y.hat){
  sqrt(  (y-y.hat)^2 ) 
}

# Change true values if needed
# True Values
gam_notheta = c(.5,1)
gam_theta   = c(3,.25)
gamma = c(gam_notheta,gam_theta)
# Loads a and b values
load("a_b_true.rda")

Sig = as.numeric(matrix(c(.25,0,0,.125),2,2))[c(1,2,4)]
B = 100

# Storage to hold bootstrap replications
a_result = matrix(0, B, 20)

b_result = matrix(0, B, 20)

gs0_result = matrix(0, B, 2)

beta_result = matrix(0, B, 2)

sig_result = array(NA, dim=c(2,2,B))


for(i in 1:B){

  a = read.csv(paste0("as_",i,".csv"))[,-1]
  b = read.csv(paste0("bs_",i,".csv"))[,-1]
  
  gs0 = read.csv(paste0("gs0_",i,".csv"))[,-1]
  
  beta = read.csv(paste0("beta_",i,".csv"))[,-1]

  load(paste0("sig_",i,".rda"))
  
  
  a_result[i,] = apply(a, 2, FUN = mean)
  b_result[i,] = apply(b, 2, FUN = mean)
  
  gs0_result[i,] = apply(gs0, 2, FUN = mean)
  
  beta_result[i,] = apply(beta, 2, FUN = mean)
  
  sig_result[,,i] = solve(apply(sig, c(1,2), FUN = mean))
}


# for(i in 1:B){
#   sig = read.csv(paste0("sigma_",i,".csv"),stringsAsFactors=F)[,-1]
#   sig_result[,,i] = solve(apply(sig, margin = c(1,2), FUN = mean))
# }

m_a_result = apply(a_result, 2, FUN = mean)

m_b_result = apply(b_result, 2, FUN = mean)

m_gs0_result = apply(gs0_result, 2, FUN = mean)

m_beta_result = apply(beta_result, 2, FUN = mean)

m_sig_result = as.numeric(apply(sig_result, c(1,2), FUN = mean))[c(1,2,4)]



a_bias = bias2(m_a_result,atrue)

b_bias = bias2(m_b_result,btrue)

gs0_bias = bias2(m_gs0_result,gamma[1:2])

beta_bias = bias2(m_beta_result,gamma[3:4])

sig_bias = bias2(m_sig_result, Sig)


a_RMSE = RMSE(m_a_result,atrue)

b_RMSE = RMSE(m_b_result,btrue)

gs0_RMSE = RMSE(m_gs0_result,gamma[1:2])

beta_RMSE = RMSE(m_beta_result,gamma[3:4])

sig_RMSE = RMSE(m_sig_result, Sig)

results_a = cbind(m_a_result, atrue, a_bias, a_RMSE)

rownames(results_a) = paste0("Item ",1:length(atrue))

colnames(results_a) = c("$a$ Estimate", "$a$ True", "$a$ Bias", "$a$ RMSE")

results_b = cbind(m_b_result,  btrue, b_bias, b_RMSE)

rownames(results_b) = paste0("Item ",1:length(btrue))
colnames(results_b) = c("$b$ Estimate", "$b$ True", "$b$ Bias", "$b$ RMSE")

  
results_gs0 = cbind(m_gs0_result,gamma[1:2],gs0_bias,gs0_RMSE)
rownames(results_gs0) = paste0("$\\gamma_",1:2,"$")
colnames(results_gs0) = c("$\\beta$ Estimate", "$\\beta$ True", "$\\beta$ Bias", "$\\beta$ RMSE")


results_beta = cbind(m_beta_result,gamma[3:4],beta_bias,beta_RMSE)
rownames(results_beta) = paste0("$\\beta_",1:2,"$")
colnames(results_beta) = c("$\\beta$ Estimate", "$\\beta$ True", "$\\beta$ Bias", "$\\beta$ RMSE")

results_sig_zeta = cbind(m_sig_result,Sig,sig_bias,sig_RMSE)
rownames(results_sig_zeta) = c("$\\Zeta_{1,1}$","$\\Zeta_{2,1} = $\\Zeta_{1,2}$", "$\\Zeta_{2,2}$")
colnames(results_sig_zeta) = c("$\\Sigma_{\\Zeta}$ Estimate", "$\\beta$ True", "$\\beta$ Bias", "$\\beta$ RMSE")

setwd("../")
save(results_a, results_b, results_gs0, results_beta, results_sig_zeta, file="sim_results.rda")
