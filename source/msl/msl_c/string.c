// string.c
// NSMBW .text: 0x802E1C28 - 0x802E4FC8

#include "string.h"

extern "C" {

[[address(0x802E1C28)]]
char* strcpy(char* restrict dst, const char* restrict src);

[[address(0x802E1CE8)]]
char* strncpy(char* dst, const char* src, size_t n);

[[address(0x802E1D2C)]]
char* strcat(char* restrict dst, const char* restrict src);

[[address(0x802E1D58)]]
char* strncat(char* restrict dst, const char* restrict src, size_t n);

[[address(0x802E1DA4)]]
int strcmp(const char* s1, const char* s2);

[[address(0x802E1EC0)]]
int strncmp(const char* s1, const char* s2, size_t n);

[[address(0x802E1F00)]]
char* strchr(const char* s, int c);

[[address(0x802E1F30)]]
char* strrchr(const char* s, int c);

[[address(0x802E1F78)]]
char* strstr(const char* haystack, const char* needle);

} // extern "C"