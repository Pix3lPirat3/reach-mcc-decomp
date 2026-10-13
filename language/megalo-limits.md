# Limits

Limits of the stock module, read from the code (V unless marked). Where a limit is checked by the gametype validator the variant is rejected on overflow; where it is not, the overflow is silent.

## Gametype file

| item | limit | where |
|---|---|---|
| serialized size | 0x5000 bytes | `function_56824` (compare at 0x5688c), `function_37890` |
| conditions | 512 | `function_544a4` (0x544a9) |
| actions | 1024 | 0x544f7 |
| triggers | 320 | 0x5453c |
| statistics | 4 | 0x545c5 |
| HUD widgets | 4 | 0x54788 |
| labels | 16 | 0x5483e |
| entry slots | 7 | fixed |
| strings | 112 (0x70) | `function_dd904` (0xdd93d) |
| string pool | 0x4bff bytes raw | 0xdd949 |
| options | 16, 8 values each | 0xddb49, 0xddb7e |
| custom traits | 16 | 0xddaf8 |
| declared global players | 8, objects 16, teams codes at most 9 | 0x54677 to 0x54696 |
| declared player, object players and objects | 4 each | 0x546d3 to 0x5472a |
| declared team players | 4, team objects 6 | 0x54767, 0x54774 |
| number and timer declaration counts | not validated (counts up to 15 are accepted; storage holds 12 global numbers, 8 global timers, 8 numbers and 4 timers elsewhere) | `function_55044` |
| MESSAGE arguments | decoded count up to 3, two slots exist | `function_1f6128` |

## Runtime

| item | limit | notes |
|---|---|---|
| player records | 16 records of 0xf0 bytes at G+0x2f4 | the new-round clear loop (0x147379 to 0x147380) and the 14 `imul 0xf0` sites in 0x1f0000 to 0x1f8000 plus 0x3db244 assume 16 players; an index of 16 or more runs into the team records at G+0x11f4 |
| team records | 9 of 0x58 bytes | 0x1473a9 |
| random-order loop | 18 dwords in the local buffer of `function_f6de8` | the 19th store overwrites the stack cookie |
| script objects | `megalo_objects` datum array of 512 records of 0x94 bytes | created by `function_7853c`; an object without a record reads the declared default values through number scope 2 |
| per-owner variable index | 3 bits (8) for player, object and team variables; 4 bits for global and option variables | `function_147012` |
| temporaries per trigger | 8 objects, 6 teams, 10 number temporaries (frame +0x28 to +0x4f; the index field is 4 bits), 3 players | see [variables](megalo-variables.md); number temporary indexes 10 to 15 address memory behind the ten slots |
| death records | 32 | `function_147134` clears 0x20 records |
| widgets | 4 | fixed |
| labels | 16 list heads | fixed |
| trait list per player | 16 | operation 11 |
| execution budget | none | no step, depth or time limit exists in `function_147958`, `function_14ad14`, `function_f6de8`, `function_1f6e0c` or `function_1f1ed0` |
| net replication of player and object state | 16-wide player loops and fixed-width entity index fields in the codecs | sites `function_4555bc`, `function_4558a0`, `function_4590bc`, `function_45931c`, `function_3d2cf0`, `function_3d2d84` (the loops with `cmp reg, 0x10` at 0x4551d1, 0x45529b, 0x455310, 0x457e7a, 0x459709, 0x4597e2, 0x459a2f are listed; their consequences are H) |
| simulated object glue | no -1 test after the glue datum allocation on the host | 0x3a63c4, 0x3a63c9 |

## Indexes the runtime does not check

Each row is read from the handler code (V); what happens when a file uses such a value is not determined (H). A file that the validator accepts can contain these values only where the validator does not reject them.

| index | handler | what the code does |
|---|---|---|
| widget index none (-1) in operations 46 to 50 | dispatcher blocks f36a0, f36e5, f3826, f38fb, f396e | the widget is addressed as G+0x258 + widget*0x28 without a test, so -1 addresses 0x28 bytes before widget 0 (G+0x230 and following) |
| trigger index in operation 20 | `function_1f1ed0` | the trigger record is addressed from the index (u8) without a comparison with the trigger count |
| number temporary index 10 to 15 | `function_14648c` (read), `function_146a28` (write) | the frame holds 10 number slots (see [variables](megalo-variables.md)) |
| player index 16 or more in the Megalo player loops and records | see the player records row above | the records are 16 wide |

## HaloScript (scenario scripts)

| item | limit | where |
|---|---|---|
| deterministic script threads | 320, non-deterministic 4, stack 0x500 | 0x84982, 0x849ab, 0x86456, 0x8638e |
| node pool | 64512 | 0x81846 |
| globals | 4096 | 0x849d4 |
| object list headers 48, elements 128 | | 0x8187a, 0x818d0 |
| native slots in the table | 1882 | table at 0xa28d40, bounds at 0x81f2d, 0x82643, 0x82789 |
