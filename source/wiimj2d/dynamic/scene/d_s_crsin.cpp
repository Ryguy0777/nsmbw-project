// d_s_crsin.cpp
// NSMBW d_bases.text: 0x8091EC10 - 0x80921060

#include "d_s_crsin.h"

#include <dynamic/d_resource_manager.h>

[[address(0x8091EC50)]]
int dScCrsin_c::loadDefaultObjectResPhase()
{
    static const char* l_objectRes[] = {
      "Mario",
      "Luigi",
      "Kinopio",
      "Yoshi",
      "P_rcha",
      "L_rcha",
      "K_rcha",
      "Y_rcha",
      "Y_TexGreen",
      "Y_TexRed",
      "Y_TexYellow",
      "Y_TexBlue",
      "obj_coin",
      "balloon",
      "I_kinoko",
      "I_fireflower",
      "I_iceflower",
      "I_star",
      "I_propeller",
      "I_penguin",
      "I_yoshi_egg",
      "block_tsuta",
      "teresa",
      "jump_step",
      "ice",
      "ice_piece",
      "obj_dokan",
      "obj_door",
      "obj_kusa",
      "obj_hana",
      "obj_hana_daishizen",
      "block_jump",
      "obj_chikuwa_block",
      "lift_rakka_ashiba",
      "Mask",

      // Added
      "Kinopico",
    };

    dResMng_c::m_instance->setRes(
      "Object", l_objectRes, sizeof(l_objectRes) / sizeof(l_objectRes[0]), nullptr
    );

    return 1;
}