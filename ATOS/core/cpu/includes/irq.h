#ifndef IRQ_H
#define IRQ_H

#include "isrs.h"

/* These are own ISRs that point to our special IRQ handler
*  instead of the regular 'fault_handler' function */

// RESTORE INTERUPT FLAG

#define ENABLE_IRQ  { __asm__ __volatile__ ("sti"); } 

// DISABLE INTERUPT FLAG

#define DISABLE_IRQ { __asm__ __volatile__ ("cli"); }


extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();


void irq_install_handler(int irq, void (*handler)(struct regs *r));
void irq_uninstall_handler(int irq);
void irq_remap(void);
void irq_install();
void _irq_handler(struct regs *r);

#endif // IRQ_H
