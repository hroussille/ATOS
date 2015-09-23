#ifndef INTERUPT_H
#define INTERUPT_H

// RESTORE INTERUPT FLAG

#define ENABLE_IRQ	{ __asm__ __volatile__ ("sti"); } 

// DISABLE INTERUPT FLAG

#define DISABLE_IRQ	{ __asm__ __volatile__ ("cli"); }



unsigned int initinterupts();

#endif // INTERUPT
