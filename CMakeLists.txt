cmake_minimum_required(VERSION 3.14)

project(gehmboi)

add_subdirectory(src/emulator)
add_subdirectory(tests)

find_package(fmt CONFIG REQUIRED)

add_executable(gehmboi main.cpp)

target_link_libraries(gehmboi PRIVATE fmt::fmt)