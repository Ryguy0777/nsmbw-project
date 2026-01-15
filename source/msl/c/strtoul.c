// strtoul.c
// NSMBW .text: 0x802E1FE4 - 0x802E24BC

#include "msl/c/stdlib.h"

[[address(0x802E1FE4)]]
unsigned long __strtoul(int, int, int (*)(void*, int, int), void*, int*, int*, int*);

[[address(0x802E23F8)]]
int atoi(const char* s);