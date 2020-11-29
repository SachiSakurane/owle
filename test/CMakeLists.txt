cmake_minimum_required(VERSION 3.9)

include(External_GTest.cmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(googletest)

add_executable(DSP_Test
        main.cpp concepts/processable.cpp)

target_link_libraries(DSP_Test PRIVATE
        ${GTEST_LIBRARY}
        ${GMOCK_LIBRARY})

gtest_add_tests(
        TARGET      DSP_Test
        TEST_LIST   DSP_Test_Targets)

target_include_directories(DSP_Test PRIVATE
        ${GTEST_INCLUDE_DIRS}
        ${GMOCK_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# set each target to timeout if not finished within 10 sec
set_tests_properties(${DSP_Test_Targets} PROPERTIES TIMEOUT 10)
