bindrcpp 0.2.3

## R CMD check results

- [x] Checked locally, R 4.3.2
- [x] Checked on CI system, R 4.3.2
- [x] Checked on win-builder, R devel

## Current CRAN check results

- [x] Checked on 2023-12-11, problems found: https://cran.r-project.org/web/checks/check_results_bindrcpp.html
- [x] WARN: r-devel-linux-x86_64-debian-clang, r-devel-linux-x86_64-fedora-clang
     Found the following significant warnings:
     RcppExports.cpp:40:18: warning: format string is not a string literal (potentially insecure) [-Wformat-security]
     RcppExports.cpp:73:18: warning: format string is not a string literal (potentially insecure) [-Wformat-security]
     RcppExports.cpp:106:18: warning: format string is not a string literal (potentially insecure) [-Wformat-security]
     RcppExports.cpp:139:18: warning: format string is not a string literal (potentially insecure) [-Wformat-security]
     RcppExports.cpp:172:18: warning: format string is not a string literal (potentially insecure) [-Wformat-security]
     RcppExports.cpp:205:18: warning: format string is not a string literal (potentially insecure) [-Wformat-security]
     RcppExports.cpp:238:18: warning: format string is not a string literal (potentially insecure) [-Wformat-security]
     RcppExports.cpp:271:18: warning: format string is not a string literal (potentially insecure) [-Wformat-security]
     RcppExports.cpp:304:18: warning: format string is not a string literal (potentially insecure) [-Wformat-security]
     RcppExports.cpp:337:18: warning: format string is not a string literal (potentially insecure) [-Wformat-security]
     RcppExports.cpp:370:18: warning: format string is not a string literal (potentially insecure) [-Wformat-security]
     RcppExports.cpp:403:18: warning: format string is not a string literal (potentially insecure) [-Wformat-security]
     See ‘/home/hornik/tmp/R.check/r-devel-clang/Work/PKGS/bindrcpp.Rcheck/00install.out’ for details.
     * used C++ compiler: ‘Debian clang version 17.0.5 (1)’
     Fixed.
- [x] NOTE: r-devel-linux-x86_64-debian-clang, r-devel-linux-x86_64-debian-gcc, r-devel-linux-x86_64-fedora-clang, r-devel-linux-x86_64-fedora-gcc, r-devel-windows-x86_64, r-patched-linux-x86_64, r-release-linux-x86_64, r-release-macos-arm64, r-release-macos-x86_64, r-release-windows-x86_64, r-oldrel-macos-arm64, r-oldrel-macos-x86_64, r-oldrel-windows-x86_64
     'LazyData' is specified without a 'data' directory
     Fixed.
