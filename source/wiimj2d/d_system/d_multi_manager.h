#pragma once

class dMultiMng_c
{
public:
    // ---------
    // Functions
    // ---------

    /* 0x800CE950 */
    void initStage();

    /* 0x800CEAC0 */
    void incCoin(int player);

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A290 */
    static dMultiMng_c* mspInstance;
};