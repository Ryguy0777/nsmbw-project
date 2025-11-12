#pragma once

#include "Pane.h"

// TODO: Clean this mess of a class up.

namespace nw4r::lyt
{

struct InflationLRTB {
    f32 l; // at 0x0
    f32 r; // at 0x4
    f32 t; // at 0x8
    f32 b; // at 0xC
};

class Window : public Pane
{
public:
    // Window(const res::Window* pRes, const ResBlockSet& rBlockSet);
    virtual ~Window(); // at 0x8

    virtual void DrawSelf(const DrawInfo& rInfo); // at 0x18
    virtual void AnimateSelf(u32 option);         // at 0x20

    virtual ut::Color GetVtxColor(u32 idx) const;       // at 0x24
    virtual void SetVtxColor(u32 idx, ut::Color color); // at 0x28
    virtual u8 GetVtxColorElement(u32 idx) const;       // at 0x34
    virtual void SetVtxColorElement(u32 idx, u8 value); // at 0x38

    virtual Material* FindMaterialByName(const char* pName,
                                         bool recursive); // at 0x40

    virtual void UnbindAnimationSelf(AnimTransform* pAnimTrans); // at 0x50

    virtual AnimationLink*
    FindAnimationLink(AnimTransform* pAnimTrans); // at 0x54

    virtual void SetAnimationEnable(AnimTransform* pAnimTrans, bool enable,
                                    bool recursive); // at 0x58

    virtual Material* GetMaterial() const;      // at 0x64
    virtual Material* GetMaterial(u32 idx) const; // at 0x68
protected:
    struct Frame {
        u8 textureFlip;      // at 0x0
        Material* pMaterial; // at 0x4

        Frame() : textureFlip(0), pMaterial(NULL) {}
    };

    struct Content {
        ut::Color vtxColors[VERTEXCOLOR_MAX]; // at 0x0
        detail::TexCoordAry texCoordAry;      // at 0x10
    };

protected:
    InflationLRTB mContentInflation; // at 0xD4
    Content mContent;                // at 0xE4
    Frame* mFrames;                  // at 0xFC
    u8 mFrameNum;                    // at 0x100
};

}; // namespace nw4r::lyt
