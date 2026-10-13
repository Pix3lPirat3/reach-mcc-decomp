# HaloScript natives, slots 941 to 1410

Part of the HaloScript reference (see the index). Each entry describes one slot of the function table at RVA 0xa28d40. Names, return types and parameter types come from the table strings; behavior is read from the evaluator code. Engine functions are given by address (function_RVA) and module globals as data_RVA. "Not determined" marks where the code was not followed far enough to say. Behavior lists the calls an evaluator can make, in order; a listed call may depend on the arguments or on state, and the text says so where that was checked. In Behavior, a0, a1, ... name the arguments in call order starting at zero.

In this range: 470 slots; 272 implemented, 12 with arguments evaluated and no other effect, 186 not implemented.

Calling convention shared by all evaluators here: the evaluator receives the function index, the script thread handle and a flag byte; function_865e8 evaluates the arguments and returns a pointer to them (or null while an argument still needs evaluation, in which case the evaluator returns at once and is entered again later); the arguments are consecutive 32-bit values, a boolean is one byte at the start of its value; function_85de0 hands the result back to the script thread. "Returns void" below means the evaluator hands back 0. A per-thread block offset such as "per-thread offset 0x320" is an offset into the static thread-local block of the module (reached through the thread environment block and the module thread-local index); the value stored there is a pointer to a state block, and "the block at per-thread offset 0xNN" means that block. Names of the form data_RVA are module globals; function_RVA are engine functions by address.

## State blocks used by the natives in this range

Each row names a per-thread offset, the fields the natives here read or write, and the evidence. Offsets inside a per-player stride (0x114 and 0xc60 bytes below) are measured from the stride address and can exceed the stride, so no origin of the per-player structure is claimed.

| Per-thread offset | Fields seen in this range |
|---|---|
| 0x10 | Object header array: 24-byte entries in the array at +0x50, payload pointer at entry offset 0x10, type byte at entry offset 4 (V) |
| 0x18 | Players array (the in-game players iterator walks it); per-player team byte at +0xac and unit handle at +0x28 of a 0x490-byte entry (V) |
| 0x20 | Game engine state block: survival set counter +0x18c, wave counter +0x190, set multiplier +0x1d4, bonus multiplier +0x1d8, pregame byte +0x1dc, license plate records +0x2e0 to +0x304, accumulators +0x220, +0x260, +0x2a0, fade mask +0x35c0 (V) |
| 0x48 | Game block: byte +0x11 holds a mode value (4 or 5 is tested before marking replication flags), +0x1d9 playtest byte, +0x1da, +0x1eab0, +0x1eab8, +0x1eac0, +0x110ed (V) |
| 0x58 | Camera state: byte +0x58 briefing flag, dword +0x5c active camera string id (V) |
| 0x78 | Cinematic script state: dword +4 cinematic, +8 scene, +0xc shot, +0x10 early exit mode, +0x14 object list count, +0x18 object list of 12-byte entries (V) |
| 0xa0 | Game time block: byte +0 active flag, short +6 ticks per second, real +8 (seconds per tick), dword +0xc (appears to be the current game tick, H) |
| 0xe0 | Cinematic display state: real +0 letterbox amount, byte +4 letterbox flag, byte +6 skip started, byte +7 suppress object creation, byte +0x23 (V) |
| 0x148 | Save request state: dword +0 nonzero while a save is pending (V) |
| 0x150 | Training and tutorial state: dword +0xa00 text string id, bytes +0xa04 and +0xa05 flags; 0x280-byte per-local-player records with byte +0x248 bit 0 (V) |
| 0x168 | Pointer to a render option byte: bit 0 motion blur, bit 1 antialias blur, bit 2 atmosphere fog, bit 3 patchy fog, bit 4 ssao, bit 6 planar fog, bit 7 vsync disable (V) |
| 0x1d8 | Scripted exposure block: flags dword +0 (bit 2 is set by the exposure fades and by cinematic scene destruction, bit 3 enables autoexposure), reals +0xc to +0x23, dword +0x20, start tick +0x24, end tick +0x28 (V) |
| 0x1e0 | Player effect records: 16 strides of 0x114 bytes with flags +0xf8, translation limit +0xfc to +0x104, rotation limit +0x108 to +0x110, start value +0x114, ticks +0x118 and +0x11a (V) |
| 0x2d8 | Rumble state: records of 0x1d8 bytes with values at +0x1d0 and +0x1d4; global rumble values at +0x760 and +0x764 (V) |
| 0x320 | Campaign objectives: ten 8-byte entries starting at +4 (state byte), states set here are 2 (shown) and 3 (finished) (V) |
| 0x3a0 | Scripted sound slot records, 16 bytes each (V) |
| 0x4a8 | Flashlight state: byte +0 enabled, dword +4 tick when it last changed (V) |
| 0x5b0 | HUD records: 16 strides of 0xc60 bytes with per-element visibility reals at +0x330 to +0x34c, fade targets at +0x354 to +0x370, fade durations at +0x378 to +0x394, countdown variable entries (12 bytes each, 10 per player) from +0x2a8, tracked entries (0x20 bytes, 16 per player) at +0xca4; plus global values at +0x168 and +0x16c (V) |
| 0x650 | Cinematic lights: count at +0xc4, 0x148-byte records from +0xc8 (V) |

Several natives index these 16-stride HUD and player-effect arrays by the low 16 bits of a player argument without a range check, so a player index of 16 or more addresses memory past the 16 strides.

