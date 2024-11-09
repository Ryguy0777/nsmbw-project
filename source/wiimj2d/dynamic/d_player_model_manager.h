#pragma once

#include "System.h"
#include <dynamic/d_player_model_base.h>
#include <machine/m_angle.h>
#include <machine/m_mtx.h>
#include <machine/m_vec.h>

class dPyMdlBase_HIO_c {};

class dPyMdlMng_c
{
    SIZE_ASSERT(0xC);

    /* 0x0 VTABLE 0x80318D98 */

public:
    enum class ModelType_e {
        MODEL_NONE = -1,
        MODEL_MARIO = 0,
        MODEL_LUIGI = 1,
        MODEL_BLUE_TOAD = 2,
        MODEL_YELLOW_TOAD = 3,
        MODEL_RED_TOAD = 4,
        MODEL_YOSHI = 5,

        // Added
        MODEL_TOADETTE = 6,
    };

    /* 0x800D6DB0 */
    dPyMdlMng_c(ModelType_e modelType);

    /**
     * VT+0x08 0x800D6EF0
     * Destroys the player model manager.
     */
    virtual ~dPyMdlMng_c();

    /* 0x800D6E00 */
    void construct(u8 index);

    /* 0x800D6EE0 @unofficial */
    void loadModel(s32 param_1, u8 param_2, s32 param_3);

    /* 0x800D6F80 */
    void play();

    /* 0x800D6FA0 */
    void calc(mMtx_c& mtx);

    /* 0x800D7030 */
    void calc(mVec3_c vec, mAng3_c angle, mVec3_c vec2);

    /* 0x800D70F0 */
    void calc2();

    /* 0x800D7110 */
    void draw();

    /* 0x4 */ dPyMdlBase_c* mModel;
    /* 0x8 */ u32 mDrawReady;

    /* 0x803710A0 */ static dPyMdlBase_HIO_c m_hio;
};
