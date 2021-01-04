cmake_minimum_required(VERSION 3.10)

set(PROJECT "CppTemplate")


project("${PROJECT}" VERSION 1.0.0 LANGUAGES CXX)

#Global CMake variables are set here
set(CMAKe_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

# Project Library Names
set(LIBRARY_NAME MyLib)
set(LIBRARY_LINALG "${PROJECT}_LinALg")
set(MAIN "${PROJECT}_Executable")

set(LIBRARY_LOG loguru)
set(LIBRARY_BENCH celero)

#options
option(USE_GCOV "Create a GCov-enabled." OFF)
OPTION(USE_BENCHMARKS "Create a Benchmark-enabled build" OFF)

# Configuration Files
configure_file("${PROJECT_SOURCE_DIR}/include/ProjectConfig.h.in"
                "${PROJECT_BINARY_DIR}/ProjectConfig.h" @ONLY)     
            
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(Documentation)
include(CTest)
if(USE_GCOV)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        include(CodeCoverage)
    else()
        message("You must use a GNU or Clang Compiler for CodeCoverage!")
    endif()
endif()

#add conan packages
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

#Add externals
add_subdirectory("external")
add_subdirectory("src")
add_subdirectory("app")
add_subdirectory("test")
add_subdirectory("benchmarks")

