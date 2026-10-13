# Conditions

A condition record is 16 bytes (decoder `function_f6ba8`, evaluator `function_f6524`):

| offset | size | field |
|---|---|---|
| +0x0 to +0xb | 12 | arguments (layout depends on the type) |
| +0xc | 1 | type (u5; 0 = none) |
| +0xd | 1 | negate flag (bool) |
| +0xe | 1 | OR group (u9 in the stream, stored in one byte) |
| +0xf | 1 | action offset (u10 in the stream, stored in one byte) |

Up to 512 conditions exist per gametype (stored from definition +0xf10). A type of 0 and all types from 18 to 31 are not handled by the evaluator: it leaves its default result of true, which the negate flag then inverts (V). A valid variant cannot contain types of 18 or more: the validator (`function_544a4`) rejects them.

## Evaluation order

A trigger names a range of conditions and a range of actions. For each action of the trigger, in order, the engine (`function_1f6e0c`) walks the conditions of the trigger from the first until it meets one whose action offset is greater than the index of the current action (V). Conditions walked with the same OR group value as the previous one are OR-ed with it (a true result short-circuits; the condition is not evaluated); a condition with a different OR group value is AND-ed: if the running result is already false the action is skipped, otherwise the condition is evaluated and its result becomes the running result. The action runs when the final result is true. Conditions are therefore re-evaluated for every action they cover, and a condition with action offset `k` applies to every action from index `k` on.

## Types

Type names are labels from a match against another build (evidence S); the behavior is read from the code (V).

| type | label | arguments | behavior |
|---|---|---|---|
| 1 | compare | ANY_REF at +0, ANY_REF at +4, comparison u3 at +8 | Compares two values of the same kind. Numbers: comparison 0 less, 1 greater, 2 equal, 3 less or equal, 4 greater or equal, any other value not equal. Players, objects and teams: only equality is tested: comparison 2 gives equal, every other value gives not equal. A timer on the left may be compared with a timer or a number on the right, and a number on the left with a timer on the right. A timer operand is converted by `function_1f6a38` to whole seconds, rounded up: (floor(value / 20) + rate - 1) / rate in integer division, with the rate the signed word at +6 of the block at TLS +0xa0; a number operand is read as a plain number. The comparison is then a signed 32-bit compare. `function_1f72d0`. |
| 2 | object_in_area | OBJECT_REF at +0, OBJECT_REF at +3 | True when the first object lies inside the boundary of the second (shape and size of operation 10). When the second reference is player-derived, the boundary stored in the player record (+0x64) is used. `function_1f74a4`, position test `function_1f7438`. |
| 3 | player_died | PLAYER_REF at +0, mask u5 at +3 | Looks up the death record of the player (`function_14d688`); true when the bit selected by record byte +0xa is set in the mask. False when the player has no record. |
| 4 | team_disposition | TEAM_REF at +0, TEAM_REF at +3, relation u2 at +6 | Relation code of the two designators: 0 when either is 8 (neutral); 2 when either is -1; otherwise 1 when equal and 2 when different. True when it equals the argument. |
| 5 | timer_expired | TIMER_REF at +0 | True when the timer has a declared initial value of 0 or more (`function_1f6838`) and its 24-bit value is 0. |
| 6 | object_is_type | OBJECT_REF at +0, OPT_U11 at +4 | True when the definition dword of the object (+0) equals the type resolved from the argument (`function_132ca0`). |
| 7 | team_is_active | TEAM_REF at +0 | When the engine virtual +0x40 of the gametype instance returns true: true when the designator is 0 or 1. Otherwise `function_37b78(function_37d44(team))`. |
| 8 | object_out_of_bounds | OBJECT_REF at +0 | `function_1f75c0`: tests the position of the object against the scenario volume list (iterator `function_473b18`, test `function_4b25d4`); volumes whose type byte is 0x19 are classified by flag bit 6 of byte +0x12. Falls back to `function_154630(object)` when no volume decides. Evidence of the exact classification is partial (V/H). |
| 9 | (always false) | PLAYER_REF at +0 | Resolves the reference and then returns false whatever the player is. |
| 10 | player_assisted_with_kill | PLAYER_REF at +0, PLAYER_REF at +3 | Looks up the death record of the player at +3; true when bit (player index of +0) is set in the record mask at +0xc. |
| 11 | object_matches_filter | OBJECT_REF at +0, label u4 at +4 (bool none, else u4; dword) | False for no object or no label. Otherwise `function_146208(label record, object)`: label record index (idx + 0xe4e) * 16 of the variant. See the label filter in [runtime](megalo-runtime.md). |
| 12 | player_is_active | PLAYER_REF at +0 | `function_4a1a8(player)`; false for no player. |
| 13 | equipment_is_active | OBJECT_REF at +0 | True when the object is an equipment object (type byte 3) and the dword at +0x1d8 is not -1. |
| 14 | player_is_spartan | PLAYER_REF at +0 | True when `function_487c4(player)` is 0. |
| 15 | player_is_elite | PLAYER_REF at +0 | True when `function_487c4(player)` is 1. |
| 16 | player_is_editor | PLAYER_REF at +0 | `function_715ac(player, 0)`. |
| 17 | game_is_forge | none | `function_71540()`. |

Types 2, 3, 6, 11 and 13 return false when the reference resolves to none.
