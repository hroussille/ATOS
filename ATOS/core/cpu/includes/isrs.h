#ifndef ISRS_H
#define ISRS_H

#include <stdint.h>

struct regs
{
	/* pushed the segs last */
    uint32_t gs;
    uint32_t fs;
    uint32_t es;
    uint32_t ds;

    /* pushed by 'pusha' */
    uint32_t edi;
    uint32_t esi;
    uint32_t ebp;
    uint32_t esp;
    uint32_t ebx;
    uint32_t edx;
    uint32_t ecx;
    uint32_t eax;

    /* our 'push byte #' and ecodes do this */
    uint32_t int_no;
    uint32_t err_code;

  	/* pushed by the processor automatically */
    uint32_t eip;
    uint32_t cs;
    uint32_t eflags;
    uint32_t useresp;
    uint32_t ss;  
};

void isrs_install();
void fault_handler(struct regs *r);
void register_trace(struct regs *r);

#endif // ISRS_H
