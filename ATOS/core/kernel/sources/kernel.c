#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif

#include <stddef.h>
#include <stdint.h>
 
#include "multiboot.h"
#include "memtest.h"
#include "memset.h"
#include "vga.h"
#include "interupt.h"
#include "vendorid.h"
#include "crash.h"


void kernel_main(multiboot_info_t* mbd, unsigned int magic) {
	
	/* Initialize terminal interface */
	
	char vendorID[4];

	terminal_initialize();

	memset(vendorID, 0, 4);
	if (vendorid(vendorID) == 0)
		terminal_printf("CPU ID : %s\n\n", vendorID);

	if (memtest(mbd, magic))
		return;

	if (initinterupts())
		return;

	BUG_ON
}