#include "cpu_ops.hpp"

#include <stdexcept>

using namespace gehmboi::emulator;

CPUOperationOperand::CPUOperationOperand() {
  m_Type = CPUOperandTypeEnum::NO_OPERAND;
  m_IsDereferenced = false;
  m_IsIncrement = false;
  m_IsDecrement = false;
}

CPUOperationOperand CPUOperationOperand::createNoOperand() {
  auto op = CPUOperationOperand();

  op.m_Type = CPUOperandTypeEnum::NO_OPERAND;

  return op;
}

CPUOperationOperand
CPUOperationOperand::createReg8Operand(CPURegister8Enum reg8,
                                       bool isDereferenced) {
  auto op = CPUOperationOperand();

  op.m_Type = CPUOperandTypeEnum::R8;
  op.m_Value.reg8 = reg8;
  op.m_IsDereferenced = isDereferenced;

  return op;
}

CPUOperationOperand
CPUOperationOperand::createReg16Operand(CPURegister16Enum reg16,
                                        bool isDereferenced, bool isIncrement,
                                        bool isDecrement) {
  auto op = CPUOperationOperand();

  op.m_Type = CPUOperandTypeEnum::R16;
  op.m_Value.reg16 = reg16;
  op.m_IsDereferenced = isDereferenced;
  op.m_IsIncrement = isIncrement;
  op.m_IsDecrement = isDecrement;

  return op;
}

CPUOperationOperand CPUOperationOperand::createLiteralOperand(uint8_t value) {
  auto op = CPUOperationOperand();

  op.m_Type = CPUOperandTypeEnum::LITERAL;
  op.m_Value.literal = value;

  return op;
}

CPUOperationOperand
CPUOperationOperand::createConditionOperand(CPUConditionEnum condition) {
  auto op = CPUOperationOperand();

  op.m_Type = CPUOperandTypeEnum::CONDITION;
  op.m_Value.condition = condition;

  return op;
}

CPUOperationOperand CPUOperationOperand::createImm8Operand(bool isDereferenced) {
  auto op = CPUOperationOperand();

  op.m_Type = CPUOperandTypeEnum::IMM8;
  op.m_IsDereferenced = isDereferenced;

  return op;
}

CPUOperationOperand CPUOperationOperand::createImm16Operand(bool isDereferenced) {
  auto op = CPUOperationOperand();

  op.m_Type = CPUOperandTypeEnum::IMM16;
  op.m_IsDereferenced = isDereferenced;

  return op;
}

CPUOperandTypeEnum CPUOperationOperand::getType() const noexcept {
  return m_Type;
}

bool CPUOperationOperand::isDereferenced() const noexcept {
  return m_IsDereferenced;
}

CPURegister8Enum CPUOperationOperand::getReg8() const {
  if (m_Type != CPUOperandTypeEnum::R8) {
    throw std::runtime_error(
        "CPUOperationOperand: Operand is not of m_Type R8");
  }

  return m_Value.reg8;
}

CPURegister16Enum CPUOperationOperand::getReg16() const {
  if (m_Type != CPUOperandTypeEnum::R16) {
    throw std::runtime_error(
        "CPUOperationOperand: Operand is not of m_Type R16");
  }

  return m_Value.reg16;
}

CPUConditionEnum CPUOperationOperand::getCondition() const {
  if (m_Type != CPUOperandTypeEnum::CONDITION) {
    throw std::runtime_error(
        "CPUOperationOperand: Operand is not of m_Type CONDITION");
  }

  return m_Value.condition;
}

uint8_t CPUOperationOperand::getLiteral() const {
  if (m_Type != CPUOperandTypeEnum::LITERAL) {
    throw std::runtime_error(
        "CPUOperationOperand: Operand is not of m_Type LITERAL");
  }

  return m_Value.literal;
}

bool CPUOperationOperand::isIncrement() const noexcept { return m_IsIncrement; }

bool CPUOperationOperand::isDecrement() const noexcept { return m_IsDecrement; }
