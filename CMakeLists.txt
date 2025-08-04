cmake_minimum_required(VERSION 3.10)

project(cpfloat_linalg LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT DEFINED ENV{CPFLOAT_HOME})
  message(FATAL_ERROR "CPFLOAT_HOME is not set.")
endif()

set(CPFLOAT_HOME $ENV{CPFLOAT_HOME})

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${CPFLOAT_HOME}/build/include
)

add_library(cpfloat_linalg STATIC
    src/linalg_core.cpp
)

target_link_libraries(cpfloat_linalg
    ${CPFLOAT_HOME}/build/lib/libcpfloat.a
    m
)

target_compile_options(cpfloat_linalg PRIVATE
    -Wall -Wextra
)

target_link_options(cpfloat_linalg PRIVATE
    -static
)
