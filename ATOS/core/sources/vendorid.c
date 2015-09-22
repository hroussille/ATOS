#include <cpuid.h>


int vendorid(char * buffer)
{
	int value;

	unsigned int eax;
	unsigned int ebx;
	unsigned int ecx;
	unsigned int edx;

	value = __get_cpuid(0, 	&eax,
							&ebx,
							&ecx,
							&edx);
	if (value == 0)
		return (1);

	((unsigned int *) buffer)[0] = ebx;
	((unsigned int *) buffer)[1] = edx;
	((unsigned int *) buffer)[2] = ecx;

	return (0);
}