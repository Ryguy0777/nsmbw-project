// OSFatal.c
// NSMBW: 0x801AF2C0 - 0x801AFEF0

#include <revolution/os.h>

extern "C" {

// 0x801AF2C0: ScreenReport

// 0x801AF5F0: ConfigureVideo

EXTERN_TEXT(
  0x801AF710, //
  void OSFatal(GXColor textColor, GXColor bgColor, const char* text)
);

// 0x801AF900: 0 Halt

} // extern "C"