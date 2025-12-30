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
}; // namespace gehmboi::emulator