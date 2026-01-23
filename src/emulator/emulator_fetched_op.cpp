#include "emulator_fetched_op.hpp"

#include <stdexcept>

using namespace gehmboi::emulator;

FetchedOperation::FetchedOperation(const Opcode& opcode, const OperandValue &value1, const OperandValue &value2)
    : m_opcode(opcode), m_v1(value1), m_v2(value2) {
    verify();
}

const Opcode& FetchedOperation::getOpcode() const noexcept {
    return m_opcode;
}

const OperandValue& FetchedOperation::getValue1() const noexcept {
    return m_v1;
}

const OperandValue& FetchedOperation::getValue2() const noexcept {
    return m_v2;
}

void FetchedOperation::verify() {
    auto op1 = m_opcode.getOperand1();
    auto op2 = m_opcode.getOperand2();

    auto v1 = getValue1();
    auto v2 = getValue2();

    // Register operand types
    if (op1.getType() == CPUOperandTypeEnum::R8) {
        if (!std::holds_alternative<uint8_t>(v1)) {
            throw std::runtime_error("FetchedOperation: Operand1 expected to be uint8_t for R8 operand");
        }
    }

    if (op1.getType() == CPUOperandTypeEnum::R16) {
        if (!std::holds_alternative<uint16_t>(v1)) {
            throw std::runtime_error("FetchedOperation: Operand1 expected to be uint16_t for R16 operand");
        }
    }

    if (op2.getType() == CPUOperandTypeEnum::R8) {
        if (!std::holds_alternative<uint8_t>(v2)) {
            throw std::runtime_error("FetchedOperation: Operand2 expected to be uint8_t for R8 operand");
        }
    }

    if (op2.getType() == CPUOperandTypeEnum::R16) {
        if (!std::holds_alternative<uint16_t>(v2)) {
            throw std::runtime_error("FetchedOperation: Operand2 expected to be uint16_t for R16 operand");
        }
    }

    // Immediate operand types
    if (op1.getType() == CPUOperandTypeEnum::IMM8) {
        if (!(std::holds_alternative<uint8_t>(v1) || std::holds_alternative<int8_t>(v1))) {
            throw std::runtime_error("FetchedOperation: Operand1 expected to be uint8_t or int8_t for IMM8 operand");
        }
    }

    if (op1.getType() == CPUOperandTypeEnum::IMM16) {
        if (!std::holds_alternative<uint16_t>(v1)) {
            throw std::runtime_error("FetchedOperation: Operand1 expected to be uint16_t for IMM16 operand");
        }
    }

    if (op2.getType() == CPUOperandTypeEnum::IMM8) {
        if (!(std::holds_alternative<uint8_t>(v2) || std::holds_alternative<int8_t>(v2))) {
            throw std::runtime_error("FetchedOperation: Operand2 expected to be uint8_t or int8_t for IMM8 operand");
        }
    }

    if (op2.getType() == CPUOperandTypeEnum::IMM16) {
        if (!std::holds_alternative<uint16_t>(v2)) {
            throw std::runtime_error("FetchedOperation: Operand2 expected to be uint16_t for IMM16 operand");
        }
    }

    // Literal operand types
    if (op1.getType() == CPUOperandTypeEnum::LITERAL) {
        if (!std::holds_alternative<uint8_t>(v1)) {
            throw std::runtime_error("FetchedOperation: Operand1 expected to be uint8_t for LITERAL operand");
        }
    }

    if (op2.getType() == CPUOperandTypeEnum::LITERAL) {
        if (!std::holds_alternative<uint8_t>(v2)) {
            throw std::runtime_error("FetchedOperation: Operand2 expected to be uint8_t for LITERAL operand");
        }
    }
}