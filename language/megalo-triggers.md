# Triggers, loops and entry points

## Trigger record

A gametype holds up to 320 triggers (count stored at definition +0x0, records from +0x8, 12 bytes each, decoded by `function_55044`). Conditions and actions live in two shared arrays; a trigger names a contiguous range of each.

| offset | size | field |
|---|---|---|
| +0 | 2 | first condition (u9 in the stream) |
| +2 | 2 | condition count (u10) |
| +4 | 2 | first action (u10) |
| +6 | 2 | action count (u11) |
| +8 | 1 | loop kind (u3), values 0 to 5 are valid |
| +9 | 1 | selector (u3), values 0 to 7 are valid |
| +0xa | 1 | label index (loop kind 5 only: bool none, else u4; other loop kinds must store 0xff) |

Validation (`function_544a4`): the loop kind must be below 6 and the selector below 8; selectors 2, 3, 4 and 7 are valid only with loop kind 0; loop kind 5 needs a label index below the label count; the condition and action ranges must lie inside the declared totals (V).

## Loop kinds

The trigger runner is `function_f6de8`; one pass over the trigger body (`function_1f6e0c`, see [conditions](megalo-conditions.md) for the evaluation rules) is made per loop iteration.

| kind | name | iteration |
|---|---|---|
| 0 | once | One pass with the current player, object and team unchanged. |
| 1 | for each player | Walks the players datum in index order (`function_4a380`); M+4 (current player) is set for each pass. |
| 2 | for each player, random order | The player indexes are collected into a local array (the cookie slot sits after the 18th element, see [limits](megalo-limits.md)), shuffled with `function_f6da8` and walked. |
| 3 | for each team | Teams 0 to 8; M+8 (current team) is set for each pass. |
| 4 | for each object | Walks the objects (`function_473a78`/`function_473b18` iterator over the object types selected by the mask 0x5cf, bits 0 to 3, 6, 7, 8 and 10 of the type byte at object header +4); passes are skipped for objects whose object table entry (stride 0x18) has flag bit 5 of the byte at +2 set; what that flag means is not determined. M+0 (current object) is set for each pass. |
| 5 | for each object with label | Passes are skipped under the same object table test as kind 4. Walks the label list `label` (list head at M+0x13a0 + label*4, i.e. G+0x150c + label*4; the next link is the dword at +0x44 + label*4 of the per-object script block, located through the word at +0x192 of the object block). |

## Selectors and when triggers run

A trigger is executed in these ways (V):

1. The per-tick executor `function_147958` runs every trigger whose selector is 0 or 6, in index order, while the engine byte +0x11 of the gametype instance is not 4. When that byte is 4 it runs only the trigger named by entry slot 6 (+0x8200) instead.
2. An entry slot (below) names a trigger that runs on an engine event.
3. Operation 20 and operation 99 run triggers or inline ranges from an action.

Selector values other than 0 and 6 are not run by the per-tick executor.

## Entry slots

Seven dwords at definition +0x81ec to +0x8204 hold trigger indexes (-1 none; each value must be -1 or below the trigger count). Every run of an entry trigger goes through `function_14ad14`, which pushes a fresh temporary frame, clears the event context and runs the trigger with `function_f6de8`.

| slot | offset | run by | when |
|---|---|---|---|
| 0 | +0x81ec | `function_1472f4` | at the start of a round, if the engine byte +0x11 is not 4 |
| 1 | +0x81f0 | `function_1472f4` | at the start of a round, after slot 0 |
| 2 | +0x81f4 | `function_14ac24` | on host migration |
| 3 | +0x81f8 | `function_14ac24` | on host migration when the argument is 1; used instead of slot 2 (slot 2 is the fallback when slot 3 is -1) |
| 4 | +0x81fc | `function_147a5c` | when a script object is killed; the event context M+0x10, M+0x14, M+0x18 and the byte at M+0x1c are filled before the run and cleared afterwards |
| 5 | +0x8200 | `function_147958` | per tick when the engine byte +0x11 is 4 |
| 6 | +0x8204 | `function_147134` | when a new map starts, after the script state is reset |


At the start of a round (`function_1472f4`) every player record is reset (`function_14c4fc`), every team record is reset (`function_14c9e8`), the global variables are reset from the declarations (`function_14bb94`) and the player records are marked changed (masks 0x1f000000). The map-start routine (`function_147134`) clears the object, widget and player state first.

## Execution budget

The engine keeps no step counter, no recursion depth and no per-tick action budget: operation 20 recurses on the native stack, and a heavy script only lengthens the tick (V).

## Event context

The event context holds the players and object involved in the current event: two players (TLS+0x290 block +0xdcc8 and +0xdccc), an object (+0xdcd0), and the copies at M+0x10, M+0x14, M+0x18. They are set by the kill and message paths (for example `function_147a5c`) and read through player code 0x1a/0x1b/0x1c, object codes 0x12 to 0x14 and team codes 0x12/0x13 ([variables](megalo-variables.md)). At the start of every tick the context fields at +0xdcc8, +0xdccc and +0xdcd0 are reset to -1 (`function_14753c`).

Roles of the event context values as far as the code shows them (V): the runner of entry slot 4 (`function_147a5c`) takes its object from the second argument register into M+0x10, the value of the fourth argument register into M+0x14, the value of the third argument register into M+0x18 and a byte read through a pointer argument into M+0x1c; its only caller (`function_74e74`) afterwards continues with the object it passed as second argument. That M+0x10 is the object that was killed, and which of the other values is the killer, is a hypothesis (H); the roles for the other entry slots are not determined.
