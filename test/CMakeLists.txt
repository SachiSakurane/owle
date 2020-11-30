cmake_minimum_required(VERSION 3.16)

include(External_GTest.cmake)
include(GoogleTest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(TEST_PROJECT_NAME ${CMAKE_PROJECT_NAME}_Test)

add_executable(${TEST_PROJECT_NAME}
        main.cpp
        concepts/base_bus.cpp
        concepts/bidirectional_bus.cpp
        concepts/connectable.cpp
        concepts/processable.cpp
        concepts/readable_bus.cpp
        concepts/writable_bus.cpp
        pipeline/connectable_pipeline.cpp
        pipeline/processable_pipeline.cpp)

target_link_libraries(${TEST_PROJECT_NAME} PRIVATE
        ${GTEST_LIBRARY}
        ${GMOCK_LIBRARY})

gtest_add_tests(
        TARGET      ${TEST_PROJECT_NAME}
        TEST_LIST   ${TEST_PROJECT_NAME}_Targets)

target_include_directories(${TEST_PROJECT_NAME} PRIVATE
        ${GTEST_INCLUDE_DIRS}
        ${GMOCK_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# set each target to timeout if not finished within 10 sec
set_tests_properties(${${TEST_PROJECT_NAME}_Targets} PROPERTIES TIMEOUT 10)
