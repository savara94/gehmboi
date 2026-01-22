#include "cpu_opcode.hpp"

#include "cpu_opcode_block_0.hpp"
#include "cpu_opcode_block_1.hpp"
#include "cpu_opcode_block_2.hpp"
#include "cpu_opcode_block_3.hpp"
#include "cpu_opcode_block_cb.hpp"
#include "cpu_opcode_static.hpp"

#include <functional>
#include <iomanip>

#include <sstream>
#include <stdexcept>

using namespace gehmboi::emulator;

static const uint8_t blockMask = 0xC0;
static const uint8_t blockShift = 6;

Opcode::Opcode(
  CPUOperationTypeEnum type,
  CPUOperationIdEnum id,
  const CPUOperationOperand& op1,
  const CPUOperationOperand& op2  
) : m_Type(type), m_Id(id), m_Op1(op1), m_Op2(op2) {

}

CPUOperationTypeEnum Opcode::getType() const {
  return m_Type;
}

CPUOperationIdEnum Opcode::getId() const {
  return m_Id;
}

CPUOperationOperand Opcode::getOperand1() const {
  return m_Op1;
}

CPUOperationOperand Opcode::getOperand2() const {
  return m_Op2;
}

Opcode Opcode::decode(uint8_t opcode, bool isCBPrefixActive) {
  if (isCBPrefixActive) {
    return cbPrefixOpcodeMap.at(opcode);
  }

  if (staticOpcodeMapNoPrefix.find(opcode) != staticOpcodeMapNoPrefix.end()) {
    return staticOpcodeMapNoPrefix.at(opcode);
  }

  auto block = (opcode & blockMask) >> blockShift;
  if (block == 0 && block0Map.find(opcode) != block0Map.end()) {
    return block0Map.at(opcode);
  }

  if (block == 1 && block1Map.find(opcode) != block1Map.end()) {
    return block1Map.at(opcode);
  }

  if (block == 2 && block2Map.find(opcode) != block2Map.end()) {
    return block2Map.at(opcode);
  }

  if (block == 3 && block3Map.find(opcode) != block3Map.end()) {
    return block3Map.at(opcode);
  }

  std::stringstream stream;
  stream << "Opcode 0x" << std::hex << std::setw(2) << std::setfill('0') << int(opcode) << " can't be decoded!";

  throw std::runtime_error(stream.str());
}