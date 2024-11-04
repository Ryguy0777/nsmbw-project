#pragma once

extern "C" {

typedef s64 OSTime;
typedef s32 OSTick;

/* 0x801B60C0 */
OSTime OSGetTime();

/* 0x801B60E0 */
OSTick OSGetTick();

} // extern "C"