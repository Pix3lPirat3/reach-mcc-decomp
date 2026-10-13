# HaloScript natives, slots 1411 to 1881

Part of the HaloScript reference (see the index). Each entry describes one slot of the function table at RVA 0xa28d40. Names, return types and parameter types come from the table strings; behavior is read from the evaluator code. Engine functions are given by address (function_RVA) and module globals as data_RVA. "Not determined" marks where the code was not followed far enough to say. Behavior lists the calls an evaluator can make, in order; a listed call may depend on the arguments or on state, and the text says so where that was checked. In Behavior, a0, a1, ... name the arguments in call order starting at zero.

In this range: 471 slots; 141 implemented, 11 with arguments evaluated and no other effect, 319 not implemented.

Calling convention shared by all evaluators here: the evaluator receives the function index, the script thread handle and a flag byte; function_865e8 evaluates the arguments and returns a pointer to them (or null while an argument still needs evaluation, in which case the evaluator returns at once and is entered again later); the arguments are consecutive 32-bit values, a boolean is one byte at the start of its value; function_85de0 hands the result back to the script thread. "Nothing is returned" below means the evaluator hands back 0 for a void function. A per-thread block offset such as "per-thread offset 0x320" is an offset into the static thread-local block of the module (reached through the thread environment block and the module thread-local index). Names of the form data_RVA are module globals; function_RVA are engine functions by address.

## State blocks used by the natives in this range

Each row names a per-thread offset, the fields the natives here read or write, and the evidence. Offsets inside a per-player stride can exceed the stride, so no origin of the per-player structure is claimed.

| Per-thread offset | Fields seen in this range |
|---|---|
| 0x10 | Object header array: 24-byte entries in the array at +0x50, payload pointer at entry offset 0x10, type byte at entry offset 4 (V) |
| 0x18 | Players array (the in-game players iterator walks it); per-player team byte at +0xac and unit handle at +0x28 of a 0x490-byte entry (V) |
| 0x20 | Game engine state block: survival set counter +0x18c, wave counter +0x190, set multiplier +0x1d4, bonus multiplier +0x1d8, pregame byte +0x1dc, license plate records +0x2e0 to +0x304, accumulators +0x220, +0x260, +0x2a0, fade mask +0x35c0 (V) |
| 0x48 | Game block: byte +0x11 holds a mode value (4 or 5 is tested before marking replication flags), +0x1d9 playtest byte, +0x1da, +0x1eab0, +0x1eab8, +0x1eac0, +0x110ed (V) |
| 0xa0 | Game time block: byte +0 active flag, short +6 ticks per second, real +8 (seconds per tick), dword +0xc (appears to be the current game tick, H) |
| 0xd8 | Player control block: entries per local player index; fields seen on this page are dword +0x1fc and byte +0x1ec of the entry at index * 0x180 (V) |
| 0xe0 | Cinematic display state: real +0 letterbox amount, byte +4 letterbox flag, byte +6 skip started, byte +7 suppress object creation, byte +0x23 (V) |
| 0x158 | Player mapping block: used to find each local player of the session (V) |
| 0x168 | Pointer to a render option byte: bit 0 motion blur, bit 1 antialias blur, bit 2 atmosphere fog, bit 3 patchy fog, bit 4 ssao, bit 6 planar fog, bit 7 vsync disable (V) |
| 0x188 | Director globals block: one 0x1ac-byte entry per camera output index (V) |
| 0x1d8 | Scripted exposure block: flags dword +0 (bit 2 is set by the exposure fades and by cinematic scene destruction, bit 3 enables autoexposure), reals +0xc to +0x23, dword +0x20, start tick +0x24, end tick +0x28 (V) |
| 0x1f0 | Airstrike block: byte +0 holds the enable flag (V) |
| 0x230 | hs runtime globals: byte +0 non-zero while scripts run, current thread handle at +8 (V) |
| 0x2e8 | Depth of field block: byte +0 enable flag, byte +1 cleared when the flag is written (V) |
| 0x320 | Campaign objectives: ten 8-byte entries starting at +4 (state byte), states set here are 2 (shown) and 3 (finished) (V) |
| 0x440 | Lasing datum array: each entry holds an object handle at +8 (V) |
| 0x5c0 | Interpolator states block: dword +0 start tick, byte +4 active flag, dword +8 (V) |
| 0x688 | Observer globals block: byte +0x104a is a one-frame cache request flag (V) |

### objectives_finish
- Slot: 1411 (table entry 0xa0e400)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b5338 (105 bytes)
- Behavior: Entries live in the campaign objectives block (per-thread offset 0x320, 160 bytes): ten primary entries of 8 bytes (string id dword at +0, state byte at +4) followed by ten secondary entries at +0x50 (string id at +0x50+8*i, state byte at +0x54+8*i). The index is range checked as an unsigned value against 9, so negative or larger values do nothing. Writes state 3 to the state byte of primary entry INDEX. Nothing else is changed; nothing is returned.
- Evidence: V

