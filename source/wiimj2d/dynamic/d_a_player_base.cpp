// d_a_player_base.cpp
// NSMBW: 0x800460D0 - 0x8005B3A0

#include "d_a_player_base.h"

#include <dynamic/d_a_player_manager.h>
#include <dynamic/system/d_a_player.h>
#include <dynamic/system/d_a_yoshi.h>

[[address(0x8004DB40)]]
bool daPlBase_c::isDemoType(DemoType_e type);

[[address(0x8004DD00)]]
bool daPlBase_c::isDemo();

[[address(0x8004E040)]]
bool daPlBase_c::isPlayerGameStop();

[[address(0x8004E050)]]
void daPlBase_c::stopOther();

[[address(0x800510F0)]]
void daPlBase_c::stopGoalOther()
{
    if (!isPlayerGameStop()) {
        return;
    }

    dActor_c::mExecStopReq |= 0xF;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        daPlBase_c* ctrlPlayer = daPyMng_c::getCtrlPlayer(i);
        if (ctrlPlayer == nullptr || !ctrlPlayer->isStatus(101)) {
            continue;
        }

        dAcPy_c* player = daPyMng_c::getPlayer(i);
        if (player != nullptr) {
            player->m0x38E &= ~0x2;
        }

        daYoshi_c* yoshi = daPyMng_c::getYoshi(i);
        if (yoshi != nullptr) {
            yoshi->m0x38E &= ~0x2;
        }
    }
}

[[address(0x800511A0)]]
void daPlBase_c::playGoalOther()
{
    dActor_c::mExecStopReq &= ~0xF;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        daPlBase_c* ctrlPlayer = daPyMng_c::getCtrlPlayer(i);
        if (ctrlPlayer == nullptr || !isStatus(101)) {
            continue;
        }

        dAcPy_c* player = daPyMng_c::getPlayer(i);
        if (player != nullptr) {
            player->m0x38E |= 0x2;
        }

        daYoshi_c* yoshi = daPyMng_c::getYoshi(i);
        if (yoshi != nullptr) {
            yoshi->m0x38E |= 0x2;
        }
    }
}

[[address(0x80051E70)]]
bool daPlBase_c::startControlDemo();

[[address(0x80051EF0)]]
void daPlBase_c::endControlDemo(int param);

[[address(0x80052470)]]
bool daPlBase_c::isBossDemoLand();

[[address(0x80056C70)]]
void daPlBase_c::onStatus(int flag);

[[address(0x80056CF0)]]
bool daPlBase_c::isStatus(int flag);