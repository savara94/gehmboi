#include <gtest/gtest.h>
#include <vector>

#include "cpu/cpu_opcode.hpp"

using namespace gehmboi::emulator;

// Block 0
TEST(CpuOpcode, CpuOpcode_NOP) {
  auto operation = Opcode::decode(0x00, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_NOP);

  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_LD_R16_IMM16) {
  auto prefix = 0x00;
  auto suffix = 0x01;
  auto table = std::vector<std::tuple<std::string, uint8_t, CPURegister16Enum>>{
      {"BC", 0x00, CPURegister16Enum::BC},
      {"DE", 0x01, CPURegister16Enum::DE},
      {"HL", 0x02, CPURegister16Enum::HL},
      {"SP", 0x03, CPURegister16Enum::SP},
  };

  for (auto &[subtest, dstcode, operand] : table) {
    auto opcode = prefix << 6 | dstcode << 4 | suffix;
    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_LD_R16_IMM16)
        << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R16) << subtest;
    EXPECT_EQ(operation.getOperand1().getReg16(), operand) << subtest;
    EXPECT_FALSE(operation.getOperand1().isDereferenced()) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::IMM16)
        << subtest;
    EXPECT_FALSE(operation.getOperand2().isDereferenced()) << subtest;
  }
}

TEST(CpuOpcode, CpuOpcode_LD_R16MEM_A) {
  auto prefix = 0x00;
  auto suffix = 0x02;

  // Table: subtest name, dst code, operand, increment, decrement
  auto table = std::vector<
      std::tuple<std::string, uint8_t, CPURegister16Enum, bool, bool>>{
      {"BC", 0x00, CPURegister16Enum::BC, false, false},
      {"DE", 0x01, CPURegister16Enum::DE, false, false},
      {"HL+", 0x02, CPURegister16Enum::HL, true, false},
      {"HL-", 0x03, CPURegister16Enum::HL, false, true},
  };

  for (auto &[subtest, dstcode, operand, inc, dec] : table) {
    auto opcode = prefix << 6 | dstcode << 4 | suffix;
    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_LD_R16MEM_A)
        << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R16) << subtest;
    EXPECT_EQ(operation.getOperand1().getReg16(), operand) << subtest;
    EXPECT_EQ(operation.getOperand1().isIncrement(), inc) << subtest;
    EXPECT_EQ(operation.getOperand1().isDecrement(), dec) << subtest;
    EXPECT_TRUE(operation.getOperand1().isDereferenced()) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R8) << subtest;
    EXPECT_EQ(operation.getOperand2().getReg8(), CPURegister8Enum::A) << subtest;
    EXPECT_FALSE(operation.getOperand2().isDereferenced()) << subtest;
  }
}

TEST(CpuOpcode, CpuOpcode_LD_A_R16MEM) {
  auto prefix = 0x00;
  auto suffix = 0x0A;

  // Table: subtest name, dst code, operand, increment, decrement
  auto table = std::vector<
      std::tuple<std::string, uint8_t, CPURegister16Enum, bool, bool>>{
      {"BC", 0x00, CPURegister16Enum::BC, false, false},
      {"DE", 0x01, CPURegister16Enum::DE, false, false},
      {"HL+", 0x02, CPURegister16Enum::HL, true, false},
      {"HL-", 0x03, CPURegister16Enum::HL, false, true},
  };

  for (auto &[subtest, dstcode, operand, inc, dec] : table) {
    auto opcode = prefix << 6 | dstcode << 4 | suffix;
    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_LD_A_R16MEM)
        << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8) << subtest;
    EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A) << subtest;
    EXPECT_FALSE(operation.getOperand1().isDereferenced()) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R16) << subtest;
    EXPECT_EQ(operation.getOperand2().getReg16(), operand) << subtest;
    EXPECT_EQ(operation.getOperand2().isIncrement(), inc) << subtest;
    EXPECT_EQ(operation.getOperand2().isDecrement(), dec) << subtest;
    EXPECT_TRUE(operation.getOperand2().isDereferenced()) << subtest;
  }
}

TEST(CpuOpcode, CpuOpcode_LD_IMM16MEM_SP) {
  auto opcode = 0x08;
  auto operation = Opcode::decode(opcode, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_LD_IMM16MEM_SP);

  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::IMM16);
  EXPECT_TRUE(operation.getOperand1().isDereferenced());

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.getOperand2().getReg16(), CPURegister16Enum::SP);
  EXPECT_FALSE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_INC_R16) {
  auto prefix = 0x00;
  auto suffix = 0x03;

  // Table: subtest name, dst code, operand
  auto table = std::vector<std::tuple<std::string, uint8_t, CPURegister16Enum>>{
      {"BC", 0x00, CPURegister16Enum::BC},
      {"DE", 0x01, CPURegister16Enum::DE},
      {"HL", 0x02, CPURegister16Enum::HL},
      {"SP", 0x03, CPURegister16Enum::SP},
  };

  for (auto &[subtest, dstcode, operand] : table) {
    auto opcode = prefix << 6 | dstcode << 4 | suffix;
    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_INC_R16) << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R16) << subtest;
    EXPECT_EQ(operation.getOperand1().getReg16(), operand) << subtest;
    EXPECT_FALSE(operation.getOperand1().isDereferenced()) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND)
        << subtest;
  }
}

