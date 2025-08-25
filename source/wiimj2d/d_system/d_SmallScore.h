#pragma once

#include "d_system/d_lyttextbox.h"

class dSmallScore_c
{
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x80015200 */
    void setPlayer1upColor(int player);

    /* 0x80015210 */
    void setPlayer1000Color(int player);

    /* 0x800153B0 */
    void setPlayer100Color(int player);

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x000, 0x1D8);

    /* 0x1D8 */ LytTextBox_c* mTxt100;
    /* 0x1DC */ LytTextBox_c* mTxt1000;

    FILL(0x1E0, 0x1E4);

    /* 0x1E4 */ LytTextBox_c* mTxt1up;
};