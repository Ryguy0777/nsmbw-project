#pragma once

#include <dynamic/d_actor.h>

class daPlBase_c : public dActor_c
{
    SIZE_ASSERT(0x14D4);

public:
    // -------------------
    // Constants and Types
    // -------------------

    enum class DamageType_e {
        NORMAL = 0,
        NORMAL2 = 1,
        KNOCKBACK_AND_HURT = 2,
        KNOCKBACK_LONG = 3, // Player does not take damage
        KNOCKBACK_LONG2 = 4, // Player does not take damage
        KNOCKBACK_SHORT = 5, // Player does not take damage
        KNOCKBACK_SHORT2 = 6, // Player does not take damage
        LAVA = 7,
        FIRE = 8, // Looks the same as NORMAL?
        ELEC_SHOCK = 9,
        POISON_WATER = 10,
        CRUSH = 11,
        EAT_DIE = 12,
        EAT_DIE2 = 13, // Like EAT_DIE but does not stop the music
        UNKNOWN = 14,
        FREEZE = 15,
        FREEZE2 = 16,
        BOUNCE = 17, // Makes the player do a squishy animation
        POISON_FOG = 18,
    };

    enum class DemoType_e {
        DEMO_0 = 0,
        DEMO_1 = 1,
        DEMO_2 = 2,
        DEMO_3 = 3,
        DEMO_4 = 4,
        DEMO_5 = 5,
        DEMO_6 = 6,
    };

public:
    // -----------------
    // Virtual Functions
    // -----------------

    /* VT+0x0D4 */
    virtual void executeMain();

    /* VT+0x0D8 */
    virtual void executeLastPlayer();

    /* VT+0x0DC */
    virtual void executeLastAll();

    /* VT+0x0E0 */
    virtual bool isItemKinopio();

public:
    // ---------
    // Functions
    // ---------

    /* 0x8004DB40 */
    bool isDemoType(DemoType_e type);

    /* 0x8004E040 */
    bool isPlayerGameStop();

    /* 0x8004E050 */
    void stopOther();

    /* 0x800510F0 */
    void stopGoalOther();

    /* 0x80051E70 */
    bool startControlDemo();

    /* 0x80051EF0 */
    void endControlDemo(int param);

    void UNDEF_80052290(s32 param);

    /* 0x80052470 */
    bool isBossDemoLand();

    /* 0x80056C70 */
    void onStatus(int flag);

    /* 0x80056CF0 */
    bool isStatus(int flag);

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x394, 0x10D4);

    /* 0x10D4 */ u32 m0x10D4;

    FILL(0x10D8, 0x14D4);
};
