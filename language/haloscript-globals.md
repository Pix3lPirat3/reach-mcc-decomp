# HaloScript external globals

The module registers 1,716 external globals in a table of descriptors (table at 0x9f6000). A descriptor holds the name, the value type (as an hs type id) and a pointer to a storage cell. A script refers to a global by its table index (bit 15 of the 16-bit variable reference marks an external global; script-defined globals use indexes without that bit and live after the first 0x6b4 entries of the runtime globals array).

## How a global is read and written

- Reading an external global copies the value from its storage cell into the runtime globals array slot (function_86cc8, a typed copy: boolean is 1 byte, real is 4 bytes, short is 2 bytes, long is 4 bytes, handle-like types are 2 or 4 bytes) and then returns the slot (function_85ee0).
- A descriptor with no storage cell reads as zero for boolean and number types and as -1 (none) for handle-like types. 1,524 of the 1,716 globals have no storage cell; they exist as names the compiler accepts but hold no engine state.
- Writing (the set form, function_83738) stores into the runtime slot and, for external globals, commits the value to the storage cell through function_86eec (a typed store that does nothing when the descriptor has no storage cell; a few type ids have no store); types are checked at compile time.
- The documentation dump only lists globals that have a storage cell; entries without a cell are skipped there.

## Counts

| Type | Globals | With storage cell |
|---|---|---|
| boolean | 1311 | 56 |
| real | 173 | 43 |
| long | 133 | 12 |
| short | 85 | 78 |
| string_id | 7 | 0 |
| ai | 3 | 2 |
| object | 2 | 1 |
| ai_behavior | 1 | 0 |
| character_physics | 1 | 0 |

## Globals with a storage cell (192)

Initial value is the value stored in the module image; it can change before a script reads it.

| Index | Name | Type | Cell | Section | Initial value |
|---|---|---|---|---|---|
| 0 | enable_melee_action | boolean | data_4e2fcb1 | .data | false |
| 22 | debug_controller_latency | boolean | data_4e2fcb0 | .data | false |
| 26 | camera_fov | real | data_b42c10 | .data | 78.0 |
| 37 | CameraObserverAllowNonrecorderFirstPerson | boolean | data_4e30755 | .data | false |
| 89 | survival_performance_mode | boolean | data_4e30382 | .data | false |
| 102 | chud_debug_highlight_object | object | data_b4c7f0 | .data | -1 |
| 103 | chud_debug_highlight_object_color_red | real | data_b4c7e4 | .data | 40.0 |
| 104 | chud_debug_highlight_object_color_green | real | data_b4c7e8 | .data | 0.0 |
| 105 | chud_debug_highlight_object_color_blue | real | data_b4c7ec | .data | 0.0 |
| 106 | chud_debug_highlight_object_color_alpha | real | data_b4c7e0 | .data | 0.0 |
| 179 | effects_corpse_nonviolent | boolean | data_4e303a4 | .data | false |
| 188 | sound_global_room_gain | real | data_afc088 | .data | 1.0 |
| 191 | sound_reverb_wet_dry_mix | real | data_afc084 | .data | 1.0 |
| 227 | debug_duckers | boolean | data_4e2fb73 | .data | false |
| 228 | debug_sound_listeners | boolean | data_4e2fb72 | .data | false |
| 245 | sound_enable_expensive_obstruction | boolean | data_b01602 | .data | true |
| 246 | sound_enable_new_obstruction_collision | boolean | data_b01601 | .data | true |
| 247 | debug_sound_enable_multithreaded | boolean | data_afc081 | .data | true |
| 280 | disable_expensive_physics_rebuilding | boolean | data_4e30634 | .data | false |
| 281 | minimum_havok_object_acceleration | real | data_b73928 | .data | 0.05 |
| 282 | minimum_havok_biped_object_acceleration | real | data_b73924 | .data | 0.3 |
| 293 | render_lightmap_shadows | boolean | data_b4444d | .data | true |
| 294 | render_rain | boolean | data_b4444c | .data | true |
| 301 | render_tessellated_mesh | boolean | data_b445f0 | .data | true |
| 304 | render_water_tessellated | boolean | data_b43b0d | .data | true |
| 306 | render_water_interaction | boolean | data_b43b04 | .data | true |
| 308 | render_water_refraction | boolean | data_b43b0c | .data | true |
| 358 | render_screen_flashes | boolean | data_b01970 | .data | true |
| 359 | texture_camera_near_plane | real | data_b43b20 | .data | 0.001 |
| 360 | texture_camera_exposure | real | data_b43b18 | .data | 1.0 |
| 361 | texture_camera_illum_scale | real | data_b43b1c | .data | 1.0 |
| 362 | render_near_clip_distance | real | data_b43a88 | .data | 0.007812 |
| 363 | render_far_clip_distance | real | data_b43a8c | .data | 10240.0 |
| 366 | render_HDR_target_stops | real | data_b43b28 | .data | 3.0 |
| 367 | render_surface_LDR_mode | long | data_b44458 | .data | 1 |
| 368 | render_surface_HDR_mode | long | data_b4445c | .data | 1 |
| 369 | render_first_person_fov_scale | real | data_b445f4 | .data | 0.88 |
| 370 | rasterizer_triliner_threshold | long | data_b43a80 | .data | 3 |
| 371 | rasterizer_present_immediate_threshold | long | data_b43a84 | .data | 10 |
| 372 | tiling | long | data_29d7cdc | .data | 0 |
| 373 | render_screen_res | long | data_4e38a00 | .data | 0 |
| 374 | render_tiling_resolve_fragment_index | long | data_4e389f4 | .data | 0 |
| 375 | render_tiling_viewport_offset_x | real | data_4e389f8 | .data | 0.0 |
| 376 | render_tiling_viewport_offset_y | real | data_4e389fc | .data | 0.0 |
| 377 | render_alpha_test_reference | long | data_b44460 | .data | 128 |
| 378 | render_true_gamma | boolean | data_b43b24 | .data | true |
| 400 | render_postprocess_hue | real | data_29dba18 | .data | 0.0 |
| 401 | render_postprocess_saturation | real | data_29dba1c | .data | 0.0 |
| 402 | render_postprocess_red_filter | real | data_29dba20 | .data | 0.0 |
| 403 | render_postprocess_green_filter | real | data_29dba24 | .data | 0.0 |
| 404 | render_postprocess_blue_filter | real | data_29dba28 | .data | 0.0 |
| 406 | render_bounce_light_intensity | real | data_b42da4 | .data | 10.0 |
| 407 | render_bounce_light_only | boolean | data_4e307a0 | .data | false |
| 411 | render_force_single_pass_rendering | boolean | data_4e38a73 | .data | false |
| 436 | render_debug_depth_render | long | data_4e3899c | .data | 0 |
| 437 | render_debug_depth_render_scale_r | real | data_b43e14 | .data | 9.0 |
| 438 | render_debug_depth_render_scale_g | real | data_b43e0c | .data | 10.0 |
| 439 | render_debug_depth_render_scale_b | real | data_b43e10 | .data | 9.0 |
| 568 | water_physics_velocity_minimum | real | data_afc424 | .data | 0.5 |
| 569 | water_physics_velocity_maximum | real | data_afc428 | .data | 3.0 |
| 785 | breakable_surfaces | boolean | data_b01960 | .data | true |
| 941 | ai_max_path_traverse_iterations | short | data_b851d0 | .data | -1 |
| 1018 | ai_current_squad | ai | data_fc9c44 | .data | 0 |
| 1019 | ai_current_actor | ai | data_fc9c40 | .data | 0 |
| 1020 | ai_current_performance | long | data_fc9c48 | .data | 0 |
| 1042 | ai_combat_status_asleep | short | data_b817d0 | .data | 0 |
| 1043 | ai_combat_status_idle | short | data_b817d2 | .data | 1 |
| 1044 | ai_combat_status_alert | short | data_b817d4 | .data | 2 |
| 1045 | ai_combat_status_active | short | data_b817d6 | .data | 3 |
| 1046 | ai_combat_status_uninspected | short | data_b817d8 | .data | 4 |
| 1047 | ai_combat_status_definite | short | data_b817da | .data | 5 |
| 1048 | ai_combat_status_certain | short | data_b817dc | .data | 6 |
| 1049 | ai_combat_status_visible | short | data_b817de | .data | 7 |
| 1050 | ai_combat_status_clear_los | short | data_b817e0 | .data | 8 |
| 1051 | ai_combat_status_dangerous | short | data_b817e2 | .data | 9 |
| 1052 | ai_task_status_never | short | data_b817d0 | .data | 0 |
| 1053 | ai_task_status_occupied | short | data_b817d2 | .data | 1 |
| 1054 | ai_task_status_empty | short | data_b817d4 | .data | 2 |
| 1055 | ai_task_status_inactive | short | data_b817d6 | .data | 3 |
| 1056 | ai_task_status_exhausted | short | data_b817d8 | .data | 4 |
| 1057 | ai_evaluator_preference | short | data_b817d0 | .data | 0 |
| 1058 | ai_evaluator_avoidance | short | data_b817d2 | .data | 1 |
| 1059 | ai_evaluator_sum | short | data_b817d4 | .data | 2 |
| 1060 | ai_action_berserk | short | data_b817d0 | .data | 0 |
| 1061 | ai_action_surprise_front | short | data_b817d2 | .data | 1 |
| 1062 | ai_action_surprise_back | short | data_b817d4 | .data | 2 |
| 1063 | ai_action_evade_left | short | data_b817d6 | .data | 3 |
| 1064 | ai_action_evade_right | short | data_b817d8 | .data | 4 |
| 1065 | ai_action_dive_forward | short | data_b817da | .data | 5 |
| 1066 | ai_action_dive_back | short | data_b817dc | .data | 6 |
| 1067 | ai_action_dive_left | short | data_b817de | .data | 7 |
| 1068 | ai_action_dive_right | short | data_b817e0 | .data | 8 |
| 1069 | ai_action_advance | short | data_b817e2 | .data | 9 |
| 1070 | ai_action_cheer | short | data_b817e4 | .data | 10 |
| 1071 | ai_action_fallback | short | data_b817e6 | .data | 11 |
| 1072 | ai_action_hold | short | data_b817e8 | .data | 12 |
| 1073 | ai_action_point | short | data_b817ea | .data | 13 |
| 1074 | ai_action_posing | short | data_b817ec | .data | 14 |
| 1075 | ai_action_shakefist | short | data_b817ee | .data | 15 |
| 1076 | ai_action_signal_attack | short | data_b817f0 | .data | 16 |
| 1077 | ai_action_signal_move | short | data_b817f2 | .data | 17 |
| 1078 | ai_action_taunt | short | data_b817f4 | .data | 18 |
| 1079 | ai_action_warn | short | data_b817f6 | .data | 19 |
| 1080 | ai_action_wave | short | data_b817f8 | .data | 20 |
| 1081 | ai_activity_none | short | data_b817d0 | .data | 0 |
| 1082 | ai_activity_patrol | short | data_b817d2 | .data | 1 |
| 1083 | ai_activity_stand | short | data_b817d4 | .data | 2 |
| 1084 | ai_activity_crouch | short | data_b817d6 | .data | 3 |
| 1085 | ai_activity_stand_drawn | short | data_b817d8 | .data | 4 |
| 1086 | ai_activity_crouch_drawn | short | data_b817da | .data | 5 |
| 1087 | ai_activity_combat | short | data_b817dc | .data | 6 |
| 1088 | ai_activity_backup | short | data_b817de | .data | 7 |
| 1089 | ai_activity_guard | short | data_b817e0 | .data | 8 |
| 1090 | ai_activity_guard_crouch | short | data_b817e2 | .data | 9 |
| 1091 | ai_activity_guard_wall | short | data_b817e4 | .data | 10 |
| 1092 | ai_activity_typing | short | data_b817e6 | .data | 11 |
| 1093 | ai_activity_kneel | short | data_b817e8 | .data | 12 |
| 1094 | ai_activity_gaze | short | data_b817ea | .data | 13 |
| 1095 | ai_activity_poke | short | data_b817ec | .data | 14 |
| 1096 | ai_activity_sniff | short | data_b817ee | .data | 15 |
| 1097 | ai_activity_track | short | data_b817f0 | .data | 16 |
| 1098 | ai_activity_watch | short | data_b817f2 | .data | 17 |
| 1099 | ai_activity_examine | short | data_b817f4 | .data | 18 |
| 1100 | ai_activity_sleep | short | data_b817f6 | .data | 19 |
| 1101 | ai_activity_at_ease | short | data_b817f8 | .data | 20 |
| 1102 | ai_activity_cower | short | data_b817fa | .data | 21 |
| 1103 | ai_activity_tai_chi | short | data_b817fc | .data | 22 |
| 1104 | ai_activity_pee | short | data_b817fe | .data | 23 |
| 1105 | ai_activity_doze | short | data_b81800 | .data | 24 |
| 1106 | ai_activity_eat | short | data_b81802 | .data | 25 |
| 1107 | ai_activity_medic | short | data_b81804 | .data | 26 |
| 1108 | ai_activity_work | short | data_b81806 | .data | 27 |
| 1109 | ai_activity_cheering | short | data_b81808 | .data | 28 |
| 1110 | ai_activity_injured | short | data_b8180a | .data | 29 |
| 1111 | ai_activity_captured | short | data_b8180c | .data | 30 |
| 1112 | ai_movement_patrol | short | data_b817b8 | .data | 0 |
| 1113 | ai_movement_asleep | short | data_b817ba | .data | 1 |
| 1114 | ai_movement_combat | short | data_b817bc | .data | 2 |
| 1115 | ai_movement_flee | short | data_b817be | .data | 3 |
| 1116 | ai_movement_flaming | short | data_b817c0 | .data | 4 |
| 1117 | ai_movement_stunned | short | data_b817c2 | .data | 5 |
| 1118 | ai_movement_berserk | short | data_b817c4 | .data | 6 |
| 1301 | e3 | boolean | data_4e30693 | .data | false |
| 1321 | lruv_lirp_enabled | boolean | data_b42bf8 | .data | true |
| 1372 | use_temp_directory_for_files | boolean | data_4e2fb96 | .data | false |
| 1402 | enable_amortized_prediction | boolean | data_b0160e | .data | true |
| 1403 | amortized_prediction_object_batch_size | long | data_b01608 | .data | 64 |
| 1404 | enable_tag_resource_prediction | boolean | data_b01610 | .data | true |
| 1405 | enable_entire_pvs_prediction | boolean | data_b0160d | .data | true |
| 1406 | enable_cluster_objects_prediction | boolean | data_b0160c | .data | true |
| 1456 | ignore_predefined_performance_throttles | boolean | data_4e389b0 | .data | false |
| 1457 | enable_first_person_prediction | boolean | data_b01612 | .data | true |
| 1458 | enable_structure_prediction | boolean | data_b01611 | .data | true |
| 1460 | minidump_force_regular_minidump_with_ui | boolean | data_b43a3c | .data | true |
| 1465 | render_alpha_to_coverage | boolean | data_4e389f0 | .data | false |
| 1466 | enable_sound_transmission | boolean | data_afc080 | .data | true |
| 1468 | motion_blur_expected_dt | real | data_b4460c | .data | 0.033333 |
| 1469 | motion_blur_max | real | data_b44600 | .data | 0.08 |
| 1470 | motion_blur_scale | real | data_b44604 | .data | 0.35 |
| 1471 | motion_blur_center_falloff_x | real | data_b44608 | .data | 7.0 |
| 1472 | motion_blur_center_falloff_y | real | data_b445fc | .data | 7.0 |
| 1481 | g_fireteam_target_selection_preference_bonus | real | data_b851d4 | .data | 8.0 |
| 1482 | ai_fireteam_hold_distance | real | data_b817ac | .data | 3.0 |
| 1483 | ai_fireteam_protect_leader | boolean | data_b817b0 | .data | true |
| 1490 | force_buffer_2_frames | boolean | data_c51964 | .data | false |
| 1491 | disable_render_state_cache_optimization | boolean | data_4e38a72 | .data | false |
| 1493 | enable_better_cpu_gpu_sync | boolean | data_b43fb8 | .data | true |
| 1499 | motion_blur_max_viewport_count | long | data_b445f8 | .data | 1 |
| 1500 | cinematic_prediction_enable | boolean | data_b0160f | .data | true |
| 1501 | skies_delete_on_zone_set_switch_enable | boolean | data_4e38f52 | .data | false |
| 1502 | reduce_widescreen_fov_during_cinematics | boolean | data_4e38a98 | .data | false |
| 1573 | respawn_players_into_friendly_vehicle | boolean | data_4e2fb9c | .data | false |
| 1601 | display_client_synchronous_input_lag | boolean | data_4e38ce3 | .data | false |
| 1610 | clients_always_respect_action_priority_for_weapon_switch | boolean | data_b7110b | .data | true |
| 1642 | render_pre_placed_lights | boolean | data_b445c0 | .data | true |
| 1652 | mirror_context_tracking_enabled | boolean | data_b7110a | .data | true |
| 1656 | guardian_kills_awarded_to_most_damage | boolean | data_4e30381 | .data | false |
| 1662 | shadow_apply_depth_bias | real | data_b43ad4 | .data | -1e-06 |
| 1663 | shadow_apply_slope_depth_bias | real | data_b43ad8 | .data | -0.01 |
| 1667 | player_respawn_check_airborne | boolean | data_afc0e4 | .data | true |
| 1670 | shadow_generate_dynamic_lights_depth_bias | real | data_b43ad0 | .data | 0.0008 |
| 1671 | shadow_generate_dynamic_lights_slope_depth_bias | real | data_b43ac4 | .data | 1.414 |
| 1672 | shadow_generate_depth_bias | real | data_b43ac8 | .data | 0.003 |
| 1673 | shadow_generate_slope_depth_bias | real | data_b43acc | .data | 1.414 |
| 1674 | imposter_cache_build | boolean | data_4e38a71 | .data | false |
| 1677 | imposter_capturing | boolean | data_4e38a70 | .data | false |
| 1695 | render_low_res_transparency_debug | boolean | data_4e389d8 | .data | false |
| 1698 | use_fmod | boolean | data_b01600 | .data | true |
| 1702 | rain_drop_alpha_scale | real | data_b44630 | .data | 0.5 |
| 1712 | saved_film_maximum_size_ignored | boolean | data_4e2fced | .data | false |
| 1713 | NetBandwidthReportFromFilm | boolean | data_2a57f08 | .data | false |
| 1714 | NetSavedFilmBypassSimulation | boolean | data_2a57f09 | .data | false |

