#ifndef PIC_H
#define PIC_H

#include "isrs.h"

#define HZ 100

void timer_phase(int hz);
void timer_handler(struct regs *r);
void timer_install();

#define 	time_after(unknown, known) ((uint32_t)(known) - (uint32_t)(unknown) < 0)
#define 	time_before(unknown, known) ((uint32_t)(unknown) - (uint32_t)(known) < 0)
#define 	time_after_eq(unknown, known) ((uint32_t)(unknown) - (uint32_t)(known) >= 0)
#define 	time_before_eq(unknown, known) ((uint32_t)(known) - (uint32_t)(unknown) >= 0)


#endif // PIC_H
