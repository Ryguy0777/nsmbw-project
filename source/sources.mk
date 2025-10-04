# Note: Uppercase letters are always sorted before lowercase

# Root source files
SOURCES += source/Rel.cpp
SOURCES += source/Four.cpp

#
# wiimj2d/d_system
# NSMBW          .text:  0x80006790 - 0x800FFF80
# NSMBW   d_bases.text:  0x8092F020 - 0x80932F60
#

# d_2d.cpp
# NSMBW          .text:  0x80006790 - 0x80007510
SOURCES += source/wiimj2d/d_system/d_2d.cpp

# d_CourseSelectGuide.cpp
# NSMBW          .text:  0x8000FC30 - 0x80014330
SOURCES += source/wiimj2d/d_system/d_CourseSelectGuide.cpp
# d_CourseSelectManager.cpp
# NSMBW   d_bases.text:  0x8092F020 - 0x80932F60
SOURCES += source/wiimj2d/d_system/d_CourseSelectManager.cpp

# d_SmallScore.cpp
# NSMBW          .text:  0x80014F10 - 0x80015D60
SOURCES += source/wiimj2d/d_system/d_SmallScore.cpp

# d_a_en_block_main.cpp
# NSMBW          .text:  0x800208B0 - 0x80023C60
SOURCES += source/wiimj2d/d_system/d_a_en_block_main.cpp

# d_a_en_dpakkun_base.cpp
# NSMBW          .text:  0x8002CB70 - 0x8002EF50
SOURCES += source/wiimj2d/d_system/d_a_en_dpakkun_base.cpp
# d_a_en_jimen_pakkun_base.cpp
# NSMBW          .text:  0x8002EF50 - 0x800311E0
SOURCES += source/wiimj2d/d_system/d_a_en_jimen_pakkun_base.cpp

# d_a_en_shell.cpp
# NSMBW          .text:  0x80037EA0 - 0x8003C9F0
SOURCES += source/wiimj2d/d_system/d_a_en_shell.cpp

# d_a_lift_remocon_main.cpp
# NSMBW          .text:  0x800439B0 - 0x80044460
SOURCES += source/wiimj2d/d_system/d_a_lift_remocon_main.cpp

# d_a_player_base.cpp
# NSMBW          .text:  0x800460D0 - 0x8005B3A0
SOURCES += source/wiimj2d/d_system/d_a_player_base.cpp
# d_a_player_demo_manager.cpp
# NSMBW          .text:  0x8005B3A0 - 0x8005D7E0
SOURCES += source/wiimj2d/d_system/d_a_player_demo_manager.cpp

# d_a_player_key.cpp
# NSMBW          .text:  0x8005DFD0 - 0x8005E9A0
SOURCES += source/wiimj2d/d_system/d_a_player_key.cpp
# d_a_player_manager.cpp
# NSMBW          .text:  0x8005E9A0 - 0x800613B0
SOURCES += source/wiimj2d/d_system/d_a_player_manager.cpp

# d_actor.cpp
# NSMBW          .text:  0x80064110 - 0x800660C0
SOURCES += source/wiimj2d/d_system/d_actor.cpp
# d_actor_groupid_mng.cpp
# NSMBW          .text:  0x800660C0 - 0x80066380
SOURCES += source/wiimj2d/d_system/d_actor_groupid_mng.cpp
# d_actor_mng.cpp
# NSMBW          .text:  0x80066380 - 0x80066FB0
SOURCES += source/wiimj2d/d_system/d_actor_mng.cpp
# d_actor_name.cpp
# NSMBW: ---
SOURCES += source/wiimj2d/d_system/d_actor_name.cpp
# d_actor_state.cpp
# NSMBW          .text:  0x80066FB0 - 0x80068040
SOURCES += source/wiimj2d/d_system/d_actor_state.cpp
# d_actorcreate_mng.cpp
# NSMBW          .text:  0x80068040 - 0x80069020
SOURCES += source/wiimj2d/d_system/d_actorcreate_mng.cpp

# d_attention.cpp
# NSMBW          .text:  0x800690F0 - 0x80069500
SOURCES += source/wiimj2d/d_system/d_attention.cpp
# d_audio.cpp
# NSMBW          .text:  0x80069500 - 0x8006C0B0
# NSMBW          .bss:   0x803561E8 - 0x80356208
SOURCES += source/wiimj2d/d_system/d_audio.cpp
# d_balloon_mng.cpp
# NSMBW          .text:  0x8006C0B0 - 0x8006C420
SOURCES += source/wiimj2d/d_system/d_balloon_mng.cpp
# d_base.cpp
# NSMBW          .text:  0x8006C420 - 0x8006C6D0
SOURCES += source/wiimj2d/d_system/d_base.cpp
# d_base_actor.cpp
# NSMBW          .text:  0x8006C6D0 - 0x8006CF40
SOURCES += source/wiimj2d/d_system/d_base_actor.cpp

# d_beans_kuribo_mng.cpp
# NSMBW          .text:  0x80076BC0 - 0x80076FD0
SOURCES += source/wiimj2d/d_system/d_beans_kuribo_mng.cpp
# d_bg.cpp
# NSMBW          .text:  0x80076FD0 - 0x8007E180
SOURCES += source/wiimj2d/d_system/d_bg.cpp

# d_bg_ctr.cpp
# NSMBW          .text:  0x8007F7A0 - 0x80081070
SOURCES += source/wiimj2d/d_system/d_bg_ctr.cpp

# d_bg_parameter.cpp
# NSMBW          .text:  0x80081D20 - 0x800822E0
SOURCES += source/wiimj2d/d_system/d_bg_parameter.cpp

# d_block_mng.cpp
# NSMBW          .text:  0x80087F40 - 0x80088D90
SOURCES += source/wiimj2d/d_system/d_block_mng.cpp

# d_cc.cpp
# NSMBW          .text:  0x8008C200 - 0x8008DC80
SOURCES += source/wiimj2d/d_system/d_cc.cpp

# d_coin.cpp
# NSMBW          .text:  0x8008DED0 - 0x8008DFF0
SOURCES += source/wiimj2d/d_system/d_coin.cpp
# d_course_data.cpp
# NSMBW          .text:  0x8008DFF0 - 0x8008ECC0
SOURCES += source/wiimj2d/d_system/d_course_data.cpp

# d_cyuukan.cpp
# NSMBW          .text:  0x8008ED70 - 0x8008F110
SOURCES += source/wiimj2d/d_system/d_cyuukan.cpp

