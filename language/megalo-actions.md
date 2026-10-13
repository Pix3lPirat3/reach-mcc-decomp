# Action opcodes

Opcode values 1 to 106 are implemented by the action dispatcher `function_f2dac`; the opcode is a 7-bit value in the action record (byte +0x10). Value 0 means no action (the record is zeroed). Values 107 to 127 decode with no arguments and the dispatcher exits without effect, but the validator (`function_544a4`) rejects every action record whose opcode is 0x6b (107) or more, so a valid variant never contains them. Each action record is 20 bytes; argument offsets below are byte offsets inside that record.

Names in the second column are labels from a matching of the handlers against another build of the same code. They are evidence level S: a static match, not proof. Six labels (operations 54, 70, 72, 78, 80 and 97) are instead the names of natives in the script table of the game data whose evaluators call the same engine function as the action. Unnamed rows have no usable match; their description comes from the code alone (V). "Writes" in an argument means the reference must be a writable variable, otherwise the write is skipped.

Reference types (PLAYER_REF, OBJECT_REF, TEAM_REF, TIMER_REF, NUM_REF, ANY_REF, MESSAGE, OPT_U11, OPT_U2, TAGGED, PROP_ASSIGN, TEAM_OR_PLAYER) are defined in [variables](megalo-variables.md) and [enums](megalo-enums.md). "M" is the script state block at G+0x16c, "G" the block at thread-local slot +0x20 (see [runtime](megalo-runtime.md)).

## Index

| op | label | name evidence | arguments (summary) | handler |
|---|---|---|---|---|
| 1 | set_score | S | value; operator; target | function_1f109c |
| 2 | create_object | S | object type; result; anchor; label; flags; offset; variant | function_1f12e0 |
| 3 | delete_object | S | object | function_1f15f4 |
| 4 | navpoint_set_visible | S | target; visibility | function_1f16a4, function_1f5bdc, function_1f1718 |
| 5 | navpoint_set_icon | S | target; icon; index | function_1f16a4, function_1f1718 |
| 6 | navpoint_set_priority | S | target; priority | function_1f16a4, function_1f1718 |
| 7 | navpoint_set_timer | S | target; timer index | function_1f16a4, function_1f1718 |
| 8 | navpoint_set_visible_range | S | target; minimum; maximum | function_1f1768 |
| 9 | set (variable operation) | S | destination; source; operator | function_1f1844 |
| 10 | set_boundary | S | target; shape; shape 1; shape 2; shape 3 | function_1f1a7c |
| 11 | apply_player_traits | S | player; trait index | inline (dispatcher block f2fbf) |
| 12 | set_pickup_filter | S | object; visibility | inline (dispatcher block f2f9a) |
| 13 | set_respawn_filter | S | object; visibility | inline (dispatcher block f2f33) |
| 14 | set_fireteam_respawn_filter | S | object; mask | inline (dispatcher block f3044) |
| 15 | set_progress_bar | S | object; visibility; second value | inline (dispatcher block f318b) |
| 16 | hud_post_message | S | message; second index; receivers | function_1f1c8c |
| 17 | timer_set_rate | S | timer; rate code | inline (dispatcher block f3160) |
| 18 | print_variable | S | message | none |
| 19 | get_player_holding_object | S | object; result | inline (dispatcher block f30f0) |
| 20 | for_each (run trigger) | S | trigger index | function_1f1ed0 |
| 21 | unnamed (round end call) | - | (none) | function_7b3ec |
| 22 | boundary_set_visible | S | object; visibility | function_1f1fa4, function_1f5bdc, function_1f2018 |
| 23 | object_set_invincibility | S | object; flag | function_1f2060 |
| 24 | unnamed (object flag) | - | object; value | inline (dispatcher block f3250) |
| 25 | random | S | maximum; result | inline (dispatcher block f3201) |
| 26 | unnamed | - | (none) | none |
| 27 | object_get_orientation | S | object; result | function_1f2128 |
| 28 | unnamed (object velocity length) | - | object; result | inline (dispatcher block f341c) |
| 29 | player_death_get_killing_player | S | player; result | inline (dispatcher block f33ce) |
| 30 | player_death_get_damage_type | S | player; result | inline (dispatcher block f3388) |
| 31 | player_death_get_special_type | S | player; result | inline (dispatcher block f3342) |
| 32 | debugging_enable_tracing | S | flag | none |
| 33 | object_attach | S | attached object; parent; offset; use parent orientation | function_1f2298 |
| 34 | unnamed (object detach call) | - | object | function_47133c |
| 35 | unnamed (player place value) | - | player; result | function_7a918 |
| 36 | unnamed (team place value) | - | team; result | function_7a960 |
| 37 | unnamed (player streak value) | - | player; result | function_10c708 |
| 38 | player_adjust_money | S | player; operator; value | inline (dispatcher block f359e) |
| 39 | player_enable_purchases | S | player; value; mask | function_1f24e0 |
| 40 | player_get_vehicle | S | player; result | function_473dc0 |
| 41 | player_set_vehicle | S | player; vehicle | function_1f2590 |
| 42 | player_set_unit | S | player; unit | function_1f266c |
| 43 | timer_reset | S | timer | inline (dispatcher block f37a7) |
| 44 | weapon_set_pickup_priority | S | weapon; priority | inline (dispatcher block f3734) |
| 45 | object_bounce | S | object | function_1f2724 |
| 46 | hud_widget_set_text | S | widget; message | inline (dispatcher block f36e5) |
| 47 | hud_widget_set_value | S | widget; message | inline (dispatcher block f36a0) |
| 48 | hud_widget_set_meter | S | widget; meter | inline (dispatcher block f3826) |
| 49 | hud_widget_set_icon | S | widget; icon | inline (dispatcher block f396e) |
| 50 | hud_widget_set_visibility | S | widget; player; visible | inline (dispatcher block f38fb) |
| 51 | play_sound | S | receivers; sound index; flag | function_1f28a0 |
| 52 | object_set_scale | S | object; scale | inline (dispatcher block f389d) |
| 53 | navpoint_set_text | S | target; message | function_1f2954 |
| 54 | object_get_shield | S | object; result | inline (dispatcher block f399e) |
| 55 | object_get_health | S | object; result | function_1f2a20 |
| 56 | player_set_objective | S | player; message | function_1f2ac8 |
| 57 | player_set_objective_allegiance | S | player; message | function_1f2b88 |
| 58 | player_set_objective_allegiance_icon | S | player; icon | inline (dispatcher block f3a4d) |
| 59 | team_set_coop_spawning | S | team; flag | function_1f2c4c |
| 60 | team_set_primary_respawn_object | S | team; object | function_1f2d18 |
| 61 | player_set_primary_respawn_object | S | player; object | function_1f2ea4 |
| 62 | player_get_fireteam_index | S | player; result | inline (dispatcher block f3b72) |
| 63 | player_set_fireteam_index | S | player; value | function_535f4 |
| 64 | object_adjust_shield | S | object; operator; value | function_1f2f70 |
| 65 | object_adjust_health | S | object; operator; value | function_1f3110 |
| 66 | object_get_distance | S | object A; object B; result | function_1f3254 |
| 67 | object_adjust_maximum_shield | S | object; operator; value | function_1f3310 |
| 68 | object_adjust_maximum_health | S | object; operator; value | function_1f3434 |
| 69 | player_set_requisition_palette | S | player; palette | inline (dispatcher block f3db2) |
| 70 | device_set_power | S | object; value | function_4d2988 (via function_14c0dc) |
| 71 | device_get_power | S | object; result | inline (dispatcher block f3cf6) |
| 72 | device_set_position | S | object; value | function_4d2910 |
| 73 | device_get_position | S | object; result | inline (dispatcher block f3c0f) |
| 74 | adjust_grenades | S | player; grenade type; operator; value | function_1f3588 |
| 75 | submit_incident | S | incident; cause; effect | function_1f36e0 |
| 76 | submit_incident_with_custom_value | S | incident; cause; effect; value | function_1f36e0 |
| 77 | set_loadout_palette | S | receivers; palette | function_1f3838 |
| 78 | device_set_position_track | S | object; track; value | function_4d3b60 |
| 79 | device_animate_position | S | object; target; NUM_REF at +6; NUM_REF at +9; NUM_REF at +0xc | function_1f38e4 |
| 80 | device_set_position_immediate | S | object; value | function_4d2b90 |
| 81 | saved_film_insert_marker | S | time; message | function_1f39d4 |
| 82 | respawn_zone_enable | S | object; value | inline (dispatcher block f40d6) |
| 83 | player_get_weapon | S | player; flag; result | function_1f3a78 |
| 84 | player_get_equipment | S | player; result | inline (dispatcher block f404e) |
| 85 | object_set_never_garbage | S | object; value | function_47c5f8 |
| 86 | player_get_target_object | S | player; result | inline (dispatcher block f3f80) |
| 87 | create_tunnel | S | type; point A; point B; width; result | function_1f3b1c |
| 88 | debug_force_player_view_count | S | value | none |
| 89 | player_pick_up_weapon | S | player; weapon | function_48dce0 |
| 90 | player_set_coop_spawning | S | player; flag | inline (dispatcher block f4182) |
| 91 | object_set_orientation | S | object; reference; copy | function_1f3d28 |
| 92 | object_face_object | S | object; target; offset | function_1f3f64 |
| 93 | biped_give_weapon | S | unit; weapon type; mode | function_1f41c4 |
| 94 | unnamed (biped weapon drop call) | - | unit; slot select; flag | function_48db90 |
| 95 | set_scenario_interpolator_state | S | index; state | function_1f4364 |
| 96 | get_random_object | S | excluded object; result; label | function_1f4454 |
| 97 | game_grief_record_custom_penalty | S | player; value | function_14fa5c |
| 98 | boundary_set_player_color | S | object; color | function_1f1fa4, function_1f2018 |
| 99 | nested trigger body | - | range | function_1f6e0c |
| 100 | start scenario script | - | script index | function_244a54, function_81be8, function_851c0 |
| 101 | unnamed (player table read) | - | player; selector; result | function_1f4584 |
| 102 | unnamed | - | team; flag | none |
| 103 | unnamed | - | player; flag | none |
| 104 | unnamed (player respawn vehicle) | - | type; player | function_533e4 |
| 105 | unnamed (team respawn vehicle) | - | type; team | function_533e4 |
| 106 | unnamed (object hidden state) | - | object; flag | function_4716dc |

