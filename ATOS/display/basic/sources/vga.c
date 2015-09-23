#include "vga.h"
#include "strlen.h"
#include "bootmessages.h"

#include "memcpy.h"
#include "memset.h"
#include "io.h"

#include <stdarg.h>

#define HEXA_MIN "0123456789abcdef"
#define HEXA_CAP "0123456789ABCDEF"

uint8_t make_color(enum vga_color fg, enum vga_color bg) {
	return fg | bg << 4;
}
 
uint16_t make_vgaentry(char c, uint8_t color) {
	uint16_t c16 = c;
	uint16_t color16 = color;
	return c16 | color16 << 8;
}

void terminal_move_cursor()
{
     unsigned temp;

    temp = terminal_row * 80 + terminal_column;

    outportb(0x3D4, 14);
    outportb(0x3D5, temp >> 8);
    outportb(0x3D4, 15);
    outportb(0x3D5, temp);
}

void terminal_scroll()
{
  unsigned blank, temp;

    blank = make_color(COLOR_BLACK, COLOR_BLACK);

    if(terminal_row >= VGA_HEIGHT)
    {
        temp = terminal_row - 25 + 1;
        memcpy (VGA_BASE_ADDR, VGA_BASE_ADDR + temp * 80, (25 - temp) * 80 * 2);
        memset (VGA_BASE_ADDR + (25 - temp) * 80, blank , 80);
        terminal_row = VGA_HEIGHT - 1;
    }
}

void terminal_initialize() {
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = make_color(COLOR_LIGHT_GREY, COLOR_BLACK);
	terminal_buffer = (uint16_t*) 0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = make_vgaentry(' ', terminal_color);
		}
	}
}
 
void terminal_setcolor(uint8_t color) {
	terminal_color = color;
}
 
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = make_vgaentry(c, color);
  terminal_move_cursor();
}
 
void terminal_putchar(char c) {

	if (c == '\n')
	{
		terminal_row = terminal_row + 1;
		if (terminal_row >= VGA_HEIGHT)
			{
        terminal_scroll();
        terminal_row--;
      }
		terminal_column    = 0;
    terminal_move_cursor();
		return;
	}
	
	terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
	if (++terminal_column >= VGA_WIDTH) {
		terminal_column = 0;
		if (++terminal_row >= VGA_HEIGHT) {
			terminal_row = 0;
		}
	}
}
 
void terminal_writestring(char* data) {
	size_t datalen = strlen(data);
	for (size_t i = 0; i < datalen; i++)
		terminal_putchar(data[i]);
}
 
void terminal_putnbr(int n)
{
  if (n >= 10)
    {
      terminal_putnbr(n / 10);
      terminal_putnbr(n % 10);
    }
  else
    terminal_putchar(48 + n);
}

void    terminal_putnbr_base(int nb, char *base)
{
  int   result;
  int   diviseur;
  int   size_base;


  size_base = strlen(base);
  if (nb < 0)
    {
      terminal_putchar('-');
      nb = -nb;
    }
  diviseur = 1;
  while ((nb / diviseur) >= size_base)
    diviseur = diviseur * size_base;
  while (diviseur > 0)
    {
      result = (nb /diviseur) % size_base;
      terminal_putchar(base[result]);
      diviseur = diviseur / size_base;
    }
}

void 	terminal_printf(char * fmt, ...)
{
   va_list ap;
   int i;

   va_start(ap, fmt);
   i = 0;

   while (fmt[i] != '\0')
   {
   	if (fmt[i] == '%')
        {
          if (fmt[i + 1] == 's')
            terminal_writestring(va_arg(ap, char *));
          else if (fmt[i + 1] == 'd' || fmt[i + 1] == 'i')
            terminal_putnbr(va_arg(ap, int));
          else if (fmt[i + 1] == 'c')
            terminal_putchar((char)va_arg(ap, int));
          else if (fmt[i + 1] == 'x' || fmt[i + 1] == 'X')
            terminal_putnbr_base(va_arg(ap, unsigned int), (fmt[i + 1] == 'x' ? HEXA_MIN : HEXA_CAP));
          else
            terminal_putchar(fmt[i + 1]);
          i++;
        }
      else
        terminal_putchar(fmt[i]);
      i++;
    }
   va_end(ap);
}

void vgatestko()
{
	terminal_setcolor(make_color(COLOR_RED, COLOR_BLACK));		
	terminal_writestring(" [KO] \n");
	terminal_printf(CRITICAL);
	terminal_setcolor(make_color(COLOR_LIGHT_GREY, COLOR_BLACK));
}

void vgatestok()
{
	terminal_setcolor(make_color(COLOR_GREEN,COLOR_BLACK));
	terminal_writestring(" [OK] \n");
	terminal_setcolor(make_color(COLOR_LIGHT_GREY, COLOR_BLACK));

}