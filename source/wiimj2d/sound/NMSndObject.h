#pragma once

#include "NMSndObjectBase.h"
#include "System.h"
#include <iterator>
#include <nw4r/math/vec.h>
#include <nw4r/snd/SoundActor.h>
#include <nw4r/snd/SoundHandle.h>

template <int TParam>
class NMSndObject : public NMSndObjectBase
{
    SIZE_ASSERT(0xAC);

public:
    // ------------
    // Constructors
    // ------------

    NMSndObject(nw4r::snd::SoundArchivePlayer& soundArchivePlayer)
      : NMSndObjectBase(OBJ_TYPE::TYPE_0, soundArchivePlayer)
      , m0x64(1.0)
      , m0x68f(0.0)
      , m0x6C(0.0)
      , mPan(0.0)
      , maSndObjList()
    {
        SetPlayableSoundCount(0, TParam);

        mNumHandles = std::size(maSndObjList);
        mRemotePlayer = 1;
    }

public:
    // -------------------
    // Constants and Types
    // -------------------

    class SoundHandlePrm
    {
        SIZE_ASSERT(0x8);

    public:
        // ------------
        // Constructors
        // ------------

        /* [0x80046470 with TParam = 4] */
        SoundHandlePrm()
        {
            mSoundHandle = nullptr;
            m0x4 = 1.0f;
        }

    public:
        // -----------
        // Member Data
        // -----------

        /* 0x0 */ nw4r::snd::SoundHandle* mSoundHandle;
        /* 0x4 */ f32 m0x4;
    };

public:
    // -----------------
    // Virtual Functions
    // -----------------

    /* VT+0x20 [0x80046E00 with TParam = 4] */
    virtual void calc(const nw4r::math::VEC2&);

    /* VT+0x24 [0x80058910 with TParam = 4] */
    virtual nw4r::snd::SoundHandle* startSound(u32 soundId, u32 remoteMask) = 0;

    /* VT+0x28 [0x80058C10 with TParam = 4] */
    virtual nw4r::snd::SoundHandle* holdSound(u32 soundId, u32 remoteMask) = 0;

    /* VT+0x2C [0x80059030 with TParam = 4] */
    virtual nw4r::snd::SoundHandle* prepareSound(u32 soundId, u32 remoteMask) = 0;

    /* VT+0x30 [0x80058A00 with TParam = 4] */
    virtual nw4r::snd::SoundHandle* startSound(u32 soundId, short seqParam, u32 remoteMask) = 0;

    /* VT+0x34 [0x80058D60 with TParam = 4] */
    virtual nw4r::snd::SoundHandle* holdSound(u32 soundId, short seqParam, u32 remoteMask) = 0;

    /* VT+0x38 [0x80058B20 with TParam = 4] */
    virtual nw4r::snd::SoundHandle*
    startSound(u32 soundId, const nw4r::math::VEC2& position, u32 remoteMask) = 0;

    /* VT+0x3C [0x80058EE0 with TParam = 4] */
    virtual nw4r::snd::SoundHandle*
    holdSound(u32 soundId, const nw4r::math::VEC2& position, u32 remoteMask) = 0;

public:
    // -----------
    // Member Data
    // -----------

    /* 0x64 */ f32 m0x64;

    union {
        /* 0x68 */ s32 m0x68;
        /* 0x68 */ f32 m0x68f;
    };

    /* 0x6C */ f32 m0x6C;
    /* 0x70 */ f32 mPan;
    /* 0x74 */ SoundHandlePrm maSndObjList[6];
    /* 0xA4 */ nw4r::math::VEC2 m0xA4;
};

// ------------------------
// Template Specializations
// ------------------------

/* VT+0x20 */
template <>
[[address(0x80046E00)]]
void NMSndObject<4>::calc(const nw4r::math::VEC2&);

/* VT+0x24 */
template <>
[[address(0x80058910)]]
nw4r::snd::SoundHandle* NMSndObject<4>::startSound(u32, u32);

/* VT+0x28 */
template <>
[[address(0x80058C10)]]
nw4r::snd::SoundHandle* NMSndObject<4>::holdSound(u32, u32);

/* VT+0x2C */
template <>
[[address(0x80059030)]]
nw4r::snd::SoundHandle* NMSndObject<4>::prepareSound(u32, u32);

/* VT+0x30 */
template <>
[[address(0x80058A00)]]
nw4r::snd::SoundHandle* NMSndObject<4>::startSound(u32, short, u32);

/* VT+0x34 */
template <>
[[address(0x80058D60)]]
nw4r::snd::SoundHandle* NMSndObject<4>::holdSound(u32, short, u32);

/* VT+0x38 */
template <>
[[address(0x80058B20)]]
nw4r::snd::SoundHandle* NMSndObject<4>::startSound(u32, const nw4r::math::VEC2&, u32);

/* VT+0x3C */
template <>
[[address(0x80058EE0)]]
nw4r::snd::SoundHandle* NMSndObject<4>::holdSound(u32, const nw4r::math::VEC2&, u32);