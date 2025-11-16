#pragma once

#include "d_system/d_enemy.h"

class daMiniGameBalloon_c : public dEn_c {
public:
    // Virtual Functions
    // ^^^^^^

    /* 0x80864170 */
    void hitCallback_Cannon(dCc_c* self, dCc_c* other);
};
