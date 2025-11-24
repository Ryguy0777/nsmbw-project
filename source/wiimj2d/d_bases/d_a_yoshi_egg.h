#pragma once

#include "d_system/d_enemy.h"

class daYoshiEgg_c : public dEn_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x80911380 */
    void loadModel();

    /* 0x80911610 */
    void spawnEggBreakEffect();

    /* 0x80911680 */
    void hatchYoshi();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5F8);

    /* 0x528 */ int mColor;

    FILL(0x528, 0x610);
};