## Operations

### 1. set_score

- Name evidence: S (matched to a named function in another build). Behavior evidence: V.
- Handler: function_1f109c.
- Arguments:
  - value: NUM_REF at +0
  - operator: u4 at +3
  - target: TEAM_OR_PLAYER at +4 (reference bytes +4..+6, tag u2 at +7)
- Effect: Applies the operator to a score. Does nothing unless the script gate function_7b15c passes (engine instance present, its word at G+0xd8 equal to 1, and either option byte +0x11 equal to 4 or the dword at G+0x840c equal to 1). Tag 1 (player): the new score is operator(old score, value); the difference is added with function_7b894. Tag 0 (team): the same, applied to every team slot 0..7 whose designator (function_14c39c) equals the referenced team, through function_18f974. Tag 2: the player reference is replaced by the mask of all 16 player slots and the player rule is applied to every active player. Scores are signed 16-bit words: players at score table + player*8, teams at score table + 0x80 + slot*8 (table from function_80634).

### 2. create_object

- Name evidence: S (matched to a named function in another build). Behavior evidence: V.
- Handler: function_1f12e0.
- Arguments:
  - object type: OPT_U11 dword at +0 (-1 = none)
  - result: OBJECT_REF at +4 (receives the new object)
  - anchor: OBJECT_REF at +7
  - label: byte at +0xa (bool none, else u4; 0xff = none)
  - flags: u3 at +0xb
  - offset: 24 raw bits at +0xc..+0xe
  - variant: byte at +0xf (u8 minus one, 0xff = none)
- Effect: Resolves the type with function_132ca0 and the anchor object; does nothing if the anchor or type is -1. The 24 offset bits are three signed bytes (x, y, z), each multiplied by 0.1, then rotated by the anchor orientation (function_f5f60). Position and orientation come from the anchor (function_471d38, function_471f9c). If flag bit 2 is clear the orientation is replaced by a fixed default. The rotated offset is added to the position. A variant byte other than 0xff is mapped with function_244a54 and used when the type has such a variant (function_1cbe70 returns a valid entry); otherwise the type default is used. A label other than 0xff selects a label record of the gametype (function_1461cc) whose data is applied to the new object (function_705c8). Flag bit 1 clear sets creation-descriptor bit 9, set clears it; bit 11 is always set. The object is created by function_46d6e0; if it
  exists, flag bit 0 marks the created object (byte +0x143, bit 0), the object is placed (function_1308bc, function_1f1244, function_3a645c) and, when the result reference is a writable variable, the new object is stored there with function_1f54dc.

### 3. delete_object

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: function_1f15f4.
- Arguments:
  - object: OBJECT_REF at +0
- Effect: Resolves the object. If its byte +0x8e is 1, its child chain (first child at +0x10, siblings through +0xc) is walked and every child that is a player-controlled unit (byte +0x8e is 0 and the player field +0x1cc is set) is sent action 0x15 (function_49f210, the exit action) first. The object is then deleted with function_46f0b0.

### 4. navpoint_set_visible

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: function_1f16a4, function_1f5bdc, function_1f1718.
- Arguments:
  - target: OBJECT_REF at +0
  - visibility: PROP_ASSIGN at +3
- Effect: Applies the visibility value to the navpoint record of the target. Object kinds 4..7 (player-derived) use the record at player record + 0x4c; other kinds use the script record of the object (+0xc). Marks the player (function_3d9b28 mask 0x4000000) or the object (function_3a664c mask 0x10000) as changed.

### 5. navpoint_set_icon

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: function_1f16a4, function_1f1718.
- Arguments:
  - target: OBJECT_REF at +0
  - icon: byte at +3 (u5 minus one)
  - index: NUM_REF at +4, present only when the icon code is 0xb
