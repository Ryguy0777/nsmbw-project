# Root source files
SOURCES += source/Rel.cpp
SOURCES += source/Four.cpp

#
# wiimj2d/dynamic
#

# d_2d.cpp
# NSMBW: 0x80006790 - 0x80007510
SOURCES += source/wiimj2d/dynamic/d_2d.cpp

#
# wiimj2d/dynamic/enemies
#

# d_a_en_block_main.cpp
# NSMBW: 0x800208B0 - 0x80023C60
SOURCES += source/wiimj2d/dynamic/actor/enemies/d_a_en_block_main.cpp

#
# wiimj2d/dynamic/actor
#

# d_a_player_base.cpp
# NSMBW: 0x800460D0 - 0x8005B3A0
SOURCES += source/wiimj2d/dynamic/actor/d_a_player_base.cpp
# d_a_player_demo_manager.cpp
# NSMBW: 0x8005B3A0 - 0x8005D7E0
SOURCES += source/wiimj2d/dynamic/actor/d_a_player_demo_manager.cpp

# d_a_player_key.cpp
# NSMBW: 0x8005DFD0 - 0x8005E9A0
SOURCES += source/wiimj2d/dynamic/actor/d_a_player_key.cpp
# d_a_player_manager.cpp
# NSMBW: 0x8005E9A0 - 0x800613B0
SOURCES += source/wiimj2d/dynamic/actor/d_a_player_manager.cpp

#
# wiimj2d/dynamic
#

# d_actor.cpp
# NSMBW: 0x80064110 - 0x800660C0
SOURCES += source/wiimj2d/dynamic/d_actor.cpp

# d_base.cpp
# NSMBW: 0x8006C420 - 0x8006C6D0
SOURCES += source/wiimj2d/dynamic/d_base.cpp
# d_base_actor.cpp
# NSMBW: 0x8006C6D0 - 0x8006CF40
SOURCES += source/wiimj2d/dynamic/d_base_actor.cpp

# d_bg.cpp
# NSMBW: 0x80076FD0 - 0x8007E180
SOURCES += source/wiimj2d/dynamic/d_bg.cpp

# d_block_mng.cpp
# NSMBW: 0x80087F40 - 0x80088D90
SOURCES += source/wiimj2d/dynamic/d_block_mng.cpp

# d_course_data.cpp
# NSMBW: 0x8008DFF0 - 0x8008ECC0
SOURCES += source/wiimj2d/dynamic/d_course_data.cpp

# d_enemy.cpp
# NSMBW: 0x80094E80 - 0x800983C0
SOURCES += source/wiimj2d/dynamic/d_enemy.cpp

# d_fader.cpp
# NSMBW: 0x800B0A20 - 0x800B0EA0
SOURCES += source/wiimj2d/dynamic/d_fader.cpp

# d_fukidashiInfo.cpp
# NSMBW: 0x800B14E0 - 0x800B2D20
SOURCES += source/wiimj2d/dynamic/d_fukidashiInfo.cpp

# d_game_common.cpp
# NSMBW .text: 0x800B2E70 - 0x800B5930
SOURCES += source/wiimj2d/dynamic/d_game_common.cpp
# d_game_key.cpp
# NSMBW: 0x800B5930 - 0x800B5B50
SOURCES += source/wiimj2d/dynamic/d_game_key.cpp
# d_game_key_core.cpp
# NSMBW: 0x800B5B50 - 0x800B64A0
SOURCES += source/wiimj2d/dynamic/d_game_key_core.cpp

# d_info.cpp
# NSMBW .text: 0x800BB0E0 - 0x800BBD80
# NSMBW .data: 0x80315E90 - 0x80315EB0
# NSMBW .bss: 0x80359054 - 0x803590F0
# NSMBW .sbss: 0x8042A25C - 0x8042A268
SOURCES += source/wiimj2d/dynamic/d_info.cpp

# d_lytbase.cpp
# NSMBW: 0x800C89A0 - 0x800C9B50
SOURCES += source/wiimj2d/dynamic/d_lytbase.cpp

