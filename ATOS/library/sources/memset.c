#include "memset.h"

void * memset(void * dst, int value, size_t lenght)
{
	unsigned char * tmp;

	tmp = dst;

    while(--lenght)
    {
        *tmp++ = (unsigned char) value;
    }

	return (dst);
}