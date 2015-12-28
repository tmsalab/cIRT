# cIRT
An R Package detailing the Choice Item Response Theory Model


# Install Instructions (All platforms)
To install the `cIRT` package, there are two options: CRAN (stable) or GitHub (Developmental).

The installation process with CRAN is the simplest
```r
install.packages("cIRT")
```

Prior to installing with `devtools`, please make sure to have a compiler installed on your system that is compatible with R.

If you have a compiler already installed, then continue on by installing the package dependencies and finally the package itself by doing the following: 

```r
# Install dependencies
install.packages("RcppArmadillo")

# Install the package from github
devtools::install_github("tmsalab/cIRT")
```
