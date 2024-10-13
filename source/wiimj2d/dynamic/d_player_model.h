#pragma once

#include "d_player_model_base.h"

class dPlayerMdl_c : public dPyMdlBase_c
{
    SIZE_ASSERT(0x824);

    /* 0x000 VTABLE 0x80318048 */
public:
    enum MODEL_e {
        MODEL_NORMAL = 0,
        MODEL_SMALL = 1,
        MODEL_PROPELLER = 2,
        MODEL_PENGUIN = 3,

        MODEL_COUNT = 4,
    };

    struct ModelData {
        /* 0x00 */ const char* mResName;
        /* 0x04 */ const char* mAnmResName;
        /* 0x08 */ const char* mBodyModels[MODEL_COUNT];
        /* 0x18 */ const char* mHeadModels[MODEL_COUNT];
        /* 0x28 */ float mUnkFloat1;
        /* 0x2C */ float mUnkFloat2;
        /* 0x30 */ float mUnkFloat3;
        /* 0x34 */ float mUnkFloat4;
    };

    static_assert(sizeof(ModelData) == 0x38);

    /* 0x800D2EC0 */
    dPlayerMdl_c();

    /* VT+0x08 0x800D31D0 */
    virtual ~dPlayerMdl_c();

    /* VT+0x0C */
    EXTERN_TEXT_INLINE(
      0x800BD7E0, // d_kinopio_model.o
      virtual int getFaceJointIdx() const override
    )
    {
        return mFaceJointIdx;
    }

    /* VT+0x10 0x800D3300 */
    virtual void createModel() override;
    /* VT+0x14 0x800D3370 */
    virtual void initialize() override;
    /* VT+0x18 0x800D3990 */
    virtual void play() override;
    /* VT+0x1C 0x800D37D0 */
    virtual void _calc() override;
    /* VT+0x20 0x800D3920 */
    virtual void calc2() override;
    /* VT+0x24 0x800D3B20 */
    virtual void draw() override;

    /* VT+0x28 */
    EXTERN_TEXT(
      0x800BD140, // d_kinopio_model.o
      virtual void* getBodyMdl() override
    );

    /* VT+0x2C 0x800BD7D0 */
    EXTERN_TEXT_INLINE(
      0x800BD7D0, // d_kinopio_model.o
      virtual const void* getAnmResFile() const override
    )
    {
        return &mAnimResFile;
    }

    /* VT+0x30 0x800D4760 */
    virtual void setPlayerMode(int) override;
    /* VT+0x34 0x800D4870 */
    virtual void setColorType(u8) override;
    /* VT+0x38 0x800D4880 */
    virtual void setDark(int) override;

    /* VT+0x40 0x800D4AC0 */
    virtual void onStarAnm() override;
    /* VT+0x44 0x800D4B40 */
    virtual void offStarAnm() override;

    /* VT+0x54 0x800D4A70 */
    virtual bool getHeadPropelJointMtx(mMtx_c*) override;
    /* VT+0x58 0x800D4150 */
    virtual void VT_0x58() override;

    /* VT+0x60 0x800D3FE0 */
    virtual void VT_0x60() override;

    /* VT+0x6C 0x800D41E0 */
    virtual void copyAnm() override;
    /* VT+0x70 0x800D4330 */
    virtual void VT_0x70() override;
    /* VT+0x74 0x800D44D0 */
    virtual void VT_0x74() override;
    /* VT+0x78 0x800D4610 */
    virtual void setAnmBind() override;
    /* VT+0x7C 0x800D3DD0 */
    virtual void VT_0x7C() override;
    /* VT+0x80 0x800D3CE0 */
    virtual void setTexAnmType(TexAnmType_e) override;

    /* VT+0x94  */
    EXTERN_TEXT_INLINE(
      0x800BD7C0, //
      virtual void setPropelRollSpeed(u16 speed) override
    )
    {
        mPropelRollSpeed = speed;
    }

    /* VT+0x98  */
    EXTERN_TEXT_INLINE(
      0x800BD7B0, //
      virtual s16 getPropelRollSpeed() const override
    )
    {
        return mPropelRollSpeed;
    }

    /* VT+0x9C  */
    EXTERN_TEXT_INLINE(
      0x800BD7A0, //
      virtual void setPropelRollAngle(s16 angle) override
    )
    {
        mPropelRollAngle = angle;
    }

    /* VT+0xA0  */
    EXTERN_TEXT_INLINE(
      0x800BD790, //
      virtual s16 getPropelRollAngle() const override
    )
    {
        return mPropelRollAngle;
    }

    /* VT+0xA4  */
    EXTERN_TEXT_INLINE(
      0x800BD780, //
      virtual void setPropelScale(float scale) override
    )
    {
        mPropelScale = scale;
    }

    /* VT+0xA8  */
    EXTERN_TEXT(
      0x800BD760, //
      virtual float getLegLengthP(u8) override
    );

public:
    FILL(0x20C, 0x210);

    /* 0x210 */ u8 mAnimResFile; // Unknown size

    FILL(0x211, 0x770);

    /* 0x770 */ MODEL_e mModelIdx;

    /* 0x774 */ MODEL_e mLastModelIdx;

    /* 0x778 */ const ModelData* mpModelData;

    /* 0x77C */ u32 mFaceJointIdx;

    /* 0x780 */ s16 mPropelRollAngle;
    /* 0x782 */ u16 mPropelRollSpeed;
    /* 0x784 */ float mPropelScale;

    FILL(0x788, 0x824);
};
