#pragma once

#include <dynamic/d_a_player_manager.h>
#include <dynamic/d_base.h>
#include <dynamic/d_lytbase.h>
#include <state/s_FStateFct.h>
#include <state/s_StateMethodUsr_FI.h>
#include <state/s_StateMgr.h>

class da2DPlayer_c;
class daWmItem_c;

class dStockItem_c : public dBase_c
{
public:
    // ------------
    // Constructors
    // ------------

    /* 0x807AF3A0 */
    dStockItem_c();

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x807B00A0 */
    void calc2DPlayerItemUpdate();

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x070, 0x074);

    /* 0x074 */ LytBase_c mLayout;
    /* 0x20C */
    sStateMgr_c<dStockItem_c, sStateMethodUsr_FI_c, sFStateFct_c, sStateIDChk_c> mStateMgr;

    FILL(0x248, 0x2E4);

    /* 0x2E4 */ da2DPlayer_c* mpa2DPlayer_Removed[4];
    /* 0x2F4 */ daWmItem_c* mpItem[7];

    FILL(0x310, 0x8DD);

    /* 0x8DD */ u8 m0x8DD;

    FILL(0x8DE, 0x8E0);
    OFFSET_ASSERT(0x8E0);

#define dStockItem_c_OFFSET_mpa2DPlayer 0x8E0
    /* 0x8E0 */ da2DPlayer_c* mpa2DPlayer[PLAYER_COUNT];
};