## Globals without a storage cell (1,524)

These names resolve at compile time and read as zero, false or none.

| Index | Name | Type |
|---|---|---|
| 1 | debug_no_drawing | boolean |
| 2 | debug_force_all_player_views_to_default_player | boolean |
| 3 | debug_force_player_view_count | long |
| 4 | debug_render_freeze | boolean |
| 5 | debug_render_player_freeze | boolean |
| 6 | debug_render_horizontal_splitscreen | boolean |
| 7 | debug_load_panic_to_main_menu | boolean |
| 8 | display_framerate | boolean |
| 9 | display_pulse_rates | boolean |
| 10 | display_throttle_rates | boolean |
| 11 | display_lag_times | boolean |
| 12 | display_frame_deltas | boolean |
| 13 | console_status_string_render | boolean |
| 14 | console_pauses_game | boolean |
| 15 | framerate_infinite | boolean |
| 16 | framerate_debug | boolean |
| 17 | framerate_use_system_time | boolean |
| 18 | framerate_stabilization | boolean |
| 19 | g_animation_debug_rendering_on | boolean |
| 20 | g_animation_debug_view_type_selected | long |
| 21 | g_animation_debug_current_target | long |
| 23 | terminal_render | boolean |
| 24 | events_debug_spam_render | boolean |
| 25 | console_dump_to_debug_display | boolean |
| 27 | camera_yaw_scale | real |
| 28 | camera_pitch_scale | real |
| 29 | camera_forward_scale | real |
| 30 | camera_side_scale | real |
| 31 | camera_up_scale | real |
| 32 | flying_camera_maximum_boost_speed | real |
| 33 | flying_camera_movement_delay | real |
| 34 | flying_camera_has_collision | boolean |
| 35 | flying_camera_use_old_controls | boolean |
| 36 | editor_director_mouse_wheel_speed_enabled | boolean |
| 38 | async_display_statistics | boolean |
| 39 | suppress_upload_debug | boolean |
| 40 | lightmap_pointsample | boolean |
| 41 | debug_no_frustum_clip | boolean |
| 42 | debug_camera_projection | boolean |
| 43 | debug_bink | boolean |
| 44 | game_paused | boolean |
| 45 | game_speed | real |
| 46 | game_time_lock | boolean |
| 47 | game_time_statistics | boolean |
| 48 | map_info_debug | boolean |
| 49 | debug_game_save | boolean |
| 50 | recover_saved_games_hack | boolean |
| 51 | game_state_verify_on_write | boolean |
| 52 | game_state_verify_on_read | boolean |
| 53 | debug_verify_game_variant_settings | boolean |
| 54 | debug_globals_empty | boolean |
| 55 | dont_load_material_effects | boolean |
| 56 | editor_strip_dialogue_sounds | boolean |
| 57 | scenario_load_fast | boolean |
| 58 | scenario_load_fast_and_playable | boolean |
| 59 | prune_global_use_empty | boolean |
| 60 | prune_global_material_effects | boolean |
| 61 | prune_scenario_lightmaps | boolean |
| 62 | prune_scenario_add_single_bsp_zones | boolean |
| 63 | prune_scenario_force_single_bsp_zone_set | boolean |
| 64 | prune_scenario_for_environment_editing | boolean |
| 65 | prune_scenario_for_environment_finishing | boolean |
| 66 | prune_scenario_for_environment_pathfinding | boolean |
| 67 | prune_scenario_for_environment_editing_keep_cinematics | boolean |
| 68 | prune_scenario_for_environment_editing_keep_scenery | boolean |
| 69 | prune_scenario_use_gray_shader | boolean |
| 70 | prune_global_dialog_sounds | boolean |
| 71 | prune_facial_animation_data | boolean |
| 72 | prune_error_geometry | boolean |
| 73 | pruning_keep_scripts | boolean |
| 74 | prune_global | boolean |
| 75 | prune_global_keep_playable | boolean |
| 76 | variant_culling_enabled | boolean |
| 77 | material_culling_enabled | boolean |
| 78 | display_precache_progress | boolean |
| 79 | log_precache_progress | boolean |
| 80 | fake_precache_percentage | long |
| 81 | force_aligned_utility_drive | boolean |
| 82 | debug_object_garbage_collection | boolean |
| 83 | debug_object_dump_log | boolean |
| 84 | allow_all_sounds_on_player | boolean |
| 85 | disable_player_rotation | boolean |
| 86 | player_rotation_scale | real |
| 87 | debug_player_respawn | boolean |
| 88 | debug_survival_mode | boolean |
| 90 | debug_survival_mode_infinite_lives | boolean |
| 91 | debug_survival_mode_respawn_if_iron | boolean |
| 92 | g_synchronous_client_maximum_catchup_chunk_size | long |
| 93 | g_editor_maximum_edited_object_speed | real |
| 94 | g_editor_edited_object_spring_constant | real |
| 95 | g_editor_maximum_rotation_speed | real |
| 96 | chud_enabled | boolean |
| 97 | chud_debug_grid | boolean |
| 98 | chud_debug_messages | boolean |
| 99 | chud_debug_crosshair | boolean |
| 100 | chud_debug_metagame | boolean |
| 101 | chud_debug_reticle_radius | real |
| 107 | chud_debug_animation_speed | real |
| 108 | debug_animation_override_blend_channel_input | string_id |
| 109 | debug_animation_blend_test_parent_relative | boolean |
| 110 | debug_animation_blend_test_horizontal | real |
| 111 | debug_animation_blend_test_vertical | real |
| 112 | debug_animation_snap_nearest_pose_blend | boolean |
| 113 | debug_animation_object_space_offset_disable | boolean |
| 114 | debug_animation_fik_correction_enable | boolean |
| 115 | debug_animation_fik_subframe_precision_enable | boolean |
| 116 | debug_animation_object_space_offset_draw | boolean |
| 117 | debug_animation_ik_chains_disable | boolean |
| 118 | debug_animation_footlock_disable | boolean |
| 119 | debug_animation_footlock_locking_disable | boolean |
| 120 | debug_animation_precomputed_velocity_boundaries_disable | boolean |
| 121 | debug_animation_ik_sets_disable | boolean |
| 122 | debug_animation_gait_preserve_frame_ratio | boolean |
| 123 | debug_animation_move_preserve_frame_ratio | boolean |
| 124 | debug_animation_root_offset_disable | boolean |
| 125 | debug_animation_camera_offset_disable | boolean |
| 126 | debug_animation_unsafe_debug_enable | boolean |
| 127 | debug_animation_maximum_channels_displayed | long |
| 128 | debug_animation_footlock_draw | boolean |
| 129 | debug_animation_footlock_draw_raw | boolean |
| 130 | debug_animation_footlock_draw_turned | boolean |
| 131 | debug_animation_footlock_draw_fitted | boolean |
| 132 | debug_animation_footlock_draw_turn_sampling | boolean |
| 133 | debug_animation_footlock_draw_grid_sampling | boolean |
| 134 | debug_animation_footlock_draw_raycast | boolean |
| 135 | debug_animation_footlock_draw_contact | boolean |
| 136 | debug_animation_footlock_draw_displacement | boolean |
| 137 | debug_animation_turn_radius_draw | boolean |
| 138 | debug_animation_assassination_selection | boolean |
| 139 | debug_animation_phonebooth_test_draw | boolean |
| 140 | debug_animation_phonebooth_draw_time | real |
| 141 | debug_pose_overlay_force_interpolation_across_sphere | boolean |
| 142 | debug_enable_press_to_assassinate | boolean |
| 143 | debug_enable_same_team_assassinate | boolean |
| 144 | debug_enable_force_phonebooth_assassinate | boolean |
| 145 | debug_unit_all_animations | boolean |
| 146 | debug_unit_animations | boolean |
| 147 | debug_unit_illumination | boolean |
| 148 | debug_unit_active_camo_frequency_modulator | real |
| 149 | debug_unit_active_camo_frequency_modulator_bias | real |
| 150 | debug_player_melee_attack | boolean |
| 151 | debug_boarding_force_enemy | boolean |
| 152 | enable_animation_decompression_cache | boolean |
| 153 | enable_animation_influenced_flight | boolean |
| 154 | enable_flight_noise | boolean |
| 155 | enable_player_transitions | boolean |
| 156 | enable_pain_screen_aim_fixup | boolean |
| 157 | disable_node_interpolation | boolean |
| 158 | disable_analog_movement | boolean |
| 159 | disable_transition_animations | boolean |
| 160 | disable_animated_source_interpolation | boolean |
| 161 | debug_enable_easy_weapon_down_claw | boolean |
| 162 | debug_vehicle_animated_trick_animation_name | string_id |
| 163 | debug_vehicle_animated_trick_camera_name | string_id |
| 164 | debug_orbiting_camera_maximum_distance_override | real |
| 165 | cheat_deathless_player | boolean |
| 166 | cheat_valhalla | boolean |
| 167 | cheat_jetpack | boolean |
| 168 | cheat_infinite_ammo | boolean |
| 169 | cheat_bottomless_clip | boolean |
| 170 | cheat_bump_possession | boolean |
| 171 | cheat_super_jump | boolean |
| 172 | cheat_reflexive_damage_effects | boolean |
| 173 | cheat_medusa | boolean |
| 174 | cheat_omnipotent | boolean |
| 175 | cheat_controller | boolean |
| 176 | cheat_chevy | boolean |
| 177 | cheat_porcupine | boolean |
| 178 | cheat_infinite_equipment_energy | boolean |
| 180 | debug_effects_nonviolent | boolean |
| 181 | debug_effects_locations | boolean |
| 182 | effects_enable | boolean |
| 183 | debug_effects_allocation | boolean |
| 184 | debug_effects_play_distances | boolean |
| 185 | debug_effects_lightprobe_sampling | boolean |
| 186 | player_effects_enabled | boolean |
| 187 | g_animation_statistic_accumulator_enabled | boolean |
| 189 | sound_direct_path_gain | real |
| 190 | sound_reverb_path_gain | real |
| 192 | enable_pc_sound | boolean |
| 193 | debug_sound | boolean |
| 194 | debug_looping_sound | boolean |
| 195 | debug_sound_channels | boolean |
| 196 | debug_sound_channels_fadeout | boolean |
| 197 | debug_sound_spatialized | boolean |
| 198 | debug_sound_spatialized_fadeout | boolean |
| 199 | debug_platform_sound_channels | boolean |
| 200 | debug_sound_reverb | boolean |
| 201 | sound_cache_list | boolean |
| 202 | debug_speaker_output_peak | boolean |
| 203 | debug_speaker_output_rms | boolean |
| 204 | debug_display_levels_data | boolean |
| 205 | debug_display_preformance_data | boolean |
| 206 | debug_display_sources_data_state | boolean |
| 207 | debug_display_sources_data | boolean |
| 208 | debug_display_mix_data | boolean |
| 209 | debug_display_reverb_data | boolean |
| 210 | debug_sound_mute_effect_final_mix | boolean |
| 211 | debug_sound_mute_effect_sub_mix | boolean |
| 212 | debug_sound_mute_effect_occlusion | boolean |
| 213 | debug_sound_mute_effect_obstruction | boolean |
| 214 | debug_sound_mute_effect_radio | boolean |
| 215 | debug_sound_mute_effect_reverb_first | boolean |
| 216 | debug_sound_mute_effect_reverb_second | boolean |
| 217 | debug_sound_mute_music | boolean |
| 218 | debug_sound_mute_dialog | boolean |
| 219 | debug_sound_mute_ambient | boolean |
| 220 | debug_sound_mute_vehicles | boolean |
| 221 | debug_sound_mute_weapons | boolean |
| 222 | debug_sound_mute_mix_dry | boolean |
| 223 | debug_sound_mute_mix_dry_obstruction | boolean |
| 224 | debug_sound_mute_mix_wet | boolean |
| 225 | debug_sound_mute_mix_wet_occlusion | boolean |
| 226 | debug_sound_mute_mix_radio | boolean |
| 229 | debug_disable_music_channel | boolean |
| 230 | debug_disable_dialog_channel | boolean |
| 231 | debug_disable_cinematic_channel | boolean |
| 232 | debug_disable_ambiant_channel | boolean |
| 233 | debug_disable_vehicle_channel | boolean |
| 234 | debug_disable_weapon_channel | boolean |
| 235 | debug_disable_other_channel | boolean |
| 236 | debug_disable_looping_channels | boolean |
| 237 | debug_disable_nonlooping_channels | boolean |
| 238 | debug_sound_force_first_person_listener | boolean |
| 239 | debug_sound_reference_counts | boolean |
| 240 | debug_sound_environment_parameters | boolean |
| 241 | debug_sound_channel_overflow | boolean |
| 242 | debug_sound_impulse_time | boolean |
| 243 | debug_sound_impulse_spam | boolean |
| 244 | debug_sound_stabbed | boolean |
| 248 | debug_acoustics | boolean |
| 249 | light_local_basis | boolean |
| 250 | collision_log_render | boolean |
| 251 | collision_log_detailed | boolean |
| 252 | collision_log_extended | boolean |
| 253 | collision_log_totals_only | boolean |
| 254 | collision_log_time | boolean |
| 255 | havok_collision_tolerance | real |
| 256 | havok_debug_mode | long |
| 257 | havok_thread_count | long |
| 258 | havok_environment_type | long |
| 259 | havok_shape_radius | real |
| 260 | havok_jumping_beans | boolean |
| 261 | havok_disable_deactivation | boolean |
| 262 | havok_deactivation_reference_distance | real |
| 263 | havok_weld_environment | boolean |
| 264 | havok_batch_add_entities_disabled | boolean |
| 265 | havok_shape_cache | boolean |
| 266 | havok_shape_cache_debug | boolean |
| 267 | havok_enable_back_stepping | boolean |
| 268 | havok_enable_sweep_shapes | boolean |
| 269 | havok_display_stats | boolean |
| 270 | havok_initialize_profiling | boolean |
| 271 | impacts_debug | boolean |
| 272 | proxies_debug | boolean |
| 273 | collision_damage_debug | boolean |
| 274 | havok_play_impact_effects | boolean |
| 275 | havok_play_biped_impact_effects | boolean |
| 276 | physics_debug | boolean |
| 277 | havok_cleanup_inactive_agents | boolean |
| 278 | havok_render_environment_queries | boolean |
| 279 | havok_pause_time_on_find_initial_contact_points | boolean |
| 283 | debug_object_scheduler | boolean |
| 284 | render_debug_turn_on_cache_state | boolean |
| 285 | debug_use_black_for_missing_instances | boolean |
| 286 | render_environment | boolean |
| 287 | render_structure | boolean |
| 288 | render_per_vertex_lit_environment | boolean |
| 289 | render_per_pixel_lit_enviroment | boolean |
| 290 | render_single_probe_lit_environment | boolean |
| 291 | render_cluster_enabled | boolean |
| 292 | render_objects | boolean |
| 295 | render_rain_particles | boolean |
| 296 | render_light_volume_rain_particles | boolean |
| 297 | render_light_volume_rain_sheets | boolean |
| 298 | render_rain_from_design_tag | boolean |
| 299 | render_rain_occluder_as_normal_object | boolean |
| 300 | render_debug_enable_first_person_squish | boolean |
| 302 | render_lightmap_shadows_apply | boolean |
| 303 | render_lights | boolean |
| 305 | render_water_wireframe | boolean |
| 307 | render_water | boolean |
| 309 | render_debug_occlusion_bsp_index | long |
| 310 | render_debug_occlusion_instance_index | long |
| 311 | render_tessellated_wireframe | boolean |
| 312 | render_first_person | boolean |
| 313 | render_debug_mode | short |
| 314 | render_debug_safe_frame_bounds | boolean |
| 315 | render_debug_aspect_ratio_scale | real |
| 316 | render_debug_force_4x3_aspect_ratio | boolean |
| 317 | render_debug_transparents | boolean |
| 318 | render_debug_slow_transparents | boolean |
| 319 | render_transparents | boolean |
| 320 | render_low_res_transparents | boolean |
| 321 | render_debug_transparent_cull | boolean |
| 322 | render_debug_transparent_cull_flip | boolean |
| 323 | render_debug_transparent_sort_method | short |
| 324 | render_debug_lens_flares | boolean |
| 325 | render_debug_shield_instrumentation | boolean |
| 326 | render_instanced_geometry | boolean |
| 327 | render_sky | boolean |
| 328 | render_lens_flares | boolean |
| 329 | render_decals | boolean |
| 330 | neuticle_render | boolean |
| 331 | neuticle_update | boolean |
| 332 | neuticle_spawn | boolean |
| 333 | render_decorators | boolean |
| 334 | render_infinite_decorators | boolean |
| 335 | render_decorators_lod_mask | long |
| 336 | render_decorators_decimation_test | real |
| 337 | light_decorators | boolean |
| 338 | render_decorator_bounds | boolean |
| 339 | render_decorator_spheres | boolean |
| 340 | render_decorator_descriptions | boolean |
| 341 | render_debug_force_cinematic_lights | boolean |
| 342 | render_debug_pix_events | boolean |
| 343 | render_atmosphere_cluster_blend_data | boolean |
| 344 | render_debug_display_command_buffer_data | boolean |
| 345 | render_cloud_texture | boolean |
| 346 | render_debug_enable_z_prepass | boolean |
| 347 | render_debug_instance_occlusion | boolean |
| 348 | render_debug_screen_shaders | boolean |
| 349 | render_debug_screen_effects | boolean |
| 350 | render_screen_effects | boolean |
| 351 | render_debug_acoustic_sectors | boolean |
| 352 | render_debug_weather_dumplings | boolean |
| 353 | render_debug_atmosphere_dumplings | boolean |
| 354 | render_debug_min_single_pass_rendering_distance | real |
| 355 | render_pc_specular | boolean |
| 356 | render_pc_albedo_lighting | boolean |
| 357 | render_debug_save_surface | long |
| 364 | render_exposure_stops | real |
| 365 | display_exposure | boolean |
| 379 | render_shadow_bounds | boolean |
| 380 | render_shadow_bounds_solid | boolean |
| 381 | render_shadow_opaque | boolean |
| 382 | render_shadow_screenspace | boolean |
| 383 | render_shadow_histencil | boolean |
| 384 | render_shadow_hires | boolean |
| 385 | render_shadow_objectspace_stencil_clip | boolean |
| 386 | render_shadow_force_fancy | boolean |
| 387 | render_shadow_force_old | boolean |
| 388 | render_postprocess | boolean |
| 389 | render_accum | long |
| 390 | render_bloom_source | long |
| 391 | render_bloom | long |
| 392 | render_downsample | long |
| 393 | render_show_alpha | long |
| 394 | render_postprocess_exposure | real |
| 395 | render_accum_filter | long |
| 396 | render_tone_curve | boolean |
| 397 | render_tone_curve_white | real |
| 398 | render_exposure_lock | boolean |
| 399 | fxaa_mode | long |
| 405 | render_screenspace_center | real |
| 408 | render_disable_prt | boolean |
| 409 | force_render_lightmap_mesh | boolean |
| 410 | render_use_single_pass_rendering | boolean |
| 412 | render_debug_foliage_enable | boolean |
| 413 | render_debug_enable_pc_transparents | boolean |
| 414 | screenshot_anisotropic_level | long |
| 415 | screenshot_gamma | real |
| 416 | render_light_intensity | real |
| 417 | render_light_clip_planes | long |
| 418 | render_light_opaque | boolean |
| 419 | cubemap_debug | boolean |
| 420 | render_debug_cloth | boolean |
| 421 | render_debug_antennas | boolean |
| 422 | render_debug_leaf_systems | boolean |
| 423 | render_debug_object_lighting | boolean |
| 424 | render_debug_object_lighting_refresh | boolean |
| 425 | render_debug_use_cholocate_mountain | boolean |
| 426 | render_debug_use_contrast_adjustment | boolean |
| 427 | render_debug_use_min_luminance | boolean |
| 428 | render_debug_use_bounce_to_ambient | boolean |
| 429 | render_debug_object_lighting_use_scenery_probe | boolean |
| 430 | render_debug_object_lighting_use_device_probe | boolean |
| 431 | render_debug_object_lighting_use_air_probe | boolean |
| 432 | render_debug_show_air_probes | boolean |
| 433 | render_debug_infinite_framerate | boolean |
| 434 | render_debug_toggle_default_lightmaps_texaccum | long |
| 435 | render_debug_object_lighting_interpolation_difference_factor | real |
| 440 | render_debug_show_4x3_bounds | boolean |
| 441 | render_weather_bounds | boolean |
| 442 | render_debug_object_imposter | boolean |
| 443 | render_debug_object_imposter_always | boolean |
| 444 | render_debug_object_imposter_never | boolean |
| 445 | render_debug_instance_imposters | boolean |
| 446 | render_debug_instance_imposter_always | boolean |
| 447 | render_debug_instance_imposter_never | boolean |
| 448 | render_debug_instance_imposter_hide_rainbows | boolean |
| 449 | true | boolean |
| 450 | build_instance_imposters | boolean |
| 451 | render_debug_cinematic_clip | boolean |
| 452 | render_buffer_gamma | real |
| 453 | render_screen_gamma | real |
| 454 | render_buffer_gamma_curve | long |
| 455 | render_color_balance_red | real |
| 456 | render_color_balance_green | real |
| 457 | render_color_balance_blue | real |
| 458 | render_black_level_red | real |
| 459 | render_black_level_green | real |
| 460 | render_black_level_blue | real |
| 461 | debug_volume_samples | boolean |
| 462 | decal_create | boolean |
| 463 | decal_frame_advance | boolean |
| 464 | decal_render | boolean |
| 465 | decal_render_preplaced | boolean |
| 466 | decal_render_debug | boolean |
| 467 | decal_render_debug_info | boolean |
| 468 | decal_render_latest_debug | boolean |
| 469 | decal_cull | boolean |
| 470 | decal_fade | boolean |
| 471 | decal_dump | boolean |
| 472 | particle_create | boolean |
| 473 | particle_frame_advance | boolean |
| 474 | particle_render | boolean |
| 475 | particle_render_debug | boolean |
| 476 | particle_collision_debug | boolean |
| 477 | particle_collision_debug_priority | boolean |
| 478 | particle_render_debug_spheres | boolean |
| 479 | particle_cull | boolean |
| 480 | particle_dump | boolean |
| 481 | particle_force_cpu | boolean |
| 482 | particle_force_gpu | boolean |
| 483 | effect_priority_cutoff | long |
| 484 | render_debug_effect_text | boolean |
| 485 | render_debug_effect_distance_from_camera | boolean |
| 486 | render_debug_effect_name | boolean |
| 487 | render_debug_effect_active_emitter_counts | boolean |
| 488 | render_debug_effect_particle_counts | boolean |
| 489 | render_debug_effect_light_volume_counts | boolean |
| 490 | render_debug_effect_contrail_counts | boolean |
| 491 | render_debug_effect_beam_counts | boolean |
| 492 | render_debug_effect_bounding_speres | boolean |
| 493 | render_debug_effect_emitter_shape | boolean |
| 494 | render_debug_effect_toggle_particle_mode | long |
| 495 | render_debug_effect_toggle_light_mode | long |
| 496 | render_debug_effect_toggle_contrail_mode | long |
| 497 | render_debug_effect_toggle_beam_mode | long |
| 498 | weather_occlusion_max_height | real |
| 499 | render_debug_viewport_scale | real |
| 500 | render_debug_light_probes | long |
| 501 | effect_property_culling | boolean |
| 502 | contrail_create | boolean |
| 503 | contrail_pulse | boolean |
| 504 | contrail_frame_advance | boolean |
| 505 | contrail_submit | boolean |
| 506 | contrail_dump | boolean |
| 507 | light_volume_create | boolean |
| 508 | light_volume_frame_advance | boolean |
| 509 | light_volume_submit | boolean |
| 510 | light_volume_dump | boolean |
| 511 | beam_create | boolean |
| 512 | beam_frame_advance | boolean |
| 513 | beam_submit | boolean |
| 514 | beam_dump | boolean |
| 515 | debug_pvs | boolean |
| 516 | debug_pvs_render_all | boolean |
| 517 | debug_pvs_activation | boolean |
| 518 | pvs_building_disabled | boolean |
| 519 | debug_pvs_editor_mode | boolean |
| 520 | render_debug_full_bsp | boolean |
| 521 | render_default_lighting | boolean |
| 522 | render_debug_analytical_lightmap_light_enabled | boolean |
| 523 | render_debug_vmf_lightmap_light_enabled | boolean |
| 524 | render_debug_bounce_light_enabled | boolean |
| 525 | visibility_debug_portals_2d | boolean |
| 526 | visibility_debug_portals_2d_verbose | boolean |
| 527 | visibility_debug_portals_3d | boolean |
| 528 | visibility_debug_visible_cluster_portals_3d | boolean |
| 529 | visibility_debug_all_portals_3d | boolean |
| 530 | visibility_disable_conditional_portals | boolean |
| 531 | visibility_debug_visible_clusters | boolean |
| 532 | visibility_debug_portals_structure_bsp_index | long |
| 533 | visibility_debug_portals_cluster_index | long |
| 534 | visibility_debug_select_bsp_instance_visible | boolean |
| 535 | visibility_debug_select_bsp_instance_bsp_index | long |
| 536 | visibility_debug_select_bsp_instance_index | long |
| 537 | visibility_enable_occlusion | boolean |
| 538 | visibility_enable_multithreading | boolean |
| 539 | error_geometry_draw_names | boolean |
| 540 | error_geometry_tangent_space | long |
| 541 | error_geometry_lightmap_lights | long |
| 542 | debug_objects | boolean |
| 543 | debug_objects_position_velocity | boolean |
| 544 | debug_objects_origin | boolean |
| 545 | debug_objects_root_node | boolean |
| 546 | debug_objects_bounding_spheres | boolean |
| 547 | debug_objects_attached_aabbs | boolean |
| 548 | debug_objects_light_overlaps | boolean |
| 549 | debug_objects_attached_bounding_spheres | boolean |
| 550 | debug_objects_dynamic_render_bounding_spheres | boolean |
| 551 | debug_objects_render_models | boolean |
| 552 | debug_objects_collision_models | boolean |
| 553 | debug_objects_cookie_cutters | boolean |
| 554 | debug_objects_early_movers | boolean |
| 555 | debug_objects_contact_points | boolean |
| 556 | debug_objects_constraints | boolean |
| 557 | debug_objects_vehicle_physics | boolean |
| 558 | debug_objects_vehicle_effects | boolean |
| 559 | debug_objects_vehicle_engines | boolean |
| 560 | debug_objects_jetwash | boolean |
| 561 | debug_objects_mass | boolean |
| 562 | debug_objects_size | boolean |
| 563 | debug_objects_speed | boolean |
| 564 | debug_objects_havok_group | boolean |
| 565 | debug_objects_physics_models | boolean |
| 566 | debug_objects_expensive_physics | boolean |
| 567 | debug_objects_water_physics | boolean |
| 570 | debug_objects_names | boolean |
| 571 | debug_objects_collision_hierarchy | boolean |
| 572 | debug_objects_names_full | boolean |
| 573 | debug_objects_indices | boolean |
| 574 | debug_objects_indices_decimal | boolean |
| 575 | debug_objects_functions | boolean |
| 576 | debug_objects_functions_all | boolean |
| 577 | debug_objects_model_targets | boolean |
| 578 | debug_objects_pathfinding | boolean |
| 579 | debug_objects_node_bounds | boolean |
| 580 | debug_objects_unit_vectors | boolean |
| 581 | debug_objects_unit_boost | boolean |
| 582 | debug_objects_unit_seats | boolean |
| 583 | debug_objects_unit_mouth_apeture | boolean |
| 584 | debug_objects_unit_firing | boolean |
| 585 | debug_objects_unit_lipsync | boolean |
| 586 | debug_objects_unit_lipsync_verbose | boolean |
| 587 | debug_objects_unit_emotion | boolean |
| 588 | debug_objects_unit_acceleration | boolean |
| 589 | debug_objects_unit_camera | boolean |
| 590 | debug_objects_biped_autoaim_pills | boolean |
| 591 | debug_objects_physics_control_node | boolean |
| 592 | debug_objects_ground_plane | boolean |
| 593 | debug_objects_movement_mode | boolean |
| 594 | debug_objects_unit_pathfinding_surface | boolean |
| 595 | debug_objects_devices | boolean |
| 596 | debug_objects_machines | boolean |
| 597 | debug_objects_garbage | boolean |
| 598 | debug_objects_type_mask | long |
| 599 | debug_objects_sound_spheres | boolean |
| 600 | debug_objects_active_nodes | boolean |
| 601 | debug_objects_unit_soft_ping_damage_regions | boolean |
| 602 | debug_objects_animation_times | boolean |
| 603 | debug_objects_animation | boolean |
| 604 | debug_objects_spawn_timers | boolean |
| 605 | debug_objects_freeze_ragdolls | boolean |
| 606 | debug_objects_disable_relaxation | boolean |
| 607 | debug_objects_sentinel_physics_ignore_lag | boolean |
| 608 | debug_objects_ignore_node_masks | boolean |
| 609 | objects_move_multithreading_enabled | boolean |
| 610 | objects_compute_node_orientation_multithreading_enabled | boolean |
| 611 | objects_assert_on_job_inconsistancy | boolean |
| 612 | debug_objects_force_awake | boolean |
| 613 | debug_objects_disable_node_animation | boolean |
| 614 | debug_objects_dump_memory_stats | boolean |
| 615 | debug_objects_object | object |
| 616 | debug_objects_by_index | long |
| 617 | debug_objects_player_only | boolean |
| 618 | debug_objects_vehicle_suspension | boolean |
| 619 | debug_objects_skeletons | boolean |
| 620 | debug_objects_cluster_counts | boolean |
| 621 | debug_objects_cluster_count_threshold | long |
| 622 | debug_objects_networking | boolean |
| 623 | debug_objects_animation_pose_channel | long |
| 624 | render_model_nodes | boolean |
| 625 | render_model_point_counts | boolean |
| 626 | render_model_vertex_counts | boolean |
| 627 | render_model_names | boolean |
| 628 | render_model_triangle_counts | boolean |
| 629 | render_model_collision_vertex_counts | boolean |
| 630 | render_model_collision_surface_counts | boolean |
| 631 | render_model_texture_usage | boolean |
| 632 | render_model_geometry_usage | boolean |
| 633 | render_model_cost | boolean |
| 634 | render_model_markers | boolean |
| 635 | render_model_no_geometry | boolean |
| 636 | render_model_skinning_disable | boolean |
| 637 | debug_weapons | boolean |
| 638 | debug_weapons_triggers | boolean |
| 639 | debug_weapons_barrels | boolean |
| 640 | debug_weapons_magazines | boolean |
| 641 | debug_weapons_primary | boolean |
| 642 | debug_weapons_secondary | boolean |
| 643 | debug_damage | boolean |
| 644 | debug_player_damage | boolean |
| 645 | debug_damage_verbose | boolean |
| 646 | debug_damage_radius | boolean |
| 647 | debug_damage_transfer | boolean |
| 648 | debug_damage_acceleration | boolean |
| 649 | debug_damage_response | boolean |
| 650 | debug_damage_aoe | boolean |
| 651 | debug_damage_armor | boolean |
| 652 | debug_damage_material | boolean |
| 653 | debug_damage_networking | boolean |
| 654 | debug_damage_filter_output | boolean |
| 655 | debug_damage_large_font | boolean |
| 656 | debug_damage_player_inflicted_recent | boolean |
| 657 | debug_damage_player_inflicted_duration | real |
| 658 | hs_verbose | boolean |
| 659 | breakpoints_enabled | boolean |
| 660 | debug_trigger_volumes | boolean |
| 661 | debug_trigger_volume_triangulation | boolean |
| 662 | debug_point_physics | boolean |
| 663 | water_physics_debug | boolean |
| 664 | collision_debug | boolean |
| 665 | collision_debug_attached | boolean |
| 666 | collision_debug_water_proxy | boolean |
| 667 | collision_debug_spray | boolean |
| 668 | collision_debug_objects_in_sphere | boolean |
| 669 | collision_debug_objects_in_sphere_attached | boolean |
| 670 | collision_debug_features | boolean |
| 671 | collision_debug_phantom_bsp | boolean |
| 672 | collision_debug_lightmaps | boolean |
| 673 | collision_debug_geometry_sampling | boolean |
| 674 | collision_debug_print_position | boolean |
| 675 | collision_kd_tree_exhaustive_debugging_enabled | boolean |
| 676 | collision_kd_tree_debug | boolean |
| 677 | collision_kd_tree_minimum_radius | real |
| 678 | collision_kd_tree_maximum_depth | long |
| 679 | collision_debug_flags | long |
| 680 | collision_debug_flag_structure | boolean |
| 681 | collision_debug_flag_water | boolean |
| 682 | collision_debug_flag_instanced_geometry | boolean |
| 683 | collision_debug_flag_objects | boolean |
| 684 | collision_debug_flag_objects_bipeds | boolean |
| 685 | collision_debug_flag_objects_giants | boolean |
| 686 | collision_debug_flag_objects_effect_scenery | boolean |
| 687 | collision_debug_flag_objects_vehicles | boolean |
| 688 | collision_debug_flag_objects_weapons | boolean |
| 689 | collision_debug_flag_objects_equipment | boolean |
| 690 | collision_debug_flag_objects_terminals | boolean |
| 691 | collision_debug_flag_objects_projectiles | boolean |
| 692 | collision_debug_flag_objects_scenery | boolean |
| 693 | collision_debug_flag_objects_machines | boolean |
| 694 | collision_debug_flag_objects_controls | boolean |
| 695 | collision_debug_flag_objects_sound_scenery | boolean |
| 696 | collision_debug_flag_objects_crates | boolean |
| 697 | collision_debug_flag_objects_creatures | boolean |
| 698 | collision_debug_flag_ignore_child_objects | boolean |
| 699 | collision_debug_flag_ignore_nonpathfindable_objects | boolean |
| 700 | collision_debug_flag_ignore_cinematic_objects | boolean |
| 701 | collision_debug_flag_ignore_dead_bipeds | boolean |
| 702 | collision_debug_flag_ignore_passthrough_bipeds | boolean |
| 703 | collision_debug_flag_front_facing_surfaces | boolean |
| 704 | collision_debug_flag_back_facing_surfaces | boolean |
| 705 | collision_debug_flag_ignore_two_sided_surfaces | boolean |
| 706 | collision_debug_flag_ignore_invisible_surfaces | boolean |
| 707 | collision_debug_flag_ignore_breakable_surfaces | boolean |
| 708 | collision_debug_flag_allow_early_out | boolean |
| 709 | collision_debug_flag_try_to_keep_location_valid | boolean |
| 710 | collision_debug_repeat | boolean |
| 711 | collision_debug_point_x | real |
| 712 | collision_debug_point_y | real |
| 713 | collision_debug_point_z | real |
| 714 | collision_debug_vector_i | real |
| 715 | collision_debug_vector_j | real |
| 716 | collision_debug_vector_k | real |
| 717 | collision_debug_length | real |
| 718 | collision_debug_width | real |
| 719 | collision_debug_height | real |
| 720 | collision_debug_ignore_object_index | long |
| 721 | collision_debug_fill_face | boolean |
| 722 | debug_obstacle_path | boolean |
| 723 | debug_obstacle_path_on_failure | boolean |
| 724 | debug_obstacle_path_start_point_x | real |
| 725 | debug_obstacle_path_start_point_y | real |
| 726 | debug_obstacle_path_goal_point_x | real |
| 727 | debug_obstacle_path_goal_point_y | real |
| 728 | suppress_pathfinding_generation | boolean |
| 729 | enable_pathfinding_generation_xbox | boolean |
| 730 | ai_generate_flood_sector_wrl | boolean |
| 731 | ai_pathfinding_generate_stats | boolean |
| 732 | ai_pathfinding_use_exclusion | boolean |
| 733 | ai_pathfinding_no_outlines_on_poopie_cutters | boolean |
| 734 | debug_zone_set_critical_portals | boolean |
| 735 | debug_camera | boolean |
| 736 | debug_tangent_space | boolean |
| 737 | debug_player | boolean |
| 738 | debug_player_control_autoaim_always_active | boolean |
| 739 | debug_structure | boolean |
| 740 | debug_structure_occlude | boolean |
| 741 | debug_structure_complexity | boolean |
| 742 | debug_structure_water | boolean |
| 743 | debug_structure_invisible | boolean |
| 744 | debug_structure_cluster_skies | boolean |
| 745 | debug_structure_slip_surfaces | boolean |
| 746 | debug_structure_soft_ceilings | boolean |
| 747 | debug_structure_soft_ceilings_biped | boolean |
| 748 | debug_structure_soft_ceilings_vehicle | boolean |
| 749 | debug_structure_soft_ceilings_huge_vehicle | boolean |
| 750 | debug_structure_soft_ceilings_camera | boolean |
| 751 | debug_structure_soft_ceilings_test_observer | boolean |
| 752 | soft_ceilings_disable | boolean |
| 753 | debug_structure_soft_kill | boolean |
| 754 | debug_structure_cookie_cutters | boolean |
| 755 | debug_structure_seam_edges | boolean |
| 756 | debug_structure_seams | boolean |
| 757 | debug_structure_seam_triangles | boolean |
| 758 | debug_structure_seam_index | long |
| 759 | debug_structure_seam_triangles_status | boolean |
| 760 | debug_structure_seam_identical_instances | boolean |
| 761 | debug_structure_automatic | boolean |
| 762 | debug_structure_unique_colors | boolean |
| 763 | debug_instanced_geometry | boolean |
| 764 | debug_instanced_geometry_bounding_spheres | boolean |
| 765 | debug_instanced_geometry_names | boolean |
| 766 | debug_instanced_geometry_vertex_counts | boolean |
| 767 | debug_instanced_geometry_collision_geometry | boolean |
| 768 | debug_instanced_geometry_cookie_cutters | boolean |
| 769 | debug_instanced_geometry_physics | boolean |
| 770 | debug_instanced_geometry_physics_memory | boolean |
| 771 | debug_instanced_geometry_physics_memory_threshold | long |
| 772 | debug_structure_surface_references | boolean |
| 773 | debug_structure_markers | boolean |
| 774 | debug_bsp | boolean |
| 775 | debug_kd | boolean |
| 776 | debug_plane_index | long |
| 777 | debug_surface_index | long |
| 778 | debug_input | boolean |
| 779 | debug_leaf0_index | long |
| 780 | debug_leaf1_index | long |
| 781 | debug_leaf_connection_index | long |
| 782 | debug_cluster_index | long |
| 783 | debug_first_person_weapons | boolean |
| 784 | debug_first_person_models | boolean |
| 786 | lightmap_light_preview_mode | boolean |
| 787 | debug_lights | boolean |
| 788 | debug_preplaced_lights | boolean |
| 789 | debug_cheap_lights | boolean |
| 790 | debug_light_passes | boolean |
| 791 | debug_biped_landing | boolean |
| 792 | debug_biped_throttle | boolean |
| 793 | debug_biped_physics_nodes | boolean |
| 794 | debug_biped_death_program_selector | boolean |
| 795 | debug_biped_node_velocities | boolean |
| 796 | debug_biped_proximity_feelers | boolean |
| 797 | debug_collision_skip_instanced_geometry | boolean |
| 798 | debug_collision_skip_objects | boolean |
| 799 | debug_collision_skip_vectors | boolean |
| 800 | debug_collision_object_payload_collision | boolean |
| 801 | debug_collision_test_line_attached_disabled | boolean |
| 802 | debug_objects_in_sphere_attached_disabled | boolean |
| 803 | debug_material_effects | boolean |
| 804 | debug_material_default_effects | boolean |
| 805 | player_training_debug | boolean |
| 806 | player_training_disable | boolean |
| 807 | game_engine_debug_statborg | boolean |
| 808 | jaime_control_hack | boolean |
| 809 | bertone_control_hack | boolean |
| 810 | motor_system_debug | boolean |
| 811 | ai_profile_disable | boolean |
| 812 | ai_profile_random | boolean |
| 813 | ai_show | boolean |
| 814 | ai_show_stats | boolean |
| 815 | ai_show_actors | boolean |
| 816 | ai_show_swarms | boolean |
| 817 | ai_show_paths | boolean |
| 818 | ai_show_line_of_sight | boolean |
| 819 | ai_show_prop_types | boolean |
| 820 | ai_show_sound_distance | boolean |
| 821 | ai_render | boolean |
| 822 | ai_render_all_actors | boolean |
| 823 | ai_render_inactive_actors | boolean |
| 824 | ai_render_lineoffire_crouching | boolean |
| 825 | ai_render_lineoffire | boolean |
| 826 | ai_render_lineofsight | boolean |
| 827 | ai_render_ballistic_lineoffire | boolean |
| 828 | ai_render_vision_cones | boolean |
| 829 | ai_render_current_state | boolean |
| 830 | ai_render_detailed_state | boolean |
| 831 | ai_render_props | boolean |
| 832 | ai_render_props_web | boolean |
| 833 | ai_render_props_no_friends | boolean |
| 834 | ai_render_props_unreachable | boolean |
| 835 | ai_render_props_unopposable | boolean |
| 836 | ai_render_props_stimulus | boolean |
| 837 | ai_render_props_dialogue | boolean |
| 838 | ai_render_props_salience | boolean |
| 839 | ai_render_props_update | boolean |
| 840 | ai_render_props_search | boolean |
| 841 | ai_render_idle_look | boolean |
| 842 | ai_render_support_surfaces | boolean |
| 843 | ai_render_recent_damage | boolean |
| 844 | ai_render_current_damage | boolean |
| 845 | ai_render_threats | boolean |
| 846 | ai_render_emotions | boolean |
| 847 | ai_render_audibility | boolean |
| 848 | ai_render_aiming_vectors | boolean |
| 849 | ai_render_secondary_looking | boolean |
| 850 | ai_render_targets | boolean |
| 851 | ai_render_targets_all | boolean |
| 852 | ai_render_targets_last_visible | boolean |
| 853 | ai_render_target_groups | boolean |
| 854 | ai_render_states | boolean |
| 855 | ai_render_vitality | boolean |
| 856 | ai_render_vehicle_anchor | boolean |
| 857 | ai_render_flying_vehicle_movement_vectors | boolean |
| 858 | ai_render_flying_target_tail_cone | boolean |
| 859 | ai_render_evaluations | boolean |
| 860 | ai_render_evaluations_detailed | boolean |
| 861 | ai_render_evaluations_text | boolean |
| 862 | ai_render_evaluations_shading_type | short |
| 863 | ai_render_pursuit | boolean |
| 864 | ai_render_shooting | boolean |
| 865 | ai_render_trigger | boolean |
| 866 | ai_render_projectile_aiming | boolean |
| 867 | ai_render_aiming_validity | boolean |
| 868 | ai_render_speech | boolean |
| 869 | ai_render_leadership | boolean |
| 870 | ai_render_status_flags | boolean |
| 871 | ai_render_goal_state | boolean |
| 872 | ai_render_behavior_debug | boolean |
| 873 | ai_render_active_camo | boolean |
| 874 | ai_render_vehicle_attachment | boolean |
| 875 | ai_render_vehicle_reservations | boolean |
| 876 | ai_render_actor_blinddeaf | boolean |
| 877 | ai_render_morphing | boolean |
| 878 | ai_render_look_orders | boolean |
| 879 | ai_render_character_names | boolean |
| 880 | ai_render_character_definition | boolean |
| 881 | ai_render_behavior_failure | ai_behavior |
| 882 | ai_render_bunkering | boolean |
| 883 | ai_render_pathfinding_influence_map | short |
| 884 | ai_render_dialogue | boolean |
| 885 | ai_render_dialogue_queue | boolean |
| 886 | ai_render_dialogue_records | boolean |
| 887 | ai_render_dialogue_player_weights | boolean |
| 888 | ai_dialogue_test_mode | boolean |
| 889 | ai_dialogue_verbose_pattern_errors | boolean |
| 890 | ai_dialogue_datamine_enable | boolean |
| 891 | ai_dialogue_datamine_failed_patterns_enable | boolean |
| 892 | ai_dialogue_log_failed_pattern_errors | boolean |
| 893 | ai_dialogue_debug_specific_vocalization | string_id |
| 894 | ai_render_teams | boolean |
| 895 | ai_render_actor_types | boolean |
| 896 | ai_render_player_ratings | boolean |
| 897 | ai_render_spatial_effects | boolean |
| 898 | ai_render_firing_positions | boolean |
| 899 | ai_render_firing_position_statistics | boolean |
| 900 | ai_render_firing_position_obstacles | boolean |
| 901 | ai_render_firing_position_bunkering | boolean |
| 902 | ai_render_mission_critical | boolean |
| 903 | ai_render_gun_positions | boolean |
| 904 | ai_render_aiming_positions | boolean |
| 905 | ai_render_burst_geometry | boolean |
| 906 | ai_render_vehicle_avoidance | boolean |
| 907 | ai_render_vehicles_enterable | boolean |
| 908 | ai_render_melee_check | boolean |
| 909 | ai_render_dialogue_variants | boolean |
| 910 | ai_render_grenades | boolean |
| 911 | ai_render_danger_zones | boolean |
| 912 | ai_render_control | boolean |
| 913 | ai_render_activation | boolean |
| 914 | ai_render_paths | boolean |
| 915 | ai_render_paths_text | boolean |
| 916 | ai_render_paths_selected_only | boolean |
| 917 | ai_render_paths_destination | boolean |
| 918 | ai_render_paths_raw | boolean |
| 919 | ai_render_paths_current | boolean |
| 920 | ai_render_paths_failed | boolean |
| 921 | ai_render_paths_smoothed | boolean |
| 922 | ai_render_paths_avoided | boolean |
| 923 | ai_render_paths_error_thresholds | boolean |
| 924 | ai_render_paths_avoidance_segment | short |
| 925 | ai_render_paths_avoidance_obstacles | boolean |
| 926 | ai_render_paths_avoidance_search | boolean |
| 927 | ai_render_paths_nodes | boolean |
| 928 | ai_render_paths_nodes_all | boolean |
| 929 | ai_render_paths_nodes_polygons | boolean |
| 930 | ai_render_paths_nodes_costs | boolean |
| 931 | ai_render_paths_nodes_closest | boolean |
| 932 | ai_render_paths_distance | boolean |
| 933 | ai_render_player_aiming_blocked | boolean |
| 934 | ai_render_squad_patrol_state | boolean |
| 935 | ai_render_deceleration_obstacles | boolean |
| 936 | ai_render_recent_obstacles | boolean |
| 937 | ai_render_inertia | boolean |
| 938 | ai_render_throttle_control | boolean |
| 939 | ai_render_stopping_distance | boolean |
| 940 | ai_render_destination_tolerance | boolean |
| 942 | ai_use_path_attractor_bounds | boolean |
| 943 | ai_render_pathfinding_performance | boolean |
| 944 | ai_render_pathfinding_performance_threshold | short |
| 945 | ai_render_pathfinding_performance_cell_size | real |
| 946 | ai_render_combat_range | boolean |
| 947 | ai_render_dynamic_firing_positions | boolean |
| 948 | ai_render_clumps | boolean |
| 949 | ai_render_clump_props | boolean |
| 950 | ai_render_clump_props_all | boolean |
| 951 | ai_render_clump_dialogue | boolean |
| 952 | ai_render_sectors | boolean |
| 953 | ai_render_sector_bsps | boolean |
| 954 | ai_render_giant_sector_bsps | boolean |
| 955 | ai_render_sector_link_errors | boolean |
| 956 | ai_render_intersection_links | boolean |
| 957 | ai_render_non_walkable_sectors | boolean |
| 958 | ai_render_threshold_links | boolean |
| 959 | ai_render_sector_geometry_errors | boolean |
| 960 | ai_pathfinding_generation_verbose | boolean |
| 961 | ai_render_timeslices | boolean |
| 962 | ai_render_sectors_range_max | long |
| 963 | ai_render_sectors_range_min | long |
| 964 | ai_render_link_specific | long |
| 965 | ai_render_links | boolean |
| 966 | ai_render_link_detailed | boolean |
| 967 | ai_render_user_hints | boolean |
| 968 | ai_render_area_flight_hints | boolean |
| 969 | ai_render_hints | boolean |
| 970 | ai_render_hints_detailed | boolean |
| 971 | ai_render_object_hints | boolean |
| 972 | ai_render_object_hints_all | boolean |
| 973 | ai_render_object_properties | boolean |
| 974 | ai_render_hints_movement | boolean |
| 975 | ai_render_movement_mapping | boolean |
| 976 | ai_render_persistent_movement_override | boolean |
| 977 | ai_orders_print_entries | boolean |
| 978 | ai_orders_print_entries_verbose | boolean |
| 979 | ai_render_orders | boolean |
| 980 | ai_render_suppress_combat | boolean |
| 981 | ai_render_squad_patrol | boolean |
| 982 | ai_render_formations | boolean |
| 983 | ai_render_objectives | boolean |
| 984 | ai_render_strength | boolean |
| 985 | ai_render_squad_fronts | boolean |
| 986 | ai_render_squad_fronts_detailed | boolean |
| 987 | ai_render_ai_iterator | ai |
| 988 | ai_render_child_stack | boolean |
| 989 | ai_render_behavior_movement_type | boolean |
| 990 | ai_render_behavior_stack | boolean |
| 991 | ai_render_behavior_stack_all | boolean |
| 992 | ai_render_stimuli | boolean |
| 993 | ai_render_stimuli_all | boolean |
| 994 | ai_render_combat_status | boolean |
| 995 | ai_render_decisions | boolean |
| 996 | ai_render_decisions_all | boolean |
| 997 | ai_render_command_scripts | boolean |
| 998 | ai_render_script_data | boolean |
| 999 | ai_hide_actor_errors | boolean |
| 1000 | ai_debug_tracking_data | boolean |
| 1001 | ai_debug_perception_data | boolean |
| 1002 | ai_debug_combat_status | boolean |
| 1003 | ai_render_tracked_props | boolean |
| 1004 | ai_render_tracked_props_all | boolean |
| 1005 | ai_debug_vignettes | boolean |
| 1006 | ai_render_joint_behaviors | boolean |
| 1007 | ai_render_swarm | boolean |
| 1008 | ai_render_flocks | boolean |
| 1009 | ai_render_flock_boid_destination | boolean |
| 1010 | ai_render_flock_danger | boolean |
| 1011 | ai_render_flock_boid_properties | boolean |
| 1012 | ai_render_vehicle_interest | boolean |
| 1013 | ai_render_player_battle_vector | boolean |
| 1014 | ai_render_player_needs_vehicle | boolean |
| 1015 | ai_debug_prop_refresh | boolean |
| 1016 | ai_debug_all_disposable | boolean |
| 1017 | ai_debug_disable_high_priority_timeslices | boolean |
| 1021 | ai_render_vehicle_turns | boolean |
| 1022 | ai_render_discarded_firing_positions | boolean |
| 1023 | ai_render_firing_positions_all | boolean |
| 1024 | ai_render_firing_position_info | boolean |
| 1025 | ai_render_firing_position_index | boolean |
| 1026 | ai_inspect_avoidance_failure | boolean |
| 1027 | ai_render_action_selection_failure | boolean |
| 1028 | ai_render_debug_pathfinding | boolean |
| 1029 | ai_render_debug_pathfinding_wall_height | real |
| 1030 | ai_render_debug_pathfinding_wall_opacity | real |
| 1031 | ai_volume_avoidance_render | boolean |
| 1032 | ai_volume_avoidance_render_cuts | boolean |
| 1033 | ai_volume_avoidance_render_volumes | boolean |
| 1034 | ai_volume_avoidance_render_step_choices | boolean |
| 1035 | ai_volume_avoidance_render_step | long |
| 1036 | ai_volume_avoidance_render_tolerance | real |
| 1037 | ai_volume_avoidance_render_start_object_name | string_id |
| 1038 | ai_volume_avoidance_render_end_object_name | string_id |
| 1039 | ai_render_flying_cover | boolean |
| 1040 | ai_render_flying_area | boolean |
| 1041 | render_melee_sync_scoring | boolean |
| 1119 | ai_print_major_upgrade | boolean |
| 1120 | ai_print_evaluation_statistics | boolean |
| 1121 | ai_print_communication | boolean |
| 1122 | ai_print_communication_player | boolean |
| 1123 | ai_print_vocalizations | boolean |
| 1124 | ai_print_placement | boolean |
| 1125 | ai_print_speech | boolean |
| 1126 | ai_print_allegiance | boolean |
| 1127 | ai_print_lost_speech | boolean |
| 1128 | ai_print_migration | boolean |
| 1129 | ai_print_scripting | boolean |
| 1130 | ai_print_disposal | boolean |
| 1131 | ai_print_killing_sprees | boolean |
| 1132 | ai_naimad_spew | boolean |
| 1133 | ai_maxd_spew | boolean |
| 1134 | ai_debug_fast_los | boolean |
| 1135 | ai_debug_evaluate_all_positions | boolean |
| 1136 | ai_debug_path | boolean |
| 1137 | ai_debug_path_start_freeze | boolean |
| 1138 | ai_debug_path_end_freeze | boolean |
| 1139 | ai_debug_path_flood | boolean |
| 1140 | ai_debug_path_maximum_radius | real |
| 1141 | ai_debug_path_attractor | boolean |
| 1142 | ai_debug_path_attractor_radius | real |
| 1143 | ai_debug_path_attractor_weight | real |
| 1144 | ai_debug_path_accept_radius | real |
| 1145 | ai_debug_path_radius | real |
| 1146 | ai_debug_path_destructible | boolean |
| 1147 | ai_debug_path_giant | boolean |
| 1148 | ai_debug_ballistic_lineoffire_freeze | boolean |
| 1149 | ai_debug_path_naive_estimate | boolean |
| 1150 | ai_debug_blind | boolean |
| 1151 | ai_debug_deaf | boolean |
| 1152 | ai_debug_invisible_player | boolean |
| 1153 | ai_debug_ignore_player | boolean |
| 1154 | ai_debug_force_all_active | boolean |
| 1155 | ai_debug_path_disable_smoothing | boolean |
| 1156 | ai_debug_path_disable_obstacle_avoidance | boolean |
| 1157 | ai_render_level_of_detail | boolean |
| 1158 | ai_flocks_disable_timeslicing | boolean |
| 1159 | net_bitstream_debug | long |
| 1160 | net_bitstream_display_errors | boolean |
| 1161 | net_bitstream_capture_structure | boolean |
| 1162 | net_never_timeout | boolean |
| 1163 | net_replication_requests_print | boolean |
| 1164 | net_packet_print_mask | boolean |
| 1165 | net_experimental | boolean |
| 1166 | net_rate_unlimited | boolean |
| 1167 | net_rate_server | long |
| 1168 | net_rate_client | long |
| 1169 | net_bandwidth_unlimited | boolean |
| 1170 | net_bandwidth_per_channel | long |
| 1171 | net_skip_countdown | boolean |
| 1172 | net_host_delegation_disable | boolean |
| 1173 | net_speculative_host_migration_disable | boolean |
| 1174 | net_streams_disable | boolean |
| 1175 | net_ignore_version | boolean |
| 1176 | net_maximum_machine_count | long |
| 1177 | net_maximum_player_count | long |
| 1178 | net_allow_out_of_sync | boolean |
| 1179 | net_distributed_always | boolean |
| 1180 | net_distributed_never | boolean |
| 1181 | net_matchmaking_force_gather | boolean |
| 1182 | net_matchmaking_force_search | boolean |
| 1183 | net_matchmaking_fail_arbitration | boolean |
| 1184 | net_nat_override | long |
| 1185 | net_matchmaking_nat_check_enabled | boolean |
| 1186 | net_matchmaking_hopper_id_adjustment | long |
| 1187 | net_matchmaking_jackpot_override | long |
| 1188 | net_channel_manager_tear_down_secure_connection_early | boolean |
| 1189 | net_matchmaking_allow_early_start | boolean |
| 1190 | net_matchmaking_skip_host_migration | boolean |
| 1191 | net_matchmaking_force_disband | boolean |
| 1192 | net_enable_host_migration_loop | long |
| 1193 | net_enable_matchmaking_latency | long |
| 1194 | net_matchmaking_fake_progress | long |
| 1195 | net_matchmaking_force_no_joining | boolean |
| 1196 | net_matchmaking_allow_idle_controllers | boolean |
| 1197 | net_force_matchmaking_sync_halt_config | boolean |
| 1198 | net_set_channel_disconnect_interval | long |
| 1199 | net_disable_detatched_controller_check | boolean |
| 1200 | net_always_upload_matchmade_films | boolean |
| 1201 | net_never_block_for_film_uploading | boolean |
| 1202 | net_disable_active_roster_presence_hack | boolean |
| 1203 | net_disable_synchronous_halt_boots | boolean |
| 1204 | net_disable_lsp_leaderboards | boolean |
| 1205 | net_status_memory | boolean |
| 1206 | net_status_link | boolean |
| 1207 | net_status_channels | boolean |
| 1208 | net_status_connections | boolean |
| 1209 | net_status_message_queues | boolean |
| 1210 | net_status_observer | boolean |
| 1211 | net_status_sessions | boolean |
| 1212 | net_status_leaderboard | boolean |
| 1213 | net_status_leaderboard_mask | long |
| 1214 | net_status_idle_detection | boolean |
| 1215 | net_test | boolean |
| 1216 | net_test_rate | long |
| 1217 | net_test_debug_spheres | boolean |
| 1218 | net_test_matchmaking_playlist_index | long |
| 1219 | net_voice_diagnostics | boolean |
| 1220 | net_http_failure_ratio | real |
| 1221 | net_show_latency_and_framerate_metrics_on_chud | boolean |
| 1222 | net_fake_latency_and_framerate_metrics_on_chud | boolean |
| 1223 | net_drop_fraction_incoming | real |
| 1224 | net_disable_out_of_order_packet_handling | boolean |
| 1225 | sim_status_world | boolean |
| 1226 | sim_status_views | boolean |
| 1227 | sim_entity_validate | boolean |
| 1228 | sim_disable_aim_assist | boolean |
| 1229 | debug_player_teleport | boolean |
| 1230 | debug_players | boolean |
| 1231 | debug_player_input | boolean |
| 1232 | debug_player_input_stick_throws | boolean |
| 1233 | display_rumble_status_lines | boolean |
| 1234 | enable_pc_joystick | boolean |
| 1235 | rumble_enable_in_playback | boolean |
| 1236 | texture_cache_show_mipmap_bias | boolean |
| 1237 | texture_cache_graph | boolean |
| 1238 | texture_cache_list | boolean |
| 1239 | texture_cache_force_low_detail | boolean |
| 1240 | texture_cache_force_medium_detail | boolean |
| 1241 | texture_cache_force_high_detail | boolean |
| 1242 | texture_cache_status | boolean |
| 1243 | texture_cache_usage | boolean |
| 1244 | texture_cache_block_warning | boolean |
| 1245 | texture_cache_lod_bias | boolean |
| 1246 | texture_cache_dynamic_low_detail_texture | boolean |
| 1247 | render_debug_low_res_textures | boolean |
| 1248 | geometry_cache_graph | boolean |
| 1249 | geometry_cache_list | boolean |
| 1250 | geometry_cache_status | boolean |
| 1251 | geometry_cache_block_warning | boolean |
| 1252 | geometry_cache_never_block | boolean |
| 1253 | geometry_cache_debug_display | boolean |
| 1254 | director_camera_switch_fast | boolean |
| 1255 | director_camera_switch_disable | boolean |
| 1256 | debug_animation_camera_enable | boolean |
| 1257 | director_camera_speed_scale | real |
| 1258 | director_disable_first_person | boolean |
| 1259 | director_use_dt | boolean |
| 1260 | observer_collision_enabled | boolean |
| 1261 | observer_collision_anticipation_enabled | boolean |
| 1262 | observer_collision_water_flags | long |
| 1263 | observer_collision_debug | boolean |
| 1264 | g_observer_wave_height | real |
| 1265 | debug_recording | boolean |
| 1266 | debug_recording_newlines | short |
| 1267 | cinematic_letterbox_style | long |
| 1268 | run_game_scripts | boolean |
| 1269 | vehicle_status_display | boolean |
| 1270 | biped_meter_display | boolean |
| 1271 | default_scenario_ai_type | long |
| 1272 | debug_menu_enabled | boolean |
| 1273 | catch_exceptions | boolean |
| 1274 | debug_first_person_hide_base | boolean |
| 1275 | debug_first_person_hide_movement | boolean |
| 1276 | debug_first_person_hide_jitter | boolean |
| 1277 | debug_first_person_hide_overlay | boolean |
| 1278 | debug_first_person_hide_pitch_turn | boolean |
| 1279 | debug_first_person_hide_ammo | boolean |
| 1280 | debug_first_person_hide_ik | boolean |
| 1281 | global_playtest_mode | boolean |
| 1282 | ui_time_scale | real |
| 1283 | ui_display_memory | boolean |
| 1284 | ui_memory_verify | boolean |
| 1285 | xov_display_memory | boolean |
| 1286 | gui_debug_text_bounds_global | boolean |
| 1287 | gui_debug_bitmap_bounds_global | boolean |
| 1288 | gui_debug_model_bounds_global | boolean |
| 1289 | gui_debug_list_item_bounds_global | boolean |
| 1290 | gui_debug_list_bounds_global | boolean |
| 1291 | gui_debug_group_bounds_global | boolean |
| 1292 | gui_debug_screen_bounds_global | boolean |
| 1293 | gui_network_force_warning_index | long |
| 1294 | gui_network_force_error_index | long |
| 1295 | render_comment_flags | boolean |
| 1296 | render_comment_flags_text | boolean |
| 1297 | render_comment_flags_look_at | boolean |
| 1298 | enable_controller_flag_drop | boolean |
| 1299 | sapien_keyboard_toggle_for_camera_movement | boolean |
| 1300 | override_player_character_type | long |
| 1302 | debug_tag_dependencies | boolean |
| 1303 | check_system_heap | boolean |
| 1304 | data_mine_player_update_interval | long |
| 1305 | data_mine_mp_player_update_interval | long |
| 1306 | data_mine_debug_menu_interval | long |
| 1307 | data_mine_spam_enabled | long |
| 1308 | webstats_file_zip_writes_per_frame | long |
| 1309 | debug_projectiles | boolean |
| 1310 | debug_projectiles_network | boolean |
| 1311 | debug_projectiles_duration_post_death | real |
| 1312 | debug_projectiles_disable_authoritative_sticks | boolean |
| 1313 | debug_damage_effects | boolean |
| 1314 | debug_damage_effect_obstacles | boolean |
| 1315 | force_player_walking | boolean |
| 1316 | unit_animation_report_missing_animations | boolean |
| 1317 | font_cache_status | boolean |
| 1318 | font_cache_debug_texture | boolean |
| 1319 | font_cache_debug_graph | boolean |
| 1320 | font_cache_debug_list | boolean |
| 1322 | allow_sound_cache_file_editing | boolean |
| 1323 | halt_on_stack_overflow | boolean |
| 1324 | disable_progress_screen | boolean |
| 1325 | render_thread_enable | boolean |
| 1326 | character_force_physics | character_physics |
| 1327 | enable_new_ik_method | boolean |
| 1328 | animation_throttle_dampening_scale | real |
| 1329 | animation_blend_change_scale | real |
| 1330 | debug_animation_force_subframe_on_loop | boolean |
| 1331 | debug_animation_fp_jump_land_disable | boolean |
| 1332 | debug_animation_fp_weapon_ik_disable | boolean |
| 1333 | debug_animation_fp_sprint_disable | boolean |
| 1334 | animation_turn_speed_blend_scale | real |
| 1335 | biped_fitting_enable | boolean |
| 1336 | biped_fitting_root_offset_enable | boolean |
| 1337 | biped_pivot_enable | boolean |
| 1338 | biped_pivot_allow_player | boolean |
| 1339 | ik_disable | boolean |
| 1340 | ik_chain_fixup_disable | boolean |
| 1341 | giant_hunt_player | long |
| 1342 | giant_hunting_min_radius | real |
| 1343 | giant_hunting_max_radius | real |
| 1344 | giant_hunting_throttle_scale | real |
| 1345 | giant_weapon_wait_time | long |
| 1346 | giant_weapon_trigger_time | long |
| 1347 | giant_ik | boolean |
| 1348 | giant_foot_ik | boolean |
| 1349 | giant_ankle_ik | boolean |
| 1350 | giant_elevation_control | boolean |
| 1351 | giant_force_buckle | boolean |
| 1352 | giant_force_crouch | boolean |
| 1353 | giant_force_death | boolean |
| 1354 | giant_buckle_rotation | boolean |
| 1355 | debug_objects_giant_feet | boolean |
| 1356 | debug_objects_giant_buckle | boolean |
| 1357 | enable_xsync_timings | boolean |
| 1358 | allow_restricted_tag_groups_to_load | boolean |
| 1359 | xsync_restricted_tag_groups | boolean |
| 1360 | enable_cache_build_resources | boolean |
| 1361 | xma_compression_level_default | long |
| 1362 | enable_console_window | boolean |
| 1363 | display_colors_in_banded_gamma | boolean |
| 1364 | use_tool_command_legacy | boolean |
| 1365 | maximum_tool_command_history | long |
| 1366 | disable_unit_aim_screens | boolean |
| 1367 | disable_unit_look_screens | boolean |
| 1368 | disable_unit_eye_tracking | boolean |
| 1369 | enable_tag_resource_xsync | boolean |
| 1370 | dont_recompile_shaders | boolean |
| 1371 | insepcting_xenon_shader | boolean |
| 1373 | scenario_load_all_tags | boolean |
| 1374 | synchronization_debug | boolean |
| 1375 | debug_objects_scenery | boolean |
| 1376 | disable_switch_zone_sets | boolean |
| 1377 | facial_animation_testing_enabled | boolean |
| 1378 | profiler_datamine_uploads_enabled | boolean |
| 1379 | debug_object_recycling | boolean |
| 1380 | enable_sound_over_network | boolean |
| 1381 | lsp_allow_lsp_connections | boolean |
| 1382 | lsp_allow_raw_connections | boolean |
| 1383 | lsp_service_id_override | long |
| 1384 | shared_files_enable | boolean |
| 1385 | sound_manager_debug_suppression | boolean |
| 1386 | serialize_update_and_render | boolean |
| 1387 | minidump_use_retail_provider | boolean |
| 1388 | scenario_use_non_bsp_zones | boolean |
| 1389 | allow_restricted_active_zone_reloads | boolean |
| 1390 | debug_scenario_content_status | boolean |
| 1391 | debug_cinematic_controls_enable | boolean |
| 1392 | debug_skulls | boolean |
| 1393 | debug_campaign_metagame | boolean |
| 1394 | debug_campaign_metagame_verbose | boolean |
| 1395 | campaign_metagame_datamine | boolean |
| 1396 | aiming_interpolation_stop_delta | real |
| 1397 | aiming_interpolation_start_delta | real |
| 1398 | aiming_interpolation_rate | real |
| 1399 | airborne_arc_enabled | boolean |
| 1400 | airborne_descent_test_duration | real |
| 1401 | airborne_descent_test_count | long |
| 1407 | disable_main_loop_throttle | boolean |
| 1408 | enable_partial_cache_flush | boolean |
| 1409 | force_unit_walking | boolean |
| 1410 | leap_force_start_rotation | boolean |
| 1411 | leap_force_end_rotation | boolean |
| 1412 | leap_force_flight_start_rotation | boolean |
| 1413 | leap_force_flight_end_rotation | boolean |
| 1414 | leap_flight_path_scale | real |
| 1415 | leap_departure_power | real |
| 1416 | leap_departure_scale | real |
| 1417 | leap_arrival_power | real |
| 1418 | leap_arrival_scale | real |
| 1419 | leap_twist_power | real |
| 1420 | leap_cannonball_power | real |
| 1421 | leap_cannonball_scale | real |
| 1422 | leap_idle_power | real |
| 1423 | leap_idle_scale | real |
| 1424 | leap_overlay_power | real |
| 1425 | leap_overlay_scale | real |
| 1426 | leap_interpolation_limit | real |
| 1427 | biped_fake_soft_landing | boolean |
| 1428 | biped_fake_hard_landing | boolean |
| 1429 | biped_soft_landing_recovery_scale | real |
| 1430 | biped_hard_landing_recovery_scale | real |
| 1431 | biped_landing_absorbtion | real |
| 1432 | debug_player_network_aiming | boolean |
| 1433 | collision_hierarchy_objects_in_cone_enabled | boolean |
| 1434 | aim_assist_disable_target_lead_vector | boolean |
| 1435 | enable_tag_edit_sync | boolean |
| 1436 | cache_file_builder_allow_sharing | boolean |
| 1437 | render_debug_dont_flash_low_res_textures | boolean |
| 1438 | debug_objects_pendulum | boolean |
| 1439 | ui_alpha | boolean |
| 1440 | ui_alpha_lockdown | long |
| 1441 | ui_alpha_eula_accepted | boolean |
| 1442 | ui_alpha_custom_games_enabled | long |
| 1443 | ui_new_user_experience_suppress | boolean |
| 1444 | net_config_client_badness_rating_threshold_override | long |
| 1445 | net_config_disable_bad_client_anticheating_override | long |
| 1446 | net_config_disable_bad_connectivity_anticheating_override | long |
| 1447 | net_config_disable_bad_bandwidth_anticheating_override | long |
| 1448 | net_config_maximum_multiplayer_split_screen_override | long |
| 1449 | net_config_crash_handling_minidump_type_override | long |
| 1450 | net_config_crash_handling_ui_display_override | long |
| 1451 | online_files_slowdown | long |
| 1452 | debug_trace_main_events | boolean |
| 1453 | force_xsync_memory_buyback | boolean |
| 1454 | bitmaps_trim_unused_pixels | boolean |
| 1455 | bitmaps_interleave_compressed_bitmaps | boolean |
| 1459 | cache_file_builder_dump_tag_sections | boolean |
| 1461 | giant_custom_anim_recovery_time | real |
| 1462 | facial_animation_enable_lipsync | boolean |
| 1463 | facial_animation_enable_gestures | boolean |
| 1464 | facial_animation_enable_noise | boolean |
| 1467 | enable_audibility_generation | boolean |
| 1473 | motion_blur_fps_threshold | real |
| 1474 | antialias_blur_compare | boolean |
| 1475 | antialias_fps_threshold | real |
| 1476 | unicode_warn_on_truncation | boolean |
| 1477 | debug_determinism_version | long |
| 1478 | debug_determinism_compatible_version | long |
| 1479 | debug_fire_teams | boolean |
| 1480 | player_can_issue_fireteam_directive | boolean |
| 1484 | error_geometry_environment_enabled | boolean |
| 1485 | error_geometry_lightmap_enabled | boolean |
| 1486 | error_geometry_seam_enabled | boolean |
| 1487 | error_geometry_instance_enabled | boolean |
| 1488 | error_geometry_object_enabled | boolean |
| 1489 | debug_objects_unit_melee | boolean |
| 1492 | debug_objects_root_node_print | boolean |
| 1494 | require_secure_cache_files | boolean |
| 1495 | require_secure_variants | boolean |
| 1496 | debug_aim_assist_targets_enabled | boolean |
| 1497 | debug_aim_assist_targets_names | boolean |
| 1498 | debug_aim_assist_vectors | boolean |
| 1503 | cinematic_debugging_enable | boolean |
| 1504 | cinematic_debugging_verbose_enable | boolean |
| 1505 | import_sound_write_diagnostic_files | boolean |
| 1506 | import_sound_cut_samples_simple | boolean |
| 1507 | import_sound_cut_samples_search_count | long |
| 1508 | import_sound_cut_samples_slope_count | long |
| 1509 | sound_no_hdd_turn_on_the_juice | boolean |
| 1510 | sound_no_hdd_caching_enabled | boolean |
| 1511 | game_state_allow_insecure | boolean |
| 1512 | dump_cache_builder_determinism_log | boolean |
| 1513 | dump_cache_builder_determinism_log_full | boolean |
| 1514 | allow_insecure_resources | boolean |
| 1515 | use_new_dialogue_stripping | boolean |
| 1516 | ragdoll_immediately_on_death | boolean |
| 1517 | xsync_all_language_for_sound | boolean |
| 1518 | debug_sound_totals | boolean |
| 1519 | debug_sound_class_totals | boolean |
| 1520 | debug_multiplayer_object_properties | boolean |
| 1521 | g_enable_debug_animation_solving | boolean |
| 1522 | g_animation_debug_initial_camera_distance | real |
| 1523 | g_animation_debug_initial_target_vertical_offset | real |
| 1524 | objective_player_can_buy_while_dead | boolean |
| 1525 | objective_auto_switch_to_dead_cam_delay | real |
| 1526 | objective_dead_cam_respawning_delay_before_voluntary_control_of_spawn | real |
| 1527 | objective_dead_cam_respawn_suppression | boolean |
| 1528 | objective_dead_cam_respawn_time_resets_when_switching_targets | boolean |
| 1529 | objective_dead_cam_extermination_allows_push_to_respawn | boolean |
| 1530 | objective_dead_cam_enable_push_to_respawn | boolean |
| 1531 | objective_dead_cam_respawning_respawn_time_on_player_seconds | real |
| 1532 | objective_dead_cam_respawning_respawn_time_at_base_seconds | real |
| 1533 | objective_dead_cam_respawning_respawn_time_at_base_after_extermination_seconds | real |
| 1534 | objective_allow_laser_designation_selection_of_objectives | boolean |
| 1535 | objective_buy_menu_screen_button_override_dpad_up | boolean |
| 1536 | requisition_auto_enter_drivers_seat_of_purchased_vehicles | boolean |
| 1537 | requisition_enable_budget_limits | boolean |
| 1538 | laser_designation_control_enable | boolean |
| 1539 | laser_designation_control_as_toggle | boolean |
| 1540 | laser_designation_allow_firing_at_own_laser | boolean |
| 1541 | laser_designation_requires_equipment | boolean |
| 1542 | laser_designation_laser_point_fade_out_seconds | real |
| 1543 | net_show_simulation_quality_machine_index | long |
| 1544 | simulation_interpolation_visualize | boolean |
| 1545 | simulation_interpolation_disable_all_position_interpolation | boolean |
| 1546 | simulation_interpolation_disable_all_rotation_interpolation | boolean |
| 1547 | simulation_interpolation_force_all_interpolation_to_use_velocity_bumps | boolean |
| 1548 | simulation_interpolation_force_all_interpolation_to_use_blending | boolean |
| 1549 | simulation_interpolation_use_override_position_config | boolean |
| 1550 | simulation_interpolation_use_override_rotation_config | boolean |
| 1551 | simulation_interpolation_force_all_interpolation_to_use_warps | boolean |
| 1552 | simulation_interpolation_disable_velocity_bumps | boolean |
| 1553 | simulation_interpolation_disable_blends | boolean |
| 1554 | debug_instance_imposters | boolean |
| 1555 | debug_instance_groups | boolean |
| 1556 | debug_instance_group_decorator_type | boolean |
| 1557 | debug_instance_group_non_decorator_type | boolean |
| 1558 | debug_instance_group_members | boolean |
| 1559 | debug_instance_group_bounds | boolean |
| 1560 | render_debug_big_battle_squads | boolean |
| 1561 | megalo_debug | boolean |
| 1562 | megalo_debug_filter_lists | boolean |
| 1563 | debug_objects_physics_models_render_polyhedron_points | boolean |
| 1564 | net_pretend_latency | long |
| 1565 | net_force_voice_transmission_frequency | real |
| 1566 | cache_file_builder_allow_invalid_map_sizes | boolean |
| 1567 | weapon_barrel_create_projectiles_log | boolean |
| 1568 | display_prefetch_progress | boolean |
| 1569 | cache_file_builder_unshare_unique_map_locations | boolean |
| 1570 | damage_response_ignore_seat_ejection | boolean |
| 1571 | spawning_unseen_spawning_cone_distance | real |
| 1572 | spawning_unseen_spawning_cone_angle | real |
| 1574 | aim_assist_log | boolean |
| 1575 | use_old_object_node_matrix_computation_method | boolean |
| 1576 | player_profile_read_minimum_duration_milliseconds | long |
| 1577 | player_profile_write_minimum_duration_milliseconds | long |
| 1578 | player_profile_bypass_hash_check | boolean |
| 1579 | debug_main_time_throttle_when_matching_remote_time | boolean |
| 1580 | debug_performances | boolean |
| 1581 | debug_performance_name | string_id |
| 1582 | megalo_profiling_mode | long |
| 1583 | megalo_filter_iteration_enabled | boolean |
| 1584 | net_force_sync_turbo_channel | long |
| 1585 | net_force_sync_turbo_all | boolean |
| 1586 | net_force_sync_turbo_none | boolean |
| 1587 | g_fade_to_black_enabled | boolean |
| 1588 | debug_weapon_tracking | boolean |
| 1589 | debug_unit_tracking | boolean |
| 1590 | superforge | boolean |
| 1591 | debug_melee_dash | boolean |
| 1592 | g_use_halo3_and_atlas_shipping_leftover_ticks_approach | boolean |
| 1593 | g_debug_draw_observer | boolean |
| 1594 | g_use_old_player_control_timing_algorithm | boolean |
| 1595 | g_disable_input_adjustment | boolean |
| 1596 | g_main_debug_fake_game_ticks | boolean |
| 1597 | g_main_debug_fake_game_ticks_duration_milliseconds | long |
| 1598 | g_wait_for_previous_frame_swap | boolean |
| 1599 | g_force_main_time_update_seconds_elapsed | real |
| 1600 | g_main_always_publish_on_game_tick | boolean |
| 1602 | debug_use_omaha_synchronous_game_time_matching | boolean |
| 1603 | assert_on_weak_damage_owner_code | boolean |
| 1604 | watermark_enabled | boolean |
| 1605 | watermark_compass_enabled | boolean |
| 1606 | chud_cache_render_data | boolean |
| 1607 | net_debug_channel_to_graph | long |
| 1608 | net_dump_network_statistics_on_upload | boolean |
| 1609 | net_host_selection_logging_verbose | boolean |
| 1611 | render_debug_visibility_bounding_sphere_scale | real |
| 1612 | game_engine_events_show_even_with_unparsed_tokens | boolean |
| 1613 | debug_button_action_mapping_active | boolean |
| 1614 | randomize_player_appearance_on_spawn | boolean |
| 1615 | render_debug_pause_aging | boolean |
| 1616 | main_disable_pix_counters | boolean |
| 1617 | net_always_record_bandwidth | boolean |
| 1618 | use_playtest_rasterizer_throttle | boolean |
| 1619 | render_debug_game_grief | boolean |
| 1620 | render_debug_players_probability_of_winning | boolean |
| 1621 | chud_state_debug_flag | boolean |
| 1622 | render_invisible_models | boolean |
| 1623 | main_block_simulate_ms | long |
| 1624 | net_block_simulate_ms | long |
| 1625 | net_message_queue_stress_test_pct | long |
| 1626 | convex_decomposition_enabled | boolean |
| 1627 | transport_force_shutdown | long |
| 1628 | prune_globals_for_gametype | boolean |
| 1629 | disable_saved_film_history | boolean |
| 1630 | allow_vehicle_to_vehicle_boarding | boolean |
| 1631 | visibility_query_plane_count | long |
| 1632 | jumperjumper_enabled | boolean |
| 1633 | net_banhammer_lsp_sync_enabled | boolean |
| 1634 | supply_depot_notification_enabled | boolean |
| 1635 | nag_messages_enabled | boolean |
| 1636 | film_farm_enabled | boolean |
| 1637 | net_log_all_message_queue_state | boolean |
| 1638 | debug_havok_memory | boolean |
| 1639 | render_transparents_bucket_low_res | long |
| 1640 | observer_collision_speed_scale | real |
| 1641 | leave_bonobo_init_in_place | boolean |
| 1643 | allow_spawning_with_no_spawn_points | boolean |
| 1644 | cui_service_record_test_enabled | boolean |
| 1645 | debug_aim_assist_lead_vectors_disabled | boolean |
| 1646 | first_person_motion_blur_speed_mapping_scale | real |
| 1647 | first_person_motion_blur_speed_mapping_offset | real |
| 1648 | special_object_motion_blur_speed_mapping_scale | real |
| 1649 | special_object_motion_blur_speed_mapping_offset | real |
| 1650 | debug_suppress_crosshair_player_names | boolean |
| 1651 | debug_suppress_all_game_engine_player_names | boolean |
| 1653 | debug_airstrike | boolean |
| 1654 | cui_debug_window_index | boolean |
| 1655 | cui_render_debug_enabled | boolean |
| 1657 | render_coop_spawn_safety_status_tests | boolean |
| 1658 | network_friends_leaderboard_test_enabled | boolean |
| 1659 | decal_bias_coeff_d | real |
| 1660 | decal_bias_coeff_e | real |
| 1661 | dump_game_options_on_establish_fail | boolean |
| 1664 | campaign_save_tracker_test_content_item_exists | long |
| 1665 | override_file_transfer_upstream_quota_bytes_per_second | long |
| 1666 | enable_prefetch_resource_defragmentation | boolean |
| 1668 | use_command_buffer_shadow_generate | boolean |
| 1669 | rasterizer_profiler_single_callback_enabled | boolean |
| 1675 | mvar_files_enabled | boolean |
| 1676 | mglo_files_enabled | boolean |
| 1678 | debug_snap_to_map_variant | boolean |
| 1679 | enable_initial_bink_reclaim | boolean |
| 1680 | map_variant_debug | boolean |
| 1681 | map_variant_debug_objects | boolean |
| 1682 | display_simulation_profiler_events | boolean |
| 1683 | render_max_z_prepass_splitscreen_count | long |
| 1684 | use_draw_bundles | boolean |
| 1685 | flicker_draw_bundles | boolean |
| 1686 | draw_bundle_stats | boolean |
| 1687 | flush_draw_bundle_cache | boolean |
| 1688 | render_durango_depth_downscale | boolean |
| 1689 | render_strobe_low_res_transparency | boolean |
| 1690 | render_low_res_transparency_use_gpu_threshold | boolean |
| 1691 | render_low_res_transparency_gpu_enable_ms | real |
| 1692 | render_low_res_transparency_gpu_disable_ms | real |
| 1693 | render_low_res_transparency_gpu_threshold_hysteresis_frames | long |
| 1694 | render_low_res_transparency_read_compressed_surface | boolean |
| 1696 | havok_debug_immediate | boolean |
| 1697 | debug_sound_manager_channels | boolean |
| 1699 | use_shadow_depth_bias_tweak | boolean |
| 1700 | shadow_depth_bias_tweak | real |
| 1701 | shadow_slope_depth_bias_tweak | real |
| 1703 | page_cache_enable_status_lines | boolean |
| 1704 | show_dynamic_buffer_stats | boolean |
| 1705 | high_quality_shadows | boolean |
| 1706 | high_quality_shadow_filter | boolean |
| 1707 | render_debug_instance_imposter_alpha_scale_override | boolean |
| 1708 | render_debug_instance_imposter_alpha_scale | real |
| 1709 | render_debug_instance_imposter_distance_scale_override | boolean |
| 1710 | render_debug_instance_imposter_distance_scale | real |
| 1711 | saved_film_tool_data_enable | boolean |
| 1715 | breadcrumbs_navpoints_enabled_override | boolean |
