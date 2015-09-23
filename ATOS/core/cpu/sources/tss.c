#include "gdt.h"
#include "tss.h"
#include "memset.h"

void write_tss( int32_t num, uint16_t ss0, uint32_t esp0) 
{
	uintptr_t base  = (uintptr_t)&tss_entry;
	uintptr_t limit = base + sizeof(tss_entry);

	/* Add the TSS descriptor to the GDT */
	gdt_set_gate(num, base, limit, 0xE9, 0x00);

	memset(&tss_entry, 0x0, sizeof(tss_entry));

	tss_entry.ss0    = ss0;
	tss_entry.esp0   = esp0;
	/* Zero out the descriptors */
	tss_entry.cs     = 0x0b;
	tss_entry.ss     =
		tss_entry.ds =
		tss_entry.es =
		tss_entry.fs =
		tss_entry.gs = 0x13;
	tss_entry.iomap_base = sizeof(tss_entry);
}