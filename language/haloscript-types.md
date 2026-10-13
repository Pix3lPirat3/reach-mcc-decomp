# HaloScript types

The compiler knows 89 value types (ids 0 to 88). The array of type names starts with the six script types (startup, dormant, continuous, static, command_script, stub) followed by the value types, so id 0 is the first value type. A type id is a 16-bit value stored in every syntax node.

## Value types

| Id | Name | Literal parser | Stored in a global as |
|---|---|---|---|
| 0 | unparsed | not applicable (internal type) | no typed copy (not stored in a global) |
| 1 | special_form | not applicable (internal type) | no typed copy (not stored in a global) |
| 2 | function_name | not applicable (internal type) | no typed copy (not stored in a global) |
| 3 | passthrough | not applicable (internal type) | no typed copy (not stored in a global) |
| 4 | void | not applicable (internal type) | no typed copy (not stored in a global) |
| 5 | boolean | function_196d24 (boolean literal (true or false)) | boolean, 1 byte, default 0 |
| 6 | real | function_196e2c (real number literal) | real, 4 bytes, default 0.0 |
| 7 | short | function_196efc (integer literal) | short, 2 bytes, default 0 |
| 8 | long | function_196efc (integer literal) | 4 bytes, default 0 |
| 9 | string | function_197024 (string (any text)) | no typed copy (not stored in a global) |
| 10 | script | function_197044 (script name) | 16-bit handle or index, default -1 |
| 11 | string_id | function_1970e4 (string parameter) | 4 bytes, default 0 |
| 12 | unit_seat_mapping | function_197160 (seat-name substring match) | 32-bit handle, default -1 |
| 13 | trigger_volume | function_197e94 (scenario block name (trigger volume)) | 16-bit handle or index, default -1 |
| 14 | cutscene_flag | function_197ef4 (scenario block name) | 16-bit handle or index, default -1 |
| 15 | cutscene_camera_point | function_197f58 (scenario block name) | 16-bit handle or index, default -1 |
| 16 | cutscene_title | function_197fbc (scenario block name) | 16-bit handle or index, default -1 |
| 17 | cutscene_recording | function_19801c (scenario block name) | 16-bit handle or index, default -1 |
| 18 | device_group | function_19807c (device group name) | 32-bit handle, default -1 |
| 19 | ai | function_198104 (AI squad or squad group name) | 4 bytes, default 0 |
| 20 | ai_command_list | function_36930 (no parser (always rejects)) | 16-bit handle or index, default -1 |
| 21 | ai_command_script | function_1981a0 (command-script name) | 16-bit handle or index, default -1 |
| 22 | ai_behavior | function_198290 (AI behavior) | 16-bit handle or index, default -1 |
| 23 | ai_orders | function_1982c0 (AI orders (deprecated)) | 16-bit handle or index, default -1 |
| 24 | ai_line | function_1982f0 (AI line) | 32-bit handle, default -1 |
| 25 | starting_profile | function_198330 (starting profile name) | 16-bit handle or index, default -1 |
| 26 | conversation | function_36930 (no parser (always rejects)) | 16-bit handle or index, default -1 |
| 27 | player | function_198390 (player reference (player0 to player15)) | 32-bit handle, default -1 |
| 28 | zone_set | function_19857c (zone set name) | 16-bit handle or index, default -1 |
| 29 | designer_zone | function_19863c (designer zone name) | no typed copy (not stored in a global) |
| 30 | point_reference | function_198af4 (point reference) | 32-bit handle, default -1 |
| 31 | style | function_198ca4 (style name) | 32-bit handle, default -1 |
| 32 | object_list | function_198da8 (object name from the scenario) | 32-bit handle, default -1 |
| 33 | folder | function_198e38 (editor folder name) | 32-bit handle, default -1 |
| 34 | sound | function_197a28 (sound tag name) | 32-bit handle, default -1 |
| 35 | effect | function_1977b4 (tag reference by name) | 32-bit handle, default -1 |
| 36 | damage | function_1977b4 (tag reference by name) | 32-bit handle, default -1 |
| 37 | looping_sound | function_1977b4 (tag reference by name) | 32-bit handle, default -1 |
| 38 | animation_graph | function_1977b4 (tag reference by name) | 32-bit handle, default -1 |
| 39 | damage_effect | function_1977b4 (tag reference by name) | 32-bit handle, default -1 |
| 40 | object_definition | function_1977b4 (tag reference by name) | 32-bit handle, default -1 |
| 41 | bitmap | function_1977b4 (tag reference by name) | 32-bit handle, default -1 |
| 42 | shader | function_1977b4 (tag reference by name) | 32-bit handle, default -1 |
| 43 | render_model | function_1977b4 (tag reference by name) | 32-bit handle, default -1 |
| 44 | structure_definition | function_1977b4 (tag reference by name) | 32-bit handle, default -1 |
| 45 | lightmap_definition | function_1977b4 (tag reference by name) | 32-bit handle, default -1 |
| 46 | cinematic_definition | function_1977b4 (tag reference by name) | 32-bit handle, default -1 |
| 47 | cinematic_scene_definition | function_1977b4 (tag reference by name) | 32-bit handle, default -1 |
| 48 | cinematic_transition_definition | function_1977b4 (tag reference by name) | 32-bit handle, default -1 |
| 49 | bink_definition | function_1977b4 (tag reference by name) | 32-bit handle, default -1 |
| 50 | cui_screen_definition | function_1977b4 (tag reference by name) | 32-bit handle, default -1 |
| 51 | any_tag | function_1977b4 (tag reference by name) | 32-bit handle, default -1 |
| 52 | any_tag_not_resolving | function_197674 (tag path) | no typed copy (not stored in a global) |
| 53 | game_difficulty | function_197a60 (named enum value) | 32-bit handle, default -1 |
| 54 | team | function_197a60 (named enum value) | 32-bit handle, default -1 |
| 55 | mp_team | function_197a60 (named enum value) | 4 bytes, default 0 |
| 56 | controller | function_197a60 (named enum value) | 4 bytes, default 0 |
| 57 | button_preset | function_197a60 (named enum value) | 4 bytes, default 0 |
| 58 | joystick_preset | function_197a60 (named enum value) | 4 bytes, default 0 |
| 59 | player_color | function_197a60 (named enum value) | 4 bytes, default 0 |
| 60 | player_model_choice | function_197a60 (named enum value) | 4 bytes, default 0 |
| 61 | voice_output_setting | function_197a60 (named enum value) | 4 bytes, default 0 |
| 62 | voice_mask | function_197a60 (named enum value) | no typed copy (not stored in a global) |
| 63 | subtitle_setting | function_197a60 (named enum value) | 4 bytes, default 0 |
| 64 | actor_type | function_197a60 (named enum value) | 4 bytes, default 0 |
| 65 | model_state | function_197a60 (named enum value) | 32-bit handle, default -1 |
| 66 | event | function_197a60 (named enum value) | 32-bit handle, default -1 |
| 67 | character_physics | function_197a60 (named enum value) | 4 bytes, default 0 |
| 68 | skull | function_197a60 (named enum value) | 32-bit handle, default -1 |
| 69 | firing_point_evaluator | function_197a60 (named enum value) | 32-bit handle, default -1 |
| 70 | damage_region | function_197a60 (named enum value) | 32-bit handle, default -1 |
| 71 | object | function_1989f4 (typed object name) | 32-bit handle, default -1 |
| 72 | unit | function_1989f4 (typed object name) | 32-bit handle, default -1 |
| 73 | vehicle | function_1989f4 (typed object name) | 32-bit handle, default -1 |
| 74 | weapon | function_1989f4 (typed object name) | 32-bit handle, default -1 |
| 75 | device | function_1989f4 (typed object name) | 32-bit handle, default -1 |
| 76 | scenery | function_1989f4 (typed object name) | 32-bit handle, default -1 |
| 77 | effect_scenery | function_1989f4 (typed object name) | 32-bit handle, default -1 |
| 78 | object_name | function_1989e8 (typed object name) | 16-bit handle or index, default -1 |
| 79 | unit_name | function_1989e8 (typed object name) | no typed copy (not stored in a global) |
| 80 | vehicle_name | function_1989e8 (typed object name) | no typed copy (not stored in a global) |
| 81 | weapon_name | function_1989e8 (typed object name) | no typed copy (not stored in a global) |
| 82 | device_name | function_1989e8 (typed object name) | no typed copy (not stored in a global) |
| 83 | scenery_name | function_1989e8 (typed object name) | no typed copy (not stored in a global) |
| 84 | effect_scenery_name | function_1989e8 (typed object name) | no typed copy (not stored in a global) |
| 85 | cinematic_lightprobe | function_198744 (not described) | 32-bit handle, default -1 |
| 86 | animation_budget_reference | function_1974ec (not described) | 32-bit handle, default -1 |
| 87 | looping_sound_budget_reference | function_1974ec (not described) | 32-bit handle, default -1 |
| 88 | sound_budget_reference | function_1974ec (not described) | 32-bit handle, default -1 |

