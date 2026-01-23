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
  cpu/cpu_registers_test.cpp
  cpu/cpu_opcode_test.cpp
)

target_link_libraries(
  cpu_tests
  emulator
  GTest::gtest_main
)


add_executable(
  emulator_tests
  emulator/emulator_executor_test.cpp
)

target_link_libraries(
  emulator_tests
  emulator
  GTest::gtest_main
)


include(GoogleTest)
gtest_discover_tests(tests)