// file_io.c
// NSMBW .text: 0x802DEC0C - 0x802DEDFC

#include "stdio.h"

EXTERN_C_START

[[nsmbw(0x802DECC8)]]
int fflush(FILE* file);

EXTERN_C_END
