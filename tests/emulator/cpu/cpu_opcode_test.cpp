#include <gtest/gtest.h>
#include <vector>

#include "cpu/cpu_opcode.hpp"

using namespace gehmboi::emulator;

static std::unordered_map<uint8_t, CPURegister8Enum> getR8MapForTests();

// Block 0
TEST(CpuOpcode, CpuOpcode_NOP) {
  auto operation = Opcode::decode(0x00, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_0_NOP);

  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::NO_OPERAND);

  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_LD_R16_IMM16) {
  auto prefix = 0x00;
  auto suffix = 0x01;
  auto table = std::vector<
      std::tuple<std::string, uint8_t, CPUOperationOperand>>{
      {"BC", 0x00,
       CPUOperationOperand::createReg16Operand(CPURegister16Enum::BC, false)},
      {"DE", 0x01,
       CPUOperationOperand::createReg16Operand(CPURegister16Enum::DE, false)},
      {"HL", 0x02,
       CPUOperationOperand::createReg16Operand(CPURegister16Enum::HL, false)},
      {"SP", 0x03,
       CPUOperationOperand::createReg16Operand(CPURegister16Enum::SP, false)},
  };

  for (auto &[subtest, dstcode, op1] : table) {
    auto opcode = prefix << 6 | dstcode << 4 | suffix;
    auto operation = Opcode::decode(0x01, false);

    EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_0_LD_R16_IMM16);

    EXPECT_EQ(operation.operand1.getType(), op1.getType());
    EXPECT_EQ(operation.operand1.getReg16(), op1.getReg16());
    EXPECT_FALSE(operation.operand1.isDereferenced());

    EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::IMM16);
    EXPECT_FALSE(operation.operand2.isDereferenced());
  }
}

TEST(CpuOpcode, CpuOpcode_LD_R16MEM_A) {
  auto operation = Opcode::decode(0x02, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_0_LD_R16MEM_A);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.operand1.getReg16(), CPURegister16Enum::BC);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand2.getReg8(), CPURegister8Enum::A);
}

TEST(CpuOpcode, CpuOpcode_LD_A_R16MEM) {
  auto operation = Opcode::decode(0x0A, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_0_LD_A_R16MEM);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::A);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.operand2.getReg16(), CPURegister16Enum::BC);
}

TEST(CpuOpcode, CpuOpcode_LD_IMM16MEM_SP) {
  auto operation = Opcode::decode(0x08, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_0_IMM16MEM_SP);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::IMM16);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.operand2.getReg16(), CPURegister16Enum::SP);
}

TEST(CpuOpcode, CpuOpcode_INC_R16) {
  auto operation = Opcode::decode(0x03, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_0_INC_R16);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.operand1.getReg16(), CPURegister16Enum::BC);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_DEC_R16) {
  auto operation = Opcode::decode(0x0B, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_0_DEC_R16);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.operand1.getReg16(), CPURegister16Enum::DE);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_ADD_HL_R16) {
  auto operation = Opcode::decode(0x19, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_0_ADD_HL_R16);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.operand1.getReg16(), CPURegister16Enum::HL);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.operand2.getReg16(), CPURegister16Enum::DE);
}

TEST(CpuOpcode, CpuOpcode_INC_R8) {
  auto operation = Opcode::decode(0x04, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_0_INC_R8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::B);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_DEC_R8) {
  auto operation = Opcode::decode(0x0C, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_0_DEC_R8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::C);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_LD_R8_IMM8) {
  auto operation = Opcode::decode(0x06, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_0_LD_R8_IMM8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::B);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::IMM8);
}

