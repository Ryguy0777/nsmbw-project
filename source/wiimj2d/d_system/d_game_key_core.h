#pragma once

#include "machine/m_pad.h"
#include "machine/m_vec.h"
#include <revolution/pad.h>

class dGameKeyCore_c
{
    SIZE_ASSERT(0x93);
    /* 0x0 VTABLE 0x80315910 */

public:
    // Structors
    // ^^^^^^

    /* 0x800B5B50 */
    dGameKeyCore_c(mPad::CH_e channel);

    /* VT+0x8 0x800B5BA0 */
    virtual ~dGameKeyCore_c();

public:
    // Constants and Types
    // ^^^^^^

    /* @unofficial */
    enum class Type_e {
        /**
         * Regular sideways Wii Remote or replay input.
         */
        CORE = 0,
        /**
         * Wii Remote with Nunchuk.
         */
        FREESTYLE = 1,
        /**
         * GameCube Controller (TODO: currently set as CORE).
         */
        DOLPHIN = 2,
        /**
         * Classic Controller (TODO).
         */
        CLASSIC = 3,
    };

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800B5BE0 */
    void allclear();

    /* 0x800B5CB0 */
    void read();

    /* 0x800B62A0 */
    void setShakeY();

    inline EGG::CoreController* getCoreController() const
    {
        return mPad::g_core[static_cast<std::size_t>(mChannel)];
    }

    inline ::PADStatus* getPadStatus() const
    {
        return EGG::CoreControllerMgr::getPadStatus(static_cast<WPADChannel>(mChannel));
    }

    /**
     * Returns true if one of the button flags is set.
     */
    inline bool isDown(u32 flags) const
    {
        return mHeld & flags;
    }

    /**
     * Returns true if one of the button flags is set on this frame.
     */
    inline bool isTrig(u32 flags) const
    {
        return mTriggered & flags;
    }

    /**
     * Checks if the confirm (2 or A) button is pressed.
     */
    inline bool checkMenuConfirm() const
    {
        u32 button = 0;

        switch (mType) {
        case Type_e::CORE:
        case Type_e::FREESTYLE:
            button = WPAD_BUTTON_2 | WPAD_BUTTON_A;
            break;

        case Type_e::CLASSIC:
            button = WPAD_BUTTON_CL_A;
            break;

        case Type_e::DOLPHIN:
            return getPadStatus()->button & PAD_BUTTON_A;
        }

        return getCoreController()->downTrigger(button);
    }

    /**
     * Checks if the cancel (1 or B) button is pressed.
     */
    inline bool checkMenuCancel() const
    {
        u32 button = 0;

        switch (mType) {
        case Type_e::CORE:
        case Type_e::FREESTYLE:
            button = WPAD_BUTTON_1 | WPAD_BUTTON_B;
            break;

        case Type_e::CLASSIC:
            button = WPAD_BUTTON_CL_B;
            break;

        case Type_e::DOLPHIN:
            return getPadStatus()->button & PAD_BUTTON_B;
        }

        return getCoreController()->downTrigger(button);
    }

    /**
     * Checks if the left button is pressed.
     */
    inline bool checkLeft() const
    {
        return isTrig(WPAD_SIDE_BUTTON_LEFT);
    }

    /**
     * Checks if the right button is pressed.
     */
    inline bool checkRight() const
    {
        return isTrig(WPAD_SIDE_BUTTON_RIGHT);
    }

    /**
     * Checks if the up button is pressed.
     */
    inline bool checkUp() const
    {
        return isTrig(WPAD_SIDE_BUTTON_UP);
    }

    /**
     * Checks if the down button is pressed.
     */
    inline bool checkDown() const
    {
        return isTrig(WPAD_SIDE_BUTTON_DOWN);
    }

public:
    /* 0x04 */ mPad::CH_e mChannel;
    /* 0x08 */ Type_e mType;

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
