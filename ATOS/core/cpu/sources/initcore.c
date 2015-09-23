#include "vga.h"
#include "bootmessages.h"
#include "tss.h"
#include "gdt.h"
#include "idt.h"
#include "isrs.h"
#include "irq.h"
#include "pic.h"

unsigned int initcore()
{
	/* Set up GDT */
	terminal_writestring(INIT_GDT);
	gdt_install();
	vgatestok();

	/* Set up IDT */
	terminal_writestring(INIT_IDT);
	idt_install();
	vgatestok();

	/* Set up ISRS */
	terminal_writestring(INIT_ISRS);
	isrs_install();
	vgatestok();

	/* Set up IRQS */
	terminal_writestring(INIT_IRQ);
	irq_install();
	ENABLE_IRQ
	vgatestok();

	/* Set up PIC */
	terminal_writestring(INIT_PIC);
	timer_phase(HZ);
	timer_install();
	vgatestok();

	return (0);
}