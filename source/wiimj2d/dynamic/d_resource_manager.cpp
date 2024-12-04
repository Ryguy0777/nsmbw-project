// d_resource_manager.cpp
// NSMBW: 0x800DF770 - 0x800DF950
// NSMBW .sbss: 0x8042A318 - 0x8042A31C

#include "d_resource_manager.h"

#include <dynamic/d_system.h>
#include <framework/f_sound_id.h>
#include <machine/m_dvd.h>
#include <machine/m_heap.h>
#include <nw4r/snd/DvdSoundArchive.h>
#include <revolution/os.h>

[[address_data(0x8042A318)]]
dResMng_c* dResMng_c::m_instance;

[[address(0x800DF8C0)]]
void dResMng_c::setRes(const char* dir, const char** files, int count, EGG::Heap* heap);

#if 0
static void addKinopicoSound(u32 newId, u32 copyId, const char* newName)
{
}
#endif

void dResMng_c::loadKinopicoSound()
{
    // Load bank data
    void* bnkData = mDvd::loadToMainRAM(
      "/Sound/BANK_SE_VOC_COURSE_KC.brbnk", nullptr, dSys_c::ms_RootHeapMem2,
      EGG::DvdRipper::EAllocDirection::ALLOC_DIR_TOP, 0, nullptr, nullptr, 0
    );
    ASSERT(bnkData != nullptr);

    void* waveData = mDvd::loadToMainRAM(
      "/Sound/GROUP_SE_VOC_COURSE_KC.brwar", nullptr, dSys_c::ms_RootHeapMem2,
      EGG::DvdRipper::EAllocDirection::ALLOC_DIR_TOP, 0, nullptr, nullptr, 0
    );
    ASSERT(waveData != nullptr);

    u32 bankNo = nw4r::snd::DvdSoundArchive::RegisterTmpFile(bnkData, waveData);

#if 0

#  define _ADD_KC_SOUND(_NEW_SOUND_ID, _OLD_SOUND_ID)                                              \
      addKinopicoSound(_NEW_SOUND_ID, _OLD_SOUND_ID, #_NEW_SOUND_ID)
#  define ADD_KC_SOUND(_SOUND_ID) _ADD_KC_SOUND(SE_VOC_KC_##_SOUND_ID, SE_VOC_KO2_##_SOUND_ID)

    ADD_KC_SOUND(PLAYER_JOIN);
    ADD_KC_SOUND(PLAYER_JOIN_MAME);
    ADD_KC_SOUND(PJ_JUMP);
    ADD_KC_SOUND(PJ_JUMP_MAME);
    ADD_KC_SOUND(PJ_SPIN_JUMP);
    ADD_KC_SOUND(PJ_SPIN_JUMP_MAME);
    ADD_KC_SOUND(PLAYER_DECIDE);
    ADD_KC_SOUND(CS_FALL_INTO_MAP);
    ADD_KC_SOUND(CS_COURSE_IN);
    ADD_KC_SOUND(CS_COURSE_IN_MULTI);
    ADD_KC_SOUND(CS_COURSE_IN_HARD);
    ADD_KC_SOUND(CS_COURSE_MISS);
    ADD_KC_SOUND(CS_JUMP);
    ADD_KC_SOUND(CS_DECIDE_JOIN);
    ADD_KC_SOUND(CS_ENCOUNT);
    ADD_KC_SOUND(CS_SHOVED);
    ADD_KC_SOUND(CS_CHASE_SHIP);
    ADD_KC_SOUND(CS_NOTICE_JR);
    ADD_KC_SOUND(GAME_OVER);
    ADD_KC_SOUND(CONTINUE);
    ADD_KC_SOUND(CONTINUE_COURSE);
    ADD_KC_SOUND(MOTIAGE);
    ADD_KC_SOUND(NAGERU);
    ADD_KC_SOUND(MOTIAGE_PLAYER);
    ADD_KC_SOUND(JUMP_2ND);
    ADD_KC_SOUND(JUMP_3RD);
    ADD_KC_SOUND(YOSHI_JUMP);
    ADD_KC_SOUND(JR_A_BATTLE_APP);
    ADD_KC_SOUND(WALL_KICK);
    ADD_KC_SOUND(PRPL_JUMP);
    ADD_KC_SOUND(PNGN_SLIDE);
    ADD_KC_SOUND(ROPE_CATCH);
    ADD_KC_SOUND(ROPE_FALL);
    ADD_KC_SOUND(ROPE_RELEASE);
    ADD_KC_SOUND(GOAL_POLE_CATCH);
    ADD_KC_SOUND(CLIFF_DIVE);
    ADD_KC_SOUND(CLIFF_UP);
    ADD_KC_SOUND(CLIFF_DOWN);
    ADD_KC_SOUND(CANNON_SHOT_S);
    ADD_KC_SOUND(CANNON_SHOT);
    ADD_KC_SOUND(BALLOON_HELP);
    ADD_KC_SOUND(HUKKATSU);
    ADD_KC_SOUND(DAMAGE_LAST);
    ADD_KC_SOUND(TIMEUP);
    ADD_KC_SOUND(TIMEUP_MULTI);
    ADD_KC_SOUND(SCROLL_OUT);
    ADD_KC_SOUND(DAMAGE_FIRE);
    ADD_KC_SOUND(DAMAGE_FREEZE);
    ADD_KC_SOUND(DAMAGE_POISON);
    ADD_KC_SOUND(DAMAGE_ELEC);
    ADD_KC_SOUND(DAMAGE_EATEN);
    ADD_KC_SOUND(INTO_SANDPILLAR);
    ADD_KC_SOUND(QUAKE);
    ADD_KC_SOUND(STOMPED);
    ADD_KC_SOUND(HIP_ATTACKED);
    ADD_KC_SOUND(TYUKAN);
    ADD_KC_SOUND(GET_STAR);
    ADD_KC_SOUND(ITEM_COMPLETE);
    ADD_KC_SOUND(CLEAR_NORMAL);
    ADD_KC_SOUND(CLEAR_ANOTHER);
    ADD_KC_SOUND(CLEAR_MULTI);
    ADD_KC_SOUND(CLEAR_HELPED);
    ADD_KC_SOUND(CLEAR_BOSS);
    ADD_KC_SOUND(CLEAR_LAST_BOSS);
    ADD_KC_SOUND(SAVE_PRINCESS);
    ADD_KC_SOUND(CS_COMPLETE_DEMO);
    ADD_KC_SOUND(GET_PRIZE);
    ADD_KC_SOUND(FLOOR_FALL);
    ADD_KC_SOUND(NOTICE);
    ADD_KC_SOUND(MISS_PRINCESS);

#  undef ADD_KC_SOUND
#  undef _ADD_KC_SOUND
#endif
}