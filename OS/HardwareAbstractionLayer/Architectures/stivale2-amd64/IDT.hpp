#pragma once

#include <stdint.h>

struct Registers
{
    uint64_t r15, r14, r13, r12, r11, r10, r9, r8, rbp, rrsp, rsi, rdi, rdx, rcx, rbx, rax;
    uint64_t interruptNumber, errorCode;
    uint64_t rip, cs, rflags, rsp, ss;
} __attribute__((packed));

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

