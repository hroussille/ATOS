#include "vga.h"
#include "bootmessages.h"
#include "tss.h"
#include "gdt.h"
#include "idt.h"
#include "isrs.h"
#include "irq.h"

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



	return (0);
}