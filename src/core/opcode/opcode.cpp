#include "opcode.hpp"

namespace gehmboi::emulator {
opcodeOp OpcodeParser::decode(uint8_t byte, bool isCBPrefixActive) noexcept {
  if (isCBPrefixActive) {
    return cbPrefixedOps[byte];
  } else {
    return baseOps[byte];
  }
}
} // namespace gehmboi::emulator