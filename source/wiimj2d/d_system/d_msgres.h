#pragma once

namespace EGG
{
class Heap;
}

class MsgRes_c
{
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x800CE7F0 */
    void MsgRes_c(const void*, EGG::Heap*);

    /* 0x800CE830 */
    void ~MsgRes_c();

    /* 0x800CE890 */
    void getScale(u32, u32);

    /* 0x800CE8C0 */
    void getFont(u32, u32);
};