# d_effactor_mng.cpp
# NSMBW          .text:  0x8008FE30 - 0x80092C00
SOURCES += source/wiimj2d/d_system/d_effactor_mng.cpp

# d_enemy.cpp
# NSMBW          .text:  0x80094E80 - 0x800983C0
SOURCES += source/wiimj2d/d_system/d_enemy.cpp
# d_enemy_boss.cpp
# NSMBW          .text:  0x800983C0 - 0x8009AD30
SOURCES += source/wiimj2d/d_system/d_enemy_boss.cpp

# d_enemy_boyon.cpp
# NSMBW          .text:  0x8009EA30 - 0x8009EAF0
SOURCES += source/wiimj2d/d_system/d_enemy_boyon.cpp
# d_enemy_carry.cpp
# NSMBW          .text:  0x8009EAF0 - 0x8009F5F0
SOURCES += source/wiimj2d/d_system/d_enemy_carry.cpp
# d_enemy_death.cpp
# NSMBW          .text:  0x8009F5F0 - 0x800A2870
SOURCES += source/wiimj2d/d_system/d_enemy_death.cpp
# d_enemy_fumi.cpp
# NSMBW          .text:  0x800A2870 - 0x800A2B70
SOURCES += source/wiimj2d/d_system/d_enemy_fumi.cpp

# d_enemy_manager.cpp
# NSMBW          .text:  0x800A7450 - 0x800A7DA0
SOURCES += source/wiimj2d/d_system/d_enemy_manager.cpp

# d_enemy_toride_kokoopa_slide.cpp
# NSMBW          .text:  0x800B0800 - 0x800B0A20
SOURCES += source/wiimj2d/d_system/d_enemy_toride_kokoopa_slide.cpp
# d_fader.cpp
# NSMBW          .text:  0x800B0A20 - 0x800B0EA0
SOURCES += source/wiimj2d/d_system/d_fader.cpp

# d_fukidashiInfo.cpp
# NSMBW          .text:  0x800B14E0 - 0x800B2D20
SOURCES += source/wiimj2d/d_system/d_fukidashiInfo.cpp

# d_game_common.cpp
# NSMBW          .text:  0x800B2E70 - 0x800B5930
SOURCES += source/wiimj2d/d_system/d_game_common.cpp
# d_game_key.cpp
# NSMBW          .text:  0x800B5930 - 0x800B5B50
SOURCES += source/wiimj2d/d_system/d_game_key.cpp
# d_game_key_core.cpp
# NSMBW          .text:  0x800B5B50 - 0x800B64A0
SOURCES += source/wiimj2d/d_system/d_game_key_core.cpp

# d_info.cpp
# NSMBW          .text:  0x800BB0E0 - 0x800BBD80
# NSMBW          .data:  0x80315E90 - 0x80315EB0
# NSMBW          .bss:   0x80359054 - 0x803590F0
# NSMBW          .sbss:  0x8042A25C - 0x8042A268
SOURCES += source/wiimj2d/d_system/d_info.cpp

# d_kinopico_model.cpp
# NSMBW: ---
SOURCES += source/wiimj2d/d_system/d_kinopico_model.cpp
# d_kinopio_model.cpp
# NSMBW          .text:  0x800BCBD0 - 0x800BD7F0
SOURCES += source/wiimj2d/d_system/d_kinopio_model.cpp

# d_lytbase.cpp
# NSMBW          .text:  0x800C89A0 - 0x800C9B50
SOURCES += source/wiimj2d/d_system/d_lytbase.cpp
# d_lyttextbox.cpp
# NSMBW          .text:  0x800C9B50 - 0x800CA000
SOURCES += source/wiimj2d/d_system/d_lyttextbox.cpp

# d_mask_mng.cpp
# NSMBW          .text:  0x800CD290 - 0x800CD800
SOURCES += source/wiimj2d/d_system/d_mask_mng.cpp

# d_message.cpp
# NSMBW          .text:  0x800CDB60 - 0x800CDFB0
SOURCES += source/wiimj2d/d_system/d_message.cpp
# d_mj2d_game.cpp
# NSMBW          .text:  0x800CDFB0 - 0x800CE660
SOURCES += source/wiimj2d/d_system/d_mj2d_game.cpp
# d_mj2d_header.cpp
# NSMBW          .text:  0x800CE660 - 0x800CE7F0
SOURCES += source/wiimj2d/d_system/d_mj2d_header.cpp
# d_mj2d_json_handler.cpp
# NSMBW: ---
SOURCES += source/wiimj2d/d_system/d_mj2d_json_handler.cpp

# d_multi_manager.cpp
# NSMBW          .text:  0x800CE8F0 - 0x800CED00
SOURCES += source/wiimj2d/d_system/d_multi_manager.cpp
# d_nand_thread.cpp
# NSMBW          .text:  0x800CED00 - 0x800CFCB0
SOURCES += source/wiimj2d/d_system/d_nand_thread.cpp

# d_next.cpp
# NSMBW          .text:  0x800CFCE0 - 0x800D03C0
SOURCES += source/wiimj2d/d_system/d_next.cpp

# d_pause_manager.cpp
# NSMBW          .text:  0x800D0A90 - 0x800D15F0
SOURCES += source/wiimj2d/d_system/d_pause_manager.cpp

# d_player_effect.cpp
# NSMBW          .text:  0x800D2AE0 - 0x800D2D10
SOURCES += source/wiimj2d/d_system/d_player_effect.cpp
# d_player_effect_mng.cpp
# NSMBW          .text:  0x800D2D10 - 0x800D2EC0
SOURCES += source/wiimj2d/d_system/d_player_effect_mng.cpp
# d_player_model.cpp
# NSMBW          .text:  0x800D2EC0 - 0x800D5420
SOURCES += source/wiimj2d/d_system/d_player_model.cpp
# d_player_model_base.cpp
# NSMBW          .text:  0x800D5420 - 0x800D6DB0
SOURCES += source/wiimj2d/d_system/d_player_model_base.cpp
# d_player_model_manager.cpp
# NSMBW          .text:  0x800D6DB0 - 0x800D7190
SOURCES += source/wiimj2d/d_system/d_player_model_manager.cpp

# d_quake.cpp
# NSMBW          .text:  0x800D8940 - 0x800D91B0
SOURCES += source/wiimj2d/d_system/d_quake.cpp

# d_remocon_mng.cpp
# NSMBW          .text:  0x800DBFD0 - 0x800DDA40
SOURCES += source/wiimj2d/d_system/d_remocon_mng.cpp

