#pragma once

#include "ops.hpp"

namespace gehmboi::emulator {
class OpcodeParser {
public:
  static opcodeOp decode(uint8_t byte, bool isCBPrefixActive) noexcept;
}
} // namespace gehmboi::emulator