TEST(CpuOpcode, CpuOpcode_DEC_R16) {
  auto prefix = 0x00;
  auto suffix = 0x0B;

  // Table: subtest name, dst code, operand
  auto table = std::vector<std::tuple<std::string, uint8_t, CPURegister16Enum>>{
      {"BC", 0x00, CPURegister16Enum::BC},
      {"DE", 0x01, CPURegister16Enum::DE},
      {"HL", 0x02, CPURegister16Enum::HL},
      {"SP", 0x03, CPURegister16Enum::SP},
  };

  for (auto &[subtest, dstcode, operand] : table) {
    auto opcode = prefix << 6 | dstcode << 4 | suffix;
    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_DEC_R16) << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R16) << subtest;
    EXPECT_EQ(operation.getOperand1().getReg16(), operand) << subtest;
    EXPECT_FALSE(operation.getOperand1().isDereferenced()) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND)
        << subtest;
  }
}

TEST(CpuOpcode, CpuOpcode_ADD_HL_R16) {
  auto prefix = 0x00;
  auto suffix = 0x09;

  // Table: subtest name, dst code, operand
  auto table = std::vector<std::tuple<std::string, uint8_t, CPURegister16Enum>>{
      {"BC", 0x00, CPURegister16Enum::BC},
      {"DE", 0x01, CPURegister16Enum::DE},
      {"HL", 0x02, CPURegister16Enum::HL},
      {"SP", 0x03, CPURegister16Enum::SP},
  };

  for (auto &[subtest, dstcode, operand] : table) {
    auto opcode = prefix << 6 | dstcode << 4 | suffix;
    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_ADD_HL_R16)
        << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R16) << subtest;
    EXPECT_EQ(operation.getOperand1().getReg16(), CPURegister16Enum::HL) << subtest;
    EXPECT_FALSE(operation.getOperand1().isDereferenced()) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R16) << subtest;
    EXPECT_EQ(operation.getOperand2().getReg16(), operand) << subtest;
    EXPECT_FALSE(operation.getOperand2().isDereferenced()) << subtest;
  }
}

TEST(CpuOpcode, CpuOpcode_INC_R8) {
  auto prefix = 0x00;
  auto suffix = 0x04;

  // Table: opcode dst code -> reg8 operand
  auto table = std::vector<std::tuple<std::string, uint8_t, CPURegister8Enum>>({
      {
          "Inc B",
          0x00,
          CPURegister8Enum::B,
      },
      {
          "Inc C",
          0x01,
          CPURegister8Enum::C,
      },
      {
          "Inc D",
          0x02,
          CPURegister8Enum::D,
      },
      {
          "Inc E",
          0x03,
          CPURegister8Enum::E,
      },
      {
          "Inc H",
          0x04,
          CPURegister8Enum::H,
      },
      {
          "Inc L",
          0x05,
          CPURegister8Enum::L,
      },
      {
          "Inc A",
          0x07,
          CPURegister8Enum::A,
      },
  });

  for (auto &[subtest, dest, op] : table) {
    uint8_t opcode = (prefix << 6) | (dest << 3) | suffix;

    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_INC_R8) << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8) << subtest;
    EXPECT_EQ(operation.getOperand1().getReg8(), op) << subtest;
    EXPECT_FALSE(operation.getOperand1().isDereferenced()) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND)
        << subtest;
  }

  // Exception mapping for 0x06 [HL]
  uint8_t opcode = (prefix << 6) | (0x06 << 3) | suffix;
  auto operation = Opcode::decode(opcode, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_INC_R8);

  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.getOperand1().getReg16(), CPURegister16Enum::HL);
  EXPECT_TRUE(operation.getOperand1().isDereferenced());

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_DEC_R8) {
  auto prefix = 0x00;
  auto suffix = 0x05;

  // Table: opcode dst code -> reg8 operand
  auto table = std::vector<std::tuple<std::string, uint8_t, CPURegister8Enum>>({
      {
          "Inc B",
          0x00,
          CPURegister8Enum::B,
      },
      {
          "Inc C",
          0x01,
          CPURegister8Enum::C,
      },
      {
          "Inc D",
          0x02,
          CPURegister8Enum::D,
      },
      {
          "Inc E",
          0x03,
          CPURegister8Enum::E,
      },
      {
          "Inc H",
          0x04,
          CPURegister8Enum::H,
      },
      {
          "Inc L",
          0x05,
          CPURegister8Enum::L,
      },
      {
          "Inc A",
          0x07,
          CPURegister8Enum::A,
      },
  });

  for (auto &[subtest, dest, op] : table) {
    uint8_t opcode = (prefix << 6) | (dest << 3) | suffix;

    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_DEC_R8) << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8) << subtest;
    EXPECT_EQ(operation.getOperand1().getReg8(), op) << subtest;
    EXPECT_FALSE(operation.getOperand1().isDereferenced()) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND)
        << subtest;
  }

  // Exception mapping for 0x06 [HL]
  uint8_t opcode = (prefix << 6) | (0x06 << 3) | suffix;
  auto operation = Opcode::decode(opcode, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_DEC_R8);

  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.getOperand1().getReg16(), CPURegister16Enum::HL);
  EXPECT_TRUE(operation.getOperand1().isDereferenced());

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_LD_R8_IMM8) {
  auto prefix = 0x00;
  auto suffix = 0x06;

  // Table: opcode dst code -> reg8 operand
  auto table = std::vector<std::tuple<std::string, uint8_t, CPURegister8Enum>>({
      {
          "LD B <- IMM8",
          0x00,
          CPURegister8Enum::B,
      },
      {
          "LD C <- IMM8",
          0x01,
          CPURegister8Enum::C,
      },
      {
          "LD D <- IMM8",
          0x02,
          CPURegister8Enum::D,
      },
      {
          "LD E <- IMM8",
          0x03,
          CPURegister8Enum::E,
      },
      {
          "LD H <- IMM8",
          0x04,
          CPURegister8Enum::H,
      },
      {
          "LD L <- IMM8",
          0x05,
          CPURegister8Enum::L,
      },
      {
          "LD A <- IMM8",
          0x07,
          CPURegister8Enum::A,
      },
  });

  for (auto &[subtest, dest, op] : table) {
    uint8_t opcode = (prefix << 6) | (dest << 3) | suffix;

    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_LD_R8_IMM8)
        << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8) << subtest;
    EXPECT_EQ(operation.getOperand1().getReg8(), op) << subtest;
    EXPECT_FALSE(operation.getOperand1().isDereferenced()) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::IMM8)
        << subtest;
    EXPECT_FALSE(operation.getOperand2().isDereferenced()) << subtest;
  }

  // Exception mapping for 0x06 [HL]
  uint8_t opcode = (prefix << 6) | (0x06 << 3) | suffix;
  auto operation = Opcode::decode(opcode, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_LD_R8_IMM8);

  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.getOperand1().getReg16(), CPURegister16Enum::HL);
  EXPECT_TRUE(operation.getOperand1().isDereferenced());

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::IMM8);
  EXPECT_FALSE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_RLCA) {
  auto operation = Opcode::decode(0x07, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_RLCA);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_RRCA) {
  auto operation = Opcode::decode(0x0F, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_RRCA);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_RLA) {
  auto operation = Opcode::decode(0x17, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_RLA);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_RRA) {
  auto operation = Opcode::decode(0x1F, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_RRA);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_DAA) {
  auto operation = Opcode::decode(0x27, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_DAA);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_CPL) {
  auto operation = Opcode::decode(0x2F, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_CPL);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_SCF) {
  auto operation = Opcode::decode(0x37, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_SCF);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_CCF) {
  auto operation = Opcode::decode(0x3F, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_CCF);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_JR_IMM8) {
  auto operation = Opcode::decode(0x18, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_JR_IMM8);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::IMM8);
  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_JR_COND_IMM8) {
  auto prefix = 0x01;
  // Table: opcode condition code -> condition operand
  auto table = std::vector<std::tuple<std::string, uint8_t, CPUConditionEnum>>({
      {
          "JR NZ, IMM8",
          0x00,
          CPUConditionEnum::NZ,
      },
      {
          "JR Z, IMM8",
          0x01,
          CPUConditionEnum::Z,
      },
      {
          "JR NC, IMM8",
          0x02,
          CPUConditionEnum::NC,
      },
      {
          "JR C, IMM8",
          0x03,
          CPUConditionEnum::C,
      },
  });

  for (auto &[subtest, dest, condition] : table) {
    uint8_t opcode = (prefix << 5) | (dest << 3);

    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_JR_COND_IMM8)
        << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::CONDITION)
        << subtest;
    EXPECT_EQ(operation.getOperand1().getCondition(), condition) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::IMM8)
        << subtest;
    EXPECT_FALSE(operation.getOperand2().isDereferenced()) << subtest;
  }
}