# d_resource_manager.cpp
# NSMBW          .text:  0x800DF770 - 0x800DF950
# NSMBW          .sbss:  0x8042A318 - 0x8042A31C
SOURCES += source/wiimj2d/d_system/d_resource_manager.cpp

# d_save_manager.cpp
# NSMBW          .text:  0x800E0270 - 0x800E1AA0
SOURCES += source/wiimj2d/d_system/d_save_manager.cpp
# d_scene.cpp
# NSMBW          .text:  0x800E1AA0 - 0x800E2070
# NSMBW          .sdata: 0x80428A40 - 0x80428A50
SOURCES += source/wiimj2d/d_system/d_scene.cpp
# d_score_manager.cpp
# NSMBW          .text:  0x800E2070 - 0x800E2640
SOURCES += source/wiimj2d/d_system/d_score_manager.cpp

# d_stage_timer.cpp
# NSMBW          .text:  0x800E38E0 - 0x800E3BA0
SOURCES += source/wiimj2d/d_system/d_stage_timer.cpp
# d_start_info.cpp
# NSMBW          .text:  0x800E3BA0 - 0x800E3BD0
SOURCES += source/wiimj2d/d_system/d_start_info.cpp
# d_switch_flag_mng.cpp
# NSMBW          .text:  0x800E3BD0 - 0x800E46E0
SOURCES += source/wiimj2d/d_system/d_switch_flag_mng.cpp
# d_system.cpp
# NSMBW          .text:  0x800E46E0 - 0x800E5480
SOURCES += source/wiimj2d/d_system/d_system.cpp

# d_tencoin_mng.cpp
# NSMBW          .text:  0x800E75D0 - 0x800E78D0
SOURCES += source/wiimj2d/d_system/d_tencoin_mng.cpp

# d_wm_actor.cpp
# NSMBW          .text:  0x800F2820 - 0x800F2C00
SOURCES += source/wiimj2d/d_system/d_wm_actor.cpp

# d_wm_demo_actor.cpp
# NSMBW          .text:  0x800F60E0 - 0x800F7050
SOURCES += source/wiimj2d/d_system/d_wm_demo_actor.cpp

# d_wm_lib.cpp
# NSMBW          .text:  0x800F9380 - 0x800FD6A0
SOURCES += source/wiimj2d/d_system/d_wm_lib.cpp

# d_wm_path.cpp
# NSMBW          .text:  0x800FDB60 - 0x800FDC40
SOURCES += source/wiimj2d/d_system/d_wm_path.cpp
# d_wm_player_base.cpp
# NSMBW          .text:  0x800FDC40 - 0x800FE140
SOURCES += source/wiimj2d/d_system/d_wm_player_base.cpp

#
# wiimj2d/d_bases
#

# d_CharacterChangeIndicator.cpp
# NSMBW   d_bases.text:  0x8076D880 - 0x8076DEE0
SOURCES += source/wiimj2d/d_bases/d_CharacterChangeIndicator.cpp
# d_CharacterChangeSelectArrow.cpp
# NSMBW   d_bases.text:  0x8076DEE0 - 0x8076F350
SOURCES += source/wiimj2d/d_bases/d_CharacterChangeSelectArrow.cpp
# d_CharacterChangeSelectBase.cpp
# NSMBW   d_bases.text:  0x8076F350 - 0x80772A50
SOURCES += source/wiimj2d/d_bases/d_CharacterChangeSelectBase.cpp
# d_CharacterChangeSelectContents.cpp
# NSMBW   d_bases.text:  0x80772A50 - 0x80773F30
SOURCES += source/wiimj2d/d_bases/d_CharacterChangeSelectContents.cpp

# d_MessageWindow.cpp
# NSMBW   d_bases.text:  0x         - 0x8078BC60
# d_MiniGameCannon.cpp
# NSMBW   d_bases.text:  0x8078BC60 - 0x8078DA20
SOURCES += source/wiimj2d/d_bases/d_MiniGameCannon.cpp
# d_MiniGameWire.cpp
# NSMBW   d_bases.text:  0x8078DA20 - 0x
# d_NumberOfPeopleChange.cpp
# NSMBW   d_bases.text:  0x8079F630 - 0x807A2CF0
SOURCES += source/wiimj2d/d_bases/d_NumberOfPeopleChange.cpp

# d_SelectPlayer.cpp
# NSMBW   d_bases.text:  0x807ABE10 - 0x807AD5F0
SOURCES += source/wiimj2d/d_bases/d_SelectPlayer.cpp

# d_StockItem.cpp
# NSMBW   d_bases.text:  0x807AF370 - 0x807B2030
SOURCES += source/wiimj2d/d_bases/d_StockItem.cpp

# d_a_castle_kokoopa_demo_1st.cpp
# NSMBW   d_bases.text:  0x807DAC10 - 0x807DCD80
SOURCES += source/wiimj2d/d_bases/d_a_castle_kokoopa_demo_1st.cpp
# d_a_castle_kokoopa_demo_2nd.cpp
# NSMBW   d_bases.text:  0x807DCD80 - 0x807DDCC0
SOURCES += source/wiimj2d/d_bases/d_a_castle_kokoopa_demo_2nd.cpp

# d_a_chukan_point.cpp
# NSMBW   d_bases.text:  0x807E2040 - 0x807E38A0
SOURCES += source/wiimj2d/d_bases/d_a_chukan_point.cpp

# d_a_last_actor_stage.cpp
# NSMBW   d_bases.text:  0x80830690 - 0x80830C40
SOURCES += source/wiimj2d/d_bases/d_a_last_actor_stage.cpp

# d_a_lift_fall.cpp
# NSMBW   d_bases.text:  0x80837370 - 0x80838020
SOURCES += source/wiimj2d/d_bases/d_a_lift_fall.cpp

# d_a_lift_ride_move.cpp
# NSMBW   d_bases.text:  0x80845940 - 0x808468E0
SOURCES += source/wiimj2d/d_bases/d_a_lift_ride_move.cpp

# d_a_line_kinoko_block.cpp
# NSMBW   d_bases.text:  0x80857490 - 0x808581A0
SOURCES += source/wiimj2d/d_bases/d_a_line_kinoko_block.cpp

# d_a_line_train.cpp
# NSMBW   d_bases.text:  0x80859440 - 0x8085BCB0
SOURCES += source/wiimj2d/d_bases/d_a_line_train.cpp

# d_a_mini_game_gun_battery_mgr.cpp
# NSMBW   d_bases.text:  0x808660F0 - 0x808672B0
SOURCES += source/wiimj2d/d_bases/d_a_mini_game_gun_battery_mgr.cpp

