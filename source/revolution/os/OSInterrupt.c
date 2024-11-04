// OSInterrupt.c
// NSMBW: 0x801B1280 - 0x801B1A50

#include "OSInterrupt.h"

extern "C" {

[[address(0x801B1280)]]
bool OSDisableInterrupts();

[[address(0x801B12A0)]]
bool OSEnableInterrupts();

[[address(0x801B12C0)]]
bool OSRestoreInterrupts(bool status);

} // extern "C"