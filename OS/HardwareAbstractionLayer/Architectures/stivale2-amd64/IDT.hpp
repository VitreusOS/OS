#pragma once

#include <stdint.h>

struct Registers
{
    uint64_t r15, r14, r13, r12, r11, r10, r9, r8, rbp, rrsp, rsi, rdi, rdx, rcx, rbx, rax;
    uint64_t interruptNumber, errorCode;
    uint64_t rip, cs, rflags, rsp, ss;
} __attribute__((packed));

#ifdef __cplusplus

#include "Debug.hpp"

HAL::Debug& operator<<(HAL::Debug& dbg, Registers& reg)
{
    dbg << "\n";
    dbg << "r15\tr14\tr13\tr12\tr11\tr10\tr9\tr8\trbp\trrsp\trsi\trdi\trdx\trcx\trbx\trax\n";
    dbg << reg.r15 << "\t" << reg.r14 << "\t" << reg.r13 << "\t" << reg.r12 << "\t" << reg.r11 << "\t" << reg.r10 << "\t" << reg.r9 << "\t" << reg.r8 << "\t" << reg.rbp << "\t" << reg.rrsp << "\t" << reg.rsi << "\t" << reg.rdi << "\t" << reg.rdx << "\t" << reg.rcx << "\t" << reg.rbx << "\t" << reg.rax << "\n";
    dbg << "int\terr\n";
    dbg << reg.interruptNumber << "\t" << reg.errorCode << "\n";
    dbg << "rip\tcs\trflags\trsp\tss\n";
    dbg << reg.rip << "\t" << reg.cs << "\t" << reg.rflags << "\t" << reg.rsp << "\t" << reg.ss << "\n";
    dbg << "\n";
    return dbg;
};

#endif

#ifdef __cplusplus
extern "C" {

void ISRHandler(Registers registers);
#else
void ISRHandler(struct Registers registers);

#endif

void loadIDT();

#ifdef __cplusplus
}
#endif

