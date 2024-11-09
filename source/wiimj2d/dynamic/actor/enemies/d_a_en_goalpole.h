#pragma once

class daEnGlpole_c
{
public:
    /* 0x80A0B020 */
    bool isAllPlayerOnPole();

    FILL(0x000, 0xAAC);

    /* 0x0AAC */ u8 mPlayerOnPoleFlag;
};