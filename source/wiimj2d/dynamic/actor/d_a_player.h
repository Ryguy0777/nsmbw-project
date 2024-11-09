#pragma once

#include "d_a_player_base.h"
#include "d_a_player_manager.h"

class dAcPy_c : public daPlBase_c
{
public:
    // ---------
    // Functions
    // ---------

    /* 0x80138FA0 */
    bool setBalloonInDamage();

    /* 0x8013D7B0 */
    void checkRest();

    /* 0x8013DA30 */
    void stopOtherDownDemo();

    /**
     * 0x801400B0
     * Actually a virtual function
     */
    void executeDemoGoal_Run();

public:
    // -----------
    // Member Data
    // -----------

    /* 0x14D4 */ daPyMng_c::PlayerType_e mPlayerType;

    FILL(0x14D8, 0x153C);

    /* 0x153C */ u8 mScrollType;

    FILL(0x153D, 0x1554);

    /* 0x1554 */ int m0x1554;
};