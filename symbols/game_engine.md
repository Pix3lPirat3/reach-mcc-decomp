# Game engine (rules, scoring, timing, variants, settings, spawning)

Part of the MCC Reach system map. Build haloreach.dll, MCC 1.3528 (sha256 738dd2d24ea3aea12e1ee9aa4a61094bf116027d42004c35a19e5048608b0894). See the [system map](SYSTEM-MAP.md).

Game engine is the game-mode runtime: the rules and scoring, round and match timing, game variants and player traits, gameplay settings, and respawn/spawn-point selection. It is the layer that turns a loaded map plus a gametype into an actual match.

Coverage: 924 of 936 functions carrying this system tag have a name (363 supported, 0 corroborated, 561 inferred). The remaining 12 are tagged to the system but not yet named.

## Subsystems and named functions

### core

The core game loop and game-mode dispatch.

Showing 20 of 448 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0xd2ac` | `game_options_clear` | supported |
| `0xd358` | `game_options_player_slot_clear` | supported |
| `0x16024` | `game_state_shell_initialize` | supported |
| `0x16394` | `game_state_header_initialize_for_new_map` | supported |
| `0x1713c` | `game_state_header_file_io` | supported |
| `0x171ac` | `game_state_data_file_io` | supported |
| `0x37f94` | `game_engine_team_index_next_with_flag` | supported |
| `0x56a88` | `game_globals_initialize` | supported |
| `0x57174` | `copy_supplied_parent_into_tls48_context_and_update_suffix_fields` | supported |
| `0x57434` | `game_update_tick` | supported |
| `0x575ac` | `game_update_systems` | supported |
| `0x57b6c` | `zero_parent_storage_and_reset_embedded_variant` | supported |
| `0x57c60` | `sanitize_parent_substorage_and_embedded_variant` | supported |
| `0x57c90` | `game_options_validate` | supported |
| `0x58708` | `game_starting_event_log` | supported |
| `0x59330` | `game_over_set` | supported |
| `0x5c218` | `game_time_initialize` | supported |
| `0x5c3d8` | `game_time_get_safe_in_seconds` | supported |
| `0x5c410` | `game_time_get` | supported |
| `0x5c484` | `game_time_update` | supported |



### scoring

Score, standings, stats and scoreboard bookkeeping. The mislabeled `clock` tag folds here because its functions are standings bookkeeping, not timing.

Showing 20 of 157 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x79c14` | `game_engine_player_rank_value_get` | supported |
| `0x7a818` | `game_engine_first_leading_team_get` | supported |
| `0x7a888` | `game_engine_first_leading_player_get` | supported |
| `0x7b28c` | `game_engine_standings_leader_get` | supported |
| `0x80634` | `game_engine_score_block_get` | supported |
| `0x80e08` | `game_ending_statistics_event_log` | supported |
| `0xf976c` | `game_results_record_incident` | supported |
| `0xfa458` | `game_engine_stats_set` | supported |
| `0xfa550` | `game_engine_player_stats_read_word` | supported |
| `0xfa5a0` | `game_engine_player_stats_accessor` | supported |
| `0xfa6cc` | `game_stats_player_write` | supported |
| `0xfa71c` | `game_stats_write_place_and_clamped_score` | supported |
| `0xfa88c` | `game_stats_counter_add_kind` | supported |
| `0xfb0e4` | `game_results_view_snapshot_copy` | supported |
| `0xfdf6c` | `game_results_receive` | supported |
| `0x1092b0` | `incident_initialize` | supported |
| `0x16fff0` | `game_results_upload_request_build` | supported |
| `0x18f5a8` | `game_engine_score_block_bank_round` | supported |
| `0x19171c` | `game_engine_standings_player_rank_get` | supported |
| `0x1917e8` | `game_engine_standings_team_rank_get` | supported |



### rules timing

Round and match timers, time limits and end conditions.

Showing 10 of 10 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x79b20` | `game_engine_player_score_get` | supported |
| `0x7a0d0` | `game_engine_round_time_limit_seconds` | supported |
| `0x109968` | `incident_dispatch_event_responses` | supported |
| `0x398b48` | `net_session_leader_set_parameter_value` | supported |
| `0x7c344` | `game_engine_round_timers_init` | inferred |
| `0x10b910` | `incident_player_kill` | inferred |
| `0x10bde4` | `incident_process_kill` | inferred |
| `0x18b62c` | `game_engine_handle_incident` | inferred |
| `0x18f54c` | `game_score_mark_all_dirty` | inferred |
| `0x1fa05c` | `incident_response_applies_to_viewer` | inferred |



### variants

Game-variant wrappers, gametype option records and player traits.

Showing 20 of 28 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x36cd8` | `game_variant_word_f83c_get` | supported |
| `0x36ce0` | `game_variant_word_f83c_set` | supported |
| `0x371b8` | `game_variant_object_construct` | supported |
| `0x373a0` | `game_variant_blf_chunk_decode` | supported |
| `0x37890` | `game_variant_clone_via_stream` | supported |
| `0x67f34` | `game_variant_wrapper_copy_data_to_block` | supported |
| `0x680c4` | `game_variant_clone` | supported |
| `0x68d74` | `game_variant_wrapper_set_option_choice` | supported |
| `0x68e08` | `game_variant_choice_records_equal` | supported |
| `0x69f14` | `variant_wrapper_create_from_file_buffer` | supported |
| `0x6a548` | `game_variant_file_load` | supported |
| `0x741c4` | `forge_engine_instance_update` | supported |
| `0x7a10c` | `game_engine_score_limit_get` | supported |
| `0x7fa80` | `game_engine_player_team_slot_assign` | supported |
| `0xdd6a0` | `game_variant_reset` | supported |
| `0xddeb8` | `game_variant_option_value_get` | supported |
| `0xe023c` | `game_variant_settings_set_byte_2_limit_60` | supported |
| `0xe0250` | `game_variant_settings_set_byte_3_5bit` | supported |
| `0xe0658` | `game_variant_settings_set_byte_1_limit_50` | supported |
| `0xe0678` | `game_variant_block_set_byte_3` | supported |



