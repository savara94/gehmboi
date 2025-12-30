#include "cpu.hpp"

using namespace gehmboi::emulator;

CPU::CPU(const CPUConfig &config) : m_config(config) {
  m_regs16[CPURegister16Enum::AF] = 0;
  m_regs16[CPURegister16Enum::BC] = 0;
  m_regs16[CPURegister16Enum::DE] = 0;
  m_regs16[CPURegister16Enum::HL] = 0;
  m_regs16[CPURegister16Enum::PC] = 0;
  m_regs16[CPURegister16Enum::SP] = 0;
}

uint8_t CPU::getFlag(CPUFlagEnum flag) const { return 0; }