#pragma once

#include <dynamic/d_actor.h>
#include <dynamic/d_mj2d_game.h>

class daPlBase_c : public dActor_c
{
    SIZE_ASSERT(0x14D4);

    /* 0x0060 VTABLE 0x803087C8 */

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

    /* VT+0x0D4 0x80046DF0 */
    virtual void executeMain();

    /* VT+0x0D8 0x800588F0 */
    virtual void executeLastPlayer();

    /* VT+0x0DC 0x800588E0 */
    virtual void executeLastAll();

    /* VT+0x0E0 0x80020BE0 */
    virtual bool isItemKinopio()
    {
        return false;
    }

    /* VT+0x0E4 0x80056BC0 @unofficial */
    virtual void setPowerup(PLAYER_POWERUP_e powerup);

    /* VT+0x0E8 0x80056D40 */
    virtual s32 getTailType(s8 param);

    /* VT+0x0EC 0x80048080 */
    virtual s32 getHeadBgPointData();

    /* VT+0x0F0 0x80054EE0 */
    virtual s32 getWallBgPointData();

    /* VT+0x0F4 0x80056BB0 */
    virtual s32 getFootBgPointData();

    /* VT+0x0F8 0x80048090 */
    virtual f32 VT_0x0F8();

    /* VT+0x0FC 0x800544E0 */
    virtual void checkBgCrossSub();

    /* VT+0x100 0x80054F80 */
    virtual void postBgCross();

    /* VT+0x104 0x800552C0 */
    virtual f32 getSandSinkRate();

    /* VT+0x108 0x80053F90 */
    virtual void setReductionScale();

    /* VT+0x10C 0x80053FE0 */
    virtual void initStampReduction();

    /* VT+0x110 0x80054070 */
    virtual void calcJumpDaiReductionScale(int param1, int param2);

    /* VT+0x114 0x800540D0 */
    virtual void setReductionBoyon();

    /* VT+0x118 0x800564F0 */
    virtual bool setPressBgDamage(int param1, int param2);

    /* VT+0x11C 0x80056360 */
    virtual int setBalloonInDispOut(int param);

    /* VT+0x120 0x8004DCF0 */
    virtual bool isChange();

public:
    // ---------
    // Functions
    // ---------

    /* 0x8004DB40 */
    bool isDemoType(DemoType_e type);

    /* 0x8004DD00 */
    bool isDemo();

    /* 0x8004E040 */
    bool isPlayerGameStop();

    /* 0x8004E050 */
    void stopOther();

    /* 0x800510F0 */
    void stopGoalOther();

    /* 0x800511A0 */
    void playGoalOther();

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
