#pragma once

#include <dynamic/d_enemy.h>

class dEnBomhei_c : public dEn_c
{
public:
    // -----------------
    // Virtual Functions
    // -----------------

    /* VT+? 0x809CA8D0 */
    void hitCallback_HipAttk(dCc_c* main, dCc_c* other);
};