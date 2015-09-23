#include "idt.h"
#include "memset.h"

#include <stdint.h>

/* Use this function to set an entry in the IDT. Alot simpler
*  than twiddling with the GDT ;) */

void idt_set_gate(unsigned char num, 
                  unsigned long base, 
                  unsigned short selector,
                  unsigned char flags)
{
    idt[num].flags = flags | 0x60;
    idt[num].zero = 0;
    idt[num].selector = selector;
    idt[num].offset_low  = ((uintptr_t) base & 0xFFFF);
    idt[num].offset_high = ((uintptr_t) base >> 16) & 0xFFFF;
}

/* Installs the IDT */
void idt_install()
{
    
    idtp.limit = (sizeof (struct idt_entry) * 256) - 1;
    idtp.base = (uintptr_t) &idt;

    /* Clear out the entire IDT, initializing it to zeros */
    memset(&idt, 0, sizeof(struct idt_entry) * 256);

    /* Add any new ISRs to the IDT here using idt_set_gate */

    /* Points the processor's internal register to the new IDT */

    idt_load();
}
		