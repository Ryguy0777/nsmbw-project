// Four.cpp
// Patches for various parts of the game for >4 players, that I did not feel like splitting and
// importing whole functions into the project.

#include "Four.h"

#include <cstring>
#include <dynamic/actor/d_a_player_manager.h>
#include <revolution/os.h>

struct FourPatch {
    u32 address;
    u8 size;
    u8 offset;
};

constinit FourPatch FOUR_PATCH_LIST[] = {
  // daEnGlpole_c::checkPlayerCollision
  {0x80A0B29A, 2},
  {0x80A0B3EE, 2},
  {0x80A0AFE6, 2},
  {0x80A0B0D2, 2},
};

void Four::Apply()
{
    for (const FourPatch& patch : FOUR_PATCH_LIST) {
        u32 address = patch.address;
        u8 size = patch.size;
        u8 offset = patch.offset;

        ASSERT(size <= 4);
        u32 newValue = PLAYER_COUNT;
        std::memcpy(
          reinterpret_cast<void*>(address), reinterpret_cast<u8*>(&newValue) + (4 - size), size
        );

        DCStoreRange(reinterpret_cast<void*>(address), size);
        ICInvalidateRange(reinterpret_cast<void*>(address), size);
    }
}