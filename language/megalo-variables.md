# Variables, references and scopes

Evidence levels: V read from the module's code, S inferred from a match with another build, H hypothesis. Offsets are byte offsets; RVAs are `function_RVA`.

## Value kinds

| kind | stored as | notes |
|---|---|---|
| number | signed 32-bit dword | Constants inside a script are signed 16-bit. Arithmetic uses 32-bit signed operators (see [enums](megalo-enums.md), operator codes 0 to 12). Reads and writes go through `function_14648c` and `function_146a28`. |
| timer | dword: low 24 bits value, high byte rate code | The value counts in units of 1/20 tick. A timer with value `s` seconds is stored as `s * tick rate * 20` (tick rate is the signed word at +6 of the block at thread-local slot +0xa0). Each tick the value is reduced by `trunc(rate multiplier * 20 + 0.5)` (`function_1069fc`); when the reduction is at least the value it becomes 0 and the rate code is cleared. The maximum initial value is `0x6270` seconds. |
| team | signed byte designator | -1 none, 0 to 7 teams, 8 neutral (no team). Variables hold -1 when unset. |
| player | signed byte player slot | Converted to a player index with `function_485e8`; -1 none. |
| object | dword object index | -1 none. |

Widgets, labels, statistics and options are declared separately (see [variant format](megalo-variant-format.md)).

## Scopes and declaration counts

Every scope owns variables of up to five kinds. The count of each kind is declared in the gametype (a 3 or 4 bit field), followed by an initial value (and for most kinds a 2-bit network priority). Declaration order inside each scope: numbers, timers, teams, players, objects. Scope order: global, player, object, team.

| scope | numbers | timers | teams | players | objects | where the values live |
|---|---|---|---|---|---|---|
| global | 12 (count field 4 bits, storage for 12) | 8 | 8 | 8 | 16 | script state block M (G+0x16c), see [runtime](megalo-runtime.md) |
| player | 8 | 4 | 4 | 4 | 4 | player record (0xf0 bytes), 16 records |
| object | 8 | 4 | 4 | 4 | 4 | script object record (0x94 bytes) |
| team | 8 | 4 | 4 | 4 | 6 | team record (0x58 bytes), 9 records |

The validator (`function_544a4`) limits the player, team and object counts of the player, players and objects kinds only as shown in [limits](megalo-limits.md); the number and timer counts are not validated, so a declared count that exceeds the storage above overruns into the next field (V).

Initial values: numbers are evaluated from the declared NUM_REF when the record is created; timer initial values are in seconds and stored as described above; object variables and player variables start at -1; team variables take the declared designator; the network priority is a 2-bit value stored with the declaration (its use by the replication code is not decoded, U).

## Reference encodings

References are decoded from the bit stream by one function per type (V). Offsets in the table are inside the 3-byte reference record unless a tag is mentioned.

| type | decoder | selector | payload |
|---|---|---|---|
| NUM_REF | `function_146f88` | u6 scope code, stored at +2 | code 0: i16 constant; 1 and 2: u5 owner code + u3 index; 3: u5 minus one owner code + u3 index; 4, 5 and 44: u4 index; 6, 9, 10: u5; 7: u5 minus one; 8: u5; 11: u5 + u2; 12: u5 minus one + u2; all other codes carry no payload |
| PLAYER_REF | `function_1f4ae0` | u2 kind, stored at +2 | 0: u5 code; 1: u5 owner + u2 index; 2: u5 owner + u2 index; 3: u5 minus one owner + u2 index |
| TEAM_REF | `function_1f50a8` | u3 kind | 0: u5 minus one; 1: u5 + u2; 2: u5 + u1; 3: u5 minus one + u2; 4 and 5: u5; 6 and 7: none |
| OBJECT_REF | `function_1f584c` | u3 kind | 0: u5; 1 and 2: u5 + u2; 3: u5 minus one + u3; 4: u5; 5 and 6: u5 + u2; 7: u5 minus one + u2 |
| TRIGGER_RANGE (8 bytes) | operation 99 | four words | +0: first condition (u9), +2: condition count (u10), +4: first action (u10), +6: action count (u11); the same widths as the trigger record |
| TIMER_REF | `function_1f6d90` | u3 kind, stored at +1 | 0: u3 index; 1: u5 + u2; 2: u5 minus one + u2; 3: u5 + u2; 4 to 7: none |
| ANY_REF (4 bytes) | `function_1f5d2c` | u3 tag stored at +3 | 0 number, 1 player, 2 object, 3 team, 4 timer; the matching reference is read into bytes +0..+2 |
| TEAM_OR_PLAYER (4 bytes) | `function_f5f14` | u2 tag stored at +3 | 0 team reference, 1 player reference. Consumers also accept tag 2 (all players) |
| OPT_U11 | `function_1f5160` | bool | set: -1; clear: u11 value (dword) |
| OPT_U2 | `function_f6154` | bool | set: -1; clear: u2 value (dword) |
| TAGGED (7 bytes) | `function_1f7268` | u2 tag at +0 | 1: NUM_REF at +1 and NUM_REF at +4; 2: TIMER_REF at +1; 0: none |
| PROP_ASSIGN (8 bytes) | `function_1f5a4c` | u3 mode at +0 | mode 4: PLAYER_REF at +1 and NUM_REF at +4 |
| MESSAGE (10 bytes) | `function_1f6128` | u7 string index minus one stored as a word at +8 (-1 none), u2 argument count (not stored) | per argument: u3 type minus one stored at slot byte +3 (0 player, 1 team, 2 object, 3 number, 4 timer), then the typed reference in the 4-byte slot (slots at +0 and +4). The count field allows 3, but only two slots exist; a third argument would overwrite the string word (V) |

