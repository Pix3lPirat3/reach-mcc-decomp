# Properties a gametype can read and write

This page lists, by entity, every property reachable from the language (V). Numbers in parentheses are action opcodes or condition types; "scope n" is a number scope code ([variables](megalo-variables.md)).

## Game

| property | read | write |
|---|---|---|
| word at G+0xda | scope 13 | no |
| gametype option value | scope 5 (`function_ddeb8`) | no |
| base variant fields | scopes 18 to 42 ([variant format](megalo-variant-format.md)) | no |
| engine virtual values | scopes 14, 15, 16, 17 | scope 15 (a flag at M+0xc) |
| event byte M+0x1c | scope 43 | no |
| global variables | scope 4, global codes of the four reference types | yes |
| temporaries | scope 44 and temporary codes | yes |
| round end | | operation 21 |
| game is Forge | condition 17 | |
| random number | | random (25) |
| saved film marker | | (81) |
| HaloScript function | | start scenario script (100) |
| scenario interpolator | | (95) |
| incidents | | (75), (76) |

## Players

| property | read | write |
|---|---|---|
| player variables (numbers, timers, teams, players, objects) | scope 1, TIMER_REF 1, TEAM_REF 1, PLAYER_REF 1, OBJECT_REF 1 | same references as targets |
| score | scope 8 | (1), scope 8 |
| computed value | scope 10 | no |
| statistics | scope 11 | scope 11 |
| datum dword +0x3b4 | scope 9 | (38), scope 9 |
| unit | OBJECT_REF kind 4 | (42) |
| vehicle | (40) | (41) |
| held weapon, equipment, target | (83), (84), (86) | (89) pick up, (94) drop, (93) give |
| place, killing spree | (35), (37) | no |
| fireteam index | (62) | (63) |
| death information | (29), (30), (31), conditions 3 and 10 | no |
| species | conditions 14 and 15 | no |
| active, editor | conditions 12 and 16 | no |
| traits | no | (11) apply (list reset every tick) |
| grenade counts | no | (74) |
| purchase flags, requisition palette, loadout palette | no | (39), (69), (77) |
| objective texts and icon | no | (56), (57), (58) |
| co-op spawning flag | no | (59), (90) |
| respawn object and vehicle | no | (61), (104) |
| HUD message and sound | no | (16), (51) |
| navpoint | no | (4) to (8), (53) with a player-derived reference |
| boundary | | (10), (22), (98) with a player-derived reference |

## Teams

| property | read | write |
|---|---|---|
| team variables | scope 3, TIMER_REF 2, TEAM_REF 3, PLAYER_REF 3, OBJECT_REF 3 | same references as targets |
| score | scope 7 | (1), scope 7 |
| statistics | scope 12 | scope 12 |
| place | (36) | no |
| disposition between two teams | condition 4 | no |
| team is active | condition 7 | no |
| co-op spawning, respawn object, respawn vehicle, loadout | no | (59), (60), (105), (77) |

## Objects

| property | read | write |
|---|---|---|
| object variables | scope 2, TIMER_REF 3, TEAM_REF 2, PLAYER_REF 2, OBJECT_REF 2 | same references as targets |
| number byte of the property block | scope 6 | no |
| type | condition 6 | creation (2), (87) |
| label | condition 11 | creation (2) with a label |
| position related | conditions 2 and 8, (66), (27), (28) | (33), (91), (92), (34), (45), (3) |
| shield, health | (54), (55) | (64), (65), (67), (68) |
| device power and position | (71), (73) | (70), (72), (78), (79), (80) |
| holder of a weapon or equipment | (19) | no |
| equipment state | condition 13 | no |
| scale | | (52) |
| flags | | (23) invincibility, (24) bit 7 of +0x138, (82) respawn zone, (85) never garbage, (106) hidden, (44) pickup priority |
| visibility filters | | (12) pickup, (13) respawn, (14) fireteam filter, (15) progress bar, (22) boundary, (4) navpoint |
| navpoint | | (4) to (8), (53) |
| boundary | | (10), (22), (98) |

## HUD widgets

Four widgets: text (46), value (47), meter (48), icon (49), visibility per player (50). Widget state is part of the script state ([runtime](megalo-runtime.md)).

## Scoring, rounds and objectives

- Scores: signed 16-bit words per player (score table + player*8) and per team slot (score table + 0x80 + slot*8); scripts read them with number scopes 8 and 7 and change them with action 1 or by writing the scope. Action 1 acts only while the script gate (`function_7b15c`) passes. Players and teams also have four statistic slots (number scopes 11 and 12) declared in the gametype ([variant format](megalo-variant-format.md)).
- Rounds: action 21 ends the round; the gametype has no separate win opcode, so the result of a round follows from the scores and statistics through the engine's own code (not part of the gametype VM). The round start runs entry slots 0 and 1 ([triggers](megalo-triggers.md)).
- Objectives: per-player objective texts (actions 56 and 57), an allegiance icon (58), navpoints on objects and players (4 to 8, 53), boundaries (10, 22, 98), progress bars (15), HUD widgets (46 to 50), messages (16) and sounds (51).
- Spawning: primary respawn objects for players and teams (60, 61), respawn vehicles (104, 105), respawn zone enable bit (82), pickup, respawn and fireteam filters on objects (12, 13, 14), co-op spawning flags (59, 90).

## Forge-related items

- Condition 17 tells whether the game is a Forge game; condition 16 whether a player is the editor player; label filters (condition 11) and the label field of action 2 use the labels declared in the gametype (up to 16).
- Objects created by action 2 can carry a label; objects with a label are enumerated by loop kind 5 and by action 96.
- Respawn zone and filter actions (12, 13, 14, 82) and the property block bytes they use (+0x11, +0x12, +0x19, +0x1a, +0x84) describe the placement data attached to Forge objects ([runtime](megalo-runtime.md)).
