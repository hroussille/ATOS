#include "memtest.h"
#include "bitwise.h"
#include "vga.h"
#include "bootmessages.h"



unsigned int memtest(multiboot_info_t* mbd, unsigned int magic)
{

	magic = (int) magic;

	terminal_writestring(MULTIBOOT_TEST);

	if (CHECK_BIT(mbd->flags, 0))
	{
		vgatestok();
		terminal_writestring(MEMORY_MAP_TEST);
		
		if (CHECK_BIT(mbd->flags, 6))
		{
			vgatestok();
			terminal_printf("\nLower memory : %d KB\n", mbd->mem_lower);
			terminal_printf("Upper memory : %d KB\n\n", mbd->mem_upper);
		}

		else
		{
			vgatestko();
			return (1);
		}

		return (0);
	}

	vgatestko();
	return (1);
}
