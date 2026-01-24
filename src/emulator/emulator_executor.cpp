#include "emulator_executor.hpp"

#include <stdexcept>

using namespace gehmboi::emulator;

CPURegisters& Executor::getRegisters() noexcept {
    return m_cpuRegisters;
}

void Executor::setRegisters(const CPURegisters& registers) {
    m_cpuRegisters = registers;
}

void Executor::setMemory(const MemoryPtr& memoryPtr) {
    m_memoryPtr = memoryPtr;
}

MemoryPtr& Executor::getMemory() noexcept {
    return m_memoryPtr;
}

void Executor::execute(const FetchedOperation& fetchedOperation) {
    if (getMemory() == nullptr) {
        throw std::runtime_error("Memory not set in Executor");
    }

    auto opcode = fetchedOperation.getOpcode();
    auto type = opcode.getType();

    switch(type) {
        case CPUOperationTypeEnum::LOAD_STORE:
            executeLoadStore(fetchedOperation);
            break;
        case CPUOperationTypeEnum::PUSH_POP:
            executePushPop(fetchedOperation);
            break;
        case CPUOperationTypeEnum::ALU:
            executeALU(fetchedOperation);
            break;
        case CPUOperationTypeEnum::ROTATE_SHIFT:
            executeRotateShift(fetchedOperation);
            break;
        case CPUOperationTypeEnum::BITWISE:
            executeBitwise(fetchedOperation);
            break;
        case CPUOperationTypeEnum::JUMP:
            executeJump(fetchedOperation);
            break;
        case CPUOperationTypeEnum::CALL:
            executeCall(fetchedOperation);
            break;
        case CPUOperationTypeEnum::RETURN:
            executeReturn(fetchedOperation);
            break;
        case CPUOperationTypeEnum::SPECIFIC:
            executeSpecific(fetchedOperation);
            break;
        default:
            throw std::runtime_error("Unsupported CPU operation type");
    }
}

void Executor::executeLoadStore(const FetchedOperation& fetchedOperation) {
    auto opcode = fetchedOperation.getOpcode();

    auto dstOperand = opcode.getOperand1();
    auto srcOperand = opcode.getOperand2();

    auto srcValue = fetchedOperation.getValue2();
    auto isSrc8bit = std::holds_alternative<uint8_t>(srcValue);
    auto isSrc16bit = std::holds_alternative<uint16_t>(srcValue);
    auto isSrcPointer = srcOperand.isDereferenced();

    auto dstValue = fetchedOperation.getValue1();
    auto isDst8bit = std::holds_alternative<uint8_t>(dstValue);
    auto isDst16bit = std::holds_alternative<uint16_t>(dstValue);
    auto isDstPointer = dstOperand.isDereferenced();

    // LD r8, r8
    // LD r8, imm8
    // LD r8, [r16mem]
    // LD r8, [r8]
    // LD r8, [imm8]
    // LD r8, [imm16]
    if (dstOperand.getType() == CPUOperandTypeEnum::R8 && !isDstPointer) {
        CPURegister8Enum dstReg = dstOperand.getReg8();
        uint8_t src8Value = 0;
        
        if (isSrcPointer) {          
            uint16_t address = 0;

            if (isSrc16bit) {
                address = std::get<uint16_t>(srcValue);
            } else if (isSrc8bit) {
                address = std::get<uint8_t>(srcValue);
            } else {
                throw std::runtime_error("Source value not 16bit or 8bit for dereferenced load");
            };

            src8Value = m_memoryPtr->readByte(address);
        } else {
            src8Value = std::get<uint8_t>(srcValue);
        }

        m_cpuRegisters.setR8(dstReg, src8Value);
        return;
    }
    
    // LD r16, imm16
    // LD r16, r16
    // LD r16, sp + imm8

    if (dstOperand.getType() == CPUOperandTypeEnum::R16 && !isDstPointer) {
        auto dstReg = dstOperand.getReg16();
        uint16_t dst16Value = 0;

        if (!isSrc16bit) {
            throw std::runtime_error("Source value not 16bit for r16 load");
        }

        if (opcode.getId() == CPUOperationIdEnum::BLOCK_3_LD_HL_SP_IMM8) {
            auto stackPointer = static_cast<int32_t>(m_cpuRegisters.getR16(CPURegister16Enum::SP));

            // TODO:
            // Check for signed parameters.

            // srcValue is signed imm8
            
            // Z: reset
            // H: set if there is a carry from bit 11, otherwise reset
            // N: reset
            // CY: set if there is a carry from bit 15, otherwise reset
            dst16Value = static_cast<uint16_t>(stackPointer + std::get<int8_t>(srcValue));
        }
        else {
            dst16Value = std::get<uint16_t>(srcValue);
        }

        m_cpuRegisters.setR16(dstReg, dst16Value);
        return;
    }

    // LD [r8], r8
    // TODO Check if this needs 0xFF00 to  be added

    // LD [r16mem], r8
    // LD [imm8], r8
    // LD [imm16], r8

    if (isDstPointer) {
        uint16_t dstAddress = 0;

        if (isDst16bit) {
            dstAddress = std::get<uint16_t>(dstValue);
        } else if (isDst8bit) {
            dstAddress = std::get<uint8_t>(dstValue);
        } else {
            throw std::runtime_error("Destination address not 16bit or 8bit for dereferenced store");
        }

        if (!isSrc8bit) {
            throw std::runtime_error("Source value not 8bit for dereferenced store operation");
        }

        uint8_t src8Value = std::get<uint8_t>(srcValue);
        m_memoryPtr->writeByte(dstAddress, src8Value);
        return;
    }

    // Special case
    // LD [imm16], r16 --- [imm16], sp
    if (opcode.getId() == CPUOperationIdEnum::BLOCK_0_LD_IMM16MEM_SP) {
        if (!isDst16bit) {
            throw std::runtime_error("Destination address not 16bit for imm16mem, sp store");
        }

        if (!isSrc16bit) {
            throw std::runtime_error("Source value not 16bit for imm16mem, sp store");
        }

        uint16_t dstAddress = std::get<uint16_t>(dstValue);
        uint16_t src16Value = std::get<uint16_t>(srcValue);

        uint8_t lowerByte = src16Value & 0x00FF;
        uint8_t upperByte = (src16Value & 0xFF00) >> 8;

        m_memoryPtr->writeByte(dstAddress, lowerByte);
        m_memoryPtr->writeByte(dstAddress + 1, upperByte);
        return;
    }

    // TODO
    // Handle incrementing/decrementing HL in LD [HL+], A and LD [HL-], A

    throw std::runtime_error("Unsupported LOAD_STORE operation in Executor");
}