TEST(CpuOpcode, CpuOpcode_STOP) {
  auto operation = Opcode::decode(0x10, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_0_STOP);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND);
}

// Block 1

TEST(CpuOpcode, CpuOpcode_LD_R8_R8) {
  auto prefix = 0x01;
  auto operation_type = CPUOperationTypeEnum::BLOCK_1_LD_R8_R8;

  // Table: opcode dest, src -> operand1, operand2
  auto table = std::vector<std::tuple<std::string, uint8_t, CPURegister8Enum>>({
      {
          "B",
          0x00,
          CPURegister8Enum::B,
      },
      {
          "C",
          0x01,
          CPURegister8Enum::C,
      },
      {
          "D",
          0x02,
          CPURegister8Enum::D,
      },
      {
          "E",
          0x03,
          CPURegister8Enum::E,
      },
      {
          "H",
          0x04,
          CPURegister8Enum::H,
      },
      {
          "L",
          0x05,
          CPURegister8Enum::L,
      },
      {
          "A",
          0x07,
          CPURegister8Enum::A,
      },
  });

  for (auto &[srcReg, srcByte, srcOp] : table) {
    for (auto &[dstReg, dstByte, dstOp] : table) {
      uint8_t opcode = (prefix << 6) | (dstByte << 3) | srcByte;
      std::stringstream ss;
      ss << "Subtest: " << dstReg << " <- " << srcReg << " opcode: 0x"
         << std::hex << int(opcode) << std::dec;
      auto subtest_msg = ss.str();

      auto operation = Opcode::decode(opcode, false);

      EXPECT_EQ(operation.getType(), operation_type) << subtest_msg;

      EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8)
          << subtest_msg;
      EXPECT_EQ(operation.getOperand1().getReg8(), dstOp) << subtest_msg;
      EXPECT_FALSE(operation.getOperand1().isDereferenced()) << subtest_msg;

      EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R8)
          << subtest_msg;
      EXPECT_EQ(operation.getOperand2().getReg8(), srcOp) << subtest_msg;
      EXPECT_FALSE(operation.getOperand2().isDereferenced()) << subtest_msg;
    }
  }

  // Exception mapping for 0x06 [HL]
  // [HL] <- A
  auto opcode = (prefix << 6) | (0x06 << 3) | 0x07;
  auto operation = Opcode::decode(opcode, false);
  
  EXPECT_EQ(operation.getType(), operation_type) << opcode;

  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.getOperand1().getReg16(), CPURegister16Enum::HL);
  EXPECT_TRUE(operation.getOperand1().isDereferenced());
  
  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand2().getReg8(), CPURegister8Enum::A);
  EXPECT_FALSE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_LD_HALT) {
  auto operation = Opcode::decode(0x76, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_1_LD_HALT);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND);
}

