## Test environments

* local macOS install, R 4.5.1
* ubuntu 24.04 (on GitHub Actions), R 4.5.1
* win-builder (devel and release)

## R CMD check results

0 errors | 0 warnings | 0 note

We are making this release to account for the RcppArmadillo change that
requires removing `CXX_STD=CXX11`.
