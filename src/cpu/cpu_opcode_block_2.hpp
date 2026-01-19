#pragma once

#include "cpu_ops.hpp"

namespace gehmboi::emulator {
static const std::unordered_map<uint8_t, DecodedOperation> block2Map = {
    // BLOCK_2_ADD_A_R8 (0x80-0x87)
    {0x80,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_ADD_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false)}},
    {0x81,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_ADD_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false)}},
    {0x82,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_ADD_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false)}},
    {0x83,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_ADD_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false)}},
    {0x84,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_ADD_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false)}},
    {0x85,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_ADD_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false)}},
    {0x86, DecodedOperation{CPUOperationTypeEnum::BLOCK_2_ADD_A_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x87,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_ADD_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false)}},

    // BLOCK_2_ADC_A_R8 (0x88-0x8F)
    {0x88,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_ADC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false)}},
    {0x89,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_ADC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false)}},
    {0x8A,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_ADC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false)}},
    {0x8B,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_ADC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false)}},
    {0x8C,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_ADC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false)}},
    {0x8D,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_ADC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false)}},
    {0x8E, DecodedOperation{CPUOperationTypeEnum::BLOCK_2_ADC_A_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x8F,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_ADC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false)}},

    // BLOCK_2_SUB_A_R8 (0x90-0x97)
    {0x90,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_SUB_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false)}},
    {0x91,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_SUB_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false)}},
    {0x92,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_SUB_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false)}},
    {0x93,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_SUB_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false)}},
    {0x94,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_SUB_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false)}},
    {0x95,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_SUB_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false)}},
    {0x96, DecodedOperation{CPUOperationTypeEnum::BLOCK_2_SUB_A_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x97,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_SUB_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false)}},

    // BLOCK_2_SBC_A_R8 (0x98-0x9F)
    {0x98,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_SBC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false)}},
    {0x99,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_SBC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false)}},
    {0x9A,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_SBC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false)}},
    {0x9B,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_SBC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false)}},
    {0x9C,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_SBC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false)}},
    {0x9D,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_SBC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false)}},
    {0x9E, DecodedOperation{CPUOperationTypeEnum::BLOCK_2_SBC_A_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x9F,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_SBC_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false)}},

    // BLOCK_2_AND_A_R8 (0xA0-0xA7)
    {0xA0,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_AND_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false)}},
    {0xA1,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_AND_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false)}},
    {0xA2,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_AND_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false)}},
    {0xA3,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_AND_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false)}},
    {0xA4,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_AND_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false)}},
    {0xA5,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_AND_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false)}},
    {0xA6, DecodedOperation{CPUOperationTypeEnum::BLOCK_2_AND_A_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xA7,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_AND_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false)}},

    // BLOCK_2_XOR_A_R8 (0xA8-0xAF)
    {0xA8,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_XOR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false)}},
    {0xA9,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_XOR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false)}},
    {0xAA,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_XOR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false)}},
    {0xAB,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_XOR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false)}},
    {0xAC,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_XOR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false)}},
    {0xAD,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_XOR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false)}},
    {0xAE, DecodedOperation{CPUOperationTypeEnum::BLOCK_2_XOR_A_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xAF,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_XOR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false)}},

    // BLOCK_2_OR_A_R8 (0xB0-0xB7)
    {0xB0,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_OR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false)}},
    {0xB1,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_OR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false)}},
    {0xB2,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_OR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false)}},
    {0xB3,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_OR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false)}},
    {0xB4,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_OR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false)}},
    {0xB5,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_OR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false)}},
    {0xB6, DecodedOperation{CPUOperationTypeEnum::BLOCK_2_OR_A_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xB7,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_OR_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false)}},

    // BLOCK_2_CP_A_R8 (0xB8-0xBF)
    {0xB8,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_CP_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false)}},
    {0xB9,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_CP_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false)}},
    {0xBA,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_CP_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false)}},
    {0xBB,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_CP_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false)}},
    {0xBC,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_CP_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false)}},
    {0xBD,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_CP_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false)}},
    {0xBE, DecodedOperation{CPUOperationTypeEnum::BLOCK_2_CP_A_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xBF,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_2_CP_A_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false)}},
};
} // namespace gehmboi::emulator