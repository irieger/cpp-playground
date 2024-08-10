cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

project(catch2-sample VERSION 0.1.2)

find_package(Catch2 REQUIRED)

add_executable(sample_test  src/catch2_many_assertions.cpp)
target_link_libraries(sample_test  PRIVATE  Catch2::Catch2WithMain)
