// d_a_player_base.cpp
// NSMBW .text: 0x800460D0 - 0x8005B3A0

#include "d_a_player_base.h"
#include "dynamic/d_player/d_gamedisplay.h"

#include <cstdio>
#include <dynamic/d_a_player_manager.h>
#include <dynamic/d_actor_name.h>
#include <dynamic/d_game_common.h>
#include <dynamic/d_player/d_a_player.h>
#include <dynamic/d_player/d_a_yoshi.h>
#include <framework/f_base_profile.h>
#include <iterator>

[[address(0x8004DB40)]]
bool daPlBase_c::isDemoType(DemoType_e type);

[[address(0x8004DD00)]]
bool daPlBase_c::isDemo();

[[address(0x8004E040)]]
bool daPlBase_c::isPlayerGameStop();

[[address(0x8004E050)]]
void daPlBase_c::stopOther();

[[address(0x8004E100)]]
void daPlBase_c::playOther();

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

[[address(0x80051F30)]]
void daPlBase_c::setControlDemoDir(u8 direction);

[[address(0x80052030)]]
bool daPlBase_c::isControlDemoWait();

[[address(0x80052080)]]
void daPlBase_c::setControlDemoWalk(const f32& pos, const f32& speed);

[[address(0x80052170)]]
void daPlBase_c::setControlDemoAnm(int anim);

[[address(0x80052470)]]
bool daPlBase_c::isBossDemoLand();

[[address(0x80056C70)]]
void daPlBase_c::onStatus(int flag);

[[address(0x80056CB0)]]
void daPlBase_c::offStatus(int flag);

[[address(0x80056CF0)]]
bool daPlBase_c::isStatus(int flag);

[[address(0x800583A0)]]
void daPlBase_c::calcHeadAttentionAngle();

using MsgArray = const char*[];

