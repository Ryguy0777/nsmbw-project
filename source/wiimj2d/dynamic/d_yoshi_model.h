#pragma once

#include "d_player_model_base.h"

class dYoshiMdl_c : public dPyMdlBase_c
{
    SIZE_ASSERT(0x404);

public:
    EXTERN_TEXT(
      0x800FE2E0, //
      dYoshiMdl_c(u8 index)
    );

    FILL(0x20C, 0x404);
};