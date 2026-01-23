#pragma once

#include <cpu/cpu_opcode.hpp>

#include <variant>

namespace gehmboi::emulator {

using OperandValue = std::variant<uint8_t, int8_t, uint16_t>;

class FetchedOperation {
  public:

  FetchedOperation(const Opcode& opcode, const OperandValue &value1, const OperandValue &value2);

  const Opcode& getOpcode() const noexcept;
  const OperandValue& getValue1() const noexcept;
  const OperandValue& getValue2() const noexcept;

  private:

  void verify();

  const Opcode m_opcode;
  const OperandValue m_v1;
  const OperandValue m_v2;
};
}