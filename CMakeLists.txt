cmake_minimum_required(VERSION 2.8)
project(testProject)

enable_testing()
find_package(GTest REQUIRED)

add_subdirectory(lib)
add_subdirectory(app)
add_subdirectory(test)