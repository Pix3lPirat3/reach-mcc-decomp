# User interface (HUD, UMG, screens, controller)

Part of the MCC Reach system map. Build haloreach.dll, MCC 1.3528 (sha256 738dd2d24ea3aea12e1ee9aa4a61094bf116027d42004c35a19e5048608b0894). See the [system map](SYSTEM-MAP.md).

UI is the in-game HUD, the UMG/Slate widget runtime, menu screens, and controller-driven navigation. It is one of the largest systems because MCC rebuilds most of Reach's front end and menus in Unreal's UMG, so a great many rows are Unreal widget classes named from reflection data.

Two different worlds live here. The combat HUD (chud) and navpoints are native Halo rendering. The menus, screens, settings and most widgets are MCC Unreal UMG (`MCC*` and `SdWidget*` classes), named reliably from the engine's reflection tables.

Coverage: 3654 of 3753 functions carrying this system tag have a name (1947 supported, 0 corroborated, 1707 inferred). The remaining 99 are tagged to the system but not yet named.

## Subsystems and named functions

### hud

The combat HUD (chud), navpoints and in-game overlays. The duplicate `hud`/`ui_hud` tags and `navpoint` were merged here.

Showing 20 of 1737 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x20c38` | `global_preferences_release` | supported |
| `0x28820` | `observer_update` | supported |
| `0x2e6f4` | `font_package_directory_path_build` | supported |
| `0x2e768` | `font_package_directory_path_build_alt` | supported |
| `0x2e98c` | `font_package_file_name_build` | supported |
| `0x2ef90` | `ascii_sprintf_unbounded` | supported |
| `0x421e0` | `file_exists` | supported |
| `0x422b0` | `file_open` | supported |
| `0x4259c` | `file_read` | supported |
| `0x899dc` | `language_short_code_from_index` | supported |
| `0xa4330` | `initialize_kind_four_options_in_supplied_parent` | supported |
| `0xc57d8` | `director_user_unit_get` | supported |
| `0xc7f98` | `observer_update_all` | supported |
| `0xc8724` | `observer_reset` | supported |
| `0xcbb94` | `font_cache_lock_acquire` | supported |
| `0xcbbdc` | `font_cache_lock_release` | supported |
| `0xcc294` | `font_character_data_cache_initialize` | supported |
| `0xcc624` | `font_cache_idle_status_lines` | supported |
| `0xcd294` | `font_package_cache_update_status_lines` | supported |
| `0x14885c` | `custom_game_engine_should_draw_navpoint` | supported |



### umg

The UMG/Slate widget runtime (SdWidget and MCC widget classes).

Showing 20 of 1419 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0xbb48e8` | `Z_Construct_UFunction_AMCCActorDollSpawnMarker_Hide` | supported |
| `0xbb4918` | `Z_Construct_UFunction_AMCCActorDollSpawnMarker_SetIdleAnimation` | supported |
| `0xbb4a30` | `Z_Construct_UFunction_UMCCBackgroundCustomizationItemWidget_HandleClicked` | supported |
| `0xbb4a60` | `Z_Construct_UFunction_UMCCBackgroundCustomizationItemWidget_HandleFocusLost` | supported |
| `0xbb4a90` | `Z_Construct_UFunction_UMCCBackgroundCustomizationItemWidget_HandleFocusReceived` | supported |
| `0xbb4ac0` | `Z_Construct_UFunction_UMCCBackgroundCustomizationItemWidget_HandleHovered` | supported |
| `0xbb4cd8` | `Z_Construct_UFunction_UMCCBootmovieWidget_HandleBinkMediaOpened` | supported |
| `0xbb4d08` | `Z_Construct_UFunction_UMCCBootmovieWidget_HandleBinkMediaReachedEnd` | supported |
| `0xbb4d38` | `Z_Construct_UFunction_UMCCBootmovieWidget_HandleMediaEndReached` | supported |
| `0xbb4d68` | `Z_Construct_UFunction_UMCCBootmovieWidget_HandleMediaFailed` | supported |
| `0xbb4ec8` | `Z_Construct_UFunction_UMCCBackgroundWidget_HandleBinkMediaOpened` | supported |
| `0xbb4ef8` | `Z_Construct_UFunction_UMCCBackgroundWidget_HandleMediaFailed` | supported |
| `0xbb4f28` | `Z_Construct_UFunction_UMCCBackgroundWidget_HandleMediaOpened` | supported |
| `0xbb4f58` | `Z_Construct_UFunction_UMCCBackgroundWidget_OnHideVideo` | supported |
| `0xbb4f88` | `Z_Construct_UFunction_UMCCBackgroundWidget_OnMediaOpened` | supported |
| `0xbb4fb8` | `Z_Construct_UFunction_UMCCBackgroundWidget_OnShowVideo` | supported |
| `0xbb50a8` | `Z_Construct_UFunction_UMCCAudioSubsystem_HandleBankLoadedEvent` | supported |
| `0xbb5108` | `Z_Construct_UFunction_UMCCBaseButtonWidget_HandleOnClicked` | supported |
| `0xbb5138` | `Z_Construct_UFunction_UMCCBaseButtonWidget_HandleOnFocused` | supported |
| `0xbb5168` | `Z_Construct_UFunction_UMCCBaseButtonWidget_HandleOnHovered` | supported |



