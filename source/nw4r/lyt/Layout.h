#pragma once

#include <nw4r/ut/Rect.h>

namespace nw4r::lyt
{

class Layout
{
public:
    // ------------
    // Constructors
    // ------------

    /* VT+0x08 */
    virtual ~Layout() = 0;

public:
    // ----------------
    // Member Functions
    // ----------------

    [[address(0x802AD660)]]
    nw4r::ut::Rect GetLayoutRect() const;
};

}; // namespace nw4r::lyt