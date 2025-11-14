#pragma once

#include "d_system/d_base.h"

class dCollectionCoinBase_c;
class dCollectionCoinDate_c;
class dModelPlayArrow_c;

class dCollectionCoin_c : public dBase_c
{
public:
    // -----------
    // Member Data
    // -----------

    FILL(0x70, 0x74);

    /* 0x74 */ dCollectionCoinBase_c* mpColCoinBase[2];
    /* 0x7C */ dCollectionCoinDate_c* mpColCoinDate[24];
    /* 0xDC */ dModelPlayArrow_c* mpMdlPlyArrow;
};
