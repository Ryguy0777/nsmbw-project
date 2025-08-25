#pragma once

#include "egg/math/eggMatrix.h"
#include "egg/math/eggVector.h"
#include "egg/prim/eggBitFlag.h"
#include "eggExEffect.h"
#include <nw4r/ef/Handle.h>

namespace EGG
{

class Effect
{
    SIZE_ASSERT(0x114);

    /* 0x000 VTABLE 0x80350AF8 */

public:
    // ------------
    // Constructors
    // ------------

    /* 0x802D7D90 */
    Effect();

    /* VT+0x08 0x802D7E10 */
    virtual ~Effect();

public:
    // -------------------
    // Constants and Types
    // -------------------

    // TODO
    enum class ERecursive {
    };

public:
    // -----------
    // Member Data
    // -----------

    /* 0x004 */ char name[32];
    /* 0x024 */ u32 mCreator;
    /* 0x028 */ TBitFlag<u32> mFlags;
    /* 0x02C */ Vector3f mScale;
    /* 0x038 */ Vector3f mTranslate;
    /* 0x044 */ Matrix34f mMatrix;
    /* 0x074 */ nw4r::ef::HandleBase mHandle;
    /* 0x07C */ ExEffectParam mExParam;
};

} // namespace EGG