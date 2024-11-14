#pragma once

namespace nw4r::lyt::res
{

constexpr u32 PANE_NAME_SIZE = 16;
constexpr u32 PANE_USERDATA_SIZE = 8;
constexpr u32 ANIMTARGET_PANE_MAX = 10;
constexpr u32 MATERIAL_NAME_SIZE = 20;
constexpr u32 NW4R_RES_NAME_SIZE = 16;
constexpr u32 NW4R_MAT_NAME_SIZE = 20;

constexpr u32 TEXCOORD_VTX_COUNT = 4;

struct DataBlockHeader {
    SIZE_ASSERT(0x8);

    /* 0x0 */ char kind[4];
    /* 0x4 */ u32 size;
};

struct ExtUserDataList {
    SIZE_ASSERT(0xC);

    /* 0x0 */ DataBlockHeader blockHeader;
    /* 0x8 */ u16 num;
    /* 0xA */ u16 padding;
};

} // namespace nw4r::lyt::res