- Effect: Stores the icon byte in the navpoint record (+0xa). When the code is 0xb the number is read, reduced by one, limited to 0..8 and added to 0xb, so codes 0xb..0x13 are number-selected icons.

### 6. navpoint_set_priority

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: function_1f16a4, function_1f1718.
- Arguments:
  - target: OBJECT_REF at +0
  - priority: u2 at +3
- Effect: Stores the value in navpoint record byte +0x14.

### 7. navpoint_set_timer

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: function_1f16a4, function_1f1718.
- Arguments:
  - target: OBJECT_REF at +0
  - timer index: byte at +3 (bool none, else u2; 0xff = none)
- Effect: Stores the value in navpoint record byte +0x15.

### 8. navpoint_set_visible_range

- Name evidence: S (matched to a named function in another build). Behavior evidence: V.
- Handler: function_1f1768.
- Arguments:
  - target: OBJECT_REF at +0
  - minimum: NUM_REF at +3
  - maximum: NUM_REF at +6
- Effect: Stores the first number, limited to -1..100, in navpoint record byte +0x16 and the second, limited to -1..100, in +0x17.

### 9. set (variable operation)

- Name evidence: S (matched to a named function in another build). Behavior evidence: V.
- Handler: function_1f1844.
- Arguments:
  - destination: ANY_REF at +0 (tag at +3)
  - source: ANY_REF at +4 (tag at +7)
  - operator: u4 at +8
- Effect: Dispatches on the destination tag. Number: destination = operator(destination, source). Player, object, team: the source value replaces the destination variable (the operator is ignored). Timer: if the operator is 4 (assign) and the source is a timer, the 24-bit value and rate byte are copied; otherwise both sides are converted to ticks (timer value / 20, or the number times the tick rate), the operator is applied, the result is limited to 0..tick rate*0x6270 and stored back multiplied by 20; the rate byte is kept.

### 10. set_boundary

- Name evidence: S (matched to a named function in another build). Behavior evidence: V.
- Handler: function_1f1a7c.
- Arguments:
  - target: OBJECT_REF at +0
  - shape: u2 at +3
  - shape 1: NUM_REF at +4
  - shape 2: NUM_REF at +4, +0xa, +0xd
  - shape 3: NUM_REF at +4, +7, +0xa, +0xd
- Effect: Writes the boundary record (four floats and a shape byte; at player record + 0x64 for player-derived targets, otherwise the multiplayer property block from function_47b848). Numbers are multiplied by 0.1 and limited by function_1f1a4c. Shape 1: float0 = first number. Shape 2: float0 = first, float2 = second (+0xa), float3 = third (+0xd). Shape 3: float0 = first, float1 = second (+7), float2 = third (+0xa), float3 = fourth (+0xd). Shape 0 clears the values. The shape byte is stored at +0x10. If anything changed the object is marked (function_3a67a4) and the player-derived path marks the player.

### 11. apply_player_traits

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f2fbf).
- Arguments:
  - player: PLAYER_REF at +0
  - trait index: dword at +4 (u4)
- Effect: Appends the index to the player trait list (count dword at player record +0xa8, up to 16 entries from +0xb0). A full list is left unchanged; duplicates are not checked.

### 12. set_pickup_filter

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f2f9a).
- Arguments:
  - object: OBJECT_REF at +0
  - visibility: PROP_ASSIGN at +3
- Effect: Applies the value to the script object record at +0x1c (mode byte, player mask dword at +0x20) and marks the object.

### 13. set_respawn_filter

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f2f33).
- Arguments:
  - object: OBJECT_REF at +0
  - visibility: PROP_ASSIGN at +3
- Effect: Applies the value to the script object record at +0x24 (mode, mask at +0x28). Requires a valid object and, when the object has a property block (function_47b848), its byte +0x11 must not be 0xf; then marks the object.

### 14. set_fireteam_respawn_filter

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f3044).
- Arguments:
  - object: OBJECT_REF at +0
  - mask: u8 at +3
- Effect: Stores the byte in script object record +2 under the same conditions as operation 13 (valid object, property block byte +0x11 not 0xf).

### 15. set_progress_bar

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f318b).
- Arguments:
  - object: OBJECT_REF at +0
  - visibility: PROP_ASSIGN at +3
  - second value: byte at +0xa (bool none, else u2)
- Effect: Stores the byte in script object record +0x90 and applies the value to the record at +0x88 (mode, mask at +0x8c); marks the object.

### 16. hud_post_message

- Name evidence: S (matched to a named function in another build). Behavior evidence: V.
- Handler: function_1f1c8c.
- Arguments:
  - message: MESSAGE at +0 (10 bytes)
  - second index: byte at +0xa (u7 minus one, 0xff = none)
  - receivers: TEAM_OR_PLAYER at +0xb (tag at +0xe)
- Effect: Builds the set of receiving players (function_1f0fe8). For each receiver a 0x20-byte entry is built from the message words and the second index; identical entries for different receivers are merged by OR-ing their receiver masks (function_1f64b0 compares). Unless option byte +0x11 is 4, each entry is sent with function_3cce24 (type 0x11) and function_14db94. The event context field +0xdcc8 is set to the player while the message arguments are resolved.

### 17. timer_set_rate

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f3160).
- Arguments:
  - timer: TIMER_REF at +0
  - rate code: byte at +3 (u5)
- Effect: Stores the code in byte +3 of the timer cell, then marks it changed (function_1f6964). Rate codes are listed in enums.md.

### 18. print_variable

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: none.
- Arguments:
  - message: MESSAGE at +0
- Effect: Accepted and decoded; the dispatcher block jumps straight to the exit. No effect.

### 19. get_player_holding_object

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f30f0).
- Arguments:
  - object: OBJECT_REF at +0
  - result: PLAYER_REF at +3 (written)
- Effect: If the object is a weapon or equipment (type byte 2 or 3) and carried (carrier at +0x1b4), the player at carrier +0x1cc is stored in the result variable; otherwise -1 is stored.

### 20. for_each (run trigger)

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: function_1f1ed0.
- Arguments:
  - trigger index: dword at +0 (u8)
- Effect: Saves the current player, object and team (M+4, M+0, M+8), runs the trigger with the given index through function_f6de8 (all of its loop and condition rules apply), then restores them; the current object is reset to -1 if the object was removed meanwhile (flag bit 5 of the byte at +2 in the object table entry, stride 0x18; what that flag means is not determined). Nesting is not limited.

### 21. unnamed (round end call)

- Name evidence: no name. Behavior evidence: V.
- Handler: function_7b3ec.
- Arguments:
  - (none)
- Effect: Calls function_7b3ec(-1, 0, 0), the same end-of-round routine used by the script natives.

### 22. boundary_set_visible

- Name evidence: S (argument shape and behavior agree). Behavior evidence: V.
- Handler: function_1f1fa4, function_1f5bdc, function_1f2018.
- Arguments:
  - object: OBJECT_REF at +0
  - visibility: PROP_ASSIGN at +3
- Effect: Applies the value to the boundary visibility record (script object record +0x2c, or player record +0x9c for player-derived targets) and marks it.

### 23. object_set_invincibility