### settings

Gameplay settings and option storage. These rows are largely MCC Unreal settings view-model and widget code.

Showing 20 of 145 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x1e98d4` | `mcc_host_get_video_settings` | supported |
| `0x1fbad8` | `mcc_window_update_client_size` | supported |
| `0x202a28` | `mcc_engine_vtable18_call_5_0` | supported |
| `0xa5fa6c` | `mcc_settings_apply_quality_preset` | supported |
| `0xa7cc48` | `mcc_settings_set_quality_preset` | supported |
| `0xb0cce0` | `mcc_get_game_user_settings` | supported |
| `0xb38034` | `mcc_settings_vm_set_resolution_index` | supported |
| `0xb380a8` | `mcc_settings_vm_set_aspect_ratio_index` | supported |
| `0xbf3fd0` | `Z_Construct_UFunction_UMCCSettingsCategoryViewModel_HandleControllerInputBindingChanged` | supported |
| `0xbf4000` | `Z_Construct_UFunction_UMCCSettingsCategoryViewModel_HandleInputBindingChanged` | supported |
| `0xbf4360` | `Z_Construct_UFunction_UMCCSettingsCategoryWidget_HandleSettingsButtonPressed` | supported |
| `0xbf4390` | `Z_Construct_UFunction_UMCCSettingsCategoryWidget_HandleSettingsOptionHovered` | supported |
| `0xbf43c0` | `Z_Construct_UFunction_UMCCSettingsCategoryWidget_HandleSettingsOptionSelected` | supported |
| `0xbf43f0` | `Z_Construct_UFunction_UMCCSettingsCategoryWidget_HandleSettingsOptionUnhovered` | supported |
| `0xbf704c` | `MCCSettingsCategoryViewModel_GetPrivateStaticClass` | supported |
| `0xbf70ec` | `MCCSettingsCategoryWidget_GetPrivateStaticClass` | supported |
| `0xbf7444` | `MCCSettingsCategoryViewModel_StaticRegisterNatives` | supported |
| `0xbf7468` | `MCCSettingsCategoryWidget_StaticRegisterNatives` | supported |
| `0xbf79bc` | `MCCSettingsCategoryViewModel_execHandleControllerInputBindingChanged` | supported |
| `0xbf7afc` | `MCCSettingsCategoryViewModel_execHandleInputBindingChanged` | supported |



### spawning

Respawn and spawn-point selection rules (object instantiation itself lives under objects).

Showing 20 of 136 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x4482c` | `player_initialize_from_options_entry` | supported |
| `0x46274` | `player_respawn_start` | supported |
| `0x46ac8` | `player_control_entry_validate` | supported |
| `0x47050` | `cinematic_skipped_event_log` | supported |
| `0x4875c` | `player_ordinal_get` | supported |
| `0x487c4` | `player_start_profile_class_get` | supported |
| `0x488ac` | `player_start_profile_get` | supported |
| `0x49ce8` | `player_spawn_location_select` | supported |
| `0x4a9c8` | `players_spawn_with_loadout` | supported |
| `0x519f8` | `game_options_players_build_from_datum` | supported |
| `0x735fc` | `forge_per_player_update` | supported |
| `0x73ffc` | `forge_players_tick_update` | supported |
| `0x78f7c` | `game_world_start` | supported |
| `0x7a258` | `player_respawn_wait_check` | supported |
| `0x7a3c4` | `player_entry_byte_1d8_set_and_mark_dirty` | supported |
| `0x7eef4` | `game_engine_player_team_get` | supported |
| `0x810ac` | `player_respawn_rule_query` | supported |
| `0xfefb0` | `spawn_location_is_free` | supported |
| `0xff13c` | `spawn_location_is_not_watched` | supported |
| `0xff34c` | `spawn_point_scan` | supported |


## Data structures

On-disk tag layouts (Assembly plugins; on-disk, not runtime):

- `matg` (globals) holds engine-wide globals and string-table references.
- `scnr` (scenario) holds spawn points, trigger volumes and map metadata (map id, map name, map type).
- `mulg` (multiplayer globals) and `play` carry multiplayer defaults.

Runtime: game variant and player-trait records travel in the variant blob; the settings subsystem stores option values through MCC's settings view-models.

## Entry points and call flow

Entry points: the match-end path (`game_over_set`, shared with HaloScript) and the spawning functions drive the visible rules. Scoring and stats are updated through the scoring functions as events occur.

The complete per-gametype rule evaluation is not fully traced; much of the variant-specific logic lives in Megalo (see game_scripting).

## Open questions / not yet mapped

- The full set of gametype option records and how each maps to behavior is only partly named.
- Spawn-point selection scoring is named at entry but not fully traced.
- The settings subsystem is MCC Unreal code; its link to engine gameplay values is not fully drawn.