# d_a_mini_game_wire_mesh.cpp
# NSMBW:  d_bases.text:  0x808681B0 - 0x8086A040
SOURCES += source/wiimj2d/d_bases/d_a_mini_game_wire_mesh.cpp
# d_a_mini_game_wire_mesh_mgr.cpp
# NSMBW   d_bases.text:  0x8086A040 - 0x8086C8F0
SOURCES += source/wiimj2d/d_bases/d_a_mini_game_wire_mesh_mgr.cpp

# d_a_next_goto_block.cpp
# NSMBW   d_bases.text:  0x8086E670 - 0x8086EEA0
SOURCES += source/wiimj2d/d_bases/d_a_next_goto_block.cpp
# d_a_nice_boat.cpp
# NSMBW   d_bases.text:  0x8086EEA0 - 0x808724E0
SOURCES += source/wiimj2d/d_bases/d_a_nice_boat.cpp

# d_a_obj_grass.cpp
# NSMBW   d_bases.text:  0x808760E0 - 0x80877510
SOURCES += source/wiimj2d/d_bases/d_a_obj_grass.cpp

# d_a_reverse_block.cpp
# NSMBW   d_bases.text:  0x80897F60 - 0x808984D0
SOURCES += source/wiimj2d/d_bases/d_a_reverse_block.cpp

# d_a_wm_2DPlayer.cpp
# NSMBW   d_bases.text:  0x808C5100 - 0x808C7D10
SOURCES += source/wiimj2d/d_bases/d_a_wm_2DPlayer.cpp

# d_a_wm_Item.cpp
# NSMBW   d_bases.text:  0x808D4890 - 0x808D50B0
SOURCES += source/wiimj2d/d_bases/d_a_wm_Item.cpp
# d_a_wm_Killer.cpp
# NSMBW   d_bases.text:  0x808D50B0 - 0x808D5E50
SOURCES += source/wiimj2d/d_bases/d_a_wm_Killer.cpp
# d_a_wm_KillerBullet.cpp
# NSMBW   d_bases.text:  0x808D5E50 - 0x808D78C0
SOURCES += source/wiimj2d/d_bases/d_a_wm_KillerBullet.cpp
# d_a_wm_KinoBalloon.cpp
# NSMBW   d_bases.text:  0x808D78C0 - 0x808D8860
SOURCES += source/wiimj2d/d_bases/d_a_wm_KinoBalloon.cpp

# d_a_wm_KoopaShip.cpp
# NSMBW   d_bases.text:  0x808DBCB0 - 0x808DE620
SOURCES += source/wiimj2d/d_bases/d_a_wm_KoopaShip.cpp
# d_a_wm_Manta.cpp
# NSMBW   d_bases.text:  0x808DE620 - 0x808DEA90
SOURCES += source/wiimj2d/d_bases/d_a_wm_Manta.cpp
# d_a_wm_Map.cpp
# NSMBW   d_bases.text:  0x808DEA90 - 0x808E3700
SOURCES += source/wiimj2d/d_bases/d_a_wm_Map.cpp
# d_a_wm_Map_static.cpp
# NSMBW          .text:  0x80100140 - 0x80100A10
SOURCES += source/wiimj2d/d_bases/d_a_wm_Map_static.cpp
# d_a_wm_Note.cpp
# NSMBW   d_bases.text:  0x808E3700 - 0x808E3DA0
SOURCES += source/wiimj2d/d_bases/d_a_wm_Note.cpp
# d_a_wm_Peach.cpp
# NSMBW   d_bases.text:  0x808E3DA0 - 0x808E4440
SOURCES += source/wiimj2d/d_bases/d_a_wm_Peach.cpp
# d_a_wm_PeachCastle.cpp
# NSMBW   d_bases.text:  0x808E4440 - 0x808E4E00
SOURCES += source/wiimj2d/d_bases/d_a_wm_PeachCastle.cpp

# d_a_wm_SubPlayer.cpp
# NSMBW   d_bases.text:  0x808E8AA0 - 0x808EF8D0
SOURCES += source/wiimj2d/d_bases/d_a_wm_SubPlayer.cpp

# d_a_wm_player.cpp
# NSMBW   d_bases.text:  0x80902790 - 0x8090D220
SOURCES += source/wiimj2d/d_bases/d_a_wm_player.cpp
# d_a_wm_player_static.cpp
# NSMBW          .text:  0x80100A10 - 0x801016B0
# NSMBW          .sbss:  0x8042A47E - 0x8042A484
SOURCES += source/wiimj2d/d_bases/d_a_wm_player_static.cpp

# d_s_GameSetup.cpp
# NSMBW   d_bases.text:  0x80917960 - 0x8091A2F0
SOURCES += source/wiimj2d/d_bases/d_s_GameSetup.cpp

# d_s_World9DeMo.cpp
# NSMBW   d_bases.text:  0x8091CB70 - 0x8091EB60
SOURCES += source/wiimj2d/d_bases/d_s_World9DeMo.cpp