- Name evidence: S (argument shape and behavior agree). Behavior evidence: V/H.
- Handler: function_1f2060.
- Arguments:
  - object: OBJECT_REF at +0
  - flag: bool at +3
- Effect: Calls function_4e46dc with the object, the flag and a small descriptor (byte 2, replaced by the byte at the definition record +0xdd of the object type when that is nonzero). Read from the code (V): the call, its arguments and the descriptor selection. Hypothesis (H): that the call turns invincibility on or off; function_4e46dc builds a record from the flag bytes (bits 0x10 and 0x40) and its effect is not decoded.

### 24. unnamed (object flag)

- Name evidence: no name. Behavior evidence: V.
- Handler: inline (dispatcher block f3250).
- Arguments:
  - object: OBJECT_REF at +0
  - value: NUM_REF at +3
- Effect: Sets bit 7 of the object dword at +0x138 when the number is nonzero and clears it otherwise. The meaning of the bit is not decoded.

### 25. random

- Name evidence: S (argument shape and behavior agree). Behavior evidence: V.
- Handler: inline (dispatcher block f3201).
- Arguments:
  - maximum: NUM_REF at +0
  - result: NUM_REF at +3 (written)
- Effect: If the maximum (the full dword) is greater than 0: state = state*0x19660d + 0x3c6ef35f (32-bit, state at the block in TLS +0x658); the maximum is then reduced to its low 16 bits taken as a signed value, and the result is ((state >> 16) * maximum16) >> 16 truncated to a signed 16-bit value. For a maximum from 1 to 32767 this is a value from 0 to maximum - 1. For a larger maximum the low word is used, so it can be 0 or negative. A maximum of 0 or below does nothing.

### 26. unnamed

- Name evidence: no name. Behavior evidence: V.
- Handler: none.
- Arguments:
  - (none)
- Effect: Accepted with no arguments; the dispatcher block exits immediately. No effect.

### 27. object_get_orientation

- Name evidence: S (matched to a named function in another build). Behavior evidence: V.
- Handler: function_1f2128.
- Arguments:
  - object: OBJECT_REF at +0
  - result: NUM_REF at +3 (written)
- Effect: Reads the two stored orientation vectors (function_472060) and their cross product, takes the dot product of each with the world up and down vectors, and writes 1..6 for the largest: 1 second vector up, 2 cross product down, 3 first vector down, 4 first vector up, 5 cross product up, 6 second vector down.

### 28. unnamed (object velocity length)

- Name evidence: no name. Behavior evidence: V.
- Handler: inline (dispatcher block f341c).
- Arguments:
  - object: OBJECT_REF at +0
  - result: NUM_REF at +3 (written)
- Effect: Reads the velocity vector (function_472584), takes its length and writes trunc(length * 10 + 0.5), or 0 when length * 10 is 0.1 or less (never negative).

### 29. player_death_get_killing_player

- Name evidence: S (by class order in that build). Behavior evidence: V.
- Handler: inline (dispatcher block f33ce).
- Arguments:
  - player: PLAYER_REF at +0
  - result: PLAYER_REF at +3 (written)
- Effect: Looks up the death record of the player (function_14d688 on the script state block M at G+0x16c) and stores the dword at record +4 (a player index) in the result variable. Nothing is written when no record exists.

### 30. player_death_get_damage_type

- Name evidence: S (by class order in that build). Behavior evidence: V.
- Handler: inline (dispatcher block f3388).
- Arguments:
  - player: PLAYER_REF at +0
  - result: NUM_REF at +3 (written)
- Effect: Writes byte +8 of the death record.

### 31. player_death_get_special_type

- Name evidence: S (by class order in that build). Behavior evidence: V.
- Handler: inline (dispatcher block f3342).
- Arguments:
  - player: PLAYER_REF at +0
  - result: NUM_REF at +3 (written)
- Effect: Writes byte +9 of the death record.

### 32. debugging_enable_tracing

- Name evidence: S (by class order in that build). Behavior evidence: V.
- Handler: none.
- Arguments:
  - flag: bool at +0
- Effect: Accepted and decoded; the dispatcher block exits at once. No effect.

### 33. object_attach

- Name evidence: S (matched to a named function in another build). Behavior evidence: V.
- Handler: function_1f2298.
- Arguments:
  - attached object: OBJECT_REF at +0
  - parent: OBJECT_REF at +3
  - offset: 24 raw bits at +6
  - use parent orientation: bool at +9
- Effect: Does nothing if either object is -1, they are the same, or the attached object already has a parent (+0x14). A unit riding a vehicle is first released (function_48f0fc). The 24 offset bits are three signed bytes (x, y, z) multiplied by 0.1; they are rotated (function_f5f60) with the parent orientation (flag set) or a default orientation (flag clear) and added to the parent position. The parent model nodes (count from +0x178, 0x34 bytes each, entries from +0x17a) are searched for the node closest to that point; the object is moved there (function_46cb38) and attached to that node (function_470f1c).

### 34. unnamed (object detach call)

- Name evidence: no name. Behavior evidence: V.
- Handler: function_47133c.
- Arguments:
  - object: OBJECT_REF at +0
- Effect: Calls function_47133c with the object.

### 35. unnamed (player place value)

- Name evidence: no name. Behavior evidence: V.
- Handler: function_7a918.
- Arguments:
  - player: PLAYER_REF at +0
  - result: NUM_REF at +3 (written)
- Effect: Writes function_7a918(player) plus 1.

### 36. unnamed (team place value)

- Name evidence: no name. Behavior evidence: V.
- Handler: function_7a960.
- Arguments:
  - team: TEAM_REF at +0
  - result: NUM_REF at +3 (written)
- Effect: Writes function_7a960(function_37d44(team)) plus 1. Operations 35 and 36 use two byte-identical routines.

### 37. unnamed (player streak value)

- Name evidence: no name. Behavior evidence: V.
- Handler: function_10c708.
- Arguments:
  - player: PLAYER_REF at +0
  - result: NUM_REF at +3 (written)
- Effect: Writes function_10c708(player).

### 38. player_adjust_money

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f359e).
- Arguments:
  - player: PLAYER_REF at +0
  - operator: u4 at +3
  - value: NUM_REF at +4
- Effect: Applies the operator to the player datum dword at +0x3b4 (number scope 9) and passes the difference to function_225960.

### 39. player_enable_purchases

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: function_1f24e0.
- Arguments:
  - player: PLAYER_REF at +0
  - value: NUM_REF at +3
  - mask: u5 at +6
- Effect: Sets the bits of the mask in player record byte +0x76 (G+0x36a) when the number is nonzero, clears them otherwise (five bits are kept); marks the player.

### 40. player_get_vehicle

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: function_473dc0.
- Arguments:
  - player: PLAYER_REF at +0
  - result: OBJECT_REF at +3 (written)
- Effect: If the unit of the player has a parent and a seat index, the vehicle is taken with function_473dc0; only an object of type 1 is accepted, otherwise -1 is stored.

### 41. player_set_vehicle

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: function_1f2590.
- Arguments:
  - player: PLAYER_REF at +0
  - vehicle: OBJECT_REF at +3
- Effect: A vehicle (type byte 1): function_4a414(player, object). No object: the unit of the player is sent action 0x15 (function_49f24c), which exits the vehicle.

