#pragma once

#include "GXStruct.h"
#include "GXEnum.h"

struct GXLightObj {
    char UNK_0x0[0xC];
    GXColor color; // at 0xC
    f32 aa; // at 0x10
    f32 ab; // at 0x14
    f32 ac; // at 0x18
    f32 ka; // at 0x1C
    f32 kb; // at 0x20
    f32 kc; // at 0x24
    f32 posX; // at 0x28
    f32 posY; // at 0x2C
    f32 posZ; // at 0x30
    f32 dirX; // at 0x34
    f32 dirY; // at 0x38
    f32 dirZ; // at 0x3C
};

void GXInitLightAttn(GXLightObj* light, f32 aa, f32 ab, f32 ac, f32 ka, f32 kb,
                     f32 kc);
void GXInitLightAttnA(GXLightObj* light, f32 a, f32 b, f32 c);
void GXInitLightAttnK(GXLightObj* light, f32 a, f32 b, f32 c);
void GXInitLightSpot(GXLightObj* light, f32 angle, GXSpotFn fn);
void GXInitLightDistAttn(GXLightObj* light, f32 distance, f32 brightness,
                         GXDistAttnFn fn);
void GXInitLightPos(GXLightObj* light, f32 x, f32 y, f32 z);
void GXGetLightPos(const GXLightObj* light, f32* x, f32* y, f32* z);
void GXInitLightDir(GXLightObj* light, f32 x, f32 y, f32 z);
void GXGetLightDir(const GXLightObj* light, f32* x, f32* y, f32* z);
void GXInitSpecularDir(GXLightObj* light, f32 x, f32 y, f32 z);
void GXInitLightColor(GXLightObj* light, GXColor color);
void GXLoadLightObjImm(const GXLightObj* light, GXLightID id);
void GXLoadLightObjIndx(u16 index, GXLightID id);
void GXSetChanAmbColor(GXChannelID chan, GXColor color);
void GXSetChanMatColor(GXChannelID chan, GXColor color);
void GXSetNumChans(u8 num);
void GXSetChanCtrl(GXChannelID chan, GXBool enable, GXColorSrc ambSrc,
                   GXColorSrc matSrc, GXLightID lightMask, GXDiffuseFn diffFn,
                   GXAttnFn attnFn);