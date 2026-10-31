test_that("cIRT() stores every post-burn-in draw when burnit = 0", {
  # Setup from the "Estimating the Model in the Paper" vignette, with a
  # five-sweep chain.
  data(trial_matrix, package = "cIRT", envir = environment())
  data(choice_matrix, package = "cIRT", envir = environment())

  hard_items <- choice_matrix$hard_q_id
  easy_items <- choice_matrix$easy_q_id
  D_easy <- model.matrix(~ -1 + factor(easy_items))
  D_hard <- -1 * model.matrix(~ -1 + factor(hard_items))[, -c(5, 10, 15)]

  high_contrasts <- rbind(-1, diag(4))
  rownames(high_contrasts) <- 12:16
  low_contrasts <- rbind(-1, diag(2))
  rownames(low_contrasts) <- 4:6
  high <- factor(choice_matrix[, "high_value"])
  low <- factor(choice_matrix[, "low_value"])
  contrasts(high) <- high_contrasts
  contrasts(low) <- low_contrasts
  fixed_effects <- model.matrix(~ high + low)

  set.seed(1)
  fit <- cIRT(
    choice_matrix[, "subject_id"],
    cbind(fixed_effects[, -1], D_easy, D_hard),
    seq_len(ncol(fixed_effects)),
    as.matrix(fixed_effects),
    as.matrix(trial_matrix),
    choice_matrix[, "choose_hard_q"],
    burnit = 0,
    chain_length = 5
  )

  # Each nY column tabulates the simulated total scores of every student;
  # an unfilled column is all zeros.
  n_students <- length(unique(choice_matrix[, "subject_id"]))
  expect_equal(colSums(fit$nY), rep(n_students, 5))
})
