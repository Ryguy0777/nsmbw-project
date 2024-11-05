// s_StateMethod.cpp
// NSMBW: 0x8015FAE0 - 0x8015FDD0

#include "s_StateMethod.h"

/**
 * VT+0x18
 * Transitions to a new state ID.
 * @param newStateID The new state ID to transition to.
 */
[[address(0x8015FD50)]]
void sStateMethod_c::changeStateMethod(const sStateIDIf_c& newStateID);