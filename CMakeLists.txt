cmake_minimum_required(VERSION 3.8)

add_library(smart INTERFACE)
add_library(smart::smart ALIAS smart)
target_include_directories(smart INTERFACE include)
target_compile_features(smart INTERFACE cxx_std_20)