#ifndef MEMTEST_H
#define MEMTEST_H

#include "multiboot.h"

unsigned int memtest(multiboot_info_t* mbd, unsigned int magic);


#endif // MEMTEST_H
