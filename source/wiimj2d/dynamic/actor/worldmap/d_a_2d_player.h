#pragma once

#include <dynamic/d_base_actor.h>

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

    /* 0x238 */ u32 mPowerup;

    FILL(0x23C, 0x384);
};