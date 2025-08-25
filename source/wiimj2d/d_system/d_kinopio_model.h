#pragma once

#include "d_system/d_player_model.h"
#include "machine/m_3d_anmtexpat.h"

class dKinopioMdl_c final : public dPlayerMdl_c
{
    SIZE_ASSERT(0x87C);

public:
    // ------------
    // Constructors
    // ------------

    /* 0x800BCBD0 */
    dKinopioMdl_c(u8 index);

    /* VT+0x08 0x800BCC90 */
    virtual ~dKinopioMdl_c() override;

public:
    // -----------------
    // Virtual Functions
    // -----------------

    /* VT+0x34 0x800BCF30 */
    virtual void setColorType(u8 colorType) override;

    /* VT+0x60 0x800BD260 */
    virtual s32 VT_0x60(s32 param1, s32 param2, s32 param3) override;

    /* VT+0x7C 0x800BD5D0 */
    virtual void VT_0x7C() override;

    /* VT+0x80 0x800BD160 */
    virtual void setTexAnmType(TexAnmType_e) override;

    /* VT+0xB0 0x800BD6F0 */
    virtual void callbackTimingA(void* param_1, void* param_2) override;

    /* VT+0xB4 0x800BD670 */
    virtual float VT_0xB4() override;

    /* VT+0xB8 0x800BCD20 */
    virtual void createPlayerModel() override;

public:
    // -----------
    // Member Data
    // -----------

    /* 0x824 */ m3d::anmTexPat_c mPropelBodySwitchAnim;
    /* 0x850 */ m3d::anmTexPat_c mPenguinBodySwitchAnim;
};