// d_a_wm_player.cpp
// NSMBW d_bases.text: 0x80902790 - 0x8090D220

#include "d_a_wm_player.h"

#include "d_bases/d_a_wm_KinoBalloon.h"
#include "d_bases/d_a_wm_SubPlayer.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_wm_lib.h"
#include "framework/f_base_profile.h"
#include "machine/m_pad.h"
#include <revolution/os.h>

/* 0x809A0DB8 */
u32 daWmPlayer_c::m_activeCharaFlag[SUBPLAYER_COUNT];

[[address(0x809027C0)]]
daWmPlayer_c::daWmPlayer_c()
  : dWmPlayerBase_c()
  , mModelManager(dPyMdlMng_c::ModelType_e::MODEL_NONE)
  , m0x1F0(mVec3_c::Zero)
  , m0x23C(6)
  , m0x240(6)
  , m0x25A(0)
  , m0x25B(0)
  , m0x27C(0)
  , m0x298(1.0)
  , m0x2E0(2)
  , m0x2FC(0)
{
    ms_instance = this;
    mp0x29C = nullptr;
}

[[address(0x80902890)]]
daWmPlayer_c::~daWmPlayer_c()
{
    ms_instance = nullptr;

    // This object doesn't belong to this class, so null it so it doesn't get deleted
    mModelManager.mModel = nullptr;

    if (mp0x29C != nullptr) {
        delete mp0x29C;
    }
}

/**
 * VT+0x08
 * do method for the create operation.
 */
[[address(0x80902960)]]
fBase_c::PACK_RESULT_e daWmPlayer_c::create()
{
    mAngle.y = 0;

    mPad::setCurrentChannel(mPad::CH_e::CHAN_0);

    // TODO: Support continues for players 5+. For now, just set their lives to 5 here
    for (int i = 4; i < PLAYER_COUNT; i++) {
        if (daPyMng_c::mRest[i] == 0) {
            daPyMng_c::mRest[i] = 5;
        }
    }

    UNDEF_80903930();

    mModelManager.mModel = nullptr;

    // Create subplayer models
    createSubPlayers();

    ASSERT(mModelManager.mModel != nullptr);

    // Some shadow related thing maybe?
    UNDEF_80906FE0(0, -1);
    UNDEF_800F6820("character_SV", "g3d/model.brres", "character_SV", 1);
    mVisible = true;

    UNDEF_80903380();
    UNDEF_80903ED0();
    UNDEF_80902C50();
    UNDEF_80907590();

    return fBase_c::PACK_RESULT_e::SUCCEEDED;
}

/**
 * VT+0x20
 * do method for the execute operation.
 */
[[address(0x809029E0)]]
fBase_c::PACK_RESULT_e daWmPlayer_c::execute();

/**
 * VT+0x2C
 * do method for the draw operation.
 */
[[address(0x80902AC0)]]
fBase_c::PACK_RESULT_e daWmPlayer_c::draw();

/**
 * VT+0x14
 * do method for the delete operation. This method was renamed due to conflict with the delete
 * C++ keyword.
 */
[[address(0x80902B30)]]
fBase_c::PACK_RESULT_e daWmPlayer_c::doDelete();

[[address(0x80902BD0)]]
void daWmPlayer_c::createSubPlayers()
{
    mPrevPlayer = nullptr;
    dWmPlayerBase_c* prevPlayer = this;

    for (u32 i = 0; i < SUBPLAYER_COUNT; i++) {
        daWmSubPlayer_c* player = reinterpret_cast<daWmSubPlayer_c*>(
          dWmActor_c::construct(+fBaseProfile_e::WM_SUBPLAYER, this, i)
        );

        prevPlayer->mNextPlayer = player;
        player->mPrevPlayer = prevPlayer;

        prevPlayer = player;

        // Set player 1's model if this is player 1's character
        daPyMng_c::PlayerType_e character = daPyMng_c::DEFAULT_PLAYER_ORDER[i % PLAYER_COUNT];
        if (character == daPyMng_c::mPlayerType[0]) {
            mModelManager.mModel = player->mModelManager->mModel;
        }
    }

    prevPlayer->mNextPlayer = nullptr;
}

[[address(0x80902CA0)]]
void daWmPlayer_c::updateActivePlayers()
{
    bool singleEntry = dWmLib::IsSingleEntry();

    for (u32 i = 0; i < PLAYER_COUNT; i++) {
        setPlayerActive(i, false, false);
        daPyMng_c::mPlayerEntry[0] = 0;
    }

    daPyMng_c::mPlayerEntry[0] = 1;
    dInfo_c* info = dInfo_c::m_instance;

    for (u32 i = 0; i < PLAYER_COUNT; i++) {
        bool active = i < 4 ? info->mPlayerActiveMode[i] : info->mExPlayerActiveMode[i - 4];
        if (active) {
            daPyMng_c::mPlayerEntry[i] = 1;
            if (m_activeCharaFlag[i] == 3) {
                setPlayerActive(i, i != 0, false);
            } else {
                setPlayerActive(i, i != 0, true);
            }
        }
    }

    if (singleEntry != dWmLib::IsSingleEntry()) {
        if (singleEntry) {
            daWmKinoBalloon_c::balloonRemove();
        } else {
            dWmLib::RestoreKinopioHelpGameInfo();
            daWmKinoBalloon_c::balloonAppear();
        }
    }

    for (u32 i = 0; i < PLAYER_COUNT; i++) {
        m_activeCharaFlag[static_cast<u32>(daPyMng_c::mPlayerType[i])] =
          info->getPlayerActiveMode(i);
    }

    for (daWmSubPlayer_c* player = static_cast<daWmSubPlayer_c*>(mNextPlayer); player != nullptr;
         player = static_cast<daWmSubPlayer_c*>(player->mNextPlayer)) {
        player->mp0x294 = &dWmLib::sc_0x8031D6B4;
    }
}

