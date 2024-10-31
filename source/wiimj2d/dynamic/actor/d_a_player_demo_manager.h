#pragma once

class daPyDemoMng_c
{
public:
    // ------------
    // Constructors
    // ------------

    /* 0x8005B3A0 */
    daPyDemoMng_c();

    /* VT+0x8 0x8005B3E0 */
    virtual ~daPyDemoMng_c();

public:
    // ---------
    // Functions
    // ---------

    /* 0x8005B430 */
    void initStage();

    /* 0x8005B4A0 */
    void init();

public:
    // -----------
    // Static Data
    // -----------

    /* 0x80429F74 */ static daPyDemoMng_c* mspInstance;
};