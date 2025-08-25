// d_actor_name.cpp
// NSMBW: ---

#include "d_actor_name.h"
#include "d_system/d_a_player_manager.h"

#include <algorithm>
#include <array>
#include "d_system/d_base.h"
#include "d_player/d_a_player.h"
#include "framework/f_base_profile.h"
#include <iterator>
#include <numeric>

namespace dActorName
{

struct ActorName {
    fBaseProfile_e profile;
    char name[256];
};

constexpr ActorName s_names[] = {
  {fBaseProfile_e::YOSHI, "Yoshi"},
  {fBaseProfile_e::YOSHI_FIRE, "Yoshi Fire"},
  {fBaseProfile_e::EN_KURIBO, "Goomba"},
  {fBaseProfile_e::EN_PATA_KURIBO, "Paragoomba"},
  {fBaseProfile_e::EN_MAME_KURIBO, "Mini Goomba"},
  {fBaseProfile_e::EN_NOKONOKO, "Koopa Troopa"},
  {fBaseProfile_e::EN_PATAPATA, "Paratroopa"},
  {fBaseProfile_e::EN_MET, "Buzzy Beetle"},
  {fBaseProfile_e::EN_TOGEZO, "Spiny"},
  {fBaseProfile_e::EN_SAKASA_TOGEZO, "Upside-down Spiny"},
  {fBaseProfile_e::EN_BUBBLE, "Lava Bubble"},
  {fBaseProfile_e::EN_DOSUN, "Thwomp"},
  {fBaseProfile_e::EN_BIGDOSUN, "Big Thwomp"},
  {fBaseProfile_e::EN_JUGEM, "Lakitu"},
  {fBaseProfile_e::EN_JUGEM_COIN, "Lakitu"},
  {fBaseProfile_e::EN_EATJUGEM, "Lakitu"},
  {fBaseProfile_e::EN_JUGEM_BODY, "Lakitu"},
  {fBaseProfile_e::EN_TOGEMET, "Spike Top"},
  {fBaseProfile_e::EN_FIREBAR, "Fire Bar"},
  {fBaseProfile_e::EN_TOGETEKKYU, "Spike Ball"},
  {fBaseProfile_e::EN_BIG_TOGETEKKYU, "Big Spike Ball"},
  {fBaseProfile_e::EN_UP_DOKAN_PAKKUN, "Piranha Plant"},
  {fBaseProfile_e::EN_DOWN_DOKAN_PAKKUN, "Piranha Plant"},
  {fBaseProfile_e::EN_RIGHT_DOKAN_PAKKUN, "Piranha Plant"},
  {fBaseProfile_e::EN_LEFT_DOKAN_PAKKUN, "Piranha Plant"},
  {fBaseProfile_e::EN_UP_DOKAN_FPAKKUN, "Fire Piranha Plant"},
  {fBaseProfile_e::EN_DOWN_DOKAN_FPAKKUN, "Fire Piranha Plant"},
  {fBaseProfile_e::EN_RIGHT_DOKAN_FPAKKUN, "Fire Piranha Plant"},
  {fBaseProfile_e::EN_LEFT_DOKAN_FPAKKUN, "Fire Piranha Plant"},
  {fBaseProfile_e::EN_JIMEN_PAKKUN, "Piranha Plant"},
  {fBaseProfile_e::EN_JIMEN_BIG_PAKKUN, "Big Guy"},
  {fBaseProfile_e::EN_JIMEN_FPAKKUN, "Fire Piranha Plant"},
  {fBaseProfile_e::EN_JIMEN_BIG_FPAKKUN, "Big Fire Guy"},
  {fBaseProfile_e::EN_WALK_PAKKUN, "Stalking Piranha Plant"},
  {fBaseProfile_e::ICEBALL, "Ice Ball"},
  {fBaseProfile_e::PL_FIREBALL, "Fireball"},
  {fBaseProfile_e::PAKKUN_FIREBALL, "Piranha Plant Fireball"},
  {fBaseProfile_e::BROS_FIREBALL, "Fire Bro Fireball"},
  {fBaseProfile_e::BOOMERANG, "Boomerang"},
  {fBaseProfile_e::EN_FIREBROS, "Fire Bro"},
  {fBaseProfile_e::EN_BOOMERANGBROS, "Boomerang Bro"},
  {fBaseProfile_e::EN_HAMMERBROS, "Hammer Bro"},
  {fBaseProfile_e::EN_LIFT_HAMMERBROS, "Hammer Bro"},
  {fBaseProfile_e::EN_ICEBROS, "Ice Bro"},
  {fBaseProfile_e::HAMMER, "Hammer"},
  {fBaseProfile_e::EN_HIMANBROS, "Sledge Bro"},
  {fBaseProfile_e::MEGA_HAMMER, "Sledge Bro Hammer"},
  {fBaseProfile_e::BROS_ICEBALL, "Ice Bro Iceball"},
  {fBaseProfile_e::EN_KILLER, "Bullet Bill"},
  {fBaseProfile_e::EN_SEARCH_KILLER, "Bullseye Bill"},
  {fBaseProfile_e::EN_MAGNUM_KILLER, "Banzai Bill"},
  {fBaseProfile_e::EN_SEARCH_MAGNUM_KILLER, "Bullseye Banzai Bill"},
  {fBaseProfile_e::EN_BASABASA, "Swoop"},
  {fBaseProfile_e::WAKI_PARABOM, "Parabomb"},
  {fBaseProfile_e::EN_PARA_BOMHEI, "Parabomb"},
  {fBaseProfile_e::EN_BOMHEI, "Bob-omb"},
  {fBaseProfile_e::EN_MECHA_KOOPA, "Mechakoopa"},
  {fBaseProfile_e::EN_MOUSE, "Scaredy Rat"},
  {fBaseProfile_e::EN_BIRIKYU, "Amp"},
  {fBaseProfile_e::EN_LINE_BIRIKYU, "Amp"},
  {fBaseProfile_e::EN_CHOROBON, "Fuzzy"},
  {fBaseProfile_e::EN_SANBO, "Pokey"},
  {fBaseProfile_e::EN_SANBO_PARTS, "Pokey"},
  {fBaseProfile_e::EN_SANBO_EL, "Pokey"},
  {fBaseProfile_e::EN_GURUGURU, "Ball and Chain"},
  {fBaseProfile_e::EN_SYNCRO_BARNAR, "Burner"},
  {fBaseProfile_e::EN_BARNAR, "Burner"},
  {fBaseProfile_e::EN_LARGE_BARNAR, "Burner"},
  {fBaseProfile_e::ROT_BARNAR, "Burner"},
  {fBaseProfile_e::EN_GESSO, "Blooper"},
  {fBaseProfile_e::EN_BARAMAKI_GESSO, "Blooper Nanny"},
  {fBaseProfile_e::EN_GESSO_CHILD, "Blooper Baby"},
  {fBaseProfile_e::EN_PUKUPUKU_PARENT, "Cheep Cheep"},
  {fBaseProfile_e::EN_PUKUPUKU, "Cheep Cheep"},
  {fBaseProfile_e::EN_TOGEPUKU, "Spiny Cheep Cheep"},
  {fBaseProfile_e::EN_MIDDLE_PUKU, "Big Cheep Cheep"},
  {fBaseProfile_e::EN_KARON, "Dry Bones"},
  {fBaseProfile_e::EN_BIGKARON, "Big Dry Bones"},
  {fBaseProfile_e::EN_NET_NOKONOKO_LR, "Climbing Koopa"},
  {fBaseProfile_e::EN_NET_NOKONOKO_UD, "Climbing Koopa"},
  {fBaseProfile_e::EN_HANACHAN, "Wiggler"},
  {fBaseProfile_e::EN_BIG_HANACHAN, "Big Wiggler"},
  {fBaseProfile_e::EN_TERESA, "Boo"},
  {fBaseProfile_e::EN_BIG_TERESA, "Big Boo"},
  {fBaseProfile_e::EN_CROW, "Crowber"},
  {fBaseProfile_e::EN_BIGPILE_UNDER, "Skewer"},
  {fBaseProfile_e::EN_BIGPILE_UPPER, "Skewer"},
  {fBaseProfile_e::EN_BIGPILE_RIGHT, "Skewer"},
  {fBaseProfile_e::EN_BIGPILE_LEFT, "Skewer"},
  {fBaseProfile_e::EN_SUPER_BIGPILE_RIGHT, "Skewer"},
  {fBaseProfile_e::EN_SUPER_BIGPILE_LEFT, "Skewer"},
  {fBaseProfile_e::EN_GOKUBUTO_BIGPILE_UNDER, "Skewer"},
  {fBaseProfile_e::EN_GOKUBUTO_BIGPILE_UPPER, "Skewer"},
  {fBaseProfile_e::EN_WANWAN, "Chain Chomp"},
  {fBaseProfile_e::EN_JUMPPUKU, "Jumping Cheep Cheep"},
  {fBaseProfile_e::EN_TOBIPUKU, "Jumping Cheep Cheep"},
  {fBaseProfile_e::EN_IGAPUKU, "Porcupuffer"},
  {fBaseProfile_e::EN_FIRESNAKE, "Fire Snake"},
  {fBaseProfile_e::EN_BOSS_KAMECK, "Kamek"},
  {fBaseProfile_e::EN_SLIP_PENGUIN, "Cooligan"},
  {fBaseProfile_e::EN_SLIP_PENGUIN2, "Cooligan"},
  {fBaseProfile_e::EN_IGA_KURIBO, "Prickly Goomba"},
  {fBaseProfile_e::KAMECK_MAGIC, "Kamek's Magic"},
  {fBaseProfile_e::EN_KERONPA, "Fire Chomp"},
  {fBaseProfile_e::KERONPA_FIRE, "Fire Chomp"},
  {fBaseProfile_e::EN_BAKUBAKU, "Cheep Chomp"},
  {fBaseProfile_e::EN_BOSS_LARRY, "Larry Koopa"},
  {fBaseProfile_e::EN_BOSS_CASTLE_LARRY, "Larry Koopa"},
  {fBaseProfile_e::OBJ_LARRY, "Larry Koopa"},
  {fBaseProfile_e::EN_BOSS_WENDY, "Wendy O. Koopa"},
  {fBaseProfile_e::EN_BOSS_CASTLE_WENDY, "Wendy O. Koopa"},
  {fBaseProfile_e::OBJ_WENDY, "Wendy O. Koopa"},
  {fBaseProfile_e::EN_BOSS_IGGY, "Iggy Koopa"},
  {fBaseProfile_e::EN_BOSS_CASTLE_IGGY, "Iggy Koopa"},
  {fBaseProfile_e::EN_BOSS_LEMMY, "Lemmy Koopa"},
  {fBaseProfile_e::EN_BOSS_CASTLE_LEMMY, "Lemmy Koopa"},
  {fBaseProfile_e::EN_BOSS_MORTON, "Morton Koopa Jr."},
  {fBaseProfile_e::EN_BOSS_CASTLE_MORTON, "Morton Koopa Jr."},
  {fBaseProfile_e::OBJ_MORTON, "Morton Koopa Jr."},
  {fBaseProfile_e::EN_BOSS_ROY, "Roy Koopa"},
  {fBaseProfile_e::EN_BOSS_CASTLE_ROY, "Roy Koopa"},
  {fBaseProfile_e::OBJ_ROY, "Roy Koopa"},
  {fBaseProfile_e::EN_BOSS_LUDWIG, "Ludwig von Koopa"},
  {fBaseProfile_e::EN_BOSS_CASTLE_LUDWIG, "Ludwig von Koopa"},
  {fBaseProfile_e::OBJ_LUDWIG, "Ludwig von Koopa"},
  {fBaseProfile_e::EN_BOSS_KOOPA, "Bowser"},
  {fBaseProfile_e::KOOPA_FIRE, "Bowser Fire Breath"},
  {fBaseProfile_e::LARRY_FIRE, "Magic Fireball"},
  {fBaseProfile_e::KOKOOPA_RING, "Wendy Ring"},
  {fBaseProfile_e::OBJ_IGGY_WANWAN, "Iggy Chain Chomp"},
  {fBaseProfile_e::CASTLE_LUDWIG_BLITZ, "Ludwig's Magic"},
  {fBaseProfile_e::FIRE_BLITZ, "Magic Fire"},
  {fBaseProfile_e::EN_UNIZOO, "Urchin"},
  {fBaseProfile_e::EN_UNIRA, "Big Urchin"},
  {fBaseProfile_e::EN_KANIBO, "Huckit Crab"},
  {fBaseProfile_e::EN_KANITAMA, "Huckit Crab's Rock"},
  {fBaseProfile_e::EN_KOPONE, "Fish Bones"},
  {fBaseProfile_e::EN_AKOYA, "Clampy"},
  {fBaseProfile_e::EN_MIDDLE_KURIBO, "Giant Goomba"},
  {fBaseProfile_e::EN_LARGE_KURIBO, "Mega Goomba"},
  {fBaseProfile_e::EN_BEANS_KURIBO, "Micro Goomba"},
  {fBaseProfile_e::JR_CLOWN_A, "Junior Clown Car"},
  {fBaseProfile_e::JR_CLOWN_B, "Junior Clown Car"},
  {fBaseProfile_e::JR_CLOWN_C, "Junior Clown Car"},
  {fBaseProfile_e::JR_CLOWN_FOR_PLAYER, "Junior Clown Car"},
  {fBaseProfile_e::BOMB_JR_C, "Bowser Jr. Bomb"},
  {fBaseProfile_e::EN_BOSS_KOOPA_JR_A, "Bowser Jr."},
  {fBaseProfile_e::EN_BOSS_KOOPA_JR_B, "Bowser Jr."},
  {fBaseProfile_e::EN_BOSS_KOOPA_JR_C, "Bowser Jr."},
  {fBaseProfile_e::JR_FIRE, "Bowser Jr. Fire Breath"},
  {fBaseProfile_e::JR_FLOOR_FIRE, "Bowser Jr. Floor Fire"},
  {fBaseProfile_e::YOGAN_INTERMITTENT, "Lava Geyser"},
  {fBaseProfile_e::EN_IBARAMUSHI, "Bramball"},
  {fBaseProfile_e::EN_CHOCHIN_ANKOH, "Bulber"},
  {fBaseProfile_e::EN_MISTMAN, "Foo"},
  {fBaseProfile_e::EN_ROT_PAKKUN, "Rotating Piranha Plant"},
  {fBaseProfile_e::EN_POLTER, "Silly Flying Thing"},
  {fBaseProfile_e::EN_ICICLE, "Icicle"},
  {fBaseProfile_e::EN_CANNON_BULLET, "Cannonball"},
  {fBaseProfile_e::KAZAN_ROCK, "Volcano Rock"},
  {fBaseProfile_e::EN_CHOROPU, "Monty Mole"},
  {fBaseProfile_e::EN_MANHOLE_CHOROPU, "Monty Mole"},
  {fBaseProfile_e::EN_JELLY_FISH, "Jellybeam"},
  {fBaseProfile_e::EN_GABON, "Spike"},
  {fBaseProfile_e::GABON_ROCK, "Spike Rock"},
  {fBaseProfile_e::EN_KING_KILLER, "King Bill"},
  {fBaseProfile_e::EN_PATAMET, "Para-Beetle"},
  {fBaseProfile_e::EN_BIG_PATAMET, "Heavy Para-Beetle"},
  {fBaseProfile_e::EN_BIG_ICICLE, "Falling Big Icicle"},
  {fBaseProfile_e::EN_BARREL, "Barrel"},
  {fBaseProfile_e::LIFT_ZEN_TOGE, "Spiky Wall from 5-Tower"},

  // Other non-death message actors
  {fBaseProfile_e::CASTLE_BOSS_DOOR, "FNAF 1 Style Door"},
  {fBaseProfile_e::CASTLE_BOSS_KEY, "Castle Boss Key"},
  {fBaseProfile_e::EN_DOOR, "Door"},
  {fBaseProfile_e::EN_SWITCHDOOR, "Door"},
  {fBaseProfile_e::EN_OBAKEDOOR, "Ghost House Door"},
  {fBaseProfile_e::EN_TORIDEDOOR, "Tower Boss Door"},
  {fBaseProfile_e::EN_CASTLEDOOR, "Castle Boss Door"},
  {fBaseProfile_e::EN_KOOPADOOR, "Final Boss Door"},
  {fBaseProfile_e::PALM_TREE, "Palm Tree"},
  {fBaseProfile_e::NICE_BOAT, "NICE_BOAT"},
  {fBaseProfile_e::LADDER, "Ladder"},
  {fBaseProfile_e::EN_REDRING, "Red Coin Ring"},
  {fBaseProfile_e::EN_SNAKEBLOCK, "Snake Block"},
  {fBaseProfile_e::SLIP_PENGUIN2_GLASSES, "Cooligan Glasses"},
};

template <u32 N>
struct PackedActorNames {
    char names[N];

