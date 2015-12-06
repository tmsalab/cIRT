# Variables
# Y = trial matix
# C = KN vector of binary choices
# N = #of subjects
# J = # of items
# K= # of choices
# atrue = true item discriminations
# btrue = true item locations
# thetatrue = true thetas/latent performance
# gamma = fixed effects coefficients
# Sig = random-effects variance-covariance
# subid = id variable for subjects

library(cIRT)


# Simulate 2PNO Data
N = 1000  # Students
J = 20    # Total numbers of possible items per SA

# Randomly pick a's and b's
set.seed(1337)
# Generate as, bs
atrue=runif(J)+1
btrue=2*runif(J)-1

# 2 Level Probit Data
K = 30

gam_notheta = c(.5,1)
gam_theta   = c(3,.25)
gamma = c(gam_notheta,gam_theta)

Sig = matrix(c(.25,0,0,.125),2,2)

# Number of replications
B = 100


for(b in 1:B){
  cat(paste0("On Iteration:",b,"\n"))
  set.seed(b + 1234)
  
  
  #true theta and etay
  thetatrue = rnorm(N)
  etay = outer(rep(1,N),atrue) * thetatrue - outer(rep(1,N),btrue)
  
  #Generate Y for 2PNO model
  p.correct = pnorm(etay)
  Y = matrix(rbinom(N*J, 1, p.correct),N,J)
  
  #################################################
  #simulating 2 level probit data
  #################################################
  
  subid = expand.grid(cid = 1:K,sid = 1:N)[,2]
  
  pred = rnorm(K*N,0,1) # Pred
  
  center_pred = center_matrix(as.matrix(pred))
  
  Xnotheta = cbind(1,center_pred)
  
  Xtheta = rep(thetatrue,each=K)*Xnotheta
  #Xtheta = cbind(Xtheta,Xtheta*Xnotheta[,2])
  X = cbind(Xnotheta,Xtheta)
  
  
  zetas = mvtnorm::rmvnorm(N,mean=c(0,0),sigma=Sig) # mvtnorm environment accessed
  W_veczeta = apply(Xnotheta*zetas[rep(1:N,each=K),],1,sum)
  
  etac = X%*%gamma + W_veczeta
  Zc = rnorm(N*K,mean=etac,sd=1)
  C = 1*(Zc>0)
  
  #    W_veczeta = as.matrix(W_veczeta)
  
  out1 = cIRT(subid, 
              Xnotheta,
              c(1,2), 
              Xnotheta,
              Y, 
              C, 
              5000)
  
  # Prediction
  write.csv(out1$as, file=paste0("as_",b,".csv"))
  write.csv(out1$bs, file=paste0("bs_",b,".csv"))
  write.csv(out1$gs0, file=paste0("gs0_",b,".csv"))
  write.csv(out1$beta, file=paste0("beta_",b,".csv"))
  
  # How to write array() to csv???
  sig = out1$Sigma_zeta_inv
  save(sig, file=paste0("sig_",b,".rda"))
  save(out1, file=paste0("data_",b,".rda"))
}

