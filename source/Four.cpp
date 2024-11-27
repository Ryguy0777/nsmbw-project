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
  // daBullet_c::hitCallback
  {0x8001DE5C + 2, 2},

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

  // daEnJimenPakkunBase_c::hitCallback_Fire
  {0x8002FB04 + 2, 2, -1},
  // daEnJimenPakkunBase_c::hitCallback_Shell
  {0x8002FC68 + 2, 2, -1},
  // daEnJimenPakkunBase_c::hitCallback_Star
  {0x8002FE04 + 2, 2, -1},
  // daEnJimenPakkunBase_c::hitCallback_YoshiFire
  {0x8002FF20 + 2, 2, -1},
  // daEnJimenPakkunBase_c::initializeState_DieOther
  {0x800304A0 + 2, 2, -1},
  // daEnJimenPakkunBase_c::initializeState_DieIceBreak
  {0x8003074C + 2, 2, -1},

  // daEnShell_c::kickSE
  {0x8003A418 + 2, 2, -1},
  // daEnShell_c::hitCallback_Ice
  {0x8003A84C + 2, 2},

  // dActor_c::playKameHitSound
  {0x80065C00 + 2, 2, -1},
  // dActor_c::checkCarried
  {0x80066040 + 2, 2},

  // dEnBossKoopaJrBase_c::setFireDamage
  {0x8009C0BC + 2, 2, -1},
  // dEnBossKoopaJrBase_c::setFireDead
  {0x8009C1B0 + 2, 2, -1},
  // dEnBossKoopaJrBase_c::setStarDamage
  {0x8009C2B0 + 2, 2, -1},
  // dEnBossKoopaJrBase_c::setStarDead
  {0x8009C390 + 2, 2, -1},
  // dEnBossKoopaJrBase_c::setFumiDamage
  {0x8009C490 + 2, 2, -1},
  // dEnBossKoopaJrBase_c::setFumiDead
  {0x8009C570 + 2, 2, -1},

  // dEn_c::hitCallback_YoshiHipAttk
  {0x800A0344 + 2, 2},
  // dEn_c::hitCallback_Ice
  {0x800A0AC4 + 2, 2},

  // dEnTorideKokoopa_c::setFumiDamage
  {0x800A9204 + 2, 2, -1},
  // dEnTorideKokoopa_c::setFumiDead
  {0x800A9320 + 2, 2, -1},
  // dEnTorideKokoopa_c::setFireDamage
  {0x800A94D8 + 2, 2, -1},
  // dEnTorideKokoopa_c::setFireDead
  {0x800A95CC + 2, 2, -1},
  // dEnTorideKokoopa_c::setStarDamage
  {0x800A9794 + 2, 2, -1},
  // dEnTorideKokoopa_c::setStarDead
  {0x800A98B0 + 2, 2, -1},
  // dEnTorideKokoopa_c::setShellDamage
  {0x800A9C80 + 2, 2, -1},
  // dEnTorideKokoopa_c::setShellDead
  {0x800A9D7C + 2, 2, -1},

  // dQuake_c::UNDEF_800d8940
  {0x800D8978 + 2, 2, -1},
  // dQuake_c::UNDEF_800d8a50
  {0x800D8AE8 + 2, 2},
  // dQuake_c::stopQuake
  {0x800D8BC4 + 2, 2},
  // dQuake_c::UNDEF_800d8ca0
  {0x800D8CB0 + 2, 2, -1},
  // dQuake_c::UNDEF_800d8d50
  {0x800D8DB0 + 2, 2},
  // dQuake_c::UNDEF_800d8e20
  {0x800D8EA4 + 2, 2},

  // daIce_c::UNDEF_8011d240
  {0x8011D288 + 2, 2, -1},
  // daIce_c::UNDEF_8011d320
  {0x8011D368 + 2, 2, -1},
  // daIce_c::checkUnderBreak
  {0x8011DEF8 + 2, 2, -1},
  // daIce_c::breakReq
  {0x8011EC7C + 2, 2, -1},

  // dfukidashiManager_c::FUN_801572F0
  {0x801572FC + 2, 2},

  // UNDEF_807d7440
  {0x807d7488 + 2, 2},

  // daChukanPoint_c::FUN_807e2710
  {0x807E27AC + 2, 2},
  {0x807E27C4 + 2, 2, -1},

  // UNDEF_807e2a30
  {0x807E2BC8 + 2, 2},
  {0x807E2BE0 + 2, 2, -1},

  // daFlagObj_c::UNDEF_807eb2d0
  {0x807EB33C + 2, 2},
  // daFlagObj_c::executeState_IfSwichMove
  {0x807EBD9C + 2, 2},
  {0x807EBF54 + 2, 2},
  {0x807EBE70 + 2, 2},
  {0x807EC01C + 2, 2},

  // UNDEF_807f92c0
  {0x807F938C + 2, 2},
  // UNDEF_807f93f0
  {0x807F9508 + 2, 2},

  // UNDEF_80821030
  {0x80821088 + 2, 2},
  {0x808210C0 + 2, 2},
  {0x808210F8 + 2, 2},

  // UNDEF_8082e970
  {0x8082E9B0 + 2, 2},

  // UNDEF_80836e50
  {0x80836F20 + 2, 2},

  // UNDEF_80838970
  {0x808389C8 + 2, 2},
  {0x80838A00 + 2, 2},
  {0x80838A38 + 2, 2},

  // UNDEF_80843940
  {0x808439EC + 2, 2},
  {0x80843AB4 + 2, 2},

  // UNDEF_80843fd0
  {0x80844124 + 2, 2},

  // daObjKinoko_c
  {0x8087F808 + 2, 2},
  {0x8087F850 + 2, 2},

  // daPowBlock_c::UNDEF_80891a70
  {0x80891A9C + 2, 2},

  // daEnGlpole_c::checkPlayerCollision
  {0x80A0B298 + 2, 2},
  {0x80A0B3EC + 2, 2},
  {0x80A0AFE4 + 2, 2},
  {0x80A0B0D0 + 2, 2},

  // UNDEF_80a39660
  {0x80A39728 + 2, 2, -1},
  // UNDEF_80a399b0
  {0x80A39A30 + 2, 2},

  // UNDEF_80a658e0
  {0x80A65958 + 2, 2},
  {0x80A659D8 + 2, 2},

  // daEnPata_c::UNDEF_80a84ca0
  {0x80A84D48 + 2, 2},
  {0x80A84D90 + 2, 2},

  // daEnSanboEl_c::initializeState_FreezeFall
  {0x80AA0EE8 + 2, 2, -1},

  // UNDEF_80aa2e70
  {0x80AA2EB8 + 2, 2},
  // UNDEF_80aa33d0
  {0x80AA3404 + 2, 2, -1},

  // UNDEF_80b50580
  {0x80B50664 + 2, 2},

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