void Executor::executePushPop(const FetchedOperation& fetchedOperation) {
    auto opcode = fetchedOperation.getOpcode();
    auto id = opcode.getId();

    if (!(id == CPUOperationIdEnum::BLOCK_3_POP_R16_STK || 
          id == CPUOperationIdEnum::BLOCK_3_PUSH_R16_STK)) {
        throw std::runtime_error("Unsupported PUSH/POP operation in Executor");
    }

    if (id == CPUOperationIdEnum::BLOCK_3_PUSH_R16_STK) {
        if (!std::holds_alternative<uint16_t>(fetchedOperation.getValue1())) {
            throw std::runtime_error("PUSH operation expects 16bit value");
        }

        auto opValue = std::get<uint16_t>(fetchedOperation.getValue2());
        uint8_t upperByte = (opValue & 0xFF00) >> 8;
        uint8_t lowerByte = opValue & 0x00FF;

        uint16_t sp = m_cpuRegisters.getR16(CPURegister16Enum::SP);

        m_memoryPtr->writeByte(sp - 1, upperByte);
        m_memoryPtr->writeByte(sp - 2, lowerByte);
        m_cpuRegisters.setR16(CPURegister16Enum::SP, sp - 2);
        return;
    }

    if (id == CPUOperationIdEnum::BLOCK_3_POP_R16_STK) {
        if (!std::holds_alternative<uint16_t>(fetchedOperation.getValue1())) {
            throw std::runtime_error("POP operation expects 16bit value");
        }

        auto reg16 = opcode.getOperand1().getReg16();
        uint16_t sp = m_cpuRegisters.getR16(CPURegister16Enum::SP);
        uint8_t lowerByte = m_memoryPtr->readByte(sp);
        uint8_t upperByte = m_memoryPtr->readByte(sp + 1);

        uint16_t opValue = (static_cast<uint16_t>(upperByte) << 8) | static_cast<uint16_t>(lowerByte);
        
        m_cpuRegisters.setR16(reg16, opValue);
        m_cpuRegisters.setR16(CPURegister16Enum::SP, sp + 2);
        return;
    }
}

