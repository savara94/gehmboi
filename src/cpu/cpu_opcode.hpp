#pragma once

#include "cpu_ops.hpp"
#include <cstdint>

namespace gehmboi::emulator {

using RawOpcodeByte = uint8_t;

class Opcode {
public:
  static Opcode decode(RawOpcodeByte opcode, bool isCBPrefixActive);

  Opcode(CPUOperationTypeEnum type, const CPUOperationOperand& op1, const CPUOperationOperand& op2);

  CPUOperationTypeEnum getType() const;
  CPUOperationOperand getOperand1() const;
  CPUOperationOperand getOperand2() const;

private:
  CPUOperationTypeEnum m_Type;
  CPUOperationOperand m_Op1;
  CPUOperationOperand m_Op2;
};
} // namespace gehmboi::emulator
