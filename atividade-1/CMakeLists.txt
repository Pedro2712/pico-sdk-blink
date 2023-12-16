project(atividade-1 C CXX ASM)

add_executable(atividade-1 ${CMAKE_SOURCE_DIR}/atividade-1/src/main.c)

pico_set_program_name(atividade-1 "MAIN")
pico_set_program_version(atividade-1 "0.1")

pico_enable_stdio_uart(atividade-1 1)
pico_enable_stdio_usb(atividade-1 0)

# Add the standard library to the build
target_link_libraries(atividade-1 pico_stdlib)

# Add any user requested libraries
target_link_libraries(atividade-1 hardware_clocks)

pico_add_extra_outputs(atividade-1)
load_chips(atividade-1)
