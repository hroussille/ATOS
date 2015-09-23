#include "vga.h"
#include "bootmessages.h"
#include "interupt.h"

unsigned int initinterupts()
{
	terminal_writestring(INIT_INTERUPTS);
	vgatestko();
	return (0);
}