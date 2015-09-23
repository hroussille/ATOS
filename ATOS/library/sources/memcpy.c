#include "memcpy.h"

void * memcpy(void * dest, const void * src, size_t count) 
{
        char* dst8 = (char*)dest;
        char* src8 = (char*)src;
        
        if (count & 1) {
            dst8[0] = src8[0];
            dst8 += 1;
            src8 += 1;
        }
        
        count /= 2;
        while (count--) {
            dst8[0] = src8[0];
            dst8[1] = src8[1];
        
            dst8 += 2;
            src8 += 2;
        }
        return dest;
    }
