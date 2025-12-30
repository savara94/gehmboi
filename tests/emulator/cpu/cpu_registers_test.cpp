#include <gtest/gtest.h>

#include "cpu/cpu_registers.hpp"

using namespace gehmboi::emulator;

TEST(CpuRegisters, CpuRegistersInitZeros) {
  auto registers = CPURegisters();

  std::vector<CPURegister16Enum> regs16 = {
      CPURegister16Enum::AF, CPURegister16Enum::BC, CPURegister16Enum::DE,
      CPURegister16Enum::HL, CPURegister16Enum::PC, CPURegister16Enum::SP,
  };

  for (auto reg16 : regs16) {
    EXPECT_EQ(registers.getR16(reg16), 0);
  }

  std::vector<CPURegister8Enum> regs8 = {
      CPURegister8Enum::A, CPURegister8Enum::F, CPURegister8Enum::B,
      CPURegister8Enum::C, CPURegister8Enum::D, CPURegister8Enum::E,
      CPURegister8Enum::H, CPURegister8Enum::L,
  };

  for (auto reg8 : regs8) {
    EXPECT_EQ(registers.getR8(reg8), 0);
  }
}

TEST(CpuRegisters, CpuAFInSync) {
  auto registers = CPURegisters();

  registers.setR16(CPURegister16Enum::AF, 0x1234);

  EXPECT_EQ(registers.getR8(CPURegister8Enum::A), 0x12);
  EXPECT_EQ(registers.getR8(CPURegister8Enum::F), 0x34);
}

TEST(CpuRegisters, CpuBCInSync) {
  auto registers = CPURegisters();

  registers.setR16(CPURegister16Enum::BC, 0x5678);

  EXPECT_EQ(registers.getR8(CPURegister8Enum::B), 0x56);
  EXPECT_EQ(registers.getR8(CPURegister8Enum::C), 0x78);
}

TEST(CpuRegisters, CpuDEInSync) {
  auto registers = CPURegisters();

  registers.setR16(CPURegister16Enum::DE, 0x9ABC);

  EXPECT_EQ(registers.getR8(CPURegister8Enum::D), 0x9A);
  EXPECT_EQ(registers.getR8(CPURegister8Enum::E), 0xBC);
}

TEST(CpuRegisters, CpuHLInSync) {
  auto registers = CPURegisters();

  registers.setR16(CPURegister16Enum::HL, 0xDEF0);

  EXPECT_EQ(registers.getR8(CPURegister8Enum::H), 0xDE);
  EXPECT_EQ(registers.getR8(CPURegister8Enum::L), 0xF0);
}

TEST(CpuRegisters, CpuSetR8UpdatesR16) {
  auto registers = CPURegisters();

  registers.setR8(CPURegister8Enum::A, 0x12);
  registers.setR8(CPURegister8Enum::F, 0x34);

  EXPECT_EQ(registers.getR16(CPURegister16Enum::AF), 0x1234);

  registers.setR8(CPURegister8Enum::B, 0x56);
  registers.setR8(CPURegister8Enum::C, 0x78);

  EXPECT_EQ(registers.getR16(CPURegister16Enum::BC), 0x5678);

  registers.setR8(CPURegister8Enum::D, 0x9A);
  registers.setR8(CPURegister8Enum::E, 0xBC);

  EXPECT_EQ(registers.getR16(CPURegister16Enum::DE), 0x9ABC);

  registers.setR8(CPURegister8Enum::H, 0xDE);
  registers.setR8(CPURegister8Enum::L, 0xF0);

  EXPECT_EQ(registers.getR16(CPURegister16Enum::HL), 0xDEF0);
}