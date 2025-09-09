#pragma once

extern "C" {

[[noreturn]]
void OSPanic(const char* file, int line, const char* format, ...);

#ifdef NDEBUG
#  define assert(cond) ((void) 0)
#else
#  define assert(cond) ((cond) || (OSPanic(__FILE__, __LINE__, "Failed assertion " #cond), 0))
#endif
}