#pragma once

#include "d_player_model.h"

class dKinopicoMdl_c final : public dPlayerMdl_c
{
public:
    dKinopicoMdl_c(u8 index);

    ~dKinopicoMdl_c() override;

protected:
    m3d::anmTexPat_c* getBodyTexAnm();

    void createAnim(m3d::anmTexPat_c& anm, const char* name, u8 modelIdx);

public:
    void setColorType(u8 modelIndex) override;

    float VT_0xB4() override;

    void createPlayerModel() override;

    //
    // Member Data
    //

    m3d::anmTexPat_c mPropelBodySwitchAnim;
    m3d::anmTexPat_c mPenguinBodySwitchAnim;
};