void daPlBase_c::addDeathMessage(dActor_c* source, DamageType_e type, bool death)
{
    // TODO: Use BMG for messages

    const char* selfName = dActorName::getActorFormattedName(this);
    if (selfName == nullptr) {
        selfName = "Someone";
    }

    const char* enemyName = dActorName::getActorFormattedName(source);
    fBaseProfile_e enemy = source ? fBaseProfile_e(source->mProfName) : fBaseProfile_e::LASTACTOR;

    const char* messages[128] = {};
    int messageCount = 0;

    auto addMsg = [&](const char* const msg) {
        if (messageCount < 128) {
            messages[messageCount++] = msg;
        }
    };

    switch (type) {
    default:
        switch (enemy) {
        default:
            if (death) {
                addMsg("%s was finished by %s");
                addMsg("%s was slain by %s");
                addMsg("%s reached an impassable %s");
                addMsg("%s couldn't handle %s");
            } else {
                addMsg("%s came into contact with %s");
            }

            addMsg("%s lost it to %s");
            addMsg("%s tried to give %s a hug");
            addMsg("%s lost a fight with %s");
            addMsg("%s existed in the same space as %s");
            break;

        case fBaseProfile_e::LASTACTOR:
            // Enemy name = "an unknown force"
            if (death) {
                addMsg("%s lost the game");
                addMsg("%s lost it to %s");
                addMsg("Someone killed %s");
                addMsg("%s died");
            } else {
                addMsg("%s was hurt badly");
            }

            addMsg("%s came into contact with %s");
            break;

        case fBaseProfile_e::EN_BIGPILE_UNDER:
        case fBaseProfile_e::EN_BIGPILE_UPPER:
        case fBaseProfile_e::EN_BIGPILE_RIGHT:
        case fBaseProfile_e::EN_BIGPILE_LEFT:
        case fBaseProfile_e::EN_SUPER_BIGPILE_RIGHT:
        case fBaseProfile_e::EN_SUPER_BIGPILE_LEFT:
        case fBaseProfile_e::EN_GOKUBUTO_BIGPILE_UNDER:
        case fBaseProfile_e::EN_GOKUBUTO_BIGPILE_UPPER:
            // "was skewered by Skewer"
            if (death) {
                addMsg("%s was skewered by %s");
            } else {
                addMsg("%s was penetrated by %s");
                addMsg("%s was pummeled by %s");
            }
            break;

        case fBaseProfile_e::EN_KILLER:
        case fBaseProfile_e::EN_SEARCH_KILLER:
        case fBaseProfile_e::EN_MAGNUM_KILLER:
        case fBaseProfile_e::EN_SEARCH_MAGNUM_KILLER:
            if (death) {
                addMsg("%s was shot by %s");
            } else {
                addMsg("%s was struck by %s");
            }
            break;

        case fBaseProfile_e::EN_KING_KILLER:
            if (death) {
                addMsg("%s was blasted by %s");
            } else {
                addMsg("%s was pummeled by %s");
            }
            break;

        case fBaseProfile_e::EN_ICICLE:
        case fBaseProfile_e::EN_BIG_ICICLE:
            if (death) {
                addMsg("%s was skewered by %s");
            } else {
                addMsg("%s was impaled by %s");
            }
            break;

        case fBaseProfile_e::EN_DOSUN:
        case fBaseProfile_e::EN_BIGDOSUN:
            if (death) {
                addMsg("%s was smashed by %s");
                addMsg("%s was thwomped by %s");
            } else {
                addMsg("%s was pounded by %s");
                addMsg("%s was thumped by %s");
            }
            break;

        case fBaseProfile_e::EN_KANITAMA:
            if (death) {
                addMsg("%s was finished by a rock");
                addMsg("%s was slain by a rock");

                // Three times for greater weight
                addMsg("%s was killed with a rock");
                addMsg("%s was killed with a rock");
                addMsg("%s was killed with a rock");
            } else {
                addMsg("%s came into contact with a rock");
            }
            addMsg("%s lost a fight with a rock");
            break;
        }

    case DamageType_e::ELEC_SHOCK:
        if (enemyName == nullptr) {
            if (death) {
                addMsg("%s was electrocuted");
            } else {
                addMsg("%s was shocked");
            }
        } else {
            if (death) {
                addMsg("%s was electrocuted by %s");
            } else {
                addMsg("%s was shocked by %s");
            }
        }
        break;

    case DamageType_e::LAVA:
        addMsg("%s tried to swim in lava");
        addMsg("%s fell into lava");
        break;

    case DamageType_e::POISON_WATER:
        addMsg("%s drank the weird lanky water");
        addMsg("%s fell into the poisonous jungle juice");
        addMsg("%s fell into the radioactive water");
        break;

    case DamageType_e::CRUSH:
        if (enemyName == nullptr) {
            if (death) {
                addMsg("%s was squished to death");
            }
            addMsg("%s was crushed by a heavy object");
            addMsg("%s was squished too much");
        } else {
            addMsg("%s was squashed by %s");
        }
        break;

    case DamageType_e::EAT_DIE:
    case DamageType_e::EAT_DIE2:
        if (enemyName == nullptr) {
            addMsg("%s was devoured");
            addMsg("%s was devoured by a hungry creature");
            addMsg("%s was devoured by a monster");
        } else {
            addMsg("%s was devoured by %s");
        }
        break;

    case DamageType_e::FREEZE:
    case DamageType_e::FREEZE2:
        if (enemyName == nullptr) {
            if (death) {
                addMsg("%s froze to death");
            } else {
                addMsg("%s was frozen solid");
            }
        } else {
            if (death) {
                addMsg("%s froze to death by %s");
            } else {
                addMsg("%s was frozen solid by %s");
            }
        }
        break;

    case DamageType_e::POISON_FOG:
        addMsg("%s couldn't escape the fog");
        addMsg("%s got lost in the fog");
        break;
    }

    const char* message = nullptr;
    if (messageCount > 0) {
        message = messages[dGameCom::rndInt(messageCount)];
    } else {
        if (death) {
            message = "%s died";
        } else {
            message = "%s was hurt";
        }
    }

    if (enemyName == nullptr) {
        enemyName = "an unknown force";
    }

    char formattedMessage[128];
    std::snprintf(formattedMessage, sizeof(formattedMessage), message, selfName, enemyName);

    wchar_t wideMessage[128];
    std::mbstowcs(wideMessage, formattedMessage, std::size(wideMessage));

    dGameDisplay_c::m_instance->newDeathMessage(wideMessage, daPyMng_c::mPlayerType[*getPlrNo()]);
}