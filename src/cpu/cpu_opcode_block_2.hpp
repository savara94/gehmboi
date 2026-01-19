#pragma once

#include "cpu_ops.hpp"

namespace gehmboi::emulator {
static const std::unordered_map<uint8_t, Opcode> block2Map = {
    // BLOCK_2_ADD_A_R8 (0x80-0x87)
    {0x80,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_ADD_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false)}},
    {0x81,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_ADD_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false)}},
    {0x82,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_ADD_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false)}},
    {0x83,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_ADD_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false)}},
    {0x84,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_ADD_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false)}},
    {0x85,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_ADD_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false)}},
    {0x86, Opcode{CPUOperationTypeEnum::BLOCK_2_ADD_A_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x87,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_ADD_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false)}},

    // BLOCK_2_ADC_A_R8 (0x88-0x8F)
    {0x88,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_ADC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false)}},
    {0x89,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_ADC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false)}},
    {0x8A,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_ADC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false)}},
    {0x8B,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_ADC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false)}},
    {0x8C,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_ADC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false)}},
    {0x8D,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_ADC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false)}},
    {0x8E, Opcode{CPUOperationTypeEnum::BLOCK_2_ADC_A_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x8F,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_ADC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false)}},

    // BLOCK_2_SUB_A_R8 (0x90-0x97)
    {0x90,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_SUB_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false)}},
    {0x91,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_SUB_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false)}},
    {0x92,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_SUB_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false)}},
    {0x93,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_SUB_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false)}},
    {0x94,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_SUB_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false)}},
    {0x95,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_SUB_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false)}},
    {0x96, Opcode{CPUOperationTypeEnum::BLOCK_2_SUB_A_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x97,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_SUB_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false)}},

    // BLOCK_2_SBC_A_R8 (0x98-0x9F)
    {0x98,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_SBC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false)}},
    {0x99,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_SBC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false)}},
    {0x9A,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_SBC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false)}},
    {0x9B,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_SBC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false)}},
    {0x9C,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_SBC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false)}},
    {0x9D,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_SBC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false)}},
    {0x9E, Opcode{CPUOperationTypeEnum::BLOCK_2_SBC_A_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x9F,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_SBC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false)}},

    // BLOCK_2_AND_A_R8 (0xA0-0xA7)
    {0xA0,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_AND_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false)}},
    {0xA1,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_AND_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false)}},
    {0xA2,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_AND_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false)}},
    {0xA3,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_AND_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false)}},
    {0xA4,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_AND_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false)}},
    {0xA5,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_AND_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false)}},
    {0xA6, Opcode{CPUOperationTypeEnum::BLOCK_2_AND_A_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xA7,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_AND_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false)}},

    // BLOCK_2_XOR_A_R8 (0xA8-0xAF)
    {0xA8,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_XOR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false)}},
    {0xA9,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_XOR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false)}},
    {0xAA,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_XOR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false)}},
    {0xAB,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_XOR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false)}},
    {0xAC,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_XOR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false)}},
    {0xAD,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_XOR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false)}},
    {0xAE, Opcode{CPUOperationTypeEnum::BLOCK_2_XOR_A_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xAF,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_XOR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false)}},

    // BLOCK_2_OR_A_R8 (0xB0-0xB7)
    {0xB0,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_OR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false)}},
    {0xB1,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_OR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false)}},
    {0xB2,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_OR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false)}},
    {0xB3,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_OR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false)}},
    {0xB4,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_OR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false)}},
    {0xB5,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_OR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false)}},
    {0xB6, Opcode{CPUOperationTypeEnum::BLOCK_2_OR_A_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xB7,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_OR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false)}},

    // BLOCK_2_CP_A_R8 (0xB8-0xBF)
    {0xB8,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_CP_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false)}},
    {0xB9,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_CP_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false)}},
    {0xBA,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_CP_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false)}},
    {0xBB,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_CP_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false)}},
    {0xBC,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_CP_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false)}},
    {0xBD,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_CP_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false)}},
    {0xBE, Opcode{CPUOperationTypeEnum::BLOCK_2_CP_A_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xBF,
     Opcode{
         CPUOperationTypeEnum::BLOCK_2_CP_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false)}},
};
} // namespace gehmboi::emulator