### How references resolve

OBJECT_REF kinds (resolver `function_1f522c`):

| kind | meaning |
|---|---|
| 0 | object code (table below) |
| 1 | object variable `idx` of the player given by the owner code |
| 2 | object variable `idx` of the object given by the owner code |
| 3 | object variable `idx` of the team given by the owner code |
| 4 | the unit of the player given by the owner code (`function_14c09c`) |
| 5 | the unit of player variable `idx` of the player |
| 6 | the unit of player variable `idx` of the object |
| 7 | the unit of player variable `idx` of the team |

Kind 5 of the player-index resolver (`function_1f53f8`) reads the byte at G + 0xf00248 + idx without scaling by a player index (V; an apparent defect of the resolver, the value read is outside the state block).

PLAYER_REF kinds (`function_1f4724`): 0 player code; 1 player variable `idx` of a player; 2 player variable of an object (script object record +0x80+idx); 3 player variable of a team (team record +0x4c+idx). Results go through `function_485e8`.

TEAM_REF kinds (`function_1f4b68`): 0 team code; 1 team variable `idx` of a player (player record +0x10+idx); 2 team variable of an object (script object record +0x4c+idx, or the declared default at variant +0xe44c+idx while no record exists); 3 team variable of a team (team record +0x18+idx); 4 the team of a player (engine virtual +0x190); 5 the team of an object (`function_14c138`); 6 and 7 resolve to -1.

TIMER_REF kinds (`function_1f6a90`): 0 global timer `idx` (G+0x214+idx*4); 1 player timer (player record +0x34+idx*4); 2 team timer (team record +0x3c+idx*4); 3 object timer (script object record +0x70+idx*4); 4, 5, 6 the built-in timers at G+0xe4, G+0xe8, G+0xec (their purpose is not decoded, U); 7 none.

### Code tables

Player codes (`function_22548c`): 0 none; 1 to 16 player slot 1 to 16 (code minus one, converted with `function_485e8`); 0x11 to 0x18 global player variables 0 to 7; 0x19 the current player (M+4); 0x1a and 0x1b event players stored at TLS+0x290 block +0xdcc8 and +0xdccc; 0x1c the player at M+0x18; 0x1d to 0x1f temporary players 0 to 2; anything else none.

Object codes (`function_22562c`): 0 none; 1 to 16 global object variables (code c is the variable c minus one, at M+0x2c + c*4, so variable 0 is at M+0x30, G+0x19c); 0x11 the current object (M+0); 0x12 the object at TLS+0x290 block +0xdcd0; 0x13 and 0x14 the objects at M+0x10 and M+0x14 (event objects); 0x15 none; 0x16 to 0x1d temporary objects 0 to 7.

