cmake_minimum_required(VERSION 3.20)

set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/Sources/Utils")

add_executable(utils_tests
    ${SOURCE_DIR}/circ_buffer.cpp  
    circ_buffer_tests.cpp
    
)

target_link_libraries(utils_tests
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(utils_tests)
