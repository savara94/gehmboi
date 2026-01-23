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
    m_Memory = memoryPtr;
}

MemoryPtr& Executor::getMemory() noexcept {
    return m_Memory;
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
            // executePushPop(fetchedOperation);
            throw std::runtime_error("PUSH/POP not implemented yet in Executor");
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
        // Execution logic for different CPU operation types would go here.
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

            src8Value = m_Memory->readByte(address);
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
        m_Memory->writeByte(dstAddress, src8Value);
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

        m_Memory->writeByte(dstAddress, lowerByte);
        m_Memory->writeByte(dstAddress + 1, upperByte);
        return;
    }

    // TODO
    // Handle incrementing/decrementing HL in LD [HL+], A and LD [HL-], A

    throw std::runtime_error("Unsupported LOAD_STORE operation in Executor");
}

void Executor::executeALU(const FetchedOperation& fetchedOperation) {
    // Implementation for ALU operation execution
}

void Executor::executeRotateShift(const FetchedOperation& fetchedOperation) {
    // Implementation for ROTATE/SHIFT operation execution
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