// Block 2

TEST(CpuOpcode, CpuOpcode_ADD_A_R8) {
  auto prefix = 0x80;

  // Table: opcode dst code -> reg8 operand
  auto table = std::vector<std::tuple<std::string, uint8_t, CPURegister8Enum>>({
      {
          "ADD A <- B",
          0x00,
          CPURegister8Enum::B,
      },
      {
          "ADD A <- C",
          0x01,
          CPURegister8Enum::C,
      },
      {
          "ADD A <- D",
          0x02,
          CPURegister8Enum::D,
      },
      {
          "ADD A <- E",
          0x03,
          CPURegister8Enum::E,
      },
      {
          "ADD A <- H",
          0x04,
          CPURegister8Enum::H,
      },
      {
          "ADD A <- L",
          0x05,
          CPURegister8Enum::L,
      },
      {
          "ADD A <- A",
          0x07,
          CPURegister8Enum::A,
      },
  });

  for (auto &[subtest, dest, op] : table) {
    uint8_t opcode = prefix | dest;

    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_2_ADD_A_R8) << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8) << subtest;
    EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A) << subtest;
    EXPECT_FALSE(operation.getOperand1().isDereferenced()) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R8) << subtest;
    EXPECT_EQ(operation.getOperand2().getReg8(), op) << subtest;
    EXPECT_FALSE(operation.getOperand2().isDereferenced()) << subtest;
  }

  // Exception mapping for 0x06 [HL]
  uint8_t opcode = prefix | 0x06;
  auto operation = Opcode::decode(opcode, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_2_ADD_A_R8);

  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A);
  EXPECT_FALSE(operation.getOperand1().isDereferenced());

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.getOperand2().getReg16(), CPURegister16Enum::HL);
  EXPECT_TRUE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_ADC_A_R8) {
  auto prefix = 0x88;

  // Table: opcode dst code -> reg8 operand
  auto table = std::vector<std::tuple<std::string, uint8_t, CPURegister8Enum>>({
      {
          "ADC A <- B",
          0x00,
          CPURegister8Enum::B,
      },
      {
          "ADC A <- C",
          0x01,
          CPURegister8Enum::C,
      },
      {
          "ADC A <- D",
          0x02,
          CPURegister8Enum::D,
      },
      {
          "ADC A <- E",
          0x03,
          CPURegister8Enum::E,
      },
      {
          "ADC A <- H",
          0x04,
          CPURegister8Enum::H,
      },
      {
          "ADC A <- L",
          0x05,
          CPURegister8Enum::L,
      },
      {
          "ADC A <- A",
          0x07,
          CPURegister8Enum::A,
      },
  });

  for (auto &[subtest, dest, op] : table) {
    uint8_t opcode = prefix | dest;

    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_2_ADC_A_R8) << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8) << subtest;
    EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A) << subtest;
    EXPECT_FALSE(operation.getOperand1().isDereferenced()) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R8) << subtest;
    EXPECT_EQ(operation.getOperand2().getReg8(), op) << subtest;
    EXPECT_FALSE(operation.getOperand2().isDereferenced()) << subtest;
  }

  // Exception mapping for 0x06 [HL]
  uint8_t opcode = prefix | 0x06;
  auto operation = Opcode::decode(opcode, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_2_ADC_A_R8);

  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A);
  EXPECT_FALSE(operation.getOperand1().isDereferenced());

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.getOperand2().getReg16(), CPURegister16Enum::HL);
  EXPECT_TRUE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_SUB_A_R8) {
  auto prefix = 0x90;

  // Table: opcode dst code -> reg8 operand
  auto table = std::vector<std::tuple<std::string, uint8_t, CPURegister8Enum>>({
      {
          "SUB A <- B",
          0x00,
          CPURegister8Enum::B,
      },
      {
          "SUB A <- C",
          0x01,
          CPURegister8Enum::C,
      },
      {
          "SUB A <- D",
          0x02,
          CPURegister8Enum::D,
      },
      {
          "SUB A <- E",
          0x03,
          CPURegister8Enum::E,
      },
      {
          "SUB A <- H",
          0x04,
          CPURegister8Enum::H,
      },
      {
          "SUB A <- L",
          0x05,
          CPURegister8Enum::L,
      },
      {
          "SUB A <- A",
          0x07,
          CPURegister8Enum::A,
      },
  });

  for (auto &[subtest, dest, op] : table) {
    uint8_t opcode = prefix | dest;

    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_2_SUB_A_R8) << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8) << subtest;
    EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A) << subtest;
    EXPECT_FALSE(operation.getOperand1().isDereferenced()) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R8) << subtest;
    EXPECT_EQ(operation.getOperand2().getReg8(), op) << subtest;
    EXPECT_FALSE(operation.getOperand2().isDereferenced()) << subtest;
  }

  // Exception mapping for 0x06 [HL]
  uint8_t opcode = prefix | 0x06;
  auto operation = Opcode::decode(opcode, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_2_SUB_A_R8);

  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A);
  EXPECT_FALSE(operation.getOperand1().isDereferenced());

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.getOperand2().getReg16(), CPURegister16Enum::HL);
  EXPECT_TRUE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_SBC_A_R8) {
  auto prefix = 0x98;

  // Table: opcode dst code -> reg8 operand
  auto table = std::vector<std::tuple<std::string, uint8_t, CPURegister8Enum>>({
      {
          "SBC A <- B",
          0x00,
          CPURegister8Enum::B,
      },
      {
          "SBC A <- C",
          0x01,
          CPURegister8Enum::C,
      },
      {
          "SBC A <- D",
          0x02,
          CPURegister8Enum::D,
      },
      {
          "SBC A <- E",
          0x03,
          CPURegister8Enum::E,
      },
      {
          "SBC A <- H",
          0x04,
          CPURegister8Enum::H,
      },
      {
          "SBC A <- L",
          0x05,
          CPURegister8Enum::L,
      },
      {
          "SBC A <- A",
          0x07,
          CPURegister8Enum::A,
      },
  });

  for (auto &[subtest, dest, op] : table) {
    uint8_t opcode = prefix | dest;

    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_2_SBC_A_R8) << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8) << subtest;
    EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A) << subtest;
    EXPECT_FALSE(operation.getOperand1().isDereferenced()) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R8) << subtest;
    EXPECT_EQ(operation.getOperand2().getReg8(), op) << subtest;
    EXPECT_FALSE(operation.getOperand2().isDereferenced()) << subtest;
  }

  // Exception mapping for 0x06 [HL]
  uint8_t opcode = prefix | 0x06;
  auto operation = Opcode::decode(opcode, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_2_SBC_A_R8);

  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A);
  EXPECT_FALSE(operation.getOperand1().isDereferenced());

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.getOperand2().getReg16(), CPURegister16Enum::HL);
  EXPECT_TRUE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_AND_A_R8) {
  auto prefix = 0xA0;

  // Table: opcode dst code -> reg8 operand
  auto table = std::vector<std::tuple<std::string, uint8_t, CPURegister8Enum>>({
      {
          "AND A <- B",
          0x00,
          CPURegister8Enum::B,
      },
      {
          "AND A <- C",
          0x01,
          CPURegister8Enum::C,
      },
      {
          "AND A <- D",
          0x02,
          CPURegister8Enum::D,
      },
      {
          "AND A <- E",
          0x03,
          CPURegister8Enum::E,
      },
      {
          "AND A <- H",
          0x04,
          CPURegister8Enum::H,
      },
      {
          "AND A <- L",
          0x05,
          CPURegister8Enum::L,
      },
      {
          "AND A <- A",
          0x07,
          CPURegister8Enum::A,
      },
  });

  for (auto &[subtest, dest, op] : table) {
    uint8_t opcode = prefix | dest;

    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_2_AND_A_R8) << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8) << subtest;
    EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A) << subtest;
    EXPECT_FALSE(operation.getOperand1().isDereferenced()) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R8) << subtest;
    EXPECT_EQ(operation.getOperand2().getReg8(), op) << subtest;
    EXPECT_FALSE(operation.getOperand2().isDereferenced()) << subtest;
  }

  // Exception mapping for 0x06 [HL]
  uint8_t opcode = prefix | 0x06;
  auto operation = Opcode::decode(opcode, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_2_AND_A_R8);

  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A);
  EXPECT_FALSE(operation.getOperand1().isDereferenced());

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.getOperand2().getReg16(), CPURegister16Enum::HL);
  EXPECT_TRUE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_XOR_A_R8) {
  auto prefix = 0xA8;

  // Table: opcode dst code -> reg8 operand
  auto table = std::vector<std::tuple<std::string, uint8_t, CPURegister8Enum>>({
      {
          "XOR A <- B",
          0x00,
          CPURegister8Enum::B,
      },
      {
          "XOR A <- C",
          0x01,
          CPURegister8Enum::C,
      },
      {
          "XOR A <- D",
          0x02,
          CPURegister8Enum::D,
      },
      {
          "XOR A <- E",
          0x03,
          CPURegister8Enum::E,
      },
      {
          "XOR A <- H",
          0x04,
          CPURegister8Enum::H,
      },
      {
          "XOR A <- L",
          0x05,
          CPURegister8Enum::L,
      },
      {
          "XOR A <- A",
          0x07,
          CPURegister8Enum::A,
      },
  });

  for (auto &[subtest, dest, op] : table) {
    uint8_t opcode = prefix | dest;

    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_2_XOR_A_R8) << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8) << subtest;
    EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A) << subtest;
    EXPECT_FALSE(operation.getOperand1().isDereferenced()) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R8) << subtest;
    EXPECT_EQ(operation.getOperand2().getReg8(), op) << subtest;
    EXPECT_FALSE(operation.getOperand2().isDereferenced()) << subtest;
  }

  // Exception mapping for 0x06 [HL]
  uint8_t opcode = prefix | 0x06;
  auto operation = Opcode::decode(opcode, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_2_XOR_A_R8);

  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A);
  EXPECT_FALSE(operation.getOperand1().isDereferenced());

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.getOperand2().getReg16(), CPURegister16Enum::HL);
  EXPECT_TRUE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_OR_A_R8) {
  auto prefix = 0xB0;

  // Table: opcode dst code -> reg8 operand
  auto table = std::vector<std::tuple<std::string, uint8_t, CPURegister8Enum>>({
      {
          "OR A <- B",
          0x00,
          CPURegister8Enum::B,
      },
      {
          "OR A <- C",
          0x01,
          CPURegister8Enum::C,
      },
      {
          "OR A <- D",
          0x02,
          CPURegister8Enum::D,
      },
      {
          "OR A <- E",
          0x03,
          CPURegister8Enum::E,
      },
      {
          "OR A <- H",
          0x04,
          CPURegister8Enum::H,
      },
      {
          "OR A <- L",
          0x05,
          CPURegister8Enum::L,
      },
      {
          "OR A <- A",
          0x07,
          CPURegister8Enum::A,
      },
  });

  for (auto &[subtest, dest, op] : table) {
    uint8_t opcode = prefix | dest;

    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_2_OR_A_R8) << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8) << subtest;
    EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A) << subtest;
    EXPECT_FALSE(operation.getOperand1().isDereferenced()) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R8) << subtest;
    EXPECT_EQ(operation.getOperand2().getReg8(), op) << subtest;
    EXPECT_FALSE(operation.getOperand2().isDereferenced()) << subtest;
  }

  // Exception mapping for 0x06 [HL]
  uint8_t opcode = prefix | 0x06;
  auto operation = Opcode::decode(opcode, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_2_OR_A_R8);

  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A);
  EXPECT_FALSE(operation.getOperand1().isDereferenced());

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.getOperand2().getReg16(), CPURegister16Enum::HL);
  EXPECT_TRUE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_CP_A_R8) {
  auto prefix = 0xB8;

  // Table: opcode dst code -> reg8 operand
  auto table = std::vector<std::tuple<std::string, uint8_t, CPURegister8Enum>>({
      {
          "CP A <- B",
          0x00,
          CPURegister8Enum::B,
      },
      {
          "CP A <- C",
          0x01,
          CPURegister8Enum::C,
      },
      {
          "CP A <- D",
          0x02,
          CPURegister8Enum::D,
      },
      {
          "CP A <- E",
          0x03,
          CPURegister8Enum::E,
      },
      {
          "CP A <- H",
          0x04,
          CPURegister8Enum::H,
      },
      {
          "CP A <- L",
          0x05,
          CPURegister8Enum::L,
      },
      {
          "CP A <- A",
          0x07,
          CPURegister8Enum::A,
      },
  });

  for (auto &[subtest, dest, op] : table) {
    uint8_t opcode = prefix | dest;

    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_2_CP_A_R8) << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8) << subtest;
    EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A) << subtest;
    EXPECT_FALSE(operation.getOperand1().isDereferenced()) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R8) << subtest;
    EXPECT_EQ(operation.getOperand2().getReg8(), op) << subtest;
    EXPECT_FALSE(operation.getOperand2().isDereferenced()) << subtest;
  }

  // Exception mapping for 0x06 [HL]
  uint8_t opcode = prefix | 0x06;
  auto operation = Opcode::decode(opcode, false);
  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_2_CP_A_R8);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A);
  EXPECT_FALSE(operation.getOperand1().isDereferenced());

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.getOperand2().getReg16(), CPURegister16Enum::HL);
  EXPECT_TRUE(operation.getOperand2().isDereferenced());
}

