#include <stddef.h>
#include <stdint.h>

#include "IDT.hpp"

#include "Debug.hpp"

using uint = unsigned int;

using ISRHandlerPtr = void(*)();

struct IDTPointer
{
    volatile uint16_t limit;
    volatile uint64_t base;
} __attribute__((packed));

struct IDTEntry
{
    uint16_t offset_low16;
    uint16_t cs;
    uint8_t ist;
    struct {
        uint gate : 4;
        uint zero : 1;
        uint ring_level : 2;
        uint present : 1;
    } __attribute__((packed)) attributes;
    uint16_t offset_mid16;
    uint32_t offset_high32;
    uint32_t zero;

    IDTEntry(ISRHandlerPtr f = nullptr)
        : offset_low16(uint16_t(uint64_t(f)))
        , cs(f != nullptr ? 0x08 : 0)
        , ist(0)
        , attributes({0b1110, 0, 0x0, f != nullptr})
        , offset_mid16(uint16_t(uint64_t(f) >> 16))
        , offset_high32(uint32_t(uint64_t(f) >> 32))
        , zero(0x0)
    {
    }
} __attribute__((packed));

extern "C" {

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();

}

IDTEntry entries[32];

void loadIDT() {
    entries[0] = IDTEntry(isr0);
    entries[1] = IDTEntry(isr1);
    entries[2] = IDTEntry(isr2);
    entries[3] = IDTEntry(isr3);
    entries[4] = IDTEntry(isr4);
    entries[5] = IDTEntry(isr5);
    entries[6] = IDTEntry(isr6);
    entries[7] = IDTEntry(isr7);
    entries[8] = IDTEntry(isr8);
    entries[9] = IDTEntry(isr9);
    entries[10] = IDTEntry(isr10);
    entries[11] = IDTEntry(isr11);
    entries[12] = IDTEntry(isr12);
    entries[13] = IDTEntry(isr13);
    entries[14] = IDTEntry(isr14);
    entries[15] = IDTEntry(isr15);
    entries[16] = IDTEntry(isr16);
    entries[17] = IDTEntry(isr17);
    entries[18] = IDTEntry(isr18);
    entries[19] = IDTEntry(isr19);
    entries[20] = IDTEntry(isr20);
    entries[21] = IDTEntry(isr21);
    entries[22] = IDTEntry(isr22);
    entries[23] = IDTEntry(isr23);
    entries[24] = IDTEntry(isr24);
    entries[25] = IDTEntry(isr25);
    entries[26] = IDTEntry(isr26);
    entries[27] = IDTEntry(isr27);
    entries[28] = IDTEntry(isr28);
    entries[29] = IDTEntry(isr29);
    entries[30] = IDTEntry(isr30);
    entries[31] = IDTEntry(isr31);

    IDTPointer ptr;
    ptr.base = (uint64_t)(void*)entries;
    ptr.limit = sizeof(entries) - 1;

    asm volatile("lidt %[idt]": [idt]"=m"(ptr));
}

[[clang::optnone]] void ISRHandlerImpl(Registers& registers)
{
    // HAL::Debug dbg;

    // dbg << registers;
}

void ISRHandler(Registers registers)
{
    ISRHandlerImpl(registers);
}
