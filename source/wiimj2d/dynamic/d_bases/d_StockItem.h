#pragma once

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
    // -----------
    // Member Data
    // -----------

    FILL(0x070, 0x074);

    /* 0x074 */ LytBase_c mLayout;
    /* 0x20C */
    sStateMgr_c<dStockItem_c, sStateMethodUsr_FI_c, sFStateFct_c, sStateIDChk_c> mStateMgr;

    FILL(0x248, 0x2E4);

    /* 0x2E4 */ da2DPlayer_c* mpa2DPlayer[4];
    /* 0x2F4 */ daWmItem_c* mpItem[7];

    FILL(0x310, 0x8DD);

    /* 0x8DD */ u8 m0x8DD;

    FILL(0x8DE, 0x8E0);
    OFFSET_ASSERT(0x8E0);
};