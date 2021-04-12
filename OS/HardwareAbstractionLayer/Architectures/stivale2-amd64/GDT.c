#include <stddef.h>
#include <stdint.h>

#include "IDT.hpp"

#define GDT_ENTRIES      5

#define GDT_FLAG_DATASEG 0x02
#define GDT_FLAG_CODESEG 0x0a
#define GDT_FLAG_TSS     0x09

#define GDT_FLAG_SEGMENT 0x10
#define GDT_FLAG_RING0   0x00
#define GDT_FLAG_RING3   0x60
#define GDT_FLAG_PRESENT 0x80

#define GDT_FLAG_4K_GRAN 0x800
#define GDT_FLAG_32_BIT  0x400

static inline void outb(uint16_t port, uint8_t data)
{
    asm volatile ("outb %0, %1" : : "a" (data), "Nd" (port));
}

struct gdt_entry {
    uint16_t limit;
    uint16_t base_low;
    uint8_t base_mid;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __attribute__((packed));

static struct gdt_entry gdt[GDT_ENTRIES] = {
    // null entry
    {0, 0, 0, 0, 0, 0},
    // kernel code
    {0, 0, 0, 0b10011010, 0b00100000, 0},
    // kernel data
    {0, 0, 0, 0b10010010, 0, 0},
    // user data
    {0, 0, 0, 0b11110010, 0, 0},
    // user code
    {0, 0, 0, 0b11111010, 0b00100000, 0},
};

struct {
    uint16_t limit;
    void* pointer;
} __attribute__((packed)) gdtp = {
    .limit = GDT_ENTRIES * 8 - 1,
    .pointer = gdt,
};

void load_gdt(void)
{
    asm volatile("lgdt %0" : : "m" (gdtp));
}

extern void reloadSegments(void);

void init_gdt(void)
{
    load_gdt();
    reloadSegments();
    loadIDT();
    asm volatile ("cli");
}

void init_pic(void)
{
    // Master-PIC initialisieren
    outb(0x20, 0x11); // Initialisierungsbefehl fuer den PIC
    outb(0x21, 0x20); // Interruptnummer fuer IRQ 0
    outb(0x21, 0x04); // An IRQ 2 haengt der Slave
    outb(0x21, 0x01); // ICW 4

    // Slave-PIC initialisieren
    outb(0xa0, 0x11); // Initialisierungsbefehl fuer den PIC
    outb(0xa1, 0x28); // Interruptnummer fuer IRQ 8
    outb(0xa1, 0x02); // An IRQ 2 haengt der Slave
    outb(0xa1, 0x01); // ICW 4

    // Alle IRQs aktivieren (demaskieren)
    outb(0x21, 0x0);
    outb(0xa1, 0x0);
}