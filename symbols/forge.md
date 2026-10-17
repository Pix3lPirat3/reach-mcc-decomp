# Forge

Part of the MCC Reach system map. Build haloreach.dll, MCC 1.3528 (sha256 738dd2d24ea3aea12e1ee9aa4a61094bf116027d42004c35a19e5048608b0894). See the [system map](SYSTEM-MAP.md).

Forge is the in-game map editor, its UI and object menus, and the map-variant data it writes. The editor runs inside a normal game session: it reads the player's input, turns edits into network commands, and places or moves objects that are stored in a fixed array of placement records.

Coverage: 230 of 236 functions carrying this system tag have a name (105 supported, 0 corroborated, 125 inferred). The remaining 6 are tagged to the system but not yet named.

## Subsystems and named functions

### forge core

Forge object placement and the editor runtime: the per-tick edit loop, placing, holding, moving and deleting objects.

Showing 18 of 182 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x36edc` | `game_variant_copy_body` | supported |
| `0x37000` | `game_variant_equals` | supported |
| `0x37300` | `game_variant_type_size` | supported |
| `0x38c30` | `map_variant_base_map_id_from_scenario_id` | supported |
| `0x3c5fc` | `map_variant_guid_from_scenario_id` | supported |
| `0x67900` | `map_variant_blf_file_init` | supported |
| `0x690c4` | `game_variant_blf_file_init` | supported |
| `0x692c4` | `map_variant_wrapper_save_to_blf_thunk` | supported |
| `0x692cc` | `build_selected_map_variant_output_envelope` | supported |
| `0x6abd0` | `map_variant_wrapper_create_from_variant` | supported |
| `0x6bb20` | `map_variant_placement_init` | supported |
| `0x6bc20` | `map_variant_flags3_write_bits` | supported |
| `0x6bcec` | `map_variant_get_current` | supported |
| `0x6c290` | `reset_and_compact_variant_with_policy_sanitization` | supported |
| `0x6c754` | `map_variant_copy_header_normalized` | supported |
| `0x6cb50` | `map_variant_placements_reconcile_with_world` | supported |
| `0x6d04c` | `encode_map_variant_selected_stream` | supported |
| `0x6d468` | `decode_map_variant_selected_stream` | supported |



### forge ui

The Forge editor UI and object menus.

Showing 18 of 48 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x6e638` | `forge_placement_record_store` | supported |
| `0x70ffc` | `player_is_in_mode_1_with_special_unit` | supported |
| `0x7241c` | `forge_player_set_editor_mode` | supported |
| `0x7598c` | `player_create_replacement_unit_at_current_position` | supported |
| `0x761fc` | `forge_command_execute` | supported |
| `0x76608` | `forge_command_place_object` | supported |
| `0x771bc` | `forge_command_set_object_properties` | supported |
| `0x7753c` | `forge_player_may_edit_object` | supported |
| `0x77b54` | `forge_command_submit` | supported |
| `0x2ccd04` | `c_forge_menu_action_row__press` | supported |
| `0x2ce4a8` | `c_forge_menu_object_properties__refresh_items` | supported |
| `0x2ce924` | `forge_properties_panel_commit_changes` | supported |
| `0x2cea18` | `forge_object_properties_advanced_datasource__construct` | supported |
| `0x2cefbc` | `forge_object_properties_advanced_datasource__load_from_object` | supported |
| `0x2cf1c4` | `forge_object_properties_advanced_datasource__refresh_items` | supported |
| `0x2d0c2c` | `forge_object_properties_datasource__get_row` | supported |
| `0x2d0c44` | `forge_object_properties_datasource__get_count` | supported |
| `0x2d0c4c` | `c_forge_object_properties_datasource__destruct` | supported |


## Data structures

Runtime (from the Forge notes and direct reading of the code):

- Placement record: 76 bytes each, 651 records in the stock game, in an array based at this+0x14fc inside the map-variant structure. Byte 0 is flags (bit 0 = in use); position is at +8; the physics mode is in the top two bits of byte +0x46 (0 normal, 1 fixed, 3 phased). A free record is taken by scanning for a clear in-use bit.
- The whole map-variant structure instance is about 0xd9bc bytes; the placement array occupies 0x14fc..0xd640 (651 x 76).
- Per-player editor record: 0x12c bytes, with held item at +0x04, aimed item at +0x08, hold distance at +0x0c and aim point at +0x10.

These are runtime layouts recovered from the code, not tag-file offsets.

## Entry points and call flow

The edit loop, in order (addresses from the Forge notes):

1. Each tick the editor reads the player's buttons and makes a command.
2. The command is written to a net message and sent; the same game receives it back and dispatches it.
3. Placing: check the player may place, find a free slot in the quota, take a free record, then build the object through the general object-create path.
4. Holding: each tick find what the player aims at, move and turn the held item; letting go saves the new position into the record.
5. Copy and property changes go through one path; deleting releases the item.
6. Saving writes the map-variant header and all placement records.

## Open questions / not yet mapped

- The object-menu UI (how categories and items are presented) is only partly named.
- The full placement-record field layout beyond the fields above is not established.
- Serialization of the map variant is named at the save path but not field-by-field.