    u32 getSize() const
    {
        return N;
    }
};

constexpr std::array<u32, std::size(s_names)> s_lengths = [] {
    std::array<u32, std::size(s_names)> lengths;
    for (u32 i = 0; i < std::size(s_names); i++) {
        u32 j;
        for (j = 0; s_names[i].name[j] != '\0'; j++) {
        }
        lengths[i] = j;
    }
    return lengths;
}();

constexpr std::array<u32, std::size(s_names)> s_sorted_indices = [] {
    std::array<u32, std::size(s_names)> indices;
    std::iota(indices.begin(), indices.end(), 0);
    std::sort(indices.begin(), indices.end(), [&](u32 a, u32 b) {
        return s_lengths[a] > s_lengths[b];
    });
    return indices;
}();

template <u32 P, u32 N>
consteval PackedActorNames<P> ProcessPackActorNames(const ActorName (&names)[N], u32& offset)
{
    PackedActorNames<P> packedNames = {};

    auto writeByte = [&](char byte) { packedNames.names[offset++] = byte; };

    for (u32 i = 0; i < N; i++) {
        const ActorName& name = names[s_sorted_indices[i]];

        writeByte(char(u16(name.profile) >> 2));
        writeByte(char(u16(name.profile) << 6));

        // Search back to see if we have a copy of the same name
        s32 foundOffset = -1;
        u32 myLength = s_lengths[s_sorted_indices[i]];
        for (u32 j = 0; j < offset - 2;) {
            if (packedNames.names[j + 1] & 0x20) {
                j += 3;
                continue;
            }

            u32 len = (packedNames.names[j + 1] << 8) & 0x1F;
            len |= packedNames.names[j + 2];
            u32 next = j + 3 + len;
            if (next > offset - 2) {
                break;
            }

            u32 k = next - 1 - myLength;
            u32 l;
            for (l = 0; l < myLength; l++) {
                if (packedNames.names[k + l] != name.name[l]) {
                    break;
                }
            }

            if (l == myLength) {
                foundOffset = s32(k);
                break;
            }

            j = next;
        }

        if (foundOffset != -1) {
            packedNames.names[offset - 1] |= 0x20 | ((foundOffset >> 8) & 0x1F);
            writeByte(foundOffset);
            continue;
        }

        u32 loc = offset++;
        for (u32 j = 0; name.name[j] != '\0'; j++) {
            writeByte(name.name[j]);
        }
        writeByte('\0');
        packedNames.names[loc] = offset - loc - 1;
    }

    return packedNames;
}

template <u32 P, u32 N>
consteval PackedActorNames<P> PackActorNames(const ActorName (&names)[N])
{
    u32 offset = 0;
    return ProcessPackActorNames<P>(names, offset);
}

constexpr u32 s_packedSize = [] {
    u32 offset = 0;
    ProcessPackActorNames<0x1000>(s_names, offset);
    return offset;
}();

constexpr PackedActorNames<s_packedSize> s_packedNames = [] {
    u32 offset = 0;
    return ProcessPackActorNames<s_packedSize>(s_names, offset);
}();

const char* getActorFormattedName(fBase_c* actor)
{
    if (actor == nullptr) {
        return nullptr;
    }

    if (auto player = actor->DynamicCast<dAcPy_c>()) {
        if (player->isItemKinopio()) {
            return "Road";
        }

        auto colorType = daPyMng_c::getPlayerColorType(player->mPlayerType);
        auto playerType = static_cast<daPyMng_c::PlayerType_e>(colorType);

        switch (playerType) {
        default:
            return "Player";

        case daPyMng_c::PlayerType_e::MARIO:
            return "Mario";
        case daPyMng_c::PlayerType_e::LUIGI:
            return "Luigi";
        case daPyMng_c::PlayerType_e::YELLOW_TOAD:
            return "Yoad";
        case daPyMng_c::PlayerType_e::BLUE_TOAD:
            return "Bload";
        case daPyMng_c::PlayerType_e::TOADETTE:
            return "Toadette";
        case daPyMng_c::PlayerType_e::PURPLE_TOADETTE:
            return "Poadette";
        case daPyMng_c::PlayerType_e::ORANGE_TOAD:
            return "Oroad";
        case daPyMng_c::PlayerType_e::BLACK_TOAD:
            return "Blaod";
        }
    }

    fBaseProfile_e name = fBaseProfile_e(actor->mProfName);
    auto names = s_packedNames.names;

    for (u32 i = 0; i < s_packedNames.getSize();) {
        u32 info = *(u32*) (names + i);
        u32 len = (info >> 8) & 0x1FFF;
        bool match = name == fBaseProfile_e(info >> 22);
        if (info & 0x200000) {
            if (match) {
                return &names[len];
            }
            i += 3;
            continue;
        }

        if (match) {
            return &names[i + 3];
        }
        i += 3 + len;
    }

    dBase_c* base = actor->DynamicCast<dBase_c>();
    return base && base->mpNameString ? base->mpNameString : "an unknown force";
}

} // namespace dActorName