#pragma once

#include "Pane.h"
#include "Resources.h"

namespace nw4r::lyt
{

enum TextColor {
    TEXTCOLOR_TOP = 0,
    TEXTCOLOR_BOTTOM = 1,

    TEXTCOLOR_MAX = 2,
};

namespace res
{

struct TextBox {
    SIZE_ASSERT(0x74);

    static constexpr char SIGNATURE[4] = {'t', 'x', 't', '1'};

    /* 0x00 */ Pane pane;
    /* 0x4C */ u16 textBufBytes;
    /* 0x4E */ u16 textStrBytes;
    /* 0x50 */ u16 materialIdx;
    /* 0x52 */ u16 fontIdx;
    /* 0x54 */ u8 textPosition;
    /* 0x55 */ u8 textAlignment;
    /* 0x56 */ FILL(0x56, 0X58) = {};
    /* 0x58 */ u32 textStrOffset;
    /* 0x5C */ nw4r::ut::Color textCols[TEXTCOLOR_MAX];
    /* 0x64 */ Size fontSize;
    /* 0x6C */ f32 charSpace;
    /* 0x70 */ f32 lineSpace;
};

} // namespace res

class TextBox : public Pane
{
    SIZE_ASSERT(0x104);

public:
    [[address(0x802ADFE0)]]
    TextBox(res::TextBox* res, ResBlockSet& resBlockSet);

    [[address(0x802AE2D0)]]
    ~TextBox();

    [[address(0x802AF000)]]
    u16 SetString(const wchar_t* pStr, u16 pos);

    ut::Color GetTextColor(u32 idx) const
    {
        return mTextColors[idx];
    }

    void SetTextColor(u32 idx, ut::Color color)
    {
        mTextColors[idx] = color;
    }

    /* 0x0D8 */ wchar_t* mTextBuf;
    /* 0x0DC */ ut::Color mTextColors[TEXTCOLOR_MAX];

    FILL(0x0E4, 0x104);
};

}; // namespace nw4r::lyt