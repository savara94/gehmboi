#pragma once

#include "cpu_ops.hpp"
#include <cstdint>

namespace gehmboi::emulator {

using RawOpcodeByte = uint8_t;

struct DecodedOperation {
  CPUOperationTypeEnum op;
  CPUOperationOperand operand1;
  CPUOperationOperand operand2;
};

class Opcode {
public:
  static DecodedOperation decode(RawOpcodeByte opcode, bool isCBPrefixActive);
};
} // namespace gehmboi::emulator