TEST(CpuOpcode, CpuOpcode_RLCA) {
  auto operation = Opcode::decode(0x07, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_0_RLCA);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_RRCA) {
  auto operation = Opcode::decode(0x0F, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_0_RRCA);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_RLA) {
  auto operation = Opcode::decode(0x17, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_0_RLA);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_RRA) {
  auto operation = Opcode::decode(0x1F, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_0_RRA);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_DAA) {
  auto operation = Opcode::decode(0x27, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_0_DAA);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_CPL) {
  auto operation = Opcode::decode(0x2F, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_0_CPL);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_SCF) {
  auto operation = Opcode::decode(0x37, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_0_SCF);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_CCF) {
  auto operation = Opcode::decode(0x3F, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_0_CCF);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_JR_IMM8) {
  auto operation = Opcode::decode(0x18, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_0_JR_IMM8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::IMM8);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_JR_COND_IMM8) {
  auto operation = Opcode::decode(0x20, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_0_JR_COND_IMM8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::IMM8);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_STOP) {
  auto operation = Opcode::decode(0x10, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_0_STOP);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

// Block 1

TEST(CpuOpcode, CpuOpcode_LD_R8_R8) {
  auto prefix = 0x01;
  auto operation_type = CPUOperationTypeEnum::BLOCK_1_LD_R8_R8;

  // Table: opcode src, destination -> operand1, operand2
  auto table = std::vector<
      std::tuple<std::string, uint8_t, uint8_t, CPUOperationOperand,
                 CPUOperationOperand>>({
      {
          "B <- C",
          0x00,
          0x01,
          CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false),
          CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false),
      },
      {
          "D <- E",
          0x02,
          0x03,
          CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false),
          CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false),
      },
      {
          "H <- L",
          0x04,
          0x05,
          CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false),
          CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false),
      },
      {
          "B <- A",
          0x07,
          0x00,
          CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
          CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false),
      },
  });

  for (auto &[subtest, src, dest, op1, op2] : table) {
    uint8_t opcode = (prefix << 6) | (dest << 3) | src;
    std::stringstream ss;
    ss << "Subtest: " << subtest << " opcode: " << std::hex << opcode
       << std::dec;
    auto subtest_msg = ss.str();

    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.op, operation_type) << subtest_msg;

    EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8)
        << subtest_msg;
    EXPECT_EQ(operation.operand1.getReg8(), op1.getReg8()) << subtest_msg;
    EXPECT_FALSE(operation.operand1.isDereferenced()) << subtest_msg;

    EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::R8)
        << subtest_msg;
    EXPECT_EQ(operation.operand2.getReg8(), op2.getReg8()) << subtest_msg;
    EXPECT_FALSE(operation.operand2.isDereferenced()) << subtest_msg;
  }

  // Exception mapping for 0x06 [HL]
  // [HL] <- A
  auto subtest = "[HL] <- A";
  auto opcode = (prefix << 6) | (0x06 << 3) | 0x07;
  auto operation = Opcode::decode(opcode, false);

  EXPECT_EQ(operation.op, operation_type) << opcode;

  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::A);
  EXPECT_FALSE(operation.operand1.isDereferenced());

  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.operand2.getReg16(), CPURegister16Enum::HL);
  EXPECT_TRUE(operation.operand2.isDereferenced());
}

TEST(CpuOpcode, CpuOpcode_LD_HALT) {

  std::vector<std::tuple<std::string, uint8_t>> halt_opcodes = {
      {"B <- B", 0x01 << 6 | 0x00 << 3 | 0x00},
      {"C <- C", 0x01 << 6 | 0x01 << 3 | 0x01},
      {"D <- D", 0x01 << 6 | 0x02 << 3 | 0x02},
      {"E <- E", 0x01 << 6 | 0x03 << 3 | 0x03},
      {"H <- H", 0x01 << 6 | 0x04 << 3 | 0x04},
      {"L <- L", 0x01 << 6 | 0x05 << 3 | 0x05},
      {"[HL] <- [HL]", 0x01 << 6 | 0x06 << 3 | 0x06},
      {"A <- A", 0x01 << 6 | 0x07 << 3 | 0x07},
  };

  for (auto &[subtest, opcode] : halt_opcodes) {
    auto operation = Opcode::decode(opcode, false);

    EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_1_LD_HALT) << subtest;
    EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::NO_OPERAND)
        << subtest;
    EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND)
        << subtest;
  }
}

// Block 2

