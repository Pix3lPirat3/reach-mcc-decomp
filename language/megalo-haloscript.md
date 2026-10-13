# HaloScript and its relation to gametypes

HaloScript is the scenario script language. Scenario scripts run on their own threads, separate from the gametype VM. The two meet in a few places only (V).

## From a gametype to a script

Action 100 (start scenario script) starts a script by index:

1. the 7-bit stream value minus one is mapped by `function_244a54`;
2. `function_81be8` finds the script with that index;
3. `function_851c0` runs it.

The script cannot take arguments, and it counts against the script limits in [limits](megalo-limits.md).

## From a script to the engine

Scripts reach the same engine functions that gametype actions use:

- the `mp_*` natives use the same end-of-round routine as action 21 (`function_7b3ec`);
- the native `game_grief_record_custom_penalty` and action 97 both call `function_14fa5c`.

## Native function table

The scenario script natives are stored in a table at RVA 0xa28d40: 1882 slots, 1093 distinct evaluators. A slot is: return type (dword at +0), flags (+4), name pointer (+8), kind (+0x10: 0 normal, 1 command-script only, 2 special form), parser (+0x18), evaluator (+0x20), usage string pointer (+0x30), parameter count word (+0x38) and parameter type words from +0x3a. The central dispatcher `function_858a8` calls `[entry + 0x20]` with the function index (16-bit) in rcx, the thread in rdx, a flag byte in r8 and the table entry in r9; the result of the call is ignored and natives return values through `function_85de0`. Argument values are evaluated through `function_865e8`. Name lookup (`function_81e78`) is a linear string comparison that also checks the parameter count, so overloaded names occupy separate slots.

| category | slots | distinct evaluators |
|---|---|---|
| implemented | 1215 | 1085 |
| "not implemented" stub (`function_86cbc`: returns 0 without evaluating arguments) | 595 | 1 |
| arguments evaluated, then 0 returned (mainly `function_199364`, shared by 65 slots) | 68 | 3 |
| constant return | 3 | 3 |
| special form without evaluator | 1 | 1 |

By name prefix the stubs are mostly debug, test, network, UI and renderer commands; every `net*`, `cui_*` and `test_*` native is a stub, as are 48 of 52 `debug_*` natives. The three constant-return natives are `generate_pathfinding`, `survival_mode_waves_per_round` and `survival_mode_rounds_per_set`.

Adding a native to the table means relocating it and changing the three bounds at `function_81f2d`, `function_82643` and `function_82789`.

## Player and object natives and the gametype state

The player natives that enumerate players (`players`, `player_get`, `game_coop_player_count`, `mp_active_player_count_by_team`) read the players datum directly; some `mp_*` natives read the per-player statistic table with stride 0xd8. They do not use the gametype script records.

## Limits

Scenario scripts have 320 deterministic and 4 non-deterministic threads, a node pool of 64512 and 4096 globals ([limits](megalo-limits.md)).
