project(tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

find_package(GTest CONFIG REQUIRED)

add_executable(
  tests
  tests.cpp
)

target_link_libraries(
  tests
  GTest::gtest_main
)

add_executable(
  cpu_tests
  emulator/cpu/cpu_opcode_test.cpp
)

target_link_libraries(
  cpu_tests
  emulator
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)