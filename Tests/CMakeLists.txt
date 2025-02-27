cmake_minimum_required(VERSION 3.20)

# load google test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)


# add test modules


add_executable(test_exe test.cpp)

include_directories(
  "${CMAKE_SOURCE_DIR}/Sources"
)

add_subdirectory(Utils)

target_link_libraries(
    test_exe
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_exe)
