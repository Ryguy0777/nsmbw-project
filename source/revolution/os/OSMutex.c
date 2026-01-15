// OSMutex.c
// NSMBW .text: 0x801B2F60 - 0x801B3380

#include "OSMutex.h"

EXTERN_C_START

[[nsmbw(0x801B2F60)]]
void OSInitMutex(OSMutex* mutex);

[[nsmbw(0x801B2FA0)]]
void OSLockMutex(OSMutex* mutex);

[[nsmbw(0x801B3080)]]
void OSUnlockMutex(OSMutex* mutex);

[[nsmbw(0x801B3150)]]
void __OSUnlockAllMutex(OSThread* thread);

[[nsmbw(0x801B31C0)]]
BOOL OSTryLockMutex(OSMutex* mutex);

[[nsmbw(0x801B3370)]]
void OSSignalCond(OSThreadQueue* queue);

EXTERN_C_END
