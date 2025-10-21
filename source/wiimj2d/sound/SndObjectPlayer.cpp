// SndObjectPlayer.cpp
// NSMBW .text: 0x8019A0F0 - 0x8019B240

#include "SndObjectPlayer.h"

#include "d_system/d_game_common.h"
#include "framework/f_sound_id.h"
#include <nw4r/snd/SoundHandle.h>

static constexpr u16 PLAYER_VOICE_SOUND_ID_LIST[SndObjctPly::PLAYER_SOUND_INDEX_COUNT]
                                               [SndObjctPly::PLAYER_VOICE_COUNT] = //
  {
    {
      SE_VOC_MA_PLAYER_JOIN,
      SE_VOC_MA_PJ_JUMP,
      SE_VOC_MA_PJ_SPIN_JUMP,
      SE_VOC_MA_PLAYER_DECIDE,
      SE_VOC_MA_CS_FALL_INTO_MAP,
      SE_VOC_MA_CS_COURSE_IN,
      SE_VOC_MA_CS_COURSE_IN_MULTI,
      SE_VOC_MA_CS_COURSE_IN_HARD,
      SE_VOC_MA_CS_COURSE_MISS,
      SE_VOC_MA_CS_JUMP,
      SE_VOC_MA_CS_DECIDE_JOIN,
      SE_VOC_MA_CS_ENCOUNT,
      SE_VOC_MA_CS_SHOVED,
      SE_VOC_MA_CS_CHASE_SHIP,
      SE_VOC_MA_CS_NOTICE_JR,
      SE_VOC_MA_GAME_OVER,
      SE_VOC_MA_CONTINUE,
      SE_VOC_MA_CONTINUE_COURSE,
      SE_VOC_MA_MOTIAGE,
      SE_VOC_MA_NAGERU,
      SE_VOC_MA_MOTIAGE_PLAYER,
      SE_VOC_MA_JUMP_2ND,
      SE_VOC_MA_JUMP_3RD,
      SE_VOC_MA_YOSHI_JUMP,
      SE_VOC_MA_JR_A_BATTLE_APP,
      SE_VOC_MA_WALL_KICK,
      SE_VOC_MA_PRPL_JUMP,
      SE_VOC_MA_PNGN_SLIDE,
      SE_VOC_MA_ROPE_CATCH,
      SE_VOC_MA_ROPE_RELEASE,
      SE_VOC_MA_ROPE_FALL,
      SE_VOC_MA_GOAL_POLE_CATCH,
      SE_VOC_MA_CLIFF_DIVE,
      SE_VOC_MA_CLIFF_UP,
      SE_VOC_MA_CLIFF_DOWN,
      SE_VOC_MA_CANNON_SHOT_S,
      SE_VOC_MA_CANNON_SHOT,
      SE_VOC_MA_BALLOON_HELP,
      SE_VOC_MA_BALLOON_HELP,
      SE_VOC_MA_HUKKATSU,
      SE_VOC_MA_DAMAGE_LAST,
      SE_VOC_MA_DAMAGE_LAST,
      SE_VOC_MA_TIMEUP,
      SE_VOC_MA_TIMEUP_MULTI,
      SE_VOC_MA_SCROLL_OUT,
      SE_VOC_MA_DAMAGE_FIRE,
      SE_VOC_MA_DAMAGE_FREEZE,
      SE_VOC_MA_DAMAGE_POISON,
      SE_VOC_MA_DAMAGE_ELEC,
      SE_VOC_MA_DAMAGE_EATEN,
      SE_VOC_MA_INTO_SANDPILLAR,
      SE_VOC_MA_QUAKE,
      SE_VOC_MA_STOMPED,
      SE_VOC_MA_HIP_ATTACKED,
      SE_VOC_MA_TYUKAN,
      SE_VOC_MA_GET_STAR,
      SE_VOC_MA_ITEM_COMPLETE,
      SE_VOC_MA_CLEAR_NORMAL,
      SE_VOC_MA_CLEAR_ANOTHER,
      SE_VOC_MA_CLEAR_MULTI,
      SE_VOC_MA_CLEAR_HELPED,
      SE_VOC_MA_CLEAR_BOSS,
      SE_VOC_MA_CLEAR_LAST_BOSS,
      SE_VOC_MA_SAVE_PRINCESS,
      SE_VOC_MA_CS_COMPLETE_DEMO,
      SE_VOC_MA_GET_PRIZE,
      SE_VOC_MA_FLOOR_FALL,
      SE_VOC_MA_NOTICE,
      SE_VOC_MA_MISS_PRINCESS,
      SE_MG_IH_MA_ACTIVE_TV,
      SE_MG_IH_MA_ACTIVE_RC,
    },

    {
      SE_VOC_LU_PLAYER_JOIN,
      SE_VOC_LU_PJ_JUMP,
      SE_VOC_LU_PJ_SPIN_JUMP,
      SE_VOC_LU_PLAYER_DECIDE,
      SE_VOC_LU_CS_FALL_INTO_MAP,
      SE_VOC_LU_CS_COURSE_IN,
      SE_VOC_LU_CS_COURSE_IN_MULTI,
      SE_VOC_LU_CS_COURSE_IN_HARD,
      SE_VOC_LU_CS_COURSE_MISS,
      SE_VOC_LU_CS_JUMP,
      SE_VOC_LU_CS_DECIDE_JOIN,
      SE_VOC_LU_CS_ENCOUNT,
      SE_VOC_LU_CS_SHOVED,
      SE_VOC_LU_CS_CHASE_SHIP,
      SE_VOC_LU_CS_NOTICE_JR,
      SE_VOC_LU_GAME_OVER,
      SE_VOC_LU_CONTINUE,
      SE_VOC_LU_CONTINUE_COURSE,
      SE_VOC_LU_MOTIAGE,
      SE_VOC_LU_NAGERU,
      SE_VOC_LU_MOTIAGE_PLAYER,
      SE_VOC_LU_JUMP_2ND,
      SE_VOC_LU_JUMP_3RD,
      SE_VOC_LU_YOSHI_JUMP,
      SE_VOC_LU_JR_A_BATTLE_APP,
      SE_VOC_LU_WALL_KICK,
      SE_VOC_LU_PRPL_JUMP,
      SE_VOC_LU_PNGN_SLIDE,
      SE_VOC_LU_ROPE_CATCH,
      SE_VOC_LU_ROPE_RELEASE,
      SE_VOC_LU_ROPE_FALL,
      SE_VOC_LU_GOAL_POLE_CATCH,
      SE_VOC_LU_CLIFF_DIVE,
      SE_VOC_LU_CLIFF_UP,
      SE_VOC_LU_CLIFF_DOWN,
      SE_VOC_LU_CANNON_SHOT_S,
      SE_VOC_LU_CANNON_SHOT,
      SE_VOC_LU_BALLOON_HELP,
      SE_VOC_LU_BALLOON_HELP,
      SE_VOC_LU_HUKKATSU,
      SE_VOC_LU_DAMAGE_LAST,
      SE_VOC_LU_DAMAGE_LAST,
      SE_VOC_LU_TIMEUP,
      SE_VOC_LU_TIMEUP_MULTI,
      SE_VOC_LU_SCROLL_OUT,
      SE_VOC_LU_DAMAGE_FIRE,
      SE_VOC_LU_DAMAGE_FREEZE,
      SE_VOC_LU_DAMAGE_POISON,
      SE_VOC_LU_DAMAGE_ELEC,
      SE_VOC_LU_DAMAGE_EATEN,
      SE_VOC_LU_INTO_SANDPILLAR,
      SE_VOC_LU_QUAKE,
      SE_VOC_LU_STOMPED,
      SE_VOC_LU_HIP_ATTACKED,
      SE_VOC_LU_TYUKAN,
      SE_VOC_LU_GET_STAR,
      SE_VOC_LU_ITEM_COMPLETE,
      SE_VOC_LU_CLEAR_NORMAL,
      SE_VOC_LU_CLEAR_ANOTHER,
      SE_VOC_LU_CLEAR_MULTI,
      SE_VOC_LU_CLEAR_HELPED,
      SE_VOC_LU_CLEAR_BOSS,
      SE_VOC_LU_CLEAR_LAST_BOSS,
      SE_VOC_LU_SAVE_PRINCESS,
      SE_VOC_LU_CS_COMPLETE_DEMO,
      SE_VOC_LU_GET_PRIZE,
      SE_VOC_LU_FLOOR_FALL,
      SE_VOC_LU_NOTICE,
      SE_VOC_LU_MISS_PRINCESS,
      SE_MG_IH_LU_ACTIVE_TV,
      SE_MG_IH_LU_ACTIVE_RC,
    },

    {
      SE_VOC_KO_PLAYER_JOIN,
      SE_VOC_KO_PJ_JUMP,
      SE_VOC_KO_PJ_SPIN_JUMP,
      SE_VOC_KO_PLAYER_DECIDE,
      SE_VOC_KO_CS_FALL_INTO_MAP,
      SE_VOC_KO_CS_COURSE_IN,
      SE_VOC_KO_CS_COURSE_IN_MULTI,
      SE_VOC_KO_CS_COURSE_IN_HARD,
      SE_VOC_KO_CS_COURSE_MISS,
      SE_VOC_KO_CS_JUMP,
      SE_VOC_KO_CS_DECIDE_JOIN,
      SE_VOC_KO_CS_ENCOUNT,
      SE_VOC_KO_CS_SHOVED,
      SE_VOC_KO_CS_CHASE_SHIP,
      SE_VOC_KO_CS_NOTICE_JR,
      SE_VOC_KO_GAME_OVER,
      SE_VOC_KO_CONTINUE,
      SE_VOC_KO_CONTINUE_COURSE,
      SE_VOC_KO_MOTIAGE,
      SE_VOC_KO_NAGERU,
      SE_VOC_KO_MOTIAGE_PLAYER,
      SE_VOC_KO_JUMP_2ND,
      SE_VOC_KO_JUMP_3RD,
      SE_VOC_KO_YOSHI_JUMP,
      SE_VOC_KO_JR_A_BATTLE_APP,
      SE_VOC_KO_WALL_KICK,
      SE_VOC_KO_PRPL_JUMP,
      SE_VOC_KO_PNGN_SLIDE,
      SE_VOC_KO_ROPE_CATCH,
      SE_VOC_KO_ROPE_RELEASE,
      SE_VOC_KO_ROPE_FALL,
      SE_VOC_KO_GOAL_POLE_CATCH,
      SE_VOC_KO_CLIFF_DIVE,
      SE_VOC_KO_CLIFF_UP,
      SE_VOC_KO_CLIFF_DOWN,
      SE_VOC_KO_CANNON_SHOT_S,
      SE_VOC_KO_CANNON_SHOT,
      SE_VOC_KO_BALLOON_HELP,
      SE_VOC_KO_BALLOON_HELP,
      SE_VOC_KO_HUKKATSU,
      SE_VOC_KO_DAMAGE_LAST,
      SE_VOC_KO_DAMAGE_LAST,
      SE_VOC_KO_TIMEUP,
      SE_VOC_KO_TIMEUP_MULTI,
      SE_VOC_KO_SCROLL_OUT,
      SE_VOC_KO_DAMAGE_FIRE,
      SE_VOC_KO_DAMAGE_FREEZE,
      SE_VOC_KO_DAMAGE_POISON,
      SE_VOC_KO_DAMAGE_ELEC,
      SE_VOC_KO_DAMAGE_EATEN,
      SE_VOC_KO_INTO_SANDPILLAR,
      SE_VOC_KO_QUAKE,
      SE_VOC_KO_STOMPED,
      SE_VOC_KO_HIP_ATTACKED,
      SE_VOC_KO_TYUKAN,
      SE_VOC_KO_GET_STAR,
      SE_VOC_KO_ITEM_COMPLETE,
      SE_VOC_KO_CLEAR_NORMAL,
      SE_VOC_KO_CLEAR_ANOTHER,
      SE_VOC_KO_CLEAR_MULTI,
      SE_VOC_KO_CLEAR_HELPED,
      SE_VOC_KO_CLEAR_BOSS,
      SE_VOC_KO_CLEAR_LAST_BOSS,
      SE_VOC_KO_SAVE_PRINCESS,
      SE_VOC_KO_CS_COMPLETE_DEMO,
      SE_VOC_KO_GET_PRIZE,
      SE_VOC_KO_FLOOR_FALL,
      SE_VOC_KO_NOTICE,
      SE_VOC_KO_MISS_PRINCESS,
      SE_MG_IH_KO_ACTIVE_TV,
      SE_MG_IH_KO_ACTIVE_RC,
    },

    {
      SE_VOC_KO2_PLAYER_JOIN,
      SE_VOC_KO2_PJ_JUMP,
      SE_VOC_KO2_PJ_SPIN_JUMP,
      SE_VOC_KO2_PLAYER_DECIDE,
      SE_VOC_KO2_CS_FALL_INTO_MAP,
      SE_VOC_KO2_CS_COURSE_IN,
      SE_VOC_KO2_CS_COURSE_IN_MULTI,
      SE_VOC_KO2_CS_COURSE_IN_HARD,
      SE_VOC_KO2_CS_COURSE_MISS,
      SE_VOC_KO2_CS_JUMP,
      SE_VOC_KO2_CS_DECIDE_JOIN,
      SE_VOC_KO2_CS_ENCOUNT,
      SE_VOC_KO2_CS_SHOVED,
      SE_VOC_KO2_CS_CHASE_SHIP,
      SE_VOC_KO2_CS_NOTICE_JR,
      SE_VOC_KO2_GAME_OVER,
      SE_VOC_KO2_CONTINUE,
      SE_VOC_KO2_CONTINUE_COURSE,
      SE_VOC_KO2_MOTIAGE,
      SE_VOC_KO2_NAGERU,
      SE_VOC_KO2_MOTIAGE_PLAYER,
      SE_VOC_KO2_JUMP_2ND,
      SE_VOC_KO2_JUMP_3RD,
      SE_VOC_KO2_YOSHI_JUMP,
      SE_VOC_KO2_JR_A_BATTLE_APP,
      SE_VOC_KO2_WALL_KICK,
      SE_VOC_KO2_PRPL_JUMP,
      SE_VOC_KO2_PNGN_SLIDE,
      SE_VOC_KO2_ROPE_CATCH,
      SE_VOC_KO2_ROPE_RELEASE,
      SE_VOC_KO2_ROPE_FALL,
      SE_VOC_KO2_GOAL_POLE_CATCH,
      SE_VOC_KO2_CLIFF_DIVE,
      SE_VOC_KO2_CLIFF_UP,
      SE_VOC_KO2_CLIFF_DOWN,
      SE_VOC_KO2_CANNON_SHOT_S,
      SE_VOC_KO2_CANNON_SHOT,
      SE_VOC_KO2_BALLOON_HELP,
      SE_VOC_KO2_BALLOON_HELP,
      SE_VOC_KO2_HUKKATSU,
      SE_VOC_KO2_DAMAGE_LAST,
      SE_VOC_KO2_DAMAGE_LAST,
      SE_VOC_KO2_TIMEUP,
      SE_VOC_KO2_TIMEUP_MULTI,
      SE_VOC_KO2_SCROLL_OUT,
      SE_VOC_KO2_DAMAGE_FIRE,
      SE_VOC_KO2_DAMAGE_FREEZE,
      SE_VOC_KO2_DAMAGE_POISON,
      SE_VOC_KO2_DAMAGE_ELEC,
      SE_VOC_KO2_DAMAGE_EATEN,
      SE_VOC_KO2_INTO_SANDPILLAR,
      SE_VOC_KO2_QUAKE,
      SE_VOC_KO2_STOMPED,
      SE_VOC_KO2_HIP_ATTACKED,
      SE_VOC_KO2_TYUKAN,
      SE_VOC_KO2_GET_STAR,
      SE_VOC_KO2_ITEM_COMPLETE,
      SE_VOC_KO2_CLEAR_NORMAL,
      SE_VOC_KO2_CLEAR_ANOTHER,
      SE_VOC_KO2_CLEAR_MULTI,
      SE_VOC_KO2_CLEAR_HELPED,
      SE_VOC_KO2_CLEAR_BOSS,
      SE_VOC_KO2_CLEAR_LAST_BOSS,
      SE_VOC_KO2_SAVE_PRINCESS,
      SE_VOC_KO2_CS_COMPLETE_DEMO,
      SE_VOC_KO2_GET_PRIZE,
      SE_VOC_KO2_FLOOR_FALL,
      SE_VOC_KO2_NOTICE,
      SE_VOC_KO2_MISS_PRINCESS,
      SE_MG_IH_KO2_ACTIVE_TV,
      SE_MG_IH_KO2_ACTIVE_RC,
    },

    {
      SE_VOC_KC_PLAYER_JOIN,
      SE_VOC_KC_PJ_JUMP,
      SE_VOC_KC_PJ_SPIN_JUMP,
      SE_VOC_KC_PLAYER_DECIDE,
      SE_VOC_KC_CS_FALL_INTO_MAP,
      SE_VOC_KC_CS_COURSE_IN,
      SE_VOC_KC_CS_COURSE_IN_MULTI,
      SE_VOC_KC_CS_COURSE_IN_HARD,
      SE_VOC_KC_CS_COURSE_MISS,
      SE_VOC_KC_CS_JUMP,
      SE_VOC_KC_CS_DECIDE_JOIN,
      SE_VOC_KC_CS_ENCOUNT,
      SE_VOC_KC_CS_SHOVED,
      SE_VOC_KC_CS_CHASE_SHIP,
      SE_VOC_KC_CS_NOTICE_JR,
      SE_VOC_KC_GAME_OVER,
      SE_VOC_KC_CONTINUE,
      SE_VOC_KC_CONTINUE_COURSE,
      SE_VOC_KC_MOTIAGE,
      SE_VOC_KC_NAGERU,
      SE_VOC_KC_MOTIAGE_PLAYER,
      SE_VOC_KC_JUMP_2ND,
      SE_VOC_KC_JUMP_3RD,
      SE_VOC_KC_YOSHI_JUMP,
      SE_VOC_KC_JR_A_BATTLE_APP,
      SE_VOC_KC_WALL_KICK,
      SE_VOC_KC_PRPL_JUMP,
      SE_VOC_KC_PNGN_SLIDE,
      SE_VOC_KC_ROPE_CATCH,
      SE_VOC_KC_ROPE_RELEASE,
      SE_VOC_KC_ROPE_FALL,
      SE_VOC_KC_GOAL_POLE_CATCH,
      SE_VOC_KC_CLIFF_DIVE,
      SE_VOC_KC_CLIFF_UP,
      SE_VOC_KC_CLIFF_DOWN,
      SE_VOC_KC_CANNON_SHOT_S,
      SE_VOC_KC_CANNON_SHOT,
      SE_VOC_KC_BALLOON_HELP,
      SE_VOC_KC_BALLOON_HELP,
      SE_VOC_KC_HUKKATSU,
      SE_VOC_KC_DAMAGE_LAST,
      SE_VOC_KC_DAMAGE_LAST,
      SE_VOC_KC_TIMEUP,
      SE_VOC_KC_TIMEUP_MULTI,
      SE_VOC_KC_SCROLL_OUT,
      SE_VOC_KC_DAMAGE_FIRE,
      SE_VOC_KC_DAMAGE_FREEZE,
      SE_VOC_KC_DAMAGE_POISON,
      SE_VOC_KC_DAMAGE_ELEC,
      SE_VOC_KC_DAMAGE_EATEN,
      SE_VOC_KC_INTO_SANDPILLAR,
      SE_VOC_KC_QUAKE,
      SE_VOC_KC_STOMPED,
      SE_VOC_KC_HIP_ATTACKED,
      SE_VOC_KC_TYUKAN,
      SE_VOC_KC_GET_STAR,
      SE_VOC_KC_ITEM_COMPLETE,
      SE_VOC_KC_CLEAR_NORMAL,
      SE_VOC_KC_CLEAR_ANOTHER,
      SE_VOC_KC_CLEAR_MULTI,
      SE_VOC_KC_CLEAR_HELPED,
      SE_VOC_KC_CLEAR_BOSS,
      SE_VOC_KC_CLEAR_LAST_BOSS,
      SE_VOC_KC_SAVE_PRINCESS,
      SE_VOC_KC_CS_COMPLETE_DEMO,
      SE_VOC_KC_GET_PRIZE,
      SE_VOC_KC_FLOOR_FALL,
      SE_VOC_KC_NOTICE,
      SE_VOC_KC_MISS_PRINCESS,
      SE_MG_IH_KO2_ACTIVE_TV,
      SE_MG_IH_KO2_ACTIVE_RC,
    },
};

