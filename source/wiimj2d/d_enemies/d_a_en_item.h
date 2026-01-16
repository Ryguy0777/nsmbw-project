#pragma once

#include "d_bases/d_profile.h"
#include "d_system/d_enemy.h"

class daEnItem_c : public dEn_c, public dProf::Info<daEnItem_c, dProf::EN_ITEM>
{
public:
    // Nested Types
    // ^^^^^^

    struct Param_s {
        /*  0 */ u32 : 1; // Unused?
        /*  1 */ u32 create_type : 7 = 0;
        /*  8 */ u32 unk8 : 2 = 0;
        /* 10 */ u32 unk10 : 2 = 0;
        /* 12 -- */ // u32 direction : 2 = 0;
        /* 14 -- */ // u32 player_type : 4 = 0;
        /* 12 ++ */ u32 player_type : 4 = 0;
        /* 16 -- */ // u32 : 1; // Unused
        /* 17 -- */ // u32 wait : 1 = 0;
        /* 16 ++ */ u32 direction : 2 = 0;
        /* 18 */ u32 red_coin_drop : 1 = 0;
        /* 19 */ u32 unk19 : 1 = 0;
        /* 20 */ u32 z_order : 1 = 0;
        /* 21 */ u32 meter_drop : 1 = 0;
        /* 22 */ u32 unk22 : 1 = 0; // No speed?
        /* 23 -- */ // u32 : 1; // Unused
        /* 23 ++ */ u32 wait : 1 = 0;
        /* 24 */ u32 unk24 : 1 = 0;
        /* 25 */ u32 unk25 : 2 = 0;
        /* 27 */ u32 type : 5 = 0;
    };
};