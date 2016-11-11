context("create")

test_that("cpp_create_environment()", {
  env_cb <- cpp_create_environment(letters, "toupper")
  env <- env_cb$env
  expect_equal(env$a, "A")
  expect_equal(env$x, "X")
  expect_null(env$X)
  expect_equal(length(ls(env)), length(letters))
  expect_error(env$a <- "a", "read-only")
})

test_that("cpp_create_environment() with inheritance", {
  env_cb <- cpp_create_environment(letters, "toupper")
  env <- env_cb$env
  env2_cb <- cpp_create_environment(LETTERS, "tolower", parent = env)
  env2 <- env2_cb$env
  expect_equal(get("a", env2), "A")
  expect_equal(get("x", env2), "X")
  expect_null(env2$a)
  expect_null(env2$x)
  expect_equal(env2$B, "b")
  expect_equal(env2$Y, "y")
  expect_equal(length(ls(env2)), length(letters))
  expect_error(env2$B <- "B", "read-only")
  expect_error(env2$a <- "a", NA)
  expect_equal(get("a", env2), "a")
})
