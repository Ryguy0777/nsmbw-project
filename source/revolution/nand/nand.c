// nand.c
// NSMBW .text: 0x801D8620 - 0x801D95E0

#include "revolution/nand.h"

extern "C" {

[[address(0x801D8620)]]
NANDResult NANDCreate(const char* path, u8 perm, u8 attr);

[[address(0x801D8920)]]
NANDResult NANDDelete(const char* path);

[[address(0x801D8B30)]]
NANDResult NANDRead(NANDFileInfo* file, void* data, u32 len);

[[address(0x801D8C20)]]
NANDResult NANDWrite(NANDFileInfo* file, const void* data, u32 len);

[[address(0x801D9110)]]
NANDResult NANDMove(const char* from, const char* to);

} // extern "C"