# d_mask_mng.cpp
# NSMBW: 0x800CD290 - 0x800CD800
SOURCES += source/wiimj2d/dynamic/d_mask_mng.cpp

# d_mj2d_game.cpp
# NSMBW: 0x800CDFB0 - 0x800CE660
SOURCES += source/wiimj2d/dynamic/d_mj2d_game.cpp
# d_mj2d_header.cpp
# NSMBW: 0x800CE660 - 0x800CE7F0
SOURCES += source/wiimj2d/dynamic/d_mj2d_header.cpp

# d_multi_manager.cpp
# NSMBW: 0x800CE8F0 - 0x800CED00
SOURCES += source/wiimj2d/dynamic/d_multi_manager.cpp

# d_kinopico_model.cpp
# NSMBW: ---
SOURCES += source/wiimj2d/dynamic/d_kinopico_model.cpp
# d_player_model.cpp
# NSMBW: 0x800D2EC0 - 0x800D5420
SOURCES += source/wiimj2d/dynamic/d_player_model.cpp
# d_player_model_base.cpp
# NSMBW: 0x800D5420 - 0x800D6DB0
SOURCES += source/wiimj2d/dynamic/d_player_model_base.cpp
# d_player_model_manager.cpp
# NSMBW: 0x800D6DB0 - 0x800D7190
SOURCES += source/wiimj2d/dynamic/d_player_model_manager.cpp

# d_remocon_mng.cpp
# NSMBW: 0x800DBFD0 - 0x800DDA40
SOURCES += source/wiimj2d/dynamic/d_remocon_mng.cpp

# d_resource_manager.cpp
# NSMBW: 0x800DF770 - 0x800DF950
# NSMBW .sbss: 0x8042A318 - 0x8042A31C
SOURCES += source/wiimj2d/dynamic/d_resource_manager.cpp

# d_save_manager.cpp
# NSMBW: 0x800E0270 - 0x800E1AA0
SOURCES += source/wiimj2d/dynamic/d_save_manager.cpp
# d_scene.cpp
# NSMBW .text: 0x800E1AA0 - 0x800E2070
# NSMBW .sdata: 0x80428A40 - 0x80428A50
SOURCES += source/wiimj2d/dynamic/d_scene.cpp

# d_system.cpp
# NSMBW: 0x800E46E0 - 0x800E5480
SOURCES += source/wiimj2d/dynamic/d_system.cpp

# d_CharacterChangeIndicator.cpp
# NSMBW d_bases.text: 0x8076D880 - 0x8076DEE0
SOURCES += source/wiimj2d/dynamic/d_CharacterChangeIndicator.cpp
# d_CharacterChangeSelectArrow.cpp
# NSMBW d_bases.text: 0x8076DEE0 - 0x8076F350
SOURCES += source/wiimj2d/dynamic/d_CharacterChangeSelectArrow.cpp
# d_CharacterChangeSelectBase.cpp
# NSMBW d_bases.text: 0x8076F350 - 0x80772A50
SOURCES += source/wiimj2d/dynamic/d_CharacterChangeSelectBase.cpp
# d_CharacterChangeSelectContents.cpp
# NSMBW: 0x80772A50 - 0x80773F30
SOURCES += source/wiimj2d/dynamic/d_CharacterChangeSelectContents.cpp

# d_NumberOfPeopleChange.cpp
# NSMBW d_bases.text: 0x8079F630 - 0x807A2CF0
SOURCES += source/wiimj2d/dynamic/d_NumberOfPeopleChange.cpp

# d_SelectPlayer.cpp
# NSMBW: 0x807ABE10 - 0x807AD5F0
SOURCES += source/wiimj2d/dynamic/d_SelectPlayer.cpp

#
# wiimj2d/dynamic/worldmap
#

# d_wm_actor.cpp
# NSMBW: 0x800F2820 - 0x800F2C00
SOURCES += source/wiimj2d/dynamic/worldmap/d_wm_actor.cpp

# d_wm_demo_actor.cpp
# NSMBW: 0x800F60E0 - 0x800F7050
SOURCES += source/wiimj2d/dynamic/worldmap/d_wm_demo_actor.cpp

