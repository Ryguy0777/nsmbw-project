// d_a_wm_player_static.cpp
// NSMBW .text: 0x80100A10 - 0x801016B0
// NSMBW .sbss: 0x8042A47E - 0x8042A484

#include "d_a_wm_player.h"

EXTERN_DATA(
  0x8042A480, //
  daWmPlayer_c* daWmPlayer_c::ms_instance
);

[[address(0x80100B60)]]
const char* daWmPlayer_c::getSkeletonRoot(dPyMdlMng_c::ModelType_e character)
{
    switch (character) {
    case dPyMdlMng_c::ModelType_e::MODEL_MARIO:
        return "mario_all_root";

    case dPyMdlMng_c::ModelType_e::MODEL_LUIGI:
        return "luigi_all_root";

    case dPyMdlMng_c::ModelType_e::MODEL_TOAD_BLUE:
    case dPyMdlMng_c::ModelType_e::MODEL_TOAD_YELLOW:
    case dPyMdlMng_c::ModelType_e::MODEL_TOAD_RED:
    case dPyMdlMng_c::ModelType_e::MODEL_TOAD_BLACK:
    case dPyMdlMng_c::ModelType_e::MODEL_TOAD_ORANGE:
        return "kinopio_all_root";

    case dPyMdlMng_c::ModelType_e::MODEL_TOADETTE:
    case dPyMdlMng_c::ModelType_e::MODEL_TOADETTE_PURPLE:
        return "kinopico_all_root";

    case dPyMdlMng_c::ModelType_e::MODEL_YOSHI:
        return "yoshi_all_root";

    case dPyMdlMng_c::ModelType_e::MODEL_NONE:
        return nullptr;
    }

    return nullptr;
}