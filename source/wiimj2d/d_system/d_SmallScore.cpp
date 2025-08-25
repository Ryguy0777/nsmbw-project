// d_SmallScore.cpp
// NSMBW .text: 0x80014F10 - 0x80015D60

#include "d_SmallScore.h"

#include "d_system/d_a_player_manager.h"
#include <nw4r/lyt/Material.h>
#include <nw4r/ut/Color.h>

[[address(0x80015200)]]
void dSmallScore_c::setPlayer1upColor(int player);

[[address(0x80015210)]]
void dSmallScore_c::setPlayer1000Color(int player)
{
    static constinit const nw4r::ut::Color l_PLY_COLOR_0[] = {
      "#FF7800", // Mario
      "#32FA32", // Luigi
      "#00B9DC", // Blue Toad
      "#FFFF00", // Yellow Toad
      "#FA8CFA", // Toadette
      "#FFFFFF", // Player 5
      "#FFFFFF", // Player 6
      "#FFFFFF", // Player 7
    };

    static constinit const nw4r::ut::Color l_PLY_COLOR_2[] = {
      "#FFC828", // Mario
      "#FFFF00", // Luigi
      "#D2FFFA", // Blue Toad
      "#FFFFB4", // Yellow Toad
      "#FFD1FF", // Toadette
      "#FFFFFF", // Player 5
      "#FFFFFF", // Player 6
      "#FFFFFF", // Player 7
    };

    int index = daPyMng_c::getPlayerColorType(static_cast<daPyMng_c::PlayerType_e>(player));

    mTxt1000->SetVtxColor(0, l_PLY_COLOR_0[index]);
    mTxt1000->SetVtxColor(2, l_PLY_COLOR_2[index]);
}

[[address(0x800153B0)]]
void dSmallScore_c::setPlayer100Color(int player)
{
    static constinit const nw4r::ut::Color l_PLY_COLOR[] = {
      "#FF9655", // Mario
      "#46FA46", // Luigi
      "#46C8E6", // Blue Toad
      "#FAFF50", // Yellow Toad
      "#FA7AEF", // Toadette
      "#FFFFFF", // Player 5
      "#FFFFFF", // Player 6
      "#FFFFFF", // Player 7
    };

    int index = daPyMng_c::getPlayerColorType(static_cast<daPyMng_c::PlayerType_e>(player));

    mTxt100->GetMaterial()->SetTevColor(1, l_PLY_COLOR[index]);
}