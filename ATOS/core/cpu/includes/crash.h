#ifndef CRASH_H
#define CRASH_H

#define HALT_CPU  	{ __asm__ __volatile__ ("hlt"); }

#define BUG_ON 		while (1);		

#endif // CRASH_H
