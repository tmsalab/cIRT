

<!-- README.md is generated from README.qmd. Please edit that file -->

# cIRT: Choice Item Response Theory <a href="https://tmsalab.github.io/cIRT/"><picture><source media="(prefers-color-scheme: dark)" srcset="man/figures/cIRT-logo-animated-dark.svg"><img src="man/figures/cIRT-logo-animated-light.svg" width="150" align="right" alt="A hexagonal logo for cIRT: two cards stand on a solid table with cIRT cut out of it; the 6-point card stays in outline while the chosen 16-point card is lifted off its dashed place, carrying the orange posterior density of θ under a dashed normal prior."/></picture></a>

<!-- badges: start -->

[![R-CMD-check](https://github.com/tmsalab/cIRT/actions/workflows/R-CMD-check.yaml/badge.svg)](https://github.com/tmsalab/cIRT/actions/workflows/R-CMD-check.yaml)
[![CRAN Version
Badge](https://www.r-pkg.org/badges/version/cIRT.png)](https://cran.r-project.org/package=cIRT)
[![RStudio CRAN Mirror’s Monthly
Downloads](https://cranlogs.r-pkg.org/badges/cIRT?color=brightgreen.png)](https://www.r-pkg.org/pkg/cIRT)
[![RStudio CRAN Mirror’s Total
Downloads](https://cranlogs.r-pkg.org/badges/grand-total/cIRT?color=brightgreen.png)](https://www.r-pkg.org/pkg/cIRT)
<!-- badges: end -->

Jointly model the accuracy of cognitive responses and item choices
within a Bayesian hierarchical framework as described by Culpepper and
Balamuta (2015).

## Installation

You can install `cIRT` from CRAN using:

``` r
install.packages("cIRT")
```

Or, you can be on the cutting-edge development version on GitHub using:

``` r
if(!requireNamespace("remotes")) install.packages("remotes")
remotes::install_github("tmsalab/cIRT")
```

## Usage

To use the `cIRT` package, load it into *R* using:

``` r
library("cIRT")
```

## Authors

Steven Andrew Culpepper and James Joseph Balamuta

## Citing the cIRT package

To ensure future development of the package, please cite `cIRT` package
if used during an analysis or simulation studies. Citation information
for the package may be acquired by using in *R*:

``` r
citation("cIRT")
```

## License

GPL (\>= 2)
