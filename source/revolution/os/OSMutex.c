// OSMutex.c
// NSMBW .text: 0x801B2F60 - 0x801B3380

#include "OSMutex.h"

extern "C" {

[[address(0x801B2F60)]]
void OSInitMutex(OSMutex* mutex);

[[address(0x801B2FA0)]]
void OSLockMutex(OSMutex* mutex);

[[address(0x801B3080)]]
void OSUnlockMutex(OSMutex* mutex);

[[address(0x801B3150)]]
void __OSUnlockAllMutex(OSThread* thread);

[[address(0x801B31C0)]]
BOOL OSTryLockMutex(OSMutex* mutex);

[[address(0x801B3370)]]
void OSSignalCond(OSThreadQueue* queue);

} // extern "C"