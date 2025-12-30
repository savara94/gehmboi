#include <cstdint>
#include <unordered_map>

#include "cpu_register.hpp"

namespace gehmboi::emulator {
struct CPUConfig {};

class CPU {
public:
  CPU(const CPUConfig &config);

  uint8_t getR8(CPURegister8Enum reg) const;
  uint16_t getR16(CPURegister16Enum reg) const;
  void setR8(CPURegister8Enum reg, uint8_t byte);
  void setR16(CPURegister16Enum reg, uint16_t byte);
  uint8_t getFlag(CPUFlagEnum reg) const;
  void setFlag(CPUFlagEnum flag, uint8_t bit);
  bool isCBPrefixActive() const noexcept;

  void execute(uint8_t opcode);

  uint8_t getMem(uint16_t address) const;
  void setMem(uint16_t address, uint8_t byte);

protected:
  CPUConfig m_config;
  std::unordered_map<CPURegister16Enum, uint16_t> m_regs16;
};
}; // namespace gehmboi::emulator