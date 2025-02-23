add_library(hal_driver
    hal_driver_init.c
    hal_driver_irq_callbacks.c
)

target_link_libraries(hal_driver
    PRIVATE st_drivers
)