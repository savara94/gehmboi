#pragma once

#include "cpu_ops.hpp"

namespace gehmboi::emulator {
static const std::unordered_map<uint8_t, Opcode> cbPrefixOpcodeMap = {
    // BLOCK_3_CB_PREFIX_RLC_R8 (0x00-0x07)
    {0x00, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RLC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x01, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RLC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x02, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RLC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x03, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RLC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x04, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RLC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x05, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RLC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x06, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RLC_R8,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x07, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RLC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createNoOperand()}},

    // BLOCK_3_CB_PREFIX_RRC_R8 (0x08-0x0F)
    {0x08, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RRC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x09, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RRC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x0A, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RRC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x0B, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RRC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x0C, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RRC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x0D, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RRC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x0E, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RRC_R8,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x0F, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RRC_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createNoOperand()}},

    // BLOCK_3_CB_PREFIX_RL_R8 (0x10-0x17)
    {0x10, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x11, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x12, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x13, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x14, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x15, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x16, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RL_R8,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x17, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createNoOperand()}},

    // BLOCK_3_CB_PREFIX_RR_R8 (0x18-0x1F)
    {0x18, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RR_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x19, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RR_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x1A, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RR_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x1B, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RR_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x1C, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RR_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x1D, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RR_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x1E, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RR_R8,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x1F, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RR_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createNoOperand()}},

    // BLOCK_3_CB_PREFIX_SLA_R8 (0x20-0x27)
    {0x20, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SLA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x21, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SLA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x22, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SLA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x23, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SLA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x24, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SLA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x25, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SLA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x26, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SLA_R8,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x27, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SLA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createNoOperand()}},

    // BLOCK_3_CB_PREFIX_SRA_R8 (0x28-0x2F)
    {0x28, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SRA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x29, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SRA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x2A, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SRA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x2B, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SRA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x2C, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SRA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x2D, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SRA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x2E, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SRA_R8,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x2F, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SRA_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createNoOperand()}},

    // BLOCK_3_CB_PREFIX_SWAP_R8 (0x30-0x37)
    {0x30, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SWAP_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x31, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SWAP_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x32, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SWAP_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x33, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SWAP_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x34, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SWAP_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x35, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SWAP_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x36, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SWAP_R8,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x37, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SWAP_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createNoOperand()}},

    // BLOCK_3_CB_PREFIX_SRL_R8 (0x38-0x3F)
    {0x38, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SRL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x39, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SRL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x3A, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SRL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x3B, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SRL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x3C, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SRL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x3D, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SRL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x3E, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SRL_R8,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false),
                            CPUOperationOperand::createNoOperand()}},
    {0x3F, Opcode{CPUOperationTypeEnum::ROTATE_SHIFT, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SRL_R8,
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false),
                            CPUOperationOperand::createNoOperand()}},

    // BLOCK_3_CB_PREFIX_BIT_B3_R8 (0x40-0x7F)
    {0x40, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x41, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x42, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x43, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x44, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x45, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x46, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x47, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0x48, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x49, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x4A, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x4B, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x4C, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x4D, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x4E, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x4F, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0x50, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x51, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x52, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x53, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x54, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x55, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x56, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x57, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0x58, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x59, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x5A, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x5B, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x5C, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x5D, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x5E, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x5F, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0x60, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x61, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x62, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x63, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x64, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x65, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x66, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x67, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0x68, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x69, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x6A, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x6B, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x6C, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x6D, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x6E, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x6F, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0x70, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x71, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x72, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x73, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x74, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x75, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x76, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x77, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0x78, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x79, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x7A, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x7B, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x7C, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x7D, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x7E, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x7F, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_BIT_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},

    // BLOCK_3_CB_PREFIX_RES_B3_R8 (0x80-0xBF)
    {0x80, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x81, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x82, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x83, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x84, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x85, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x86, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x87, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0x88, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x89, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x8A, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x8B, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x8C, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x8D, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x8E, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x8F, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0x90, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x91, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x92, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x93, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x94, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x95, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x96, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x97, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0x98, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0x99, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0x9A, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0x9B, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0x9C, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0x9D, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0x9E, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0x9F, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0xA0, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xA1, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xA2, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xA3, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xA4, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xA5, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xA6, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xA7, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0xA8, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xA9, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xAA, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xAB, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xAC, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xAD, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xAE, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xAF, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0xB0, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xB1, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xB2, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xB3, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xB4, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xB5, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xB6, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xB7, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0xB8, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xB9, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xBA, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xBB, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xBC, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xBD, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xBE, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xBF, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RES_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},

    // BLOCK_3_CB_PREFIX_SET_B3_R8 (0xC0-0xFF)
    {0xC0, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xC1, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xC2, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xC3, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xC4, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xC5, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xC6, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xC7, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(0),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0xC8, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xC9, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xCA, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xCB, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xCC, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xCD, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xCE, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xCF, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(1),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0xD0, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xD1, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xD2, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xD3, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xD4, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xD5, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xD6, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xD7, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(2),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0xD8, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xD9, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xDA, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xDB, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xDC, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xDD, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xDE, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xDF, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(3),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0xE0, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xE1, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xE2, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xE3, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xE4, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xE5, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xE6, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xE7, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(4),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0xE8, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xE9, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xEA, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xEB, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xEC, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xED, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xEE, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xEF, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(5),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0xF0, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xF1, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xF2, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xF3, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xF4, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xF5, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xF6, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xF7, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(6),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
    {0xF8, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::B, false)}},
    {0xF9, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::C, false)}},
    {0xFA, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::D, false)}},
    {0xFB, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::E, false)}},
    {0xFC, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::H, false)}},
    {0xFD, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::L, false)}},
    {0xFE, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, true, false, false)}},
    {0xFF, Opcode{CPUOperationTypeEnum::BITWISE, CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SET_B3_R8,
                            CPUOperationOperand::createLiteralOperand(7),
                            CPUOperationOperand::createReg8Operand(
                                CPURegister8Enum::A, false)}},
};

} // namespace gehmboi::emulator