/* VT+0x24 */
[[address(0x8019A0F0)]]
nw4r::snd::SoundHandle* SndObjctPly::startSound(u32 soundId, u32 remoteMask);

/* VT+0x28 */
[[address(0x8019A1E0)]]
nw4r::snd::SoundHandle* SndObjctPly::holdSound(u32 soundId, u32 remoteMask);

/* VT+0x30 */
[[address(0x8019A330)]]
nw4r::snd::SoundHandle* SndObjctPly::startSound(u32 soundId, short seqParam, u32 remoteMask);

/* VT+0x34 */
[[address(0x8019A450)]]
nw4r::snd::SoundHandle* SndObjctPly::holdSound(u32 soundId, short seqParam, u32 remoteMask);

/* VT+0x38 */
[[address(0x8019A5D0)]]
nw4r::snd::SoundHandle*
SndObjctPly::startSound(u32 soundId, const nw4r::math::VEC2& position, u32 remoteMask);

/* VT+0x3C */
[[address(0x8019A6C0)]]
nw4r::snd::SoundHandle*
SndObjctPly::holdSound(u32 soundId, const nw4r::math::VEC2& position, u32 remoteMask);

[[address(0x8019A810)]]
nw4r::snd::SoundHandle* SndObjctPly::startFootSound(u32 soundId, f32 param2, u32 remoteMask);

