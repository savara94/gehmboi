#pragma once

#include "cpu_ops.hpp"

namespace gehmboi::emulator {
static const std::unordered_map<uint8_t, DecodedOperation> block1Map = {
    // BLOCK_1_LD_HALT
    {0x76,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_HALT,
         CPUOperationOperand::createNoOperand(),
         CPUOperationOperand::createNoOperand(),
     }},
    // BLOCK_1_LD_R8_R8
    // B register destination
    {0x40,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false),
     }},
    {0x41,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false),
     }},
    {0x42,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false),
     }},
    {0x43,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false),
     }},
    {0x44,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false),
     }},
    {0x45,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false),
     }},
    {0x46,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false),
         CPUOperationOperand::createReg16Operand(CPURegister16Enum::HL, true,
                                                 false, false),
     }},
    {0x47,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
     }},
    // C register destination
    {0x48,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false),
     }},
    {0x49,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false),
     }},
    {0x4A,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false),
     }},
    {0x4B,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false),
     }},
    {0x4C,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false),
     }},
    {0x4D,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false),
     }},
    {0x4E,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false),
         CPUOperationOperand::createReg16Operand(CPURegister16Enum::HL, true,
                                                 false, false),
     }},
    {0x4F,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
     }},
    // D register destination
    {0x50,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false),
     }},
    {0x51,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false),
     }},
    {0x52,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false),
     }},
    {0x53,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false),
     }},
    {0x54,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false),
     }},
    {0x55,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false),
     }},
    {0x56,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false),
         CPUOperationOperand::createReg16Operand(CPURegister16Enum::HL, true,
                                                 false, false),
     }},
    {0x57,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
     }},
    // E register destination
    {0x58,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false),
     }},
    {0x59,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false),
     }},
    {0x5A,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false),
     }},
    {0x5B,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false),
     }},
    {0x5C,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false),
     }},
    {0x5D,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false),
     }},
    {0x5E,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false),
         CPUOperationOperand::createReg16Operand(CPURegister16Enum::HL, true,
                                                 false, false),
     }},
    {0x5F,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
     }},
    // H register destination
    {0x60,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false),
     }},
    {0x61,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false),
     }},
    {0x62,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false),
     }},
    {0x63,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false),
     }},
    {0x64,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false),
     }},
    {0x65,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false),
     }},
    {0x66,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false),
         CPUOperationOperand::createReg16Operand(CPURegister16Enum::HL, true,
                                                 false, false),
     }},
    {0x67,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
     }},
    // L register destination
    {0x68,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false),
     }},
    {0x69,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false),
     }},
    {0x6A,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false),
     }},
    {0x6B,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false),
     }},
    {0x6C,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false),
     }},
    {0x6D,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false),
     }},
    {0x6E,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false),
         CPUOperationOperand::createReg16Operand(CPURegister16Enum::HL, true,
                                                 false, false),
     }},
    {0x6F,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
     }},
    // HL Memory destination
    {0x70,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg16Operand(CPURegister16Enum::HL, true,
                                                 false, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false),
     }},
    {0x71,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg16Operand(CPURegister16Enum::HL, true,
                                                 false, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false),
     }},
    {0x72,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg16Operand(CPURegister16Enum::HL, true,
                                                 false, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false),
     }},
    {0x73,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg16Operand(CPURegister16Enum::HL, true,
                                                 false, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false),
     }},
    {0x74,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg16Operand(CPURegister16Enum::HL, true,
                                                 false, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false),
     }},
    {0x75,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg16Operand(CPURegister16Enum::HL, true,
                                                 false, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false),
     }},
    {0x77,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg16Operand(CPURegister16Enum::HL, true,
                                                 false, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
     }},
    // A register destination
    {0x78,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::B, false),
     }},
    {0x79,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::C, false),
     }},
    {0x7A,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::D, false),
     }},
    {0x7B,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::E, false),
     }},
    {0x7C,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::H, false),
     }},
    {0x7D,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::L, false),
     }},
    {0x7E,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg16Operand(CPURegister16Enum::HL, true,
                                                 false, false),
     }},
    {0x7F,
     DecodedOperation{
         CPUOperationTypeEnum::BLOCK_1_LD_R8_R8,
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
         CPUOperationOperand::createReg8Operand(CPURegister8Enum::A, false),
     }},

};
} // namespace gehmboi::emulator