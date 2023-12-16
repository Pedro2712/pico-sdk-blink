project(atividade-3 C CXX ASM)

add_executable(atividade-3 ${CMAKE_SOURCE_DIR}/atividade-3/src/main.c)

pico_set_program_name(atividade-3 "MAIN")
pico_set_program_version(atividade-3 "0.1")

pico_enable_stdio_uart(atividade-3 1)
pico_enable_stdio_usb(atividade-3 0)

# Add the standard library to the build
target_link_libraries(atividade-3 pico_stdlib)

# Add any user requested libraries
target_link_libraries(atividade-3 hardware_clocks)

pico_add_extra_outputs(atividade-3)
load_chips(atividade-3)
