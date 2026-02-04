#pragma once

#include "d_system/d_player_model.h"

class dGameWatchMdl_c final : public dPlayerMdl_c
{
public:
    dGameWatchMdl_c(u8 index);

    ~dGameWatchMdl_c() override;

protected:
    m3d::anmTexPat_c* getBodyTexAnm();

    void createAnim(m3d::anmTexPat_c& anm, const char* name, u8 modelIdx);

public:
    float VT_0xB4() override;

    void createPlayerModel() override;
};