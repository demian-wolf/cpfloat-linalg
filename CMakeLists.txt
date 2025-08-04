cmake_minimum_required(VERSION 3.14)

project(linalg LANGUAGES CXX)

# -----------------------------------------------------------------------------
# Build options
# -----------------------------------------------------------------------------
option(BUILD_UNIT_TESTS "Build unit tests" ON)

# -----------------------------------------------------------------------------
# CPFloat external location
# -----------------------------------------------------------------------------
set(CPFLOAT_ROOT "$ENV{HOME}/cpfloat" CACHE PATH "Path to CPFloat build root")
set(CPFLOAT_INCLUDE_DIR "${CPFLOAT_ROOT}/build/include" CACHE PATH "CPFloat headers")
set(CPFLOAT_LIBRARY "${CPFLOAT_ROOT}/build/lib/libcpfloat.a" CACHE FILEPATH "CPFloat static lib")

# -----------------------------------------------------------------------------
# Core library target
# -----------------------------------------------------------------------------
add_library(linalg STATIC
    src/linalg_core.cpp
)

target_include_directories(linalg
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        ${CPFLOAT_INCLUDE_DIR}
)

target_link_libraries(linalg
    PUBLIC
        ${CPFLOAT_LIBRARY}
        m
)

target_compile_features(linalg PUBLIC cxx_std_17)

# -----------------------------------------------------------------------------
# Tests
# -----------------------------------------------------------------------------
if(BUILD_UNIT_TESTS)
    include(CTest)

    include(FetchContent)
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.5.1
    )
    FetchContent_MakeAvailable(Catch2)

    enable_testing()

    file(GLOB TEST_SOURCES "tests/*_test.cpp")
    add_executable(linalg_tests ${TEST_SOURCES})

    target_link_libraries(linalg_tests
        PRIVATE
        linalg
        Catch2::Catch2WithMain
    )

    add_test(NAME linalg_all_tests COMMAND linalg_tests)
endif()
