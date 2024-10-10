#pragma once

class dInfo_c
{
    /* 0x000 VTABLE 0x80315EA0 */
public:
    /* 0x800BB130 */
    virtual ~dInfo_c();

    /* 0x800BB180 */
    void PlayerStateInit();

    FILL(0x004, 0x03C);

    /* 0x03C */ s32 mWorld;
    /* 0x040 */ s32 mLevel;
    /* 0x044 */ s32 mWmNode;

    FILL(0x048, 0x384);

    /* 0x384 */ s32 mPlayerActiveMode[4];

    /* 0x8042A25C */ static dInfo_c* m_instance;
};