#ifndef TSS_H
#define TSS_H

#include <stdint.h>

/*
	The Task State Segment (TSS) is a special data structure for x86 processors.
	Which holds information about a task. The TSS is primarily suited for hardware 
	multitasking, where each individual process has its own TSS. In Software multitasking,
	one or two TSS's are also generally used.
	As they allow for entering ring0 code after an interrupt.
*/
	
typedef struct tss_t 
{
	uint32_t	prev_tss;
	uint32_t	esp0;
	uint32_t	ss0;
	uint32_t	esp1;
	uint32_t	ss1;
	uint32_t	esp2;
	uint32_t	ss2;
	uint32_t	cr3;
	uint32_t	eip;
	uint32_t	eflags;
	uint32_t	eax;
	uint32_t	ecx;
	uint32_t	edx;
	uint32_t	ebx;
	uint32_t	esp;
	uint32_t	ebp;
	uint32_t	esi;
	uint32_t	edi;
	uint32_t	es;
	uint32_t	cs;
	uint32_t	ss;
	uint32_t	ds;
	uint32_t	fs;
	uint32_t	gs;
	uint32_t	ldt;
	uint16_t	trap;
	uint16_t	iomap_base;

} __attribute__ ((packed)) tss_entry_t;

void write_tss(int32_t num, uint16_t ss0, uint32_t esp0);
extern void tss_flush();

#endif // TSS_H