[[address(0x80902E30)]]
void daWmPlayer_c::setPlayerActive(u32 id, bool param2, bool param3);

[[address(0x80907A60)]]
daWmPlayer_c::PATH_DIR_e daWmPlayer_c::getMovementDirection();

/* VT+0x60 0x80909940 */
[[address(0x80909940)]]
void daWmPlayer_c::VT_0x60();

[[address(0x809093D0)]]
void daWmPlayer_c::initActiveCharaFlags()
{
    dInfo_c* info = dInfo_c::m_instance;

    for (u32 i = 0; i < SUBPLAYER_COUNT; i++) {
        s32 flag = i < 4 ? info->mPlayerActiveMode[i] : info->mExPlayerActiveMode[i - 4];
        m_activeCharaFlag[s32(daPyMng_c::mPlayerType[i]) % SUBPLAYER_COUNT] = flag == 3 ? 3 : 0;
    }
}

/**
 * VT+0x70
 */
[[address(0x8090BE30)]]
void daWmPlayer_c::VT_0x70();

/**
 * VT+0x74
 */
[[address(0x8090C160)]]
void daWmPlayer_c::VT_0x74();

/**
 * VT+0x80
 */
[[address(0x8090C8C0)]]
void daWmPlayer_c::VT_0x80();

/**
 * VT+0x78
 */
[[address(0x8090C8E0)]]
void daWmPlayer_c::VT_0x78();

/**
 * VT+0x7C
 */
[[address(0x8090C940)]]
void daWmPlayer_c::procDemoLose();

