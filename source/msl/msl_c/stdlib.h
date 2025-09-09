#pragma once

#include "msl/msl_c/stddef.h"

extern "C" {

#define abs(x) __builtin_abs(x)
#define labs(x) __builtin_abs(x)

/* 0x802E1FE4 */
unsigned long __strtoul(int, int, int (*)(void*, int, int), void*, int*, int*, int*);

/* 0x802E23F8 */
int atoi(const char* s);

/* 0x802DF0EC */
size_t mbstowcs(wchar_t* dest, const char* src, size_t len);

/* 0x802DDB50 */
void* free(void* ptr);

} // extern "C"