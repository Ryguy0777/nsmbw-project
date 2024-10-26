#pragma once

#include "d_player_model.h"

class dKinopioMdl_c : public dPlayerMdl_c
{
    SIZE_ASSERT(0x87C);

public:
    [[address(0x800BCBD0)]]
    dKinopioMdl_c(u8 index);

    FILL(0x824, 0x87C);
};