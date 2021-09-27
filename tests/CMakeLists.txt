cmake_minimum_required(VERSION 3.0)

project(Smart-Tests C CXX)
set(EXECUTABLE_OUTPUT_PATH 
    ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}
)
add_executable(${PROJECT_NAME}
    main.cpp
)
set_property(TARGET ${PROJECT_NAME}
    PROPERTY CXX_STANDARD 20
)
include_directories(
    ../src
    ../doctest
)