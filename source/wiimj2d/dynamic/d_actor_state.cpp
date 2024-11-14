// d_actor_state.cpp
// NSMBW: 0x80066FB0 - 0x80068040

#include "d_actor_state.h"

/* VT+0xD4 */
[[address(0x80067230)]]
void dActorState_c::initializeState_Gegneric();

/* VT+0xD8 */
[[address(0x80067250)]]
void dActorState_c::executeState_Gegneric();

/* VT+0xDC */
[[address(0x80067240)]]
void dActorState_c::finalizeState_Gegneric();

/* VT+0xD4 */
[[address(0x800675C0)]]
void dActorMultiState_c::changeState(const sStateIDIf_c& state);

/* VT+0xD8 */
[[address(0x80067590)]]
void dActorMultiState_c::initializeState_GegnericMulti();

/* VT+0xDC */
[[address(0x800675B0)]]
void dActorMultiState_c::executeState_GegnericMulti();

/* VT+0xE0 */
[[address(0x800675A0)]]
void dActorMultiState_c::finalizeState_GegnericMulti();