# d_wm_path.cpp
# NSMBW: 0x800FDB60 - 0x800FDC40
SOURCES += source/wiimj2d/dynamic/worldmap/d_wm_path.cpp
# d_wm_player_base.cpp
# NSMBW: 0x800FDC40 - 0x800FE140
SOURCES += source/wiimj2d/dynamic/worldmap/d_wm_player_base.cpp

#
# wiimj2d/dynamic/actor/objects
#

# d_a_obj_grass.cpp
# NSMBW: 0x808760E0 - 0x80877510
SOURCES += source/wiimj2d/dynamic/actor/objects/d_a_obj_grass.cpp

#
# wiimj2d/dynamic/actor/worldmap
#

# d_a_2d_player.cpp
# NSMBW d_bases.text: 0x808C5100 - 0x808C7D10
SOURCES += source/wiimj2d/dynamic/actor/worldmap/d_a_2d_player.cpp

# d_a_wm_player_static.cpp
# NSMBW .text: 0x80100A10 - 0x801016B0
# NSMBW .sbss: 0x8042A47E - 0x8042A484
SOURCES += source/wiimj2d/dynamic/actor/worldmap/d_a_wm_player_static.cpp

# d_a_wm_sub_player.cpp
# NSMBW d_bases.text: 0x808E8AA0 - 0x808EF8D0
SOURCES += source/wiimj2d/dynamic/actor/worldmap/d_a_wm_sub_player.cpp

# d_a_wm_player.cpp
# NSMBW d_bases.text: 0x80902790 - 0x8090D220
SOURCES += source/wiimj2d/dynamic/actor/worldmap/d_a_wm_player.cpp

#
# wiimj2d/dynamic/scene
#

# d_s_stage_static.cpp
# NSMBW: 0x80101A50 - 0x8010276C
SOURCES += source/wiimj2d/dynamic/scene/d_s_stage_static.cpp

#
# wiimj2d/dynamic/worldmap
#

# d_wm_effectManager.cpp
# NSMBW: 0x80103020 - 0x801038D0
SOURCES += source/wiimj2d/dynamic/worldmap/d_wm_effectManager.cpp

#
# wiimj2d/dynamic
#

# d_WiiStrap.cpp
# NSMBW: 0x8010F080 - 0x8010F530
SOURCES += source/wiimj2d/dynamic/d_WiiStrap.cpp

#
# wiimj2d/dynamic/actor
#

# d_a_fireball_player.cpp
# NSMBW: 0x8011A5B0 - 0x8011B640
SOURCES += source/wiimj2d/dynamic/actor/d_a_fireball_player.cpp

# d_a_iceball.cpp
# NSMBW: 0x801233F0 - 0x80124D40
SOURCES += source/wiimj2d/dynamic/actor/d_a_iceball.cpp

# d_a_mask.cpp
# NSMBW: 0x80124EB0 - 0x80126650
SOURCES += source/wiimj2d/dynamic/actor/d_a_mask.cpp
# d_a_player.cpp
# NSMBW: 0x80126650 - 0x8014A480
SOURCES += source/wiimj2d/dynamic/actor/d_a_player.cpp

#
# wiimj2d/dynamic
#

# d_bg_gm.cpp
# NSMBW: 0x80154800 - 0x80156FE0
SOURCES += source/wiimj2d/dynamic/d_bg_gm.cpp
# d_fukidashiManager.cpp
# NSMBW: 0x80156FE0 - 0x80157820
SOURCES += source/wiimj2d/dynamic/d_fukidashiManager.cpp

#
# wiimj2d/dynamic/scene
#

# d_s_boot.cpp
# NSMBW: 0x8015C270 - 0x8015F270
SOURCES += source/wiimj2d/dynamic/scene/d_s_boot.cpp

# d_s_game_setup.cpp
# NSMBW d_bases.text: 0x80917960 - 0x8091A2F0
SOURCES += source/wiimj2d/dynamic/scene/d_s_game_setup.cpp

