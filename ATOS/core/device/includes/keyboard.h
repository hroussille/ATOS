#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "isrs.h"

extern unsigned char kbdus[128];

void keyboard_handler(struct regs *r);

#endif // KEYBOARD_H