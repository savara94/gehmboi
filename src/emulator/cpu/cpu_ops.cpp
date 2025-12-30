#include "cpu_ops.hpp"

using namespace gehmboi::emulator;

CPUOperationOperand::CPUOperationOperand() {
  type = CPUOperandTypeEnum::NO_OPERAND;
}

CPUOperationOperand CPUOperationOperand::createNoOperand() {
  auto op = CPUOperationOperand();

  op.type = CPUOperandTypeEnum::NO_OPERAND;

  return op;
}

CPUOperationOperand
CPUOperationOperand::createReg8Operand(CPURegister8Enum reg8) {
  auto op = CPUOperationOperand();

  op.type = CPUOperandTypeEnum::R8;
  op.value.reg8 = reg8;

  return op;
}

CPUOperationOperand
CPUOperationOperand::createReg16Operand(CPURegister16Enum reg16) {
  auto op = CPUOperationOperand();

  op.type = CPUOperandTypeEnum::R16;
  op.value.reg16 = reg16;

  return op;
}

CPUOperationOperand CPUOperationOperand::createImm8Operand(uint8_t imm8) {
  auto op = CPUOperationOperand();

  op.type = CPUOperandTypeEnum::IMM8;
  op.value.imm8 = imm8;

  return op;
}

CPUOperationOperand CPUOperationOperand::createImm16Operand(uint16_t imm16) {
  auto op = CPUOperationOperand();

  op.type = CPUOperandTypeEnum::IMM16;
  op.value.imm16 = imm16;

  return op;
}

CPUOperandTypeEnum CPUOperationOperand::getType() const noexcept {
  return type;
}