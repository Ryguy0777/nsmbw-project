#pragma once

#include "d_player_model.h"

class dKinopicoMdl_c : public dPlayerMdl_c
{
public:
    dKinopicoMdl_c();

    ~dKinopicoMdl_c() override;

    float getLegLengthP(u8 param_1) override;
};
