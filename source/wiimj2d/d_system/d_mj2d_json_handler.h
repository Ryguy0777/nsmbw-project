#pragma once

#include "d_mj2d_game.h"
#include "d_mj2d_header.h"
#include <cstdint>
#include <cstdio>
#include <variant>

class dMj2dJsonHandler_c
{
private:
    // ----------------
    // Member Functions
    // ----------------

    bool expectValue()
    {
        if (mValueCount == 0 ||
            mFlags & (UNKNOWN_OBJECT | EXPECT_ARRAY_START | EXPECT_OBJECT_START | JSON_END)) {
            return false;
        }

        mValueCount--;
        return true;
    }

public:
    bool Null() const
    {
        return mFlags & UNKNOWN_OBJECT;
    }

    bool Bool(bool value)
    {
        return Uint(value);
    }

    bool Int(int value)
    {
        return Uint(value);
    }

    bool Uint(unsigned int value);

    bool Int64(std::int64_t value) const
    {
        return mFlags & UNKNOWN_OBJECT;
    }

    bool Uint64(std::uint64_t value) const
    {
        return mFlags & UNKNOWN_OBJECT;
    }

    bool RawNumber(const char* str, std::size_t length, bool copy) const
    {
        return mFlags & UNKNOWN_OBJECT;
    }

    bool Double(double value) const
    {
        return mFlags & UNKNOWN_OBJECT;
    }

    bool String(const char* str, std::size_t length, bool copy);

    bool Key(const char* str, std::size_t length, bool copy);

    bool StartObject();
    bool EndObject(std::size_t memberCount);

    bool StartArray();
    bool EndArray(std::size_t elementCount);

private:
    // -------------------
    // Constants and Types
    // -------------------

    enum Flag_e {
        UNKNOWN_OBJECT = 1 << 0,
        EXPECT_ARRAY_START = 1 << 1,
        EXPECT_ARRAY_END = 1 << 2,
        EXPECT_OBJECT_START = 1 << 3,
        TEMP_SAVE = 1 << 4,
        BIT_FLAGS_LE = 1 << 5,
        JSON_END = 1 << 6,
        SUBTRACT_1 = 1 << 7,
    };

    enum class Object_e {
        BASE,
        FILE,
        STOCK_ITEM,
        PLAYER_KEY,
        PLAYER,
        WORLD_KEY,
        WORLD,
        ENEMY_KEY,
        ENEMY,
        COURSE_KEY,
        COURSE,
        HINT_MOVIE_ARRAY,
        STAR_COIN_ARRAY,
        PLAY_COUNT_ARRAY,
    };

private:
    // -----------
    // Member Data
    // -----------

    u8 mFlags = EXPECT_OBJECT_START;
    Object_e mObject = Object_e::BASE;
    std::size_t mUnknownNest = 0;

    std::variant<
      s8*, u8*, u16*, u32*, bool*, dMj2dGame_c::Revision_s*, dMj2dGame_c::GAME_COMPLETION_e*,
      dMj2dGame_c::START_KINOKO_KIND_e*, dMj2dGame_c::PLAYER_CREATE_ITEM_u8_e*,
      dMj2dGame_c::PLAYER_MODE_u8_e*, dMj2dGame_c::PLAYER_TYPE_u8_e*, STAGE_e*,
      dMj2dGame_c::WORLD_COMPLETION_e*, PATH_DIRECTION_e*, dMj2dGame_c::COURSE_COMPLETION_e*,
      cBitmask_c<HINT_MOVIE_COUNT>*>
      mpValue;
    std::size_t mValueCount = 0;

    s8 mSaveSlot = -1;
    PLAYER_TYPE_e mPlayer = PLAYER_TYPE_e::COUNT;
    WORLD_e mWorld = WORLD_e::COUNT;
    STAGE_e mCourse = STAGE_e::COUNT;
    u8 mWmEnemy = AMBUSH_ENEMY_COUNT;

public:
    // ----------------
    // Static Functions
    // ----------------

    static bool writeJSON(std::FILE* f);
};