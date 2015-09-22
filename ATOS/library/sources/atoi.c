#include <stdint.h>
#include "atoi.h"
#include "strlen.h"

int atoi(const char * str) 
{
	uint32_t lenght = strlen(str);
	uint32_t value = 0;
	uint32_t index;
	uint32_t power = 1;

	for (index = lenght; index > 0; --index) 
	{
		value = value + (str[index - 1] - 48) * power;
		power = power * 10;
	}
	return value;
}