Types with no parser entry cannot be written as a literal. An expression of such a type is rejected with "expressions of type %s are currently unsupported".

## Type groups

- Basic: boolean (5), real (6), short (7), long (8), string (9), string_id (11).
- Script references: script (10).
- Tag references (resolved by name at compile time): ids 35 to 51 (effect through any_tag) use function_1977b4; any_tag_not_resolving (52) uses the tag path parser function_197674.
- Enumerations: ids 53 to 70 (game_difficulty through damage_region) use function_197a60. Each enum is stored as a 32-bit value.
- Object types: object (71), unit (72), vehicle (73), weapon (74), device (75), scenery (76), effect_scenery (77).
- Object name types: object_name (78) to effect_scenery_name (84), one per object type. Names are resolved against the scenario object names.
- Budget references: animation_budget_reference (86), looping_sound_budget_reference (87), sound_budget_reference (88).

## When a value fits a slot

The check function_86ad4 takes the type of the provided value (actual) and the type the slot expects (expected). It accepts the pair when any of these holds, in this order:

1. The provided type is passthrough (id 3), or the two types are equal.
2. The expected type is an object type (71 to 77). Then a provided object type (71 to 84) is accepted when its bit set is contained in the expected type's bit set (table below). A provided long (8), ai (19) or player (27) is also accepted, and is converted when the value is used.
3. The expected type is an object name type (78 to 84). Then only a provided object name type (78 to 84) is accepted, again by bit-set containment.
4. Otherwise the pair is accepted when the conversion table has an entry for it (next section).

