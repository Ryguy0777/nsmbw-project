#pragma once

#include <d/d_player_model_manager.h>
#include <d/wm/d_wm_player_base.h>

class daWmSubPlayer_c : public dWmPlayerBase_c
{
public:
    /* 0x808EE0C0 */
    s32 getPlayerOrder();

    /* 0x1CC */ dPyMdlMng_c* mModelManager;
};