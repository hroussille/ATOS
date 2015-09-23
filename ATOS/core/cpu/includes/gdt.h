#ifndef GDT_H
#define GDT_H

#include "tss.h"
#include <stdint.h>

#define GDT_ENTRY_NUMBER 6

/* Defines a GDT entry. We say packed, because it prevents the
*  compiler from doing things that it thinks is best: Prevent
*  compiler "optimization" by packing */

struct gdt_entry
{
    unsigned short limit_low;
    unsigned short base_low;
    unsigned char base_middle;
    unsigned char access;
    unsigned char granularity;
    unsigned char base_high;
} __attribute__((packed));

/* Special pointer which includes the limit: The max bytes
*  taken up by the GDT, minus 1. Again, this NEEDS to be packed */

struct gdt_ptr
{
    unsigned short limit;
    uintptr_t base;
} __attribute__((packed));

/* Our GDT, with 6 entries, and finally our special GDT pointer */

/* Currently 6 entries :
   
  	- NULL descriptor
  	- kernel code descriptor
  	- kernel data descriptor
  	- user code descriptor 
  	- user data descriptor
  	- TSS  descriptor
*/

struct gdt_entry gdt[6];
struct gdt_ptr gp;
tss_entry_t tss_entry;

/* This will be a function in assembly folder. We use this to properly
*  reload the new segment registers */

extern void gdt_flush();

void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);
void gdt_install();

#endif // GDT_H
