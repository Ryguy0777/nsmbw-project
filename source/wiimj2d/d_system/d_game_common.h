#pragma once

#include <revolution/sc.h>

namespace nw4r::lyt
{
class Picture;
} // namespace nw4r::lyt

class LytTextBox_c;

namespace dGameCom
{

/* 0x800B2E70 */
void initRandomSeed();

/* 0x800B2EE0 */
u32 rndInt(u32 max);

/* 0x800B30C0 */
f32 getDispCenterX();

/* 0x800B5340 */
bool chkContinue();

/* 0x800B53F0 */
bool chkCancelButton(int player);

/* 0x800B3B50 */
bool isGameStop(u32 flag);

/* 0x800B3B60 */
void LayoutDispNumber(const int& value, const int& maxChars, LytTextBox_c* textBox, bool itoaType);

/* 0x800B44D0 */
void SelectCursorSetup(nw4r::lyt::Picture* pane, int param2, bool param3);

/* 0x800B4760 */
bool PlayerEnterCheck(int player);

/* 0x800B4780 */
void Player1upColor(LytTextBox_c* textBox, int player);

/* 0x800B5500 */
SCAspectRatio GetAspectRatio();

} // namespace dGameCom