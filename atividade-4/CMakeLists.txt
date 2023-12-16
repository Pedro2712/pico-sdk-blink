project(atividade-4 C CXX ASM)

add_executable(atividade-4 ${CMAKE_SOURCE_DIR}/atividade-4/src/main.c)

pico_set_program_name(atividade-4 "MAIN")
pico_set_program_version(atividade-4 "0.1")

pico_enable_stdio_uart(atividade-4 1)
pico_enable_stdio_usb(atividade-4 0)

# Add the standard library to the build
target_link_libraries(atividade-4 pico_stdlib)

# Add any user requested libraries
target_link_libraries(atividade-4 hardware_clocks)

pico_add_extra_outputs(atividade-4)
load_chips(atividade-4)
