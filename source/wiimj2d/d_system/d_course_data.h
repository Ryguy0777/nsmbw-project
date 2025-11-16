#pragma once

class dCdFile_c
{
public:
    // Structors
    // ^^^^^^

    dCdFile_c();

    /* VT+0x8 */
    virtual ~dCdFile_c();

public:
    // Constants and Types
    // ^^^^^^

    // @unofficial
    struct CourseInfo_s {
        SIZE_ASSERT(0x14);

        FILL(0x00, 0x11);

        /* 0x11 */ bool mIsAmbush;

        FILL(0x12, 0x14);
    };

public:
    // Instance Variables
    // ^^^^^^

    /* 0x004 */ u8 mCourseID;
    /* 0x008 */ void* mpPaletteList;
    /* 0x00C */ CourseInfo_s* mpCourseInfo;
};

class dCd_c
{
public:
    // Static Methods
    // ^^^^^^

    /* 0x8005EE70 */
    static dCdFile_c* getFileP(int course);
};
