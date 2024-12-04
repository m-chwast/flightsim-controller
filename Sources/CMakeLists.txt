set (PROJECT_SOURCES
    main.cpp
    System/startup_stm32f205vetx.s
    System/syscalls.c
    System/sysmem.c
)

set (EXE_NAME "flightsim-controller")

add_executable(${EXE_NAME} ${PROJECT_SOURCES})

target_link_libraries(${EXE_NAME} 
    PRIVATE 
    st_drivers
)

add_custom_command(TARGET ${EXE_NAME} POST_BUILD COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${EXE_NAME}>)
