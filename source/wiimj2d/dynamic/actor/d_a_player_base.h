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