### objectives_unavailable
- Slot: 1412 (table entry 0xa0e3b0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b53a4 (105 bytes)
- Behavior: Entries live in the campaign objectives block (per-thread offset 0x320, 160 bytes): ten primary entries of 8 bytes (string id dword at +0, state byte at +4) followed by ten secondary entries at +0x50 (string id at +0x50+8*i, state byte at +0x54+8*i). The index is range checked as an unsigned value against 9, so negative or larger values do nothing. Writes state 1 to the state byte of primary entry INDEX.
- Evidence: V

### objectives_secondary_show
- Slot: 1413 (table entry 0xa0e360)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b5410 (105 bytes)
- Behavior: Entries live in the campaign objectives block (per-thread offset 0x320, 160 bytes): ten primary entries of 8 bytes (string id dword at +0, state byte at +4) followed by ten secondary entries at +0x50 (string id at +0x50+8*i, state byte at +0x54+8*i). The index is range checked as an unsigned value against 9, so negative or larger values do nothing. Writes state 2 to the state byte of secondary entry INDEX.
- Evidence: V

### objectives_secondary_finish
- Slot: 1414 (table entry 0xa0e4f0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b547c (105 bytes)
- Behavior: Entries live in the campaign objectives block (per-thread offset 0x320, 160 bytes): ten primary entries of 8 bytes (string id dword at +0, state byte at +4) followed by ten secondary entries at +0x50 (string id at +0x50+8*i, state byte at +0x54+8*i). The index is range checked as an unsigned value against 9, so negative or larger values do nothing. Writes state 3 to the state byte of secondary entry INDEX.
- Evidence: V

### objectives_secondary_unavailable
- Slot: 1415 (table entry 0xa0e4a0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b54e8 (105 bytes)
- Behavior: Entries live in the campaign objectives block (per-thread offset 0x320, 160 bytes): ten primary entries of 8 bytes (string id dword at +0, state byte at +4) followed by ten secondary entries at +0x50 (string id at +0x50+8*i, state byte at +0x54+8*i). The index is range checked as an unsigned value against 9, so negative or larger values do nothing. Writes state 1 to the state byte of secondary entry INDEX.
- Evidence: V

### objectives_set_string
- Slot: 1416 (table entry 0xa0e450)
- Returns: void
- Parameters: a0: long, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b5554 (105 bytes)
- Behavior: Entries live in the campaign objectives block (per-thread offset 0x320, 160 bytes): ten primary entries of 8 bytes (string id dword at +0, state byte at +4) followed by ten secondary entries at +0x50 (string id at +0x50+8*i, state byte at +0x54+8*i). The index is range checked as an unsigned value against 9, so negative or larger values do nothing. Stores the string id (second argument) in the string id field of primary entry INDEX. The state byte is not touched.
- Evidence: V

### objectives_secondary_set_string
- Slot: 1417 (table entry 0xa0e220)
- Returns: void
- Parameters: a0: long, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b55c0 (106 bytes)
- Behavior: Entries live in the campaign objectives block (per-thread offset 0x320, 160 bytes): ten primary entries of 8 bytes (string id dword at +0, state byte at +4) followed by ten secondary entries at +0x50 (string id at +0x50+8*i, state byte at +0x54+8*i). The index is range checked as an unsigned value against 9, so negative or larger values do nothing. Stores the string id (second argument) in the string id field of secondary entry INDEX. The state byte is not touched.
- Evidence: V

### objectives_show_string
- Slot: 1418 (table entry 0xa0e1d0)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b562c (111 bytes)
- Behavior: Finds the primary objective whose stored string id equals the argument and writes state 2 to its state byte (campaign objectives block at per-thread offset 0x320, ten 8-byte entries: string id dword at +0, state byte at +4). The entry is found by function_2e7ba8 (scans the ten primary entries and returns the highest index whose stored string id equals the argument, or -1); the result is range checked as unsigned against 9, so an unknown string id does nothing.
- Evidence: V

### objectives_finish_string
- Slot: 1419 (table entry 0xa0e310)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b569c (111 bytes)
- Behavior: Finds the primary objective whose stored string id equals the argument and writes state 3 to its state byte. The entry is found by function_2e7ba8 (scans the ten primary entries and returns the highest index whose stored string id equals the argument, or -1); the result is range checked as unsigned against 9, so an unknown string id does nothing.
- Evidence: V

### objectives_unavailable_string
- Slot: 1420 (table entry 0xa0e2c0)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b570c (111 bytes)
- Behavior: Finds the primary objective whose stored string id equals the argument and writes state 1 to its state byte. The entry is found by function_2e7ba8 (scans the ten primary entries and returns the highest index whose stored string id equals the argument, or -1); the result is range checked as unsigned against 9, so an unknown string id does nothing.
- Evidence: V

### objectives_secondary_show_string
- Slot: 1421 (table entry 0xa0e270)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b577c (111 bytes)
- Behavior: Finds the secondary objective whose stored string id equals the argument and writes state 2 to its state byte (secondary entries start at +0x50 of the campaign objectives block, state byte at +0x54+8*i). The entry is found by function_2e7bec (same scan over the ten secondary entries at +0x50, highest matching index or -1); the result is range checked as unsigned against 9, so an unknown string id does nothing.
- Evidence: V

### objectives_secondary_finish_string
- Slot: 1422 (table entry 0xa0e060)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b57ec (111 bytes)
- Behavior: Finds the secondary objective whose stored string id equals the argument and writes state 3 to its state byte. The entry is found by function_2e7bec (same scan over the ten secondary entries at +0x50, highest matching index or -1); the result is range checked as unsigned against 9, so an unknown string id does nothing.
- Evidence: V

### objectives_secondary_unavailable_string
- Slot: 1423 (table entry 0xa0e010)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b585c (111 bytes)
- Behavior: Finds the secondary objective whose stored string id equals the argument and writes state 1 to its state byte. The entry is found by function_2e7bec (same scan over the ten secondary entries at +0x50, highest matching index or -1); the result is range checked as unsigned against 9, so an unknown string id does nothing.
- Evidence: V

### input_suppress_rumble
- Slot: 1424 (table entry 0xa0dfc0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b58cc (69 bytes)
- Behavior: Copies the boolean argument (one byte) into the global byte at data_2dfbe85. No other state is touched and nothing is returned. Readers of the byte were not traced.
- Evidence: V

### input_disable_claw_button_combos
- Slot: 1425 (table entry 0xa0e180)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### update_remote_camera
- Slot: 1426 (table entry 0xa0e140)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_build_network_config
- Slot: 1427 (table entry 0xa0e100)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_build_game_variant
- Slot: 1428 (table entry 0xa0e0b0)
- Returns: void
- Parameters: a0: boolean, a1: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_verify_game_variant
- Slot: 1429 (table entry 0xa0de40)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_load_and_use_game_variant
- Slot: 1430 (table entry 0xa0ddf0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_use_hopper_directory
- Slot: 1431 (table entry 0xa0dda0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_quality_dump
- Slot: 1432 (table entry 0xa0dd60)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_quality_clear
- Slot: 1433 (table entry 0xa0df80)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_quality_set_connection_badness_history
- Slot: 1434 (table entry 0xa0df30)
- Returns: void
- Parameters: a0: boolean, a1: short
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_quality_set_squad_host_badness_history
- Slot: 1435 (table entry 0xa0dee0)
- Returns: void
- Parameters: a0: boolean, a1: short
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_quality_set_squad_client_badness_history
- Slot: 1436 (table entry 0xa0de90)
- Returns: void
- Parameters: a0: boolean, a1: short
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_quality_set_squad_speculative_migration_badness_history
- Slot: 1437 (table entry 0xa0dbe0)
- Returns: void
- Parameters: a0: boolean, a1: short
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_quality_set_squad_bridging_badness_history
- Slot: 1438 (table entry 0xa0db90)
- Returns: void
- Parameters: a0: boolean, a1: short
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_quality_set_group_host_badness_history
- Slot: 1439 (table entry 0xa0db40)
- Returns: void
- Parameters: a0: boolean, a1: short
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_quality_set_group_client_badness_history
- Slot: 1440 (table entry 0xa0daf0)
- Returns: void
- Parameters: a0: boolean, a1: short
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_quality_set_group_speculative_migration_badness_history
- Slot: 1441 (table entry 0xa0dd10)
- Returns: void
- Parameters: a0: boolean, a1: short
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_quality_set_group_bridging_badness_history
- Slot: 1442 (table entry 0xa0dcc0)
- Returns: void
- Parameters: a0: boolean, a1: short
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_status_filter
- Slot: 1443 (table entry 0xa0dc70)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_test_ping
- Slot: 1444 (table entry 0xa0dc30)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_test_channel_delete
- Slot: 1445 (table entry 0xa0d980)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_test_delegate_host
- Slot: 1446 (table entry 0xa0d930)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_test_delegate_leader
- Slot: 1447 (table entry 0xa0d8e0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_test_map_name
- Slot: 1448 (table entry 0xa0d890)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_test_variant
- Slot: 1449 (table entry 0xa0daa0)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_test_campaign_difficulty
- Slot: 1450 (table entry 0xa0da50)
- Returns: void
- Parameters: a0: short
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_test_player_color
- Slot: 1451 (table entry 0xa0da00)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_test_reset_objects
- Slot: 1452 (table entry 0xa0d9c0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_test_fatal_error
- Slot: 1453 (table entry 0xa0d710)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### events_enabled
- Slot: 1454 (table entry 0xa0d6c0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### events_suppression
- Slot: 1455 (table entry 0xa0d670)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### events_suppress_display
- Slot: 1456 (table entry 0xa0d620)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### events_global_display
- Slot: 1457 (table entry 0xa0d840)
- Returns: void
- Parameters: a0: event
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### events_global_log
- Slot: 1458 (table entry 0xa0d7f0)
- Returns: void
- Parameters: a0: event
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### events_global_debugger
- Slot: 1459 (table entry 0xa0d7a0)
- Returns: void
- Parameters: a0: event
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### events_global_datamine
- Slot: 1460 (table entry 0xa0d750)
- Returns: void
- Parameters: a0: event
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### events_category_display
- Slot: 1461 (table entry 0xa0d490)
- Returns: void
- Parameters: a0: string, a1: event
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### events_category_force_display
- Slot: 1462 (table entry 0xa0d440)
- Returns: void
- Parameters: a0: string, a1: event
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### events_category_log
- Slot: 1463 (table entry 0xa0d3f0)
- Returns: void
- Parameters: a0: string, a1: event
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### events_category_debugger
- Slot: 1464 (table entry 0xa0d3a0)
- Returns: void
- Parameters: a0: string, a1: event
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### events_category_debugger_break
- Slot: 1465 (table entry 0xa0d5d0)
- Returns: void
- Parameters: a0: string, a1: event
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### events_category_halt
- Slot: 1466 (table entry 0xa0d580)
- Returns: void
- Parameters: a0: string, a1: event
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### events_category_datamine
- Slot: 1467 (table entry 0xa0d530)
- Returns: void
- Parameters: a0: string, a1: event
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### events_list_categories
- Slot: 1468 (table entry 0xa0d4e0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### event_logs_snapshot
- Slot: 1469 (table entry 0xa0d220)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### events_disable_suppression
- Slot: 1470 (table entry 0xa0d1d0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### event_global_display_category
- Slot: 1471 (table entry 0xa0d180)
- Returns: void
- Parameters: a0: event
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### event_global_log_category
- Slot: 1472 (table entry 0xa0d130)
- Returns: void
- Parameters: a0: event
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### event_global_remote_log_category
- Slot: 1473 (table entry 0xa0d350)
- Returns: void
- Parameters: a0: event
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### event_display_category
- Slot: 1474 (table entry 0xa0d300)
- Returns: void
- Parameters: a0: string, a1: event
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### event_force_display_category
- Slot: 1475 (table entry 0xa0d2b0)
- Returns: void
- Parameters: a0: string, a1: event
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### event_debugger_break_category
- Slot: 1476 (table entry 0xa0d260)
- Returns: void
- Parameters: a0: string, a1: event
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### event_halt_category
- Slot: 1477 (table entry 0xa0cfc0)
- Returns: void
- Parameters: a0: string, a1: event
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### event_list_categories
- Slot: 1478 (table entry 0xa0cf70)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### events_suppress_console_display
- Slot: 1479 (table entry 0xa0cf20)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### play_bink_movie
- Slot: 1480 (table entry 0xa0ced0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: implemented
- Evaluator: function_1b5914 (194 bytes)
- Behavior: Starts a movie by name. The name is resolved through function_1990a0 (script string data pointer) and expanded by function_2d7908 into a movie path buffer (format string at 0xa35dc0 filled with the game data directory from function_d928 and the name; when the host object at data_c1a100 exists its virtual function at +0x180 is also called with (4, path, 0x100); the role of that host call was not determined). function_2d7908 always returns true. If the global flag bytes data_2881ba1 and data_2881ba0 show a movie already active, function_d7fd4 is called first to stop it. If no movie is active afterwards, function_d9484 is called with (path, -1, 0x1e) to start playback. Nothing is returned.
- Evidence: V

### play_bink_movie_from_tag
- Slot: 1481 (table entry 0xa0d0e0)
- Returns: void
- Parameters: a0: bink_definition
- Kind: normal
- Status: implemented
- Evaluator: function_1b59d8 (138 bytes)
- Behavior: Starts a movie from a tag reference. If the global flag bytes data_2881ba1 and data_2881ba0 show a movie already active, function_d7fd4 is called first to stop it. If no movie is active afterwards, function_d9484 is called with (null path, the tag handle argument, 0x1000) to start playback. Nothing is returned.
- Evidence: V

### play_credits_skip_to_menu
- Slot: 1482 (table entry 0xa0d0a0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b5a64 (118 bytes)
- Behavior: Starts the credits movie. Builds a movie path with function_2d7908 from the fixed name string at 0xa35dd8, calls function_d9484 with (path, -1, 0x241e) when that succeeds, then sets the global byte data_2881ba6 to 1 whether or not a movie started. Nothing is returned.
- Evidence: V

### bink_time
- Slot: 1483 (table entry 0xa0d060)
- Returns: long
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b5adc (111 bytes)
- Behavior: Returns a movie playback time in game ticks. With no movie record (data_2881d20 null) the result is 0. Otherwise, with m = the record, it computes t = ((m.dword18 * m.dword8 * 1000) / m.dword14) * (m.dword8 - m.dwordC) / max(m.dword8, 1) using unsigned integer division, converts t to float, divides by 1000.0 and passes the result to function_81b08 (seconds to ticks); a result of zero or less is returned as 0.
- Evidence: V

### set_global_doppler_factor
- Slot: 1484 (table entry 0xa0d010)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Arguments are evaluated and then the value 0 is handed back as the result; nothing else happens. The evaluator is the shared function_199364, so a call has no effect beyond evaluating its argument expressions.
- Evidence: V

### set_global_mixbin_headroom
- Slot: 1485 (table entry 0xa0cd60)
- Returns: void
- Parameters: a0: long, a1: long
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Arguments are evaluated and then the value 0 is handed back as the result; nothing else happens. The evaluator is the shared function_199364, so a call has no effect beyond evaluating its argument expressions.
- Evidence: V

### debug_sound_environment_source_parameter
- Slot: 1486 (table entry 0xa0cd10)
- Returns: void
- Parameters: a0: long, a1: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### data_mine_set_mission_segment
- Slot: 1487 (table entry 0xa0ccc0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: implemented
- Evaluator: function_1b5b4c (77 bytes)
- Behavior: Resolves the string argument with function_1990a0 and passes it to function_db578. function_db578 does nothing when the host object data_c1a100 is null. Otherwise it computes an Adler-32 checksum of the string and, for each local player found through the player mapping block (per-thread offset 0x158), hands the checksum and per-player data to virtual functions of the host object (+0x50, +0x498, +0x338) when it differs from the value stored at data_4e2fee0. The purpose of the host calls was not determined.
- Evidence: S

### data_mine_insert
- Slot: 1488 (table entry 0xa0cc70)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Arguments are evaluated and then the value 0 is handed back as the result; nothing else happens. The evaluator is the shared function_199364, so a call has no effect beyond evaluating its argument expressions.
- Evidence: V

### data_mine_upload
- Slot: 1489 (table entry 0xa0ce90)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### data_mine_enable
- Slot: 1490 (table entry 0xa0ce40)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Arguments are evaluated and then the value 0 is handed back as the result; nothing else happens. The evaluator is the shared function_199364, so a call has no effect beyond evaluating its argument expressions.
- Evidence: V

### data_mine_flush
- Slot: 1491 (table entry 0xa0ce00)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### data_mine_debug_menu_setting
- Slot: 1492 (table entry 0xa0cdb0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Arguments are evaluated and then the value 0 is handed back as the result; nothing else happens. The evaluator is the shared function_199364, so a call has no effect beyond evaluating its argument expressions.
- Evidence: V

### data_mine_open_debug_menu
- Slot: 1493 (table entry 0xa0cb10)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### data_mine_set_display_mission_segment
- Slot: 1494 (table entry 0xa0cac0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### data_mine_set_header_flag
- Slot: 1495 (table entry 0xa0ca70)
- Returns: void
- Parameters: a0: long, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### test_memory_allocators (slot 1496)
- Slot: 1496 (table entry 0xa0ca20)
- Returns: void
- Parameters: a0: long, a1: short, a2: short, a3: short, a4: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### test_memory_allocators (slot 1497)
- Slot: 1497 (table entry 0xa0cc20)
- Returns: void
- Parameters: a0: long, a1: short, a2: short, a3: short, a4: long, a5: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### display_video_standard
- Slot: 1498 (table entry 0xa0cbe0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### test_xcr_monkey_enable
- Slot: 1499 (table entry 0xa0cb90)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### test_show_guide_status
- Slot: 1500 (table entry 0xa0cb50)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### test_show_users_xuids
- Slot: 1501 (table entry 0xa0c8a0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### test_show_are_users_friends
- Slot: 1502 (table entry 0xa0c850)
- Returns: void
- Parameters: a0: long, a1: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### test_invite_friend
- Slot: 1503 (table entry 0xa0c800)
- Returns: void
- Parameters: a0: long, a1: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### test_get_squad_session_id
- Slot: 1504 (table entry 0xa0c7c0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cui_get_active_screens
- Slot: 1505 (table entry 0xa0c9d0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cui_get_screen_components
- Slot: 1506 (table entry 0xa0c980)
- Returns: void
- Parameters: a0: long, a1: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cui_get_component_properties
- Slot: 1507 (table entry 0xa0c930)
- Returns: void
- Parameters: a0: long, a1: long, a2: string_id
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cui_send_button_press
- Slot: 1508 (table entry 0xa0c8e0)
- Returns: void
- Parameters: a0: long, a1: long, a2: long, a3: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cui_invoke_list_item_by_string_id
- Slot: 1509 (table entry 0xa0c640)
- Returns: void
- Parameters: a0: long, a1: long, a2: string_id, a3: string_id, a4: string_id, a5: string_id
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cui_invoke_list_item_by_long
- Slot: 1510 (table entry 0xa0c5f0)
- Returns: void
- Parameters: a0: long, a1: long, a2: string_id, a3: string_id, a4: string_id, a5: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cui_invoke_list_item_by_boolean
- Slot: 1511 (table entry 0xa0c5a0)
- Returns: void
- Parameters: a0: long, a1: long, a2: string_id, a3: string_id, a4: string_id, a5: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cui_invoke_list_item_by_text
- Slot: 1512 (table entry 0xa0c550)
- Returns: void
- Parameters: a0: long, a1: long, a2: string_id, a3: string_id, a4: string_id, a5: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### test_download_storage_file
- Slot: 1513 (table entry 0xa0c770)
- Returns: void
- Parameters: a0: string, a1: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### test_game_results_save_to_file
- Slot: 1514 (table entry 0xa0c720)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### test_game_results_load_from_file
- Slot: 1515 (table entry 0xa0c6d0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### test_game_results_make_random
- Slot: 1516 (table entry 0xa0c690)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### test_fragment_utility_drive
- Slot: 1517 (table entry 0xa0c3c0)
- Returns: void
- Parameters: a0: long, a1: long, a2: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### flag_new
- Slot: 1518 (table entry 0xa0c370)
- Returns: void
- Parameters: a0: string, a1: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### flag_new_at_look
- Slot: 1519 (table entry 0xa0c320)
- Returns: void
- Parameters: a0: string, a1: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### flags_clear
- Slot: 1520 (table entry 0xa0c2e0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### flags_default_name
- Slot: 1521 (table entry 0xa0c500)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### flags_default_comment
- Slot: 1522 (table entry 0xa0c4b0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### flags_set_filter
- Slot: 1523 (table entry 0xa0c460)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### bug_now
- Slot: 1524 (table entry 0xa0c410)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### bug_now_lite
- Slot: 1525 (table entry 0xa0c160)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### bug_now_auto
- Slot: 1526 (table entry 0xa0c110)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### bug_now_on_next_kill
- Slot: 1527 (table entry 0xa0c0c0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### object_list_children
- Slot: 1528 (table entry 0xa0c070)
- Returns: object_list
- Parameters: a0: object, a1: object_definition
- Kind: normal
- Status: implemented
- Evaluator: function_1b5b9c (180 bytes)
- Behavior: Builds a list of the child objects of an object. If the object handle is -1 the result is -1. Otherwise function_192960 allocates a new object list (a failed allocation also yields -1). The object data is found through the object datum array (per-thread offset 0x10); if its dword at +0x10 is -1 (no first child) the empty list is returned, otherwise function_47bfe8 is called with (that first child handle, the object definition argument, the list) to add the matching children. The result is the list handle.
- Evidence: V

### ai_selected_actor_jump
- Slot: 1529 (table entry 0xa0c290)
- Returns: void
- Parameters: a0: real, a1: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### dump_loaded_tags
- Slot: 1530 (table entry 0xa0c250)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### interpolator_start
- Slot: 1531 (table entry 0xa0c200)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b5c50 (68 bytes)
- Behavior: Calls function_165c64 with the string id. A zero id does nothing. Otherwise function_1660c8 looks the id up in the scenario interpolator table (entries of 0x34 bytes, found through the scenario tag data block at +0x698); if found, the matching state record in the interpolator states block (per-thread offset 0x5c0) is initialised: dword +0 = game tick (game time block +0xc), byte +4 = 1, and dword +8 = 0 when the definition dword at +0x28 is zero. An unknown id changes nothing.
- Evidence: S

### interpolator_stop
- Slot: 1532 (table entry 0xa0c1b0)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b5c94 (68 bytes)
- Behavior: Calls function_165cd4 with the string id. A zero id does nothing. Otherwise the interpolator is looked up with function_1660c8 and, by the definition dword at +0x2c, its state record is set: 0 = byte +4 is 1 and value +8 is 0.0; 1 = byte +4 is 1 and value +8 is the current interpolated value (computed from the game time and definition, wrapped with fmodf when definition bit 0 is set, otherwise clamped to 0.0..1.0); 2 = byte +4 is 1 and value +8 is 1.0; 3 = byte +4 is 0 and value +8 is the definition dword at +0x30. Finally dword +0 of the state record is set to -1. An unknown id changes nothing.
- Evidence: S

### interpolator_stop_all
- Slot: 1533 (table entry 0xa0bf50)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b5cd8 (163 bytes)
- Behavior: Stops every interpolator of the scenario: walks the scenario tag block at +0x698 (0x34-byte entries, count in its first dword) and calls function_165cd4 with the id stored at +4 of each entry. Does nothing if the scenario pointer or the block is missing.
- Evidence: S

### interpolator_dump
- Slot: 1534 (table entry 0xa0bf00)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b5d7c (82 bytes)
- Behavior: Calls function_1660c8 with the string id (the lookup helper used by the other interpolator natives); the two outputs go to stack buffers that are not read afterwards. A zero id is skipped. The call has no other effect.
- Evidence: S

### interpolator_dump_all
- Slot: 1535 (table entry 0xa0bec0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### set_pc_runtime_language
- Slot: 1536 (table entry 0xa0be70)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### animation_cache_stats_reset
- Slot: 1537 (table entry 0xa0c030)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cinematic_clone_players_weapon
- Slot: 1538 (table entry 0xa0bfe0)
- Returns: void
- Parameters: a0: object, a1: string_id, a2: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b5dd0 (75 bytes)
- Behavior: Passes the object handle and the two string ids to function_d3abc. The effects inside function_d3abc were not decoded.
- Evidence: S

### cinematic_move_attached_objects
- Slot: 1539 (table entry 0xa0bf90)
- Returns: void
- Parameters: a0: object, a1: string_id, a2: string_id, a3: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b5e1c (79 bytes)
- Behavior: Passes the object handle and the three string ids to function_d3e6c. The effects inside function_d3e6c were not decoded.
- Evidence: S

### vehicle_enable_ghost_effects
- Slot: 1540 (table entry 0xa0bd00)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Arguments are evaluated and then the value 0 is handed back as the result; nothing else happens. The evaluator is the shared function_199364, so a call has no effect beyond evaluating its argument expressions.
- Evidence: V

### set_global_sound_environment
- Slot: 1541 (table entry 0xa0bcb0)
- Returns: void
- Parameters: a0: real, a1: real, a2: real, a3: real, a4: long, a5: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b5e6c (105 bytes)
- Behavior: Builds a message of type 0x11 on the stack (the first four reals copied to message bytes +0x18..+0x27, the long at +0x28, the last real at +0x2c) and passes it to function_bc170, which adds it to the game sound message queue. Nothing is returned.
- Evidence: V

### game_save_cinematic_skip
- Slot: 1542 (table entry 0xa0bc70)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b5ed8 (32 bytes)
- Behavior: Calls function_1664e0 with argument 4 (a game save request). Nothing is returned.
- Evidence: V

### cinematic_outro_start
- Slot: 1543 (table entry 0xa0bc30)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b5ef8
- Behavior: Sets byte +0x22 of the cinematic globals block (per-thread offset 0xe0) to 1. Nothing is returned.
- Evidence: V

### cinematic_enable_ambience_details
- Slot: 1544 (table entry 0xa0be20)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b5f28 (76 bytes)
- Behavior: Copies the boolean argument into byte +0xa1 of the structure pointed to by data_c1a3e8. Nothing is returned.
- Evidence: V

### cache_block_for_one_frame
- Slot: 1545 (table entry 0xa0bde0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b5f74
- Behavior: Sets byte +0x104a of the observer globals block (per-thread offset 0x688) to 1. Nothing is returned.
- Evidence: V

### sound_suppress_ambience_update_on_revert
- Slot: 1546 (table entry 0xa0bda0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b5fa4 (40 bytes)
- Behavior: Builds a message of type 0x12 on the stack (only the type dword is set; the rest of the message is whatever the stack held) and passes it to function_bc170 (game sound message queue). Nothing is returned.
- Evidence: V

### render_autoexposure_enable
- Slot: 1547 (table entry 0xa0bd50)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b5fcc (102 bytes)
- Behavior: Sets or clears bit 3 (value 8) of the first dword of the scripted exposure block (per-thread offset 0x1d8) depending on whether the boolean argument is non-zero. Nothing is returned.
- Evidence: V

### render_exposure_full
- Slot: 1548 (table entry 0xa0baf0)
- Returns: void
- Parameters: a0: real, a1: real, a2: real, a3: real, a4: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b6034 (167 bytes)
- Behavior: Sets bit 2 of the first dword of the scripted exposure block, copies the first four reals to +0x14..+0x23, stores the current game tick in +0x24 and stores in +0x28 the tick plus ceilf(fifth real * the 16-bit value at game time block +6). Fields are in the scripted exposure block (per-thread offset 0x1d8). The game time block (per-thread offset 0xa0) supplies the current tick dword at +0xc, and its 16-bit value at +6 is multiplied with the seconds argument to get ticks.
- Evidence: V

### render_exposure_fade_in
- Slot: 1549 (table entry 0xa0baa0)
- Returns: void
- Parameters: a0: real, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b60dc (75 bytes)
- Behavior: Passes its two reals to function_25dc08 (first real, second real). Shared by render_exposure_fade_in and render_exposure; both natives run this same code. Same evaluator as render_exposure.
- Evidence: S

### render_exposure_fade_out
- Slot: 1550 (table entry 0xa0bbe0)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b6128 (188 bytes)
- Behavior: Sets bit 2 of the first dword of the scripted exposure block, copies +0xc to +0x1c, clears +0x20, copies +0x10 to +0x14 and +0x18, stores the current game tick in +0x24 and stores in +0x28 the tick plus ceilf(argument * the 16-bit value at game time block +6). Fields are in the scripted exposure block (per-thread offset 0x1d8). The game time block (per-thread offset 0xa0) supplies the current tick dword at +0xc, and its 16-bit value at +6 is multiplied with the seconds argument to get ticks.
- Evidence: V

### render_exposure
- Slot: 1551 (table entry 0xa0bb90)
- Returns: void
- Parameters: a0: real, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b60dc (75 bytes)
- Behavior: Passes its two reals to function_25dc08 (first real, second real). Shared by render_exposure_fade_in and render_exposure; both natives run this same code. Same evaluator as render_exposure_fade_in.
- Evidence: S

### render_autoexposure_instant
- Slot: 1552 (table entry 0xa0bb40)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b61e4 (134 bytes)
- Behavior: Stores (the 16-bit value at game time block +6 divided by 30) * the long argument into dword +0x2c of the scripted exposure block. Nothing is returned.
- Evidence: V

### render_exposure_set_environment_darken
- Slot: 1553 (table entry 0xa0b9b0)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b626c (135 bytes)
- Behavior: Stores the negated real argument in +8 of the scripted exposure block and powf(2.0, argument) in +4. Nothing is returned.
- Evidence: V

### render_depth_of_field_enable
- Slot: 1554 (table entry 0xa0b960)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b62f4 (98 bytes)
- Behavior: Writes the boolean argument to byte +0 and 0 to byte +1 of the depth of field block (per-thread offset 0x2e8). Nothing is returned.
- Evidence: V

### render_depth_of_field
- Slot: 1555 (table entry 0xa0b910)
- Returns: void
- Parameters: a0: real, a1: real, a2: real, a3: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b6358 (224 bytes)
- Behavior: Only acts when function_586c4 returns true (it reads the game globals block at per-thread offset 0x48 and returns 1 when byte +0x1eab0 is non-zero, byte +0 is 0 and byte +1 is non-zero). Then, in the depth of field block (per-thread offset 0x2e8), sets bytes +0 and +1 to 1, stores the first real at +8 and the second at +0xc, stores 1.0 / max(third real, 0.001) at +0x10, stores the game tick in +0x24 and the tick plus ceilf(fourth real * the 16-bit value at game time block +6) in +0x28, and clears +0x2c. Nothing is returned.
- Evidence: V

### render_dof_focus_depth
- Slot: 1556 (table entry 0xa0ba50)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b6438 (123 bytes)
- Behavior: Stores 1.0 / max(argument, 0.001) at +0x10 of the depth of field block (per-thread offset 0x2e8). Nothing is returned.
- Evidence: V

### render_dof_blur_animate
- Slot: 1557 (table entry 0xa0ba00)
- Returns: void
- Parameters: a0: real, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b64b4 (157 bytes)
- Behavior: In the depth of field block (per-thread offset 0x2e8): copies dword +0x30 to +0x14, stores the first real at +0x18, stores the game tick at +0x1c and the tick plus ceilf(second real * the 16-bit value at game time block +6) at +0x20. Nothing is returned.
- Evidence: V

### predict_animation
- Slot: 1558 (table entry 0xa0b790)
- Returns: void
- Parameters: a0: animation_graph, a1: string_id
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Arguments are evaluated and then the value 0 is handed back as the result; nothing else happens. The evaluator is the shared function_199364, so a call has no effect beyond evaluating its argument expressions.
- Evidence: V

### mp_player_count_by_team
- Slot: 1559 (table entry 0xa0b740)
- Returns: long
- Parameters: a0: mp_team
- Kind: normal
- Status: implemented
- Evaluator: function_1b6554 (177 bytes)
- Behavior: Counts players by team. A team argument above 7 (unsigned) returns 0. Otherwise it iterates players with function_4a380 (iterator over the players datum array, per-thread offset 0x18) and for each calls function_1360cc, then counts those whose signed byte at +1 of the returned structure equals the argument. Returns the count.
- Evidence: V

### mp_players_by_team
- Slot: 1560 (table entry 0xa0b6f0)
- Returns: object_list
- Parameters: a0: mp_team
- Kind: normal
- Status: implemented
- Evaluator: function_1b6608 (68 bytes)
- Behavior: Returns the object list handle produced by function_18f3e4 for the team argument (no range check in the evaluator).
- Evidence: S

### mp_active_player_count_by_team
- Slot: 1561 (table entry 0xa0b6a0)
- Returns: long
- Parameters: a0: mp_team
- Kind: normal
- Status: implemented
- Evaluator: function_1b664c (208 bytes)
- Behavior: Counts players by team. A team argument above 7 (unsigned) returns 0. Otherwise it walks the players datum array (per-thread offset 0x18) with function_13870 and counts the entries whose signed team byte at +0xad equals the argument and for which either the dword at +0x28 is not -1 or the word at +0x2ee is greater than 0. Returns the count.
- Evidence: V

### deterministic_end_game
- Slot: 1562 (table entry 0xa0b8d0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b671c (84 bytes)
- Behavior: Does nothing unless function_586c4 returns true, the game globals block (per-thread offset 0x48) has byte +0x10 equal to 3 and byte +0x11 not equal to 4; then it calls function_3a3c40(1, 0, 0). Nothing is returned.
- Evidence: V

### mp_game_won
- Slot: 1563 (table entry 0xa0b880)
- Returns: void
- Parameters: a0: mp_team
- Kind: normal
- Status: implemented
- Evaluator: function_1b6770 (180 bytes)
- Behavior: Acts only when the game engine globals (per-thread offset 0x20) have dword +0x841c in 1..4, the pointer at data_b95f78[index] is non-null and bit 3 (value 8) of the first byte of the block is set, and byte +0x11 of the game globals block (per-thread offset 0x48) is not 4 and the team argument is at most 7 (unsigned); then calls function_7b3ec(team, 1, 1). Nothing is returned.
- Evidence: V

### mp_respawn_override_timers
- Slot: 1564 (table entry 0xa0b830)
- Returns: void
- Parameters: a0: mp_team
- Kind: normal
- Status: implemented
- Evaluator: function_1b6824 (68 bytes)
- Behavior: Calls function_18f490 with the team argument. Nothing is returned.
- Evidence: S

### mp_ai_allegiance
- Slot: 1565 (table entry 0xa0b7e0)
- Returns: void
- Parameters: a0: team, a1: mp_team
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Arguments are evaluated and then the value 0 is handed back as the result; nothing else happens. The evaluator is the shared function_199364, so a call has no effect beyond evaluating its argument expressions.
- Evidence: V

### mp_allegiance
- Slot: 1566 (table entry 0xa0b530)
- Returns: void
- Parameters: a0: mp_team, a1: mp_team
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Arguments are evaluated and then the value 0 is handed back as the result; nothing else happens. The evaluator is the shared function_199364, so a call has no effect beyond evaluating its argument expressions.
- Evidence: V

### mp_round_started
- Slot: 1567 (table entry 0xa0b4f0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b6868 (38 bytes)
- Behavior: Returns the byte result of function_7b15c.
- Evidence: V

### mp_round_end_with_winning_player
- Slot: 1568 (table entry 0xa0b4a0)
- Returns: void
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1b6890 (189 bytes)
- Behavior: Takes a player handle. When the engine check holds (the game engine globals have dword +0x841c in 1..4, the table pointer at data_b95f78[index] is non-null and bit 3 of the first byte of the block is set) the value passed on is the team byte at +0xad of the players datum entry selected by the low 16 bits of the handle; otherwise the argument value itself is passed. Then calls function_7b3ec(that value, 0, 1). Nothing is returned.
- Evidence: V

### mp_round_end_with_winning_team
- Slot: 1569 (table entry 0xa0b450)
- Returns: void
- Parameters: a0: mp_team
- Kind: normal
- Status: implemented
- Evaluator: function_1b6950 (74 bytes)
- Behavior: Calls function_7b3ec(team, 0, 1) with the team argument. Nothing is returned.
- Evidence: V

### mp_round_end
- Slot: 1570 (table entry 0xa0b660)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b699c (36 bytes)
- Behavior: Calls function_7b3ec(-1, 0, 1). Nothing is returned.
- Evidence: V

### mp_scripts_reset
- Slot: 1571 (table entry 0xa0b620)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b69c0 (134 bytes)
- Behavior: Unless byte +0x11 of the game globals block (per-thread offset 0x48) equals 4: when the first byte of the hs runtime globals block (per-thread offset 0x230) is non-zero, walks all script threads with function_87188 and function_87200 and deletes (function_857e4) every thread whose byte +0x20 is not 2; then calls function_84ec8 and function_6be324. Nothing is returned.
- Evidence: V

### mp_wake_script
- Slot: 1572 (table entry 0xa0b5d0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### tag_file_set_backend
- Slot: 1573 (table entry 0xa0b580)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### mp_debug_goal_object_boundary_geometry
- Slot: 1574 (table entry 0xa0b2c0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### mp_dump_candy_monitor_state
- Slot: 1575 (table entry 0xa0b280)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### determinism_debug_manager_enable_logging
- Slot: 1576 (table entry 0xa0b230)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### determinism_debug_manager_set_trace_flags
- Slot: 1577 (table entry 0xa0b1e0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### determinism_debug_manager_enable_game_state_checksum
- Slot: 1578 (table entry 0xa0b400)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### determinism_debug_manager_enable_trace
- Slot: 1579 (table entry 0xa0b3b0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### determinism_debug_manager_set_consumer_sample_level
- Slot: 1580 (table entry 0xa0b360)
- Returns: void
- Parameters: a0: string, a1: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### determinism_log_compare_log_files
- Slot: 1581 (table entry 0xa0b310)
- Returns: void
- Parameters: a0: string, a1: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### determinism_debug_manager_enable_log_file_comparision_on_oos
- Slot: 1582 (table entry 0xa0b050)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### saved_film_play
- Slot: 1583 (table entry 0xa0b000)
- Returns: void
- Parameters: a0: controller, a1: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### saved_film_play_last
- Slot: 1584 (table entry 0xa0afc0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### saved_film_disable_version_checking
- Slot: 1585 (table entry 0xa0af70)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### saved_film_toggle_debug_saving
- Slot: 1586 (table entry 0xa0b190)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### saved_films_show_timestamp
- Slot: 1587 (table entry 0xa0b140)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### mover_set_program
- Slot: 1588 (table entry 0xa0b0f0)
- Returns: boolean
- Parameters: a0: object, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_1b6a48 (185 bytes)
- Behavior: Takes an object handle and a short program index. Returns false unless the object type byte (+4 of the object datum entry) is 0, 1, 11 or 12 and the program index is 15 or less; then calls function_510f10(pointer = object data + the signed word at object data +0x1b2, object handle, program index) and returns its boolean result.
- Evidence: V

### floating_point_exceptions_enable
- Slot: 1589 (table entry 0xa0b0a0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### tag_reload_force
- Slot: 1590 (table entry 0xa0adf0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### tag_unload_force
- Slot: 1591 (table entry 0xa0ada0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### tag_load_force
- Slot: 1592 (table entry 0xa0ad50)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### predict_bink_movie
- Slot: 1593 (table entry 0xa0ad00)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: implemented
- Evaluator: function_1b6b04 (155 bytes)
- Behavior: Resolves the string through function_1990a0, builds the movie path with function_2d7908 and, when that succeeds, calls function_d8818(path, -1, 0, 0). Nothing is returned.
- Evidence: V

### predict_bink_movie_from_tag
- Slot: 1594 (table entry 0xa0af20)
- Returns: void
- Parameters: a0: bink_definition
- Kind: normal
- Status: implemented
- Evaluator: function_1b6ba0 (89 bytes)
- Behavior: Calls function_d8818(null path, tag handle, 0x1000, 0). Nothing is returned.
- Evidence: V

### profiler_dump_history
- Slot: 1595 (table entry 0xa0aee0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### camera_set_mode
- Slot: 1596 (table entry 0xa0ae90)
- Returns: void
- Parameters: a0: unit, a1: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b6bfc (218 bytes)
- Behavior: Takes a unit handle and a long. For the output indices enumerated by function_54044 (iterator whose state starts from the dword at unit object data offset +0x1cc, output index starts at -1), calls function_c5834 with (entry = director globals block (per-thread offset 0x188) + output index * 0x1ac, the long, 0, 0.0). Nothing is returned.
- Evidence: V

### camera_set_flying_cam_at_point
- Slot: 1597 (table entry 0xa0ae40)
- Returns: void
- Parameters: a0: unit, a1: cutscene_camera_point
- Kind: normal
- Status: implemented
- Evaluator: function_1b6cd8 (72 bytes)
- Behavior: Calls function_c4b68 with (unit handle, 16-bit cutscene camera point index). Nothing is returned.
- Evidence: S

### camera_set_target
- Slot: 1598 (table entry 0xa0ab80)
- Returns: void
- Parameters: a0: unit, a1: object
- Kind: normal
- Status: implemented
- Evaluator: function_1b6d20 (230 bytes)
- Behavior: Takes a unit handle and an object handle. Does nothing if the unit handle is -1. For the output indices enumerated by function_54044 (iterator whose state starts from the dword at unit object data offset +0x1cc, output index starts at -1), calls the virtual function at offset 0x20 of the object stored at (director globals block + output index * 0x1ac + 8), passing the target object handle. Nothing is returned.
- Evidence: V

### camera_set_orbiting_cam_at_target_relative_point
- Slot: 1599 (table entry 0xa0ab30)
- Returns: void
- Parameters: a0: unit, a1: string_id, a2: real, a3: real, a4: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b6e08 (236 bytes)
- Behavior: Takes a unit handle, a string id and three reals. For the output indices enumerated by function_54044 (iterator whose state starts from the dword at unit object data offset +0x1cc, output index starts at -1), calls function_c4950(output index, string id, first real, second real, third real). Nothing is returned.
- Evidence: V

### director_cycle_debug_camera
- Slot: 1600 (table entry 0xa0aae0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_coop_player_count
- Slot: 1601 (table entry 0xa0aaa0)
- Returns: long
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b6ef4 (45 bytes)
- Behavior: Returns 0 unless function_58b5c returns true, in which case it returns function_4a1ec(1).
- Evidence: V

### player_force_mode
- Slot: 1602 (table entry 0xa0acb0)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### profiler_output_pulse
- Slot: 1603 (table entry 0xa0ac70)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### string_id_name
- Slot: 1604 (table entry 0xa0ac20)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### find
- Slot: 1605 (table entry 0xa0abd0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### add_recycling_volume
- Slot: 1606 (table entry 0xa0a950)
- Returns: void
- Parameters: a0: trigger_volume, a1: long, a2: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b6f24 (80 bytes)
- Behavior: Calls function_4ff5e0(trigger volume index (16-bit), first long, second long, -1). Nothing is returned.
- Evidence: S

### add_recycling_volume_by_type
- Slot: 1607 (table entry 0xa0a900)
- Returns: void
- Parameters: a0: trigger_volume, a1: long, a2: long, a3: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b6f74 (80 bytes)
- Behavior: Calls function_4ff5e0(trigger volume index (16-bit), first long, second long, third long). Nothing is returned.
- Evidence: S

### tag_resources_set_per_frame_publish
- Slot: 1608 (table entry 0xa0a8b0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### object_recycling_clear_history
- Slot: 1609 (table entry 0xa0aa60)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### dump_cinematics_script
- Slot: 1610 (table entry 0xa0aa20)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### dump_tag_stats
- Slot: 1611 (table entry 0xa0a9e0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### global_preferences_clear
- Slot: 1612 (table entry 0xa0a9a0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### network_storage_set_storage_subdirectory
- Slot: 1613 (table entry 0xa0a740)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### network_storage_set_storage_user
- Slot: 1614 (table entry 0xa0a6f0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### network_storage_run_locally
- Slot: 1615 (table entry 0xa0a6a0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### status_line_dump
- Slot: 1616 (table entry 0xa0a660)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_tick_get
- Slot: 1617 (table entry 0xa0a870)
- Returns: long
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b6fc4
- Behavior: Returns the dword at +0xc of the game time block (per-thread offset 0xa0).
- Evidence: V

### loop_it
- Slot: 1618 (table entry 0xa0a820)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### loop_clear
- Slot: 1619 (table entry 0xa0a7e0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### status_lines_enable
- Slot: 1620 (table entry 0xa0a790)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### status_lines_disable
- Slot: 1621 (table entry 0xa0a4e0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### on_target_platform
- Slot: 1622 (table entry 0xa0a4a0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated. The declared return type is boolean; the value handed back is 0.
- Evidence: V

### f7_profiler_enable
- Slot: 1623 (table entry 0xa0a450)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### f7_profiler_substring_activate
- Slot: 1624 (table entry 0xa0a610)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### f7_profiler_substring_deactivate
- Slot: 1625 (table entry 0xa0a5c0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_get_game_id
- Slot: 1626 (table entry 0xa0a580)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### saved_film_set_playback_game_speed
- Slot: 1627 (table entry 0xa0a530)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b6ff0 (70 bytes)
- Behavior: Calls function_5b068 with the real argument. Nothing is returned.
- Evidence: S

### noguchis_mystery_tour
- Slot: 1628 (table entry 0xa0a2c0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### designer_zone_sync
- Slot: 1629 (table entry 0xa0a280)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### dump_designer_zone
- Slot: 1630 (table entry 0xa0a230)
- Returns: void
- Parameters: a0: designer_zone
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### designer_zone_activate
- Slot: 1631 (table entry 0xa0a1e0)
- Returns: void
- Parameters: a0: designer_zone
- Kind: normal
- Status: implemented
- Evaluator: function_1b7038 (174 bytes)
- Behavior: Zone index is the byte argument; bit = 1 << index. Does nothing when the bit is set in the result of function_97ad4(data_afbe30), or not set in the result of function_97a9c(data_afbe30), or set in data_4e2fb24. Otherwise it clears the bit in data_263ead8, sets it in data_263eadc and stores in the byte data_263eac4 a 1 if any of data_263ead8, data_263eadc, data_263eae0, data_263eae4 is non-zero, else 0. Nothing is returned.
- Evidence: V

### designer_zone_deactivate
- Slot: 1632 (table entry 0xa0a400)
- Returns: void
- Parameters: a0: designer_zone
- Kind: normal
- Status: implemented
- Evaluator: function_1b70e8 (156 bytes)
- Behavior: Zone index is the byte argument; bit = 1 << index. Does nothing when the bit is set in the result of function_97a9c(data_afbe30) or not set in data_4e2fb24. Otherwise it sets the bit in data_263ead8, clears it in data_263eadc and recomputes the byte data_263eac4 as designer_zone_activate does. Nothing is returned.
- Evidence: V

### object_set_always_active
- Slot: 1633 (table entry 0xa0a3b0)
- Returns: void
- Parameters: a0: object, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b7184 (71 bytes)
- Behavior: Calls function_46c7a4(object handle, boolean). Nothing is returned.
- Evidence: S

### saved_film_seek_to_film_tick
- Slot: 1634 (table entry 0xa0a360)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### saved_film_seek_to_film_timestamp
- Slot: 1635 (table entry 0xa0a310)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### tag_is_active
- Slot: 1636 (table entry 0xa0a070)
- Returns: boolean
- Parameters: a0: any_tag_not_resolving
- Kind: normal
- Status: implemented
- Evaluator: function_1b71cc (80 bytes)
- Behavior: Returns the boolean result of function_8f620 called with the tag handle argument.
- Evidence: S

### tag_resources_set_incremental_publish
- Slot: 1637 (table entry 0xa0a020)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### tag_resources_enable_optional_caching
- Slot: 1638 (table entry 0xa09fd0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### dump_active_resources
- Slot: 1639 (table entry 0xa0a1a0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### object_set_persistent
- Slot: 1640 (table entry 0xa0a150)
- Returns: void
- Parameters: a0: object, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b721c (71 bytes)
- Behavior: Calls function_47c5f8(object handle, boolean). Nothing is returned.
- Evidence: S

### display_zone_size_estimates
- Slot: 1641 (table entry 0xa0a100)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### report_zone_size_estimates
- Slot: 1642 (table entry 0xa0a0c0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_test_disconnect_squad
- Slot: 1643 (table entry 0xa09e70)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_test_disconnect_group
- Slot: 1644 (table entry 0xa09e30)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_test_clear_squad_session_parameter
- Slot: 1645 (table entry 0xa09de0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_test_clear_group_session_parameter
- Slot: 1646 (table entry 0xa09d90)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_test_life_cycle_pause
- Slot: 1647 (table entry 0xa09f80)
- Returns: void
- Parameters: a0: string, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_test_life_cycle_display_states
- Slot: 1648 (table entry 0xa09f40)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### overlapped_display_task_descriptions
- Slot: 1649 (table entry 0xa09f00)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### overlapped_task_inject_error
- Slot: 1650 (table entry 0xa09eb0)
- Returns: void
- Parameters: a0: string, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### test_sapien_crash
- Slot: 1651 (table entry 0xa09c10)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### output_window_add_category
- Slot: 1652 (table entry 0xa09bc0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### output_window_remove_category
- Slot: 1653 (table entry 0xa09b70)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### output_window_list_categories
- Slot: 1654 (table entry 0xa09b30)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### decorators_split
- Slot: 1655 (table entry 0xa09d40)
- Returns: void
- Parameters: a0: long, a1: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### bandwidth_profiler_enable
- Slot: 1656 (table entry 0xa09cf0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### bandwidth_profiler_set_context
- Slot: 1657 (table entry 0xa09ca0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### simulation_priority_display_set_enabled
- Slot: 1658 (table entry 0xa09c50)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### simulation_priority_display_set_object_names
- Slot: 1659 (table entry 0xa099e0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### simulation_priority_display_set_machine_filter
- Slot: 1660 (table entry 0xa099a0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### simulation_priority_display_set_priority_scope_tick
- Slot: 1661 (table entry 0xa09960)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### simulation_priority_display_set_priority_scope_second_worst
- Slot: 1662 (table entry 0xa09920)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### simulation_priority_display_set_priority_scope_second_best
- Slot: 1663 (table entry 0xa09af0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### simulation_priority_display_set_color_by_relevance
- Slot: 1664 (table entry 0xa09ab0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### simulation_priority_display_set_color_by_update_period
- Slot: 1665 (table entry 0xa09a70)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### simulation_priority_display_set_color_by_final_priority
- Slot: 1666 (table entry 0xa09a30)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### overlapped_task_pause
- Slot: 1667 (table entry 0xa09790)
- Returns: void
- Parameters: a0: string, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_build_map_variant
- Slot: 1668 (table entry 0xa09740)
- Returns: void
- Parameters: a0: boolean, a1: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_verify_map_variant
- Slot: 1669 (table entry 0xa096f0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_load_and_use_map_variant
- Slot: 1670 (table entry 0xa096a0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### write_current_map_variant
- Slot: 1671 (table entry 0xa098d0)
- Returns: void
- Parameters: a0: boolean, a1: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### read_map_variant_and_make_current
- Slot: 1672 (table entry 0xa09880)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### async_set_thread_work_delay_milliseconds
- Slot: 1673 (table entry 0xa09830)
- Returns: void
- Parameters: a0: long, a1: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### tag_resources_set_demand_throttle_to_io
- Slot: 1674 (table entry 0xa097e0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### tag_resources_flush_optional
- Slot: 1675 (table entry 0xa09520)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### set_performance_throttle
- Slot: 1676 (table entry 0xa094d0)
- Returns: void
- Parameters: a0: string, a1: long, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b7264 (85 bytes)
- Behavior: Resolves the string through function_1990a0 and calls function_270414(string, long, real). Nothing is returned.
- Evidence: S

### get_performance_throttle
- Slot: 1677 (table entry 0xa09480)
- Returns: real
- Parameters: a0: string, a1: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b72bc (88 bytes)
- Behavior: Resolves the string through function_1990a0 and returns the real value of function_270730(string, long).
- Evidence: S

### cinematic_zone_activate
- Slot: 1678 (table entry 0xa09650)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b7314 (163 bytes)
- Behavior: Zone index is the long argument. Does nothing when it is negative, not below the dword at +0x77c of the scenario tag data, or when bit (1 << index) is set in data_4e2fb20. Otherwise it clears that bit in data_263eae0, sets it in data_263eae4 and recomputes the byte data_263eac4 as 1 when any of data_263ead8, data_263eadc, data_263eae0, data_263eae4 is non-zero, else 0. Nothing is returned.
- Evidence: V

### cinematic_zone_deactivate
- Slot: 1679 (table entry 0xa09600)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b73b8 (68 bytes)
- Behavior: Calls function_351f0 with the long argument. Shared by cinematic_zone_deactivate and cinematic_scripting_clean_up; both natives run this same code. Nothing is returned. Same evaluator as cinematic_scripting_clean_up.
- Evidence: S

### cinematic_zone_activate_from_editor
- Slot: 1680 (table entry 0xa095b0)
- Returns: void
- Parameters: a0: any_tag
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cinematic_zone_deactivate_from_editor
- Slot: 1681 (table entry 0xa09560)
- Returns: void
- Parameters: a0: any_tag
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### tiling_current
- Slot: 1682 (table entry 0xa09350)
- Returns: long
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b73fc
- Behavior: Returns the dword at data_4e38a04.
- Evidence: V

### unit_limit_lipsync_to_mouth_only
- Slot: 1683 (table entry 0xa09300)
- Returns: void
- Parameters: a0: unit, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b740c (71 bytes)
- Behavior: Calls function_4f911c(unit handle, boolean). Nothing is returned.
- Evidence: S

### dump_active_zone_tags
- Slot: 1684 (table entry 0xa092c0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### calculate_tag_prediction
- Slot: 1685 (table entry 0xa09430)
- Returns: void
- Parameters: a0: any_tag
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### tag_resources_enable_fast_prediction
- Slot: 1686 (table entry 0xa093e0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### unit_start_first_person_custom_animation
- Slot: 1687 (table entry 0xa09390)
- Returns: boolean
- Parameters: a0: unit, a1: animation_graph, a2: string_id, a3: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b7454 (91 bytes)
- Behavior: Calls function_2b5888(unit handle, animation graph tag handle, string id, boolean) and returns its boolean result.
- Evidence: S

### unit_is_playing_custom_first_person_animation
- Slot: 1688 (table entry 0xa09180)
- Returns: boolean
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_1b74b0 (80 bytes)
- Behavior: Returns the boolean result of function_2b53d8(unit handle).
- Evidence: S

### unit_stop_first_person_custom_animation
- Slot: 1689 (table entry 0xa09130)
- Returns: void
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_1b7500 (68 bytes)
- Behavior: Calls function_2b5428(unit handle). Nothing is returned.
- Evidence: S

### prepare_to_switch_to_zone_set
- Slot: 1690 (table entry 0xa090e0)
- Returns: void
- Parameters: a0: zone_set
- Kind: normal
- Status: implemented
- Evaluator: function_1b7544 (69 bytes)
- Behavior: Calls function_353fc with the sign-extended 16-bit zone set index. Nothing is returned.
- Evidence: S

### cinematic_zone_activate_for_debugging
- Slot: 1691 (table entry 0xa09090)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b758c (68 bytes)
- Behavior: Calls function_35240 with the long argument. Nothing is returned.
- Evidence: S

### unit_play_random_ping
- Slot: 1692 (table entry 0xa09270)
- Returns: void
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_1b75d0 (68 bytes)
- Behavior: Calls function_4fa4bc(unit handle). Nothing is returned.
- Evidence: S

### player_control_fade_out_all_input
- Slot: 1693 (table entry 0xa09220)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b7614 (73 bytes)
- Behavior: Calls function_660f4(0.0, argument). Nothing is returned.
- Evidence: S

### player_control_fade_in_all_input
- Slot: 1694 (table entry 0xa091d0)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b7660 (78 bytes)
- Behavior: Calls function_660f4(1.0, argument). Nothing is returned.
- Evidence: S

### player_control_lock_gaze
- Slot: 1695 (table entry 0xa08f50)
- Returns: void
- Parameters: a0: player, a1: point_reference, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b76b0 (98 bytes)
- Behavior: Takes a player handle, a point reference and a real. If the player handle is -1 nothing happens. Otherwise function_53b5c maps the player to an input index; when that index is 3 or less, function_66160(input index, point reference, real) is called. Nothing is returned.
- Evidence: S

### player_control_unlock_gaze
- Slot: 1696 (table entry 0xa08f00)
- Returns: void
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1b7714 (133 bytes)
- Behavior: Takes a player handle. If it is -1 nothing happens. Otherwise function_53b5c maps the player to an input index; when that index is 3 or less, in the player control globals block (per-thread offset 0xd8) the entry at index * 0x180 gets dword +0x1fc = 0 and byte +0x1ec = 0. Nothing is returned.
- Evidence: V

### player_control_scale_all_input
- Slot: 1697 (table entry 0xa08eb0)
- Returns: void
- Parameters: a0: real, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b779c (75 bytes)
- Behavior: Calls function_660f4(first real, second real). Nothing is returned.
- Evidence: S

### profiler_auto_core_save
- Slot: 1698 (table entry 0xa09040)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cinematic_tag_reference_get_bink
- Slot: 1699 (table entry 0xa08ff0)
- Returns: bink_definition
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b77e8 (159 bytes)
- Behavior: Reads the tag block at +0x780 of the scenario tag data (entries of 0x14 bytes) at the long index (no range check). If the dword at +0x10 of that entry is -1 the result is -1. Otherwise the 16-bit tag index in that dword selects a tag instance and the dword at +0x58 of its tag data is returned.
- Evidence: V

### object_set_custom_animation_speed
- Slot: 1700 (table entry 0xa08fa0)
- Returns: void
- Parameters: a0: object, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b7888 (219 bytes)
- Behavior: Takes an object handle and a real. Does nothing when the handle is -1 or when the object data has word -1 at +0x18e. Otherwise the structure p = object data + the signed word at +0x18e is used: if dword p+0x12c is -1, bit 2 of dword p+0x160 is clear, byte p+0x1e is 0, dword p+0 is -1, word p+0xa is negative, or dword p+0x204 is not 0xe8, nothing changes; otherwise float p+0x20 is set to max(real, 0.0001). Nothing is returned.
- Evidence: V

### scenery_animation_start_at_frame_loop
- Slot: 1701 (table entry 0xa08d20)
- Returns: void
- Parameters: a0: scenery, a1: animation_graph, a2: string_id, a3: short
- Kind: normal
- Status: implemented
- Evaluator: function_1b7964 (95 bytes)
- Behavior: Calls function_4fdfac(scenery handle, animation graph tag handle, string id, 16-bit frame, -1, 1, 1) (the last three are fixed by the evaluator). Nothing is returned.
- Evidence: S

### saved_film_set_repro_mode
- Slot: 1702 (table entry 0xa08cd0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b79c4 (149 bytes)
- Behavior: Compares the boolean with the byte data_278ee39; when equal nothing happens. Otherwise the byte is updated and, when function_586c4 and function_58eec are both true, function_53d7c(output index, -1) is called for indices 0 to 3, then, if function_58eec is still true, function_43e60(1) is called. Nothing is returned.
- Evidence: S

### font_set_emergency
- Slot: 1703 (table entry 0xa08c90)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b7a5c (114 bytes)
- Behavior: If the first byte of the block at data_25b18c0 is 0, the block is initialised: 0xc158 bytes cleared with function_78932a, dword +4 set to -1, function_cbc28 and function_ccbac called, byte +0 set to 1. Then, with the lock taken by function_cbedc and released by function_cbbdc, the byte data_25b18c2 is set to 1. Nothing is returned.
- Evidence: V

### biped_force_ground_fitting_on
- Slot: 1704 (table entry 0xa08c40)
- Returns: void
- Parameters: a0: unit, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b7ad0 (152 bytes)
- Behavior: Takes a unit handle and a boolean. Does nothing if the handle is -1 or the object type byte (+4 of the object datum entry) is not 0. Otherwise bit 12 of the dword at +0x9d8 of the object data is set when the boolean is non-zero and cleared when it is 0. Nothing is returned.
- Evidence: V

### cinematic_set_chud_objective
- Slot: 1705 (table entry 0xa08e60)
- Returns: void
- Parameters: a0: cutscene_title
- Kind: normal
- Status: implemented
- Evaluator: function_1b7b68 (69 bytes)
- Behavior: Calls function_d38fc with the 16-bit title index. Nothing is returned.
- Evidence: S

### chud_show_cinematic_title
- Slot: 1706 (table entry 0xa08e10)
- Returns: void
- Parameters: a0: player, a1: cutscene_title
- Kind: normal
- Status: implemented
- Evaluator: function_1b7bb0 (72 bytes)
- Behavior: Calls function_d39d0(player handle, 16-bit title index). Nothing is returned.
- Evidence: S

### unit_get_primary_weapon
- Slot: 1707 (table entry 0xa08dc0)
- Returns: weapon
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_1b7bf8 (123 bytes)
- Behavior: Reads the signed byte at +0x34a of the object data of the unit and returns function_48b3d0(unit handle, that byte).
- Evidence: S

### budget_resource_get_animation_graph
- Slot: 1708 (table entry 0xa08d70)
- Returns: animation_graph
- Parameters: a0: animation_budget_reference
- Kind: normal
- Status: implemented
- Evaluator: function_1b7c74 (82 bytes)
- Behavior: Returns the tag handle argument when function_8f620 returns true for it, otherwise -1. Shared by budget_resource_get_animation_graph, budget_resource_get_looping_sound and budget_resource_get_sound; all three natives run this same code. Same evaluator as budget_resource_get_looping_sound, budget_resource_get_sound.
- Evidence: S

### budget_resource_get_looping_sound
- Slot: 1709 (table entry 0xa08b00)
- Returns: looping_sound
- Parameters: a0: looping_sound_budget_reference
- Kind: normal
- Status: implemented
- Evaluator: function_1b7c74 (82 bytes)
- Behavior: Returns the tag handle argument when function_8f620 returns true for it, otherwise -1. Shared by budget_resource_get_animation_graph, budget_resource_get_looping_sound and budget_resource_get_sound; all three natives run this same code. Same evaluator as budget_resource_get_animation_graph, budget_resource_get_sound.
- Evidence: S

### game_safe_to_respawn (slot 1710)
- Slot: 1710 (table entry 0xa08ab0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b7cc8 (169 bytes)
- Behavior: Takes a boolean. For every entry of the players datum array (per-thread offset 0x18, walked with function_1381c) the byte at +0x1ba is set to 1 when the boolean is 0 and to 0 otherwise. Nothing is returned.
- Evidence: V

### game_safe_to_respawn (slot 1711)
- Slot: 1711 (table entry 0xa08a60)
- Returns: void
- Parameters: a0: boolean, a1: player
- Kind: normal
- Status: implemented
- Evaluator: function_1b7d74 (132 bytes)
- Behavior: Takes a boolean and a player handle. If the handle is -1 nothing happens. Otherwise the byte at +0x1ba of the players datum entry selected by the low 16 bits of the handle (entries of 0x490 bytes) is set to 1 when the boolean is 0 and to 0 otherwise. Nothing is returned.
- Evidence: V

### ai_migrate_infanty
- Slot: 1712 (table entry 0xa08bf0)
- Returns: void
- Parameters: a0: ai, a1: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1b7df8 (71 bytes)
- Behavior: Calls function_6bfbe0(first ai reference, second ai reference). Nothing is returned.
- Evidence: S

### render_cinematic_motion_blur
- Slot: 1713 (table entry 0xa08ba0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b7e40 (112 bytes)
- Behavior: If the rasterizer game states block (per-thread offset 0x168) exists, sets bit 5 (0x20) of its first byte when the boolean is non-zero and clears it otherwise. Nothing is returned.
- Evidence: V

### ai_dont_do_avoidance
- Slot: 1714 (table entry 0xa08b50)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b7eb0 (71 bytes)
- Behavior: Calls function_6c2db8(ai reference, boolean). Nothing is returned.
- Evidence: S

### cinematic_scripting_clean_up
- Slot: 1715 (table entry 0xa08930)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b73b8 (68 bytes)
- Behavior: Calls function_351f0 with the long argument. Shared by cinematic_zone_deactivate and cinematic_scripting_clean_up; both natives run this same code. Nothing is returned. Same evaluator as cinematic_zone_deactivate.
- Evidence: S

### ai_erase_inactive
- Slot: 1716 (table entry 0xa088e0)
- Returns: void
- Parameters: a0: ai, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_1b7ef8 (216 bytes)
- Behavior: Takes an ai reference and a short. The value v = (the 16-bit tick at +0xc of the game time block + the short) when the short is greater than 0, otherwise -1. function_6be174 and function_6be220 then walk every actor of the reference; an actor with bit 3 (0x8) set in its byte +6 gets dword +0x64 = the sign-extended low 16 bits of v and is kept, every other actor is removed with function_6aa324(actor handle, 0). Nothing is returned.
- Evidence: V

### ai_survival_cleanup
- Slot: 1717 (table entry 0xa08890)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b7fd0 (210 bytes)
- Behavior: Takes an ai reference and two booleans (a at +4, b at +8). Walks every actor with function_6be174 and function_6be220: bit 2 (0x4) of actor byte +7 is set to a and, when a is set, bit 3 of actor byte +6 is clear and b is set, the actor is removed with function_6aa324(actor handle, 0). Nothing is returned.
- Evidence: V

### ai_enable_stuck_flying_kill
- Slot: 1718 (table entry 0xa08a10)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b80a4 (171 bytes)
- Behavior: Takes an ai reference and a boolean. Walks every actor with function_6be174 and function_6be220 and sets bit 3 (0x8) of actor byte +7 to the boolean. Nothing is returned.
- Evidence: V

### ai_set_stuck_velocity_threshold
- Slot: 1719 (table entry 0xa089c0)
- Returns: void
- Parameters: a0: ai, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b8150 (140 bytes)
- Behavior: Takes an ai reference and a real. Walks every actor with function_6be174 and function_6be220 and stores the real at actor +0x14. Nothing is returned.
- Evidence: V

### stop_bink_movie
- Slot: 1720 (table entry 0xa08980)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b81dc (27 bytes)
- Behavior: Calls function_d7fd4. Nothing is returned.
- Evidence: V

### play_credits_unskippable
- Slot: 1721 (table entry 0xa08760)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b81f8 (118 bytes)
- Behavior: Starts the unskippable credits movie. Builds a movie path with function_2d7908 from the fixed name string at 0xa35dd8, calls function_d9484 with (path, -1, 0x41c) when that succeeds, then sets the global byte data_2881ba6 to 1 whether or not a movie started. Nothing is returned.
- Evidence: V

### budget_resource_get_sound
- Slot: 1722 (table entry 0xa08710)
- Returns: sound
- Parameters: a0: sound_budget_reference
- Kind: normal
- Status: implemented
- Evaluator: function_1b7c74 (82 bytes)
- Behavior: Returns the tag handle argument when function_8f620 returns true for it, otherwise -1. Shared by budget_resource_get_animation_graph, budget_resource_get_looping_sound and budget_resource_get_sound; all three natives run this same code. Same evaluator as budget_resource_get_animation_graph, budget_resource_get_looping_sound.
- Evidence: S

### controller_set_single_player_level_unlocked
- Slot: 1723 (table entry 0xa086c0)
- Returns: void
- Parameters: a0: controller, a1: short, a2: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### physical_memory_dump
- Slot: 1724 (table entry 0xa08680)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### tag_resources_validate_all_pages
- Slot: 1725 (table entry 0xa08840)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cinematic_set_debug_mode
- Slot: 1726 (table entry 0xa087f0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b8270 (69 bytes)
- Behavior: Copies the boolean into the global byte data_2d597ee. Nothing is returned.
- Evidence: V

### cinematic_scripting_get_object
- Slot: 1727 (table entry 0xa087a0)
- Returns: object
- Parameters: a0: long, a1: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b82b8 (71 bytes)
- Behavior: Returns the object handle returned by function_236e7c(first long, second long).
- Evidence: S

### player_override_team
- Slot: 1728 (table entry 0xa08500)
- Returns: void
- Parameters: a0: long, a1: team
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### unit_set_stance
- Slot: 1729 (table entry 0xa084b0)
- Returns: void
- Parameters: a0: unit, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b8300 (159 bytes)
- Behavior: Takes a unit handle and a string id. Does nothing if the handle is -1. Otherwise p = object data + the signed word at +0x18e is looked up; if p is non-null and the string id is non-zero, function_145580(p, string id, 4) is called, and if the string id is 0 the dword at p+0x1c4 is cleared. Nothing is returned.
- Evidence: S

### player_set_stance
- Slot: 1730 (table entry 0xa08460)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### sound_impulse_start_editor
- Slot: 1731 (table entry 0xa08410)
- Returns: void
- Parameters: a0: sound, a1: object, a2: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### sound_impulse_start_effect_editor
- Slot: 1732 (table entry 0xa08630)
- Returns: void
- Parameters: a0: sound, a1: object, a2: real, a3: string_id
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### sound_impulse_start_3d_editor
- Slot: 1733 (table entry 0xa085e0)
- Returns: void
- Parameters: a0: sound, a1: real, a2: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### sound_looping_start_editor
- Slot: 1734 (table entry 0xa08590)
- Returns: void
- Parameters: a0: looping_sound, a1: object, a2: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_sound_channels_log_start
- Slot: 1735 (table entry 0xa08550)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_sound_channels_log_start_named
- Slot: 1736 (table entry 0xa08280)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_sound_channels_log_stop
- Slot: 1737 (table entry 0xa08240)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### simulation_profiler_enable
- Slot: 1738 (table entry 0xa08200)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### saved_film_insert_marker
- Slot: 1739 (table entry 0xa081b0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### saved_film_seek_to_marker
- Slot: 1740 (table entry 0xa083c0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_simulation_set_stream_bandwidth
- Slot: 1741 (table entry 0xa08370)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_sound_fadeout_time
- Slot: 1742 (table entry 0xa08320)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### render_model_marker_name_filter
- Slot: 1743 (table entry 0xa082d0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### skull_enable
- Slot: 1744 (table entry 0xa08030)
- Returns: void
- Parameters: a0: skull, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b83a0 (158 bytes)
- Behavior: Takes a skull index and a boolean. For an index of 0x28 or less (unsigned) bit INDEX of the qword at +0x1eac8 of the game globals block (per-thread offset 0x48) is set when the boolean is non-zero and cleared otherwise. In all cases function_4e2b98 is then called with the address of that qword. Nothing is returned.
- Evidence: V

### allow_object_to_be_lased
- Slot: 1745 (table entry 0xa07fe0)
- Returns: void
- Parameters: a0: object, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b8440 (115 bytes)
- Behavior: Takes an object handle and a boolean. When the handle is not -1 and function_4739cc(handle, -1) returns object data, bit 31 of the dword at +4 of that object data is set when the boolean is non-zero and cleared otherwise. Nothing is returned.
- Evidence: V

### is_object_being_lased
- Slot: 1746 (table entry 0xa07f90)
- Returns: boolean
- Parameters: a0: object
- Kind: normal
- Status: implemented
- Evaluator: function_1b84b4 (177 bytes)
- Behavior: Takes an object handle and returns true when it appears in the lasing datum array (per-thread offset 0x440): each entry is visited with function_157e40 and the entry dword at +8 is compared with the handle. A handle of -1 returns false.
- Evidence: V

### simulation_profiler_detail_level
- Slot: 1747 (table entry 0xa08160)
- Returns: long
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b8568 (82 bytes)
- Behavior: Clamps the long argument to the range 0..9 and stores it in the global dword data_4e38d3c. Nothing is returned.
- Evidence: V

### simulation_profiler_enable_downstream_processing
- Slot: 1748 (table entry 0xa08110)
- Returns: boolean
- Parameters: a0: boolean
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Arguments are evaluated and then the value 0 is handed back as the result; nothing else happens. The evaluator is the shared function_199364, so a call has no effect beyond evaluating its argument expressions.
- Evidence: V

### campaign_metagame_get_player_score
- Slot: 1749 (table entry 0xa080c0)
- Returns: long
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1b85bc (68 bytes)
- Behavior: Returns function_a1718(player handle).
- Evidence: S

### collision_debug_lightmaps_print
- Slot: 1750 (table entry 0xa08080)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### load_binary_game_engine
- Slot: 1751 (table entry 0xa07e00)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### network_storage_files_display_file_names
- Slot: 1752 (table entry 0xa07dc0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### network_storage_files_force_download
- Slot: 1753 (table entry 0xa07d70)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_lightmap_inspect
- Slot: 1754 (table entry 0xa07d30)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### render_debug_colorbars
- Slot: 1755 (table entry 0xa07f40)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### voice_force_global_repeater_use
- Slot: 1756 (table entry 0xa07ef0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### levels_add_campaign_map_with_id
- Slot: 1757 (table entry 0xa07ea0)
- Returns: void
- Parameters: a0: long, a1: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### levels_add_campaign_map
- Slot: 1758 (table entry 0xa07e50)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### levels_add_multiplayer_map
- Slot: 1759 (table entry 0xa07bf0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### network_team_picker_unit_test
- Slot: 1760 (table entry 0xa07bb0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_objects_unit_seats_filter
- Slot: 1761 (table entry 0xa07b60)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_lock_enforcement
- Slot: 1762 (table entry 0xa07b10)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### rewards_get_cookie_total
- Slot: 1763 (table entry 0xa07ce0)
- Returns: long
- Parameters: a0: controller
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Arguments are evaluated and then the value 0 is handed back as the result; nothing else happens. The evaluator is the shared function_199364, so a call has no effect beyond evaluating its argument expressions.
- Evidence: V

### cui_set_screen_name_override_prefix
- Slot: 1764 (table entry 0xa07c90)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cui_load_screen
- Slot: 1765 (table entry 0xa07c40)
- Returns: void
- Parameters: a0: cui_screen_definition
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cui_load_themed_screen
- Slot: 1766 (table entry 0xa07980)
- Returns: void
- Parameters: a0: cui_screen_definition, a1: string_id
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### player_profile_clear_to_default_values
- Slot: 1767 (table entry 0xa07930)
- Returns: void
- Parameters: a0: controller
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### submit_incident
- Slot: 1768 (table entry 0xa078e0)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b15b8 (68 bytes)
- Behavior: Calls function_10ae54 with the string id. Nothing is returned. Shared with slot 1173 (survival_mode_incident_new); both natives run the same evaluator.
- Evidence: S

### submit_incident_with_cause_player
- Slot: 1769 (table entry 0xa07890)
- Returns: void
- Parameters: a0: string_id, a1: player
- Kind: normal
- Status: implemented
- Evaluator: function_1b8600 (71 bytes)
- Behavior: Calls function_10ac68(string id, player handle). Nothing is returned.
- Evidence: S

### submit_incident_with_cause_team
- Slot: 1770 (table entry 0xa07ac0)
- Returns: void
- Parameters: a0: string_id, a1: mp_team
- Kind: normal
- Status: implemented
- Evaluator: function_1b8648 (126 bytes)
- Behavior: The incident metadata buffer on the stack is 0x20 bytes: dwords +0, +4, +8, +0xc are -1 unless filled in, byte +0x10 is the cause team and byte +0x11 the effect team (-1 unless filled in). The string id is the incident name; function_10a998 queues the incident and function_1099cc dispatches it. Sets cause team byte (+0x10) to the team argument, leaves everything else -1, calls function_10a998 and then function_1099cc. Nothing is returned.
- Evidence: V

### submit_incident_with_cause_player_and_effect_player
- Slot: 1771 (table entry 0xa07a70)
- Returns: void
- Parameters: a0: string_id, a1: player, a2: player
- Kind: normal
- Status: implemented
- Evaluator: function_1b86c8 (75 bytes)
- Behavior: Calls function_10ada4(string id, cause player handle, effect player handle). Nothing is returned.
- Evidence: S

### submit_incident_with_cause_player_and_effect_team
- Slot: 1772 (table entry 0xa07a20)
- Returns: void
- Parameters: a0: string_id, a1: player, a2: mp_team
- Kind: normal
- Status: implemented
- Evaluator: function_1b8714 (190 bytes)
- Behavior: The incident metadata buffer on the stack is 0x20 bytes: dwords +0, +4, +8, +0xc are -1 unless filled in, byte +0x10 is the cause team and byte +0x11 the effect team (-1 unless filled in). The string id is the incident name; function_10a998 queues the incident and function_1099cc dispatches it. If the cause player handle is -1 nothing happens. Otherwise function_10ac14 fills the buffer from the cause player, the effect fields are set to -1 and the effect team byte (+0x11) to the team argument, then function_10a998 and function_1099cc are called. Nothing is returned.
- Evidence: V

### submit_incident_with_cause_team_and_effect_player
- Slot: 1773 (table entry 0xa079d0)
- Returns: void
- Parameters: a0: string_id, a1: mp_team, a2: player
- Kind: normal
- Status: implemented
- Evaluator: function_1b87d4 (215 bytes)
- Behavior: The incident metadata buffer on the stack is 0x20 bytes: dwords +0, +4, +8, +0xc are -1 unless filled in, byte +0x10 is the cause team and byte +0x11 the effect team (-1 unless filled in). The string id is the incident name; function_10a998 queues the incident and function_1099cc dispatches it. If the effect player handle is -1 nothing happens. Otherwise the cause team byte is the team argument, dword +8 is the effect player handle, dword +0xc is function_489c8(effect player) and byte +0x11 is the team byte at +0xad of that player's datum entry; then function_10a998 and function_1099cc are called. Nothing is returned.
- Evidence: V

### submit_incident_with_cause_team_and_effect_team
- Slot: 1774 (table entry 0xa07710)
- Returns: void
- Parameters: a0: string_id, a1: mp_team, a2: mp_team
- Kind: normal
- Status: implemented
- Evaluator: function_1b88ac (129 bytes)
- Behavior: The incident metadata buffer on the stack is 0x20 bytes: dwords +0, +4, +8, +0xc are -1 unless filled in, byte +0x10 is the cause team and byte +0x11 the effect team (-1 unless filled in). The string id is the incident name; function_10a998 queues the incident and function_1099cc dispatches it. Sets cause team byte (+0x10) and effect team byte (+0x11) from the two team arguments, then calls function_10a998 and function_1099cc. Nothing is returned.
- Evidence: V

### submit_incident_with_cause_campaign_team
- Slot: 1775 (table entry 0xa076c0)
- Returns: void
- Parameters: a0: string_id, a1: team
- Kind: normal
- Status: implemented
- Evaluator: function_1b8930 (71 bytes)
- Behavior: Calls function_10acc4(string id, team). Nothing is returned.
- Evidence: S

### net_set_campaign_insertion_point
- Slot: 1776 (table entry 0xa07670)
- Returns: void
- Parameters: a0: short
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### hs_make_interactive_scripts_deterministic
- Slot: 1777 (table entry 0xa07620)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### threadlib_runtests
- Slot: 1778 (table entry 0xa07850)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### player_set_respawn_vehicle
- Slot: 1779 (table entry 0xa07800)
- Returns: void
- Parameters: a0: player, a1: object_definition
- Kind: normal
- Status: implemented
- Evaluator: function_1b8978 (71 bytes)
- Behavior: Calls function_533e4(player handle, object definition tag handle). Nothing is returned.
- Evidence: S

### teleport_players_into_vehicle
- Slot: 1780 (table entry 0xa077b0)
- Returns: boolean
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_1b89c0 (230 bytes)
- Behavior: Takes a unit (vehicle) handle and always returns false. If the handle is -1 nothing happens. Otherwise it walks the players datum array (per-thread offset 0x18) with function_1381c; for every player whose dword at +0x28 is not -1, function_473d70 gets the root object of the unit argument, function_493bac and function_493c8c walk the units seated in it, and when the player's dword +0x28 value is not found among them function_4a414(player handle, unit handle) is called.
- Evidence: S

### command_buffer_cache_playback_enable
- Slot: 1781 (table entry 0xa07760)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### player_set_spartan_loadout
- Slot: 1782 (table entry 0xa074b0)
- Returns: void
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1b8aa8 (125 bytes)
- Behavior: Takes a player handle. If it is -1 nothing happens. Otherwise byte +0x3e0 of the players datum entry (entries of 0x490 bytes, selected by the low 16 bits of the handle) is set to 0 and function_103cc0 is called. Nothing is returned.
- Evidence: S

### player_set_elite_loadout
- Slot: 1783 (table entry 0xa07460)
- Returns: void
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1b8b28 (125 bytes)
- Behavior: Takes a player handle. If it is -1 nothing happens. Otherwise byte +0x3e0 of the players datum entry (entries of 0x490 bytes, selected by the low 16 bits of the handle) is set to 1 and function_103cc0 is called. Nothing is returned.
- Evidence: S

### auto_graph
- Slot: 1784 (table entry 0xa07410)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### auto_graph_reset
- Slot: 1785 (table entry 0xa073d0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### auto_graph_enable_list
- Slot: 1786 (table entry 0xa075d0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### auto_graph_filter_list
- Slot: 1787 (table entry 0xa07580)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### auto_graph_list
- Slot: 1788 (table entry 0xa07540)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### auto_graph_hide
- Slot: 1789 (table entry 0xa07500)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### location_names_print
- Slot: 1790 (table entry 0xa07260)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_force_host
- Slot: 1791 (table entry 0xa07210)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_force_host_squad
- Slot: 1792 (table entry 0xa071c0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_force_host_posse
- Slot: 1793 (table entry 0xa07170)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_force_host_group
- Slot: 1794 (table entry 0xa07380)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_dump_network_statistics
- Slot: 1795 (table entry 0xa07340)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_enable_block_detection
- Slot: 1796 (table entry 0xa072f0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### main_enable_block_detection
- Slot: 1797 (table entry 0xa072a0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### main_synchronous_networking_request_vblank_slip
- Slot: 1798 (table entry 0xa06ff0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_button_action_mapping_set
- Slot: 1799 (table entry 0xa06fa0)
- Returns: void
- Parameters: a0: long, a1: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### player_appearance_force_model_area
- Slot: 1800 (table entry 0xa06f50)
- Returns: void
- Parameters: a0: long, a1: string_id
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### player_appearance_force_model_area_disable
- Slot: 1801 (table entry 0xa06f00)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_instanced_geometry_names_filter
- Slot: 1802 (table entry 0xa07120)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### stream_manager_load_core
- Slot: 1803 (table entry 0xa070d0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### stream_manager_save_cores
- Slot: 1804 (table entry 0xa07080)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_waypoint_flags
- Slot: 1805 (table entry 0xa07030)
- Returns: void
- Parameters: a0: controller, a1: long, a2: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### waypoint_set_unlock_flag
- Slot: 1806 (table entry 0xa06db0)
- Returns: void
- Parameters: a0: controller, a1: long, a2: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### async_test_hang
- Slot: 1807 (table entry 0xa06d60)
- Returns: void
- Parameters: a0: real, a1: long, a2: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### incidents_force_campaign
- Slot: 1808 (table entry 0xa06d20)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### incidents_force_firefight
- Slot: 1809 (table entry 0xa06ce0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### incidents_force_multiplayer
- Slot: 1810 (table entry 0xa06ec0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### incidents_force_matchmaking
- Slot: 1811 (table entry 0xa06e80)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### incidents_force_custom_games
- Slot: 1812 (table entry 0xa06e40)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### incidents_force_solo
- Slot: 1813 (table entry 0xa06e00)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### incidents_force_coop
- Slot: 1814 (table entry 0xa06b80)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### incidents_force_four_player_coop
- Slot: 1815 (table entry 0xa06b40)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_sound_stress_test_message_queue
- Slot: 1816 (table entry 0xa06b00)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_log_channel_message_queue_state
- Slot: 1817 (table entry 0xa06ab0)
- Returns: void
- Parameters: a0: long, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### global_preferences_set_campaign_state
- Slot: 1818 (table entry 0xa06c90)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### lightmap_memory_inspect
- Slot: 1819 (table entry 0xa06c50)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_set_random_holiday
- Slot: 1820 (table entry 0xa06c10)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### airstrike_enable
- Slot: 1821 (table entry 0xa06bc0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b8ba8 (126 bytes)
- Behavior: Stores the boolean in byte +0 of the airstrike block (per-thread offset 0x1f0). When the boolean is non-zero and the dword at +0x2ec of the scenario tag data is -1, the byte is reset to 0. Nothing is returned.
- Evidence: V

### airstrike_weapons_exist
- Slot: 1822 (table entry 0xa06940)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b8c28 (200 bytes)
- Behavior: Returns false when byte +0 of the airstrike block (per-thread offset 0x1f0) is 0. Otherwise the 16-bit tag index at block +4 is resolved through the tag instance table and the tag chunk table twice (the dword at +4 of that tag data is an offset to a second structure whose dword at +0x48 is read); if that dword is -1 the result is false. Otherwise every object is visited with function_473a78 and the result is true when an object's first dword equals that dword.
- Evidence: S

### airstrike_set_launches
- Slot: 1823 (table entry 0xa068f0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b8cf0 (68 bytes)
- Behavior: Calls function_4daf64 with the long argument. Nothing is returned.
- Evidence: S

### cui_debug_add_global_property_watch
- Slot: 1824 (table entry 0xa068a0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cui_debug_add_property_watch
- Slot: 1825 (table entry 0xa06a60)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cui_debug_remove_global_property_watch
- Slot: 1826 (table entry 0xa06a10)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cui_debug_remove_property_watch
- Slot: 1827 (table entry 0xa069c0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cui_debug_clear_global_property_watches
- Slot: 1828 (table entry 0xa06980)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cui_debug_clear_property_watches
- Slot: 1829 (table entry 0xa06750)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cui_debug_add_global_binding_watch
- Slot: 1830 (table entry 0xa06700)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cui_debug_add_binding_watch
- Slot: 1831 (table entry 0xa066b0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cui_debug_remove_global_binding_watch
- Slot: 1832 (table entry 0xa06660)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cui_debug_remove_binding_watch
- Slot: 1833 (table entry 0xa06850)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cui_debug_clear_global_binding_watches
- Slot: 1834 (table entry 0xa06810)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cui_debug_clear_binding_watches
- Slot: 1835 (table entry 0xa067d0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cui_debug_clear_global
- Slot: 1836 (table entry 0xa06790)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cui_debug_clear
- Slot: 1837 (table entry 0xa064f0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_grief_record_custom_penalty
- Slot: 1838 (table entry 0xa064a0)
- Returns: void
- Parameters: a0: player, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b8d34 (73 bytes)
- Behavior: Calls function_14fa5c(player handle, real). Nothing is returned.
- Evidence: S

### game_grief_reset
- Slot: 1839 (table entry 0xa06460)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_grief_force_social_matchmaking
- Slot: 1840 (table entry 0xa06420)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_grief_force_ranked_matchmaking
- Slot: 1841 (table entry 0xa06620)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_grief_set_ranked_matchmaking_multiplier
- Slot: 1842 (table entry 0xa065d0)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_grief_set_social_matchmaking_multiplier
- Slot: 1843 (table entry 0xa06580)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_grief_set_custom_game_multiplier
- Slot: 1844 (table entry 0xa06530)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_grief_set_objects_in_sphere_radius
- Slot: 1845 (table entry 0xa06290)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_grief_set_ai_multiplier
- Slot: 1846 (table entry 0xa06240)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_grief_set_enemy_ai_nearby_multiplier
- Slot: 1847 (table entry 0xa061f0)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_grief_set_enemy_player_nearby_multiplier
- Slot: 1848 (table entry 0xa061a0)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_grief_set_same_squad_multiplier
- Slot: 1849 (table entry 0xa063d0)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_grief_set_shield_damage_base_penalty
- Slot: 1850 (table entry 0xa06380)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_grief_set_body_damage_base_penalty
- Slot: 1851 (table entry 0xa06330)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_grief_set_betrayal_base_penalty
- Slot: 1852 (table entry 0xa062e0)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_grief_set_betrayal_boot_cutoff
- Slot: 1853 (table entry 0xa06020)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_grief_set_ejection_cutoff
- Slot: 1854 (table entry 0xa05fd0)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_grief_set_betrayal_decay_seconds
- Slot: 1855 (table entry 0xa05f80)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_grief_set_eject_decay_seconds
- Slot: 1856 (table entry 0xa05f30)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### net_disconnect_and_reconnect_all_channels
- Slot: 1857 (table entry 0xa06160)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### player_set_profile (slot 1858)
- Slot: 1858 (table entry 0xa06110)
- Returns: void
- Parameters: a0: starting_profile
- Kind: normal
- Status: implemented
- Evaluator: function_1b8d80 (177 bytes)
- Behavior: Takes a starting profile index (16-bit). Does nothing when it is negative or not below the dword at +0x268 of the scenario tag data. Otherwise the dword at +0x1b0 of every entry of the players datum array (walked with function_1381c) is set to the index. Nothing is returned.
- Evidence: V

### player_set_profile (slot 1859)
- Slot: 1859 (table entry 0xa060c0)
- Returns: void
- Parameters: a0: starting_profile, a1: player
- Kind: normal
- Status: implemented
- Evaluator: function_1b8e34 (147 bytes)
- Behavior: Takes a starting profile index (16-bit) and a player handle. Does nothing when the handle is -1, the index is negative or the index is not below the dword at +0x268 of the scenario tag data. Otherwise the dword at +0x1b0 of that player's datum entry (entries of 0x490 bytes, low 16 bits of the handle) is set to the index. Nothing is returned.
- Evidence: V

### network_session_security_set_challenge_response
- Slot: 1860 (table entry 0xa06070)
- Returns: void
- Parameters: a0: string, a1: boolean, a2: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### network_session_security_set_challenge_failure_on_timeout
- Slot: 1861 (table entry 0xa05dc0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### network_session_security_set_challenge_force_fail
- Slot: 1862 (table entry 0xa05d70)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### network_session_security_disable_challenges
- Slot: 1863 (table entry 0xa05d20)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### test_player_appearance_encode_for_sneakernet
- Slot: 1864 (table entry 0xa05ce0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### test_player_appearance_decode_from_sneakernet
- Slot: 1865 (table entry 0xa05ee0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### ui_content_resize_cache
- Slot: 1866 (table entry 0xa05e90)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### motl_dump_bitvector_for_scenario
- Slot: 1867 (table entry 0xa05e50)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### motl_verify_mapinfo_for_scenario
- Slot: 1868 (table entry 0xa05e10)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### TestPrintBool
- Slot: 1869 (table entry 0xa05b60)
- Returns: void
- Parameters: a0: string, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### TestPrintReal
- Slot: 1870 (table entry 0xa05b10)
- Returns: void
- Parameters: a0: string, a1: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### EnableWeaponTTEDebug
- Slot: 1871 (table entry 0xa05ac0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### ForceFullAutoMagnum
- Slot: 1872 (table entry 0xa05a70)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### ForceAllFullAuto
- Slot: 1873 (table entry 0xa05c90)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### DisablePauseOnDefocus
- Slot: 1874 (table entry 0xa05c40)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### EnablePlayerBarrelStateDebug
- Slot: 1875 (table entry 0xa05bf0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### DisableWeaponTimingFeatures
- Slot: 1876 (table entry 0xa05bb0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### unit_action_test_secondary_trigger
- Slot: 1877 (table entry 0xa059e0)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1b8ec8 (85 bytes)
- Behavior: Returns the boolean result of function_656b8(player handle, 4).
- Evidence: S

### player_action_test_secondary_trigger
- Slot: 1878 (table entry 0xa059a0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b8f20 (44 bytes)
- Behavior: Returns the boolean result of function_655f8(4).
- Evidence: S

### debug_key_evaluate
- Slot: 1879 (table entry 0xa05950)
- Returns: void
- Parameters: a0: string, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### player_machinima_camera_enable_toggle
- Slot: 1880 (table entry 0xa05910)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b8f4c (38 bytes)
- Behavior: Returns the boolean result of function_5d754().
- Evidence: S

### debug_menu_rebuild
- Slot: 1881 (table entry 0xa05a30)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V
