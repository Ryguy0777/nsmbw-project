#pragma once

namespace EGG {

class StateGX {
public:
    // ----------------
    // Static Functions
    // ----------------

    [[address(0x802D34F0)]]
    static void GXSetViewport_(f32, f32, f32, f32, f32, f32);
};

}