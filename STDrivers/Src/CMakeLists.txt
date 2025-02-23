add_library(st_drivers)

target_compile_definitions(st_drivers PUBLIC
	USE_HAL_DRIVER 
	STM32F205xx
)

target_include_directories(st_drivers PUBLIC
    # General driver includes
    Core/Inc
    Drivers/STM32F2xx_HAL_Driver/Inc
    Drivers/STM32F2xx_HAL_Driver/Inc/Legacy
    Middlewares/Third_Party/FreeRTOS/Source/include
    Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS
    Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3
    Drivers/CMSIS/Device/ST/STM32F2xx/Include
    Drivers/CMSIS/Include
    # USB driver includes
    Middlewares/ST/STM32_USB_Device_Library/Core/Inc
    Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc
    USB_DEVICE/App
    USB_DEVICE/Target
    )
    
target_sources(st_drivers PRIVATE
    Core/Src/gpio.c
    Core/Src/freertos.c
    Core/Src/can.c
    Core/Src/i2c.c
    Core/Src/spi.c
    Core/Src/usart.c
    Core/Src/usb_otg.c
    Core/Src/stm32f2xx_hal_msp.c
    Core/Src/stm32f2xx_hal_timebase_tim.c
    Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_can.c
    Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal.c
    Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_rcc.c
    Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_rcc_ex.c
    Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_cortex.c
    Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_flash.c
    Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_flash_ex.c
    Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_pwr.c
    Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_pwr_ex.c
    Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_gpio.c
    Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_dma.c
    Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_dma_ex.c
    Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_exti.c
    Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_i2c.c
    Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_spi.c
    Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_tim.c
    Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_tim_ex.c
    Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_uart.c
    Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_pcd_ex.c
    Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_pcd.c
    Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_ll_usb.c
    Middlewares/Third_Party/FreeRTOS/Source/croutine.c
    Middlewares/Third_Party/FreeRTOS/Source/event_groups.c
    Middlewares/Third_Party/FreeRTOS/Source/list.c
    Middlewares/Third_Party/FreeRTOS/Source/queue.c
    Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.c
    Middlewares/Third_Party/FreeRTOS/Source/tasks.c
    Middlewares/Third_Party/FreeRTOS/Source/timers.c
    Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.c
    Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c
    Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3/port.c
    # USB drivers
    Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c
    Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c
    Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c
    Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.c
    USB_DEVICE/App/usb_device.c
    USB_DEVICE/App/usbd_cdc_if.c
    USB_DEVICE/App/usbd_desc.c
    USB_DEVICE/Target/usbd_conf.c
)

if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()
