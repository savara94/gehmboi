#include <gtest/gtest.h>

#include "cpu/cpu_opcode.hpp"

using namespace gehmboi::emulator;

// TEST(CpuOpcode, CpuOpcodeUndefined) {
//   auto operation = Opcode::decode(0xFFU, false);

//   EXPECT_EQ(operation.op, CPUOperationTypeEnum::UNDEFINED);
// }

TEST(CpuOpcode, CpuOpcodeNOP) {
  auto operation = Opcode::decode(0x00, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_0_NOP);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}
