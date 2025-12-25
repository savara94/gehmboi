cmake_minimum_required(VERSION 3.10)

project(gehmboi)

find_package(fmt CONFIG REQUIRED)

add_executable(gehmboi main.cpp)

target_link_libraries(gehmboi PRIVATE fmt::fmt)