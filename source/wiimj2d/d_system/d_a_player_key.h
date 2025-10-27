#pragma once

class dAcPyKey_c
{
    SIZE_ASSERT(0x164);

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x8005E040 */
    void update();

    /* 0x8005e590 */
    int triggerOne() const;

    /* 0x8005E5D0 */
    int buttonOne() const;

    /* 0x8005E8B0 */
    bool triggerJumpBuf(int param2);

    /* 0x8005E910 */
    void onDemoButton(int button);

    /* 0x8005E930 */
    void offDemoButton(int button);

public:
    // -----------
    // Member Data
    // -----------

    int mRemoconID;
    u16 mDownButtons;
    u16 mTriggeredButtons;
    u16 mPrevDownButtons;
    u16 mPrevTriggeredButtons;
    u16 mDownButtonsDemo;
    u16 mTriggeredButtonsDemo;
    u16 mDemoDoShake;
    u16 mStatus;
    u8 mHipAtkHoldCount;
    bool mHipAtkRead;
    bool mHipAtkHoldStart;
    u8 mTriggerShakeJump;
    u8 mActiveShakeJump;
    bool mActionTriggered;
    int mShakeCooldown;
    int m_20;

    int mJumpTriggeredHistory[4][10];
    int mJumpButtonHistory[4][10];
};