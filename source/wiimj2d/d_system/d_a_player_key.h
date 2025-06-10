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

    FILL(0x000, 0x164);
};