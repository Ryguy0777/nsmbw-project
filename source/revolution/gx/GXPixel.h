#pragma once

#include <revolution/gx/GXEnum.h>
#include <revolution/gx/GXStruct.h>

#include <revolution/mtx.h>

EXTERN_C_START

typedef struct _GXFogAdjTable {
    u16 r[10]; // at 0x0
} GXFogAdjTable;

#define GX_FOG_ADJ_TABLE_SZ 10

void GXSetFog(GXFogType type, GXColor color, f32 start, f32 end, f32 near,
              f32 far);
void GXInitFogAdjTable(GXFogAdjTable* table, u16 width, const Mtx44 proj);
void GXSetFogRangeAdj(GXBool enable, u16 center, const GXFogAdjTable* table);
void GXSetBlendMode(GXBlendMode mode, GXBlendFactor src, GXBlendFactor dst,
                    GXLogicOp op);
void GXSetColorUpdate(GXBool enable);
void GXSetAlphaUpdate(GXBool enable);
void GXSetZMode(GXBool enableTest, GXCompare func, GXBool enableUpdate);
void GXSetZCompLoc(GXBool beforeTex);
void GXSetPixelFmt(GXPixelFmt pixelFmt, GXZFmt16 zFmt);
void GXSetDither(GXBool enable);
void GXSetDstAlpha(GXBool enable, u8 alpha);
void GXSetFieldMask(GXBool enableEven, GXBool enableOdd);
void GXSetFieldMode(GXBool texLOD, GXBool adjustAR);

EXTERN_C_END
