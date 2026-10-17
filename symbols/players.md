# Players

Part of the MCC Reach system map. Build haloreach.dll, MCC 1.3528 (sha256 738dd2d24ea3aea12e1ee9aa4a61094bf116027d42004c35a19e5048608b0894). See the [system map](SYSTEM-MAP.md).

Players is the local player representation: the player datum and player-facing control, the camera/observer system that builds the view, and controller/device input sampling.

Note the split in where the code lives. The player datum and the camera (director/observer) are native Halo engine code. Input, by contrast, is largely MCC's Unreal-side UI binding code (the `MCCInputBinding*` widgets), because MCC routes device input through its UMG layer.

Coverage: 249 of 262 functions carrying this system tag have a name (52 supported, 0 corroborated, 197 inferred). The remaining 13 are tagged to the system but not yet named.

## Subsystems and named functions

### player

The player datum, player state and player-facing control: player creation, local-user assignment, and the unit a player drives.

Showing 20 of 110 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x43440` | `players_initialize` | supported |
| `0x43dc8` | `player_new` | supported |
| `0x539cc` | `player_local_user_assign` | supported |
| `0x53b5c` | `player_local_user_index_get` | supported |
| `0x53ca4` | `player_users_unit_assign` | supported |
| `0x53d7c` | `local_user_player_assign` | supported |
| `0x53e70` | `player_local_users_clear` | supported |
| `0x53ec8` | `local_user_player_get` | supported |
| `0x53ef8` | `local_user_unit_get` | supported |
| `0x53f28` | `player_local_user_next` | supported |
| `0x53f98` | `local_user_is_valid` | supported |
| `0x54044` | `player_local_user_iterator_next` | supported |
| `0x54070` | `local_user_unit_set` | supported |
| `0x5d3d0` | `player_control_initialize` | supported |
| `0x809c0` | `player_pair_relation_matrix_update` | supported |
| `0x93f94` | `object_physics_cache_record_update` | supported |
| `0xfa314` | `game_stat_increment_clamped_to_limits` | supported |
| `0x107af0` | `player_traits_decode_block_0x00` | supported |
| `0x1080dc` | `player_traits_decode_block_0x0c` | supported |
| `0x108820` | `player_traits_decode_block_0x20` | supported |



### camera

The camera system: the director that picks a camera mode and the observer that builds the actual view.

Showing 20 of 116 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0xc3eb4` | `director_initialize` | supported |
| `0xc461c` | `director_camera_debug_text_format` | supported |
| `0xc7b5c` | `observer_initialize` | supported |
| `0x133ddc` | `c_game_director__get_dead_desired_camera_mode` | supported |
| `0x16f994` | `observers_get_min_distance_squared_to_point` | supported |
| `0x1da088` | `scripted_camera_transform_camera_into_flag_space` | supported |
| `0x4560f0` | `player_set_orbiting_camera_target_event_get_name` | supported |
| `0x1da94` | `spring_damper_integrate_vector3d` | inferred |
| `0xc30d0` | `game_local_user_count_clamped_1_to_4` | inferred |
| `0xc3140` | `c_player_render_camera_iterator` | inferred |
| `0xc31f4` | `main_render_view` | inferred |
| `0xc3e74` | `director_globals_publish_state_pointer` | inferred |
| `0xc3e94` | `director_scripting_publish_state_pointer` | inferred |
| `0xc42e4` | `director_initialize_for_saved_game` | inferred |
| `0xc43ec` | `director_initialize_for_new_map` | inferred |
| `0xc4458` | `director_update` | inferred |
| `0xc453c` | `director_reset` | inferred |
| `0xc5040` | `survival_mode_update_flying_camera` | inferred |
| `0xc51f8` | `director_player_get_team_index` | inferred |
| `0xc527c` | `director_handle_deleted_object` | inferred |



### input

Controller and device input. These rows are MCC Unreal UMG input-binding widgets, named from the engine's reflection data.

Showing 20 of 23 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0xbd440c` | `MCCInputBindingViewModel_GetPrivateStaticClass` | supported |
| `0xbd4e3c` | `MCCInputBindingViewModel_StaticRegisterNatives` | supported |
| `0xbd58f4` | `MCCInputBindingViewModel_execHandleAction` | supported |
| `0xbe5a2c` | `Z_Construct_UFunction_UMCCOptionInputBindingDisplayWidget_HandleOnClicked` | supported |
| `0xbe5b0c` | `Z_Construct_UFunction_UMCCOptionInputBindingWidget_HandleOnClickedPrimary` | supported |
| `0xbe5b3c` | `Z_Construct_UFunction_UMCCOptionInputBindingWidget_HandleOnClickedSecondary` | supported |
| `0xbe5b6c` | `Z_Construct_UFunction_UMCCOptionInputBindingWidget_HandleOnHoveredPrimary` | supported |
| `0xbe5d34` | `Z_Construct_UFunction_UMCCOptionInputControllerBindingWidget_GetButtonCurrentMappingName` | supported |
| `0xbe7b0c` | `MCCOptionInputBindingDisplayWidget_GetPrivateStaticClass` | supported |
| `0xbe7bac` | `MCCOptionInputBindingWidget_GetPrivateStaticClass` | supported |
| `0xbe7c4c` | `MCCOptionInputControllerBindingWidget_GetPrivateStaticClass` | supported |
| `0xbe8fa0` | `MCCOptionInputBindingDisplayWidget_StaticRegisterNatives` | supported |
| `0xbe8fc4` | `MCCOptionInputBindingWidget_StaticRegisterNatives` | supported |
| `0xbe8fe8` | `MCCOptionInputControllerBindingWidget_StaticRegisterNatives` | supported |
| `0xbe9a9c` | `MCCOptionInputControllerBindingWidget_execGetButtonCurrentMappingName` | supported |
| `0xbe9cac` | `MCCOptionInputBindingDisplayWidget_execHandleOnClicked` | supported |
| `0xbe9d24` | `MCCOptionInputBindingWidget_execHandleOnClickedPrimary` | supported |
| `0xbe9d9c` | `MCCOptionInputControllerBindingWidget_execHandleOnClickedPrimary` | supported |
| `0xbe9e14` | `MCCOptionInputBindingWidget_execHandleOnClickedSecondary` | supported |
| `0xbe9e8c` | `MCCOptionInputBindingWidget_execHandleOnHoveredPrimary` | supported |


## Data structures

Runtime (from direct reading of the code):

- Player datum: a per-player record in the players pool, created by `player_new` and initialized by `players_initialize`. Local-user assignment ties a player to a signed-in local user (`player_local_user_assign`, `player_local_user_index_get`) and to the unit it controls (`player_users_unit_assign`).
- Camera: a director object (`director_initialize`) selects a camera mode (`c_game_director__get_dead_desired_camera_mode`) and an observer object (`observer_initialize`) builds the view.

Input widget names (MCCInputBinding*) come from the Unreal reflection tables, so they are reliable identifiers even though the underlying handler bodies are MCC code.

## Entry points and call flow

Entry points: `players_initialize` sets up the players pool at game start; `player_new` creates a player; the director and observer are initialized per view. The camera is rebuilt each frame from the director's chosen mode.

The exact per-frame camera construction math and the full input routing from device to game action are only partly mapped.

## Open questions / not yet mapped

- The full player datum field layout is not established beyond the local-user and unit links.
- Camera mode selection is named but the per-mode view math is not fully traced.
- Input mapping from the UMG binding widgets down to in-game actions is not fully drawn.
