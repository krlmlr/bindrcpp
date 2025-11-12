<!-- NEWS.md is maintained by https://fledge.cynkra.com, contributors should not edit this file -->

# bindrcpp 0.2.3.9025 (2025-11-12)

## Continuous integration

- Fix reviewdog and add commenting workflow (#40).


# bindrcpp 0.2.3.9024 (2025-11-10)

## Chore

- Auto-update from GitHub Actions.

  Run: https://github.com/krlmlr/bindrcpp/actions/runs/17450838020

- Auto-update from GitHub Actions.

  Run: https://github.com/krlmlr/bindrcpp/actions/runs/14641090525

## Continuous integration

- Use workflows for fledge (#39).

- Sync (#38).

- Use reviewdog for external PRs (#37).

- Cleanup and fix macOS (#36).

- Format with air, check detritus, better handling of `extra-packages` (#35).

- Enhance permissions for workflow (#34).

- Permissions, better tests for missing suggests, lints (#33).

- Only fail covr builds if token is given (#32).

- Always use `_R_CHECK_FORCE_SUGGESTS_=false` (#31).

- Correct installation of xml2 (#30).

- Explain (#29).

- Add xml2 for covr, print testthat results (#28).

- Fix (#27).

- Sync (#26).


# bindrcpp 0.2.3.9023 (2024-12-09)

## Continuous integration

- Avoid failure in fledge workflow if no changes (#25).


# bindrcpp 0.2.3.9022 (2024-12-08)

## Continuous integration

- Fetch tags for fledge workflow to avoid unnecessary NEWS entries (#24).


# bindrcpp 0.2.3.9021 (2024-12-07)

## Continuous integration

- Use larger retry count for lock-threads workflow (#23).


# bindrcpp 0.2.3.9020 (2024-11-28)

## Continuous integration

- Ignore errors when removing pkg-config on macOS (#22).


# bindrcpp 0.2.3.9019 (2024-11-27)

## Continuous integration

- Explicit permissions (#21).


# bindrcpp 0.2.3.9018 (2024-11-26)

## Continuous integration

- Use styler from main branch (#20).


# bindrcpp 0.2.3.9017 (2024-11-25)

## Continuous integration

- Need to install R on Ubuntu 24.04 (#19).

- Correctly detect branch protection (#16).

- Use Ubuntu 24.04 and styler PR (#17).


# bindrcpp 0.2.3.9016 (2024-11-22)

## Continuous integration

  - Correctly detect branch protection (#16).


# bindrcpp 0.2.3.9015 (2024-11-18)

## Continuous integration

  - Use stable pak (#15).


# bindrcpp 0.2.3.9014 (2024-11-11)

## Continuous integration

  - Trigger run (#14).
    
      - ci: Trigger run
    
      - ci: Latest changes


# bindrcpp 0.2.3.9013 (2024-10-28)

## Continuous integration

  - Use pkgdown branch (#13).
    
      - ci: Use pkgdown branch
    
      - ci: Updates from duckdb
    
      - ci: Trigger run


# bindrcpp 0.2.3.9012 (2024-09-15)

## Continuous integration

  - Install via R CMD INSTALL ., not pak (#12).
    
      - ci: Install via R CMD INSTALL ., not pak
    
      - ci: Bump version of upload-artifact action


# bindrcpp 0.2.3.9011 (2024-08-31)

## Continuous integration

  - Install local package for pkgdown builds.

  - Improve support for protected branches with fledge.

  - Improve support for protected branches, without fledge.


# bindrcpp 0.2.3.9010 (2024-08-17)

## Chore

- Auto-update from GitHub Actions.

  Run: https://github.com/krlmlr/bindrcpp/actions/runs/10425482950

## Continuous integration

- Sync with latest developments.


# bindrcpp 0.2.3.9009 (2024-08-10)

## Continuous integration

- Use v2 instead of master.


# bindrcpp 0.2.3.9008 (2024-08-06)

## Continuous integration

- Inline action.


# bindrcpp 0.2.3.9007 (2024-08-02)

## Chore

- Auto-update from GitHub Actions.

  Run: https://github.com/krlmlr/bindrcpp/actions/runs/10200119080

## Continuous integration

- Use dev roxygen2 and decor.


# bindrcpp 0.2.3.9006 (2024-07-02)

## Continuous integration

- Fix on Windows, tweak lock workflow.


# bindrcpp 0.2.3.9005 (2024-06-30)

## Chore

- Auto-update from GitHub Actions.

  Run: https://github.com/krlmlr/bindrcpp/actions/runs/9727973898


# bindrcpp 0.2.3.9004 (2024-06-28)

## Chore

- Auto-update from GitHub Actions.

  Run: https://github.com/krlmlr/bindrcpp/actions/runs/9691614338

## Continuous integration

- Avoid checking bashisms on Windows.

- Better commit message.

- Bump versions, better default, consume custom matrix.

- Recent updates.


# bindrcpp 0.2.3.9003 (2024-05-27)

## Chore

- Bump.


# bindrcpp 0.2.3.9002 (2024-01-24)

- Internal changes only.


# bindrcpp 0.2.3.9001 (2024-01-15)

- Internal changes only.


# bindrcpp 0.2.3.9000 (2023-12-12)

- Merge branch 'cran-0.2.3'.


# bindrcpp 0.2.3 (2023-12-11)

## Bugfix

- Fix `-Wformat-security` warning with R-devel

## Chore

- Install Rcpp from GitHub for CI/CD.


# bindrcpp 0.2.2 (2018-03-29)

- Fix compatibility with dplyr installed and built against an older version of bindrcpp.
- Support callbacks that accept a list. The new `xxx_env_yyy_wrapped()` functions expect a list as payload, and a callback function with `List` instead of `PAYLOAD` as second argument. This helps controlling the lifetime of objects associated with a callback: these can be placed in an `XPtr` inside the `List`. The `xxx_env_yyy()` functions have been aliased to `xxx_env_yyy_typed()` (#7).
- Bump dependency to bindr 0.1.1.


# bindrcpp 0.2 (2017-06-15)

- Fixed very rare segmentation fault due to missing protection of function arguments in autogenerated boilerplate code.
- Fix compilation errors on FreeBSD due to use of nonstandard Make features (#5).
- Native symbol registration added by Rcpp.


# bindrcpp 0.1 (2016-12-08)

Initial CRAN release.

## Exported C++ functions

- `create_env_string()` creates an environment with active bindings, with names given as a character vector.  Access of these bindings triggers a call to a C++ function with a fixed signature (`GETTER_FUNC_STRING`); this call contains the name of the binding (as character) and an arbitrary payload (`PAYLOAD`, essentially a wrapped `void*`).
- `create_env_symbol()` is similar, the callback function accepts the name of the binding as symbol instead of
  character (`GETTER_FUNC_SYMBOL`).
- `populate_env_string()` and `populate_env_symbol()` populate an existing environment instead of creating a new one.
- Use `LinkingTo: bindrcpp` and `#include <bindrcpp.h>` to access these functions from your package.

## Exported R functions

- Reexported from `bindr`: `create_env()` and `populate_env()`.
