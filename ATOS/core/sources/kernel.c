#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif
#include <stddef.h>
#include <stdint.h>
 
#include "vga.h"

void kernel_main() {
	
	/* Initialize terminal interface */
	
	terminal_initialize();

	while (1)
	{
		terminal_writestring("Atos is alive !\n");
		terminal_writestring("Atos can write a new line !\n");
	}
	
}