[[address(0x8019AAB0)]]
nw4r::snd::SoundHandle* SndObjctPly::startVoiceSound(PLAYER_VOICE_e voice, u32 remoteMask)
{
    if (voice >= PLAYER_VOICE_e::COUNT || mPlayerSndIndex >= PLAYER_SOUND_INDEX_e::COUNT) {
        return nullptr;
    }

    PLAYER_SOUND_INDEX_e playerSndIndex = mPlayerSndIndex;

    if (mPlayerSndIndex == PLAYER_SOUND_INDEX_e::KC2) {
        playerSndIndex = PLAYER_SOUND_INDEX_e::KC;
    } else if (mPlayerSndIndex == PLAYER_SOUND_INDEX_e::KO3 ||
               mPlayerSndIndex == PLAYER_SOUND_INDEX_e::KO4) {
        playerSndIndex =
          dGameCom::rndInt(2) == 0 ? PLAYER_SOUND_INDEX_e::KO : PLAYER_SOUND_INDEX_e::KO2;
    }

    u32 sound =
      PLAYER_VOICE_SOUND_ID_LIST[static_cast<int>(playerSndIndex)][static_cast<int>(voice)];

    if (GetPlayingSoundCount(1) >= 1 || VT_0x1C(sound, 1) != 0) {
        return nullptr;
    }

    nw4r::snd::SoundHandle* handle = startSound(sound, remoteMask);

    // Mini mushroom pitch up
    f32 pitch = mSoundPlyMode == 3 ? 1.5f : 1.0f;

    // Pitch changes for additional characters
    if (mPlayerSndIndex == PLAYER_SOUND_INDEX_e::KC2) {
        pitch *= 0.85f;
    } else if (mPlayerSndIndex == PLAYER_SOUND_INDEX_e::KO3) {
        pitch *= 1.15f;
    } else if (mPlayerSndIndex == PLAYER_SOUND_INDEX_e::KO4) {
        pitch *= 0.85f;
    }

    if (handle != nullptr && handle->mpSound != nullptr) {
        handle->mpSound->SetPitch(pitch);
    }

    return handle;
}

