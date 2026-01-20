set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

add_library(
    emulator
    STATIC
    cpu/cpu_ops.cpp
    cpu/cpu_ops.hpp
    cpu/cpu_registers.hpp
    cpu/cpu_registers.cpp
    cpu/cpu_opcode.cpp
    cpu/cpu_opcode.hpp
)

target_include_directories(
    emulator
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)