# d_s_crsin.cpp
# NSMBW   d_bases.text:  0x8091EC10 - 0x80921060
SOURCES += source/wiimj2d/d_bases/d_s_crsin.cpp
# d_s_game_over.cpp
# NSMBW   d_bases.text:  0x80921060 - 0x80922060
SOURCES += source/wiimj2d/d_bases/d_s_game_over.cpp
# d_s_movie.cpp
# NSMBW   d_bases.text:  0x80922060 - 0x80923970
SOURCES += source/wiimj2d/d_bases/d_s_movie.cpp
# d_s_restart_crsin.cpp
# NSMBW   d_bases.text:  0x80923970 - 0x80923B60
SOURCES += source/wiimj2d/d_bases/d_s_restart_crsin.cpp
# d_s_select.cpp
# NSMBW   d_bases.text:  0x80923B60 - 0x80923C10
SOURCES += source/wiimj2d/d_bases/d_s_select.cpp
# d_s_stage.cpp
# NSMBW   d_bases.text:  0x80923C10 - 0x80926740
SOURCES += source/wiimj2d/d_bases/d_s_stage.cpp
# d_s_stage_static.cpp
# NSMBW          .text:  0x80101A50 - 0x80102770
SOURCES += source/wiimj2d/d_bases/d_s_stage_static.cpp
# d_s_world_map.cpp
# NSMBW   d_bases.text:  0x80926740 - 0x80928810
SOURCES += source/wiimj2d/d_bases/d_s_world_map.cpp
# d_s_world_map_static.cpp
# NSMBW          .text:  0x80102770 - 0x80102DB0
SOURCES += source/wiimj2d/d_bases/d_s_world_map_static.cpp
# d_wm_WorldSelect.cpp
# NSMBW   d_bases.text:  0x80928810 - 0x8092B3E0
SOURCES += source/wiimj2d/d_bases/d_wm_WorldSelect.cpp
# d_wm_WorldSelectGuide.cpp
# NSMBW   d_bases.text:  0x8092B3E0 - 0x8092B8B0
SOURCES += source/wiimj2d/d_bases/d_wm_WorldSelectGuide.cpp
# d_wm_effectManager.cpp
# NSMBW          .text:  0x80103020 - 0x801038D0
SOURCES += source/wiimj2d/d_bases/d_wm_effectManager.cpp
# d_wm_seManager.cpp
# NSMBW          .text:  0x80103F50 - 0x801060E0
SOURCES += source/wiimj2d/d_bases/d_wm_seManager.cpp
# d_world_camera.cpp
# NSMBW   d_bases.text:  0x8092B8B0 - 0x8092F020
SOURCES += source/wiimj2d/d_bases/d_world_camera.cpp
# d_world_camera_static.cpp
# NSMBW          .text:  0x80106E70 - 0x80106F00
# NSMBW          .sbss:  0x8042A560 - 0x8042A568
SOURCES += source/wiimj2d/d_bases/d_world_camera_static.cpp

#
# wiimj2d/d_player
#

# d_SelectCursor.cpp
# NSMBW          .text:  0x8010C130 - 0x8010CAE0
SOURCES += source/wiimj2d/d_player/d_SelectCursor.cpp
# d_SmallScoreManager.cpp
# NSMBW          .text:  0x8010CAE0 - 0x8010D270
SOURCES += source/wiimj2d/d_player/d_SmallScoreManager.cpp
# d_WarningManager.cpp
# NSMBW          .text:  0x8010D270 - 0x8010F080
SOURCES += source/wiimj2d/d_player/d_WarningManager.cpp
# d_WiiStrap.cpp
# NSMBW          .text:  0x8010F080 - 0x8010F530
SOURCES += source/wiimj2d/d_player/d_WiiStrap.cpp
# d_a_cursor.cpp
# NSMBW          .text:  0x8010F530 - 0x8010F9A0
SOURCES += source/wiimj2d/d_player/d_a_cursor.cpp
# d_a_en_eat_coin.cpp
# NSMBW          .text:  0x8010F9A0 - 0x801102B0
SOURCES += source/wiimj2d/d_player/d_a_en_eat_coin.cpp
# d_a_en_hatena_balloon.cpp
# NSMBW          .text:  0x801102B0 - 0x80114C00
SOURCES += source/wiimj2d/d_player/d_a_en_hatena_balloon.cpp
# d_a_enemy_ice.cpp
# NSMBW          .text:  0x80114C00 - 0x80115BD0
SOURCES += source/wiimj2d/d_player/d_a_enemy_ice.cpp
# d_a_farBG.cpp
# NSMBW          .text:  0x80115BD0 - 0x8011A5B0
SOURCES += source/wiimj2d/d_player/d_a_farBG.cpp
# d_a_fireball_player.cpp
# NSMBW          .text:  0x8011A5B0 - 0x8011B640
SOURCES += source/wiimj2d/d_player/d_a_fireball_player.cpp
# d_a_ice.cpp
# NSMBW          .text:  0x8011B640 - 0x801233F0
SOURCES += source/wiimj2d/d_player/d_a_ice.cpp
# d_a_iceball.cpp
# NSMBW          .text:  0x801233F0 - 0x80124D40
SOURCES += source/wiimj2d/d_player/d_a_iceball.cpp
# d_a_last_actor.cpp
# NSMBW          .text:  0x80124D40 - 0x80124EB0
SOURCES += source/wiimj2d/d_player/d_a_last_actor.cpp
# d_a_mask.cpp
# NSMBW          .text:  0x80124EB0 - 0x80126650
SOURCES += source/wiimj2d/d_player/d_a_mask.cpp
# d_a_player.cpp
# NSMBW          .text:  0x80126650 - 0x8014A830
SOURCES += source/wiimj2d/d_player/d_a_player.cpp
# d_a_player_ice.cpp
# NSMBW          .text:  0x8014A830 - 0x8014B400
SOURCES += source/wiimj2d/d_player/d_a_player_ice.cpp
# d_a_yoshi.cpp
# NSMBW          .text:  0x8014B400 - 0x80154800
SOURCES += source/wiimj2d/d_player/d_a_yoshi.cpp
# d_bg_gm.cpp
# NSMBW          .text:  0x80154800 - 0x80156FE0
SOURCES += source/wiimj2d/d_player/d_bg_gm.cpp
# d_death_message_mgr.cpp
# NSMBW          .text:  ---
SOURCES += source/wiimj2d/d_player/d_death_message_mgr.cpp
# d_fukidashiManager.cpp
# NSMBW          .text:  0x80156FE0 - 0x80157820
SOURCES += source/wiimj2d/d_player/d_fukidashiManager.cpp
# d_gamedisplay.cpp
# NSMBW          .text:  0x80157820 - 0x8015A480
SOURCES += source/wiimj2d/d_player/d_gamedisplay.cpp
# d_pausewindow.cpp
# NSMBW          .text:  0x8015A480 - 0x8015BA70
SOURCES += source/wiimj2d/d_player/d_pausewindow.cpp
# d_s_boot.cpp
# NSMBW          .text:  0x8015BA70 - 0x8015F270
SOURCES += source/wiimj2d/d_player/d_s_boot.cpp

#
# wiimj2d/d_enemies
#

# d_a_en_big_block.cpp
# NSMBW d_enemies.text:  0x809B88C0 - 0x809B9DF0
SOURCES += source/wiimj2d/d_enemies/d_a_en_big_block.cpp

# d_a_en_big_hanachan.cpp
# NSMBW d_enemies.text:  0x809B1EC0 - 0x809B4200
SOURCES += source/wiimj2d/d_enemies/d_a_en_big_hanachan.cpp

# d_a_en_block.cpp
# NSMBW d_enemies.text:  0x809BED80 - 0x809C0770
SOURCES += source/wiimj2d/d_enemies/d_a_en_block.cpp

