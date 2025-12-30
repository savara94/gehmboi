#pragma once

#include "cpu_ops.hpp"
#include <cstdint>

namespace gehmboi::emulator {
class Opcode {
public:
  static CPUOperation decode(uint8_t opcode, bool isCBPrefixActive);
};
} // namespace gehmboi::emulator
