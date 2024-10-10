#pragma once

#include <stddef.h>

extern "C" {

//
// runtime/__mem.c
//

/* 0x80004364 */
void* memcpy(void* restrict dest, const void* restrict src, size_t n);

/* 0x800046B4 */
void* memset(void* s, int c, size_t n);

/* 0x800046B4 */
size_t strlen(const char* s);

//
// mem.c
//

/* 0x802DF264 */
void* memmove(void* dest, const void* src, size_t n);

/* 0x802DF330 */
void* memchr(const void* s, int c, size_t n);

/* 0x802DF35C */
void* __memrchr(const void* s, int c, size_t n);
void* memrchr(const void* s, int c, size_t n) asm("__memrchr");

/* 0x802DF388 */
int memcmp(const void* s1, const void* s2, size_t n);

//
// string.c
//

/* 0x802E1C28 */
char* strcpy(char* restrict dst, const char* restrict src);

/* 0x802E1CE8 */
char* strncpy(char* dst, const char* src, size_t n);

/* 0x802E1D2C */
char* strcat(char* restrict dst, const char* restrict src);

/* 0x802E1D58 */
char* strncat(char* restrict dst, const char* restrict src, size_t n);

/* 0x802E1DA4 */
int strcmp(const char* s1, const char* s2);

/* 0x802E1EC0 */
int strncmp(const char* s1, const char* s2, size_t n);

/* 0x802E1F00 */
char* strchr(const char* s, int c);

/* 0x802E1F30 */
char* strrchr(const char* s, int c);

/* 0x802E1F78 */
char* strstr(const char* haystack, const char* needle);


} // extern "C"