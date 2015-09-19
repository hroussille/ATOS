#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif
#include <stddef.h>
#include <stdint.h>
 
#include "vga.h"

void kernel_main() {
	
	/* Initialize terminal interface */
	
	terminal_initialize();
	terminal_writestring("Atos is alive !");
	
	while (1);
}