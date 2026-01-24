#pragma once

#include <memory/memory.hpp>

#include "emulator_fetched_op.hpp"

namespace gehmboi::emulator {

class Executor {
  public:
    void execute(const FetchedOperation& fetchedOperation);

    CPURegisters& getRegisters() noexcept;
    void setRegisters(const CPURegisters& registers);

    void setMemory(const MemoryPtr& memoryPtr);
    MemoryPtr& getMemory() noexcept;

  private:
    void executeLoadStore(const FetchedOperation& fetchedOperation);
    void executePushPop(const FetchedOperation& fetchedOperation);
    void executeALU(const FetchedOperation& fetchedOperation);
    void executeRotateShift(const FetchedOperation& fetchedOperation);
    void executeBitwise(const FetchedOperation& fetchedOperation);
    void executeJump(const FetchedOperation& fetchedOperation);
    void executeCall(const FetchedOperation& fetchedOperation);
    void executeReturn(const FetchedOperation& fetchedOperation);
    void executeSpecific(const FetchedOperation& fetchedOperation);

    void executeAdd(const FetchedOperation& fetchedOperation);
    void executeAdc(const FetchedOperation& fetchedOperation);
    void executeSub(const FetchedOperation& fetchedOperation);
    void executeSbc(const FetchedOperation& fetchedOperation);
    void executeAnd(const FetchedOperation& fetchedOperation);
    void executeXor(const FetchedOperation& fetchedOperation);
    void executeOr(const FetchedOperation& fetchedOperation);
    void executeCp(const FetchedOperation& fetchedOperation);
    void executeInc(const FetchedOperation& fetchedOperation);
    void executeDec(const FetchedOperation& fetchedOperation);

    CPURegisters m_cpuRegisters;
    MemoryPtr m_memoryPtr;
};

}