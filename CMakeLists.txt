cmake_minimum_required(VERSION 3.8)

set(WARNINGS_AS_ERRORS_FOR_SMART OFF CACHE BOOL "ON iff you want to treat warnings as errors")

add_library(smart INTERFACE)
add_library(smart::smart ALIAS smart)

if(WARNINGS_AS_ERRORS_FOR_SMART)
    target_include_directories(smart INTERFACE include)
else()
    target_include_directories(smart SYSTEM INTERFACE include)
endif()
target_compile_features(smart INTERFACE cxx_std_20)