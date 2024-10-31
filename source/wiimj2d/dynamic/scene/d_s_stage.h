#pragma once

#include <dynamic/d_fader.h>
#include <dynamic/d_mj2d_game.h>
#include <framework/f_base_profile.h>

class dScStage_c
{
public:
    // ----------------
    // Static Functions
    // ----------------

    /* 0x8005EC90 */
    static bool getCourseIn()
    {
        return m_isCourseIn;
    }

    /* 0x80101AA0 */
    static void setLoopType();

    /* 0x80102370 @unofficial */
    static void
    goToSceneAfterLevel(int profile, int param2, int param3, dFader_c::fader_type_e faderType);

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A4A8 */
    static dScStage_c* m_instance;

    /* 0x8042A4FC */
    static bool m_isCourseIn;

    /* 0x8042A4FD */
    static bool m_isCourseOut;

    /* 0x8042A4FE */
    static bool m_isOtehonReturn;

    /* 0x8042A4FF */
    static bool m_isStaffCredit;

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x0000, 0x120C);

    /* 0x120C */ WORLD_e mWorld;
    /* 0x120D */ STAGE_e mStage;
    /* 0x120E */ u8 mCourse; // A.k.a. Area
    /* 0x120F */ u8 mArea; // A.k.a. Zone
    /* 0x1210 */ u8 mLayer;
    /* 0x1211 */ u8 mGoto; // A.k.a Entrance
};