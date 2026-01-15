#pragma once

EXTERN_C_START

[[noreturn]]
void OSPanic(const char* file, int line, const char* format, ...);

#ifdef NDEBUG
#  define assert(cond) ((void) 0)
#else
#  define assert(cond) ((cond) || (OSPanic(__FILE_NAME__, __LINE__, "Failed assertion " #cond), 0))
#endif

EXTERN_C_END