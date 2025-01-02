#pragma once

#include <dynamic/d_a_player_manager.h>
#include <dynamic/d_player_model_manager.h>
#include <dynamic/d_wm_player_base.h>

class daWmSubPlayer_c : public dWmPlayerBase_c
{
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x808EB7D0 */
    void loadModel();

    /* 0x808EE0C0 */
    s32 getPlayerOrder();

    /* 0x808EEA00 */
    s32 UNDEF_808EEA00(int playerOrder);

    /* 0x808EF2B0 */
    bool isPlayerType(daPyMng_c::PlayerType_e playerType);

public:
    // ----------------
    // Static Functions
    // ----------------

    /* 0x808EE950 */
    static int getSubPlayerNum();

public:
    // -----------
    // Member Data
    // -----------

    /* 0x1CC */ dPyMdlMng_c* mModelManager;

    FILL(0x1D0, 0x208);

    /* 0x208 */ int mSubPlayerNo;
};