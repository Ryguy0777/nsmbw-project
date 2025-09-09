// file_io.c
// NSMBW .text: 0x802DEC0C - 0x802DEDFC

#include "stdio.h"

extern "C" {

[[address(0x802DECC8)]]
int fflush(FILE* file);

} // extern "C"