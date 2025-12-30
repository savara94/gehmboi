add_library(
    emulator
    STATIC
    cpu/cpu_opcode.cpp
    cpu/cpu_opcode.hpp
    cpu/cpu_ops.cpp
    cpu/cpu_ops.hpp
)

target_include_directories(
    emulator
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)