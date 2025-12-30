#include "cpu_opcode.hpp"
#include <sstream>
#include <stdexcept>

using namespace gehmboi::emulator;

static uint getOpcodeBlock(uint8_t opcode);
static CPUOperation decodeBlock0(uint8_t opcode);
static CPUOperation decodeBlock1(uint8_t opcode);
static CPUOperation decodeBlock2(uint8_t opcode);
static CPUOperation decodeBlock3(uint8_t opcode);

CPUOperation Opcode::decode(uint8_t opcode, bool isCBPrefixActive) {
  auto decodedOperation = CPUOperation();

  decodedOperation.op = CPUOperationTypeEnum::UNDEFINED;
  decodedOperation.operand1 = CPUOperationOperand::createNoOperand();
  decodedOperation.operand2 = CPUOperationOperand::createNoOperand();

  if (isCBPrefixActive) {
    decodedOperation = decodeBlock3(opcode);
    return decodedOperation;
  }

  auto block = getOpcodeBlock(opcode);
  switch (block) {
  case 0:
    decodedOperation = decodeBlock0(opcode);
    break;
  case 1:
    decodedOperation = decodeBlock1(opcode);
    break;
  case 2:
    decodedOperation = decodeBlock2(opcode);
    break;
  case 3:
    decodedOperation = decodeBlock3(opcode);
    break;

  default:
    // TODO
    // Throw error.
    // Make a class that can easily interpolate strings.
    std::stringstream stream;
    stream << "Opcode " << std::hex << opcode << "can't be decoded!";

    throw std::runtime_error(stream.str());
  }

  return decodedOperation;
}

uint getOpcodeBlock(uint8_t opcode) { return 0; }

CPUOperation decodeBlock0(uint8_t opcode) { return CPUOperation(); }

CPUOperation decodeBlock1(uint8_t opcode) { return CPUOperation(); }

CPUOperation decodeBlock2(uint8_t opcode) { return CPUOperation(); }

CPUOperation decodeBlock3(uint8_t opcode) { return CPUOperation(); }