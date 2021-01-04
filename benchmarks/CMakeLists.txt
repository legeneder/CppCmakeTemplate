if(USE_BENCHMARKS)
    set(BENCHMARK_FILES "main.cpp")
    set(BENCHMARK_MAIN "${PROJECT}_benchmarks")
    if(WIN32)
        set(BENCHMARK_FLAGS "/Ox")
    endif()
    if(UNIX)
        set(BENCHMARK_FLAGS "-O3")


    endif()
    add_executable(${BENCHMARK_MAIN} ${BENCHMARK_FILES})
    target_compile_options(${BENCHMARK_MAIN} PUBLIC ${BENCHMARK_FLAGS})
    #target_compile_features(${LIBRARY_NAME} PUBLIC cxx_std_17)
    target_link_libraries(${BENCHMARK_MAIN} PUBLIC ${LIBRARY_NAME})
    target_link_libraries(${BENCHMARK_MAIN} PUBLIC ${LIBRARY_BENCH})
    target_set_warnings(TARGET ${MAIN} ENABLE OFF AS_ERROR OFF)

endif()