// Block 3

TEST(CPUOpcode, CpuOpcode_ADD_A_IMM8) {
  auto operation = Opcode::decode(0xC6, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_ADD_A_IMM8);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A);

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::IMM8);
  EXPECT_FALSE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_ADC_A_IMM8) {
  auto operation = Opcode::decode(0xCE, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_ADC_A_IMM8);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A);

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::IMM8);
  EXPECT_FALSE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_SUB_A_IMM8) {
  auto operation = Opcode::decode(0xD6, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_SUB_A_IMM8);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A);

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::IMM8);
  EXPECT_FALSE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_SBC_A_IMM8) {
  auto operation = Opcode::decode(0xDE, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_SBC_A_IMM8);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A);

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::IMM8);
  EXPECT_FALSE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_AND_A_IMM8) {
  auto operation = Opcode::decode(0xE6, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_AND_A_IMM8);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A);

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::IMM8);
  EXPECT_FALSE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_XOR_A_IMM8) {
  auto operation = Opcode::decode(0xEE, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_XOR_A_IMM8);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A);

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::IMM8);
  EXPECT_FALSE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_OR_A_IMM8) {
  auto operation = Opcode::decode(0xF6, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_OR_A_IMM8);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A);

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::IMM8);
  EXPECT_FALSE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_CP_A_IMM8) {
  auto operation = Opcode::decode(0xFE, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_CP_A_IMM8);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A);

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::IMM8);
  EXPECT_FALSE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_RET_COND) {
  auto prefix = 0xC0;
  // Table: opcode condition code -> condition operand
  auto table = std::vector<std::tuple<std::string, uint8_t, CPUConditionEnum>>({
      {
          "RET NZ",
          0x00,
          CPUConditionEnum::NZ,
      },
      {
          "RET Z",
          0x01,
          CPUConditionEnum::Z,
      },
      {
          "RET NC",
          0x02,
          CPUConditionEnum::NC,
      },
      {
          "RET C",
          0x03,
          CPUConditionEnum::C,
      },
  });

  for (auto &[subtest, dest, condition] : table) {
    uint8_t opcode = prefix | dest << 3;

    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_RET_COND) << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::CONDITION)
        << subtest;
    EXPECT_EQ(operation.getOperand1().getCondition(), condition) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND)
        << subtest;
  }
}

