#pragma once

#include "cpu_ops.hpp"

namespace gehmboi::emulator {
static const std::unordered_map<uint8_t, DecodedOperation> cbPrefixOpcodeMap = {
    // BLOCK_3_CB_PREFIX_RLC_R8 (0x00-0x07)
    {0x00, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RLC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x01, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RLC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x02, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RLC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x03, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RLC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x04, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RLC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x05, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RLC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x06, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RLC_R8,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x07, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RLC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createNoOperand()}},

    // BLOCK_3_CB_PREFIX_RRC_R8 (0x08-0x0F)
    {0x08, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RRC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x09, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RRC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x0A, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RRC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x0B, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RRC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x0C, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RRC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x0D, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RRC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x0E, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RRC_R8,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x0F, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RRC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createNoOperand()}},

    // BLOCK_3_CB_PREFIX_RL_R8 (0x10-0x17)
    {0x10, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x11, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x12, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x13, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x14, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x15, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x16, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RL_R8,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x17, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createNoOperand()}},

    // BLOCK_3_CB_PREFIX_RR_R8 (0x18-0x1F)
    {0x18, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RR_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x19, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RR_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x1A, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RR_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x1B, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RR_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x1C, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RR_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x1D, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RR_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x1E, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RR_R8,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x1F, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RR_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createNoOperand()}},

    // BLOCK_3_CB_PREFIX_SLA_R8 (0x20-0x27)
    {0x20, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SLA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x21, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SLA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x22, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SLA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x23, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SLA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x24, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SLA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x25, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SLA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x26, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SLA_R8,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x27, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SLA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createNoOperand()}},

    // BLOCK_3_CB_PREFIX_SRA_R8 (0x28-0x2F)
    {0x28, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SRA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x29, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SRA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x2A, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SRA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x2B, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SRA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x2C, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SRA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x2D, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SRA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x2E, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SRA_R8,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x2F, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SRA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createNoOperand()}},

    // BLOCK_3_CB_PREFIX_SWAP_R8 (0x30-0x37)
    {0x30, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SWAP_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x31, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SWAP_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x32, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SWAP_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x33, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SWAP_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x34, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SWAP_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x35, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SWAP_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x36, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SWAP_R8,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x37, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SWAP_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createNoOperand()}},

    // BLOCK_3_CB_PREFIX_SRL_R8 (0x38-0x3F)
    {0x38, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SRL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x39, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SRL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x3A, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SRL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x3B, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SRL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x3C, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SRL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x3D, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SRL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x3E, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SRL_R8,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x3F, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SRL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createNoOperand()}},

    // BLOCK_3_CB_PREFIX_BIT_B3_R8 (0x40-0x7F)
    {0x40, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x41, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x42, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x43, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x44, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x45, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x46, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x47, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0x48, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x49, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x4A, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x4B, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x4C, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x4D, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x4E, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x4F, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0x50, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x51, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x52, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x53, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x54, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x55, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x56, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x57, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0x58, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x59, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x5A, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x5B, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x5C, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x5D, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x5E, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x5F, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0x60, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x61, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x62, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x63, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x64, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x65, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x66, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x67, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0x68, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x69, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x6A, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x6B, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x6C, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x6D, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x6E, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x6F, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0x70, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x71, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x72, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x73, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x74, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x75, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x76, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x77, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0x78, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x79, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x7A, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x7B, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x7C, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x7D, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x7E, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x7F, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},

    // BLOCK_3_CB_PREFIX_RES_B3_R8 (0x80-0xBF)
    {0x80, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x81, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x82, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x83, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x84, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x85, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x86, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x87, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0x88, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x89, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x8A, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x8B, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x8C, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x8D, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x8E, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x8F, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0x90, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x91, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x92, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x93, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x94, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x95, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x96, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x97, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0x98, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x99, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x9A, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x9B, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x9C, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x9D, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x9E, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x9F, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0xA0, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xA1, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xA2, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xA3, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xA4, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xA5, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xA6, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xA7, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0xA8, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xA9, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xAA, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xAB, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xAC, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xAD, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xAE, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xAF, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0xB0, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xB1, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xB2, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xB3, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xB4, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xB5, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xB6, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xB7, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0xB8, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xB9, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xBA, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xBB, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xBC, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xBD, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xBE, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xBF, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},

    // BLOCK_3_CB_PREFIX_SET_B3_R8 (0xC0-0xFF)
    {0xC0, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xC1, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xC2, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xC3, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xC4, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xC5, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xC6, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xC7, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0xC8, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xC9, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xCA, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xCB, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xCC, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xCD, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xCE, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xCF, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0xD0, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xD1, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xD2, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xD3, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xD4, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xD5, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xD6, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xD7, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0xD8, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xD9, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xDA, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xDB, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xDC, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xDD, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xDE, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xDF, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0xE0, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xE1, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xE2, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xE3, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xE4, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xE5, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xE6, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xE7, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0xE8, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xE9, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xEA, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xEB, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xEC, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xED, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xEE, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xEF, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0xF0, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xF1, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xF2, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xF3, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xF4, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xF5, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xF6, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xF7, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0xF8, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xF9, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xFA, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xFB, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xFC, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xFD, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xFE, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xFF, DecodedOperation{CPUOperationTypeEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
};

} // namespace gehmboi::emulator