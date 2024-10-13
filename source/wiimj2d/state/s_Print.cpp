// s_Print.cpp
// NSMBW: 0x8015F810 - 0x8015F900

#include <revolution/os/OSError.h>

// Unknown 0x8015F810

// Unknown 0x8015F820

// Override of the weak symbol from OSError.c
EXTERN_TEXT(
  0x8015F870, //
  void OSReport(const char* format, ...)
);

// Override of the weak symbol from OSError.c
EXTERN_TEXT(
  0x8015F880, //
  void OSVReport(const char* format, va_list args)
);