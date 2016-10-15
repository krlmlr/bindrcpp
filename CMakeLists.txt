cmake_minimum_required(VERSION 3.6)
project(bindrcpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(R_LIBRARY "~/R-library")
set(R_INCLUDE "/usr/share/R/include")

include_directories(${R_LIBRARY}/Rcpp/include)
include_directories(${R_LIBRARY}/plogr/include)
include_directories(${R_INCLUDE})
include_directories(inst/include)
include_directories(src)

file(GLOB SOURCE_FILES src/*.cpp src/*.c)
add_library(bindrcpp ${SOURCE_FILES})

add_custom_target(
    Rinstall
    # Using MAKEFLAGS=-j$(nproc) didn't work
    COMMAND MAKEFLAGS=-j4 nice R CMD INSTALL --libs-only --no-test-load ${bindrcpp_SOURCE_DIR}
)