# d_a_en_bomhei.cpp
# NSMBW d_enemies.text:  0x809C8D30 - 0x809CDE70
SOURCES += source/wiimj2d/d_enemies/d_a_en_bomhei.cpp

# d_a_en_brick_block.cpp
# NSMBW d_enemies.text:  0x809D0090 - 0x809D0450
SOURCES += source/wiimj2d/d_enemies/d_a_en_brick_block.cpp

# d_a_en_goalpole.cpp
# NSMBW d_enemies.text:  0x80A096E0 - 0x80A0BE30
SOURCES += source/wiimj2d/d_enemies/d_a_en_goalpole.cpp

# d_a_en_item.cpp
# NSMBW d_enemies.text:  0x80A26A80 - 0x80A2D610
SOURCES += source/wiimj2d/d_enemies/d_a_en_item.cpp

# d_a_en_jumpdai.cpp
# NSMBW d_enemies.text:  0x80A38A00 - 0x80A3AEF0
SOURCES += source/wiimj2d/d_enemies/d_a_en_jumpdai.cpp

# d_a_en_mecha_koopa.cpp
# NSMBW d_enemies.text:  0x80A64110 - 0x80A67470
SOURCES += source/wiimj2d/d_enemies/d_a_en_mecha_koopa.cpp

# d_a_en_red_ring.cpp
# NSMBW d_enemies.text:  0x80A926A0 - 0x80A93990
SOURCES += source/wiimj2d/d_enemies/d_a_en_red_ring.cpp
# d_a_en_redcoin.cpp
# NSMBW d_enemies.text:  0x80A93990 - 0x80A94D90
SOURCES += source/wiimj2d/d_enemies/d_a_en_redcoin.cpp

# d_a_en_water_stream.cpp
# NSMBW d_enemies.text:  0x80AC7800 - 0x80AC8270
SOURCES += source/wiimj2d/d_enemies/d_a_en_water_stream.cpp

#
# wiimj2d/state
# NSMBW          .text:  0x8015F270 - 0x8015FF80
#

# s_Crc.cpp
# NSMBW          .text:  0x8015F270 - 0x8015F280
SOURCES += source/wiimj2d/state/s_Crc.cpp
# s_Lib.cpp
# NSMBW          .text:  0x8015F280 - 0x8015F740
SOURCES += source/wiimj2d/state/s_Lib.cpp
# s_Phase.cpp
# NSMBW          .text:  0x8015F740 - 0x8015F810
SOURCES += source/wiimj2d/state/s_Phase.cpp
# s_Print.cpp
# NSMBW          .text:  0x8015F810 - 0x8015F900
SOURCES += source/wiimj2d/state/s_Print.cpp
# s_StateID.cpp
# NSMBW          .text:  0x8015F900 - 0x8015FAE0
SOURCES += source/wiimj2d/state/s_StateID.cpp
# s_StateMethod.cpp
# NSMBW          .text:  0x8015FAE0 - 0x8015FDD0
SOURCES += source/wiimj2d/state/s_StateMethod.cpp
# s_StateMethodUsr_FI.cpp
# NSMBW          .text:  0x8015FDD0 - 0x8015FF80
SOURCES += source/wiimj2d/state/s_StateMethodUsr_FI.cpp

#
# wiimj2d
# NSMBW          .text:  0x8015FF80 - 0x80160C10
#

# Counter.cpp
# NSMBW          .text:  0x8015FF80 - 0x8015FF90
SOURCES += source/wiimj2d/Counter.cpp
# DynamicLink.cpp
# NSMBW          .text:  0x8015FF90 - 0x80160C10
SOURCES += source/wiimj2d/DynamicLink.cpp

#
# wiimj2d/component
# NSMBW          .text:  0x80160C10 - 0x80161A60
#

# c_lib.cpp
# NSMBW          .text:  0x80160C10 - 0x80161050
SOURCES += source/wiimj2d/component/c_lib.cpp
# c_list.cpp
# NSMBW          .text:  0x80161050 - 0x801611A0
SOURCES += source/wiimj2d/component/c_list.cpp
# c_math.cpp
# NSMBW          .text:  0x801611A0 - 0x801615A0
SOURCES += source/wiimj2d/component/c_math.cpp
# c_random.cpp
# NSMBW          .text:  0x801615A0 - 0x80161670
SOURCES += source/wiimj2d/component/c_random.cpp
# c_tree.cpp
# NSMBW          .text:  0x80161670 - 0x80161880
SOURCES += source/wiimj2d/component/c_tree.cpp

#
# wiimj2d/framework
# NSMBW          .text:  0x80161880 - 0x801632B0
#

# f_ba_helper.cpp
# NSMBW          .text:  0x80161880 - 0x80161A60
SOURCES += source/wiimj2d/framework/f_ba_helper.cpp
# f_base.cpp
# NSMBW          .text:  0x80161A60 - 0x80162C80
SOURCES += source/wiimj2d/framework/f_base.cpp
# f_feature.cpp
# NSMBW: ----
SOURCES += source/wiimj2d/framework/f_feature.cpp
# f_list.cpp
# NSMBW          .text:  0x80162C80 - 0x80162E30
SOURCES += source/wiimj2d/framework/f_list.cpp
# f_manager.cpp
# NSMBW          .text:  0x80162E30 - 0x80163140
SOURCES += source/wiimj2d/framework/f_manager.cpp
# f_tree.cpp
# NSMBW          .text:  0x80163140 - 0x801632B0
SOURCES += source/wiimj2d/framework/f_tree.cpp

#
# wiimj2d/machine
# NSMBW          .text:  0x801632B0 - 0x80171500
#

