cmake_minimum_required(VERSION 3.28)

include(pico-sdk/pico_sdk_init.cmake)

project(pico_templates_project C CXX ASM)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)

if (PICO_SDK_VERSION_STRING VERSION_LESS "2.2.0")
	message(FATAL_ERROR "Raspberry Pi Pico SDK version 2.2.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

pico_sdk_init()

# Flatten output directories to the root of the build folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(hello_world)
add_subdirectory(echo_uart)
add_subdirectory(echo_spi)
add_subdirectory(echo_i2c)
add_subdirectory(echo_irq)
