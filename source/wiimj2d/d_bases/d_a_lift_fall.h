#pragma once

#include "d_system/d_actor_state.h"
#include "d_system/d_rc.h"

class daLiftFall_c : public dActorState_c
{
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x808377B0 */
    bool checkRideStart() const;

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x3D0, 0x508);

    /* 0x508 */ dRideRoll_c mRc;
};