# m_2d.cpp
# NSMBW          .text:  0x801632B0 - 0x80164630
SOURCES += source/wiimj2d/machine/m_2d.cpp
# m_3d.cpp
# NSMBW          .text:  0x80164630 - 0x80165210
SOURCES += source/wiimj2d/machine/m_3d.cpp
# m_3d_anmchr.cpp
# NSMBW          .text:  0x80165210 - 0x80165660
SOURCES += source/wiimj2d/machine/m_3d_anmchr.cpp
# m_3d_anmchrblend.cpp
# NSMBW          .text:  0x80165660 - 0x80165960
SOURCES += source/wiimj2d/machine/m_3d_anmchrblend.cpp
# m_3d_anmmatclr.cpp
# NSMBW          .text:  0x80165960 - 0x80166560
SOURCES += source/wiimj2d/machine/m_3d_anmmatclr.cpp
# m_3d_anmtexpat.cpp
# NSMBW          .text:  0x80166560 - 0x80167140
SOURCES += source/wiimj2d/machine/m_3d_anmtexpat.cpp
# m_3d_anmtexsrt.cpp
# NSMBW          .text:  0x80167140 - 0x80167D80
SOURCES += source/wiimj2d/machine/m_3d_anmtexsrt.cpp
# m_3d_anmvis.cpp
# NSMBW          .text:  0x80167D80 - 0x80168000
SOURCES += source/wiimj2d/machine/m_3d_anmvis.cpp
# m_3d_banm.cpp
# NSMBW          .text:  0x80168000 - 0x80168240
SOURCES += source/wiimj2d/machine/m_3d_banm.cpp
# m_3d_bmdl.cpp
# NSMBW          .text:  0x80168240 - 0x80168C80
SOURCES += source/wiimj2d/machine/m_3d_bmdl.cpp
# m_3d_calcratio.cpp
# NSMBW          .text:  0x80168C80 - 0x80168E50
SOURCES += source/wiimj2d/machine/m_3d_calcratio.cpp
# m_3d_fanm.cpp
# NSMBW          .text:  0x80168E50 - 0x80169360
SOURCES += source/wiimj2d/machine/m_3d_fanm.cpp
# UNKNOWN
# NSMBW          .text:  0x80169360 - 0x801696A0
# m_3d_mdl.cpp
# NSMBW          .text:  0x801696A0 - 0x8016A150
SOURCES += source/wiimj2d/machine/m_3d_mdl.cpp
# m_3d_scnleaf.cpp
# NSMBW          .text:  0x8016A150 - 0x8016A430
SOURCES += source/wiimj2d/machine/m_3d_scnleaf.cpp
# m_3d_smdl.cpp
# NSMBW          .text:  0x8016A430 - 0x8016A5A0
SOURCES += source/wiimj2d/machine/m_3d_smdl.cpp

# m_dvd.cpp
# NSMBW          .text:  0x8016B090 - 0x8016C540
SOURCES += source/wiimj2d/machine/m_dvd.cpp

# m_fader.cpp
# NSMBW          .text:  0x8016DBE0 - 0x8016DD40
# NSMBW          .sbss:  0x8042A720 - 0x8042A728
SOURCES += source/wiimj2d/machine/m_fader.cpp

# m_heap.cpp
# NSMBW  .bss: 0x80377F48 - 0x80377F58
SOURCES += source/wiimj2d/machine/m_heap.cpp

# m_pad.cpp
# NSMBW          .text:  0x8016F330 - 0x8016F880
SOURCES += source/wiimj2d/machine/m_pad.cpp

# m_vec.cpp
# NSMBW          .text:  0x80170AC0 - 0x80170D90
# NSMBW          .bss:   0x803780C8 - 0x803780F8
SOURCES += source/wiimj2d/machine/m_vec.cpp

#
# wiimj2d/sound
# NSMBW          .text:  0x80194A10 - 0x8019F1F0
#

# SndAudioMgr.cpp
# NSMBW          .text:  0x80194A10 - 0x80197440
SOURCES += source/wiimj2d/sound/SndAudioMgr.cpp
# SndObjectBase.cpp
# NSMBW:         .text:  0x80197440 - 0x80197790
SOURCES += source/wiimj2d/sound/SndObjectBase.cpp
# SndObjectEnemy.cpp
# NSMBW          .text:  0x80197790 - 0x80198CF0
SOURCES += source/wiimj2d/sound/SndObjectEnemy.cpp
# SndObjectMap.cpp
# NSMBW          .text:  0x80198CF0 - 0x80199A20
SOURCES += source/wiimj2d/sound/SndObjectMap.cpp

# SndObjectPlayer.cpp
# NSMBW          .text:  0x8019A0F0 - 0x8019B240
SOURCES += source/wiimj2d/sound/SndObjectPlayer.cpp

# SndSceneMgr.cpp
# NSMBW          .text:  0x8019B500 - 0x8019DE90
SOURCES += source/wiimj2d/sound/SndSceneMgr.cpp

#
# revolution/ai
# NSMBW          .text:  0x8019F1F0 - 0x8019F7A0
#

#
# revolution/arc
# NSMBW          .text:  0x8019F7A0 - 0x801A0190
#

# arc.c
# NSMBW          .text:  0x8019F7A0 - 0x801A0190
SOURCES += source/revolution/arc/arc.c

#
# revolution/ax
# NSMBW          .text:  0x801A0190 - 0x801A9C60
#

#
# revolution/base
# NSMBW          .text:  0x801A9C60 - 0x801A9E80

# PPCArch.c
# NSMBW          .text:  0x801A9C60 - 0x801A9E80
SOURCES += source/revolution/base/PPCArch.c

#
# revolution/os
# NSMBW          .text:  0x801A9E80 - 0x801B8B70
#

# OSCache.c
# NSMBW          .text:  0x801AC560 - 0x801ACC10
SOURCES += source/revolution/os/OSCache.c

# OSError.c
# NSMBW          .text:  0x801AD620 - 0x801ADCE0
SOURCES += source/revolution/os/OSError.c

# OSFatal.c
# NSMBW          .text:  0x801AF2C0 - 0x801AFEF0
SOURCES += source/revolution/os/OSFatal.c

# OSInterrupt.c
# NSMBW          .text:  0x801B1280 - 0x801B1A50
SOURCES += source/revolution/os/OSInterrupt.c
# OSLink.c
# NSMBW          .text:  0x801B1A50 - 0x801B24D0
SOURCES += source/revolution/os/OSLink.c

# OSMutex.c
# NSMBW          .text:  0x801B2F60 - 0x801B3380
SOURCES += source/revolution/os/OSMutex.c

# OSTime.c
# NSMBW          .text:  0x801B60C0 - 0x801B64F0
SOURCES += source/revolution/os/OSTime.c



#
# revolution/si
# NSMBW          .text:  0x801BA940 - 0x801BBA70
#

# SIBios.c
# NSMBW          .text:  0x801BA940 - 0x801BB980
SOURCES += source/revolution/si/SIBios.c
# SISamplingRate.c
# NSMBW          .text:  0x801BB980 - 0x801BBA70
SOURCES += source/revolution/si/SISamplingRate.c

#
# revolution/vi
#

# vi.c
# NSMBW          .text:  0x801BBB70 - 0x801BE5C0
SOURCES += source/revolution/vi/vi.c
# i2c.c
# NSMBW          .text:  0x801BE5C0 - 0x801BEEE0
SOURCES += source/revolution/vi/i2c.c
# vi3in1.c
# NSMBW          .text:  0x801BEEE0 - 0x801C0610
SOURCES += source/revolution/vi/vi3in1.c