### scenario_content_status_force_local
- Slot: 941 (table entry 0xa17150)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### scenario_content_status_force_content
- Slot: 942 (table entry 0xa16ee0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### scenario_content_status_force_clear
- Slot: 943 (table entry 0xa16ea0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### map_reset
- Slot: 944 (table entry 0xa16e60)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1aeda0
- Behavior: Stores 1 into the 16-bit value at data_263eab8 (byte 0 becomes 1, byte 1 becomes 0) and 0 into the byte at data_263eaba, then returns void. These bytes belong to a group of one-shot request flags (data_263eab8 to data_263eabd) polled by the saved-state checkpoint service. Arguments: none. The native only requests the reset; it does not itself reload the map.
- Evidence: V, S

### map_reset_random
- Slot: 945 (table entry 0xa16e20)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### switch_zone_set
- Slot: 946 (table entry 0xa16fe0)
- Returns: void
- Parameters: a0: zone_set
- Kind: normal
- Status: implemented
- Evaluator: function_1aedbc (69 bytes)
- Behavior: Reads the zone set argument (16-bit, sign-extended) and calls function_35370 with it. Returns void. If the argument block cannot be built nothing is called. Called functions: function_35370 (switch zone set).
- Evidence: V, S

### scenario_print_zone_sets
- Slot: 947 (table entry 0xa16fa0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### scenario_print_current_zone_set
- Slot: 948 (table entry 0xa16f60)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### current_zone_set
- Slot: 949 (table entry 0xa16f20)
- Returns: long
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1aee04
- Behavior: Returns the 32-bit value stored at data_afbe30, which is the same value the sibling native passes to function_14bb8 as the zone set index (current zone set index). Arguments: none.
- Evidence: V, S

### current_zone_set_fully_active
- Slot: 950 (table entry 0xa16cb0)
- Returns: long
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1aee14 (54 bytes)
- Behavior: Calls function_14bb8 with the 32-bit value at data_afbe30. If it returns nonzero, returns that same value (the current zone set index); otherwise returns -1. Arguments: none. Called functions: function_14bb8 (zone set is fully active).
- Evidence: V, S

### switch_map_and_zone_set
- Slot: 951 (table entry 0xa16c60)
- Returns: void
- Parameters: a0: string, a1: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### crash
- Slot: 952 (table entry 0xa16c10)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### version
- Slot: 953 (table entry 0xa16bd0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### status
- Slot: 954 (table entry 0xa16de0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### record_movie
- Slot: 955 (table entry 0xa16d90)
- Returns: void
- Parameters: a0: short, a1: real, a2: short, a3: short
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### record_movie_distributed
- Slot: 956 (table entry 0xa16d40)
- Returns: void
- Parameters: a0: short, a1: long, a2: short, a3: long, a4: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### screenshot
- Slot: 957 (table entry 0xa16cf0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### screenshot_big
- Slot: 958 (table entry 0xa16a50)
- Returns: void
- Parameters: a0: short, a1: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### screenshot_big_raw
- Slot: 959 (table entry 0xa16a00)
- Returns: void
- Parameters: a0: short, a1: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### screenshot_size
- Slot: 960 (table entry 0xa169b0)
- Returns: void
- Parameters: a0: short, a1: short, a2: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### screenshot_simple
- Slot: 961 (table entry 0xa16960)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### screenshot_cubemap
- Slot: 962 (table entry 0xa16b80)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### screenshot_webmap
- Slot: 963 (table entry 0xa16b30)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cubemap_dynamic_generate
- Slot: 964 (table entry 0xa16af0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### object_snapshot
- Slot: 965 (table entry 0xa16aa0)
- Returns: void
- Parameters: a0: long, a1: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### structure_instance_snapshot
- Slot: 966 (table entry 0xa167f0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### object_thumbnail
- Slot: 967 (table entry 0xa167a0)
- Returns: void
- Parameters: a0: string, a1: string, a2: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### main_menu
- Slot: 968 (table entry 0xa16760)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### main_halt
- Slot: 969 (table entry 0xa16710)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### map_name
- Slot: 970 (table entry 0xa16910)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_multiplayer
- Slot: 971 (table entry 0xa168c0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_campaign
- Slot: 972 (table entry 0xa16880)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_survival
- Slot: 973 (table entry 0xa16840)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_player_count
- Slot: 974 (table entry 0xa16580)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_set_variant
- Slot: 975 (table entry 0xa16530)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_splitscreen
- Slot: 976 (table entry 0xa164e0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_difficulty
- Slot: 977 (table entry 0xa16490)
- Returns: void
- Parameters: a0: game_difficulty
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_active_skulls
- Slot: 978 (table entry 0xa166c0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_coop_players
- Slot: 979 (table entry 0xa16670)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_initial_zone_set
- Slot: 980 (table entry 0xa16620)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_tick_rate
- Slot: 981 (table entry 0xa165d0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_start
- Slot: 982 (table entry 0xa16340)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_start_when_ready
- Slot: 983 (table entry 0xa16300)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_start_when_joined
- Slot: 984 (table entry 0xa162b0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_rate
- Slot: 985 (table entry 0xa16260)
- Returns: void
- Parameters: a0: real, a1: real, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1aee4c (214 bytes)
- Behavior: Reads three reals a, b, c. Clamps a and b each to the range 0.2 to 5.0 (constants data_a8ac70 and data_a8b2c8). If c is greater than 0.0, writes into the block at per-thread offset 0xa0: dword +0x18 = 0, real +0x1c = c, real +0x20 = clamped a, real +0x24 = clamped b, and then calls function_5ca98 with clamped a. If c is not greater than 0.0 it calls function_5ca98 with clamped b and writes nothing to the record. Returns void. Called functions: function_5ca98 (game rate).
- Evidence: V

### texture_cache_flush
- Slot: 986 (table entry 0xa16450)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### geometry_cache_flush
- Slot: 987 (table entry 0xa16410)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### sound_cache_flush
- Slot: 988 (table entry 0xa163d0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### animation_cache_flush
- Slot: 989 (table entry 0xa16390)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### font_cache_flush
- Slot: 990 (table entry 0xa16110)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### language_set
- Slot: 991 (table entry 0xa160c0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### texture_cache_test_malloc
- Slot: 992 (table entry 0xa16080)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_memory
- Slot: 993 (table entry 0xa16040)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_memory_by_file
- Slot: 994 (table entry 0xa16220)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_memory_for_file
- Slot: 995 (table entry 0xa161d0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_tags
- Slot: 996 (table entry 0xa16190)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_single_tag
- Slot: 997 (table entry 0xa16150)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### tags_verify_all
- Slot: 998 (table entry 0xa15ed0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### trace_next_frame
- Slot: 999 (table entry 0xa15e80)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### trace_next_frame_to_file
- Slot: 1000 (table entry 0xa15e30)
- Returns: void
- Parameters: a0: long, a1: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### trace_tick
- Slot: 1001 (table entry 0xa15de0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### collision_log_enable
- Slot: 1002 (table entry 0xa15ff0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### damage_control_get
- Slot: 1003 (table entry 0xa15fa0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### damage_control_set
- Slot: 1004 (table entry 0xa15f50)
- Returns: void
- Parameters: a0: string, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### ai_lines
- Slot: 1005 (table entry 0xa15f10)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### ai_dialogue_break_on_vocalization
- Slot: 1006 (table entry 0xa15ca0)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### fade_in
- Slot: 1007 (table entry 0xa15c50)
- Returns: void
- Parameters: a0: real, a1: real, a2: real, a3: short
- Kind: normal
- Status: implemented
- Evaluator: function_1aef24 (85 bytes)
- Behavior: Reads three reals (argument offsets 0, 4, 8) and a short (offset 0xc, sign-extended) and passes them to function_d7504 as three floating point arguments plus an integer. Returns void. Called functions: function_d7504 (fade in).
- Evidence: V, S

### fade_out
- Slot: 1008 (table entry 0xa15c00)
- Returns: void
- Parameters: a0: real, a1: real, a2: real, a3: short
- Kind: normal
- Status: implemented
- Evaluator: function_1aef7c (85 bytes)
- Behavior: Same argument handling as the fade-in native (three reals and a sign-extended short) but calls function_d7430. Returns void. Called functions: function_d7430 (fade out).
- Evidence: V, S

### fade_in_for_player
- Slot: 1009 (table entry 0xa15bb0)
- Returns: void
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1aefd4 (116 bytes)
- Behavior: If the player argument is not -1, clears bit N in the 32-bit mask at offset 0x35c0 of the block at per-thread offset 0x20, where N is the low 16 bits of the player argument. Returns void. The argument is not range checked; N is taken modulo 32 by the bit instruction.
- Evidence: V

### fade_out_for_player
- Slot: 1010 (table entry 0xa15d90)
- Returns: void
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1af048 (116 bytes)
- Behavior: If the player argument is not -1, sets bit N in the 32-bit mask at offset 0x35c0 of the block at per-thread offset 0x20, where N is the low 16 bits of the player argument. Returns void. Counterpart of the fade-in-for-player native, which clears the same bit.
- Evidence: V

### cinematic_tag_fade_out_from_game
- Slot: 1011 (table entry 0xa15d40)
- Returns: short
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1af0bc (241 bytes)
- Behavior: Calls function_1eb420 with the string id and keeps its 32-bit result. Calls function_d75d8 with the string id; if that returns something other than -1 and bit 0 of the dword at +0x30 in the tag data it designates is set, writes 1 to the byte at offset 0x23 of the block at per-thread offset 0xe0. Then stores the function_1eb420 result into the dword at offset 0 of the block at per-thread offset 0x78 and calls function_1eb078 with that result and transition mode 0. Returns the 16-bit result of function_1eb078. If the argument block cannot be built it returns nothing. Called functions: function_d75d8 (finds the element of the scenario block (count at scenario +0x77c, 20-byte elements referenced at +0x780) whose tag has the argument at +0x28, and returns the element's first dword, or -1); function_1eb078 (cinematic apply transition); function_1eb420 (returns the dword at +0x48 of the tag found by function_d75d8, or -1).
- Evidence: V

### cinematic_tag_fade_in_to_cinematic
- Slot: 1012 (table entry 0xa15cf0)
- Returns: short
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1af1b0 (93 bytes)
- Behavior: Calls function_1eb420 with the string id and then function_1eb078 with that result and transition mode 1. Returns the 16-bit result of function_1eb078. Called functions: function_1eb078 (cinematic apply transition); function_1eb420 (returns the dword at +0x48 of the tag found by function_d75d8, or -1).
- Evidence: V

### cinematic_tag_fade_out_from_cinematic
- Slot: 1013 (table entry 0xa15ac0)
- Returns: short
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1af210 (93 bytes)
- Behavior: Calls function_1eb420 with the string id and then function_1eb078 with that result and transition mode 2. Returns the 16-bit result of function_1eb078. Called functions: function_1eb078 (cinematic apply transition); function_1eb420 (returns the dword at +0x48 of the tag found by function_d75d8, or -1).
- Evidence: V

### cinematic_tag_fade_in_to_game
- Slot: 1014 (table entry 0xa15a70)
- Returns: short
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1af270 (93 bytes)
- Behavior: Calls function_1eb420 with the string id and then function_1eb078 with that result and transition mode 4. Returns the 16-bit result of function_1eb078. Called functions: function_1eb078 (cinematic apply transition); function_1eb420 (returns the dword at +0x48 of the tag found by function_d75d8, or -1).
- Evidence: V

### cinematic_transition_fade_out_from_game
- Slot: 1015 (table entry 0xa15a20)
- Returns: short
- Parameters: a0: cinematic_transition_definition
- Kind: normal
- Status: implemented
- Evaluator: function_1af2d0 (83 bytes)
- Behavior: Calls function_1eb078 with the transition definition argument and transition mode 0. Returns its 16-bit result. Called functions: function_1eb078 (cinematic apply transition).
- Evidence: V

### cinematic_transition_fade_in_to_cinematic
- Slot: 1016 (table entry 0xa15b60)
- Returns: short
- Parameters: a0: cinematic_transition_definition
- Kind: normal
- Status: implemented
- Evaluator: function_1af324 (86 bytes)
- Behavior: Calls function_1eb078 with the transition definition argument and transition mode 1. Returns its 16-bit result. Called functions: function_1eb078 (cinematic apply transition).
- Evidence: V

### cinematic_transition_fade_out_from_cinematic
- Slot: 1017 (table entry 0xa15b10)
- Returns: short
- Parameters: a0: cinematic_transition_definition
- Kind: normal
- Status: implemented
- Evaluator: function_1af37c (86 bytes)
- Behavior: Calls function_1eb078 with the transition definition argument and transition mode 2. Returns its 16-bit result. Called functions: function_1eb078 (cinematic apply transition).
- Evidence: V

### cinematic_transition_fade_in_to_game
- Slot: 1018 (table entry 0xa158b0)
- Returns: short
- Parameters: a0: cinematic_transition_definition
- Kind: normal
- Status: implemented
- Evaluator: function_1af3d4 (86 bytes)
- Behavior: Calls function_1eb078 with the transition definition argument and transition mode 4. Returns its 16-bit result. Called functions: function_1eb078 (cinematic apply transition).
- Evidence: V

### cinematic_run_script_by_name
- Slot: 1019 (table entry 0xa15860)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1af42c (86 bytes)
- Behavior: Calls function_81be8 with the string id (second argument 0) to find a script by name, which returns a 16-bit script index. If the index is not 0xffff, calls function_85fa0 with it (starts that script). Returns void. Called functions: function_81be8 (hs script find by name); function_85fa0 (hs script run).
- Evidence: V, S

### cinematic_start
- Slot: 1020 (table entry 0xa15820)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1af484 (27 bytes)
- Behavior: Calls function_d3240 and returns void. Arguments: none. Called functions: function_d3240 (cinematic start).
- Evidence: V, S

### cinematic_stop
- Slot: 1021 (table entry 0xa157e0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1af4a0 (27 bytes)
- Behavior: Calls function_d3444 and returns void. Arguments: none. Called functions: function_d3444 (cinematic stop).
- Evidence: V, S

### cinematic_skip_start_internal
- Slot: 1022 (table entry 0xa159e0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1af4bc (100 bytes)
- Behavior: Sets the byte at offset 6 of the block at per-thread offset 0xe0 to 1 and calls function_d31d8 with 0. If the global pointer data_c1a100 is not null, calls the virtual method at vtable offset 0x340 of that object with a pointer to data_9d8b88, two byte arguments equal to 1 and a fifth argument 0. Returns void. Arguments: none. Called functions: function_d31d8 (cinematic skip start internal).
- Evidence: V

### cinematic_skip_stop_internal
- Slot: 1023 (table entry 0xa159a0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1af520 (27 bytes)
- Behavior: Calls function_d36f8 and returns void. Arguments: none. Called functions: function_d36f8 (cinematic skip stop internal).
- Evidence: V, S

### cinematic_show_letterbox
- Slot: 1024 (table entry 0xa15950)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1af53c (95 bytes)
- Behavior: Writes the boolean argument to the byte at offset 4 of the block at per-thread offset 0xe0. Returns void.
- Evidence: V

### cinematic_show_letterbox_immediate
- Slot: 1025 (table entry 0xa15900)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1af59c (116 bytes)
- Behavior: Writes the boolean argument to the byte at offset 4 of the block at per-thread offset 0xe0 and writes the real 1.0 (data_a8af18) at offset 0 of the same block when the boolean is true, 0.0 when it is false. Returns void.
- Evidence: V

### cinematic_set_title
- Slot: 1026 (table entry 0xa15660)
- Returns: void
- Parameters: a0: cutscene_title
- Kind: normal
- Status: implemented
- Evaluator: function_1af610 (72 bytes)
- Behavior: Calls function_d388c with the 16-bit title index (zero-extended) and the real 0.0. Returns void. Called functions: function_d388c (cinematic set title).
- Evidence: V, S

### cinematic_set_title_delayed
- Slot: 1027 (table entry 0xa15610)
- Returns: void
- Parameters: a0: cutscene_title, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1af658 (74 bytes)
- Behavior: Calls function_d388c with the 16-bit title index (zero-extended) and the real argument as the second value. Returns void. Called functions: function_d388c (cinematic set title).
- Evidence: V, S

### cinematic_suppress_bsp_object_creation
- Slot: 1028 (table entry 0xa155c0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1af6a4 (95 bytes)
- Behavior: Writes the boolean argument to the byte at offset 7 of the block at per-thread offset 0xe0. Returns void.
- Evidence: V

### cinematic_subtitle
- Slot: 1029 (table entry 0xa15570)
- Returns: void
- Parameters: a0: string_id, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1af704 (79 bytes)
- Behavior: Calls function_d5e34 with the string id, the real argument and a constant 1. Returns void. Called functions: function_d5e34 (cinematic subtitle).
- Evidence: V, S

### cinematic_set
- Slot: 1030 (table entry 0xa15790)
- Returns: void
- Parameters: a0: cinematic_definition
- Kind: normal
- Status: implemented
- Evaluator: function_1af754 (95 bytes)
- Behavior: Writes the cinematic definition argument to the dword at offset 4 of the block at per-thread offset 0x78. Returns void.
- Evidence: V

### cinematic_set_shot
- Slot: 1031 (table entry 0xa15740)
- Returns: void
- Parameters: a0: cinematic_scene_definition, a1: long
- Kind: normal
- Status: implemented
- Evaluator: function_1af7b4 (103 bytes)
- Behavior: Writes the scene argument to the dword at offset 8 and the shot number to the dword at offset 0xc of the block at per-thread offset 0x78. Returns void.
- Evidence: V

### cinematic_get_shot
- Slot: 1032 (table entry 0xa15700)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cinematic_set_early_exit
- Slot: 1033 (table entry 0xa156b0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1af81c (95 bytes)
- Behavior: Writes the long argument to the dword at offset 0x10 of the block at per-thread offset 0x78. Returns void.
- Evidence: V

### cinematic_get_early_exit
- Slot: 1034 (table entry 0xa15420)
- Returns: long
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1af87c
- Behavior: Returns the dword at offset 0x10 of the block at per-thread offset 0x78. Arguments: none.
- Evidence: V

### cinematic_set_active_camera
- Slot: 1035 (table entry 0xa153d0)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1af8a8 (95 bytes)
- Behavior: Writes the string id argument to the dword at offset 0x5c of the block at per-thread offset 0x58. Returns void.
- Evidence: V

### cinematic_object_create
- Slot: 1036 (table entry 0xa15380)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1af908 (68 bytes)
- Behavior: Calls function_d6088 with the string id. Returns void. Called functions: function_d6088 (cinematic object create).
- Evidence: V, S

### cinematic_object_create_cinematic_anchor
- Slot: 1037 (table entry 0xa15330)
- Returns: void
- Parameters: a0: cutscene_flag
- Kind: normal
- Status: implemented
- Evaluator: function_1af94c (69 bytes)
- Behavior: Calls function_d6e4c with the 16-bit cutscene flag index (sign-extended). Returns void. Called functions: function_d6e4c (cinematic object create cinematic anchor).
- Evidence: V, S

### cinematic_object_destroy
- Slot: 1038 (table entry 0xa15520)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1af994 (169 bytes)
- Behavior: Walks the list held by the block at per-thread offset 0x78 (entry count at offset 0x14, entries of 12 bytes starting at offset 0x18). For every entry whose first dword equals the string id it calls function_d63f4 with the entry index, and keeps walking. Returns void. Called functions: function_d63f4 (cinematic object destroy).
- Evidence: V

### cinematic_objects_destroy_all
- Slot: 1039 (table entry 0xa154e0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1afa40 (27 bytes)
- Behavior: Calls function_d647c and returns void. Arguments: none. Called functions: function_d647c (cinematic objects destroy all).
- Evidence: V, S

### cinematic_destroy
- Slot: 1040 (table entry 0xa154a0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1afa5c (27 bytes)
- Behavior: Calls function_d6acc and returns void. Arguments: none. Called functions: function_d6acc (cinematic destroy).
- Evidence: V, S

### cinematic_in_progress
- Slot: 1041 (table entry 0xa15460)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated. The declared return type is boolean, so scripts receive 0 (false for boolean).
- Evidence: V

### cinematic_can_be_skipped
- Slot: 1042 (table entry 0xa15220)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated. The declared return type is boolean, so scripts receive 0 (false for boolean).
- Evidence: V

### cinematic_clips_initialize_for_shot
- Slot: 1043 (table entry 0xa151d0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1afa78 (68 bytes)
- Behavior: Calls function_d6b98 with the long argument and returns void. Called functions: function_d6b98 (cinematic clips initialize for shot).
- Evidence: V, S

### cinematic_clips_destroy
- Slot: 1044 (table entry 0xa15190)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1afabc (27 bytes)
- Behavior: Calls function_d6d94 and returns void. Arguments: none. Called functions: function_d6d94 (cinematic clips destroy).
- Evidence: V, S

### cinematic_lights_initialize_for_shot
- Slot: 1045 (table entry 0xa152e0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1afad8 (68 bytes)
- Behavior: Calls function_1edc28 with the long argument and returns void. Called functions: function_1edc28 (cinematic lights initialize for shot).
- Evidence: V, S

### cinematic_lights_destroy
- Slot: 1046 (table entry 0xa152a0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1afb1c (27 bytes)
- Behavior: Calls function_1ede48 and returns void. Arguments: none. Called functions: function_1ede48 (cinematic lights destroy).
- Evidence: V, S

### cinematic_lights_destroy_shot
- Slot: 1047 (table entry 0xa15260)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1afb38 (27 bytes)
- Behavior: Calls function_1edda4 and returns void. Arguments: none. Called functions: function_1edda4 (cinematic lights destroy shot).
- Evidence: V, S

### cinematic_light_object
- Slot: 1048 (table entry 0xa15050)
- Returns: void
- Parameters: a0: object, a1: string_id, a2: cinematic_lightprobe, a3: cutscene_camera_point
- Kind: normal
- Status: implemented
- Evaluator: function_1afb54 (80 bytes)
- Behavior: Calls function_1edf14 with the object (dword at offset 0), the string id (offset 4), the lightprobe argument (dword at offset 8) and the camera point (16-bit at offset 0xc, zero-extended). Returns void. Called functions: function_1edf14 (cinematic light object).
- Evidence: V, S

### cinematic_light_object_off
- Slot: 1049 (table entry 0xa15000)
- Returns: void
- Parameters: a0: object
- Kind: normal
- Status: implemented
- Evaluator: function_1afba4 (68 bytes)
- Behavior: Calls function_1ee010 with the object argument and returns void. Called functions: function_1ee010 (cinematic light object off).
- Evidence: V, S

### cinematic_lighting_rebuild_all
- Slot: 1050 (table entry 0xa14fc0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1afbe8 (185 bytes)
- Behavior: Reads the light count (dword at offset 0xc4) of the block at per-thread offset 0x650. For each light in turn (records of 0x148 bytes starting at offset 0xc8 of that block) it sets the four dwords at record offsets 0x100, 0x104, 0x108 and 0x10c to 1.0 and calls function_1ed838 with a pointer to the record, the dword at record offset 0, the dword at record offset 0x110 and a pointer to record offset 0x114. Returns void. Arguments: none. Called functions: function_1ed838 (cinematic light initialize from definition).
- Evidence: V, S

### cinematic_lighting_update_dynamic_light_direction
- Slot: 1051 (table entry 0xa15140)
- Returns: void
- Parameters: a0: string, a1: long, a2: real, a3: real, a4: real
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (so any nested calls still run) and then returns 0. It calls no engine function and reads or writes no state. Shared evaluator (11 slots in this range).
- Evidence: V

### cinematic_lighting_update_vmf_light
- Slot: 1052 (table entry 0xa150f0)
- Returns: void
- Parameters: a0: string, a1: real, a2: real, a3: real, a4: real, a5: real, a6: real, a7: real
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (so any nested calls still run) and then returns 0. It calls no engine function and reads or writes no state. Shared evaluator (11 slots in this range).
- Evidence: V

### cinematic_lighting_update_analytical_light
- Slot: 1053 (table entry 0xa150a0)
- Returns: void
- Parameters: a0: string, a1: real, a2: real, a3: real, a4: real, a5: real, a6: real
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (so any nested calls still run) and then returns 0. It calls no engine function and reads or writes no state. Shared evaluator (11 slots in this range).
- Evidence: V

### cinematic_lighting_update_ambient_light
- Slot: 1054 (table entry 0xa14e80)
- Returns: void
- Parameters: a0: string, a1: real, a2: real, a3: real, a4: real
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (so any nested calls still run) and then returns 0. It calls no engine function and reads or writes no state. Shared evaluator (11 slots in this range).
- Evidence: V

### cinematic_lighting_update_scales
- Slot: 1055 (table entry 0xa14e30)
- Returns: void
- Parameters: a0: string, a1: real, a2: real, a3: real, a4: real
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (so any nested calls still run) and then returns 0. It calls no engine function and reads or writes no state. Shared evaluator (11 slots in this range).
- Evidence: V

### cinematic_object_get
- Slot: 1056 (table entry 0xa14f70)
- Returns: object
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1afca4 (68 bytes)
- Behavior: Calls function_237020 with the string id and returns the 32-bit object handle it produces (-1 style failure value is whatever that function returns). Called functions: function_237020 (cinematic object get).
- Evidence: V, S

### cinematic_unit_get
- Slot: 1057 (table entry 0xa14f20)
- Returns: unit
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1afce8 (95 bytes)
- Behavior: Calls function_237020 with the string id to get an object handle, then function_47d8a0 to test that the handle refers to a unit. Returns the handle if it is a unit, -1 otherwise. Called functions: function_237020 (cinematic object get); function_47d8a0 (object try and dynamic cast to unit).
- Evidence: V, S

### cinematic_weapon_get
- Slot: 1058 (table entry 0xa14ed0)
- Returns: weapon
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1afd48 (153 bytes)
- Behavior: Calls function_237020 with the string id to get an object handle, then function_4739cc with the handle and -1 to resolve it. If that gives an object whose header type byte (24-byte header entries in the array at +0x50 of the block at per-thread offset 0x10, byte at offset 4) equals 2, returns the handle; otherwise returns -1. Called functions: function_237020 (cinematic object get); function_4739cc (object try and get and verify type).
- Evidence: V, S

### cinematic_reset
- Slot: 1059 (table entry 0xa14cb0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### camera_set_briefing
- Slot: 1060 (table entry 0xa14c60)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1afde4 (95 bytes)
- Behavior: Writes the boolean argument to the byte at offset 0x58 of the block at per-thread offset 0x58. Returns void.
- Evidence: V

### cinematic_tag_reference_get_cinematic
- Slot: 1061 (table entry 0xa14c10)
- Returns: cinematic_definition
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1afe44 (111 bytes)
- Behavior: Reads the scenario tag data pointer at data_c1a230, takes the dword at offset 0x780 as the location of a tag block whose elements are 20 bytes long, and returns the dword at offset 0x10 of element number (long argument). The index is not range checked.
- Evidence: V

### cinematic_tag_reference_get_scene
- Slot: 1062 (table entry 0xa14bc0)
- Returns: cinematic_scene_definition
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1afeb4 (68 bytes)
- Behavior: Calls function_d66c4 with the long argument and returns its 32-bit result. Called functions: function_d66c4 (cinematic tag reference get scene).
- Evidence: V, S

### cinematic_tag_reference_get_effect
- Slot: 1063 (table entry 0xa14de0)
- Returns: effect
- Parameters: a0: long, a1: long, a2: long, a3: long
- Kind: normal
- Status: implemented
- Evaluator: function_1afef8 (79 bytes)
- Behavior: Calls function_d6728 with the four long arguments (in order) and returns its 32-bit result. Called functions: function_d6728 (cinematic tag reference get effect).
- Evidence: V, S

### cinematic_tag_reference_get_dialogue
- Slot: 1064 (table entry 0xa14d90)
- Returns: sound
- Parameters: a0: long, a1: long, a2: long, a3: long
- Kind: normal
- Status: implemented
- Evaluator: function_1aff48 (79 bytes)
- Behavior: Calls function_d681c with the four long arguments (in order) and returns its 32-bit result. Called functions: function_d681c (cinematic tag reference get dialogue).
- Evidence: V, S

### cinematic_tag_reference_get_music
- Slot: 1065 (table entry 0xa14d40)
- Returns: sound
- Parameters: a0: long, a1: long, a2: long, a3: long
- Kind: normal
- Status: implemented
- Evaluator: function_1aff98 (79 bytes)
- Behavior: Calls function_d6910 with the four long arguments (in order) and returns its 32-bit result. Both natives that use this evaluator behave identically. This evaluator is shared with cinematic_tag_reference_get_music_looping. Called functions: function_d6910 (cinematic tag reference get music).
- Evidence: V, S

### cinematic_tag_reference_get_music_looping
- Slot: 1066 (table entry 0xa14cf0)
- Returns: looping_sound
- Parameters: a0: long, a1: long, a2: long, a3: long
- Kind: normal
- Status: implemented
- Evaluator: function_1aff98 (79 bytes)
- Behavior: Calls function_d6910 with the four long arguments (in order) and returns its 32-bit result. Both natives that use this evaluator behave identically. This evaluator is shared with cinematic_tag_reference_get_music. Called functions: function_d6910 (cinematic tag reference get music).
- Evidence: V, S

### cinematic_tag_reference_get_animation
- Slot: 1067 (table entry 0xa14ad0)
- Returns: animation_graph
- Parameters: a0: long, a1: long, a2: long
- Kind: normal
- Status: implemented
- Evaluator: function_1affe8 (75 bytes)
- Behavior: Calls function_d6a04 with the three long arguments (in order) and returns its 32-bit result. Called functions: function_d6a04 (cinematic tag reference get animation).
- Evidence: V, S

### cinematic_scripting_object_coop_flags_valid
- Slot: 1068 (table entry 0xa14a80)
- Returns: boolean
- Parameters: a0: long, a1: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b0034 (83 bytes)
- Behavior: Calls function_236a50 with the two long arguments and returns its boolean result. Called functions: function_236a50 (cinematic scripting object coop flags valid).
- Evidence: V, S

### cinematic_scripting_fade_out
- Slot: 1069 (table entry 0xa14a30)
- Returns: void
- Parameters: a0: real, a1: real, a2: real, a3: short
- Kind: normal
- Status: implemented
- Evaluator: function_1b0088 (120 bytes)
- Behavior: If the dword at offset 0x10 of the block at per-thread offset 0x78 equals 2, does nothing. Otherwise calls function_d7430 with the three reals and the sign-extended short (the same routine the fade-out native uses). Returns void. Called functions: function_d7430 (fade out).
- Evidence: V

### cinematic_scripting_create_object
- Slot: 1070 (table entry 0xa14b70)
- Returns: void
- Parameters: a0: long, a1: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b0100 (71 bytes)
- Behavior: Calls function_236ac0 with the two long arguments. Returns void. Called functions: function_236ac0 (cinematic scripting create object).
- Evidence: V, S

### cinematic_scripting_create_cinematic_object
- Slot: 1071 (table entry 0xa14b20)
- Returns: void
- Parameters: a0: long, a1: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b0148 (71 bytes)
- Behavior: Calls function_236b90 with the two long arguments. Returns void. Called functions: function_236b90 (cinematic scripting create cinematic object).
- Evidence: V, S

### cinematic_scripting_start_animation
- Slot: 1072 (table entry 0xa148f0)
- Returns: void
- Parameters: a0: long, a1: long, a2: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b0190 (75 bytes)
- Behavior: Calls function_236c08 with the two long arguments and the string id. Returns void. Called functions: function_236c08 (cinematic scripting start animation).
- Evidence: V, S

### cinematic_scripting_destroy_object
- Slot: 1073 (table entry 0xa148a0)
- Returns: void
- Parameters: a0: long, a1: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b01dc (71 bytes)
- Behavior: Calls function_2371bc with the two long arguments. Returns void. Called functions: function_2371bc (cinematic scripting destroy object).
- Evidence: V, S

### cinematic_scripting_destroy_objects
- Slot: 1074 (table entry 0xa14850)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b0224 (68 bytes)
- Behavior: Calls function_2372ac with the long argument. Returns void. Called functions: function_2372ac (cinematic scripting destroy objects).
- Evidence: V, S

### cinematic_scripting_create_scene
- Slot: 1075 (table entry 0xa149e0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b0268 (106 bytes)
- Behavior: Calls function_d66c4 with the long argument and stores the result in the dword at offset 8 of the block at per-thread offset 0x78, and clears the dword at offset 0xc of the same block. Returns void. Called functions: function_d66c4 (cinematic tag reference get scene).
- Evidence: V, S

### cinematic_scripting_destroy_scene
- Slot: 1076 (table entry 0xa14990)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b02d4 (221 bytes)
- Behavior: Calls function_1ede48 and function_d6d94, then updates the scripted exposure block at per-thread offset 0x1d8 (the same writes as render_exposure_fade_out with a duration of 0.0): sets bit 2 of the dword at offset 0, copies the real at +0xc to +0x1c and the real at +0x10 to +0x14 and +0x18, clears the dword at +0x20, copies the dword at +0xc of the block at per-thread offset 0xa0 to +0x24, and stores into +0x28 the same dword plus ceil(short at +6 of the per-thread offset 0xa0 block multiplied by data_a7a434, which holds 0.0 in the module image). Finally calls function_2372ac with the long argument. Returns void. Called functions: function_d6d94 (cinematic clips destroy); function_1ede48 (cinematic lights destroy); function_2372ac (cinematic scripting destroy objects); function_91a13e (ceiling of a real).
- Evidence: V

### cinematic_scripting_start_effect
- Slot: 1077 (table entry 0xa14940)
- Returns: void
- Parameters: a0: long, a1: long, a2: long, a3: object
- Kind: normal
- Status: implemented
- Evaluator: function_1b03b4 (203 bytes)
- Behavior: Calls function_236a04 with the first long to get a scene record (null stops the native). The second long must be below the count at +0x2c of that record; it selects an 0xd0-byte shot element (52 dwords) in the block referenced at +0x30. The third long must be below the count at +0x58 of the shot; it selects a 40-byte element in the block referenced at +0x5c. It then calls function_1ecedc with the dword at +0x10 of that element, the object argument, the dword at +0x18 of that element and 0. Out-of-range indexes make it do nothing. Returns void. Called functions: function_1ecedc (effect new on object marker); function_236a04 (cinematic scripting get scene).
- Evidence: V, S

### cinematic_scripting_start_music
- Slot: 1078 (table entry 0xa14710)
- Returns: void
- Parameters: a0: long, a1: long, a2: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b0480 (75 bytes)
- Behavior: Calls function_2372f4 with the three long arguments. Returns void. Called functions: function_2372f4 (cinematic scripting start music).
- Evidence: V, S

### cinematic_scripting_start_dialogue
- Slot: 1079 (table entry 0xa146c0)
- Returns: void
- Parameters: a0: long, a1: long, a2: long, a3: object
- Kind: normal
- Status: implemented
- Evaluator: function_1b04cc (79 bytes)
- Behavior: Calls function_2373dc with the three long arguments and the object. Returns void. Called functions: function_2373dc (cinematic scripting start dialogue).
- Evidence: V, S

### cinematic_scripting_stop_music
- Slot: 1080 (table entry 0xa14800)
- Returns: void
- Parameters: a0: long, a1: long, a2: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b051c (211 bytes)
- Behavior: Gets the scene record with function_236a04 (first long), picks the shot (second long, range checked against the count at +0x2c, 0xd0-byte elements) and the sound element (third long, range checked against the count at +0x4c, 24-byte elements in the block referenced at +0x50). If the dword at +4 of that element is the group id 0x6c736e64 ('lsnd') and the dword at +0x10 is not -1, calls function_c16c0 with that handle and 0. Otherwise does nothing. Returns void. Called functions: function_c16c0 (sound looping stop); function_236a04 (cinematic scripting get scene).
- Evidence: V, S

### cinematic_scripting_start_screen_effect
- Slot: 1081 (table entry 0xa147b0)
- Returns: void
- Parameters: a0: long, a1: long, a2: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b05f0 (75 bytes)
- Behavior: Calls function_237548 with the three long arguments. Returns void. Called functions: function_237548 (cinematic scripting start screen effect).
- Evidence: V, S

### cinematic_scripting_stop_screen_effect
- Slot: 1082 (table entry 0xa14760)
- Returns: void
- Parameters: a0: long, a1: long, a2: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b063c (75 bytes)
- Behavior: Calls function_237658 with the three long arguments. Returns void. Called functions: function_237658 (cinematic scripting stop screen effect).
- Evidence: V, S

### cinematic_scripting_create_and_animate_object
- Slot: 1083 (table entry 0xa14590)
- Returns: void
- Parameters: a0: long, a1: long, a2: long, a3: string_id, a4: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b0688 (86 bytes)
- Behavior: Calls function_236d60 with the first four arguments in order (three longs and the string id) and the boolean passed on the stack. Returns void. The native that creates a cinematic object and the one that creates an ordinary object share this evaluator. This evaluator is shared with cinematic_scripting_create_and_animate_cinematic_object. Called functions: function_236d60 (cinematic scripting create and animate object).
- Evidence: V, S

### cinematic_scripting_create_and_animate_cinematic_object
- Slot: 1084 (table entry 0xa14540)
- Returns: void
- Parameters: a0: long, a1: long, a2: long, a3: string_id, a4: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b0688 (86 bytes)
- Behavior: Calls function_236d60 with the first four arguments in order (three longs and the string id) and the boolean passed on the stack. Returns void. The native that creates a cinematic object and the one that creates an ordinary object share this evaluator. This evaluator is shared with cinematic_scripting_create_and_animate_object. Called functions: function_236d60 (cinematic scripting create and animate object).
- Evidence: V, S

### cinematic_scripting_create_and_animate_object_no_animation
- Slot: 1085 (table entry 0xa144f0)
- Returns: void
- Parameters: a0: long, a1: long, a2: long, a3: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b06e0 (85 bytes)
- Behavior: Calls function_236d60 with the three long arguments, 0 in place of the string id and the boolean passed on the stack. Returns void. Both natives using this evaluator behave identically. This evaluator is shared with cinematic_scripting_create_and_animate_cinematic_object_no_animation. Called functions: function_236d60 (cinematic scripting create and animate object).
- Evidence: V, S

### cinematic_scripting_create_and_animate_cinematic_object_no_animation
- Slot: 1086 (table entry 0xa14670)
- Returns: void
- Parameters: a0: long, a1: long, a2: long, a3: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b06e0 (85 bytes)
- Behavior: Calls function_236d60 with the three long arguments, 0 in place of the string id and the boolean passed on the stack. Returns void. Both natives using this evaluator behave identically. This evaluator is shared with cinematic_scripting_create_and_animate_object_no_animation. Called functions: function_236d60 (cinematic scripting create and animate object).
- Evidence: V, S

### cinematic_scripting_set_user_input_constraints
- Slot: 1087 (table entry 0xa14620)
- Returns: void
- Parameters: a0: long, a1: long, a2: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b0738 (213 bytes)
- Behavior: Gets the scene record with function_236a04 (first long) and picks the shot (second long, range checked, 0xd0-byte elements). The third long must be below the count at +0x88 of the shot; it selects a 20-byte element in the block referenced at +0x8c. It calls function_1d7cc8 with the dword at +4 of that element, a pointer to the element plus 8, and the real at +0x10. Returns void; out-of-range or null does nothing. Called functions: function_1d7cc8 (cinematic scripting set user input constraints); function_236a04 (cinematic scripting get scene).
- Evidence: V, S

### attract_mode_start
- Slot: 1088 (table entry 0xa145e0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### attract_mode_set_seconds
- Slot: 1089 (table entry 0xa143e0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_won
- Slot: 1090 (table entry 0xa143a0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b0810 (79 bytes)
- Behavior: Calls function_586c4. If it returns true and the byte at offset 0x1eab8 of the block at per-thread offset 0x48 is zero, sets the byte at offset 0x1eac0 of that block to 1 and calls function_59330. Returns void. Arguments: none. Called functions: function_586c4 (true when the block at per-thread offset 0x48 exists, its byte at +0x1eab0 is nonzero, its byte at +0 is zero and its byte at +1 is nonzero); function_59330 (game won).
- Evidence: V, S

### game_lost
- Slot: 1091 (table entry 0xa14350)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b0860 (68 bytes)
- Behavior: Calls function_5922c with the boolean argument and returns void. Called functions: function_5922c (game lost).
- Evidence: V, S

### game_revert
- Slot: 1092 (table entry 0xa14310)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b08a4
- Behavior: Stores the 16-bit value 0x0c01 at data_263eabb (byte 0x01 at data_263eabb, byte 0x0c at data_263eabc). These are part of the one-shot request flag group at data_263eab8 polled by the checkpoint service. Returns void. Arguments: none.
- Evidence: V, S

### game_award_level_complete_achievements
- Slot: 1093 (table entry 0xa144b0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b08b8 (27 bytes)
- Behavior: Calls function_5907c and returns void. Arguments: none. Called functions: function_5907c (game award level complete achievements).
- Evidence: V, S

### game_is_cooperative
- Slot: 1094 (table entry 0xa14470)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b08d4 (39 bytes)
- Behavior: Calls function_58ce4 and returns its boolean result. Arguments: none. Called functions: function_58ce4 (game is cooperative).
- Evidence: V, S

### game_is_playtest
- Slot: 1095 (table entry 0xa14430)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b08fc
- Behavior: Returns the byte at offset 0x1d9 of the block at per-thread offset 0x48. Arguments: none.
- Evidence: V

### game_can_use_flashlights
- Slot: 1096 (table entry 0xa14190)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b0938 (129 bytes)
- Behavior: If the byte at offset 0 of the block at per-thread offset 0x4a8 differs from the boolean argument, stores the new value there and sets the dword at offset 4 of that block to the dword at +0xc of the block at per-thread offset 0xa0 when function_586c4 returns true, otherwise to 0. If the byte already matches nothing changes. Returns void. Called functions: function_586c4 (true when the block at per-thread offset 0x48 exists, its byte at +0x1eab0 is nonzero, its byte at +0 is zero and its byte at +1 is nonzero).
- Evidence: V, S

### game_save_and_quit
- Slot: 1097 (table entry 0xa14150)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_save_unsafe
- Slot: 1098 (table entry 0xa14110)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_insertion_point_unlock
- Slot: 1099 (table entry 0xa140c0)
- Returns: void
- Parameters: a0: short
- Kind: normal
- Status: implemented
- Evaluator: function_1b09bc (159 bytes)
- Behavior: Accepts the short argument if it is 0xb or lower, the byte at offset 0x10 of the block at per-thread offset 0x48 equals 1 and function_58eec returns false. It then calls function_3d564 with pointers to +0x2c and +0x3c of that block and, when the returned index is 0x3f or lower, runs an empty loop. It writes no state in this build. Called functions: function_3d564 (levels get campaign level index); function_58eec (true when a game is active (function_588e0) and the byte at offset 0x1da of the block at per-thread offset 0x48 is nonzero).
- Evidence: V

### game_insertion_point_lock
- Slot: 1100 (table entry 0xa142c0)
- Returns: void
- Parameters: a0: short
- Kind: normal
- Status: implemented
- Evaluator: function_1b0a5c (154 bytes)
- Behavior: Same checks as the insertion point unlock native (short argument 0xb or lower, byte at +0x10 of the block at per-thread offset 0x48 equal to 1, function_58eec false) followed by a call to function_3d564 and an empty loop. It writes no state in this build. Called functions: function_3d564 (levels get campaign level index); function_58eec (true when a game is active (function_588e0) and the byte at offset 0x1da of the block at per-thread offset 0x48 is nonzero).
- Evidence: V

### game_insertion_point_set
- Slot: 1101 (table entry 0xa14270)
- Returns: void
- Parameters: a0: short
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (so any nested calls still run) and then returns 0. It calls no engine function and reads or writes no state. Shared evaluator (11 slots in this range).
- Evidence: V

### saved_games_delete_campaign_save
- Slot: 1102 (table entry 0xa14220)
- Returns: void
- Parameters: a0: controller
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### saved_games_autosave_free_up_space
- Slot: 1103 (table entry 0xa141e0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### achievement_grant_to_player
- Slot: 1104 (table entry 0xa13f30)
- Returns: void
- Parameters: a0: player, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b0af8 (71 bytes)
- Behavior: Calls function_c3e24 with the player argument and the string id. Returns void. Called functions: function_c3e24 (achievement grant to player).
- Evidence: V, S

### achievement_grant_to_controller
- Slot: 1105 (table entry 0xa13ee0)
- Returns: void
- Parameters: a0: controller, a1: string_id
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### achievement_grant_to_all_players
- Slot: 1106 (table entry 0xa13e90)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### achievements_enable
- Slot: 1107 (table entry 0xa13e40)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### achievements_skip_validation_checks
- Slot: 1108 (table entry 0xa14070)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_spawning_influencers
- Slot: 1109 (table entry 0xa14020)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_spawning_respawn_zones
- Slot: 1110 (table entry 0xa13fd0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_spawning_proximity_forbid
- Slot: 1111 (table entry 0xa13f80)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_spawning_moving_vehicle
- Slot: 1112 (table entry 0xa13cb0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_spawning_weapon_influences
- Slot: 1113 (table entry 0xa13c60)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_spawning_dangerous_projectiles
- Slot: 1114 (table entry 0xa13c10)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_spawning_deployed_equipment
- Slot: 1115 (table entry 0xa13bc0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_spawning_proximity_enemy
- Slot: 1116 (table entry 0xa13df0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_spawning_teammates
- Slot: 1117 (table entry 0xa13da0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_spawning_dead_teammates
- Slot: 1118 (table entry 0xa13d50)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_spawning_random_influence
- Slot: 1119 (table entry 0xa13d00)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_spawning_nominal_weight
- Slot: 1120 (table entry 0xa13a30)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_spawning_natural_weight
- Slot: 1121 (table entry 0xa139e0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_spawning_target
- Slot: 1122 (table entry 0xa13990)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_spawning_use_history
- Slot: 1123 (table entry 0xa13940)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_initial_spawn_point_objects
- Slot: 1124 (table entry 0xa13b70)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_respawn_point_objects
- Slot: 1125 (table entry 0xa13b20)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_export_variant_settings
- Slot: 1126 (table entry 0xa13ad0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_engine_event_test_general
- Slot: 1127 (table entry 0xa13a80)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_engine_event_test_flavor
- Slot: 1128 (table entry 0xa137c0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### core_load
- Slot: 1129 (table entry 0xa13780)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b0b40 (54 bytes)
- Behavior: Sets the byte at data_263ea77 to 1 and copies the string 'core' (data_990290) into the 0x40-byte buffer at data_263ea78 with function_117b8. Returns void. Arguments: none. Called functions: function_117b8 (string copy padded).
- Evidence: V

### core_load_name
- Slot: 1130 (table entry 0xa13730)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: implemented
- Evaluator: function_1b0b78 (97 bytes)
- Behavior: Resolves the string argument with function_1990a0, sets the byte at data_263ea77 to 1 and copies the resolved string into the 0x40-byte buffer at data_263ea78 with function_117b8. Returns void. Called functions: function_117b8 (string copy padded); function_1990a0 (resolves a string argument of a script call to its character data).
- Evidence: V

### core_save
- Slot: 1131 (table entry 0xa136f0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### core_save_name
- Slot: 1132 (table entry 0xa138f0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (so any nested calls still run) and then returns 0. It calls no engine function and reads or writes no state. Shared evaluator (11 slots in this range).
- Evidence: V

### core_load_game
- Slot: 1133 (table entry 0xa138b0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### core_load_game_name
- Slot: 1134 (table entry 0xa13860)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### core_regular_upload_to_debug_server
- Slot: 1135 (table entry 0xa13810)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### core_set_upload_option
- Slot: 1136 (table entry 0xa135a0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### core_force_immediate_save_on_core_load
- Slot: 1137 (table entry 0xa13550)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### force_debugger_not_present
- Slot: 1138 (table entry 0xa13500)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### force_debugger_always_present
- Slot: 1139 (table entry 0xa134b0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### game_safe_to_save
- Slot: 1140 (table entry 0xa136b0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b0bdc (39 bytes)
- Behavior: Calls function_166560 and returns its boolean result. Arguments: none. Called functions: function_166560 (game safe to save).
- Evidence: V, S

### game_safe_to_speak
- Slot: 1141 (table entry 0xa13670)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b0c04 (86 bytes)
- Behavior: Calls function_4f2810 with a pointer to a dword set to -1; if it returns true the result is false. Otherwise calls function_51974 with that same pointer, ignores its return value, and the result is true only if the byte at that pointer is 0. Returns the boolean. Arguments: none. Called functions: function_51974 (players any are dead); function_4f2810 (game safe to speak internal).
- Evidence: V

### game_all_quiet
- Slot: 1142 (table entry 0xa13630)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b0c5c (116 bytes)
- Behavior: Returns true only when all of these return false: function_4f2810 (with a pointer to a dword set to -1), function_4ed200, function_11a678, function_48bc58 and function_6932d4 (the pointer is passed to all but function_11a678). Calls stop at the first one that returns true. Arguments: none. Called functions: function_11a678 (dangerous effects near player); function_48bc58 (any unit is dangerous); function_4ed200 (dangerous items near player); function_4f2810 (game safe to speak internal); function_6932d4 (ai game all quiet wrapper).
- Evidence: V

### game_save
- Slot: 1143 (table entry 0xa135f0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b0cd0 (32 bytes)
- Behavior: Calls function_1664e0 with mode 1 and returns void. Arguments: none. Called functions: function_1664e0 (game save).
- Evidence: V, S

### game_save_cancel
- Slot: 1144 (table entry 0xa13350)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b0cf0
- Behavior: Clears the dword at offset 0 of the block at per-thread offset 0x148 and returns void. Arguments: none.
- Evidence: V

### game_save_no_timeout
- Slot: 1145 (table entry 0xa13310)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b0d1c (32 bytes)
- Behavior: Calls function_1664e0 with mode 2 and returns void. Arguments: none. Called functions: function_1664e0 (game save).
- Evidence: V, S

### game_save_immediate
- Slot: 1146 (table entry 0xa132d0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b0d3c (32 bytes)
- Behavior: Calls function_1664e0 with mode 3 and returns void. Arguments: none. Called functions: function_1664e0 (game save).
- Evidence: V, S

### game_saving
- Slot: 1147 (table entry 0xa13290)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b0d5c
- Behavior: Returns true when the byte at data_263eabe is nonzero or the dword at offset 0 of the block at per-thread offset 0x148 is nonzero. Arguments: none.
- Evidence: V

### game_reverted
- Slot: 1148 (table entry 0xa13470)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b0da8
- Behavior: Returns true when the dword at data_24fb708 equals the dword at offset 0xc of the block at per-thread offset 0xa0. Arguments: none.
- Evidence: V

### survival_mode_respawn_dead_players
- Slot: 1149 (table entry 0xa13430)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b0de8 (181 bytes)
- Behavior: Walks every player with the in-game iterator (function_4a380) over the players array at per-thread offset 0x18. For each player whose dword at +0x28 (unit handle) is -1 it sets bit 0x11 of the dword at +4, calls function_7a1dc with the iterator index to get a respawn time in seconds, multiplies it by the short at +6 of the block at per-thread offset 0xa0 and stores the product in the dwords at +0x1b4 and +0x1bc of the player entry. It then calls function_3a61a4 with the sign-extended index; if that is not -1 it calls function_3d9b28 with the result and 2. Returns void. Arguments: none. Called functions: function_4a380 (advances the in-game players iterator); function_7a1dc (game engine get player respawn time seconds); function_3a61a4 (returns a 32-bit id (or -1) from the element selected by function_1cd92c when the byte at +0x11 of the block at per-thread offset 0x48 equals 5 and function_58eec is false); function_3d9b28 (simulation entity mark state dirty).
- Evidence: V, S

### survival_mode_lives_get
- Slot: 1150 (table entry 0xa133e0)
- Returns: long
- Parameters: a0: team
- Kind: normal
- Status: implemented
- Evaluator: function_1b0ea0 (68 bytes)
- Behavior: Calls function_10e154 with the team argument and returns its 32-bit result. Called functions: function_10e154 (survival mode lives get).
- Evidence: V, S

### survival_mode_lives_set
- Slot: 1151 (table entry 0xa13390)
- Returns: void
- Parameters: a0: team, a1: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b0ee4 (71 bytes)
- Behavior: Calls function_10e184 with the team and the long argument. Returns void. Called functions: function_10e184 (survival mode lives set).
- Evidence: V, S

### survival_mode_get_mp_round_count
- Slot: 1152 (table entry 0xa13150)
- Returns: long
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b0f2c (27 bytes)
- Behavior: Calls function_7a164 and returns its 32-bit result. Arguments: none. Called functions: function_7a164 (survival mode get mp round count).
- Evidence: V, S

### survival_mode_get_mp_round_current
- Slot: 1153 (table entry 0xa13110)
- Returns: long
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b0f48 (26 bytes)
- Behavior: Calls function_7b238 and returns its 32-bit result. Arguments: none. Called functions: function_7b238 (survival mode get mp round current).
- Evidence: V, S

### survival_mode_set_get
- Slot: 1154 (table entry 0xa130d0)
- Returns: short
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b0f64
- Behavior: Returns the 16-bit value at offset 0x18c of the block at per-thread offset 0x20. Arguments: none.
- Evidence: V

### survival_mode_round_get
- Slot: 1155 (table entry 0xa13090)
- Returns: short
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b0fa4
- Behavior: Returns the signed 16-bit value (dword at offset 0x190 of the block at per-thread offset 0x20) divided by 5, truncated toward zero. Arguments: none.
- Evidence: V

### survival_mode_waves_per_round
- Slot: 1156 (table entry 0xa13250)
- Returns: short
- Parameters: none
- Kind: normal
- Status: implemented (constant result)
- Evaluator: function_1b0ff0
- Behavior: Returns the constant 5 as a 16-bit value. Reads and writes no state. Arguments: none.
- Evidence: V

### survival_mode_rounds_per_set
- Slot: 1157 (table entry 0xa13210)
- Returns: short
- Parameters: none
- Kind: normal
- Status: implemented (constant result)
- Evaluator: function_1b1010
- Behavior: Returns the constant 3 as a 16-bit value. Reads and writes no state. Arguments: none.
- Evidence: V

### survival_mode_wave_get
- Slot: 1158 (table entry 0xa131d0)
- Returns: short
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b1030
- Behavior: Returns the dword at offset 0x190 of the block at per-thread offset 0x20 reduced modulo 5 (value minus 5 times its quotient by 5, truncated toward zero), as a 16-bit value. Arguments: none.
- Evidence: V

### survival_mode_set_multiplier_get
- Slot: 1159 (table entry 0xa13190)
- Returns: real
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b1088
- Behavior: Returns the real at offset 0x1d4 of the block at per-thread offset 0x20. Arguments: none.
- Evidence: V

### survival_mode_set_multiplier_set
- Slot: 1160 (table entry 0xa12f40)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b10c4 (98 bytes)
- Behavior: Writes the real argument to offset 0x1d4 of the block at per-thread offset 0x20. Returns void.
- Evidence: V

### survival_mode_bonus_multiplier_get
- Slot: 1161 (table entry 0xa12f00)
- Returns: real
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b1128
- Behavior: Returns the real at offset 0x1d8 of the block at per-thread offset 0x20. Arguments: none.
- Evidence: V

### survival_mode_bonus_multiplier_set
- Slot: 1162 (table entry 0xa12eb0)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b1164 (122 bytes)
- Behavior: Writes the real argument to offset 0x1d8 of the block at per-thread offset 0x20. If the byte at offset 0x11 of the block at per-thread offset 0x48 is not 4, calls function_3a5be8 with 0x2000. Returns void. Called functions: function_3a5be8 (marks parts of the game engine globals (bit mask argument) as updated for replication).
- Evidence: V, S

### survival_mode_get_wave_squad
- Slot: 1163 (table entry 0xa12e70)
- Returns: long
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b11e0 (27 bytes)
- Behavior: Calls function_10e204 and returns its 32-bit result. Arguments: none. Called functions: function_10e204 (survival mode get wave squad).
- Evidence: V, S

### survival_mode_current_wave_is_initial
- Slot: 1164 (table entry 0xa13050)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b11fc
- Behavior: Let v be the dword at offset 0x190 of the block at per-thread offset 0x20. Returns true when v is a multiple of 5 and v is not 0xf, false otherwise. Arguments: none.
- Evidence: V

### survival_mode_current_wave_is_boss
- Slot: 1165 (table entry 0xa13010)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b1264
- Behavior: Returns true when the dword at offset 0x190 of the block at per-thread offset 0x20 modulo 5 equals 4. Arguments: none.
- Evidence: V

### survival_mode_current_wave_is_bonus
- Slot: 1166 (table entry 0xa12fd0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b12bc
- Behavior: Returns true when the dword at offset 0x190 of the block at per-thread offset 0x20 equals 0xf. Both natives using this evaluator return the same value. Arguments: none. This evaluator is shared with survival_mode_current_wave_is_last_in_set.
- Evidence: V

### survival_mode_current_wave_is_last_in_set
- Slot: 1167 (table entry 0xa12f90)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b12bc
- Behavior: Returns true when the dword at offset 0x190 of the block at per-thread offset 0x20 equals 0xf. Both natives using this evaluator return the same value. Arguments: none. This evaluator is shared with survival_mode_current_wave_is_bonus.
- Evidence: V

### survival_mode_begin_new_set
- Slot: 1168 (table entry 0xa12d50)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b12fc (115 bytes)
- Behavior: Increments the dword at offset 0x18c and sets the dword at offset 0x190 to -1 in the block at per-thread offset 0x20, clears the 0x40 bytes at offset 0x2a0 of that block with a memset, and if the byte at offset 0x11 of the block at per-thread offset 0x48 is not 4 calls function_3a5be8 with 0x2000. Returns void. Arguments: none. Called functions: function_3a5be8 (marks parts of the game engine globals (bit mask argument) as updated for replication).
- Evidence: V, S

### survival_mode_begin_new_wave
- Slot: 1169 (table entry 0xa12d10)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b1370 (27 bytes)
- Behavior: Calls function_10ddd8 and returns void. Arguments: none. Called functions: function_10ddd8 (survival mode begin new wave).
- Evidence: V, S

### survival_mode_end_set
- Slot: 1170 (table entry 0xa12cd0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b138c (78 bytes)
- Behavior: Calls function_10dd28 with 0x78005b, 0x78005c and a pointer to offset 0x2a0 of the block at per-thread offset 0x20, then function_fa600 with 0. Returns void. Arguments: none. Called functions: function_fa600 (adjusts a 15-bit value of a 16-bit table entry (data_28d2f00 indexed by the argument) within limits taken from data_b016c0, only when data_4e2fef0 is nonzero and data_4e2fef1 is zero); function_10dd28 (survival accumulator submit deathless incidents).
- Evidence: V, S

### survival_mode_end_wave
- Slot: 1171 (table entry 0xa12c90)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b13dc (216 bytes)
- Behavior: If the dword at offset 0x190 of the block at per-thread offset 0x20 is not negative, calls function_10dd28 with 0x78005f, 0x780060 and offset 0x220; if that value is 4, 9 or 0xe also calls it with 0x78005d, 0x78005e and offset 0x260. Then calls function_fa600 with 2, and with 1 when the value is 4, 9 or 0xe. If the value is 0xf it is reset to -1. Returns void. Arguments: none. Called functions: function_fa600 (adjusts a 15-bit value of a 16-bit table entry (data_28d2f00 indexed by the argument) within limits taken from data_b016c0, only when data_4e2fef0 is nonzero and data_4e2fef1 is zero); function_10dd28 (survival accumulator submit deathless incidents).
- Evidence: V

### survival_mode_award_hero_medal
- Slot: 1172 (table entry 0xa12e30)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b14b4 (259 bytes)
- Behavior: For each team number 0 to 7, walks the in-game players and counts those on the team (byte at +0xac of the player entry) and those among them with a unit (dword at +0x28 not -1), remembering the last team member with a unit. If exactly one has a unit, the team has more members than that, function_10e0b0 returns true for the team and the dword at offset 0x190 of the block at per-thread offset 0x20 is not 0xf, it calls function_10ac68 with 0x78003b and that player's index. Returns void. Arguments: none. Called functions: function_4a380 (advances the in-game players iterator); function_10ac68 (submit incident with cause player); function_10e0b0 (survival mode disables respawning).
- Evidence: V, S

### survival_mode_incident_new
- Slot: 1173 (table entry 0xa12de0)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b15b8 (68 bytes)
- Behavior: Calls function_10ae54 with the string id and returns void. Shared with slot 1768 (submit_incident); both natives run the same evaluator. Called functions: function_10ae54 (submit incident).
- Evidence: V, S

### chud_bonus_round_show_timer
- Slot: 1174 (table entry 0xa12d90)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b15fc (140 bytes)
- Behavior: Does not read its boolean argument. For each of 16 timer records (0xc60 bytes apart, starting at offset 0x2b0 of the block at per-thread offset 0x5b0) it clears the dword at -4, keeps the real at 0, and sets the byte at -8 to 1. Then calls function_3a5be8 with 0x8000. Returns void. Called functions: function_3a5be8 (marks parts of the game engine globals (bit mask argument) as updated for replication).
- Evidence: V

### chud_bonus_round_start_timer
- Slot: 1175 (table entry 0xa12b40)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b1688 (150 bytes)
- Behavior: Does not use the value of its boolean argument (only that the argument block exists). For each of 16 timer records (0xc60 bytes apart, starting at offset 0x2b0 of the block at per-thread offset 0x5b0) it keeps the real at 0, sets the byte at -8 to 1 and sets the dword at -4 to 1. Then calls function_3a5be8 with 0x8000. Returns void. Called functions: function_3a5be8 (marks parts of the game engine globals (bit mask argument) as updated for replication).
- Evidence: V

### chud_bonus_round_set_timer
- Slot: 1176 (table entry 0xa12af0)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b1720 (152 bytes)
- Behavior: Calls function_5cc74 with the real argument, converts the integer it returns to a real, and for each of 16 timer records (0xc60 bytes apart, starting at offset 0x2b0 of the block at per-thread offset 0x5b0) clears the dword at -4, stores that real at 0 and sets the byte at -8 to 1. Then calls function_3a5be8 with 0x8000. Returns void. Called functions: function_5cc74 (converts seconds (real) to game ticks: 0 when the byte at offset 0 of the block at per-thread offset 0xa0 is zero, otherwise rounds the seconds times the short at +6 of that block); function_3a5be8 (marks parts of the game engine globals (bit mask argument) as updated for replication).
- Evidence: V

### survival_mode_meets_set_start_requirements
- Slot: 1177 (table entry 0xa12ab0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b17b8 (97 bytes)
- Behavior: Calls function_58c04; if it returns false the result is true. Otherwise returns whether function_4a1ec (called with 1) is greater than or equal to the signed byte at offset 0x110ed of the block at per-thread offset 0x48. Arguments: none. Called functions: function_4a1ec (game coop player count); function_58c04 (true when a game is active (function_588e0) and the byte at offset 0x110ec of the block at per-thread offset 0x48 is nonzero).
- Evidence: V, S

### survival_mode_set_pregame
- Slot: 1178 (table entry 0xa12a60)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b181c (68 bytes)
- Behavior: Calls function_10e008 with the boolean argument and returns void. Called functions: function_10e008 (survival mode set pregame).
- Evidence: V, S

### survival_mode_is_pregame
- Slot: 1179 (table entry 0xa12c50)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b1860
- Behavior: Returns the byte at offset 0x1dc of the block at per-thread offset 0x20. Arguments: none.
- Evidence: V

### survival_mode_get_time_limit
- Slot: 1180 (table entry 0xa12c10)
- Returns: long
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b189c
- Behavior: Returns the byte at offset 0x2ba of the record whose pointer is stored at data_4e30388, zero-extended; 0 if the pointer is null. Arguments: none.
- Evidence: V

### survival_mode_get_set_count
- Slot: 1181 (table entry 0xa12bd0)
- Returns: long
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b18c0
- Behavior: Returns the byte at offset 0x740 of the record whose pointer is stored at data_4e30388, zero-extended; 0 if the pointer is null. Arguments: none.
- Evidence: V

### survival_mode_get_bonus_lives_awarded
- Slot: 1182 (table entry 0xa12b90)
- Returns: long
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b18e4
- Behavior: Returns the byte at offset 0x741 of the record whose pointer is stored at data_4e30388, sign-extended; 0 if the pointer is null. Arguments: none.
- Evidence: V

### survival_mode_get_bonus_target
- Slot: 1183 (table entry 0xa12920)
- Returns: long
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b1908
- Behavior: Returns the 16-bit value at offset 0x742 of the record whose pointer is stored at data_4e30388, sign-extended; 0 if the pointer is null. Arguments: none.
- Evidence: V

### survival_mode_get_shared_team_life_count
- Slot: 1184 (table entry 0xa128e0)
- Returns: long
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b192c
- Behavior: Returns the 16-bit value at offset 0x9c4 of the record whose pointer is stored at data_4e30388, sign-extended; 0 if the pointer is null. Arguments: none.
- Evidence: V

### survival_mode_get_elite_life_count
- Slot: 1185 (table entry 0xa128a0)
- Returns: long
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b1950
- Behavior: Returns the 16-bit value at offset 0x9c6 of the record whose pointer is stored at data_4e30388, sign-extended; 0 if the pointer is null. Arguments: none.
- Evidence: V

### survival_mode_max_lives
- Slot: 1186 (table entry 0xa12860)
- Returns: long
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b1974
- Behavior: Returns the 16-bit value at offset 0x9ca of the record whose pointer is stored at data_4e30388, sign-extended; 0 if the pointer is null. Arguments: none.
- Evidence: V

### survival_mode_generator_count
- Slot: 1187 (table entry 0xa12a20)
- Returns: long
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b1998
- Behavior: Returns the 16-bit value at offset 0x9cc of the record whose pointer is stored at data_4e30388, sign-extended; 0 if the pointer is null. Arguments: none.
- Evidence: V

### survival_mode_bonus_lives_elite_death
- Slot: 1188 (table entry 0xa129e0)
- Returns: long
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b19bc
- Behavior: Returns the 16-bit value at offset 0x744 of the record whose pointer is stored at data_4e30388, sign-extended; 0 if the pointer is null. Arguments: none.
- Evidence: V

### survival_mode_scenario_extras_enable
- Slot: 1189 (table entry 0xa129a0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b19e0
- Behavior: Returns bit 0 of the byte at offset 0x738 of the record whose pointer is stored at data_4e30388; false if the pointer is null. Arguments: none.
- Evidence: V

### survival_mode_weapon_drops_enable
- Slot: 1190 (table entry 0xa12960)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b1a10
- Behavior: Returns bit 3 of the byte at offset 0x738 of the record whose pointer is stored at data_4e30388; false if the pointer is null. Arguments: none.
- Evidence: V

### survival_mode_ammo_crates_enable
- Slot: 1191 (table entry 0xa12700)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b1a40
- Behavior: Returns bit 4 of the byte at offset 0x738 of the record whose pointer is stored at data_4e30388; false if the pointer is null. Arguments: none.
- Evidence: V

### survival_mode_waves_disabled
- Slot: 1192 (table entry 0xa126c0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b1a70
- Behavior: Returns bit 0 of the byte at offset 0x739 of the record whose pointer is stored at data_4e30388; false if the pointer is null. Arguments: none.
- Evidence: V

### survival_mode_generator_defend_all
- Slot: 1193 (table entry 0xa12680)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b1aa0
- Behavior: Returns bit 1 of the byte at offset 0x738 of the record whose pointer is stored at data_4e30388; false if the pointer is null. Arguments: none.
- Evidence: V

### survival_mode_generator_random_spawn
- Slot: 1194 (table entry 0xa12640)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b1ad0
- Behavior: Returns bit 2 of the byte at offset 0x738 of the record whose pointer is stored at data_4e30388; false if the pointer is null. Arguments: none.
- Evidence: V

### survival_mode_current_wave_uses_dropship
- Slot: 1195 (table entry 0xa12820)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b1b00 (98 bytes)
- Behavior: If function_58bbc returns true, calls function_f8020 with the pointer at data_4e30388 and the dword at offset 0x190 of the block at per-thread offset 0x20, and returns bit 0 of the byte at the pointer it returns. Returns false if function_58bbc returns false. Arguments: none. Called functions: function_58bbc (campaign survival enabled).
- Evidence: V, S

### survival_mode_get_current_wave_time_limit
- Slot: 1196 (table entry 0xa127e0)
- Returns: short
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b1b64 (98 bytes)
- Behavior: If function_58bbc returns true and the dword at offset 0x190 of the block at per-thread offset 0x20 equals 0xf, returns the 16-bit value at offset 0x7e4 of the record whose pointer is stored at data_4e30388; otherwise returns 0. Arguments: none. Called functions: function_58bbc (campaign survival enabled).
- Evidence: V, S

### survival_mode_get_respawn_time_seconds
- Slot: 1197 (table entry 0xa12790)
- Returns: long
- Parameters: a0: mp_team
- Kind: normal
- Status: implemented
- Evaluator: function_1b1bc8 (89 bytes)
- Behavior: If the pointer at data_4e30388 is not null, calls the virtual method at vtable offset 0x70 of that object with the team argument and returns the byte at offset 3 of the pointer it returns. Returns 0 if the pointer is null.
- Evidence: V

### survival_mode_team_respawns_on_wave
- Slot: 1198 (table entry 0xa12740)
- Returns: boolean
- Parameters: a0: team
- Kind: normal
- Status: implemented
- Evaluator: function_1b1c24 (114 bytes)
- Behavior: If the pointer at data_4e30388 is not null, picks the record at offset 0x98c when the team argument is 7 and at offset 0x2c0 otherwise, and returns true when the byte at +3 of that record is 0xff. Returns false when the pointer is null.
- Evidence: V

### survival_mode_sudden_death
- Slot: 1199 (table entry 0xa124b0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b1c98 (68 bytes)
- Behavior: Calls function_10d968 with the boolean argument and returns void. Called functions: function_10d968 (survival mode sudden death).
- Evidence: V, S

### survival_increment_human_score
- Slot: 1200 (table entry 0xa12460)
- Returns: void
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1b1cdc (73 bytes)
- Behavior: Calls function_7b894 with the player argument and a delta of 1. Returns void. The human-score and elite-score natives share this evaluator, so they behave identically. This evaluator is shared with survival_increment_elite_score. Called functions: function_7b894 (survival increment score).
- Evidence: V, S

### survival_increment_elite_score
- Slot: 1201 (table entry 0xa12410)
- Returns: void
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1b1cdc (73 bytes)
- Behavior: Calls function_7b894 with the player argument and a delta of 1. Returns void. The human-score and elite-score natives share this evaluator, so they behave identically. This evaluator is shared with survival_increment_human_score. Called functions: function_7b894 (survival increment score).
- Evidence: V, S

### survival_mode_set_spartan_license_plate
- Slot: 1202 (table entry 0xa123c0)
- Returns: void
- Parameters: a0: long, a1: long, a2: string_id, a3: string_id, a4: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b1d28 (205 bytes)
- Behavior: Writes into the block at per-thread offset 0x20: dword +0x2e0 = the dword at +0xc of the block at per-thread offset 0xa0, byte +0x2e4 = low byte of the first long, byte +0x2e5 = low byte of the second long, dword +0x2e8 = first string id, dword +0x2ec = second string id, dword +0x2f0 = third string id. If the byte at +0x11 of the block at per-thread offset 0x48 is not 4 it calls function_3a5be8 with 0x1000. Returns void. Called functions: function_3a5be8 (marks parts of the game engine globals (bit mask argument) as updated for replication).
- Evidence: V, S

### survival_mode_set_elite_license_plate
- Slot: 1203 (table entry 0xa125f0)
- Returns: void
- Parameters: a0: long, a1: long, a2: string_id, a3: string_id, a4: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b1df8 (205 bytes)
- Behavior: Writes into the block at per-thread offset 0x20: dword +0x2f4 = the dword at +0xc of the block at per-thread offset 0xa0, byte +0x2f8 = low byte of the first long, byte +0x2f9 = low byte of the second long, dword +0x2e8 = first string id (the same field the Spartan variant writes for its first string id), dword +0x300 = second string id, dword +0x304 = third string id. If the byte at +0x11 of the block at per-thread offset 0x48 is not 4 it calls function_3a5be8 with 0x1000. Returns void. Called functions: function_3a5be8 (marks parts of the game engine globals (bit mask argument) as updated for replication).
- Evidence: V, S

### survival_mode_player_count_by_team
- Slot: 1204 (table entry 0xa125a0)
- Returns: long
- Parameters: a0: team
- Kind: normal
- Status: implemented
- Evaluator: function_1b1ec8 (176 bytes)
- Behavior: If the team argument is 7 or lower, walks the in-game players over the array at per-thread offset 0x18 and counts those for which the team byte returned by function_1360cc equals the argument. Returns the count; 0 if the argument is above 7. Called functions: function_4a380 (advances the in-game players iterator); function_1360cc (game get player team).
- Evidence: V

### survival_mode_players_by_team
- Slot: 1205 (table entry 0xa12550)
- Returns: object_list
- Parameters: a0: team
- Kind: normal
- Status: implemented
- Evaluator: function_1b1f78 (68 bytes)
- Behavior: Calls function_10e324 with the team argument and returns its 32-bit object list result. Called functions: function_10e324 (survival mode players by team).
- Evidence: V, S

### sound_impulse_predict
- Slot: 1206 (table entry 0xa12500)
- Returns: void
- Parameters: a0: sound
- Kind: normal
- Status: implemented
- Evaluator: function_1b1fbc (68 bytes)
- Behavior: Calls function_2645c with the sound argument and returns void. Called functions: function_2645c (sound predict).
- Evidence: V, S

### sound_impulse_trigger
- Slot: 1207 (table entry 0xa12230)
- Returns: void
- Parameters: a0: sound, a1: object, a2: real, a3: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b2000 (80 bytes)
- Behavior: Calls function_bb1ec with the sound, the object, the real argument and the long argument. Returns void. Called functions: function_bb1ec (sound impulse trigger).
- Evidence: V, S

### sound_impulse_start
- Slot: 1208 (table entry 0xa121e0)
- Returns: void
- Parameters: a0: sound, a1: object, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b2050 (116 bytes)
- Behavior: Calls function_bb880 with the sound, the object, the real argument, a gain value taken from data_9d8310 (0.0 in the module image) passed both as the fourth argument and as a stack argument, -1, a byte 1 and a byte 0. Returns void. Called functions: function_bb880 (sound impulse start).
- Evidence: V, S

### sound_impulse_start_cinematic
- Slot: 1209 (table entry 0xa12190)
- Returns: void
- Parameters: a0: sound, a1: object, a2: real, a3: real, a4: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b20c4 (152 bytes)
- Behavior: Converts the real at offset 0xc and the real at offset 0x10 with function_afba8 (a gain to decibels conversion), then calls function_bb880 with the sound, the object, the real at offset 8, the first decibel value, the second decibel value on the stack, -1, a byte 1 and a byte 0. Returns void. Called functions: function_afba8 (sound gain to decibels); function_bb880 (sound impulse start).
- Evidence: V, S

### sound_impulse_start_effect
- Slot: 1210 (table entry 0xa12140)
- Returns: void
- Parameters: a0: sound, a1: object, a2: real, a3: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b215c (86 bytes)
- Behavior: Calls function_bb840 with the sound, the object, the real argument, the string id and a stack argument 0. Returns void. Called functions: function_bb840 (sound impulse start with effect).
- Evidence: V, S

### sound_impulse_start_with_subtitle
- Slot: 1211 (table entry 0xa12370)
- Returns: void
- Parameters: a0: sound, a1: object, a2: real, a3: string_id, a4: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b21b4 (121 bytes)
- Behavior: Calls function_bb840 with the sound, the object, the real argument, the first string id and a pointer to a local real. It then calls function_d5e34 with the second string id, the real written to the local, and 1. Returns void. Called functions: function_bb840 (sound impulse start with effect); function_d5e34 (cinematic subtitle).
- Evidence: V, S

### sound_impulse_time (slot 1212)
- Slot: 1212 (table entry 0xa12320)
- Returns: long
- Parameters: a0: sound
- Kind: normal
- Status: implemented
- Evaluator: function_1b2230 (95 bytes)
- Behavior: If the sound argument is -1 returns 0. Otherwise calls function_c18d8 with the sound, converts the real it returns to game ticks with function_81b08, calls function_bd2bc with the sound and the tick count, and returns its 32-bit result. Called functions: function_81b08 (converts seconds (real) to ticks at a fixed 30 per second, rounded half away from zero); function_bd2bc (scripted sound language time explicit hs ticks); function_c18d8 (returns the real at offset 0xc of the sound's tag data when a tag group check on the sound passes).
- Evidence: V, S

### sound_impulse_time (slot 1213)
- Slot: 1213 (table entry 0xa122d0)
- Returns: long
- Parameters: a0: sound, a1: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b2290 (71 bytes)
- Behavior: Calls function_bd2bc with the sound and the long argument and returns its 32-bit result. Called functions: function_bd2bc (scripted sound language time explicit hs ticks).
- Evidence: V, S

### sound_impulse_language_time
- Slot: 1214 (table entry 0xa12280)
- Returns: long
- Parameters: a0: sound
- Kind: normal
- Status: implemented
- Evaluator: function_1b22d8 (218 bytes)
- Behavior: Returns a tick count. If the sound argument is -1, or function_bc12c finds no playing slot for it, the value converted is 0.0. Otherwise it takes the sound slot record (16-byte records in the array at per-thread offset 0x3a0), calls function_c193c with the sound and the record's field at +0xc, calls function_5cc74, adds the difference between the record's dword at +4 and the dword at +0xc of the block at per-thread offset 0xa0, multiplies the sum by the real at +8 of that block, uses it only if it is greater than 0.0 (otherwise 0.0), and converts it with function_81b08. Called functions: function_5cc74 (converts seconds (real) to game ticks: 0 when the byte at offset 0 of the block at per-thread offset 0xa0 is zero, otherwise rounds the seconds times the short at +6 of that block); function_81b08 (converts seconds (real) to ticks at a fixed 30 per second, rounded half away
  from zero); function_bc12c (sound impulse slot find by tag); function_c193c (game sound get actual playing time seconds).
- Evidence: V, S

### sound_impulse_stop
- Slot: 1215 (table entry 0xa11fb0)
- Returns: void
- Parameters: a0: sound
- Kind: normal
- Status: implemented
- Evaluator: function_1b23b4 (68 bytes)
- Behavior: Calls function_bd368 with the sound argument and returns void. Called functions: function_bd368 (sound impulse stop).
- Evidence: V, S

### sound_impulse_start_3d
- Slot: 1216 (table entry 0xa11f60)
- Returns: void
- Parameters: a0: sound, a1: real, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b23f8 (78 bytes)
- Behavior: Calls function_bb6b8 with the sound and the two reals. Returns void. Called functions: function_bb6b8 (sound impulse start 3d).
- Evidence: V, S

### sound_impulse_mark_as_outro
- Slot: 1217 (table entry 0xa11f10)
- Returns: void
- Parameters: a0: sound
- Kind: normal
- Status: implemented
- Evaluator: function_1b2448 (165 bytes)
- Behavior: Finds the playing slot of the sound with function_bc12c. If a slot exists, its byte at +0xe is zero and function_137c4 resolves its handle (dword at +8) in the datum array at per-thread offset 0x90, sets bit 0xc of the dword at +4 of that datum's element (256-byte elements) provided the byte at +2 of the element is zero. Returns void. Called functions: function_137c4 (datum try and get); function_bc12c (sound impulse slot find by tag).
- Evidence: V, S

### sound_impulse_start_naked
- Slot: 1218 (table entry 0xa11ec0)
- Returns: void
- Parameters: a0: sound, a1: string_id, a2: string_id
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### sound_preload_dialogue_sounds
- Slot: 1219 (table entry 0xa120f0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### sound_looping_predict
- Slot: 1220 (table entry 0xa120a0)
- Returns: void
- Parameters: a0: looping_sound
- Kind: normal
- Status: implemented
- Evaluator: function_1b24f0 (196 bytes)
- Behavior: If the looping sound handle is not -1, looks it up in the tag instance table (data_c1a600) and reads the block of 0xb0-byte (0x2c dword) elements whose count is at +0x20 and reference at +0x24 of its tag data. For each element it calls function_2645c with the dword at element offset +0x28 (the count is held in a 16-bit counter). Returns void. Called functions: function_2645c (sound predict).
- Evidence: V, S

### sound_looping_start_with_effect
- Slot: 1221 (table entry 0xa12050)
- Returns: void
- Parameters: a0: looping_sound, a1: object, a2: real, a3: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b25b4 (85 bytes)
- Behavior: Calls function_bd544 with the looping sound, the object, the real, the string id as fourth argument and a stack byte 0. Returns void. Called functions: function_bd544 (sound looping start).
- Evidence: V, S

### sound_looping_start
- Slot: 1222 (table entry 0xa12000)
- Returns: void
- Parameters: a0: looping_sound, a1: object, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b260c (84 bytes)
- Behavior: Calls function_bd544 with the looping sound, the object, the real, 0 as fourth argument and a stack byte 0. Returns void. Called functions: function_bd544 (sound looping start).
- Evidence: V, S

### sound_looping_resume
- Slot: 1223 (table entry 0xa11d40)
- Returns: void
- Parameters: a0: looping_sound, a1: object, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b2660 (84 bytes)
- Behavior: Calls function_bd544 with the looping sound, the object, the real, 0 as fourth argument and a stack byte 1 (the only difference from the start native). Returns void. Called functions: function_bd544 (sound looping start).
- Evidence: V, S

### sound_looping_stop
- Slot: 1224 (table entry 0xa11cf0)
- Returns: void
- Parameters: a0: looping_sound
- Kind: normal
- Status: implemented
- Evaluator: function_1b26b4 (75 bytes)
- Behavior: If the looping sound is not -1, calls function_c16c0 with it and mode 0. Returns void. Called functions: function_c16c0 (sound looping stop).
- Evidence: V, S

### sound_looping_stop_immediately
- Slot: 1225 (table entry 0xa11ca0)
- Returns: void
- Parameters: a0: looping_sound
- Kind: normal
- Status: implemented
- Evaluator: function_1b2700 (78 bytes)
- Behavior: If the looping sound is not -1, calls function_c16c0 with it and mode 2. Returns void. Called functions: function_c16c0 (sound looping stop).
- Evidence: V, S

### sound_looping_set_scale
- Slot: 1226 (table entry 0xa11c50)
- Returns: void
- Parameters: a0: looping_sound, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b2750 (73 bytes)
- Behavior: Calls function_bd648 with the looping sound and the real. Returns void. Called functions: function_bd648 (sound looping set scale).
- Evidence: V, S

### sound_looping_set_alternate
- Slot: 1227 (table entry 0xa11e70)
- Returns: void
- Parameters: a0: looping_sound, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b279c (71 bytes)
- Behavior: Calls function_bd6d8 with the looping sound and the boolean. Returns void. Called functions: function_bd6d8 (sound looping set alternate).
- Evidence: V, S

### sound_looping_activate_layer
- Slot: 1228 (table entry 0xa11e20)
- Returns: void
- Parameters: a0: looping_sound, a1: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b27e4 (105 bytes)
- Behavior: If the layer number (long) is 1 to 4, builds a sound message of type 0xf holding the looping sound, the layer and the flag 1 and submits it with function_bc170. Otherwise does nothing. Returns void. Called functions: function_bc170 (game sound add message).
- Evidence: V, S

### sound_looping_deactivate_layer
- Slot: 1229 (table entry 0xa11dd0)
- Returns: void
- Parameters: a0: looping_sound, a1: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b2850 (105 bytes)
- Behavior: If the layer number (long) is 1 to 4, builds a sound message of type 0xf holding the looping sound, the layer and the flag 0 and submits it with function_bc170. Otherwise does nothing. Returns void. Called functions: function_bc170 (game sound add message).
- Evidence: V, S

### sound_loop_spam
- Slot: 1230 (table entry 0xa11d90)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### sound_class_show_channel
- Slot: 1231 (table entry 0xa11ac0)
- Returns: void
- Parameters: a0: string, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### sound_class_debug_sound_start
- Slot: 1232 (table entry 0xa11a70)
- Returns: void
- Parameters: a0: string, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### debug_sounds_enable
- Slot: 1233 (table entry 0xa11a20)
- Returns: void
- Parameters: a0: string, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### sound_class_set_gain
- Slot: 1234 (table entry 0xa119d0)
- Returns: void
- Parameters: a0: string, a1: real, a2: short
- Kind: normal
- Status: implemented
- Evaluator: function_1b28bc (105 bytes)
- Behavior: Resolves the string with function_1990a0, divides the short argument (as a real) by 30.0 (data_a8b3d8), and calls function_b2884 with the string, the real argument and that quotient; function_b2884 converts the gain with function_afba8 and calls function_b28b8. Returns void. Called functions: function_b2884 (audio set value with index lookup); function_1990a0 (resolves a string argument of a script call to its character data).
- Evidence: V, S

### sound_class_set_gain_db
- Slot: 1235 (table entry 0xa11c00)
- Returns: void
- Parameters: a0: string, a1: real, a2: short
- Kind: normal
- Status: implemented
- Evaluator: function_1b2928 (108 bytes)
- Behavior: Resolves the string with function_1990a0, divides the short argument (as a real) by 30.0 (data_a8b3d8) and calls function_b28b8 with the string, the real argument (as the value in decibels), that quotient and 0. Returns void. Called functions: function_b28b8 (sound class set gain); function_1990a0 (resolves a string argument of a script call to its character data).
- Evidence: V, S

### sound_class_enable_ducker
- Slot: 1236 (table entry 0xa11bb0)
- Returns: void
- Parameters: a0: string, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b2994 (80 bytes)
- Behavior: Resolves the string with function_1990a0 and calls function_b2994 with it and the boolean argument. Returns void. Called functions: function_b2994 (sound class enable ducker); function_1990a0 (resolves a string argument of a script call to its character data).
- Evidence: V, S

### debug_sound_environment_parameter
- Slot: 1237 (table entry 0xa11b60)
- Returns: void
- Parameters: a0: long, a1: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### sound_start_global_effect
- Slot: 1238 (table entry 0xa11b10)
- Returns: void
- Parameters: a0: string_id, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b29e4 (110 bytes)
- Behavior: Builds a sound message of type 0xa holding the string id, the real argument and the real -1.0 (data_a8b7e8) and submits it with function_bc170. Returns void. Called functions: function_bc170 (game sound add message).
- Evidence: V, S

### sound_start_timed_global_effect
- Slot: 1239 (table entry 0xa11890)
- Returns: void
- Parameters: a0: string_id, a1: real, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b2a54 (116 bytes)
- Behavior: If the second real (time) is greater than 0.0, builds a sound message of type 0xa holding the string id, the first real and the second real, and submits it with function_bc170. Otherwise does nothing. Returns void. Called functions: function_bc170 (game sound add message).
- Evidence: V, S

### sound_stop_global_effect
- Slot: 1240 (table entry 0xa11840)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b2ac8 (85 bytes)
- Behavior: Builds a sound message of type 0xb holding the string id and submits it with function_bc170. Returns void. Called functions: function_bc170 (game sound add message).
- Evidence: V, S

### sound_enable_acoustic_palette
- Slot: 1241 (table entry 0xa117f0)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b2b20 (85 bytes)
- Behavior: Builds a sound message of type 8 holding the string id and submits it with function_bc170. Returns void. Called functions: function_bc170 (game sound add message).
- Evidence: V, S

### sound_disable_acoustic_palette
- Slot: 1242 (table entry 0xa117a0)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b2b78 (85 bytes)
- Behavior: Builds a sound message of type 9 holding the string id and submits it with function_bc170. Returns void. Called functions: function_bc170 (game sound add message).
- Evidence: V, S

### vehicle_force_alternate_state
- Slot: 1243 (table entry 0xa11980)
- Returns: void
- Parameters: a0: vehicle, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b2bd0 (200 bytes)
- Behavior: If the vehicle argument is not -1, finds the object payload pointer (24-byte header entries in the array at +0x50 of the block at per-thread offset 0x10, pointer at entry offset 0x10), calls function_4addf4 on the payload at +0x9e8 and compares the flag it returns with the boolean. If different, calls function_4ac1e4 with the dword at offset 0 of the payload (a vehicle type); when that is 3 it stores the boolean in the byte at payload offset 0xad6. Then calls function_46c854 with the handle and function_4715f8 with the handle and 0. Returns void. Called functions: function_46c854 (object wake); function_4715f8 (object set at rest state); function_4addf4 (vehicle type3 flag 0xee get).
- Evidence: V, S

### vehicle_auto_turret
- Slot: 1244 (table entry 0xa11930)
- Returns: void
- Parameters: a0: vehicle, a1: trigger_volume, a2: real, a3: real, a4: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b2c98 (98 bytes)
- Behavior: Calls function_4ae850 with the vehicle, the trigger volume (16-bit at offset 4, sign-extended), three reals and -1 as a stack argument. Returns void. Called functions: function_4ae850 (vehicle auto turret).
- Evidence: V, S

### vehicle_hover
- Slot: 1245 (table entry 0xa118e0)
- Returns: void
- Parameters: a0: vehicle, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b2cfc (71 bytes)
- Behavior: Calls function_4ae908 with the vehicle and the boolean. Returns void. Called functions: function_4ae908 (vehicle hover).
- Evidence: V, S

### vehicle_count_bipeds_killed
- Slot: 1246 (table entry 0xa11620)
- Returns: long
- Parameters: a0: vehicle
- Kind: normal
- Status: implemented
- Evaluator: function_1b2d44 (124 bytes)
- Behavior: If the vehicle argument is not -1, returns the dword at offset 0xb7c of its object payload (header entries as in the force-alternate-state native); otherwise returns 0.
- Evidence: V

### biped_ragdoll
- Slot: 1247 (table entry 0xa115d0)
- Returns: void
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_1b2dc0 (150 bytes)
- Behavior: If the unit argument is not -1, resolves it with function_4739cc (type mask argument 1). If an object comes back, calls function_47caa8 with the handle, 1, 1, 2 and a stack argument 1, sets the byte at +0x294 of the object to 1 and calls function_4715f8 with the handle and 0. Returns void. Called functions: function_4715f8 (object set at rest state); function_4739cc (object try and get and verify type); function_47caa8 (unit kill).
- Evidence: V, S

### water_float_reset
- Slot: 1248 (table entry 0xa11580)
- Returns: void
- Parameters: a0: object
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (so any nested calls still run) and then returns 0. It calls no engine function and reads or writes no state. Shared evaluator (11 slots in this range).
- Evidence: V

### hud_show_training_text
- Slot: 1249 (table entry 0xa11750)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b2e58 (98 bytes)
- Behavior: Writes the boolean to the byte at offset 0xa04 of the block at per-thread offset 0x150. Returns void.
- Evidence: V

### hud_set_training_text
- Slot: 1250 (table entry 0xa11700)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b2ebc (98 bytes)
- Behavior: Writes the string id to the dword at offset 0xa00 of the block at per-thread offset 0x150. Returns void.
- Evidence: V

### hud_enable_training
- Slot: 1251 (table entry 0xa116b0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b2f20 (98 bytes)
- Behavior: Writes the boolean to the byte at offset 0xa05 of the block at per-thread offset 0x150. Returns void.
- Evidence: V

### player_training_activate_night_vision
- Slot: 1252 (table entry 0xa11670)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b2f84 (97 bytes)
- Behavior: Walks the local player indices with function_53c34 (starting from -1). For each one sets bit 0 of the byte at offset 0x248 of that player's 0x280-byte record in the block at per-thread offset 0x150. Returns void. Arguments: none.
- Evidence: V, S

### player_training_activate_crouch
- Slot: 1253 (table entry 0xa11450)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b2fe8 (32 bytes)
- Behavior: Calls function_113c48 with 1 and returns void. Arguments: none. Called functions: function_113c48 (player training activate).
- Evidence: V, S

### player_training_activate_stealth
- Slot: 1254 (table entry 0xa11410)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b3008 (32 bytes)
- Behavior: Calls function_113c48 with 2 and returns void. Arguments: none. Called functions: function_113c48 (player training activate).
- Evidence: V, S

### player_training_activate_equipment
- Slot: 1255 (table entry 0xa113d0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### player_training_activate_jump
- Slot: 1256 (table entry 0xa11390)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b3028 (32 bytes)
- Behavior: Calls function_113c48 with 4 and returns void. Arguments: none. Called functions: function_113c48 (player training activate).
- Evidence: V, S

### player_training_reset
- Slot: 1257 (table entry 0xa11530)
- Returns: void
- Parameters: a0: controller
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### chud_texture_cam
- Slot: 1258 (table entry 0xa114e0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b3048 (68 bytes)
- Behavior: Calls function_2c34b0 with the boolean and returns void. Called functions: function_2c34b0 (chud texture cam).
- Evidence: V, S

### chud_show
- Slot: 1259 (table entry 0xa11490)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b308c (119 bytes)
- Behavior: Writes the boolean to the byte at offset 0x320 of each of the 16 records (0xc60 bytes each) in the block at per-thread offset 0x5b0. Returns void.
- Evidence: V

### chud_show_weapon_stats
- Slot: 1260 (table entry 0xa112a0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b3104 (138 bytes)
- Behavior: Writes the real 1.0 (true) or 0.0 (false) to offset 0x330 of each of the 16 records (0xc60 bytes each) in the block at per-thread offset 0x5b0. Returns void.
- Evidence: V

### chud_show_crosshair
- Slot: 1261 (table entry 0xa11250)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b3190 (138 bytes)
- Behavior: Writes the real 1.0 (true) or 0.0 (false) to offset 0x334 of each of the 16 records (0xc60 bytes each) in the block at per-thread offset 0x5b0. Returns void.
- Evidence: V

### chud_show_shield
- Slot: 1262 (table entry 0xa11200)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b321c (138 bytes)
- Behavior: Writes the real 1.0 (true) or 0.0 (false) to offset 0x338 of each of the 16 records (0xc60 bytes each) in the block at per-thread offset 0x5b0. Returns void.
- Evidence: V

### chud_show_grenades
- Slot: 1263 (table entry 0xa11340)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b32a8 (138 bytes)
- Behavior: Writes the real 1.0 (true) or 0.0 (false) to offset 0x33c of each of the 16 records (0xc60 bytes each) in the block at per-thread offset 0x5b0. Returns void.
- Evidence: V

### chud_show_messages
- Slot: 1264 (table entry 0xa112f0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b3334 (68 bytes)
- Behavior: Calls function_2c3508 with the boolean and returns void. Called functions: function_2c3508 (chud show messages).
- Evidence: V, S

### chud_show_motion_sensor
- Slot: 1265 (table entry 0xa110c0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b3378 (138 bytes)
- Behavior: Writes the real 1.0 (true) or 0.0 (false) to offset 0x344 of each of the 16 records (0xc60 bytes each) in the block at per-thread offset 0x5b0. Returns void.
- Evidence: V

### chud_show_cinematics
- Slot: 1266 (table entry 0xa11070)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b3404 (138 bytes)
- Behavior: Writes the real 1.0 (true) or 0.0 (false) to offset 0x34c of each of the 16 records (0xc60 bytes each) in the block at per-thread offset 0x5b0. Returns void.
- Evidence: V

### chud_fade_weapon_stats_for_player
- Slot: 1267 (table entry 0xa11020)
- Returns: void
- Parameters: a0: player, a1: real, a2: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b3490 (150 bytes)
- Behavior: If the player argument is not -1, selects the record whose index is the low 16 bits of the player argument (0xc60 bytes each, from the block at per-thread offset 0x5b0; the index is not range checked). If the long argument is greater than 0, stores the real at offset 0x354 and the long at offset 0x378 of that record; otherwise stores the real at offset 0x330. Returns void.
- Evidence: V

### chud_fade_crosshair_for_player
- Slot: 1268 (table entry 0xa111b0)
- Returns: void
- Parameters: a0: player, a1: real, a2: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b3528 (150 bytes)
- Behavior: If the player argument is not -1, selects the record whose index is the low 16 bits of the player argument (0xc60 bytes each, from the block at per-thread offset 0x5b0; the index is not range checked). If the long argument is greater than 0, stores the real at offset 0x358 and the long at offset 0x37c of that record; otherwise stores the real at offset 0x334. Returns void.
- Evidence: V

### chud_fade_shield_for_player
- Slot: 1269 (table entry 0xa11160)
- Returns: void
- Parameters: a0: player, a1: real, a2: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b35c0 (150 bytes)
- Behavior: If the player argument is not -1, selects the record whose index is the low 16 bits of the player argument (0xc60 bytes each, from the block at per-thread offset 0x5b0; the index is not range checked). If the long argument is greater than 0, stores the real at offset 0x35c and the long at offset 0x380 of that record; otherwise stores the real at offset 0x338. Returns void.
- Evidence: V

### chud_fade_grenades_for_player
- Slot: 1270 (table entry 0xa11110)
- Returns: void
- Parameters: a0: player, a1: real, a2: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b3658 (150 bytes)
- Behavior: If the player argument is not -1, selects the record whose index is the low 16 bits of the player argument (0xc60 bytes each, from the block at per-thread offset 0x5b0; the index is not range checked). If the long argument is greater than 0, stores the real at offset 0x360 and the long at offset 0x384 of that record; otherwise stores the real at offset 0x33c. Returns void.
- Evidence: V

### chud_fade_messages_for_player
- Slot: 1271 (table entry 0xa10ee0)
- Returns: void
- Parameters: a0: player, a1: real, a2: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b36f0 (150 bytes)
- Behavior: If the player argument is not -1, selects the record whose index is the low 16 bits of the player argument (0xc60 bytes each, from the block at per-thread offset 0x5b0; the index is not range checked). If the long argument is greater than 0, stores the real at offset 0x364 and the long at offset 0x388 of that record; otherwise stores the real at offset 0x340. Returns void.
- Evidence: V

### chud_fade_motion_sensor_for_player
- Slot: 1272 (table entry 0xa10e90)
- Returns: void
- Parameters: a0: player, a1: real, a2: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b3788 (150 bytes)
- Behavior: If the player argument is not -1, selects the record whose index is the low 16 bits of the player argument (0xc60 bytes each, from the block at per-thread offset 0x5b0; the index is not range checked). If the long argument is greater than 0, stores the real at offset 0x368 and the long at offset 0x38c of that record; otherwise stores the real at offset 0x344. Returns void.
- Evidence: V

### chud_fade_chapter_title_for_player
- Slot: 1273 (table entry 0xa10fd0)
- Returns: void
- Parameters: a0: player, a1: real, a2: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b3820 (150 bytes)
- Behavior: If the player argument is not -1, selects the record whose index is the low 16 bits of the player argument (0xc60 bytes each, from the block at per-thread offset 0x5b0; the index is not range checked). If the long argument is greater than 0, stores the real at offset 0x36c and the long at offset 0x390 of that record; otherwise stores the real at offset 0x348. Returns void.
- Evidence: V

### chud_fade_cinematics_for_player
- Slot: 1274 (table entry 0xa10f80)
- Returns: void
- Parameters: a0: player, a1: real, a2: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b38b8 (150 bytes)
- Behavior: If the player argument is not -1, selects the record whose index is the low 16 bits of the player argument (0xc60 bytes each, from the block at per-thread offset 0x5b0; the index is not range checked). If the long argument is greater than 0, stores the real at offset 0x370 and the long at offset 0x394 of that record; otherwise stores the real at offset 0x34c. Returns void.
- Evidence: V

### chud_cinematic_fade
- Slot: 1275 (table entry 0xa10f30)
- Returns: void
- Parameters: a0: real, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b3950 (75 bytes)
- Behavior: Calls function_2c3554 with the two reals and returns void. Called functions: function_2c3554 (chud cinematic fade).
- Evidence: V, S

### chud_track_object
- Slot: 1276 (table entry 0xa10d50)
- Returns: void
- Parameters: a0: object, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b399c (119 bytes)
- Behavior: Calls function_2cbc68 with 0, a pointer to a local holding the object, the boolean argument as a byte, 0 and -1 on the stack. Returns void. The function has a stack cookie check. Called functions: function_2cbc68 (chud track object); function_787e00 (stack cookie check).
- Evidence: V, S

### chud_track_object_with_priority (slot 1277)
- Slot: 1277 (table entry 0xa10d00)
- Returns: void
- Parameters: a0: object, a1: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b3a14 (119 bytes)
- Behavior: Calls function_2cbc68 with 0, a pointer to a local holding the object, a byte 1, the long argument as fourth argument and -1 on the stack. Returns void. The function has a stack cookie check. Called functions: function_2cbc68 (chud track object); function_787e00 (stack cookie check).
- Evidence: V, S

### chud_track_object_with_priority (slot 1278)
- Slot: 1278 (table entry 0xa10cb0)
- Returns: void
- Parameters: a0: object, a1: long, a2: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b3a8c (121 bytes)
- Behavior: Calls function_2cbc68 with 0, a pointer to a local holding the object, a byte 1, the long argument as fourth argument and the string id on the stack. Returns void. The function has a stack cookie check. Called functions: function_2cbc68 (chud track object); function_787e00 (stack cookie check).
- Evidence: V, S

### chud_track_flag
- Slot: 1279 (table entry 0xa10e40)
- Returns: void
- Parameters: a0: cutscene_flag, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b3b08 (79 bytes)
- Behavior: Calls function_2cbd68 with the cutscene flag (16-bit, zero-extended), the boolean, 0 and -1. Returns void. Called functions: function_2cbd68 (chud track flag).
- Evidence: V, S

### chud_track_flag_with_priority (slot 1280)
- Slot: 1280 (table entry 0xa10df0)
- Returns: void
- Parameters: a0: cutscene_flag, a1: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b3b58 (79 bytes)
- Behavior: Calls function_2cbd68 with the cutscene flag (16-bit, zero-extended), a byte 1, the long argument and -1. Returns void. Called functions: function_2cbd68 (chud track flag).
- Evidence: V, S

### chud_track_flag_with_priority (slot 1281)
- Slot: 1281 (table entry 0xa10da0)
- Returns: void
- Parameters: a0: cutscene_flag, a1: long, a2: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b3ba8 (79 bytes)
- Behavior: Calls function_2cbd68 with the cutscene flag (16-bit, zero-extended), a byte 1, the long argument and the string id. Returns void. Called functions: function_2cbd68 (chud track flag).
- Evidence: V, S

### chud_track_object_for_player
- Slot: 1282 (table entry 0xa10b70)
- Returns: void
- Parameters: a0: player, a1: object, a2: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b3bf8 (83 bytes)
- Behavior: Calls function_2cbc18 with the player, the object, the boolean, 0 and -1 on the stack. Returns void. Called functions: function_2cbc18 (chud track object for player).
- Evidence: V, S

### chud_track_object_for_player_with_priority (slot 1283)
- Slot: 1283 (table entry 0xa10b20)
- Returns: void
- Parameters: a0: player, a1: object, a2: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b3c4c (83 bytes)
- Behavior: Calls function_2cbc18 with the player, the object, a byte 1, the long argument and -1 on the stack. Returns void. Called functions: function_2cbc18 (chud track object for player).
- Evidence: V, S

### chud_track_object_for_player_with_priority (slot 1284)
- Slot: 1284 (table entry 0xa10c60)
- Returns: void
- Parameters: a0: player, a1: object, a2: long, a3: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b3ca0 (85 bytes)
- Behavior: Calls function_2cbc18 with the player, the object, a byte 1, the long argument and the string id on the stack. Returns void. Called functions: function_2cbc18 (chud track object for player).
- Evidence: V, S

### chud_track_flag_for_player
- Slot: 1285 (table entry 0xa10c10)
- Returns: void
- Parameters: a0: player, a1: cutscene_flag, a2: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b3cf8 (84 bytes)
- Behavior: Calls function_2cbd18 with the player, the cutscene flag (16-bit, zero-extended), the boolean, 0 and -1 on the stack. Returns void. Called functions: function_2cbd18 (chud track flag for player).
- Evidence: V, S

### chud_track_flag_for_player_with_priority (slot 1286)
- Slot: 1286 (table entry 0xa10bc0)
- Returns: void
- Parameters: a0: player, a1: cutscene_flag, a2: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b3d4c (84 bytes)
- Behavior: Calls function_2cbd18 with the player, the cutscene flag (16-bit, zero-extended), a byte 1, the long argument and -1 on the stack. Returns void. Called functions: function_2cbd18 (chud track flag for player).
- Evidence: V, S

### chud_track_flag_for_player_with_priority (slot 1287)
- Slot: 1287 (table entry 0xa10a30)
- Returns: void
- Parameters: a0: player, a1: cutscene_flag, a2: long, a3: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b3da0 (86 bytes)
- Behavior: Calls function_2cbd18 with the player, the cutscene flag (16-bit, zero-extended), a byte 1, the long argument and the string id on the stack. Returns void. Called functions: function_2cbd18 (chud track flag for player).
- Evidence: V, S

### chud_track_object_set_vertical_offset
- Slot: 1288 (table entry 0xa109e0)
- Returns: void
- Parameters: a0: object, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b3df8 (155 bytes)
- Behavior: For i from 0 to 15 and j from 0 to 15, looks at the 0x20-byte entry at block + 0xc60*i + 0xca4 + 0x20*j, where block is the pointer at per-thread offset 0x5b0. When the entry's first dword is 0 and its second dword equals the object argument, it writes the real to the entry's dword at +0x1c. Returns void.
- Evidence: V

### chud_track_cutscene_flag_set_vertical_offset
- Slot: 1289 (table entry 0xa10990)
- Returns: void
- Parameters: a0: cutscene_flag, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b3e94 (167 bytes)
- Behavior: For i from 0 to 15 and j from 0 to 15, looks at the 0x20-byte entry at block + 0xc60*i + 0xca4 + 0x20*j, where block is the pointer at per-thread offset 0x5b0. When the entry's first dword is 1 and its second dword equals the cutscene flag index (16-bit, zero-extended), it writes the real to the entry's dword at +0x1c. Returns void.
- Evidence: V

### chud_breadcrumbs_track_flag
- Slot: 1290 (table entry 0xa10ad0)
- Returns: void
- Parameters: a0: cutscene_flag, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b3f3c (75 bytes)
- Behavior: Calls function_2cbdac with the cutscene flag (16-bit, zero-extended), the boolean and 0. Returns void. Called functions: function_2cbdac (chud breadcrumbs track flag).
- Evidence: V, S

### chud_breadcrumbs_track_flag_with_priority
- Slot: 1291 (table entry 0xa10a80)
- Returns: void
- Parameters: a0: cutscene_flag, a1: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b3f88 (75 bytes)
- Behavior: Calls function_2cbdac with the cutscene flag (16-bit, zero-extended), a byte 1 and the long argument. Returns void. Called functions: function_2cbdac (chud breadcrumbs track flag).
- Evidence: V, S

### chud_breadcrumbs_track_object
- Slot: 1292 (table entry 0xa10850)
- Returns: void
- Parameters: a0: object, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b3fd4 (78 bytes)
- Behavior: Calls function_2cbccc with the object, the boolean, 0 and -1. Returns void. Called functions: function_2cbccc (chud breadcrumbs track object).
- Evidence: V, S

### chud_breadcrumbs_track_position
- Slot: 1293 (table entry 0xa10800)
- Returns: void
- Parameters: a0: real, a1: real, a2: real, a3: string, a4: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b4024 (111 bytes)
- Behavior: Resolves the string with function_1990a0 and calls function_2cbdfc with the three reals, the resolved string, 0 as a stack dword and the boolean as a stack byte. Returns void. Called functions: function_1990a0 (resolves a string argument of a script call to its character data); function_2cbdfc (chud breadcrumbs track position).
- Evidence: V, S

### chud_breadcrumbs_track_position_with_priority
- Slot: 1294 (table entry 0xa107b0)
- Returns: void
- Parameters: a0: real, a1: real, a2: real, a3: string, a4: long, a5: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b4094 (114 bytes)
- Behavior: Resolves the string with function_1990a0 and calls function_2cbdfc with the three reals, the resolved string, the long argument as a stack dword and the boolean as a stack byte. Returns void. Called functions: function_1990a0 (resolves a string argument of a script call to its character data); function_2cbdfc (chud breadcrumbs track position).
- Evidence: V, S

### chud_breadcrumbs_track_object_with_priority (slot 1295)
- Slot: 1295 (table entry 0xa10940)
- Returns: void
- Parameters: a0: object, a1: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b4108 (78 bytes)
- Behavior: Calls function_2cbccc with the object, a byte 1, the long argument and -1. Returns void. Called functions: function_2cbccc (chud breadcrumbs track object).
- Evidence: V, S

### chud_breadcrumbs_track_object_with_priority (slot 1296)
- Slot: 1296 (table entry 0xa108f0)
- Returns: void
- Parameters: a0: object, a1: long, a2: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b4158 (78 bytes)
- Behavior: Calls function_2cbccc with the object, a byte 1, the long argument and the string id. Returns void. Called functions: function_2cbccc (chud breadcrumbs track object).
- Evidence: V, S

### chud_breadcrumbs_track_object_set_vertical_offset
- Slot: 1297 (table entry 0xa108a0)
- Returns: void
- Parameters: a0: object, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b41a8 (164 bytes)
- Behavior: Does nothing when the dword at data_24971e0 is zero. Otherwise, for i from 0 to 15 and j from 0 to 15, looks at the 0x20-byte entry at block + 0xc60*i + 0xca4 + 0x20*j, where block is the pointer at per-thread offset 0x5b0. When the entry's first dword is 0 and its second dword equals the object argument, it writes the real to the entry's dword at +0x1c. Returns void.
- Evidence: V

### chud_breadcrumbs_using_revised_nav_points
- Slot: 1298 (table entry 0xa10680)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b424c
- Behavior: Returns true when the dword at data_24971e0 is nonzero. Arguments: none.
- Evidence: V

### chud_post_message_HACK
- Slot: 1299 (table entry 0xa10630)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: implemented
- Evaluator: function_1b426c (209 bytes)
- Behavior: Resolves the string with function_1990a0, converts it to a wide string of up to 0x200 characters with function_362ac, then for every player in the game (iterator over the array at per-thread offset 0x18) calls function_2c44f0 with the player index, the wide string and 3. Returns void. The function has a stack cookie check. Called functions: function_362ac (string ascii to wide); function_4a380 (advances the in-game players iterator); function_1990a0 (resolves a string argument of a script call to its character data); function_2c44f0 (chud player post message); function_787e00 (stack cookie check).
- Evidence: V, S

### chud_post_message
- Slot: 1300 (table entry 0xa105e0)
- Returns: void
- Parameters: a0: player, a1: string_id
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### chud_post_medal
- Slot: 1301 (table entry 0xa10760)
- Returns: void
- Parameters: a0: player, a1: string_id
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### chud_set_static_hs_variable
- Slot: 1302 (table entry 0xa10710)
- Returns: void
- Parameters: a0: player, a1: long, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b4340 (76 bytes)
- Behavior: Calls function_2c360c with the player, the long argument and the real. Returns void. Called functions: function_2c360c (chud set static hs variable).
- Evidence: V, S

### chud_set_countdown_hs_variable
- Slot: 1303 (table entry 0xa106c0)
- Returns: void
- Parameters: a0: player, a1: long, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b438c (157 bytes)
- Behavior: If the player is not -1 and the variable number (long) is 9 or lower, selects the player's record (low 16 bits of the player, 0xc60 bytes each, block at per-thread offset 0x5b0) and the 12-byte variable entry number (long). Stores the real at entry offset 0x2b0, sets the byte at 0x2a8 to 1 and the dword at 0x2ac to 1. Returns void.
- Evidence: V

### chud_set_countup_hs_variable
- Slot: 1304 (table entry 0xa104a0)
- Returns: void
- Parameters: a0: player, a1: long, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b442c (157 bytes)
- Behavior: If the player is not -1 and the variable number (long) is 9 or lower, selects the player's record (low 16 bits of the player, 0xc60 bytes each, block at per-thread offset 0x5b0) and the 12-byte variable entry number (long). Stores the real at entry offset 0x2b0, sets the byte at 0x2a8 to 1 and the dword at 0x2ac to 2. Returns void.
- Evidence: V

### chud_clear_hs_variable
- Slot: 1305 (table entry 0xa10450)
- Returns: void
- Parameters: a0: player, a1: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b44cc (132 bytes)
- Behavior: If the player is not -1 and the variable number (long) is 9 or lower, clears the byte at offset 0x2a8 of that variable entry (12-byte entries inside the player's 0xc60-byte record in the block at per-thread offset 0x5b0). Returns void.
- Evidence: V

### chud_get_hs_variable
- Slot: 1306 (table entry 0xa10590)
- Returns: void
- Parameters: a0: real, a1: player
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (so any nested calls still run) and then returns 0. It calls no engine function and reads or writes no state. Shared evaluator (11 slots in this range).
- Evidence: V

### chud_show_arbiter_ai_navpoint
- Slot: 1307 (table entry 0xa10540)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (so any nested calls still run) and then returns 0. It calls no engine function and reads or writes no state. Shared evaluator (11 slots in this range).
- Evidence: V

### chud_show_screen_objective
- Slot: 1308 (table entry 0xa104f0)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b4550 (98 bytes)
- Behavior: Writes the string id to the dword at offset 0x168 of the block at per-thread offset 0x5b0 (not a per-player record). Returns void.
- Evidence: V

### chud_show_screen_chapter_title
- Slot: 1309 (table entry 0xa102d0)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b45b4 (98 bytes)
- Behavior: Writes the string id to the dword at offset 0x16c of the block at per-thread offset 0x5b0 (not a per-player record). Returns void.
- Evidence: V

### chud_show_screen_training
- Slot: 1310 (table entry 0xa10280)
- Returns: void
- Parameters: a0: player, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1b4618 (132 bytes)
- Behavior: If function_58eec returns false and the player is not -1, writes the string id to the dword at offset 0x398 of the player's record (low 16 bits of the player, 0xc60 bytes each, block at per-thread offset 0x5b0). Returns void. Called functions: function_58eec (true when a game is active (function_588e0) and the byte at offset 0x1da of the block at per-thread offset 0x48 is nonzero).
- Evidence: V, S

### cls
- Slot: 1311 (table entry 0xa10240)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### events_spam_suppression_enable
- Slot: 1312 (table entry 0xa10400)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### error_geometry_show
- Slot: 1313 (table entry 0xa103b0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### error_geometry_hide
- Slot: 1314 (table entry 0xa10360)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### error_geometry_show_all
- Slot: 1315 (table entry 0xa10320)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### error_geometry_hide_all
- Slot: 1316 (table entry 0xa100c0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### error_geometry_list
- Slot: 1317 (table entry 0xa10080)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### player_effect_set_max_translation
- Slot: 1318 (table entry 0xa10030)
- Returns: void
- Parameters: a0: real, a1: real, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b469c (142 bytes)
- Behavior: For i from 0 to 15, writes the three reals to the dwords at 0xfc, 0x100 and 0x104 (first real at 0xfc) of the i-th 0x114-byte record of the block at per-thread offset 0x1e0. Returns void.
- Evidence: V

### player_effect_set_max_rotation
- Slot: 1319 (table entry 0xa0ffe0)
- Returns: void
- Parameters: a0: real, a1: real, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b472c (177 bytes)
- Behavior: Multiplies each of the three reals by data_a8aac0 (0.0174532924, degrees to radians) and, for i from 0 to 15, writes them to the dwords at 0x108, 0x10c and 0x110 (first real at 0x108) of the i-th 0x114-byte record of the block at per-thread offset 0x1e0. Returns void.
- Evidence: V

### player_effect_set_max_rumble
- Slot: 1320 (table entry 0xa101f0)
- Returns: void
- Parameters: a0: real, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b47e0 (111 bytes)
- Behavior: Writes the first real argument (as raw dword bits) to offset 0x760 and the second real to offset 0x764 of the block at per-thread offset 0x2d8. Returns void.
- Evidence: V

### player_effect_start
- Slot: 1321 (table entry 0xa101a0)
- Returns: void
- Parameters: a0: real, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b4850 (193 bytes)
- Behavior: For i from 0 to 15, with the i-th 0x114-byte record of the block at per-thread offset 0x1e0: stores the first real at record offset 0x114, calls function_5cc74 with the second real and stores the integer it returns in the 16-bit values at offsets 0x118 and 0x11a, sets bit 0 and clears bit 1 of the dword at offset 0xf8. Returns void. Called functions: function_5cc74 (converts seconds (real) to game ticks: 0 when the byte at offset 0 of the block at per-thread offset 0xa0 is zero, otherwise rounds the seconds times the short at +6 of that block).
- Evidence: V

### player_effect_stop
- Slot: 1322 (table entry 0xa10150)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b4914 (165 bytes)
- Behavior: For i from 0 to 15, with the i-th 0x114-byte record of the block at per-thread offset 0x1e0: calls function_5cc74 with the real, stores the integer it returns in the 16-bit values at offsets 0x118 and 0x11a and sets bit 1 of the dword at offset 0xf8. Returns void. Called functions: function_5cc74 (converts seconds (real) to game ticks: 0 when the byte at offset 0 of the block at per-thread offset 0xa0 is zero, otherwise rounds the seconds times the short at +6 of that block).
- Evidence: V

### player_effect_set_max_translation_for_player
- Slot: 1323 (table entry 0xa10100)
- Returns: void
- Parameters: a0: player, a1: real, a2: real, a3: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b49bc (149 bytes)
- Behavior: If the player is not -1, selects the 0x114-byte record numbered by the low 16 bits of the player in the block at per-thread offset 0x1e0 (not range checked) and writes the three reals to its dwords at 0xfc, 0x100 and 0x104 (first real at 0xfc). Returns void.
- Evidence: V

### player_effect_set_max_rotation_for_player
- Slot: 1324 (table entry 0xa0fe60)
- Returns: void
- Parameters: a0: player, a1: real, a2: real, a3: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b4a54 (173 bytes)
- Behavior: If the player is not -1, multiplies the three reals by data_a8aac0 (0.0174532924, degrees to radians) and writes them to the dwords at 0x108, 0x10c and 0x110 of the 0x114-byte record numbered by the low 16 bits of the player in the block at per-thread offset 0x1e0 (not range checked). Returns void.
- Evidence: V

### player_effect_set_max_rumble_for_player
- Slot: 1325 (table entry 0xa0fe10)
- Returns: void
- Parameters: a0: player, a1: real, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b4b04 (183 bytes)
- Behavior: If the player is not -1, walks the output users that belong to the player with function_54044 (starting from the low 16 bits of the player). For each local player index it writes the first real to offset 0x1d0 and the second real to offset 0x1d4 of the 0x1d8-byte record with that index in the block at per-thread offset 0x2d8. Returns void.
- Evidence: V, S

### player_effect_start_for_player
- Slot: 1326 (table entry 0xa0fdc0)
- Returns: void
- Parameters: a0: player, a1: real, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b4bbc (168 bytes)
- Behavior: If the player is not -1, selects the 0x114-byte record numbered by the low 16 bits of the player in the block at per-thread offset 0x1e0 (not range checked), stores the first real at record offset 0x114, calls function_5cc74 with the second real and stores the integer it returns in the 16-bit values at 0x118 and 0x11a, then sets bit 0 and clears bit 1 of the dword at 0xf8. Returns void. Called functions: function_5cc74 (converts seconds (real) to game ticks: 0 when the byte at offset 0 of the block at per-thread offset 0xa0 is zero, otherwise rounds the seconds times the short at +6 of that block).
- Evidence: V

### player_effect_stop_for_player
- Slot: 1327 (table entry 0xa0fd70)
- Returns: void
- Parameters: a0: player, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1b4c64 (144 bytes)
- Behavior: If the player is not -1, selects the 0x114-byte record numbered by the low 16 bits of the player in the block at per-thread offset 0x1e0 (not range checked), calls function_5cc74 with the real, stores the integer it returns in the 16-bit values at 0x118 and 0x11a and sets bit 1 of the dword at 0xf8. Returns void. Called functions: function_5cc74 (converts seconds (real) to game ticks: 0 when the byte at offset 0 of the block at per-thread offset 0xa0 is zero, otherwise rounds the seconds times the short at +6 of that block).
- Evidence: V

### time_code_show
- Slot: 1328 (table entry 0xa0ff90)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### time_code_start
- Slot: 1329 (table entry 0xa0ff40)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### time_code_reset
- Slot: 1330 (table entry 0xa0ff00)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### render_atmosphere_fog
- Slot: 1331 (table entry 0xa0feb0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b4cf4 (112 bytes)
- Behavior: If the pointer at per-thread offset 0x168 is not null, sets bit 2 (0x04) of the byte it points to when the boolean is true and clears it when false. Returns void.
- Evidence: V

### motion_blur
- Slot: 1332 (table entry 0xa0fc30)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b4d64 (112 bytes)
- Behavior: If the pointer at per-thread offset 0x168 is not null, sets bit 0 (0x01) of the byte it points to when the boolean is true and clears it when false. Returns void.
- Evidence: V

### antialias_blur
- Slot: 1333 (table entry 0xa0fbe0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b4dd4 (112 bytes)
- Behavior: If the pointer at per-thread offset 0x168 is not null, sets bit 1 (0x02) of the byte it points to when the boolean is true and clears it when false. Returns void.
- Evidence: V

### render_weather
- Slot: 1334 (table entry 0xa0fd20)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b4e44 (112 bytes)
- Behavior: Calls function_250160 with the boolean. Then, if the byte at offset 0x11 of the block at per-thread offset 0x48 equals 5, calls function_3a5be8 with 0x800. Returns void. Called functions: function_250160 (render weather); function_3a5be8 (marks parts of the game engine globals (bit mask argument) as updated for replication).
- Evidence: V, S

### render_patchy_fog
- Slot: 1335 (table entry 0xa0fcd0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b4eb4 (112 bytes)
- Behavior: If the pointer at per-thread offset 0x168 is not null, sets bit 3 (0x08) of the byte it points to when the boolean is true and clears it when false. Returns void.
- Evidence: V

### render_ssao
- Slot: 1336 (table entry 0xa0fc80)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b4f24 (112 bytes)
- Behavior: If the pointer at per-thread offset 0x168 is not null, sets bit 4 (0x10) of the byte it points to when the boolean is true and clears it when false. Returns void.
- Evidence: V

### render_planar_fog
- Slot: 1337 (table entry 0xa0fac0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b4f94 (112 bytes)
- Behavior: If the pointer at per-thread offset 0x168 is not null, sets bit 6 (0x40) of the byte it points to when the boolean is true and clears it when false. Returns void.
- Evidence: V

### motion_blur_enabled
- Slot: 1338 (table entry 0xa0fa80)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b5004
- Behavior: Returns bit 0 of the byte pointed to by the pointer at per-thread offset 0x168, or false if that pointer is null. Arguments: none.
- Evidence: V

### render_disable_vsync
- Slot: 1339 (table entry 0xa0fa30)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b5048 (112 bytes)
- Behavior: If the pointer at per-thread offset 0x168 is not null, sets bit 7 (0x80) of the byte it points to when the boolean is true and clears it when false. Returns void.
- Evidence: V

### player_has_skills
- Slot: 1340 (table entry 0xa0fba0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated. The declared return type is boolean, so scripts receive 0 (false for boolean).
- Evidence: V

### player_has_mad_secret_skills
- Slot: 1341 (table entry 0xa0fb50)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (so any nested calls still run) and then returns 0. It calls no engine function and reads or writes no state. Shared evaluator (11 slots in this range).
- Evidence: V

### controller_invert_look
- Slot: 1342 (table entry 0xa0fb10)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_look_speed
- Slot: 1343 (table entry 0xa0f8a0)
- Returns: void
- Parameters: a0: short
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### player_invert_look
- Slot: 1344 (table entry 0xa0f850)
- Returns: void
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1b50b8 (68 bytes)
- Behavior: Calls function_65ce0 with the player argument and returns void. Called functions: function_65ce0 (player invert look).
- Evidence: V, S

### user_interface_controller_get_last_level_played
- Slot: 1345 (table entry 0xa0f800)
- Returns: long
- Parameters: a0: short
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_1a4460 (62 bytes)
- Behavior: Evaluates its arguments (so any nested calls still run) and then returns -1. It calls no engine function and reads or writes no state.
- Evidence: V

### controller_set_look_inverted
- Slot: 1346 (table entry 0xa0f9e0)
- Returns: void
- Parameters: a0: controller, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_vibration_enabled
- Slot: 1347 (table entry 0xa0f990)
- Returns: void
- Parameters: a0: controller, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_flight_stick_aircraft_controls
- Slot: 1348 (table entry 0xa0f940)
- Returns: void
- Parameters: a0: controller, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_auto_center_look
- Slot: 1349 (table entry 0xa0f8f0)
- Returns: void
- Parameters: a0: controller, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_crouch_lock
- Slot: 1350 (table entry 0xa0f670)
- Returns: void
- Parameters: a0: controller, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_southpaw
- Slot: 1351 (table entry 0xa0f620)
- Returns: void
- Parameters: a0: controller, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_clench_protection
- Slot: 1352 (table entry 0xa0f5d0)
- Returns: void
- Parameters: a0: controller, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_button_preset
- Slot: 1353 (table entry 0xa0f580)
- Returns: void
- Parameters: a0: controller, a1: button_preset
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_custom_button
- Slot: 1354 (table entry 0xa0f7b0)
- Returns: void
- Parameters: a0: controller, a1: long, a2: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_joystick_preset
- Slot: 1355 (table entry 0xa0f760)
- Returns: void
- Parameters: a0: controller, a1: joystick_preset
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_look_sensitivity
- Slot: 1356 (table entry 0xa0f710)
- Returns: void
- Parameters: a0: controller, a1: short
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_unlock_single_player_levels
- Slot: 1357 (table entry 0xa0f6c0)
- Returns: void
- Parameters: a0: controller
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_lock_single_player_levels
- Slot: 1358 (table entry 0xa0f3f0)
- Returns: void
- Parameters: a0: controller
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_unlock_skulls
- Slot: 1359 (table entry 0xa0f3a0)
- Returns: void
- Parameters: a0: controller
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_lock_skulls
- Slot: 1360 (table entry 0xa0f350)
- Returns: void
- Parameters: a0: controller
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_unlock_models
- Slot: 1361 (table entry 0xa0f300)
- Returns: void
- Parameters: a0: controller
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_lock_models
- Slot: 1362 (table entry 0xa0f530)
- Returns: void
- Parameters: a0: controller
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_single_player_level_completed
- Slot: 1363 (table entry 0xa0f4e0)
- Returns: void
- Parameters: a0: controller, a1: long, a2: boolean, a3: game_difficulty, a4: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_primary_change_color
- Slot: 1364 (table entry 0xa0f490)
- Returns: void
- Parameters: a0: controller, a1: player_color
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_secondary_change_color
- Slot: 1365 (table entry 0xa0f440)
- Returns: void
- Parameters: a0: controller, a1: player_color
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_tertiary_change_color
- Slot: 1366 (table entry 0xa0f170)
- Returns: void
- Parameters: a0: controller, a1: player_color
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_primary_emblem_color
- Slot: 1367 (table entry 0xa0f120)
- Returns: void
- Parameters: a0: controller, a1: player_color
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_secondary_emblem_color
- Slot: 1368 (table entry 0xa0f0d0)
- Returns: void
- Parameters: a0: controller, a1: player_color
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_background_emblem_color
- Slot: 1369 (table entry 0xa0f080)
- Returns: void
- Parameters: a0: controller, a1: player_color
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_player_character_type
- Slot: 1370 (table entry 0xa0f2b0)
- Returns: void
- Parameters: a0: controller, a1: player_model_choice
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_emblem_info
- Slot: 1371 (table entry 0xa0f260)
- Returns: void
- Parameters: a0: controller, a1: short, a2: short
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_voice_output_setting
- Slot: 1372 (table entry 0xa0f210)
- Returns: void
- Parameters: a0: controller, a1: voice_output_setting
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_subtitle_setting
- Slot: 1373 (table entry 0xa0f1c0)
- Returns: void
- Parameters: a0: controller, a1: subtitle_setting
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_nag_message_data
- Slot: 1374 (table entry 0xa0eef0)
- Returns: void
- Parameters: a0: controller, a1: long, a2: long, a3: long, a4: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_temporary_users_always_attached
- Slot: 1375 (table entry 0xa0eea0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_new_user_experience
- Slot: 1376 (table entry 0xa0ee50)
- Returns: void
- Parameters: a0: controller, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_initial_bonus_toast
- Slot: 1377 (table entry 0xa0ee00)
- Returns: void
- Parameters: a0: controller, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_loyalty_bonus_toast
- Slot: 1378 (table entry 0xa0f030)
- Returns: void
- Parameters: a0: controller, a1: short
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_generic_bonus_toast
- Slot: 1379 (table entry 0xa0efe0)
- Returns: void
- Parameters: a0: controller, a1: short
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_set_unsignedin_user
- Slot: 1380 (table entry 0xa0ef90)
- Returns: void
- Parameters: a0: controller, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### controller_display_storage_device_selection
- Slot: 1381 (table entry 0xa0ef40)
- Returns: void
- Parameters: a0: controller
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### font_cache_bitmap_save
- Slot: 1382 (table entry 0xa0ec70)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### ui_debug_load_main_menu
- Slot: 1383 (table entry 0xa0ec30)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### ui_debug_text_bounds
- Slot: 1384 (table entry 0xa0ebe0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### ui_debug_text_font
- Slot: 1385 (table entry 0xa0eb90)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### ui_debug_show_title_safe_bounds
- Slot: 1386 (table entry 0xa0edb0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### ui_debug_element_bounds
- Slot: 1387 (table entry 0xa0ed60)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### ui_memory_dump
- Slot: 1388 (table entry 0xa0ed10)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### ui_time_scale_step
- Slot: 1389 (table entry 0xa0ecc0)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### xoverlapped_debug_render
- Slot: 1390 (table entry 0xa0ea20)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b50fc (69 bytes)
- Behavior: Writes the boolean to the byte at data_46f122a. Returns void.
- Evidence: V

### shader_compile_target_platform
- Slot: 1391 (table entry 0xa0e9d0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### shader_compile_shader_pipeline
- Slot: 1392 (table entry 0xa0e980)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### shader_compile_filter_shader_type
- Slot: 1393 (table entry 0xa0e930)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### shader_compile_filter_category_option
- Slot: 1394 (table entry 0xa0eb40)
- Returns: void
- Parameters: a0: string, a1: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### gui_load_screen
- Slot: 1395 (table entry 0xa0eaf0)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### gui_reset
- Slot: 1396 (table entry 0xa0eab0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### gui_start
- Slot: 1397 (table entry 0xa0ea70)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### gui_stop
- Slot: 1398 (table entry 0xa0e7b0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### gui_error_post
- Slot: 1399 (table entry 0xa0e760)
- Returns: void
- Parameters: a0: string_id, a1: long, a2: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### gui_error_post_toast
- Slot: 1400 (table entry 0xa0e710)
- Returns: void
- Parameters: a0: string_id, a1: long, a2: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### gui_error_resolve
- Slot: 1401 (table entry 0xa0e6c0)
- Returns: void
- Parameters: a0: string_id, a1: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### gui_error_clear
- Slot: 1402 (table entry 0xa0e8e0)
- Returns: void
- Parameters: a0: string_id, a1: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### gui_dialog_show
- Slot: 1403 (table entry 0xa0e890)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### gui_debug_music_state
- Slot: 1404 (table entry 0xa0e840)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### cc_enable
- Slot: 1405 (table entry 0xa0e7f0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1b5144 (110 bytes)
- Behavior: When the boolean is false, sets the dword at data_4e38c24 to 9, clears 0x40 bytes at data_4e38c28 and clears bit 0 of the dword at data_4e38c20. When it is true, sets bit 0 of the dword at data_4e38c20. Returns void.
- Evidence: V

### cc_test
- Slot: 1406 (table entry 0xa0e5d0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: Not implemented. The evaluator is the shared stub function_86cbc: it does not evaluate any argument and hands the value 0 back as the result, so a call has no effect and its argument expressions are never evaluated.
- Evidence: V

### objectives_clear
- Slot: 1407 (table entry 0xa0e590)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1b51b4 (26 bytes)
- Behavior: Calls function_2e782c and returns void. Arguments: none. Called functions: function_2e782c (objectives clear).
- Evidence: V, S

### objectives_show_up_to
- Slot: 1408 (table entry 0xa0e540)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b51d0 (128 bytes)
- Behavior: If the long argument is 0 to 9, goes through objective entries 0 to that number in the 8-byte-stride table whose first byte sits at offset 4 of the block at per-thread offset 0x320 and changes each entry whose byte is 0 to 2. Returns void; other values do nothing.
- Evidence: V

### objectives_finish_up_to
- Slot: 1409 (table entry 0xa0e670)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b5250 (124 bytes)
- Behavior: If the long argument is 0 to 9, sets the byte of objective entries 0 to that number (8-byte stride, first byte at offset 4 of the block at per-thread offset 0x320) to 3. Returns void; other values do nothing.
- Evidence: V

### objectives_show
- Slot: 1410 (table entry 0xa0e620)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1b52cc (105 bytes)
- Behavior: If the long argument is 0 to 9, sets the byte at offset 4 of that objective entry (8-byte stride, block at per-thread offset 0x320) to 2. Returns void; other values do nothing.
- Evidence: V
