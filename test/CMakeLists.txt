set(TEST_SOURCES "main.cpp")
set(TEST_MAIN "${PROJECT}_unit_tests")
add_executable(${TEST_MAIN} ${TEST_SOURCES})

if(WIN32)
    set(TEST_FLAGS "/Od")
    target_link_libraries(${TEST_MAIN} PRIVATE ${LIBRARY_NAME} gtest)
endif()
if(UNIX)
    set(TEST_FLAGS "-O0;-g")
    target_link_libraries(${TEST_MAIN} PRIVATE ${LIBRARY_NAME} gtest pthread)
endif()

target_compile_options(${TEST_MAIN} PUBLIC ${TEST_FLAGS})
target_compile_features(${TEST_MAIN} PUBLIC cxx_std_17)
target_set_warnings(TARGET ${TEST_MAIN} ENABLE OFF AS_ERROR OFF)

add_test(NAME ${LIBRARY_NAME}.${TEST_MAIN} COMMAND ${TEST_MAIN})

if(USE_GCOV)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        set(COVERAGE_MAIN "${PROJECT}_coverage")
        set(COVERAGE_LCOV_EXCLUDES 
        "${PROJECT_SOURCE_DIR}/external/*"
        "${PROJECT_SOURCE_DIR}/app/*"
        "${CONAN_GTEST_ROOT}/*"
        "${CONAN_BOOST_ROOT}/*")
        setup_target_for_coverage_lcov(
            NAME ${COVERAGE_MAIN}
            EXECUTABLE ctest
            DEPENDENCIES ${TEST_MAIN}
        )
    else()
        message("You must use a GNU or Clang Compiler for CodeCoverage!")
    endif()
endif()