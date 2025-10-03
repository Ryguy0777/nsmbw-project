#pragma once

class mVec3_c;

class dSmallScoreManager_c
{
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x8010CFC0 */
    void CreateBlueNumber(const mVec3_c& pos, int, int);

    /* 0x8010CFE0 */
    void CreateRedNumber(const mVec3_c& pos, int);

    /* 0x8010D000 */
    void CreateSmallScore(const mVec3_c& pos, int type, int color);

    /* 0x8010D0B0 */
    void CreateGoalScore(const mVec3_c& pos, int type, int color);

    /* 0x8010D160 */
    void GoalScoreExecute(const mVec3_c& pos, int);

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A5B0 */ static dSmallScoreManager_c* m_instance;
};
