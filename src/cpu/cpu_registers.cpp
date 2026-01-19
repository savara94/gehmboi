#include "cpu_registers.hpp"

using namespace gehmboi::emulator;

static const auto upperByteShift = 8;

CPURegisters::CPURegisters() {
  m_regs16[CPURegister16Enum::AF] = 0;
  m_regs16[CPURegister16Enum::BC] = 0;
  m_regs16[CPURegister16Enum::DE] = 0;
  m_regs16[CPURegister16Enum::HL] = 0;
  m_regs16[CPURegister16Enum::PC] = 0;
  m_regs16[CPURegister16Enum::SP] = 0;

  reg8ToReg16Map = std::unordered_map<CPURegister8Enum,
                                      std::pair<CPURegister16Enum, uint8_t>>(
      {{CPURegister8Enum::A, {CPURegister16Enum::AF, upperByteShift}},
       {CPURegister8Enum::F, {CPURegister16Enum::AF, 0}},
       {CPURegister8Enum::B, {CPURegister16Enum::BC, upperByteShift}},
       {CPURegister8Enum::C, {CPURegister16Enum::BC, 0}},
       {CPURegister8Enum::D, {CPURegister16Enum::DE, upperByteShift}},
       {CPURegister8Enum::E, {CPURegister16Enum::DE, 0}},
       {CPURegister8Enum::H, {CPURegister16Enum::HL, upperByteShift}},
       {CPURegister8Enum::L, {CPURegister16Enum::HL, 0}}});
}

uint16_t CPURegisters::getR16(CPURegister16Enum reg) const {
  return m_regs16.at(reg);
}

uint8_t CPURegisters::getR8(CPURegister8Enum reg) const {
  auto entry = reg8ToReg16Map.at(reg);
  auto &reg16 = entry.first;
  auto &shift = entry.second;

  return getR16(reg16) >> shift;
}

void CPURegisters::setR16(CPURegister16Enum reg, uint16_t byte) {
  m_regs16[reg] = byte;
}

void CPURegisters::setR8(CPURegister8Enum reg, uint8_t byte) {
  auto entry = reg8ToReg16Map.at(reg);
  auto &reg16 = entry.first;
  auto &shift = entry.second;

  auto current_value = getR16(reg16);

  current_value &= ~(0xFF << shift);
  current_value |= (byte << shift);

  setR16(reg16, current_value);
}

uint8_t CPURegisters::getFlag(CPUFlagEnum flag) const { return 0; }