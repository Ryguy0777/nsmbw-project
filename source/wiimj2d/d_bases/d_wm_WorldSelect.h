#pragma once

class daWmIsland_c;

class dWorldSelect_c
{
public:
    // -----------
    // Member Data
    // -----------

    FILL(0x000, 0x248);

    /* 0x248 */ daWmIsland_c* mpaIsland[9];
};