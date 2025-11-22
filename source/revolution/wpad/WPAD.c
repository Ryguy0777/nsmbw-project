// WPAD.c
// NSMBW .text: 0x801DDC90 - 0x801E55A0

#include <revolution/wpad.h>

EXTERN_C_START

[[address(0x801DFC40)]]
WPADClearDeviceCallback WPADSetClearDeviceCallback(WPADClearDeviceCallback pCallback);

[[address(0x801DFD10)]]
BOOL WPADSetAcceptConnection(BOOL accept);

[[address(0x801E0F80)]]
void WPADDisconnect(WPADChannel chan);

[[address(0x801E1080)]]
WPADResult WPADProbe(WPADChannel chan, u32* pDevType);

[[address(0x801E1620)]]
void WPADControlMotor(WPADChannel chan, WPADMotorCommand command);

EXTERN_C_END
