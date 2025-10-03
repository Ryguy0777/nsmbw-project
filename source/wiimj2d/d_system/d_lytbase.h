#pragma once

#include "d_system/d_2d.h"
#include "d_system/d_lyttextbox.h"
#include "framework/f_base.h"
#include <nw4r/lyt/Layout.h>
#include <nw4r/lyt/Pane.h>
#include <nw4r/lyt/Picture.h>
#include <nw4r/lyt/TextBox.h>
#include <nw4r/lyt/Window.h>

class LytBase_c : public d2d::Multi_c
{
    SIZE_ASSERT(0x198);

public:
    /* 0x800C89A0 */
    LytBase_c();

    /* VT+0x08 0x800C89F0 */
    virtual ~LytBase_c() override;

    /* VT+0x14 0x800C8A60 */
    virtual bool build(const char* lytName, d2d::ResAccMult_c* resAcc) override;

    /* 0x800C8D00 */
    bool ReadResource(const char* arcName, bool param2);

    /* 0x800C8E50 */
    void NPaneRegister(const char** paneNames, nw4r::lyt::Pane** nullPanes, int count);

    template <std::size_t N>
    constexpr void NPaneRegister(nw4r::lyt::Pane** nullPanes, const char* const (&paneNames)[N])
    {
        return NPaneRegister(const_cast<const char**>(paneNames), nullPanes, N);
    }

    /* 0x800C8EC0 */
    void WPaneRegister(const char** paneNames, nw4r::lyt::Window** windowPanes, int count);

    template <std::size_t N>
    constexpr void WPaneRegister(nw4r::lyt::Window** windowPanes, const char* const (&paneNames)[N])
    {
        return WPaneRegister(const_cast<const char**>(paneNames), windowPanes, N);
    }

    /* 0x800C8F30 */
    void PPaneRegister(const char** paneNames, nw4r::lyt::Picture** picturePanes, int count);

    template <std::size_t N>
    constexpr void
    PPaneRegister(nw4r::lyt::Picture** picturePanes, const char* const (&paneNames)[N])
    {
        return PPaneRegister(const_cast<const char**>(paneNames), picturePanes, N);
    }

    /* 0x800C8FA0 */
    void TPaneRegister(const char** paneNames, LytTextBox_c** textBoxPanes, int count);

    template <std::size_t N>
    constexpr void TPaneRegister(LytTextBox_c** textBoxPanes, const char* const (&paneNames)[N])
    {
        return TPaneRegister(const_cast<const char**>(paneNames), textBoxPanes, N);
    }

    /* 0x800C9010 */
    void TPaneNameRegister(const char** paneNames, const int* param2, int param3, int count);

    template <std::size_t N>
    constexpr void
    TPaneNameRegister(int param3, const char* const (&paneNames)[N], const int (&param2)[N])
    {
        return TPaneNameRegister(const_cast<const char**>(paneNames), param2, param3, N);
    }

    /* 0x800C90A0 */
    void AnimeResRegister(const char** animNames, int count);

    template <std::size_t N>
    constexpr void AnimeResRegister(const char* const (&animNames)[N])
    {
        return AnimeResRegister(const_cast<const char**>(animNames), N);
    }

    /* 0x800C91E0 */
    void GroupRegister(const char** groupNames, const int* param2, int count);

    template <std::size_t N>
    constexpr void GroupRegister(const char* const (&groupNames)[N], const int (&param2)[N])
    {
        return GroupRegister(const_cast<const char**>(groupNames), param2, N);
    }

    /* 0x800C93E0 */
    void AnimeStartSetup(int group, bool param2);

    /* 0x800C9470 */
    void LoopAnimeStartSetup(int group);

    /* 0x800C94C0 */
    void ReverseAnimeStartSetup(int group, bool param2);

    /* 0x800C9580 */
    void AnimeEndSetup(int param1);

    /* 0x800C95F0 */
    void AllAnimeEndSetup();

    /* 0x800C9650 */
    void AnimePlay();

    /* 0x800C9700 const added */
    bool isAnime(int group) const;

    /* 0x800C9730 const added */
    bool isAllAnime() const;

    /* 0x800C9A20 */
    fBase_c::PACK_RESULT_e doDelete();

public:
    // -----------
    // Member Data
    // -----------

    /* 0x0AC */ d2d::ResAccMultLoader_c mResAccLoader;

    FILL(0x180, 0x198);
};
