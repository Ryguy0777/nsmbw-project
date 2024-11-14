// Four.cpp
// Patches for various parts of the game for >4 players, that I did not feel like splitting and
// importing whole functions into the project.

#include "Four.h"

#include <cstring>
#include <dynamic/actor/bases/d_a_player_manager.h>
#include <revolution/os.h>

struct FourPatch {
    u32 address;
    u8 size;
    s8 offset;
};

constinit FourPatch FOUR_PATCH_LIST[] = {
  // daEnDpakkunBase_c::hitCallback_Fire
  {0x8002D514 + 2, 2, -1},
  // daEnDpakkunBase_c::hitCallback_YoshiFire
  {0x8002D694 + 2, 2, -1},
  // daEnDpakkunBase_c::hitCallback_Star
  {0x8002D8F0 + 2, 2, -1},
  // daEnDpakkunBase_c::hitCallback_Shell
  {0x8002D9F8 + 2, 2, -1},
  // daEnDpakkunBase_c::kill
  {0x8002DB54 + 2, 2, -1},
  // daEnDpakkunBase_c::initializeState_DieIceBreak
  {0x8002E3D0 + 2, 2, -1},

  // dfukidashiManager_c::FUN_801572F0
  {0x801572FC + 2, 2},

  // daObjKinoko_c
  {0x8087F808 + 2, 2},
  {0x8087F850 + 2, 2},

  // daEnGlpole_c::checkPlayerCollision
  {0x80A0B298 + 2, 2},
  {0x80A0B3EC + 2, 2},
  {0x80A0AFE4 + 2, 2},
  {0x80A0B0D0 + 2, 2},

  // Unknown
  {0x80A39728 + 2, 2, -1},

  // daLiftSpinRotation_c
  // TODO: 8084cdf0
};

void Four::Apply()
{
    for (const FourPatch& patch : FOUR_PATCH_LIST) {
        u32 address = patch.address;
        u8 size = patch.size;
        u8 offset = patch.offset;

        ASSERT(size <= 4);
        u32 newValue = PLAYER_COUNT + patch.offset;
        std::memcpy(
          reinterpret_cast<void*>(address), reinterpret_cast<u8*>(&newValue) + (4 - size), size
        );

        DCStoreRange(reinterpret_cast<void*>(address), size);
        ICInvalidateRange(reinterpret_cast<void*>(address), size);
    }
}