### 42. player_set_unit

- Name evidence: S (matched to a named function in another build). Behavior evidence: V.
- Handler: function_1f266c.
- Arguments:
  - player: PLAYER_REF at +0
  - unit: OBJECT_REF at +3
- Effect: Requires a biped (type byte 0) not controlled by a player (+0x1cc = -1) and the current unit of the player, if any, to be a biped; then function_45814(player, object) and function_49920(player).

### 43. timer_reset

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f37a7).
- Arguments:
  - timer: TIMER_REF at +0
- Effect: Sets the timer to its declared initial value (function_1f6838, limited to 0..tick rate*0x6270, stored times 20) and the rate byte to 0; marks it changed.

### 44. weapon_set_pickup_priority

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f3734).
- Arguments:
  - weapon: OBJECT_REF at +0
  - priority: u2 at +3
- Effect: Requires a weapon (type byte 2); stores the value in script object record +3 and marks the object.

### 45. object_bounce

- Name evidence: S (matched to a named function in another build). Behavior evidence: V/H.
- Handler: function_1f2724.
- Arguments:
  - object: OBJECT_REF at +0
- Effect: Takes a pseudo-random direction from a table of 0x402 vectors (same generator as operation 25), scales it by a random factor and applies it as an impulse (function_46ce68, function_46cf24). Read from the code (V): the 0x402 vector table, the random scale and the two calls. Hypothesis (H): that the result is a bounce; what function_46ce68 and function_46cf24 do is not decoded.

### 46. hud_widget_set_text

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f36e5).
- Arguments:
  - widget: OPT_U2 dword at +0
  - message: MESSAGE at +4
- Effect: Copies the message (8 bytes at widget +0x4, string word) into the widget record G+0x25c + widget*0x28 and marks the widget (function_3a5be8, bit widget+0xe). The widget index is not tested for none (-1). With -1 the record address lies 0x28 bytes before widget 0, so the handler accesses G+0x234 (8 bytes) and G+0x23c (2 bytes) (address arithmetic read from the code, V). That area holds the last global timer, the global player variables and the temporary frame pointer at G+0x244; what the access breaks is not determined (H).

### 47. hud_widget_set_value

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f36a0).
- Arguments:
  - widget: OPT_U2 dword at +0
  - message: MESSAGE at +4
- Effect: Same, into the second message slot of the widget record (G+0x266 + widget*0x28). The widget index is not tested for none (-1). With -1 the record address lies 0x28 bytes before widget 0, so the handler accesses G+0x23e (8 bytes) and G+0x246 (2 bytes) (address arithmetic read from the code, V). That area holds the last global timer, the global player variables and the temporary frame pointer at G+0x244; what the access breaks is not determined (H).

### 48. hud_widget_set_meter

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f3826).
- Arguments:
  - widget: OPT_U2 dword at +0
  - meter: TAGGED at +4 (7 bytes)
- Effect: Copies the 7 bytes into the widget record (G+0x270 + widget*0x28): dword, word, byte. The widget index is not tested for none (-1). With -1 the record address lies 0x28 bytes before widget 0, so the handler accesses G+0x248 (4 bytes), G+0x24c (2 bytes) and G+0x24e (1 byte) (address arithmetic read from the code, V). That area holds the last global timer, the global player variables and the temporary frame pointer at G+0x244; what the access breaks is not determined (H).

### 49. hud_widget_set_icon

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f396e).
- Arguments:
  - widget: OPT_U2 dword at +0
  - icon: dword at +4 (bool none = -1, else u6)
- Effect: Stores the dword in the widget record (G+0x278 + widget*0x28). The widget index is not tested for none (-1). With -1 the record address lies 0x28 bytes before widget 0, so the handler accesses G+0x250 (4 bytes) (address arithmetic read from the code, V). That area holds the last global timer, the global player variables and the temporary frame pointer at G+0x244; what the access breaks is not determined (H).

### 50. hud_widget_set_visibility

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f38fb).
- Arguments:
  - widget: OPT_U2 dword at +0
  - player: PLAYER_REF at +4
  - visible: bool at +7
- Effect: Sets or clears the bit of the player in the widget player mask (G+0x258 + widget*0x28). The widget index is not tested for none (-1). With -1 the record address lies 0x28 bytes before widget 0, so the handler accesses G+0x230 (the dword is read and one bit is set or cleared) (address arithmetic read from the code, V). That area holds the last global timer, the global player variables and the temporary frame pointer at G+0x244; what the access breaks is not determined (H).

### 51. play_sound

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: function_1f28a0.
- Arguments:
  - receivers: TEAM_OR_PLAYER at +0 (tag at +3)
  - sound index: byte at +4 (u7 minus one)
  - flag: bool at +5
- Effect: Builds the receiving player set (function_1f0fe8) and, unless option byte +0x11 is 4, sends a type 0x11 message carrying the index and the flag (function_3cce24, function_14db94).

### 52. object_set_scale

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f389d).
- Arguments:
  - object: OBJECT_REF at +0
  - scale: NUM_REF at +3
- Effect: Divides the number by 100, limits it at 0 and calls function_46cc34(object, scale); marks the object.

### 53. navpoint_set_text

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: function_1f2954.
- Arguments:
  - target: OBJECT_REF at +0
  - message: MESSAGE at +4
- Effect: Copies the message (8 bytes and the string word) into the navpoint record (+0, +8) and marks it.

### 54. object_get_shield

- Name evidence: S (name of a native in the script table of the game data; its evaluator calls the same engine function). Behavior evidence: V.
- Handler: inline (dispatcher block f399e).
- Arguments:
  - object: OBJECT_REF at +0
  - result: NUM_REF at +3 (written)
- Effect: Reads the shield vitality (function_49dcec), limits it to 0..4, multiplies by 100 and writes the truncated value (100 is a full shield). The label is the name of a native in the script table of the game data: object_get_shield (evaluator function_19b098 also calls function_49dcec).

### 55. object_get_health

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: function_1f2a20.
- Arguments:
  - object: OBJECT_REF at +0
  - result: NUM_REF at +3 (written)
- Effect: Reads the health vitality (function_49dbec), limits it to 0..1 (the lower limit is 0.01 unless bit 2 of the object dword +0x138 is set, then 0), multiplies by 100 and writes the truncated value.

### 56. player_set_objective

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: function_1f2ac8.
- Arguments:
  - player: PLAYER_REF at +0
  - message: MESSAGE at +4
- Effect: If the message differs from the stored one (function_1f5ee8 compares string word and both argument slots), stores it at player record +0x78, copies the current time word (TLS block +0xa0 field +0xc) to +0x94 and marks the player (mask 0x8000000).

### 57. player_set_objective_allegiance

- Name evidence: S (matched to a named function in another build). Behavior evidence: V.
- Handler: function_1f2b88.
- Arguments:
  - player: PLAYER_REF at +0
  - message: MESSAGE at +4
- Effect: Same as operation 56 with the second message slot at player record +0x88.

### 58. player_set_objective_allegiance_icon

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f3a4d).
- Arguments:
  - player: PLAYER_REF at +0
  - icon: dword at +4 (bool none = -1, else u7)
