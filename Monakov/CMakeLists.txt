cmake_minimum_required(VERSION 2.8)

project(monakov)

set(SRC_ROOT "${PROJECT_SOURCE_DIR}/src")

set(HEADERS
    ${SRC_ROOT}/t9.h
    )

set(SOURCES
    ${SRC_ROOT}/main.cpp
    )

set(SHARED_SOURCES
    ${SRC_ROOT}/t9.cpp
    )

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${SHARED_SOURCES})


#----------- precompiled -----------
set_target_properties(${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "${STDAFX_H}")
cotire(${PROJECT_NAME})
#-------------- tests --------------
set(TEST_PROJECT test_${PROJECT_NAME})
add_test(NAME ${TEST_PROJECT} COMMAND ${TEST_PROJECT})

add_subdirectory(tests)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
enable_testing()