TEST(CpuOpcode, CpuOpcode_ADD_A_R8) {
  auto operation = Opcode::decode(0x80, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_2_ADD_A_R8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::B);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_ADC_A_R8) {
  auto operation = Opcode::decode(0x88, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_2_ADC_A_R8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::B);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_SUB_A_R8) {
  auto operation = Opcode::decode(0x90, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_2_SUB_A_R8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::B);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_SBC_A_R8) {
  auto operation = Opcode::decode(0x98, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_2_SBC_A_R8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::B);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_AND_A_R8) {
  auto operation = Opcode::decode(0xA0, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_2_AND_A_R8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::B);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_XOR_A_R8) {
  auto operation = Opcode::decode(0xA8, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_2_XOR_A_R8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::B);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_OR_A_R8) {
  auto operation = Opcode::decode(0xB0, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_2_OR_A_R8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::B);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_CP_A_R8) {
  auto operation = Opcode::decode(0xB8, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_2_CP_A_R8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::B);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

// Block 3

TEST(CpuOpcode, CpuOpcode_RET_COND) {
  auto operation = Opcode::decode(0xC6, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_3_ADD_A_IMM8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::IMM8);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_RET) {
  auto operation = Opcode::decode(0xC6, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_3_ADD_A_IMM8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::IMM8);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_RETI) {
  auto operation = Opcode::decode(0xC6, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_3_ADD_A_IMM8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::IMM8);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_JP_COND_IMM16) {
  auto operation = Opcode::decode(0xC6, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_3_ADD_A_IMM8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::IMM8);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_JP_IMM16) {
  auto operation = Opcode::decode(0xC6, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_3_ADD_A_IMM8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::IMM8);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_CALL_COND_IMM16) {
  auto operation = Opcode::decode(0xC6, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_3_ADD_A_IMM8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::IMM8);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_CALL_IMM16) {
  auto operation = Opcode::decode(0xC6, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_3_ADD_A_IMM8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::IMM8);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_RST_TGT3) {
  auto operation = Opcode::decode(0xC6, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_3_ADD_A_IMM8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::IMM8);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_POP_R16_STK) {
  auto operation = Opcode::decode(0xC1, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_3_POP_R16_STK);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.operand1.getReg16(), CPURegister16Enum::BC);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_PUSH_R16_STK) {
  auto operation = Opcode::decode(0xC5, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_3_PUSH_R16_STK);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R16);
  EXPECT_EQ(operation.operand1.getReg16(), CPURegister16Enum::BC);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_CB_PREFIX_OP) {
  auto operation = Opcode::decode(0xCB, false);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_OP);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::NO_OPERAND);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_CB_PREFIX_RLC_R8) {
  auto operation = Opcode::decode(0x00, true);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RLC_R8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::B);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_CB_PREFIX_RRC_R8) {
  auto operation = Opcode::decode(0x08, true);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RRC_R8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::B);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_CB_PREFIX_RL_R8) {
  auto operation = Opcode::decode(0x10, true);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RL_R8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::B);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_CB_PREFIX_RR_R8) {
  auto operation = Opcode::decode(0x18, true);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RR_R8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::B);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_CB_PREFIX_SLA_R8) {
  auto operation = Opcode::decode(0x20, true);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SLA_R8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::B);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_CB_PREFIX_SRA_R8) {
  auto operation = Opcode::decode(0x28, true);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SRA_R8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::B);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_CB_PREFIX_SLL_R8) {
  auto operation = Opcode::decode(0x30, true);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SLL_R8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::B);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_CB_PREFIX_SRL_R8) {
  auto operation = Opcode::decode(0x38, true);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SRL_R8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::B);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_CB_PREFIX_BIT_B3_R8) {
  auto operation = Opcode::decode(0x58, true);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::B);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_CB_PREFIX_RES_B3_R8) {
  auto operation = Opcode::decode(0x98, true);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::B);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

TEST(CpuOpcode, CpuOpcode_CB_PREFIX_SET_B3_R8) {
  auto operation = Opcode::decode(0xD8, true);

  EXPECT_EQ(operation.op, CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8);
  EXPECT_EQ(operation.operand1.getType(), CPUOperandTypeEnum::R8);
  EXPECT_EQ(operation.operand1.getReg8(), CPURegister8Enum::B);
  EXPECT_EQ(operation.operand2.getType(), CPUOperandTypeEnum::NO_OPERAND);
}

static std::unordered_map<uint8_t, CPURegister8Enum> getR8Map() {
  return std::unordered_map<uint8_t, CPURegister8Enum>{
      {0x0, CPURegister8Enum::B},
      {0x1, CPURegister8Enum::C},
      {0x2, CPURegister8Enum::D},
      {0x3, CPURegister8Enum::E},
      {0x4, CPURegister8Enum::H},
      {0x5, CPURegister8Enum::L},
      // {0x6, CPURegister8Enum::HLPtr}, // (HL) is mapped to A for testing
      // purposes
      {0x7, CPURegister8Enum::A},
  };
}