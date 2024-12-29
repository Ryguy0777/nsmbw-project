// d_a_wm_player.cpp
// NSMBW d_bases.text: 0x80902790 - 0x8090D220

#include "d_a_wm_player.h"
#include "framework/f_base.h"

#include <dynamic/d_a_player_manager.h>
#include <dynamic/d_bases/d_a_wm_SubPlayer.h>
#include <dynamic/d_info.h>
#include <dynamic/d_mj2d_game.h>
#include <machine/m_pad.h>
#include <revolution/os.h>

EXTERN_DATA(
  0x809A0DB8, //
  u32 daWmPlayer_c::m_activeCharaFlag[4]
);

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

    UNDEF_80903930();

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
        daWmSubPlayer_c* player =
          (daWmSubPlayer_c*) dWmActor_c::construct(0x295, this, i, nullptr, nullptr);

        prevPlayer->mNextPlayer = player;
        player->mPrevPlayer = prevPlayer;

        prevPlayer = player;

        // Set player 1's model if this is player 1's character
        static const daPyMng_c::PlayerType_e l_idTable[] = {
          daPyMng_c::PlayerType_e::MARIO,       daPyMng_c::PlayerType_e::LUIGI,
          daPyMng_c::PlayerType_e::YELLOW_TOAD, daPyMng_c::PlayerType_e::BLUE_TOAD,
          daPyMng_c::PlayerType_e::TOADETTE,
        };
        daPyMng_c::PlayerType_e character = l_idTable[i % 4];
        if (character == daPyMng_c::mPlayerType[0]) {
            mModelManager.mModel = player->mModelManager->mModel;
        }
    }

    prevPlayer->mNextPlayer = nullptr;
}

