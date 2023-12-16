# Copy the wokwi-api.h file to the build directory
get_filename_component(API_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/test/wokwi-api.h" ABSOLUTE)
add_custom_command(
    OUTPUT "${CMAKE_BINARY_DIR}/wokwi-api.h"  # Output path in the build directory
    COMMAND ${CMAKE_COMMAND} -E copy ${API_HEADER} "${CMAKE_BINARY_DIR}/wokwi-api.h"
    DEPENDS ${API_HEADER}
    COMMENT "Copying wokwi-api.h to build directory"
)

macro(load_chips name)
    # Retrieve all files matching the pattern name.chip.c
    file(GLOB CHIP_C_SOURCES "${CMAKE_SOURCE_DIR}/${name}/test/chip/*.c")

    foreach(CHIP_C_SOURCE ${CHIP_C_SOURCES})
        # Extract file name without extension
        get_filename_component(BASENAME ${CHIP_C_SOURCE} NAME_WE)

        # Compile WASM
        add_custom_target(${name}-chip-${BASENAME}
            COMMAND clang --target=wasm32-unknown-wasi --sysroot=/opt/wasi-libc -nostartfiles -Wl,--import-memory -Wl,--export-table -Wl,--no-entry -Werror -o ${CMAKE_SOURCE_DIR}/${name}/test/chip/${BASENAME}.wasm ${CHIP_C_SOURCE}
            DEPENDS ${CMAKE_SOURCE_DIR}/${name}/test/chip/${BASENAME}.c
        )
    endforeach()
endmacro()
