set (PROJECT_SOURCES
    main.cpp
    System/startup_stm32f205vetx.s
    System/system_stm32f2xx.c
    System/syscalls.c
    System/sysmem.c
    System/stm32f2xx_it.c
)

set (EXE_NAME "flightsim-controller")

add_executable(${EXE_NAME} ${PROJECT_SOURCES})

include_directories(
    # all libs should have access to sources
    PRIVATE "${CMAKE_SOURCE_DIR}/Sources"
)

target_link_libraries(${EXE_NAME} 
    PRIVATE hal_driver 
    drivers
    utils
    # external libraries
    st_drivers
)

add_custom_command(TARGET ${EXE_NAME} POST_BUILD COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${EXE_NAME}>)

add_subdirectory(HALDriver)
add_subdirectory(Drivers)
add_subdirectory(Utils)
