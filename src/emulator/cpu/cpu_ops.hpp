#pragma once

#include "cpu_register.hpp"
#include <cstdint>

namespace gehmboi::emulator {
enum class CPUOperationTypeEnum {
  UNDEFINED = -1,
  // Block 0
  BLOCK_0_NOP,
  BLOCK_0_LD_R16_IMM16,
  BLOCK_0_LD_R16MEM_A,
  BLOCK_0_LD_A_R16MEM,
  BLOCK_0_IMM16MEM_SP,
  BLOCK_0_INC_R16,
  BLOCK_0_DEC_R16,
  BLOCK_0_ADD_HL_R16,
  BLOCK_0_INC_R8,
  BLOCK_0_DEC_R8,
  BLOCK_0_LD_R8_IMM8,
  BLOCK_0_RLCA,
  BLOCK_0_RRCA,
  BLOCK_0_RLA,
  BLOCK_0_RRA,
  BLOCK_0_DAA,
  BLOCK_0_CPL,
  BLOCK_0_SCF,
  BLOCK_0_CCF,
  BLOCK_0_JR_IMM8,
  BLOCK_0_JR_COND_IMM8,
  BLOCK_0_STOP,
  // Block 1
  BLOCK_1_LD_R8_R8,
  BLOCK_1_LD_HALT,
  // Block 2
  BLOCK_2_ADD_A_R8,
  BLOCK_2_ADC_A_R8,
  BLOCK_2_SUB_A_R8,
  BLOCK_2_SBC_A_R8,
  BLOCK_2_AND_A_R8,
  BLOCK_2_XOR_A_R8,
  BLOCK_2_OR_A_R8,
  BLOCK_2_CP_A_R8,
  // Block 3
  BLOCK_3_ADD_A_IMM8,
  BLOCK_3_ADC_A_IMM8,
  BLOCK_3_SUB_A_IMM8,
  BLOCK_3_SBC_A_IMM8,
  BLOCK_3_AND_A_IMM8,
  BLOCK_3_XOR_A_IMM8,
  BLOCK_3_OR_A_IMM8,
  BLOCK_3_CP_A_IMM8,
  BLOCK_3_RET_COND,
  BLOCK_3_RET,
  BLOCK_3_RETI,
  BLOCK_3_JP_COND_IMM16,
  BLOCK_3_JP_IMM16,
  BLOCK_3_CALL_COND_IMM16,
  BLOCK_3_CALL_IMM16,
  BLOCK_3_RST_TGT3,
  BLOCK_3_POP_R16_STK,
  BLOCK_3_PUSH_R16_STK,
  BLOCK_3_CB_PREFIX_OP,
  BLOCK_3_CB_PREFIX_RLC_R8,
  BLOCK_3_CB_PREFIX_RRC_R8,
  BLOCK_3_CB_PREFIX_RL_R8,
  BLOCK_3_CB_PREFIX_RR_R8,
  BLOCK_3_CB_PREFIX_SLA_R8,
  BLOCK_3_CB_PREFIX_SRA_R8,
  BLOCK_3_CB_PREFIX_SLL_R8,
  BLOCK_3_CB_PREFIX_SRL_R8,
  BLOCK_3_CB_PREFIX_BIT_B3_R8,
  BLOCK_3_CB_PREFIX_RES_B3_R8,
  BLOCK_3_CB_PREFIX_SET_B3_R8,
};

enum class CPUOperandTypeEnum {
  NO_OPERAND,
  R8,
  R16,
  IMM8,
  IMM16,
};

struct CPUOperationOperand {
public:
  CPUOperationOperand();
  static CPUOperationOperand createNoOperand();
  static CPUOperationOperand createReg8Operand(CPURegister8Enum reg8);
  static CPUOperationOperand createReg16Operand(CPURegister16Enum reg16);
  static CPUOperationOperand createImm8Operand(uint8_t imm8);
  static CPUOperationOperand createImm16Operand(uint16_t imm16);

  CPUOperandTypeEnum getType() const noexcept;
  CPURegister8Enum getReg8() const;
  CPURegister16Enum getReg16() const;
  uint8_t getImm8() const;
  uint16_t getImm16() const;

private:
  CPUOperandTypeEnum type;
  union {
    CPURegister8Enum reg8;
    CPURegister16Enum reg16;
    uint8_t imm8;
    uint16_t imm16;
  } value;
};

struct CPUOperation {
  CPUOperationTypeEnum op;
  CPUOperationOperand operand1;
  CPUOperationOperand operand2;
};
};