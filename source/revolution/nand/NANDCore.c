// NANDCore.c
// NSMBW .text: 0x801DA250 - 0x801DB280

#include "revolution/nand.h"

EXTERN_C_START

[[nsmbw(0x801DA6B0)]]
NANDResult nandConvertErrorCode(s32 isfsError);

[[nsmbw(0x801DAC30)]]
NANDResult NANDGetHomeDir(char* out);

[[nsmbw(0x801DAFB0)]]
NANDResult NANDGetType(const char* path, u8* type);

EXTERN_C_END
