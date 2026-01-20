#include <cstdint>
#include <unordered_map>

namespace gehmboi::emulator {
enum class CPURegister16Enum {
  AF,
  BC,
  DE,
  HL,
  SP,
  PC,
};

enum class CPURegister8Enum {
  A,
  F,
  B,
  C,
  D,
  E,
  H,
  L,
};

enum class CPUFlagEnum {
  ZERO,
  SUBTRACTION,
  CARRY,
  HALF_CARRY,
};

class CPURegisters {
public:
  CPURegisters();

  uint8_t getR8(CPURegister8Enum reg) const;
  uint16_t getR16(CPURegister16Enum reg) const;
  void setR8(CPURegister8Enum reg, uint8_t byte);
  void setR16(CPURegister16Enum reg, uint16_t byte);
  uint8_t getFlag(CPUFlagEnum flag) const;
  void setFlag(CPUFlagEnum flag, uint8_t bit);

protected:
  std::unordered_map<CPURegister16Enum, uint16_t> m_regs16;
  std::unordered_map<CPURegister8Enum, std::pair<CPURegister16Enum, uint8_t>>
      reg8ToReg16Map;
};
}; // namespace gehmboi::emulator