- Effect: Stores the dword at player record +0x84 when it changed, updates the time word at +0x94 and marks the player (mask 0x8000000).

### 59. team_set_coop_spawning

- Name evidence: S (matched to a named function in another build). Behavior evidence: V.
- Handler: function_1f2c4c.
- Arguments:
  - team: TEAM_REF at +0
  - flag: bool at +3
- Effect: Stores the byte at player record +0x98 for every player whose team equals the team, marks those players (mask 0x10000000) and the team (function_3db328).

### 60. team_set_primary_respawn_object

- Name evidence: S (matched to a named function in another build). Behavior evidence: V.
- Handler: function_1f2d18.
- Arguments:
  - team: TEAM_REF at +0
  - object: OBJECT_REF at +3
- Effect: Reads the visibility record of the script object (+0x24, mode byte) and the team designator of the object (function_14c138). The action proceeds only when the record mode accepts the relation between the referenced team and the object team: mode 1 always, mode 2 when both teams are real and equal, mode 3 when they differ (or either is none), modes 0, 4 and 5 never. For every player whose team equals the referenced team, and whose fireteam bit (player datum +0x48c) is set in the record mask byte +2 (a fireteam of -1 or an object of -1 skips the mask test), it calls function_53360(player, object).

### 61. player_set_primary_respawn_object

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: function_1f2ea4.
- Arguments:
  - player: PLAYER_REF at +0
  - object: OBJECT_REF at +3
- Effect: With an object of -1 it calls function_53360(player, -1). Otherwise, if the script object record exists, function_1f5a94(record + 0x24, player, team of the object) accepts the player (see PROP_ASSIGN in the reference encodings) and the fireteam bit of the player is set in record byte +2 (or the fireteam is -1), it calls function_53360(player, object).

### 62. player_get_fireteam_index

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f3b72).
- Arguments:
  - player: PLAYER_REF at +0
  - result: NUM_REF at +3 (written)
- Effect: Writes the player datum dword at +0x48c.

### 63. player_set_fireteam_index

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: function_535f4.
- Arguments:
  - player: PLAYER_REF at +0
  - value: NUM_REF at +3
- Effect: Calls function_535f4(player, value) when the player exists and the value is at most 16.

### 64. object_adjust_shield

- Name evidence: S (matched to a named function in another build). Behavior evidence: V/H.
- Handler: function_1f2f70.
- Arguments:
  - object: OBJECT_REF at +0
  - operator: u4 at +3
  - value: NUM_REF at +4
- Effect: Reads the number, divides it by 100, reads the shield (function_49dcec) and applies the operator (0 add, 1 subtract, 2 multiply, 3 divide when the divisor is above a minimum, 4 assign). The result is limited between 0 and 4 and stored with function_49e2fc. Objects with dword +0x138 bit 2 set are not changed. A reduction can trigger function_49e79c / function_47bc4c; a result of exactly zero fires function_4e41cc, other changes with bit 3 of +0x138 fire function_4e42f0. Read from the code (V): the operator rules, the clamp, the flag tests and when each function is called. Hypothesis (H): what function_49e79c, function_47bc4c, function_4e41cc and function_4e42f0 do is not decoded.

### 65. object_adjust_health

- Name evidence: S (matched to a named function in another build). Behavior evidence: V/H.
- Handler: function_1f3110.
- Arguments:
  - object: OBJECT_REF at +0
  - operator: u4 at +3
  - value: NUM_REF at +4
- Effect: Same as operation 64 for health (function_49dbec read, function_49dc4c write), limited to 0..1. A result of exactly zero calls function_4e46dc with a small descriptor (word 2). Read from the code (V): the operator rules, the clamp and when function_4e46dc is called. Hypothesis (H): what that call does is not decoded.

### 66. object_get_distance

- Name evidence: S (matched to a named function in another build). Behavior evidence: V.
- Handler: function_1f3254.
- Arguments:
  - object A: OBJECT_REF at +0
  - object B: OBJECT_REF at +3
  - result: NUM_REF at +6 (written)
- Effect: Writes trunc(distance * 10 + 0.5), the distance between the positions (function_471e90 returns each position); if either object is -1 the value 0 is written.

### 67. object_adjust_maximum_shield

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: function_1f3310.
- Arguments:
  - object: OBJECT_REF at +0
  - operator: u4 at +3
  - value: NUM_REF at +4
- Effect: Applies the operator to the float at object +0x110 (a multiplier of the shield maximum), keeps it at 0 or above, rounds it (function_91a13e), writes it back and rescales the current shield (function_49e2fc). Not applied when +0x138 bit 2 is set. The operand is converted from an integer to a float and used as it is; unlike operations 64 and 65 it is not divided by 100. Operator codes: 0 add, 1 subtract, 2 multiply, 3 divide (only when the divisor is above a small constant), 4 assign.

### 68. object_adjust_maximum_health

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: function_1f3434.
- Arguments:
  - object: OBJECT_REF at +0
  - operator: u4 at +3
  - value: NUM_REF at +4
- Effect: Same as operation 67 for the float at object +0x10c and health; a result of exactly zero calls function_49ec08. The operand is used as it is, not divided by 100, as in operation 67.

### 69. player_set_requisition_palette

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f3db2).
- Arguments:
  - player: PLAYER_REF at +0
  - palette: u4 at +3
- Effect: Stores the value in player record byte +0x77, or 0 when it is 13 or more.

### 70. device_set_power

- Name evidence: S (name of a native in the script table of the game data; its evaluator calls the same engine function). Behavior evidence: V.
- Handler: function_4d2988 (via function_14c0dc).
- Arguments:
  - object: OBJECT_REF at +0
  - value: NUM_REF at +3
- Effect: Converts the object to a device index (function_14c0dc, -1 if it is not a device), divides the number by 100, limits it between 0 and 1 and calls function_4d2988. The label is the name of a native in the script table of the game data: device_set_power (evaluator function_1a0094 also calls function_4d2988).

### 71. device_get_power

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f3cf6).
- Arguments:
  - object: OBJECT_REF at +0
  - result: NUM_REF at +3 (written)
- Effect: Writes the float at device +0x1b0 scaled by a constant, limited, truncated.

### 72. device_set_position

- Name evidence: S (name of a native in the script table of the game data; its evaluator calls the same engine function). Behavior evidence: V.
- Handler: function_4d2910.
- Arguments:
  - object: OBJECT_REF at +0
  - value: NUM_REF at +3
- Effect: Same as operation 70 with function_4d2910. The label is the name of a native in the script table of the game data: device_set_position (evaluator function_1a0200 also calls function_4d2910).

### 73. device_get_position

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f3c0f).
- Arguments:
  - object: OBJECT_REF at +0
  - result: NUM_REF at +3 (written)
- Effect: Writes the float at device +0x1c0 scaled by a constant, limited, truncated.

### 74. adjust_grenades

- Name evidence: S (matched to a named function in another build). Behavior evidence: V.
- Handler: function_1f3588.
- Arguments:
  - player: PLAYER_REF at +0
  - grenade type: u1 at +3
  - operator: u4 at +4
  - value: NUM_REF at +5
