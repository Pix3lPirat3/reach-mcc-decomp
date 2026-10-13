# Enumerations and codes

Values are the numbers stored in the gametype; meanings are what the engine does with them (V) unless marked.

## Operators (4-bit field, `function_14bfc0`)

`a` is the current value, `b` the operand. The result replaces `a`.

| code | operation |
|---|---|
| 0 | a + b |
| 1 | a - b |
| 2 | a * b |
| 3 | a / b (signed; 0 when b is 0) |
| 4 | b (assign) |
| 5 | a mod b (signed remainder; 0 when b is 0) |
| 6 | a and b |
| 7 | a or b |
| 8 | a xor b |
| 9 | not b (bitwise) |
| 10 | a shifted left by b |
| 11 | a shifted right by b (arithmetic) |
| 12 to 15 | absolute value of b |

The float operations on object vitality and maximums (operations 64, 65, 67, 68) and on grenades (74) use the codes 0 to 4 as add, subtract, multiply, divide (only for a positive divisor) and assign; any other code leaves the value unchanged.

## Comparison (3-bit field of condition 1)

0 less than, 1 greater than, 2 equal, 3 less or equal, 4 greater or equal; every other value means not equal. For players, objects and teams only 2 (equal) is distinguished from the rest (not equal).

## Loop kinds and selectors

Loop kinds 0 to 5: once, for each player, for each player in random order, for each team, for each object, for each object with a label ([triggers](megalo-triggers.md)). Selector values 0 to 7: the per-tick executor runs 0 and 6; 2, 3, 4 and 7 are valid only with loop kind 0.

## Visibility selector (PROP_ASSIGN mode, 3 bits)

Evaluated by `function_1f5a94` for one player and one owner team:

| mode | visible to |
|---|---|
| 0 | nobody |
| 1 | everybody |
| 2 | players whose team relation to the owner is "same team" |
| 3 | players whose team relation is "different" (an unset team counts as different; neutral does not match) |
| 4 | the players set in the mask (a player of -1 is never visible) |
| 5 to 7 | nobody |

Team relation code (condition 4 and the functions above): 0 when either designator is 8, 2 when either is -1, otherwise 1 for equal and 2 for different.

Defaults: a newly reset navpoint has mode 5.

## Boundary shape (operation 10)

0 none, 1 one value (first number), 2 three values (+0x4, +0xa, +0xd), 3 four values (+0x4, +0x7, +0xa, +0xd). The numbers are multiplied by 0.1 and limited by `function_1f1a4c` before they are stored as floats.

## Timer rate codes (5 bits, `function_1069fc`)

The multiplier applied per tick (times 20 units); a negative multiplier makes the timer count up until its limit:

| code | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| rate | 0 | 0.1 | 0.25 | 0.5 | 0.75 | 1 | 1.25 | 1.5 | 1.75 | 2 | 3 | 4 | 5 | 10 |

| code | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 | 25 | 26 | 27 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| rate | -0.1 | -0.25 | -0.5 | -0.75 | -1 | -1.25 | -1.5 | -1.75 | -2 | -3 | -4 | -5 | -10 | 0 |

Codes 28 to 31 read data that follows the table (not meaningful values); they are valid in the stream.

## Team designators

-1 none; 0 to 7 the eight teams; 8 neutral. Team slots 0 to 8 exist in the script state.

## Object type byte (object header +4)

The values below are the ones the actions rely on: 0 unit (biped), 1 vehicle, 2 weapon, 3 equipment (S: the numbering matches the usual object type order; the code only compares them).

## Navpoint icon codes (operation 5)

The stored value is the stream value minus one. Values 0 to 0xa select icons directly; 0xb takes the icon from a number: `0xb + min(max(n - 1, 0), 8)`. The icon images themselves are not decoded.

## Operation 93 mode

Stream value 0 gives engine argument 3, 1 gives 0, 2 gives 1, 3 gives 0.

## Grenade type (operation 74)

1 bit (0 or 1): the count byte at unit +0x37e + type, limited to 0 to 4.

## Widget positions (4-bit, below 0xc)

Twelve position codes are accepted; their screen positions are not decoded.

## Statistics

Per statistic: name index (u7), format (u2, 0 to 3), sort order (u2 minus one), group flag (u1); the validator requires the format below 4 and the sort value plus one at most 3. The numbers are read and written through number scopes 11 and 12 (index + 0xf).

## Players and slots

Player slot values: 1 to 16 in the stream correspond to player slots 0 to 15 (`function_485e8`); fireteam indexes are bytes at the player datum +0x48c with -1 meaning none (operation 63 accepts 0 to 16).

## Operation 21 and HaloScript

Operation 21 and the `mp_*` natives call the same end-of-round routine `function_7b3ec`.
