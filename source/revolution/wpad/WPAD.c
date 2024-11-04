// WPAD.c
// NSMBW: 0x801DDC90 - 0x801E55A0

#include <revolution/wpad.h>

extern "C" {

[[address(0x801E1080)]]
WPADResult WPADProbe(WPADChannel chan, WPADDeviceType* devTypeOut);

} // extern "C"