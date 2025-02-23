cmake_minimum_required(VERSION 3.20)

if (WIN32)

if (CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "Release")

set (CMAKE_GENERATOR "Unix Makefiles" CACHE INTERNAL "" FORCE)

elseif (CMAKE_BUILD_TYPE STREQUAL "TestDebug")

set (CMAKE_GENERATOR "MinGW Makefiles" CACHE INTERNAL "" FORCE)

endif()

message ("PreLoad.cmake -- Set generator to ${CMAKE_GENERATOR}")

else()

message ("PreLoad.cmake ignored")

endif()