TEST(CpuOpcode, CpuOpcode_RET) {
  auto operation = Opcode::decode(0xC9, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_RET);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_RETI) {
  auto operation = Opcode::decode(0xD9, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_RETI);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_JP_COND_IMM16) {
  auto prefix = 0xC0;
  auto suffix = 0x02;
  // Table: opcode condition code -> condition operand
  auto table = std::vector<std::tuple<std::string, uint8_t, CPUConditionEnum>>({
      {
          "JP NZ, IMM16",
          0x00,
          CPUConditionEnum::NZ,
      },
      {
          "JP Z, IMM16",
          0x01,
          CPUConditionEnum::Z,
      },
      {
          "JP NC, IMM16",
          0x02,
          CPUConditionEnum::NC,
      },
      {
          "JP C, IMM16",
          0x03,
          CPUConditionEnum::C,
      },
  });

  for (auto &[subtest, dest, condition] : table) {
    uint8_t opcode = prefix | dest << 3 | suffix;

    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_JP_COND_IMM16)
        << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::CONDITION)
        << subtest;
    EXPECT_EQ(operation.getOperand1().getCondition(), condition) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::IMM16)
        << subtest;
  }
}

TEST(CpuOpcode, CpuOpcode_JP_IMM16) {
  auto operation = Opcode::decode(0xC3, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_JP_IMM16);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::IMM16);
  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_JP_HL) {
  auto operation = Opcode::decode(0xE9, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_JP_HL);

  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.getOperand1().getReg16(), CPURegister16Enum::HL);

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_CALL_COND_IMM16) {
  auto prefix = 0xC0;
  auto suffix = 0x04;
  // Table: opcode condition code -> condition operand
  auto table = std::vector<std::tuple<std::string, uint8_t, CPUConditionEnum>>({
      {
          "CALL NZ, IMM16",
          0x00,
          CPUConditionEnum::NZ,
      },
      {
          "CALL Z, IMM16",
          0x01,
          CPUConditionEnum::Z,
      },
      {
          "CALL NC, IMM16",
          0x02,
          CPUConditionEnum::NC,
      },
      {
          "CALL C, IMM16",
          0x03,
          CPUConditionEnum::C,
      },
  });

  for (auto &[subtest, dest, condition] : table) {
    uint8_t opcode = prefix | dest << 3 | suffix;

    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_CALL_COND_IMM16)
        << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::CONDITION)
        << subtest;
    EXPECT_EQ(operation.getOperand1().getCondition(), condition) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::IMM16)
        << subtest;
  }
}