[[address(0x8019ABB0)]]
nw4r::snd::SoundHandle* SndObjctPly::holdVoiceSound(PLAYER_VOICE_e voice, u32 remoteMask)
{
    if (voice >= PLAYER_VOICE_e::COUNT || mPlayerSndIndex >= PLAYER_SOUND_INDEX_e::COUNT) {
        return nullptr;
    }

    PLAYER_SOUND_INDEX_e playerSndIndex = mPlayerSndIndex;

    if (mPlayerSndIndex == PLAYER_SOUND_INDEX_e::KC2) {
        playerSndIndex = PLAYER_SOUND_INDEX_e::KC;
    } else if (mPlayerSndIndex == PLAYER_SOUND_INDEX_e::KO3 ||
               mPlayerSndIndex == PLAYER_SOUND_INDEX_e::KO4) {
        playerSndIndex =
          dGameCom::rndInt(2) == 0 ? PLAYER_SOUND_INDEX_e::KO : PLAYER_SOUND_INDEX_e::KO2;
    }

    u32 sound =
      PLAYER_VOICE_SOUND_ID_LIST[static_cast<int>(playerSndIndex)][static_cast<int>(voice)];

    nw4r::snd::SoundHandle* handle = holdSound(sound, remoteMask);

    // Mini mushroom pitch up
    f32 pitch = mSoundPlyMode == 3 ? 1.5f : 1.0f;

    // Pitch changes for additional characters
    if (mPlayerSndIndex == PLAYER_SOUND_INDEX_e::KC2) {
        pitch *= 0.85f;
    } else if (mPlayerSndIndex == PLAYER_SOUND_INDEX_e::KO3) {
        pitch *= 1.15f;
    } else if (mPlayerSndIndex == PLAYER_SOUND_INDEX_e::KO4) {
        pitch *= 0.85f;
    }

    if (handle != nullptr && handle->mpSound != nullptr) {
        handle->mpSound->SetPitch(pitch);
    }

    return handle;
}

SndObjctPly::~SndObjctPly()
{
}
