#pragma once

#include <dynamic/d_base_actor.h>
#include <dynamic/d_mj2d_game.h>

class dPyMdlMng_c;

class da2DPlayer_c : public dBaseActor_c
{
    SIZE_ASSERT(0x384);

    /* 0x060 VTABLE 0x809812E0 */

public:
    /* 0x808C5130 */
    da2DPlayer_c();

    /* 0x808C5990 */
    void loadPlayer();

    //
    // Member Data
    //

    /* 0x128 */ dPyMdlMng_c* mModelMng;

    FILL(0x12C, 0x238);

    /* 0x238 */ PLAYER_POWERUP_e mPowerup;

    FILL(0x23C, 0x260);

    /* 0x260 */ bool mReady;

    FILL(0x261, 0x264);

    /* 0x264 */ u8 m0x264;

    FILL(0x265, 0x266);

    /* 0x266 */ u8 m0x266;
    /* 0x267 */ u8 m0x267;

    FILL(0x268, 0x269);

    /* 0x269 */ u8 m0x269;
    /* 0x26A */ u8 m0x26A;

    FILL(0x26B, 0x384);
};