// NANDOpenClose.c
// NSMBW .text: 0x801D95E0 - 0x801DA250

#include "revolution/nand.h"

extern "C" {

[[address(0x801D96F0)]]
NANDResult NANDOpen(const char* path, NANDFileInfo* file, u8 mode);

[[address(0x801D9990)]]
NANDResult NANDClose(NANDFileInfo* file);

} // extern "C"