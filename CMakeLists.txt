#############################################################################################################################
# file:  CMakeLists.txt
# brief: Template "CMakeLists.txt" for building of executables and static libraries.
#
# usage: Edit "VARIABLES"-section to suit project requirements.
#        For debug build:
#          cmake -DCMAKE_TOOLCHAIN_FILE=cubeide-gcc.cmake  -S ./ -B Debug -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug
#          make -C Debug VERBOSE=1 -j
#        For release build:
#          cmake -DCMAKE_TOOLCHAIN_FILE=cubeide-gcc.cmake  -S ./ -B Release -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
#          make -C Release VERBOSE=1 -j
#############################################################################################################################
cmake_minimum_required(VERSION 3.20)

###################### CONSTANTS ######################################
set (PROJECT_TYPE_EXECUTABLE          "exe")
set (PROJECT_TYPE_STATIC_LIBRARY      "static-lib")
set (MCPU_CORTEX_M0				      "-mcpu=cortex-m0")
set (MCPU_CORTEX_M0PLUS				  "-mcpu=cortex-m0plus")
set (MCPU_CORTEX_M3				      "-mcpu=cortex-m3")
set (MCPU_CORTEX_M4				      "-mcpu=cortex-m4")
set (MCPU_CORTEX_M7				      "-mcpu=cortex-m7")
set (MCPU_CORTEX_M33				  "-mcpu=cortex-m33")
set (MCPU_CORTEX_M55				  "-mcpu=cortex-m55")
set (MCPU_CORTEX_M85				  "-mcpu=cortex-m85")
set (MFPU_FPV4_SP_D16                 "-mfpu=fpv4-sp-d16")
set (MFPU_FPV5_D16                    "-mfpu=fpv5-d16")
set (RUNTIME_LIBRARY_REDUCED_C        "--specs=nano.specs")
set (RUNTIME_LIBRARY_STD_C            "")
set (RUNTIME_LIBRARY_SYSCALLS_MINIMAL "--specs=nosys.specs")
set (RUNTIME_LIBRARY_SYSCALLS_NONE    "")
set (MFLOAT_ABI_SOFTWARE              "-mfloat-abi=soft")
set (MFLOAT_ABI_HARDWARE              "-mfloat-abi=hard")
set (MFLOAT_ABI_MIX                   "-mfloat-abi=softfp")
#######################################################################

###################### VARIABLES ######################################
set (PROJECT_NAME             "flightsim-controller")
set (PROJECT_TYPE             "exe")
set (LINKER_SCRIPT            "../STM32F205VETX_FLASH.ld")
set (MCPU                     "-mcpu=Cortex-M3")
set (MFLOAT_ABI               "")
set (RUNTIME_LIBRARY          "--specs=nano.specs")
set (RUNTIME_LIBRARY_SYSCALLS "--specs=nosys.specs")


set (PROJECT_SOURCES
	# LIST SOURCE FILES HERE
	Startup/startup_stm32f205vetx.s
	Sources/main.cpp
	Sources/syscalls.c
	Sources/sysmem.c


	)

set (PROJECT_DEFINES
	# LIST COMPILER DEFINITIONS HERE

    )

set (PROJECT_INCLUDES
	# LIST INCLUDE DIRECTORIES HERE

    )

############ MODIFY ACCORDING TO REQUIREMENTS) ########################

#######################################################################

################## PROJECT SETUP ######################################
project(${PROJECT_NAME} C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (OPTIMIZATION_LEVEL "-Og")


# Check if requested build is supported
set(allowableBuildTypes Debug Release TestDebug)	# list of all available builds is here
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY
STRINGS "${allowableBuildTypes}")
# set default build type to Debug, throw error if build type not supported
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
elseif(NOT CMAKE_BUILD_TYPE IN_LIST allowableBuildTypes)
	message(FATAL_ERROR "Invalid build type: ${CMAKE_BUILD_TYPE}")
endif()


if(${CMAKE_BUILD_TYPE} STREQUAL ["Debug"|"Release"])
	set (TOOLCHAIN_OPTIONS "${MCPU} ${MFPU} ${MFLOAT_ABI} ${RUNTIME_LIBRARY} \
  		-ffunction-sections -fdata-sections -mthumb -fstack-usage")
  	set (CMAKE_EXE_LINKER_FLAGS "-T${LINKER_SCRIPT} ${RUNTIME_LIBRARY_SYSCALLS} \
		-Wl,-Map=test.map -Wl,--gc-sections -static -Wl,--start-group -lc -lm -Wl,--end-group")

	if (${PROJECT_TYPE} MATCHES ${PROJECT_TYPE_EXECUTABLE})
		add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
		add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${CMAKE_PROJECT_NAME}>)
	elseif (${PROJECT_TYPE} MATCHES ${PROJECT_TYPE_STATIC_LIBRARY})
		add_library(${PROJECT_NAME} ${PROJECT_SOURCES})
	endif()
	
	add_compile_definitions (${PROJECT_DEFINES})
	include_directories (${PROJECT_INCLUDES})
	  
elseif(${CMAKE_BUILD_TYPE} STREQUAL "TestDebug")

	set (TOOLCHAIN_OPTIONS "")

	add_subdirectory(Tests)
	
endif()


set (CMAKE_EXECUTABLE_SUFFIX ".elf")
set (CMAKE_STATIC_LIBRARY_SUFFIX ".a")

set (COMMON_C_CXX_FLAGS "${TOOLCHAIN_OPTIONS} ${OPTIMIZATION_LEVEL} \
	-Wall -Werror")

set (CMAKE_C_FLAGS "${COMMON_C_CXX_FLAGS}")
set (CMAKE_CXX_FLAGS "${COMMON_C_CXX_FLAGS} -fno-exceptions -fno-rtti -fno-use-cxa-atexit")

set (CMAKE_ASM_FLAGS "${CMAKE_C_FLAGS} -x assembler-with-cpp")