// TODO: Expand to more than four players
[[address(0x80902CA0)]]
void daWmPlayer_c::updateActivePlayers() ASM_METHOD(
  // clang-format off
/* 80902CA0 9421FFD0 */  stwu     r1, -48(r1);
/* 80902CA4 7C0802A6 */  mflr     r0;
/* 80902CA8 90010034 */  stw      r0, 52(r1);
/* 80902CAC 39610030 */  addi     r11, r1, 48;
/* 80902CB0 4B9DA3A5 */  bl       UNDEF_802dd054;
/* 80902CB4 3C808043 */  lis      r4, m_instance__7dInfo_c@ha;
/* 80902CB8 7C7E1B78 */  mr       r30, r3;
/* 80902CBC 83E4A25C */  lwz      r31, m_instance__7dInfo_c@l(r4);
/* 80902CC0 4B7F9E11 */  bl       UNDEF_800fcad0;
/* 80902CC4 3F008035 */  lis      r24, mPlayerEntry__9daPyMng_c@ha;
/* 80902CC8 7C7B1B78 */  mr       r27, r3;
/* 80902CCC 3B185150 */  addi     r24, r24, mPlayerEntry__9daPyMng_c@l;
/* 80902CD0 3B200000 */  li       r25, 0;
/* 80902CD4 3B800000 */  li       r28, 0;
UNDEF_80902cd8:;
/* 80902CD8 7FC3F378 */  mr       r3, r30;
/* 80902CDC 7F24CB78 */  mr       r4, r25;
/* 80902CE0 38A00000 */  li       r5, 0;
/* 80902CE4 38C00000 */  li       r6, 0;
/* 80902CE8 48000149 */  bl       UNDEF_80902e30;
/* 80902CEC 3B390001 */  addi     r25, r25, 1;
/* 80902CF0 93980000 */  stw      r28, 0(r24);
/* 80902CF4 2C190004 */  cmpwi    r25, 4;
/* 80902CF8 3B180004 */  addi     r24, r24, 4;
/* 80902CFC 4180FFDC */  blt+     UNDEF_80902cd8;
/* 80902D00 3CA08035 */  lis      r5, mPlayerEntry__9daPyMng_c@ha;
/* 80902D04 3C808035 */  lis      r4, mPlayerType__9daPyMng_c@ha;
                         addi     r26, r4, mPlayerType__9daPyMng_c@l;
/* 80902D0C 3B800001 */  li       r28, 1;
                         addi     r24, r5, mPlayerEntry__9daPyMng_c@l;
/* 80902D14 3FA0809A */  lis      r29, UNDEF_809a0db8@ha;
/* 80902D18 93855150 */  stw      r28, mPlayerEntry__9daPyMng_c@l(r5);
                         mr       r25, r31;
/* 80902D28 3BBD0DB8 */  addi     r29, r29, UNDEF_809a0db8@l;
                         li       r23, 0;
UNDEF_80902d30:;
/* 80902D30 80190384 */  lwz      r0, 900(r25);
/* 80902D34 809A0000 */  lwz      r4, 0(r26);
/* 80902D38 2C000003 */  cmpwi    r0, 3;
/* 80902D3C 4082003C */  bne-     UNDEF_80902d78;
/* 80902D40 5480103A */  slwi     r0, r4, 2;
/* 80902D44 93980000 */  stw      r28, 0(r24);
/* 80902D48 7C1D002E */  lwzx     r0, r29, r0;
/* 80902D4C 2C000003 */  cmpwi    r0, 3;
/* 80902D50 41820018 */  beq-     UNDEF_80902d68;
/* 80902D54 7FC3F378 */  mr       r3, r30;
                         //       r5 = r23 != 0
                         subic    r5, r23, 1;
                         subfe    r5, r5, r23;
/* 80902D5C 38C00001 */  li       r6, 1;
/* 80902D60 480000D1 */  bl       UNDEF_80902e30;
/* 80902D64 48000014 */  b        UNDEF_80902d78;
UNDEF_80902d68:;
/* 80902D68 7FC3F378 */  mr       r3, r30;
                         //       r5 = r23 != 0
                         subic    r5, r23, 1;
                         subfe    r5, r5, r23;
/* 80902D70 38C00000 */  li       r6, 0;
/* 80902D74 480000BD */  bl       UNDEF_80902e30;
UNDEF_80902d78:;
/* 80902D78 3AF70001 */  addi     r23, r23, 1;
/* 80902D7C 3B390004 */  addi     r25, r25, 4;
/* 80902D80 2C170004 */  cmpwi    r23, 4;
/* 80902D84 3B180004 */  addi     r24, r24, 4;
/* 80902D88 3B5A0004 */  addi     r26, r26, 4;
/* 80902D8C 4180FFA4 */  blt+     UNDEF_80902d30;
/* 80902D90 4B7F9D41 */  bl       UNDEF_800fcad0;
/* 80902D94 7C1B1840 */  cmplw    r27, r3;
/* 80902D98 4182001C */  beq-     UNDEF_80902db4;
/* 80902D9C 2C1B0000 */  cmpwi    r27, 0;
/* 80902DA0 4182000C */  beq-     UNDEF_80902dac;
/* 80902DA4 4BFD57BD */  bl       UNDEF_808d8560;
/* 80902DA8 4800000C */  b        UNDEF_80902db4;
UNDEF_80902dac:;
/* 80902DAC 4B7FA415 */  bl       UNDEF_800fd1c0;
/* 80902DB0 4BFD5831 */  bl       UNDEF_808d85e0;
UNDEF_80902db4:;
/* 80902DB4 3CA08035 */  lis      r5, mPlayerType__9daPyMng_c@ha;
/* 80902DB8 3CC0809A */  lis      r6, UNDEF_809a0db8@ha;
/* 80902DBC 38A55160 */  addi     r5, r5, mPlayerType__9daPyMng_c@l;
/* 80902DC0 3C608032 */  lis      r3, UNDEF_8031d6b4@ha;
/* 80902DC4 80850004 */  lwz      r4, 4(r5);
/* 80902DC8 38C60DB8 */  addi     r6, r6, UNDEF_809a0db8@l;
/* 80902DCC 80FF0388 */  lwz      r7, 904(r31);
/* 80902DD0 3863D6B4 */  addi     r3, r3, UNDEF_8031d6b4@l;
/* 80902DD4 5484103A */  slwi     r4, r4, 2;
/* 80902DD8 80050008 */  lwz      r0, 8(r5);
/* 80902DDC 7CE6212E */  stwx     r7, r6, r4;
/* 80902DE0 39610030 */  addi     r11, r1, 48;
/* 80902DE4 5404103A */  slwi     r4, r0, 2;
/* 80902DE8 8005000C */  lwz      r0, 12(r5);
/* 80902DEC 80BF038C */  lwz      r5, 908(r31);
/* 80902DF0 7CA6212E */  stwx     r5, r6, r4;
/* 80902DF4 5400103A */  slwi     r0, r0, 2;
/* 80902DF8 809F0390 */  lwz      r4, 912(r31);
/* 80902DFC 7C86012E */  stwx     r4, r6, r0;
/* 80902E00 809E0184 */  lwz      r4, 388(r30);
/* 80902E04 90640294 */  stw      r3, 660(r4);
/* 80902E08 80840184 */  lwz      r4, 388(r4);
/* 80902E0C 90640294 */  stw      r3, 660(r4);
/* 80902E10 80840184 */  lwz      r4, 388(r4);
/* 80902E14 90640294 */  stw      r3, 660(r4);

                         // Copy one more time for our new subplayer
                         lwz      r4, 0x184(r4);
                         stw      r3, 0x294(r4);

                         // Copy player 1's status thing
                         lwz      r9, 0x384(r31);
                         lis      r10, mPlayerType__9daPyMng_c@ha;
                         lwz      r10, mPlayerType__9daPyMng_c@l(r10); // Player 1 character
                         slwi     r10, r10, 2;
                         stwx     r9, r6, r10;

/* 80902E18 4B9DA289 */  bl       UNDEF_802dd0a0;
/* 80902E1C 80010034 */  lwz      r0, 52(r1);
/* 80902E20 7C0803A6 */  mtlr     r0;
/* 80902E24 38210030 */  addi     r1, r1, 48;
/* 80902E28 4E800020 */  blr;
  // clang-format on
);

/* VT+0x60 0x80909940 */
[[address(0x80909940)]]
void daWmPlayer_c::VT_0x60();

[[address(0x809093D0)]]
void daWmPlayer_c::initActiveCharaFlags()
{
    dInfo_c* info = dInfo_c::m_instance;

    for (u32 i = 0; i < 4; i++) {
        m_activeCharaFlag[s32(daPyMng_c::mPlayerType[i]) % 4] =
          info->mPlayerActiveMode[i] == 3 ? 3 : 0;
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