TEST(CpuOpcode, CpuOpcode_CALL_IMM16) {
  auto operation = Opcode::decode(0xCD, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_CALL_IMM16);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::IMM16);
  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_RST_TGT3) {
  auto prefix = 0xC0;
  auto suffix = 0x07;

  // Table: opcode target code -> value
  auto table = std::vector<std::tuple<std::string, uint8_t, uint8_t>>({
      {
          "RST 00H",
          0x00,
          0x00,
      },
      {
          "RST 08H",
          0x01,
          0x08,
      },
      {
          "RST 10H",
          0x02,
          0x10,
      },
      {
          "RST 18H",
          0x03,
          0x18,
      },
      {
          "RST 20H",
          0x04,
          0x20,
      },
      {
          "RST 28H",
          0x05,
          0x28,
      },
      {
          "RST 30H",
          0x06,
          0x30,
      },
      {
          "RST 38H",
          0x07,
          0x38,
      },
  });

  for (auto &[subtest, dest, value] : table) {
    uint8_t opcode = prefix | dest << 3 | suffix;

    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_RST_TGT3) << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::LITERAL)
        << subtest;
    EXPECT_EQ(operation.getOperand1().getLiteral(), value) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND)
        << subtest;
  }
}

TEST(CpuOpcode, CpuOpcode_POP_R16_STK) {
  auto prefix = 0xC0;
  auto suffix = 0x01;

  // Table: opcode register code -> reg16 operand
  auto table =
      std::vector<std::tuple<std::string, uint8_t, CPURegister16Enum>>({
          {
              "POP BC",
              0x00,
              CPURegister16Enum::BC,
          },
          {
              "POP DE",
              0x01,
              CPURegister16Enum::DE,
          },
          {
              "POP HL",
              0x02,
              CPURegister16Enum::HL,
          },
          {
              "POP AF",
              0x03,
              CPURegister16Enum::AF,
          },
      });

  for (auto &[subtest, dest, reg16] : table) {
    uint8_t opcode = prefix | dest << 4 | suffix;

    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_POP_R16_STK)
        << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R16) << subtest;
    EXPECT_EQ(operation.getOperand1().getReg16(), reg16) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND)
        << subtest;
  }
}

TEST(CpuOpcode, CpuOpcode_PUSH_R16_STK) {
  auto prefix = 0xC0;
  auto suffix = 0x05;

  // Table: opcode register code -> reg16 operand
  auto table =
      std::vector<std::tuple<std::string, uint8_t, CPURegister16Enum>>({
          {
              "PUSH BC",
              0x00,
              CPURegister16Enum::BC,
          },
          {
              "PUSH DE",
              0x01,
              CPURegister16Enum::DE,
          },
          {
              "PUSH HL",
              0x02,
              CPURegister16Enum::HL,
          },
          {
              "PUSH AF",
              0x03,
              CPURegister16Enum::AF,
          },
      });

  for (auto &[subtest, dest, reg16] : table) {
    uint8_t opcode = prefix | dest << 4 | suffix;

    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_PUSH_R16_STK)
        << subtest;

    EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R16) << subtest;
    EXPECT_EQ(operation.getOperand1().getReg16(), reg16) << subtest;

    EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND)
        << subtest;
  }
}

