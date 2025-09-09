// fs.c
// NSMBW .text: 0x802265D0 = 0x80227CB0

#include "revolution/fs.h"

extern "C" {

[[address(0x80227180)]]
s32 ISFS_Rename(const char* oldPath, const char* newPath);

} // extern "C"