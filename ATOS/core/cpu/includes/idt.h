#ifndef IDT_H
#define IDT_H

#include <stdint.h>

/* Defines an IDT entry */

struct idt_entry
{
   uint16_t offset_low; // offset bits 0..15
   uint16_t selector; // a code segment selector in GDT or LDT
   uint8_t  zero;      // unused, set to 0
   uint8_t  flags; // type and attributes, see below
   uint16_t offset_high; // offset bits 16..31
} __attribute__((packed));

struct idt_ptr
{
    unsigned short limit;
    uintptr_t	   base;
} __attribute__((packed));

/* Declare an IDT of 256 entries. Although we will only use the
*  first 32 entries in this tutorial, the rest exists as a bit
*  of a trap. If any undefined IDT entry is hit, it normally
*  will cause an "Unhandled Interrupt" exception. Any descriptor
*  for which the 'presence' bit is cleared (0) will generate an
*  "Unhandled Interrupt" exception */

struct idt_entry idt[256];
struct idt_ptr idtp;

/* This exists in the assembly folder, and is used to load our IDT */

extern void idt_load();

void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);
void idt_install();

#endif // IDT_H