#
# revolution/dvd
#

# dvdfs.c
# NSMBW          .text:  0x801CA790 - 0x801CADA0
SOURCES += source/revolution/dvd/dvdfs.c

#
# revolution/nand
# NSMBW          .text:  0x801D8620 - 0x801DB980
#

# nand.c
# NSMBW           .text: 0x801D8620 - 0x801D95E0
SOURCES += source/revolution/nand/nand.c
# NANDOpenClose.c
# NSMBW           .text: 0x801D95E0 - 0x801DA250
SOURCES += source/revolution/nand/NANDOpenClose.c
# NANDCore.c
# NSMBW           .text: 0x801DA250 - 0x801DB280
SOURCES += source/revolution/nand/NANDCore.c
# NANDCheck.c
# NSMBW           .text: 0x801DB1C0 - 0x801DB3F0
SOURCES += source/revolution/nand/NANDCheck.c
# NANDLogging.c
# NSMBW           .text: 0x801DB3F0 - 0x801DB980
SOURCES += source/revolution/nand/NANDLogging.c
# NANDErrorMessage.c
# NSMBW           .text: 0x801DB980 - 0x801DB980
SOURCES += source/revolution/nand/NANDErrorMessage.c

#
# revolution/pad
#

# Pad.c
# NSMBW          .text:  0x801DDB10 - 0x801DDB70
SOURCES += source/revolution/pad/Pad.c

#
# revolution/wpad
#

# WPAD.c
# NSMBW          .text:  0x801DDC90 - 0x801E55A0
SOURCES += source/revolution/wpad/WPAD.c

#
# revolution/kpad
#

# KPAD.c
# NSMBW          .text:  0x801EAA80 - 0x801EEAE0
SOURCES += source/revolution/kpad/KPAD.c

#
# revolution/fs
# NSMBW          .text:  0x802265D0 - 0x80227CB0

# fs.c
# NSMBW          .text:  0x802265D0 = 0x80227CB0
SOURCES += source/revolution/fs/fs.c

#
# nw4r/g3d
#

# g3d_resfile.cpp
# NSMBW          .text:  0x80239F70 - 0x8023B2F0
SOURCES += source/nw4r/g3d/ResFile.cpp

#
# nw4r/snd
#

# snd_DvdSoundArchive.cpp
# NSMBW          .text:  0x80269130 - 0x802697A0
SOURCES += source/nw4r/snd/DvdSoundArchive.cpp

# snd_SoundActor.cpp
# NSMBW: 0x80275530 - 0x80275780
SOURCES += source/nw4r/snd/SoundActor.cpp
# snd_SoundArchive.cpp
# NSMBW          .text:  0x80275780 - 0x80275E80
SOURCES += source/nw4r/snd/SoundArchive.cpp
# snd_SoundArchiveFile.cpp
# NSMBW          .text:  0x80275E80 - 0x80277190
SOURCES += source/nw4r/snd/SoundArchiveFile.cpp
# snd_SoundArchiveLoader.cpp
# NSMBW          .text:  0x80277190 - 0x802777F0
SOURCES += source/nw4r/snd/SoundArchiveLoader.cpp

# snd_Util.cpp
# NSMBW          .text:  0x802836F0 - 0x80283BD0
SOURCES += source/nw4r/snd/Util.cpp

#
# egg/core
#

# eggDvdFile.cpp
# NSMBW          .text:  0x802B7C00 - 0x802B8010
SOURCES += source/egg/core/eggDvdFile.cpp
# eggDvdRipper.cpp
# NSMBW          .text:  0x802B8010 - 0x802B8560
SOURCES += source/egg/core/eggDvdRipper.cpp
# eggStreamDecomp.cpp
# NSMBW          .text:  0x802B8560 - 0x802B8BB0
SOURCES += source/egg/core/eggStreamDecomp.cpp

# eggHeap.cpp
# NSMBW          .text:  0x802B8C80 - 0x802B93E0
SOURCES += source/egg/core/eggHeap.cpp
# eggExpHeap.cpp
# NSMBW          .text:  0x802B93E0 - 0x802B98C0
SOURCES += source/egg/core/eggExpHeap.cpp

# eggDisposer.cpp
# NSMBW          .text:  0x802BA410 - 0x802BA4F0
SOURCES += source/egg/core/eggDisposer.cpp

# eggController.cpp
# NSMBW          .text:  0x802BC9D0 - 0x802BE710
SOURCES += source/egg/core/eggController.cpp

#
# egg/gfx
#

# eggScreen.cpp
# NSMBW          .text:  0x802D0D90 - 0x802D2060
SOURCES += source/egg/gfx/eggScreen.cpp

#
# egg/util
#

# eggEffect.cpp
# NSMBW          .text:  0x802D7D90 - 0x802D8BC0
SOURCES += source/egg/util/eggEffect.cpp

#
# runtime
#

# __mem.c
# NSMBW          .init:  0x80004364 - 0x800046E4
# NSMBW          .text:  0x802DC98C - 0x802DC9A8
SOURCES += source/runtime/__mem.c

# runtime.c
# NSMBW          .text:  0x802DCF3C - 0x802DD5D0
SOURCES += source/runtime/runtime.c

#
# msl/msl_c
#

# file_io.c
# NSMBW          .text:  0x802DEC0C - 0x802DEDFC
SOURCES += source/msl/msl_c/file_io.c

# mbstring.c
# NSMBW          .text:  0x802DF06C - 0x802DF264
SOURCES += source/msl/msl_c/mbstring.c
# mem.c
# NSMBW          .text:  0x802DF264 - 0x802DF3D4
SOURCES += source/msl/msl_c/mem.c

# printf.c
# NSMBW          .text:  0x802DF7A8 - 0x802E1BA0
SOURCES += source/msl/msl_c/printf.c
# scanf.c
# NSMBW          .text:  0x802E1BA0 - 0x802E1C28
SOURCES += source/msl/msl_c/scanf.c
# string.c
# NSMBW          .text:  0x802E1C28 - 0x802E4FC8
SOURCES += source/msl/msl_c/string.c
# strtoul.c
# NSMBW          .text:  0x802E1FE4 - 0x802E24BC
SOURCES += source/msl/msl_c/strtoul.c

# wchar_io.c
# NSMBW          .text:  0x802E47E8 - 0x802E4860
SOURCES += source/msl/msl_c/wchar_io.c
