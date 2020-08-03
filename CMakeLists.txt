cmake_minimum_required(VERSION 3.15)
project(CRC LANGUAGES CXX VERSION 0.0.1)

include(GNUInstallDirs)

add_subdirectory(include)

include(cmake/googletest.cmake)
include_googletest()

enable_testing()
add_subdirectory(test)