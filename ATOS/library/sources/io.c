#include "io.h"


unsigned char inportb(unsigned short port) 
{
	unsigned char value;
	asm volatile ("inb %1, %0" : "=a" (value) : "dN" (port));
	return value;
}

unsigned short inports(unsigned short port) 
{
	unsigned short value;
	asm volatile ("inw %1, %0" : "=a" (value) : "dN" (port));
	return value;
}
unsigned int inportl(unsigned short port) 

{
	unsigned int value;
	asm volatile ("inl %%dx, %%eax" : "=a" (value) : "dN" (port));
	return value;
}



void outportb(unsigned short port, unsigned char data) 
{
	__asm__ __volatile__ ("outb %1, %0" : : "dN" (port), "a" (data));
}

void outports(unsigned short port, unsigned short data) 
{
	asm volatile ("outw %1, %0" : : "dN" (port), "a" (data));
}

void outportl(unsigned short port, unsigned int data) 
{
	asm volatile ("outl %%eax, %%dx" : : "dN" (port), "a" (data));
}