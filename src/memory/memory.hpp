#pragma once

#include <memory>

namespace gehmboi::emulator {
using Address = uint16_t;
using RawByte = uint8_t;

class Memory;
using MemoryPtr = std::shared_ptr<Memory>;

class Memory {
    public:

    virtual RawByte readByte(Address address) = 0;
    virtual void writeByte(Address address, RawByte value) = 0;

    virtual ~Memory();
};

}