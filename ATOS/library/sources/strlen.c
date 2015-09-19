#include "strlen.h"

size_t strlen(char *str)
{
	size_t lenght;

	lenght = 0;

	while (str[lenght])
		{
			lenght++;
		}
		
	return (lenght);
}