void Executor::executeALU(const FetchedOperation& fetchedOperation) {
    auto opcode = fetchedOperation.getOpcode();
    auto id = opcode.getId();

    // ADD A, r8
    // ADD A, imm8
    // ADD A, [r16]
    // ADD HL, r16
    // ADD SP, imm8
    if (id == CPUOperationIdEnum::BLOCK_0_ADD_HL_R16 ||
        id == CPUOperationIdEnum::BLOCK_2_ADD_A_R8 ||
        id == CPUOperationIdEnum::BLOCK_3_ADD_A_IMM8 ||
        id == CPUOperationIdEnum::BLOCK_3_ADD_SP_IMM8) {
        executeAdd(fetchedOperation);
        return;
    }

    // ADC A, r8
    // ADC A, imm8
    if (id == CPUOperationIdEnum::BLOCK_2_ADC_A_R8 ||
        id == CPUOperationIdEnum::BLOCK_3_ADC_A_IMM8) {
        executeAdc(fetchedOperation);
        return;
    }

    // SUB A, r8
    // SUB A, imm8
    if (id == CPUOperationIdEnum::BLOCK_2_SUB_A_R8 ||
        id == CPUOperationIdEnum::BLOCK_3_SUB_A_IMM8) {
        executeSub(fetchedOperation);
        return;
    }

    // SBC A, r8
    // SBC A, imm8
    if (id == CPUOperationIdEnum::BLOCK_2_SBC_A_R8 ||
        id == CPUOperationIdEnum::BLOCK_3_SBC_A_IMM8) {
        executeSbc(fetchedOperation);
        return;
    }

    // AND A, r8
    // AND A, imm8
    if (id == CPUOperationIdEnum::BLOCK_2_AND_A_R8 ||
        id == CPUOperationIdEnum::BLOCK_3_AND_A_IMM8) {
        executeAnd(fetchedOperation);
        return;
    }

    // XOR A, r8
    // XOR A, imm8
    if (id == CPUOperationIdEnum::BLOCK_2_XOR_A_R8 ||
        id == CPUOperationIdEnum::BLOCK_3_XOR_A_IMM8) {
        executeXor(fetchedOperation);
        return;
    }

    // OR A, r8
    // OR A, imm8
    if (id == CPUOperationIdEnum::BLOCK_2_OR_A_R8 ||
        id == CPUOperationIdEnum::BLOCK_3_OR_A_IMM8) {
        executeOr(fetchedOperation);
        return;
    }

    // CP A, r8
    // CP A, imm8
    if (id == CPUOperationIdEnum::BLOCK_2_CP_A_R8 ||
        id == CPUOperationIdEnum::BLOCK_3_CP_A_IMM8) {
        executeCp(fetchedOperation);
        return;
    }

    // INC r16
    // INC r8
    if (id == CPUOperationIdEnum::BLOCK_0_INC_R16 ||
        id == CPUOperationIdEnum::BLOCK_0_INC_R8) {
        executeInc(fetchedOperation);
        return;
    }

    // DEC r16
    // DEC r8
    if (id == CPUOperationIdEnum::BLOCK_0_DEC_R16 ||
        id == CPUOperationIdEnum::BLOCK_0_DEC_R8) {
        executeDec(fetchedOperation);
        return;
    }
}

void Executor::executeRotateShift(const FetchedOperation& fetchedOperation) {
    auto id = fetchedOperation.getOpcode().getId();

    if (id == CPUOperationIdEnum::BLOCK_0_RLCA) {
        // Implementation for RLCA operation execution
        return;
    }

    if (id == CPUOperationIdEnum::BLOCK_0_RLA) {
        // Implementation for RLA operation execution
        return;
    }

    if (id == CPUOperationIdEnum::BLOCK_0_RRCA) {
        // Implementation for RRCA operation execution
        return;
    }

    if (id == CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RLC_R8) {
        // Implementation for RLC operation execution
        return;
    }

    if (id == CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RL_R8) {
        // Implementation for RL operation execution
        return;
    }

    if (id == CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RRC_R8) {
        // Implementation for RRC operation execution
        return;
    }

    if (id == CPUOperationIdEnum::BLOCK_3_CB_PREFIX_RR_R8) {
        // Implementation for RR operation execution
        return;
    }

    if (id == CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SLA_R8) {
        // Implementation for SLA operation execution
        return;
    }

    if (id == CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SRA_R8) {
        // Implementation for SRA operation execution
        return;
    }

    if (id == CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SRL_R8) {
        // Implementation for SRL operation execution
        return;
    }

    if (id == CPUOperationIdEnum::BLOCK_3_CB_PREFIX_SWAP_R8) {
        // Implementation for SWAP operation execution
        return;
    }
}

void Executor::executeBitwise(const FetchedOperation& fetchedOperation) {
    // Implementation for BITWISE operation execution
}

void Executor::executeJump(const FetchedOperation& fetchedOperation) {
    // Implementation for JUMP operation execution
}

void Executor::executeCall(const FetchedOperation& fetchedOperation) {
    // Implementation for CALL operation execution
}

void Executor::executeReturn(const FetchedOperation& fetchedOperation) {
    // Implementation for RETURN operation execution
}

void Executor::executeSpecific(const FetchedOperation& fetchedOperation) {
    // Implementation for SPECIFIC operation execution
}

void Executor::executeAdd(const FetchedOperation& fetchedOperation) {

}

void Executor::executeAdc(const FetchedOperation& fetchedOperation) {

}

void Executor::executeSub(const FetchedOperation& fetchedOperation) {

}

void Executor::executeSbc(const FetchedOperation& fetchedOperation) {

}

void Executor::executeAnd(const FetchedOperation& fetchedOperation) {

}

void Executor::executeXor(const FetchedOperation& fetchedOperation) {

}

void Executor::executeOr(const FetchedOperation& fetchedOperation) {

}

void Executor::executeCp(const FetchedOperation& fetchedOperation) {

}

void Executor::executeInc(const FetchedOperation& fetchedOperation) {

}

void Executor::executeDec(const FetchedOperation& fetchedOperation) {

}