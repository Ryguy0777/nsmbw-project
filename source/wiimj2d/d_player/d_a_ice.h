#pragma once

#include "d_system/d_actor.h"

class daIce_c : public dActor_c
{
public:
    // -------------------
    // Constants and Types
    // -------------------

    static constexpr fBaseProfile_e EXPECTED_PROFILES[] = {
      fBaseProfile_e::ICE_ACTOR,
    };

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x8011EFC0 */
    bool checkPlAttach_Head(int*);
};
