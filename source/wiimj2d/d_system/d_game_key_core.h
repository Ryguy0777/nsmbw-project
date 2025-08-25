#pragma once

#include "machine/m_pad.h"
#include "machine/m_vec.h"

class dGameKeyCore_c
{
    SIZE_ASSERT(0x93);
    /* 0x0 VTABLE 0x80315910 */

public:
    // ------------
    // Constructors
    // ------------

    /* 0x800B5B50 */
    dGameKeyCore_c(mPad::CH_e channel);

    /* VT+0x8 0x800B5BA0 */
    virtual ~dGameKeyCore_c();

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x800B5BE0 */
    void allclear();

    /* 0x800B5CB0 */
    void read();

    /* 0x800B62A0 */
    void setShakeY();

public:
    /* 0x04 */ mPad::CH_e mChannel;
    /* 0x08 */ s32 mControllerType;

    FILL(0x0C, 0x18);

    /* 0x18 */ u32 mHeld;
    /* 0x1C */ u32 mTriggered;

    FILL(0x20, 0x30);

    /* 0x30 */ u32 m0x30;
    /* 0x34 */ mVec3_c mAccel;
    /* 0x40 */ mVec3_c mAccelOld;
    /* 0x4C */ mVec2_c mAccelVerticalX;
    /* 0x54 */ mVec2_c mAccelVerticalXOld;
    /* 0x5C */ mVec2_c mAccelVerticalY;
    /* 0x64 */ mVec2_c mAccelVerticalYOld;
    /* 0x6C */ mVec2_c mAccelVerticalZ;
    /* 0x74 */ mVec2_c mAngle;
    /* 0x7C */ mVec2_c mAngleOld;
    /* 0x84 */ f32 mMoveDistance;
    /* 0x88 */ f32 mMoveDistanceOld;
    /* 0x8C */ bool mShake;
    /* 0x8D */ bool mShakeOld;
    /* 0x8E */ u16 mTilt;
    /* 0x90 */ u8 mShakeTimer1;
    /* 0x91 */ u8 mShakeTimer2;
    /* 0x92 */ u8 mShakeTimer3;
};