#pragma once

#include <dynamic/d_a_lift_remocon_main.h>
#include <dynamic/d_a_player_manager.h>
#include <dynamic/d_actor.h>

class daNiceBoat_c : public daLiftRemoconMain_c
{
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x80871440 */
    int calcPlayerOnRide();

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x454, 0xE0A);

    /* 0xE0A */ u8 mPlayerRideStatus_Removed[4];

    FILL(0xE0E, 0xE18);
    OFFSET_ASSERT(0xE18);

#define OFFSET_mPlayerRideStatus 0xE18
    /* 0xE18 */ u8 mPlayerRideStatus[PLAYER_COUNT];
};