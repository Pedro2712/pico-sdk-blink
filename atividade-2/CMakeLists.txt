project(atividade-2 C CXX ASM)

add_executable(atividade-2 ${CMAKE_SOURCE_DIR}/atividade-2/src/main.c)

pico_set_program_name(atividade-2 "MAIN")
pico_set_program_version(atividade-2 "0.1")

pico_enable_stdio_uart(atividade-2 1)
pico_enable_stdio_usb(atividade-2 0)

# Add the standard library to the build
target_link_libraries(atividade-2 pico_stdlib)

# Add any user requested libraries
target_link_libraries(atividade-2 hardware_clocks)

pico_add_extra_outputs(atividade-2)
load_chips(atividade-2)
