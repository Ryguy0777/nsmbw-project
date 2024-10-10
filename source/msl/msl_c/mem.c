// mem.c
// NSMBW: 0x802DF264 - 0x802DF3D4

#include <string.h>

EXTERN_TEXT(
  0x802DF264, //
  void* memmove(void* dest, const void* src, size_t n)
);

EXTERN_TEXT(
  0x802DF330, //
  void* memchr(const void* s, int c, size_t n)
);

EXTERN_TEXT(
  0x802DF35C, //
  void* __memrchr(const void* s, int c, size_t n)
);

EXTERN_TEXT(
  0x802DF388, //
  int memcmp(const void* s1, const void* s2, size_t n)
);