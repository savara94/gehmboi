#include <gtest/gtest.h>

#include "emulator/emulator_executor.hpp"

using namespace gehmboi::emulator;

TEST(EmulatorExecutor, SetAndGetRegisters) {
    Executor executor;
    CPURegisters registers;

    registers.setR16(CPURegister16Enum::BC, 0x1234);
    executor.setRegisters(registers);

    CPURegisters retrievedRegisters = executor.getRegisters();
    EXPECT_EQ(retrievedRegisters.getR16(CPURegister16Enum::BC), 0x1234);
}