# d_s_world_9_demo.cpp
# NSMBW d_bases.text: 0x8091CB70 - 0x8091EB60
SOURCES += source/wiimj2d/dynamic/scene/d_s_world_9_demo.cpp

# d_s_crsin.cpp
# NSMBW d_bases.text: 0x8091EC10 - 0x80921060
SOURCES += source/wiimj2d/dynamic/scene/d_s_crsin.cpp

#
# dynamic/actor/enemies
#

# d_a_en_big_block.cpp
# NSMBW: 0x809B88C0 - 0x809B9DF0
SOURCES += source/wiimj2d/dynamic/actor/enemies/d_a_en_big_block.cpp

# d_a_en_block.cpp
# NSMBW: 0x809BED80 - 0x809C0770
SOURCES += source/wiimj2d/dynamic/actor/enemies/d_a_en_block.cpp

# d_a_en_goalpole.cpp
# NSMBW: 0x80A096E0 - 0x80A0BE30
SOURCES += source/wiimj2d/dynamic/actor/enemies/d_a_en_goalpole.cpp

# d_a_en_item.cpp
# NSMBW: 0x80A26A80 - 0x80A2D610
SOURCES += source/wiimj2d/dynamic/actor/enemies/d_a_en_item.cpp

#
# wiimj2d/state
#

# s_Print.cpp
# NSMBW: 0x8015F810 - 0x8015F900
SOURCES += source/wiimj2d/state/s_Print.cpp
# s_StateID.cpp
# NSMBW: 0x8015F900 - 0x8015FAE0
SOURCES += source/wiimj2d/state/s_StateID.cpp
# s_StateMethod.cpp
# NSMBW: 0x8015FAE0 - 0x8015FDD0
SOURCES += source/wiimj2d/state/s_StateMethod.cpp

#
# wiimj2d/framework
#

# f_base.cpp
# NSMBW: 0x80161C10 - 0x80162C80
SOURCES += source/wiimj2d/framework/f_base.cpp

# f_manager.cpp
# NSMBW: 0x80162E30 - 0x80163130
SOURCES += source/wiimj2d/framework/f_manager.cpp

#
# wiimj2d/machine/m3d
#

# m_anmtexpat.cpp
# NSMBW: 0x80166560 - 0x80167140
SOURCES += source/wiimj2d/machine/m3d/m_anmtexpat.cpp

# m_mdl.cpp
# NSMBW: 0x801696A0 - 0x8016A150
SOURCES += source/wiimj2d/machine/m3d/m_mdl.cpp

#
# wiimj2d/machine
#

# m_dvd.cpp
# NSMBW: 0x8016B090 - 0x8016C540
SOURCES += source/wiimj2d/machine/m_dvd.cpp

# m_fader.cpp
# NSMBW .text: 0x8016DBE0 - 0x8016DD40
# NSMBW .sbss: 0x8042A720 - 0x8042A728
SOURCES += source/wiimj2d/machine/m_fader.cpp

# m_heap.cpp
# NSMBW .bss: 0x80377F48 - 0x80377F58
SOURCES += source/wiimj2d/machine/m_heap.cpp

# m_pad.cpp
# NSMBW: 0x8016F330 - 0x8016F880
SOURCES += source/wiimj2d/machine/m_pad.cpp

# m_vec.cpp
# NSMBW .text: 0x80170AC0 - 0x80170D90
# NSMBW .bss: 0x803780C8 - 0x803780F8
SOURCES += source/wiimj2d/machine/m_vec.cpp

#
# revolution/arc
#

# arc.c
# NSMBW: 0x8019F7A0 - 0x801A0190
SOURCES += source/revolution/arc/arc.c

#
# revolution/os
#

# OSCache.c
# NSMBW: 0x801AC560 - 0x801ACC10
SOURCES += source/revolution/os/OSCache.c

# OSError.c
# NSMBW: 0x801AD620 - 0x801ADCE0
SOURCES += source/revolution/os/OSError.c

# OSFatal.c
# NSMBW: 0x801AF2C0 - 0x801AFEF0
SOURCES += source/revolution/os/OSFatal.c