Team codes (`function_22576c`): -1 none and 0 to 8 literal designators; 9 to 16 global team variables 0 to 7; 0x11 the current team (M+8); 0x12 the team of the event player stored at TLS+0x290 block +0xdcc8 (engine virtual +0x190); 0x14 to 0x19 temporary teams 0 to 5; any other code (including 0x13): the team of the event player at +0xdccc when one is stored, otherwise the team of the event object at +0xdcd0.

### Temporaries

Each trigger run (`function_14ad14`) uses a 0x60-byte temporary frame on its own stack and stores its address at G+0x244 for the duration of the run; the previous frame address is restored afterwards, so every nested trigger (operation 20) runs with its own frame. Layout as the resolvers read it: object temporaries 0 to 7 at frame +0 to +0x1f (codes 0x16 to 0x1d), team temporaries 0 to 5 at +0x20 to +0x25 (one byte each), number temporaries at +0x28 (NUM_REF scope 44, four bytes each), player temporaries 0 to 2 at +0x50 to +0x52. The function does not store initial values into the frame: the six calls it makes for the team temporaries (`function_372a0`) only return their argument. What the frame holds when a run starts is therefore not determined by this code. The frame has room for 10 number temporaries (+0x28 to +0x4f), but the index field of scope 44 is 4 bits wide (0 to 15): index
  10 reaches the player temporaries at +0x50, indexes 11 to 13 reach +0x54 to +0x5f; index 14 lies on the stack cookie of `function_14ad14` at frame +0x60 and index 15 lies at +0x64, past the frame (V for the addresses; the consequence of using those indexes is H).

## Number scope codes

NUM_REF scope code `c` as read (`function_14648c`) and written (`function_146a28`). Constant codes carry values in the instruction; codes 13 to 43 read engine or gametype settings.

| code | value read | write |
|---|---|---|
| 0 | i16 constant | no |
| 1 | player variable: dword at player record +0x14 + idx*4 | yes (marks the player) |
| 2 | object variable: script object record +0x50 + idx*4; if no record exists, the declared default (variant declaration at (idx + 0x4c08)*3) | yes (marks the object) |
| 3 | team variable: team record +0x1c + idx*4 | yes |
| 4 | global variable: M+0x78 + idx*4 | yes |
| 5 | gametype option value (`function_ddeb8`), read again as a NUM_REF | no |
| 6 | object byte at property block +0x1a | no |
| 7 | team score (`function_37d44`, `function_79f1c`) | yes (`function_18f974`) |
| 8 | player score (`function_79b20`: word at score table + player*8, +2 when a game flag is set) | yes (`function_7b894`) |
| 9 | player datum dword +0x3b4 | yes (`function_225960`) |
| 10 | computed player value (`function_79c14`, a weighted sum of player statistics) | no |
| 11 | player statistic number idx + 0xf (`function_fa5a0`) | yes (`function_fa458`) |
| 12 | team statistic number idx + 0xf | yes |
| 13 | game property: word at G+0xda (`function_7b238`) | no |
| 14 | engine virtual +0x58 (byte) | no |
| 15 | engine virtual +0x58 (byte) | yes: stores (value != 0) at M+0xc |
| 16 | engine virtual +0x48 | no |
| 17 | engine virtual +0x40 (byte) | no |
| 18 | variant byte +0x2b8 bit 0 | no |
| 19 | variant byte +0x2ba times 60 | no |
| 20 | variant byte +0x2bb | no |
| 21 | variant byte +0x2b8 bit 3 | no |
| 22 | variant byte +0x2b9 | no |
| 23 | variant word +0x2bc | no |
| 24 | variant word +0x2be | no |
| 25 to 32 | variant bytes +0x2c1 to +0x2c8 | no |
| 33 to 37 | variant word +0x2f8 bits 0 to 4 | no |
| 38 | variant +0x2fc bit 0 | no |
| 39 | variant +0x2fc bit 5 | no |
| 40 to 42 | variant bytes +0x3b4 to +0x3b6 | no |
| 43 | byte at M+0x1c (G+0x188) | no |
| 44 | number temporary `idx` of the current frame | yes |

Every write with a code not listed above (including 13, 14, 16 to 43) goes to the temporary array (scope 44 behavior). Codes 0, 5 and 6 as write targets go to the team-score path. The setter dirties the replication marks `function_3db198` (global), `function_3db218` (player), `function_3db2c0` (object), `function_3db3b4` (team) (V).
