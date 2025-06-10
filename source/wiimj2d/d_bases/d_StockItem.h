#pragma once

#include <d_system/d_a_player_manager.h>
#include <d_system/d_base.h>
#include <d_system/d_lytbase.h>
#include <state/s_FStateFct.h>
#include <state/s_State.h>
#include <state/s_StateMethodUsr_FI.h>
#include <state/s_StateMgr.h>

class da2DPlayer_c;
class daWmItem_c;
class dStockItemShadow_c;

class dStockItem_c : public dBase_c
{
public:
    // ------------
    // Constructors
    // ------------

    /* 0x807AF3A0 */
    dStockItem_c();

public:
    // -------------------
    // Constants and Types
    // -------------------

    enum class PANE_LIST_e {
        FIRST = 0,

        P_iconBase_00 = 14,
        P_iconBase_01 = 15,
        P_iconBase_02 = 16,
        P_iconBase_03 = 17,
        P_iconBase_04 = 18,
        P_iconBase_05 = 19,  
        P_iconBase_06 = 20,
        P_iconBase_07 = 21,
        P_iconBase_08 = 22,
        P_iconBase_09 = 23,
        NONE = 24,
    };

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x807AFB90 */
    PANE_LIST_e getPosPaneForPlayer(int player);

    /* 0x807AFBC0 */
    void calcPosScale();

    /* 0x807B00A0 */
    void calc2DPlayerItemUpdate();

    /* 0x807B06C0 */
    bool checkItemSelect();

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
    /* 0x2F4 */ daWmItem_c* mpaItem[7];
    /* 0x310 */ dStockItemShadow_c* mpShadow;

    FILL(0x314, 0x8B0);

    /* 0x8B0 */ int mPresentPlayerCount;
    /* 0x8B4 */ int mItemCount[7];

    FILL(0x8D0, 0x8D8);

    /* 0x8D8 */ bool maPlayerPresent_Removed[4];

    FILL(0x8DC, 0x8DD);

    /* 0x8DD */ u8 m0x8DD;

    FILL(0x8DE, 0x8E0);
    OFFSET_ASSERT(0x8E0);

#define dStockItem_c_OFFSET_mpa2DPlayer 0x8E0
    /* 0x8E0 */ da2DPlayer_c* mpa2DPlayer[PLAYER_COUNT];

#define dStockItem_c_OFFSET_maPlayerPresent (dStockItem_c_OFFSET_mpa2DPlayer + PLAYER_COUNT * 4)
    /* 0x8F0 */ u8 maPlayerPresent[PLAYER_COUNT];

public:
    // ---------
    // State IDs
    // ---------

    /*
     * executeState: 0x807B09D0
     */
    sState_Extern(0x809957E8, dStockItem_c, WindowOpenInit);

    sState_Extern(0x80995828, dStockItem_c, WindowOpenAnimeEndWait);

    sState_Extern(0x80995868, dStockItem_c, ButtonChangeAnimeEndWait);

    sState_Extern(0x809958A8, dStockItem_c, ItemSelectWait);

    sState_Extern(0x809958E8, dStockItem_c, SuccessionItemSelectWait);

    sState_Extern(0x80995928, dStockItem_c, WindowCloseAnimeEndWait);

    sState_Extern(0x80995968, dStockItem_c, HitAnimeEndWait);

    sState_Extern(0x809959A8, dStockItem_c, WindowCloseInit);
};