- Effect: Reads the byte at unit + 0x37e + type, applies the operator with the number, limits the result to 0..4 and stores it when it changed (function_494640 follows).

### 75. submit_incident

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V/H.
- Handler: function_1f36e0.
- Arguments:
  - incident: dword at +0 (u10 minus one)
  - cause: TEAM_OR_PLAYER at +4
  - effect: TEAM_OR_PLAYER at +8
- Effect: Resolves both sides to player and team numbers (function_10ac14, function_489c8, function_37d44), then builds an incident record (type = incident, value 0) and submits it to function_10a998 / function_1099cc through an iterator (function_1f7da4, function_1f7e60); values outside a valid range are skipped. Read from the code (V): the player and team lookups, the record fields and the iterator calls. Hypothesis (H): the meaning of the incident type, the valid range and what function_10a998 and function_1099cc do with the record are not decoded.

### 76. submit_incident_with_custom_value

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: function_1f36e0.
- Arguments:
  - incident: dword at +0
  - cause: TEAM_OR_PLAYER at +4
  - effect: TEAM_OR_PLAYER at +8
  - value: NUM_REF at +0xc
- Effect: Same as operation 75, with the number stored in the record (16 bits; zero if outside -0x8000..0x7fff).

### 77. set_loadout_palette

- Name evidence: S (matched to a named function in another build). Behavior evidence: V.
- Handler: function_1f3838.
- Arguments:
  - receivers: TEAM_OR_PLAYER at +0 (tag at +3)
  - palette: byte at +4 (u3 minus one)
- Effect: Calls function_103e6c(player, palette) for the player, or for every player of the team (followed by function_103cc0).

### 78. device_set_position_track

- Name evidence: S (name of a native in the script table of the game data; its evaluator calls the same engine function). Behavior evidence: V.
- Handler: function_4d3b60.
- Arguments:
  - object: OBJECT_REF at +0
  - track: dword at +4 (u8 minus one)
  - value: NUM_REF at +8
- Effect: Maps the track index with function_244a54 and calls function_4d3b60(device, track, value as float). The label is the name of a native in the script table of the game data: device_set_position_track (evaluator function_1a06b4 also calls function_4d3b60).

### 79. device_animate_position

- Name evidence: S (matched to a named function in another build). Behavior evidence: V/H.
- Handler: function_1f38e4.
- Arguments:
  - object: OBJECT_REF at +0
  - target: NUM_REF at +3
  - NUM_REF at +6
  - NUM_REF at +9
  - NUM_REF at +0xc
- Effect: Converts the object to a device, divides the first number by a constant (limited at 0 and by a maximum) and calls function_4d432c with it and the other three numbers as floats. Their meaning is not decoded. Read from the code (V): the conversion to a device, the division and the call with four floats. Hypothesis (H): that the call animates a device position; the meaning of the other three numbers is not decoded.

### 80. device_set_position_immediate

- Name evidence: S (name of a native in the script table of the game data; its evaluator calls the same engine function). Behavior evidence: V.
- Handler: function_4d2b90.
- Arguments:
  - object: OBJECT_REF at +0
  - value: NUM_REF at +3
- Effect: Same as operation 70 with function_4d2b90. The label is the name of a native in the script table of the game data: device_set_position_immediate (evaluator function_1a02e0 also calls function_4d2b90).

### 81. saved_film_insert_marker

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: function_1f39d4.
- Arguments:
  - time: NUM_REF at +0
  - message: MESSAGE at +4
- Effect: Formats the message to a 0x100 byte string (function_1f5f38, function_689518) and calls function_5bb00(string, number * tick rate).

### 82. respawn_zone_enable

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f40d6).
- Arguments:
  - object: OBJECT_REF at +0
  - value: NUM_REF at +3
- Effect: Sets or clears bit 14 (0x4000) of the word at property block +0x12 according to the number, when the bit differs, and marks the object (function_3a67a4).

### 83. player_get_weapon

- Name evidence: S (matched to a named function in another build). Behavior evidence: V.
- Handler: function_1f3a78.
- Arguments:
  - player: PLAYER_REF at +0
  - flag: bool at +3
  - result: OBJECT_REF at +4 (written)
- Effect: Flag set: the weapon in the slot stored in unit byte +0x34a (function_48b3d0). Flag clear: function_48b518(unit). The result is stored with function_1f54dc; -1 when there is no unit.

### 84. player_get_equipment

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f404e).
- Arguments:
  - player: PLAYER_REF at +0
  - result: OBJECT_REF at +3 (written)
- Effect: Stores the dword at unit +0x374.

### 85. object_set_never_garbage

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V/H.
- Handler: function_47c5f8.
- Arguments:
  - object: OBJECT_REF at +0
  - value: NUM_REF at +3
- Effect: Only for object kinds 0..3 (not player-derived kinds): function_47c5f8(object, number != 0). Read from the code (V): the kind check and the call with the flag. Hypothesis (H): what function_47c5f8 does with the flag is not decoded.

### 86. player_get_target_object

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f3f80).
- Arguments:
  - player: PLAYER_REF at +0
  - result: OBJECT_REF at +3 (written)
- Effect: Uses the target record in the unit block at +0x2bb (aligned): when function_106f04 accepts it, its type byte is 1 and flag bit 2 at +0x24 is set, the target object at +8 is stored if it exists (function_4739cc), otherwise -1.

### 87. create_tunnel

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V/H.
- Handler: function_1f3b1c.
- Arguments:
  - type: OPT_U11 dword at +0
  - point A: OBJECT_REF at +4
  - point B: OBJECT_REF at +7
  - width: NUM_REF at +0xa
  - result: OBJECT_REF at +0xd (written)
- Effect: Creates an object of the type (function_46d6e0) at the midpoint of A and B, oriented along the line (function_1e1b4, function_186b4), with the scale vector set from the distance and the width (number / constant); marks it, and stores it in the result variable. Read from the code (V): the midpoint, orientation and scale arithmetic and the creation call. Hypothesis (H): what the created object is used for and how the scale vector is used is not decoded.

### 88. debug_force_player_view_count

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: none.
- Arguments:
  - value: NUM_REF at +0
- Effect: Accepted and decoded; the dispatcher block exits at once. No effect.

### 89. player_pick_up_weapon

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: function_48dce0.
- Arguments:
  - player: PLAYER_REF at +0
  - weapon: OBJECT_REF at +3
- Effect: Requires a weapon (type byte 2): function_48dce0(unit, weapon, 1).

### 90. player_set_coop_spawning

- Name evidence: S (by position in that build, argument shape agrees). Behavior evidence: V.
- Handler: inline (dispatcher block f4182).
- Arguments:
  - player: PLAYER_REF at +0
  - flag: bool at +3
- Effect: Stores the byte at player record +0x98 and marks the player (mask 0x10000000).

### 91. object_set_orientation

- Name evidence: S (matched to a named function in another build). Behavior evidence: V/H.
- Handler: function_1f3d28.
- Arguments:
  - object: OBJECT_REF at +0
  - reference: OBJECT_REF at +3
  - copy: bool at +6
