#pragma once

extern "C" {

/* 0x801B1280 */
bool OSDisableInterrupts();

/* 0x801B12A0 */
bool OSEnableInterrupts();

/* 0x801B12C0 */
bool OSRestoreInterrupts(bool status);

} // extern "C"