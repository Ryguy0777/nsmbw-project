#pragma once

#include "d_bases/d_profile.h"
#include "d_system/d_allocator.h"
#include "d_system/d_enemy.h"
#include "machine/m_3d_anmchr.h"
#include "machine/m_3d_anmtexpat.h"
#include "machine/m_3d_anmtexsrt.h"
#include "machine/m_3d_mdl.h"

class daEnHatenaBalloon_c : public dEn_c,
                            public dProf::Info<daEnHatenaBalloon_c, dProf::EN_HATENA_BALLOON>
{
    SIZE_ASSERT(0x8A0);

public:
    // Nested Types
    // ^^^^^^

    struct Param_s {
        u32 : 15;
        u32 item_type : 5 = 0; // +++
        u32 has_item : 4 = 0;
        u32 unk : 4 = 0;
        u32 player : 4 = 0;
    };

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80111990 */
    void model_set();

    /* 0x80112110 */
    void createItem();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x524 */ dHeapAllocator_c mAllocator;
    /* 0x540 */ nw4r::g3d::ResFile mResFile;
    /* 0x544 */ m3d::mdl_c mModel;
    /* 0x584 */ m3d::mdl_c mModelBack;
    /* 0x5C4 */ m3d::anmChr_c mAnmChr;
    /* 0x5FC */ m3d::anmChr_c mAnmChrBack;
    /* 0x634 */ m3d::anmTexPat_c mAnmTexPat;
    /* 0x660 */ m3d::anmTexPat_c mAnmTexPatBack;
    /* 0x68C */ m3d::anmTexSrt_c mAnmTexSrt;
    /* 0x6B8 */ m3d::mdl_c mItemModel;
    /* 0x6F8 */ m3d::anmChr_c mItemAnmChr;
    /* 0x730 */ m3d::anmTexPat_c mItemAnmTexPat;

    FILL(0x75C, 0x7A4);

    /* 0x7A4 */ mVec3_c mItemScale;

    FILL(0x7B0, 0x7EC);

    /* 0x7EC */ int mHasItem;

    FILL(0x7F0, 0x8A0);
};