Object type bit sets used in the containment test (the bits are the engine's object classes; their meaning is not determined here):

| Type | Bit set |
|---|---|
| object | 0xffff |
| unit | 0x1003 |
| vehicle | 0x0002 |
| weapon | 0x0004 |
| device | 0x0190 |
| scenery | 0x0040 |
| effect_scenery | 0x2000 |

The name types (78 to 84) use the same sets in the same order. In practice this means a vehicle expression fits a unit slot and a unit fits an object slot, but not the reverse; the cast forms unit, vehicle, weapon, device, scenery and effect_scenery narrow an object explicitly.

## Implicit conversions

The conversion table (function_84948 fills it at start-up; 89 by 89 pointers at data_c1b040) is indexed by expected type (row) and provided type (column). A non-null entry means the provided value is converted by that function when it is used. Diagonal entries (every type except player) and every entry in the passthrough column leave the value unchanged. Converters of the same function are grouped below.

- function_86860: value unchanged. 176 pairs: 88 identical-type pairs (every type except player) and 88 further pairs whose provided type is passthrough.
- function_d560: always 0 (the value is discarded). Pairs (expected from provided): void from boolean, void from real, void from short, void from long, void from string, void from script, void from string_id, void from unit_seat_mapping, void from trigger_volume, void from cutscene_flag, void from cutscene_camera_point, void from cutscene_title, void from cutscene_recording, void from device_group, void from ai, void from ai_command_list, void from ai_command_script, void from ai_behavior, void from ai_orders, void from ai_line and 64 more.
- function_868f0: enum value plus 1, as a real (only the low 16 bits of the enum value are used). Pairs (expected from provided): real from game_difficulty, real from team, real from mp_team, real from controller, real from button_preset, real from joystick_preset, real from player_color, real from player_model_choice, real from voice_output_setting, real from voice_mask, real from subtitle_setting, real from actor_type, real from model_state, real from event, real from character_physics, real from skull, real from firing_point_evaluator, real from damage_region.
- function_86a9c: single object handle to an object list holding it (function_192960, function_1929cc). Pairs (expected from provided): object_list from object, object_list from unit, object_list from vehicle, object_list from weapon, object_list from device, object_list from scenery, object_list from effect_scenery.
- function_86a60: object name to an object list holding that object (function_47b49c, function_192960, function_1929cc). Pairs (expected from provided): object_list from object_name, object_list from unit_name, object_list from vehicle_name, object_list from weapon_name, object_list from device_name, object_list from scenery_name, object_list from effect_scenery_name.
- function_86868: 1 when the 32-bit value is zero, otherwise 0. Pairs (expected from provided): boolean from real, boolean from long.
- function_86970: object or unit handle to the player that owns it (function_4739cc), -1 when none. Pairs (expected from provided): player from object, player from unit.
- function_869dc: player reference to that player's unit handle (function_486e8, function_489c8). Pairs (expected from provided): object from player, unit from player.
- function_8687c: 1 when the 16-bit value is zero, otherwise 0. Pairs (expected from provided): boolean from short.
- function_86890: 1 when the string is empty, otherwise 0. Pairs (expected from provided): boolean from string.
- function_868c4: signed 16-bit integer to real. Pairs (expected from provided): real from short.
- function_868dc: 32-bit integer to real. Pairs (expected from provided): real from long.
- function_86908: real truncated to a signed 16-bit integer. Pairs (expected from provided): short from real.
- function_86934: 16-bit value, upper half cleared. Pairs (expected from provided): short from long.
- function_86864: low 8 bits of the value (boolean to number). Pairs (expected from provided): long from boolean.
- function_86924: real truncated to a 32-bit integer. Pairs (expected from provided): long from real.
- function_86930: sign-extended 16-bit value. Pairs (expected from provided): long from short.
- function_86944: player index mapped through the roster (function_486e8) when the value is 7 or less. Pairs (expected from provided): player from player.
- function_6be388: AI reference to an object list of its units (function_6be174, function_6be220). Pairs (expected from provided): object_list from ai.
- function_86a10: player reference to an object list holding that player's unit (function_192960, function_1929cc). Pairs (expected from provided): object_list from player.

Observations read from the converters:

- A boolean slot given a real, short or long value receives 1 when the value is zero and 0 otherwise (functions 86868 and 8687c): numbers convert to boolean by an equals-zero test. In plain terms a nonzero number given where a boolean is expected becomes false and zero becomes true, which is the opposite of the usual meaning.
- A real slot given an enum value receives the enum value plus 1 (function_868f0).
- A short or long slot given a real truncates toward zero (functions 86908 and 86924); a real slot given a short or long converts the integer to a real (functions 868c4 and 868dc).
- A boolean slot given a string receives 1 when the string is empty (function_86890).
- A void slot accepts every value type (entry always 0); the value is dropped.
- A player value fits object and unit slots (it becomes that player's unit) and object list slots (a one-element list). player0 to player15 are the only player literals.

## Enumeration values

The named-value parser (function_197a60) reads one table per enumeration type at data_996110 (16-byte entries indexed by type id minus 53: a count, a flag byte and a pointer to the list of name strings). A script value is stored as the position of its name in the list, counting from 0. The lists below are in table order.

### game_difficulty (type id 53, 4 values)

0 easy, 1 normal, 2 heroic, 3 legendary

### team (type id 54, 8 values)

0 default, 1 player, 2 human, 3 covenant, 4 brute, 5 mule, 6 spare, 7 covenant_player

### mp_team (type id 55, 8 values)

0 mp_team_red, 1 mp_team_blue, 2 mp_team_green, 3 mp_team_yellow, 4 mp_team_purple, 5 mp_team_orange, 6 mp_team_brown, 7 mp_team_grey

### controller (type id 56, 4 values)

0 controller1, 1 controller2, 2 controller3, 3 controller4

### button_preset (type id 57, 12 values)

0 standard, 1 community, 2 boxer, 3 green_thumb, 4 professional, 5 evolved, 6 community2, 7 universal_recon, 8 universal_reclaimer, 9 universal_zoom_and_shoot, 10 universal_bumper_jumper, 11 universal_green_fingers

### joystick_preset (type id 58, 4 values)

0 standard, 1 south_paw, 2 legacy, 3 legacy_south_paw

### player_color (type id 59, 32 values)

0 player_color_00, 1 player_color_01, 2 player_color_02, 3 player_color_03, 4 player_color_04, 5 player_color_05, 6 player_color_06, 7 player_color_07, 8 player_color_08, 9 player_color_09, 10 player_color_10, 11 player_color_11, 12 player_color_12, 13 player_color_13, 14 player_color_14, 15 player_color_15, 16 player_color_16, 17 player_color_17, 18 player_color_18, 19 player_color_19, 20 player_color_20, 21 player_color_21, 22 player_color_22, 23 player_color_23, 24 player_color_24, 25 player_color_25, 26 player_color_26, 27 player_color_27, 28 player_color_28, 29 player_color_29, 30 player_color_30, 31 player_color_31

### player_model_choice (type id 60, 2 values)

0 spartan, 1 elite

### voice_output_setting (type id 61, 2 values)

0 default, 1 headset

### voice_mask (type id 62, 2 values)

0 none, 1 anonymous

### subtitle_setting (type id 63, 3 values)

0 automatic, 1 enabled, 2 disabled

### actor_type (type id 64, 17 values)

0 none, 1 player, 2 marine, 3 crew, 4 spartan, 5 elite, 6 jackal, 7 grunt, 8 brute, 9 hunter, 10 prophet, 11 bugger, 12 scarab, 13 engineer, 14 skirmisher, 15 mule, 16 mounted_weapon

### model_state (type id 65, 5 values)

0 default, 1 minor damage, 2 medium damage, 3 major damage, 4 destroyed

### event (type id 66, 6 values)

0 verbose, 1 status, 2 message, 3 warning, 4 error, 5 critical

### character_physics (type id 67, 3 values)

0 NONE, 1 player, 2 biped

### skull (type id 68, 41 values)

0 skull_iron, 1 skull_black_eye, 2 skull_tough_luck, 3 skull_catch, 4 skull_fog, 5 skull_famine, 6 skull_thunderstorm, 7 skull_tilt, 8 skull_mythic, 9 skull_assassin, 10 skull_blind, 11 skull_superman, 12 skull_birthday_party, 13 skull_daddy, 14 skull_red, 15 skull_yellow, 16 skull_blue, 17 skull_anger, 18 skull_bandanna, 19 skull_bonded_pair, 20 skull_boom, 21 skull_envy, 22 skull_eye_patch, 23 skull_feather, 24 skull_foreign, 25 skull_ghost, 26 skull_reserved26, 27 skull_jacked, 28 skull_malfunction, 29 skull_masterblaster, 30 skull_pinata, 31 skull_reserved31, 32 skull_recession, 33 skull_scarab, 34 skull_so_angry, 35 skull_sputnik, 36 skull_streaking, 37 skull_swarm, 38 skull_thats_just_wrong, 39 skull_reserved39, 40 skull_boots_off_the_ground

### firing_point_evaluator (type id 69, 58 values)

0 INVALID, 1 attack_dangerousenemy, 2 attack_idealrange, 3 attack_leader_distance, 4 attack_same_frame_of_reference, 5 attack_weaponrange, 6 combat_cue, 7 combatmove_elevation, 8 combatmove_follow_unit, 9 combatmove_lineoffire, 10 combatmove_lineoffire_occluded, 11 cover_near_friends, 12 current_position, 13 current_destination, 14 danger_zone, 15 directional_movement, 16 facing, 17 fireteam_leader, 18 flag_preferences, 19 flank, 20 flee_to_leader, 21 friendly, 22 friend_bunkering, 23 goal_points_only, 24 goal_preferences, 25 heatmap, 26 hide_equipment, 27 inertia_preservation, 28 leadership, 29 movement_planning, 30 move_into_danger_zone, 31 move_distance, 32 move_localized, 33 multi_target, 34 obstacle, 35 panic_closetotarget, 36 panic_targetdistance, 37 pathfinding, 38 perch_preferences, 39 postsearch_prefer_original, 40 previously_discarded, 41 pursuit_search_pattern, 42
  ranged_fight, 43 squad_patrol_search, 44 stalking, 45 stimulus, 46 task_direction, 47 too_far_from_leader, 48 vehicle_move_distance, 49 vehicle_pickup, 50 wall_leanable, 51 3d_path_available, 52 attack_visible, 53 attack_visible_los_optional, 54 guard_cover, 55 hide_cover, 56 uncover_visible, 57 vehicle_hide_cover

### damage_region (type id 70, 11 values)

0 gut, 1 chest, 2 head, 3 left shoulder, 4 left arm, 5 left leg, 6 left foot, 7 right shoulder, 8 right arm, 9 right leg, 10 right foot
