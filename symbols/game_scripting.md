# Game scripting (HaloScript and Megalo)

Part of the MCC Reach system map. Build haloreach.dll, MCC 1.3528 (sha256 738dd2d24ea3aea12e1ee9aa4a61094bf116027d42004c35a19e5048608b0894). See the [system map](SYSTEM-MAP.md).

Game scripting is the two virtual machines that drive Reach gameplay logic. HaloScript (hsc) is Bungie's engine script VM and its large bank of built-in functions, used mainly by the campaign and by engine glue. Megalo is the gametype scripting VM that multiplayer variants run on, including Forge-aware traits and per-object labels.

This family was lifted out of the game-engine grouping into its own top level because the two VMs are large and distinct from rules and scoring.

Coverage: 1620 of 1623 functions carrying this system tag have a name (1177 supported, 1 corroborated, 442 inferred). The remaining 3 are tagged to the system but not yet named.

## Subsystems and named functions

### haloscript

The HaloScript VM and its built-in function bank: script evaluation, object lists, game globals, zone-set switching and the hsc built-ins.

Showing 24 of 1450 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x35370` | `game_zone_set_switch_now` | supported |
| `0x353fc` | `game_zone_set_prepare_to_switch` | supported |
| `0x59330` | `game_over_set` | supported |
| `0x59c70` | `random_seed_advance_for_player_actions` | supported |
| `0x817ec` | `object_list_datum_arrays_initialize` | supported |
| `0x82528` | `script_documentation_line_print` | supported |
| `0x82674` | `script_documentation_file_write` | supported |
| `0x8283c` | `script_function_signature_format` | supported |
| `0x82fa0` | `hs_globals_array_set_new_base_address` | supported |
| `0x84154` | `hs_sleep_eval` | supported |
| `0x8415c` | `hs_cinematic_sleep_eval` | supported |
| `0x84490` | `hs_sleep_until_eval` | supported |
| `0x84498` | `hs_sleep_until_game_ticks_eval` | supported |
| `0x84948` | `hs_datum_arrays_initialize` | supported |
| `0x84f94` | `hs_runtime_update` | supported |
| `0x86cbc` | `hs_evaluate_stub_return_void_used_by_595_descriptors` | supported |
| `0xb28b8` | `sound_class_set_gain_db_by_name` | supported |
| `0xb2994` | `sound_class_set_ducker_enabled_by_name` | supported |
| `0xbb880` | `game_sound_scripted_sound_start` | supported |
| `0xbd368` | `game_sound_scripted_sound_stop` | supported |
| `0x10ddd8` | `firefight_new_wave_event_log` | supported |
| `0x1664e0` | `game_save_attempt_event_log` | supported |
| `0x19493c` | `hs_compile_begin_family` | supported |
| `0x194b18` | `hs_compile_if` | supported |



### megalo

The Megalo gametype VM: opcode execution, loops, object labels, random number draws, and the Forge trait lists multiplayer variants read.

Showing 24 of 170 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x5695c` | `mglo_file_name_build` | supported |
| `0x70f04` | `megalo_object_labels_relink` | supported |
| `0x74970` | `forge_engine_trait_list_read` | supported |
| `0xf6da8` | `game_random_below` | supported |
| `0xf6de8` | `megalo_for_each_loop_execute` | supported |
| `0xfa314` | `game_stat_increment_clamped_to_limits` | supported |
| `0x104808` | `game_engine_player_added` | supported |
| `0x1079a4` | `trait_record_sanitize_block_00` | supported |
| `0x108b1c` | `trait_record_sanitize_copy` | supported |
| `0x146a28` | `megalo_numeric_reference_write` | supported |
| `0x14753c` | `megalo_engine_instance_update` | supported |
| `0x147958` | `megalo_execute_triggers` | supported |
| `0x147a5c` | `megalo_object_death_event` | supported |
| `0x147c08` | `megalo_damage_kill_event` | supported |
| `0x147ec8` | `custom_game_engine_player_record_initialize` | supported |
| `0x147f18` | `megalo_player_team_index_get` | supported |
| `0x1481e0` | `megalo_player_trait_list_read` | supported |
| `0x14918c` | `megalo_post_tick_update` | supported |
| `0x149874` | `megalo_player_respawn_rule` | supported |
| `0x149e74` | `megalo_player_record_detect_changes` | supported |
| `0x14a060` | `megalo_player_record_apply_update` | supported |
| `0x14ad14` | `megalo_trigger_invoke_frame` | supported |
| `0x14d208` | `megalo_object_label_lists_insert` | supported |
| `0x14d528` | `megalo_label_list_unlink` | supported |


## Data structures

On-disk tag layouts (Assembly plugins; on-disk, not runtime):

- `scnr` (scenario) carries the compiled HaloScript: script nodes, globals and source. `hsc_` is a small related group.
- Multiplayer variant and Megalo data travel in the game variant and map-variant blobs rather than a single tag group.

Runtime (from direct reading of the code):

- HaloScript globals were decoded into a globals table; object lists are datum arrays initialized by `object_list_datum_arrays_initialize`.
- Megalo executes opcodes against the engine's object and team entities; `megalo_object_labels_relink` and `megalo_for_each_loop_execute` show the label and loop machinery.

## Entry points and call flow

Known entry points (names from this build):

- HaloScript: zone-set control (`game_zone_set_switch_now`, `game_zone_set_prepare_to_switch`), match end (`game_over_set`), and the per-player random advance (`random_seed_advance_for_player_actions`).
- Megalo: file naming (`mglo_file_name_build`), label relink (`megalo_object_labels_relink`), the for-each loop (`megalo_for_each_loop_execute`), the random draw (`game_random_below`), and Forge trait reading (`forge_engine_trait_list_read`).

The VM dispatch loops are named at their entry, but a full opcode-by-opcode table is only partly recovered for Megalo and larger but still incomplete for the HaloScript built-in bank.

## Open questions / not yet mapped

- The complete Megalo opcode table (every opcode number to its handler) is not yet fully mapped.
- Many HaloScript built-ins are named but their exact argument and return semantics are inferred.
- How gametype script state is serialized into the variant blob is only partly understood.
