// d_a_player_base.cpp
// NSMBW .text: 0x800460D0 - 0x8005B3A0

#include "d_a_player_base.h"

#include <cstdio>
#include <d_system/d_a_player_manager.h>
#include <d_system/d_actor_name.h>
#include <d_system/d_game_common.h>
#include <d_player/d_a_player.h>
#include <d_player/d_a_yoshi.h>
#include <d_player/d_gamedisplay.h>
#include <framework/f_base_profile.h>
#include <framework/f_manager.h>
#include <iterator>

[[address(0x8004DB40)]]
bool daPlBase_c::isDemoType(DemoType_e type);

[[address(0x8004DD00)]]
bool daPlBase_c::isDemo();

[[address(0x8004DDE0)]]
bool daPlBase_c::isDemoAll();

[[address(0x8004E040)]]
bool daPlBase_c::isPlayerGameStop();

[[address(0x8004E050)]]
void daPlBase_c::stopOther();

[[address(0x8004E100)]]
void daPlBase_c::playOther();

[[address(0x8004E290)]]
void daPlBase_c::changeDemoState(const sStateIDIf_c& state, int param);

[[address(0x80050D80)]]
bool daPlBase_c::isDispOutCheckOn();

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

// Static array works here as we have a limited number of players
static fBaseID_e s_lastHitEnemy[PLAYER_COUNT] = {};

void daPlBase_c::addDeathMessage(dActor_c* source, DamageType_e type, bool death)
{
    // TODO: Use BMG for messages

    fBaseID_e lastHit = s_lastHitEnemy[mPlayerNo];
    s_lastHitEnemy[mPlayerNo] = source ? source->mUniqueID : fBaseID_e::NULL;

    bool repeat = source ? source->mUniqueID == lastHit : false;

    const char* selfName = dActorName::getActorFormattedName(this);
    if (selfName == nullptr) {
        selfName = "Someone";
    }

    const char* enemyName = dActorName::getActorFormattedName(source);
    fBaseProfile_e enemy = source ? fBaseProfile_e(source->mProfName) : fBaseProfile_e::LASTACTOR;

    fBase_c* lastEnemy = fManager_c::searchBaseByID(lastHit);
    const char* lastEnemyName = nullptr;
    if (lastEnemy != nullptr) {
        lastEnemyName = dActorName::getActorFormattedName(lastEnemy);
    }

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
            if (repeat) {
                addMsg("%s gave %s another chance");
                addMsg("%s didn't learn their lesson about %s");
                if (!death) {
                    break;
                }
            }

            if (death) {
                addMsg("%s was finished by %s");
                addMsg("%s was slain by %s");
                addMsg("%s reached an impassable %s");
                addMsg("%s couldn't handle %s");
                addMsg("%s lost a fight with %s");
                addMsg("%s lost it to %s");
                addMsg("%s was no match for %s");
                addMsg("%s seriously died to %s?");
                addMsg("%s met the wrath of %s");
                addMsg("%s didn't get the memo about %s");
            } else {
                addMsg("%s came into contact with %s");
                addMsg("%s occupied the same space as %s");
                addMsg("%s and %s touched hitboxes");
                addMsg("%s was hurt badly by %s");
                addMsg("%s forgot %s was harmful");
                addMsg("%s! Stay away from %s!");
                addMsg("%s wasn't warned about %s...");
                addMsg("%s was scratched by %s");
                addMsg("%s tried to hug %s");
                addMsg("%s touched %s the wrong way");
            }
            break;

        case fBaseProfile_e::LASTACTOR:
            // Enemy name = "an unknown force"
            if (death) {
                addMsg("%s lost the game");
                addMsg("%s lost a fight with the game");
                addMsg("%s lost it to %s");
                addMsg("Someone killed %s!!!");
                addMsg("%s died");
            } else {
                addMsg("%s came into contact with %s");
                addMsg("%s was hurt badly");
            }

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
                addMsg("%s was destroyed by %s");
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
        break;

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

    case DamageType_e::FALL_DOWN:
        if (enemyName == nullptr) {
            if (lastEnemyName) {
                enemyName = lastEnemyName;
                addMsg("%s couldn't live in the same world as %s");
                addMsg("%s was knocked off a cliff by %s");
                addMsg("%s stumbled over %s and fell off");
            } else {
                addMsg("%s fell off");
                addMsg("%s fell through the floor");
                addMsg("%s fell off (on purpose)");
            }

            addMsg("%s fell out of the world");
            addMsg("%s forgot how to jump");
            addMsg("%s thought there was ground there");
            addMsg("%s didn't want to play anymore");
            addMsg("%s lost the game");
            addMsg("%s you're not supposed to go down there");
            addMsg("%s what's it like down there");
            addMsg("%s left the confines of the world");
        } else {
            addMsg("%s fell off and dragged %s with them");
            addMsg("%s sacrificed themselves to take out %s");
            addMsg("%s thought the world better without %s");
            addMsg("~%s was dragged into the void by %s");
            addMsg("~%s was betrayed by %s");
        }
        break;

    case DamageType_e::SCROLL_OUT:
        if (enemyName == nullptr) {
            addMsg("%s met the wrath of the edge of the screen");
            addMsg("%s mysteriously vanished");
            addMsg("%s died because the screen scrolled too much");
            addMsg("The screen just went too far for %s");
            addMsg("%s left the confines of the screen");
            addMsg("%s died");
            addMsg("%s was left behind");
            addMsg("%s died because people need to slow down");
            addMsg("%s died because people need to slow down");
            addMsg("%s died because PEOPLE NEED TO SLOW DOWN!!!!");
        } else {
            addMsg("%s and %s couldn't handle the screen's edge");
            addMsg("%s and %s met the edge of the screen");
            addMsg("%s showed %s to the edge of the screen");
            addMsg("%s and %s were left behind");
            addMsg("%s and %s mysteriously vanished");
            addMsg("%s and %s died");
            addMsg("%s and %s died because people need to slow down");
        }
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

    daPlBase_c* player = this;
    if (message[0] == '~') {
        // Swap order of names
        const char* temp = selfName;
        selfName = enemyName;
        enemyName = temp;
        if (source) {
            if (auto player2 = source->DynamicCast<daPlBase_c>()) {
                player = player2;
            }
        }
    }

    char formattedMessage[128];
    std::snprintf(formattedMessage, sizeof(formattedMessage), message, selfName, enemyName);

    wchar_t wideMessage[128];
    std::mbstowcs(wideMessage, formattedMessage, std::size(wideMessage));

    dGameDisplay_c::m_instance->newDeathMessage(
      wideMessage, daPyMng_c::mPlayerType[*player->getPlrNo()]
    );
}