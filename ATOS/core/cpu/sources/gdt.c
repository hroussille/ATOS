#include "gdt.h"

/* Setup a descriptor in the Global Descriptor Table */
void gdt_set_gate(int num, unsigned long base, 
						   unsigned long limit, 
						   unsigned char access, 
						   unsigned char gran)
{
    /* Setup the descriptor base address */
    gdt[num].base_low = (base & 0xFFFF);
    gdt[num].base_middle = (base >> 16) & 0xFF;
    gdt[num].base_high = (base >> 24) & 0xFF;

    /* Setup the descriptor limits */
    gdt[num].limit_low = (limit & 0xFFFF);
    gdt[num].granularity = ((limit >> 16) & 0x0F);

    /* Finally, set up the granularity and access flags */
    gdt[num].granularity |= (gran & 0xF0);
    gdt[num].access = access;
}

/* Should be called by main. This will setup the special GDT
*  pointer, set up the first 3 entries in our GDT, and then
*  finally call gdt_flush() in our assembler file in order
*  to tell the processor where the new GDT is and update the
*  new segment registers */

void gdt_install()
{
    /* Setup the GDT pointer and limit */
    
    gp.limit = (sizeof(struct gdt_entry) * GDT_ENTRY_NUMBER) - 1;
    gp.base = (uintptr_t) &gdt;

    /* Our NULL descriptor */
    
    gdt_set_gate(0, 0, 0, 0, 0);

    /* The second entry is our Code Segment. The base address
    *  is 0, the limit is 4GBytes, it uses 4KByte granularity,
    *  uses 32-bit opcodes, and is a Code Segment descriptor.
    *  Please check the table above in the tutorial in order
    *  to see exactly what each value means */

    gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);

    /* The third entry is our Data Segment. It's EXACTLY the
    *  same as our code segment, but the descriptor type in
    *  this entry's access byte says it's a Data Segment */
    
    gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);


    /* The fourth entry is the user code. */

    gdt_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);


    /* The fifth entry is the user data */

    gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);

    /* The last one is the TSS */

    write_tss(5, 0x10, 0x0);

    /* Flush out the old GDT and install the new changes! */
    gdt_flush();
    tss_flush();
}