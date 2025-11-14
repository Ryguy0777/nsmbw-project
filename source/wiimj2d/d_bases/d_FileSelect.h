#pragma once

#include "framework/f_base.h"

class dDateFile_c;
class dInfoWindow_c;

class dFileSelect_c : public fBase_c
{
public:
    FILL(0x064, 0x24C);

    /* 0x24C */ dDateFile_c* mpDateFile[SAVE_SLOT_COUNT];
    /* 0x258 */ dInfoWindow_c* mpInfoWindow;
};
