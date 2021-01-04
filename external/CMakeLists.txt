add_library(${LIBRARY_LINALG} INTERFACE )
target_include_directories(${LIBRARY_LINALG} INTERFACE linalg)

#Loguru
file(GLOB LOGURU_SOURCES "loguru/*.cpp")
add_library(${LIBRARY_LOG} STATIC ${LOGURU_SOURCES})
target_include_directories(${LIBRARY_LOG} PUBLIC loguru)
if(UNIX)
    target_link_libraries(${LIBRARY_LOG} PUBLIC pthread dl)
endif()

#Celero
if(USE_BENCHMARKS)
    add_subdirectory(Celero)
endif()
