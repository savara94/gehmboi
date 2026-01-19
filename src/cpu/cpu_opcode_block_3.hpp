#pragma once

#include "cpu_ops.hpp"

namespace gehmboi::emulator {
static const std::unordered_map<uint8_t, Opcode> block3Map = {
    // BLOCK_3_RET_COND
    {0xC0, Opcode{CPUOperationTypeEnum::BLOCK_3_RET_COND,
                            CPUOperationOperand::createConditionOperand(
                                CPUConditionEnum::NZ),
                            CPUOperationOperand::createNoOperand()}},
    {0xC8, Opcode{CPUOperationTypeEnum::BLOCK_3_RET_COND,
                            CPUOperationOperand::createConditionOperand(
                                CPUConditionEnum::Z),
                            CPUOperationOperand::createNoOperand()}},
    {0xD0, Opcode{CPUOperationTypeEnum::BLOCK_3_RET_COND,
                            CPUOperationOperand::createConditionOperand(
                                CPUConditionEnum::NC),
                            CPUOperationOperand::createNoOperand()}},
    {0xD8, Opcode{CPUOperationTypeEnum::BLOCK_3_RET_COND,
                            CPUOperationOperand::createConditionOperand(
                                CPUConditionEnum::C),
                            CPUOperationOperand::createNoOperand()}},
    // BLOCK_3_JP_COND_IMM16
    {0xC2, Opcode{CPUOperationTypeEnum::BLOCK_3_JP_COND_IMM16,
                            CPUOperationOperand::createConditionOperand(
                                CPUConditionEnum::NZ),
                            CPUOperationOperand::createImm16Operand(false)}},
    {0xCA, Opcode{CPUOperationTypeEnum::BLOCK_3_JP_COND_IMM16,
                            CPUOperationOperand::createConditionOperand(
                                CPUConditionEnum::Z),
                            CPUOperationOperand::createImm16Operand(false)}},
    {0xD2, Opcode{CPUOperationTypeEnum::BLOCK_3_JP_COND_IMM16,
                            CPUOperationOperand::createConditionOperand(
                                CPUConditionEnum::NC),
                            CPUOperationOperand::createImm16Operand(false)}},
    {0xDA, Opcode{CPUOperationTypeEnum::BLOCK_3_JP_COND_IMM16,
                            CPUOperationOperand::createConditionOperand(
                                CPUConditionEnum::C),
                            CPUOperationOperand::createImm16Operand(false)}},
    // BLOCK_3_CALL_COND_IMM16
    {0xC4, Opcode{CPUOperationTypeEnum::BLOCK_3_CALL_COND_IMM16,
                            CPUOperationOperand::createConditionOperand(
                                CPUConditionEnum::NZ),
                            CPUOperationOperand::createImm16Operand(false)}},
    {0xCC, Opcode{CPUOperationTypeEnum::BLOCK_3_CALL_COND_IMM16,
                            CPUOperationOperand::createConditionOperand(
                                CPUConditionEnum::Z),
                            CPUOperationOperand::createImm16Operand(false)}},
    {0xD4, Opcode{CPUOperationTypeEnum::BLOCK_3_CALL_COND_IMM16,
                            CPUOperationOperand::createConditionOperand(
                                CPUConditionEnum::NC),
                            CPUOperationOperand::createImm16Operand(false)}},
    {0xDC, Opcode{CPUOperationTypeEnum::BLOCK_3_CALL_COND_IMM16,
                            CPUOperationOperand::createConditionOperand(
                                CPUConditionEnum::C),
                            CPUOperationOperand::createImm16Operand(false)}},
    // BLOCK_3_RST_TGT3
    {0xC7, Opcode{CPUOperationTypeEnum::BLOCK_3_RST_TGT3,
                            CPUOperationOperand::createLiteralOperand(0x00),
                            CPUOperationOperand::createNoOperand()}},
    {0xCF, Opcode{CPUOperationTypeEnum::BLOCK_3_RST_TGT3,
                            CPUOperationOperand::createLiteralOperand(0x08),
                            CPUOperationOperand::createNoOperand()}},
    {0xD7, Opcode{CPUOperationTypeEnum::BLOCK_3_RST_TGT3,
                            CPUOperationOperand::createLiteralOperand(0x10),
                            CPUOperationOperand::createNoOperand()}},
    {0xDF, Opcode{CPUOperationTypeEnum::BLOCK_3_RST_TGT3,
                            CPUOperationOperand::createLiteralOperand(0x18),
                            CPUOperationOperand::createNoOperand()}},
    {0xE7, Opcode{CPUOperationTypeEnum::BLOCK_3_RST_TGT3,
                            CPUOperationOperand::createLiteralOperand(0x20),
                            CPUOperationOperand::createNoOperand()}},
    {0xEF, Opcode{CPUOperationTypeEnum::BLOCK_3_RST_TGT3,
                            CPUOperationOperand::createLiteralOperand(0x28),
                            CPUOperationOperand::createNoOperand()}},
    {0xF7, Opcode{CPUOperationTypeEnum::BLOCK_3_RST_TGT3,
                            CPUOperationOperand::createLiteralOperand(0x30),
                            CPUOperationOperand::createNoOperand()}},
    {0xFF, Opcode{CPUOperationTypeEnum::BLOCK_3_RST_TGT3,
                            CPUOperationOperand::createLiteralOperand(0x38),
                            CPUOperationOperand::createNoOperand()}},
    // BLOCK_3_POP_R16_STK
    {0xC1, Opcode{CPUOperationTypeEnum::BLOCK_3_POP_R16_STK,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::BC, false, false, false),
                            CPUOperationOperand::createNoOperand()}},
    {0xD1, Opcode{CPUOperationTypeEnum::BLOCK_3_POP_R16_STK,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::DE, false, false, false),
                            CPUOperationOperand::createNoOperand()}},
    {0xE1, Opcode{CPUOperationTypeEnum::BLOCK_3_POP_R16_STK,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, false, false, false),
                            CPUOperationOperand::createNoOperand()}},
    {0xF1, Opcode{CPUOperationTypeEnum::BLOCK_3_POP_R16_STK,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::AF, false, false, false),
                            CPUOperationOperand::createNoOperand()}},
    // BLOCK_3_PUSH_R16_STK
    {0xC5, Opcode{CPUOperationTypeEnum::BLOCK_3_PUSH_R16_STK,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::BC, false, false, false),
                            CPUOperationOperand::createNoOperand()}},
    {0xD5, Opcode{CPUOperationTypeEnum::BLOCK_3_PUSH_R16_STK,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::DE, false, false, false),
                            CPUOperationOperand::createNoOperand()}},
    {0xE5, Opcode{CPUOperationTypeEnum::BLOCK_3_PUSH_R16_STK,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::HL, false, false, false),
                            CPUOperationOperand::createNoOperand()}},
    {0xF5, Opcode{CPUOperationTypeEnum::BLOCK_3_PUSH_R16_STK,
                            CPUOperationOperand::createReg16Operand(
                                CPURegister16Enum::AF, false, false, false),
                            CPUOperationOperand::createNoOperand()}},
};

} // namespace gehmboi::emulator