- Effect: Does nothing if either object is -1 or the object already has a parent (+0x14). Copy set: the object receives the orientation vectors of the reference. Copy clear: the vectors of both objects are composed (cross products and dot products) and applied; the step is skipped when the vectors already agree within a small threshold. The result is applied with function_46cb38. Read from the code (V): the conditions and the vector arithmetic. Hypothesis (H): the geometric meaning of the composed result; what function_46cb38 does is not decoded.

### 92. object_face_object

- Name evidence: S (matched to a named function in another build). Behavior evidence: V/H.
- Handler: function_1f3f64.
- Arguments:
  - object: OBJECT_REF at +0
  - target: OBJECT_REF at +3
  - offset: 24 raw bits at +6
- Effect: Does nothing if either object is -1 or the object has a parent. Computes the direction to the target (with the expanded offset, function_f5f60), normalizes it (function_1fcfc) and sets the orientation (function_46cb38). Read from the code (V): the conditions, the direction computation and the calls. Hypothesis (H): the geometric meaning of the result; what function_46cb38 does is not decoded.

### 93. biped_give_weapon

- Name evidence: S (matched to a named function in another build). Behavior evidence: V.
- Handler: function_1f41c4.
- Arguments:
  - unit: OBJECT_REF at +0
  - weapon type: OPT_U11 dword at +4
  - mode: u2 at +8
- Effect: Requires a biped (type byte 0). Skips the action if the unit already holds a weapon of that type in its current or second slot. Otherwise the weapon is created (function_46d6e0) and given with function_48dce0(unit, weapon, m) with m = 3 for mode 0, 0 for mode 1, 1 for mode 2 and 0 for mode 3; if giving fails the weapon is deleted.

### 94. unnamed (biped weapon drop call)

- Name evidence: no name. Behavior evidence: V.
- Handler: function_48db90.
- Arguments:
  - unit: OBJECT_REF at +0
  - slot select: bool at +3
  - flag: bool at +4
- Effect: Requires a biped. Selects the weapon (slot select set: slot in unit byte +0x34a, function_48b3d0; clear: function_48b518) and calls function_48db90(unit, weapon, flag != 0).

### 95. set_scenario_interpolator_state

- Name evidence: S (matched to a named function in another build). Behavior evidence: V/H.
- Handler: function_1f4364.
- Arguments:
  - index: NUM_REF at +0
  - state: NUM_REF at +3
- Effect: The index minus one must be 0..31. The state is compared with the current one (function_1660c8 for entry 0x2a6 + index; with a stored limit test against function_5c3d8); when it differs function_165c64 (on) or function_165cd4 (off) is called. Read from the code (V): the index range (index minus one from 0 to 31), the comparison and the two calls. Hypothesis (H): that the entry is an interpolator state and what function_165c64 and function_165cd4 do are not decoded.

### 96. get_random_object

- Name evidence: S (matched to a named function in another build). Behavior evidence: V.
- Handler: function_1f4454.
- Arguments:
  - excluded object: OBJECT_REF at +0
  - result: OBJECT_REF at +3 (written)
  - label: byte at +6 (bool none, else u4)
- Effect: Walks the list of script objects that carry the label (list heads at M+0x13a0, i.e. G+0x150c + label*4; links in the per-object script block found through the word at +0x192 of the object block), counts those other than the excluded object, picks one with the generator of operation 25 and stores it in the result; -1 if there is none.

### 97. game_grief_record_custom_penalty

- Name evidence: S (name of a native in the script table of the game data; its evaluator calls the same engine function). Behavior evidence: V.
- Handler: function_14fa5c.
- Arguments:
  - player: PLAYER_REF at +0
  - value: NUM_REF at +3
- Effect: Calls function_14fa5c(player, number / 100 as a float). The label is the name of a native in the script table of the game data: game_grief_record_custom_penalty (evaluator function_1b8d34 also calls function_14fa5c).

### 98. boundary_set_player_color

- Name evidence: S (argument shape and behavior agree). Behavior evidence: V.
- Handler: function_1f1fa4, function_1f2018.
- Arguments:
  - object: OBJECT_REF at +0
  - color: byte at +3 (bool none = 0xff, else u2)
- Effect: Stores the byte at +8 of the boundary visibility record and marks it.

### 99. nested trigger body

- Name evidence: no name. Behavior evidence: V.
- Handler: function_1f6e0c.
- Arguments:
  - range: TRIGGER_RANGE at +0 (condition start u9, condition count u10, action start u10, action count u11, words at +0, +2, +4, +6)
- Effect: Runs the inline range of conditions and actions with the same rules as a trigger body (function_1f6e0c), using the current player, object and team.

### 100. start scenario script

- Name evidence: no name. Behavior evidence: V.
- Handler: function_244a54, function_81be8, function_851c0.
- Arguments:
  - script index: dword at +0 (u7 minus one)
- Effect: Maps the index with function_244a54, finds the HaloScript function with that index (function_81be8) and runs it (function_851c0) while a script-context pair at globals 0xed58d6/0xed58a6 is set to the engine thread; the script cannot take arguments.

### 101. unnamed (player table read)

- Name evidence: no name. Behavior evidence: V/U.
- Handler: function_1f4584.
- Arguments:
  - player: PLAYER_REF at +0
  - selector: u5 at +3
  - result: NUM_REF at +4 (written)
- Effect: Picks one of thirteen per-player tables with the selector (0..12; other values use the first table), indexes it with the slot value of the player datum (+0x20), uses the dword found there as an index into a second table and writes one byte of that entry to the result (zero when the entry flag at +0x9a7 bit 0 is set or the entry value does not match). The meaning of the value is not decoded. Read from the code (V): the table selection, the indexing and the written byte. Not decoded (U): the meaning of the value.

### 102. unnamed

- Name evidence: no name. Behavior evidence: V.
- Handler: none.
- Arguments:
  - team: TEAM_REF at +0
  - flag: bool at +3
- Effect: Accepted and decoded; the dispatcher block exits at once. No effect.

### 103. unnamed

- Name evidence: no name. Behavior evidence: V.
- Handler: none.
- Arguments:
  - player: PLAYER_REF at +0
  - flag: bool at +3
- Effect: Accepted and decoded; the dispatcher block exits at once. No effect.

### 104. unnamed (player respawn vehicle)

- Name evidence: no name. Behavior evidence: V.
- Handler: function_533e4.
- Arguments:
  - type: OPT_U11 dword at +0
  - player: PLAYER_REF at +4
- Effect: Calls function_533e4(player, type).

### 105. unnamed (team respawn vehicle)

- Name evidence: no name. Behavior evidence: V.
- Handler: function_533e4.
- Arguments:
  - type: OPT_U11 dword at +0
  - team: TEAM_REF at +4
- Effect: Calls function_533e4(player, type) for every player whose team equals the referenced team.

### 106. unnamed (object hidden state)

- Name evidence: no name. Behavior evidence: V.
- Handler: function_4716dc.
- Arguments:
  - object: OBJECT_REF at +0
  - flag: bool at +3
- Effect: Calls function_4716dc(object, flag). The flag byte is loaded from record byte +3 in the dispatcher block (f445e) just before the call and is passed as the second argument.
