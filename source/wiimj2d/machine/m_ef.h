#pragma once

#include <egg/util/eggEffect.h>

namespace mEf
{

class effect_c : public EGG::Effect
{
    SIZE_ASSERT(0x114);

    /* 0x000 VTABLE 0x80329D68 */

public:
    // ------------
    // Constructors
    // ------------

    effect_c() = default;

    /* VT+0x08 0x80025FE0 */
    virtual ~effect_c();
};

class levelEffect_c : public effect_c
{
    SIZE_ASSERT(0x128);

    /* 0x000 VTABLE 0x80329D68 */

public:
    // ------------
    // Constructors
    // ------------

    // This is normally inlined but is (luckily for us) emitted externally as its own function in
    // d_en_toride_kokoopa.cpp for use with __construct_array, alleviating the requirement for us to
    // recreate the entire vtable.
    [[address(0x800A8AB0)]]
    levelEffect_c();

    // This also is normally inlined
    [[address(0x80025F60)]]
    virtual ~levelEffect_c() override;

public:
    // -----------
    // Member Data
    // -----------

    /* 0x114 */ levelEffect_c* mpPrev;
    /* 0x118 */ levelEffect_c* mpNext;
    /* 0x11C */ bool mSet;
    /* 0x11D */ bool mActive;
    /* 0x120 */ u32 m0x120;
    /* 0x124 */ u32 m0x124;
};

} // namespace mEf