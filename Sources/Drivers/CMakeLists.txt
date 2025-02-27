cmake_minimum_required(VERSION 3.20)

add_library(drivers
    usb.cpp
)

target_link_libraries(drivers
    PRIVATE st_drivers
    utils
)