TEST(CpuOpcode, CpuOpcode_LD_CMEM_A) {
  auto operation = Opcode::decode(0xE2, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_LD_CMEM_A);

  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::C);
  EXPECT_TRUE(operation.getOperand1().isDereferenced());

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand2().getReg8(), CPURegister8Enum::A);
  EXPECT_FALSE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_LD_IMM8MEM_A) {
  auto operation = Opcode::decode(0xE0, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_LD_IMM8MEM_A);

  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::IMM8);
  EXPECT_TRUE(operation.getOperand1().isDereferenced());

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand2().getReg8(), CPURegister8Enum::A);
  EXPECT_FALSE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_LD_IMM16_MEM_A) {
  auto operation = Opcode::decode(0xEA, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_LD_IMM16MEM_A);

  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::IMM16);
  EXPECT_TRUE(operation.getOperand1().isDereferenced());

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand2().getReg8(), CPURegister8Enum::A);
  EXPECT_FALSE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_LD_A_CMEM) {
  auto operation = Opcode::decode(0xF2, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_LD_A_CMEM);

  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A);
  EXPECT_FALSE(operation.getOperand1().isDereferenced());

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand2().getReg8(), CPURegister8Enum::C);
  EXPECT_TRUE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_LD_A_IMM8MEM) {
  auto operation = Opcode::decode(0xF0, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_LD_A_IMM8MEM);

  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A);
  EXPECT_FALSE(operation.getOperand1().isDereferenced());

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::IMM8);
  EXPECT_TRUE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_LD_A_IMM16_MEM) {
  auto operation = Opcode::decode(0xFA, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_LD_A_IMM16MEM);

  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.getOperand1().getReg8(), CPURegister8Enum::A);
  EXPECT_FALSE(operation.getOperand1().isDereferenced());

  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::IMM16);
  EXPECT_TRUE(operation.getOperand2().isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_DI) {
  auto operation = Opcode::decode(0xF3, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_DI);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_EI) {
  auto operation = Opcode::decode(0xFB, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_EI);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_CB_PREFIX_OP) {
  auto operation = Opcode::decode(0xCB, false);

  EXPECT_EQ(operation.getType(), CPUOperationTypeEnum::BLOCK_3_CB_PREFIX);
  EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_CB_PREFIX_INSTRUCTIONS) {
  auto prefix_table = std::vector<std::tuple<std::string, uint8_t, CPUOperationTypeEnum>>({
      {"RLC", 0x00, CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RLC_R8},
      {"RRC", 0x08, CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RRC_R8},
      {"RL", 0x10, CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RL_R8},
      {"RR", 0x18, CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RR_R8},
      {"SLA", 0x20, CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SLA_R8},
      {"SRA", 0x28, CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SRA_R8},
      {"SWAP", 0x30, CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SWAP_R8},
      {"SRL", 0x38, CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SRL_R8}
  });

  auto table = std::vector<std::tuple<std::string, uint8_t, CPURegister8Enum>>({
      {
          "B",
          0x00,
          CPURegister8Enum::B,
      },
      {
          "C",
          0x01,
          CPURegister8Enum::C,
      },
      {
          "D",
          0x02,
          CPURegister8Enum::D,
      },
      {
          "E",
          0x03,
          CPURegister8Enum::E,
      },
      {
          "H",
          0x04,
          CPURegister8Enum::H,
      },
      {
          "L",
          0x05,
          CPURegister8Enum::L,
      },
      {
          "A",
          0x07,
          CPURegister8Enum::A,
      },
  });

  for (auto &[prefix_subtest, prefix_dest, prefix_op] : prefix_table) {
    for (auto &[reg_name, dest, reg8] : table) {
      auto subtest = prefix_subtest + " " + reg_name;

      uint8_t opcode = prefix_dest | dest;

      auto operation = Opcode::decode(opcode, true);

      EXPECT_EQ(operation.getType(), prefix_op) << subtest;

      EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::R8)
          << subtest;
      EXPECT_EQ(operation.getOperand1().getReg8(), reg8)
          << subtest;

      EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::NO_OPERAND)
          << subtest;
    }
  }
}

TEST(CpuOpcode, CpuOpcode_CB_PREFIX_BIT_RES_SET_B3_R8) {
  auto prefix_table = std::vector<std::tuple<std::string, uint8_t, CPUOperationTypeEnum>>({
      {"BIT B3", 0x40, CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8},
      {"RES B3", 0x80, CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8},
      {"SET B3", 0xC0, CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8}
  });

  auto reg_table = std::vector<std::tuple<std::string, uint8_t, CPURegister8Enum>>({
      {
          "B",
          0x00,
          CPURegister8Enum::B,
      },
      {
          "C",
          0x01,
          CPURegister8Enum::C,
      },
      {
          "D",
          0x02,
          CPURegister8Enum::D,
      },
      {
          "E",
          0x03,
          CPURegister8Enum::E,
      },
      {
          "H",
          0x04,
          CPURegister8Enum::H,
      },
      {
          "L",
          0x05,
          CPURegister8Enum::L,
      },
      {
          "A",
          0x07,
          CPURegister8Enum::A,
      },
  });

  for (auto &[prefix_subtest, prefix_dest, prefix_op] : prefix_table) {
    for(uint8_t i = 0; i < 8; i++) {
      for (auto &[reg_name, dest, reg8] : reg_table) {
        auto subtest = prefix_subtest + " " + std::to_string(i) + " " + reg_name;

        uint8_t opcode = prefix_dest | i << 3 | dest;
        auto operation = Opcode::decode(opcode, true);

        EXPECT_EQ(operation.getType(), prefix_op) << subtest;
        
        EXPECT_EQ(operation.getOperand1().getType(), CPUOperandTypeEnum::LITERAL)
            << subtest;
        EXPECT_EQ(operation.getOperand1().getLiteral(), i)
            << subtest;

        EXPECT_EQ(operation.getOperand2().getType(), CPUOperandTypeEnum::R8)
            << subtest;
        EXPECT_EQ(operation.getOperand2().getReg8(), reg8)
            << subtest;
      }
    }
  }
}

