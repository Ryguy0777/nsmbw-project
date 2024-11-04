// OSTime.c
// NSMBW: 0x801B60C0 - 0x801B64F0

#include "OSTime.h"

extern "C" {

[[address(0x801B60C0)]]
OSTime OSGetTime();

[[address(0x801B60E0)]]
OSTick OSGetTick();

// UNUSED: __SetTime
// UNUSED: __OSSetTime

EXTERN_SYMBOL(0x801B60F0, "__OSGetSystemTime");

EXTERN_SYMBOL(0x801B6160, "__OSTimeToSystemTime");

// UNUSED: __OSSetTick

EXTERN_SYMBOL(0x801B61C0, "OSTicksToCalendarTime");

// UNUSED: OSCalendarTimeToTicks

} // extern "C"