### screens

Menu screens and screen flow.

Showing 20 of 270 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x1e66b0` | `mcc_pause_active_flag_update` | supported |
| `0x1ecf6c` | `mcc_pause_menu_open` | supported |
| `0x1ed288` | `mcc_campaign_carnage_report_open` | supported |
| `0x1eda10` | `mcc_pause_request` | supported |
| `0x1eda44` | `mcc_pause_release` | supported |
| `0x1edae8` | `mcc_pause_menu_close` | supported |
| `0x1f111c` | `mcc_hud_scoring_set_visible` | supported |
| `0x202a58` | `mcc_hud_scoring_command_execute` | supported |
| `0x2f7e80` | `mcc_friends_panel_event_router` | supported |
| `0x2f8014` | `mcc_friends_panel_promote` | supported |
| `0x2f8098` | `mcc_host_forward_player_id_event` | supported |
| `0x329cec` | `mcc_mainmenu_select_game` | supported |
| `0x3c2608` | `mcc_screen_push_custom_game` | supported |
| `0x3c27e0` | `mcc_screen_push_find_game` | supported |
| `0x3c2a90` | `mcc_screen_push_search` | supported |
| `0x3c2b4c` | `mcc_screen_push_matchmaking_mix` | supported |
| `0x3c2d00` | `mcc_screen_push_quick_match` | supported |
| `0x3c2d44` | `mcc_screen_push_cgb_filter` | supported |
| `0x3c2d64` | `mcc_screen_push_cgb_browser` | supported |
| `0x3c2d94` | `mcc_screen_push_cgb_create` | supported |



### controller

Controller-driven UI navigation and view-models.

Showing 20 of 228 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x1f64d0` | `mcc_ui_runtime_init` | supported |
| `0x1f7788` | `mcc_frame_pump` | supported |
| `0x1f95f8` | `mcc_frame_tick` | supported |
| `0x1fc21c` | `mcc_menu_set_mode_0` | supported |
| `0x209460` | `mcc_menu_state_party_prison_get_id` | supported |
| `0x278cd0` | `mcc_menu_state_matchmaking_mix_get_id` | supported |
| `0x2b4088` | `mcc_frame_timing_dispatch` | supported |
| `0x2c3730` | `mcc_menu_state_restart_screen_get_id` | supported |
| `0x317430` | `mcc_menu_state_ftue_get_id` | supported |
| `0x32b2f0` | `mcc_menu_enter_mission_remix` | supported |
| `0x32b974` | `mcc_menu_enter_firefight` | supported |
| `0x34ee9c` | `mcc_menu_mode_set` | supported |
| `0x3ceb40` | `mcc_menu_state_boot_movie_get_id` | supported |
| `0x3cec30` | `mcc_menu_state_campaign_lobby_get_id` | supported |
| `0x3cec70` | `mcc_menu_state_multiplayer_custom_game_get_id` | supported |
| `0x3cecf0` | `mcc_menu_state_mission_remix_get_id` | supported |
| `0x3ced2c` | `mcc_menu_state_spartan_ops_get_id` | supported |
| `0x3ced90` | `mcc_menu_state_multiplayer_search_get_id` | supported |
| `0x3cedf8` | `mcc_menu_state_theatre_get_id` | supported |
| `0x3cee58` | `mcc_menu_state_firefight_custom_game_get_id` | supported |


## Data structures

Most UI structures are Unreal UObject/UWidget instances whose field layout is defined by Unreal reflection rather than a Halo tag. The widget and view-model names (MCC*, SdWidget*) are read from the reflection tables, so the names are dependable even where the behavior is not traced.

The native combat HUD draws from chud tag data (not in the tag-plugin set used here) and from navpoint submit calls. Runtime HUD layouts are not fully recovered.

## Entry points and call flow

Entry points: UMG widgets expose generated `exec*` thunks and `StaticRegisterNatives`/`GetPrivateStaticClass` entries (from Unreal reflection). The native HUD is driven from the game update; navpoints are submitted by gameplay and drawn as a HUD overlay.

Screen flow (which screen opens which) is only partly mapped; most screen rows are named by class, not by traced transitions.

## Open questions / not yet mapped

- The native combat HUD runtime layout and draw order are only partly recovered.
- Screen-to-screen flow is not traced; screens are named by class.
- Because most rows are reflection-named Unreal classes, having a name does not mean the behavior is understood.