# OSInterrupt.c
# NSMBW: 0x801B1280 - 0x801B1A50
SOURCES += source/revolution/os/OSInterrupt.c
# OSLink.c
# NSMBW: 0x801B1A50 - 0x801B24D0
SOURCES += source/revolution/os/OSLink.c

# OSTime.c
# NSMBW: 0x801B60C0 - 0x801B64F0
SOURCES += source/revolution/os/OSTime.c

#
# revolution/si
#

# SIBios.c
# NSMBW: 0x801BA940 - 0x801BB980
SOURCES += source/revolution/si/SIBios.c
# SISamplingRate.c
# NSMBW: 0x801BB980 - 0x801BBA70
SOURCES += source/revolution/si/SISamplingRate.c

#
# revolution/vi
#

# vi.c
# NSMBW: 0x801BBB70 - 0x801BE5C0
SOURCES += source/revolution/vi/vi.c
# i2c.c
# NSMBW: 0x801BE5C0 - 0x801BEEE0
SOURCES += source/revolution/vi/i2c.c
# vi3in1.c
# NSMBW: 0x801BEEE0 - 0x801C0610
SOURCES += source/revolution/vi/vi3in1.c

#
# revolution/dvd
#

# dvdfs.c
# NSMBW: 0x801CA790 - 0x801CADA0
SOURCES += source/revolution/dvd/dvdfs.c

#
# revolution/pad
#

# Pad.c
# NSMBW: 0x801DDB10 - 0x801DDB70
SOURCES += source/revolution/pad/Pad.c

#
# revolution/wpad
#

# WPAD.c
# NSMBW: 0x801DDC90 - 0x801E55A0
SOURCES += source/revolution/wpad/WPAD.c

#
# revolution/kpad
#

# KPAD.c
# NSMBW: 0x801EAA80 - 0x801EEAE0
SOURCES += source/revolution/kpad/KPAD.c

#
# nw4r/g3d
#

# g3d_resfile.cpp
# NSMBW: 0x80239F70 - 0x8023B2F0
SOURCES += source/nw4r/g3d/ResFile.cpp

#
# egg/core
#

# eggDvdFile.cpp
# NSMBW: 0x802B7C00 - 0x802B8010
SOURCES += source/egg/core/eggDvdFile.cpp
# eggDvdRipper.cpp
# NSMBW: 0x802B8010 - 0x802B8560
SOURCES += source/egg/core/eggDvdRipper.cpp
# eggStreamDecomp.cpp
# NSMBW: 0x802B8560 - 0x802B8BB0
SOURCES += source/egg/core/eggStreamDecomp.cpp

# eggHeap.cpp
# NSMBW: 0x802B8C80 - 0x802B93E0
SOURCES += source/egg/core/eggHeap.cpp
# eggExpHeap.cpp
# NSMBW: 0x802B93E0 - 0x802B98C0
SOURCES += source/egg/core/eggExpHeap.cpp

# eggDisposer.cpp
# NSMBW: 0x802BA410 - 0x802BA4F0
SOURCES += source/egg/core/eggDisposer.cpp

# eggController.cpp
# NSMBW: 0x802BC9D0 - 0x802BE710
SOURCES += source/egg/core/eggController.cpp

#
# runtime
#

# __mem.c
# NSMBW .init: 0x80004364 - 0x800046E4
# NSMBW .text: 0x802DC98C - 0x802DC9A8
SOURCES += source/runtime/__mem.c

#
# msl/msl_c
#

# mem.c
# NSMBW: 0x802DF264 - 0x802DF3D4
SOURCES += source/msl/msl_c/mem.c

# printf.c
# NSMBW: 0x802DF7A8 - 0x802E1BA0
SOURCES += source/msl/msl_c/printf.c
# scanf.c
# NSMBW: 0x802E1BA0 - 0x802E1C28
SOURCES += source/msl/msl_c/scanf.c
# string.c
# NSMBW: 0x802E1C28 - 0x802E4FC8
SOURCES += source/msl/msl_c/string.c