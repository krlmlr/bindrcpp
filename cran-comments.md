Update addressing feedback from the CRAN submission of bindrcpp 0.2.1: Updating bindrcpp doesn't break an installed dplyr package anymore.

## Test environments
* local ubuntu 17.10 install, R 3.4.3
* ubuntu 12.04 (on travis-ci), R devel, release, and oldrel, and OS X
* win-builder (devel and release)

## R CMD check results

0 errors | 0 warnings | 0 notes


## Reverse dependencies

Checked the two downstream dependencies dplyr and valr, now also when installing dplyr over the CRAN version of bindrcpp, and then installing the release candidate of bindrcpp without updating dplyr.
