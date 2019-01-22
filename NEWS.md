# cIRT 1.2.1

- Added `src/init.c` for R 3.4 compatibility
- Added GitHub project page link

# cIRT 1.2.0

- Added two vignettes that cover the model estimation and simulation results in the package. 
- Added a `NEWS.md` file to track changes to the package.

# cIRT 1.1.0

- Adds two columns to choice matrix: `hard_q_id` and `easy_q_id`.

# cIRT 1.0.0

## Modeling Framework
- Implementation of the hiercharical framework described in "A Hierarchical Model for Accuracy and Choice on Standardized Tests"
- Specifically, a choice inclusive Probit HLM and a Two Parameter Ogive Model.

## C++ Functions
- Random Number Generation for the following distributions: Wishart, Inverse Wishart, and Multivariate Normal
- Matrix Centering
- Direct Sum calculation

## Data
- Student Performance on Revised Purdue Spatial Visualization Test (Revised PSVT:R) by Yoon, 2011 in `trial_matrix`
- The choices students made among items presented to them in `choice_matrix`
- The end payout results for students based on their choices in `payout_matrix`
- One additional data set exists containing the student's sex response in `survey_data`
