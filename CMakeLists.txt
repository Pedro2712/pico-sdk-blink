# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
# set(PICO_SDK_PATH "/home/mathew/src/pico/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Proj C CXX ASM)

set(PICO_CXX_ENABLE_EXCEPTIONS 1)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# # Add executable. Default name is the project name, version 0.1

# add_executable(main src/main.cpp)

# pico_set_program_name(main "MAIN")
# pico_set_program_version(main "0.1")

# pico_enable_stdio_uart(main 1)
# pico_enable_stdio_usb(main 0)

# # Add the standard library to the build
# target_link_libraries(main pico_stdlib)

# # Add any user requested libraries
# target_link_libraries(main hardware_clocks)

# pico_add_extra_outputs(main)

include(chip_sdk_import.cmake)

add_subdirectory(atividade-1)
add_subdirectory(atividade-2)
add_subdirectory(atividade-3)
add_subdirectory(atividade-4)
