# Runtime state

All offsets come from the code of the module (V). "G" is the 0x8430-byte block at thread-local slot +0x20 (created by `function_7853c`). The script state "M" starts at G+0x16c. Script objects live in the datum array `megalo_objects` (thread-local slot +0x4f0).

## Script state block M

| M offset | G offset | content |
|---|---|---|
| +0x0 | +0x16c | current object (dword) |
| +0x4 | +0x170 | current player |
| +0x8 | +0x174 | current team |
| +0xc | +0x178 | byte flag (number scope 15) |
| +0x10, +0x14, +0x18 | +0x17c, +0x180, +0x184 | event context: object, object, player |
| +0x1c | +0x188 | event byte (number scope 43) |
| +0x30 | +0x19c | 16 global object variables (variable n at +0x30 + n*4; codes 1 to 16 address them at +0x2c + code*4) |
| +0x70 | +0x1dc | 8 global team variables (bytes) |
| +0x78 | +0x1e4 | 12 global number variables (dwords) |
| +0xa8 | +0x214 | 8 global timers |
| +0xc8 | +0x234 | 8 global player variables (bytes) |
| +0xd8 | +0x244 | pointer to the current temporary frame |
| +0xec | +0x258 | 4 HUD widget records of 0x28 bytes |
| +0x188 | +0x2f4 | 16 player records of 0xf0 bytes |
| +0x1088 | +0x11f4 | 9 team records of 0x58 bytes |
| +0x13a0 | +0x150c | 16 label list heads (dwords) |
| +0x1274 | +0x13e0 | death record count (dword); 32 records of 16 bytes follow at M+0x127c (G+0x13e8) |
| | +0x841c | engine instance type (1 to 4); the instance table is at RVA 0xb95f70 |

### Player record (0xf0 bytes, initialised by `function_14c4fc`)

| offset | content |
|---|---|
| +0x00 | 4 object variables (dwords, start at -1) |
| +0x10 | 4 team variables (bytes) |
| +0x14 | 8 number variables (dwords) |
| +0x34 | 4 timers |
| +0x44 | 4 player variables (bytes, -1) |
| +0x4c | navpoint record: message 8 bytes, string word at +0x54, icon byte +0x56 (0xff), visibility mode +0x58 (5), mask +0x5c, priority +0x60 (1), timer +0x61 (0xff), range bytes +0x62 and +0x63 |
| +0x64 | boundary record: 4 floats (+0x64 to +0x73), shape byte at +0x74 |
| +0x76 | byte of 5 purchase flags (operation 39) |
| +0x77 | requisition palette byte (operation 69) |
| +0x78 | objective message (operation 56): 8 bytes, string word at +0x80 |
| +0x84 | allegiance icon dword (operation 58) |
| +0x88 | allegiance message (operation 57): 8 bytes, string word at +0x90 |
| +0x94 | time stamp dword for the two messages |
| +0x98 | byte flag (operations 59 and 90) |
| +0x9c | boundary visibility record: mode +0x9c, mask +0xa0, color byte +0xa4 |
| +0xa8 | trait count (dword), traits dword array from +0xb0 (16 entries) |

### Team record (0x58 bytes, `function_14c9e8`)

+0x00 6 object variables (dwords), +0x18 4 team variables (bytes), +0x1c 8 numbers, +0x3c 4 timers, +0x4c 4 player variables (bytes), +0x50 word counter used for replication timing.

### Script object record (0x94 bytes, `megalo_objects` datum)

| offset | content |
|---|---|
| +0x02 | fireteam mask byte (operation 14) |
| +0x03 | weapon pickup priority (operation 44) |
| +0x04 | navpoint record (message +0x4, string word +0xc, icon +0xe, visibility mode +0x10, mask +0x14, priority +0x18, timer +0x19, range +0x1a and +0x1b) |
| +0x1c | pickup visibility (mode +0x1c, mask +0x20) |
| +0x24 | respawn visibility (mode +0x24, mask +0x28) |
| +0x2c | boundary visibility (mode +0x2c, mask +0x30, color byte +0x34) |
| +0x3c | 4 object variables |
| +0x4c | 4 team variables (bytes) |
| +0x50 | 8 number variables |
| +0x70 | 4 timers |
| +0x80 | 4 player variables (bytes) |
| +0x88 | progress bar visibility (mode +0x88, mask +0x8c), byte +0x90 |

### HUD widget record (0x28 bytes at G+0x258 + widget*0x28)

+0x00 dword mask of players the widget is visible to; +0x04 text message (8 bytes, string word at +0x0c); +0x0e value message (8 bytes, string word at +0x16); +0x18 meter (dword, word at +0x1c, byte at +0x1e); +0x20 icon dword. Changes mark bit `widget + 0xe` of the engine change mask through `function_3a5be8`.

### Death record (16 bytes, 32 records from M+0x127c)

+0 player index (the key searched by `function_14d688`), +4 killer player index, +8 damage type byte, +9 special type byte, +0xa kind byte (bit index tested by condition 3), +0xc mask of players credited with assists.

### Object property block (from `function_47b848`)

Offsets inside the block pointed to by an object's multiplayer properties: +0x00 to +0x0f four boundary floats, +0x10 boundary shape byte, +0x11 a type byte (the value 0xf is excluded by operations 13 and 14), +0x12 a flag word (bit 14 enables a respawn zone, operation 82), +0x19 team designator byte, +0x1a number byte (number scope 6), +0x84 label string id.

### Label matching (`function_146208`)

An object matches a label record when its object index is valid and: the label name matches the object label (`function_1463d4` against property +0x84); if flag bit 0 is set, the object type equals the label type; if flag bit 2 is set, the property byte +0x1a equals the label number; if flag bit 1 is set and the label team is not 9, the property byte +0x19 equals the label team. An object with no property block matches only when no flag bit 1 or 2 is set and the label name is -1.

## Per tick

`function_14753c` (called through the engine instance) first clears the event context fields in the thread-local block at +0x290 (+0xdcc8, +0xdccc, +0xdcd0) to -1. When the script gate `function_7b15c` passes it sets the trait count (player record +0xa8) of all 16 player records to 0, so traits applied with operation 11 last for one tick only; it then runs the engine virtual +0x350, updates the timers (`function_14ce60`, which applies the per-tick reduction `function_1069fc` and the limit check `function_106a54` to every global, player, team and object timer and marks the owner as changed when a limit was hit), and steps the per-object and per-player script blocks. The trigger run is `function_147958` ([triggers](megalo-triggers.md)).

## Replication of script variables

Variables replicate through simulation entities: players (`function_4555bc`, `function_4558a0`), globals (`function_456634`, `function_4578d4`), objects (`function_4590bc`, `function_45931c`) and teams (`function_458ee8`, `function_458ff4`). Every setter marks the changed variable with a dirty mark (`function_3db198`, `function_3db218`, `function_3db2c0`, `function_3db3b4`).