[[address(0x8090CE10)]]
bool daWmPlayer_c::startGame(WORLD_e world, STAGE_e stage, u8 entrance) ASM_METHOD(
  // clang-format off
/* 8090CE10 9421FFA0 */  stwu     r1, -96(r1);
/* 8090CE14 7C0802A6 */  mflr     r0;
/* 8090CE18 90010064 */  stw      r0, 100(r1);
/* 8090CE1C 39610060 */  addi     r11, r1, 96;
/* 8090CE20 4B9D0225 */  bl       UNDEF_802dd044;
/* 8090CE24 3CE08043 */  lis      r7, m_instance__7dInfo_c@ha;
/* 8090CE28 3D00809A */  lis      r8, UNDEF_809a2370@ha;
/* 8090CE2C 83E7A25C */  lwz      r31, m_instance__7dInfo_c@l(r7);
/* 8090CE30 3EE08035 */  lis      r23, mPlayerEntry__9daPyMng_c@ha;
/* 8090CE34 3EC08035 */  lis      r22, mPlayerType__9daPyMng_c@ha;
/* 8090CE38 3F408035 */  lis      r26, mPlayerMode__9daPyMng_c@ha;
/* 8090CE3C 82A82370 */  lwz      r21, UNDEF_809a2370@l(r8);
/* 8090CE40 7C731B78 */  mr       r19, r3;
/* 8090CE44 7C9C2378 */  mr       r28, r4;
/* 8090CE48 7CBD2B78 */  mr       r29, r5;
/* 8090CE4C 7CDE3378 */  mr       r30, r6;
/* 8090CE50 7FF8FB78 */  mr       r24, r31;
/* 8090CE54 3AF75150 */  addi     r23, r23, mPlayerEntry__9daPyMng_c@l;
/* 8090CE58 3AD65160 */  addi     r22, r22, mPlayerType__9daPyMng_c@l;
/* 8090CE5C 3B5A5170 */  addi     r26, r26, mPlayerMode__9daPyMng_c@l;
/* 8090CE60 3A800000 */  li       r20, 0;
/* 8090CE64 3B200001 */  li       r25, 1;
/* 8090CE68 3B600000 */  li       r27, 0;
UNDEF_8090ce6c:;
                         cmpwi    r20, 4;
                         bne      daWmPlayer_c_startGame_NoPtrIncrement;
                         addi     r24, r24, OFFSET_dInfo_c_mExPlayerActiveMode - 0x384 - (4 * 0x4);
daWmPlayer_c_startGame_NoPtrIncrement:;
/* 8090CE6C 80180384 */  lwz      r0, 0x384(r24);
/* 8090CE70 2C000003 */  cmpwi    r0, 3;
/* 8090CE74 40820024 */  bne-     UNDEF_8090ce98;
/* 8090CE78 93370000 */  stw      r25, 0(r23);
/* 8090CE7C 7EA3AB78 */  mr       r3, r21;
/* 8090CE80 7E84A378 */  mr       r4, r20;
/* 8090CE84 4802435D */  bl       UNDEF_809311e0;
/* 8090CE88 80160000 */  lwz      r0, 0(r22);
/* 8090CE8C 5400103A */  slwi     r0, r0, 2;
/* 8090CE90 7C7A012E */  stwx     r3, r26, r0;
/* 8090CE94 48000008 */  b        UNDEF_8090ce9c;
UNDEF_8090ce98:;
/* 8090CE98 93770000 */  stw      r27, 0(r23);
UNDEF_8090ce9c:;
/* 8090CE9C 3A940001 */  addi     r20, r20, 1;
/* 8090CEA0 3AF70004 */  addi     r23, r23, 4;
/* 8090CEA4 2C140004 */  cmpwi    r20, PLAYER_COUNT;
/* 8090CEA8 3AD60004 */  addi     r22, r22, 4;
/* 8090CEAC 3B180004 */  addi     r24, r24, 4;
/* 8090CEB0 4180FFBC */  blt+     UNDEF_8090ce6c;
/* 8090CEB4 7E639B78 */  mr       r3, r19;
/* 8090CEB8 4BFFA6D9 */  bl       UNDEF_80907590;
/* 8090CEBC 939F0050 */  stw      r28, 80(r31);
/* 8090CEC0 38000000 */  li       r0, 0;
/* 8090CEC4 93BF0054 */  stw      r29, 84(r31);
/* 8090CEC8 981F006D */  stb      r0, 109(r31);
/* 8090CECC 9B810009 */  stb      r28, 9(r1);
/* 8090CED0 9BA10008 */  stb      r29, 8(r1);
/* 8090CED4 4B7EFBFD */  bl       UNDEF_800fcad0;
/* 8090CED8 2C030000 */  cmpwi    r3, 0;
/* 8090CEDC 40820030 */  bne-     UNDEF_8090cf0c;
/* 8090CEE0 3CA08043 */  lis      r5, m_instance__7dInfo_c@ha;
/* 8090CEE4 88010009 */  lbz      r0, 9(r1);
/* 8090CEE8 8065A25C */  lwz      r3, m_instance__7dInfo_c@l(r5);
/* 8090CEEC 38C00001 */  li       r6, 1;
/* 8090CEF0 3880002A */  li       r4, 42;
/* 8090CEF4 7C630214 */  add      r3, r3, r0;
/* 8090CEF8 98C303A9 */  stb      r6, 937(r3);
/* 8090CEFC 8065A25C */  lwz      r3, m_instance__7dInfo_c@l(r5);
/* 8090CF00 88010009 */  lbz      r0, 9(r1);
/* 8090CF04 7C630214 */  add      r3, r3, r0;
/* 8090CF08 98830395 */  stb      r4, 917(r3);
UNDEF_8090cf0c:;
/* 8090CF0C 7F83E378 */  mr       r3, r28;
/* 8090CF10 7FA4EB78 */  mr       r4, r29;
/* 8090CF14 38A10009 */  addi     r5, r1, 9;
/* 8090CF18 38C10008 */  addi     r6, r1, 8;
/* 8090CF1C 4B7F0315 */  bl       UNDEF_800fd230;
/* 8090CF20 88610009 */  lbz      r3, 9(r1);
/* 8090CF24 38800000 */  li       r4, 0;
/* 8090CF28 88010008 */  lbz      r0, 8(r1);
/* 8090CF2C 90810018 */  stw      r4, 24(r1);
/* 8090CF30 98810017 */  stb      r4, 23(r1);
/* 8090CF34 98810016 */  stb      r4, 22(r1);
/* 8090CF38 9BC10015 */  stb      r30, 21(r1);
/* 8090CF3C 9B81001C */  stb      r28, 28(r1);
/* 8090CF40 9BA1001D */  stb      r29, 29(r1);
/* 8090CF44 9861001E */  stb      r3, 30(r1);
/* 8090CF48 9801001F */  stb      r0, 31(r1);
/* 8090CF4C 4801B645 */  bl       UNDEF_80928590;
/* 8090CF50 7FE3FB78 */  mr       r3, r31;
/* 8090CF54 38810010 */  addi     r4, r1, 16;
/* 8090CF58 4B7AE879 */  bl       UNDEF_800bb7d0;
/* 8090CF5C 39610060 */  addi     r11, r1, 96;
/* 8090CF60 38600001 */  li       r3, 1;
/* 8090CF64 4B9D012D */  bl       UNDEF_802dd090;
/* 8090CF68 80010064 */  lwz      r0, 100(r1);
/* 8090CF6C 7C0803A6 */  mtlr     r0;
/* 8090CF70 38210060 */  addi     r1, r1, 96;
/* 8090CF74 4E800020 */  blr;
  // clang-format on
);