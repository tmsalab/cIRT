## Test environments
* local OS X install, R 3.4.0
* ubuntu 12.04 (on travis-ci), R 3.4.0
* win-builder (devel and release)

## R CMD check results
There were no ERRORs or WARNINGs. 

We have one note related to spelling:

* checking CRAN incoming feasibility ... NOTE
Maintainer: 'James Balamuta <balamut2@illinois.edu>'

Possibly mis-spelled words in DESCRIPTION:
  Balamuta (11:5)
  Culpepper (10:62)
  bayesian (10:14)
  datasets (12:18)
  
The first two are the authors' last names. The last two are correct spellings. 