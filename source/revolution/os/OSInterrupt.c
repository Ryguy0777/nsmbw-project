// OSInterrupt.c
// NSMBW .text: 0x801B1280 - 0x801B1A50

#include "OSInterrupt.h"

EXTERN_C_START

[[nsmbw(0x801B1280)]]
bool OSDisableInterrupts();

[[nsmbw(0x801B12A0)]]
bool OSEnableInterrupts();

[[nsmbw(0x801B12C0)]]
bool OSRestoreInterrupts(bool status);

EXTERN_C_END
