# HaloScript natives, slots 471 to 940

Part of the HaloScript reference (see the index). Each entry describes one slot of the function table at RVA 0xa28d40. Names, return types and parameter types come from the table strings; behavior is read from the evaluator code. Engine functions are given by address (function_RVA) and module globals as data_RVA. "Not determined" marks where the code was not followed far enough to say. Behavior lists the calls an evaluator can make, in order; a listed call may depend on the arguments or on state, and the text says so where that was checked. In Behavior, a0, a1, ... name the arguments in call order starting at zero.

Slots 561 to 575 are not listed on this page. Entries follow the order of the function table.

## Common mechanics

- Argument block: function_865e8(thread, count, types) evaluates the argument expressions of the call one at a time on the script thread stack and returns a pointer to a block of 4-byte slots (slot i holds argument i; bytes and 16-bit values use the low part of the slot). It returns null while arguments are still being evaluated; the evaluator then returns without effect and is run again later.
- Result: function_85de0(thread, value) stores the result of the call on the script thread stack according to the return type of the table entry.
- Script thread: function_85754(handle) returns the thread record (0x52c bytes) for a thread handle; bit 15 selects the second thread array.
- AI references: an ai-typed value is a 32-bit reference whose top 3 bits select its kind. function_6be174(ref, iterator) starts an actor iteration and function_6be220(iterator) returns the next actor record (thread-local +0x8 array, 0xd00 bytes per element) or null. Kinds 3 and 4 resolve to a single actor through function_6bd848; kinds 1, 2, 5 and 6 walk squads and their actors (function_6bdea0, function_6be080, function_69c0ec, function_69c150); kinds 0 and 7 select nothing. Nothing is iterated when the byte at +1 of the ai globals block (thread-local +0x30) is 0.
- Datum handles: a 32-bit handle is salt << 16 | index; -1 means none. function_137c4(array, handle) returns the element or null when the handle is -1, the index is not below the array count (+0x44), or the salt word at element +0 is 0 or differs from the handle salt.
- Stack protector: calls to function_787e00 in evaluator code are the stack cookie check and are not described per entry.
- Command script natives (the cs_ family): one evaluator serves both call forms. When the running thread is a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of the thread record and the arguments start at slot 0; otherwise a0 is the AI reference and the arguments follow it. Natives whose ai form has a boolean directly after the ai argument use it as a wait flag (treated as 1 on such a thread); with the flag set the evaluator stores 0xfffffffd at +0xc and the AI reference at +0x24 of the thread record. Some natives (for example cs_shoot, cs_posture_set, cs_custom_animation_loop and cs_vehicle_speed_instantaneous) have no wait flag and never write the thread record. Command script elements (thread-local +0x60, 0x1ec bytes) are found or created per actor with function_6b02c8(actor, script thread handle, create flag); command slots inside an element are created with function_6b0648(element, command type, 1).

### ai_set_targeting_group (slot 471)
- Slot: 471 (table entry 0xa1ffb0)
- Returns: void
- Parameters: a0: ai, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a2244 (75 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_6c10f0(a0, a1 (16-bit), 0); then returns nothing (void). function_6c10f0 (115 bytes): returns early when a0 == -1; calls function_6be174, function_6be220.
- Evidence: V

### ai_set_targeting_group (slot 472)
- Slot: 472 (table entry 0xa1ff60)
- Returns: void
- Parameters: a0: ai, a1: short, a2: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a2290 (76 bytes)
- Behavior: Evaluates 3 argument(s). When all arguments are available it calls function_6c10f0(a0, a1 (16-bit), a2 (8-bit)); then returns nothing (void). function_6c10f0 (115 bytes): returns early when a0 == -1; calls function_6be174, function_6be220.
- Evidence: V

### ai_teleport_to_starting_location_if_outside_bsp
- Slot: 473 (table entry 0xa1fd80)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a22dc (68 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6c1164(a0); then returns nothing (void). function_6c1164 (970 bytes): accesses ai globals (thread-local +0x30 block/header): reads +0x1 byte; touches data at 0xc1a230; calls function_6bdea0, function_6be080, function_69c0ec, function_69c150, function_6a8108, function_710fac, function_6944c0, function_710e54 and 3 more.
- Evidence: V

### ai_teleport_to_spawn_point_if_outside_bsp
- Slot: 474 (table entry 0xa1fd30)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a22dc (68 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6c1164(a0); then returns nothing (void). function_6c1164 (970 bytes): accesses ai globals (thread-local +0x30 block/header): reads +0x1 byte; touches data at 0xc1a230; calls function_6bdea0, function_6be080, function_69c0ec, function_69c150, function_6a8108, function_710fac, function_6944c0, function_710e54 and 3 more.
- Evidence: V

### ai_teleport
- Slot: 475 (table entry 0xa1fce0)
- Returns: void
- Parameters: a0: ai, a1: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_1a2320 (71 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_6c1530(a0, a1); then returns nothing (void). function_6c1530 (803 bytes): accesses swarm (thread-local +0x238 x0x34): reads +0x18 32-bit; touches data at 0x98faf8, 0xc1a230; calls function_6b2950, function_710e54, function_6be174, function_6be220, function_473dc0, function_46cb38, function_46c8b4, function_717f50 and 2 more.
- Evidence: V

### ai_bring_forward
- Slot: 476 (table entry 0xa1fe70)
- Returns: void
- Parameters: a0: object, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a2368 (83 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it if a0 != -1 then calls function_6a663c(a0) and float in xmm2=a1 (float); then returns nothing (void). When a0 == -1 the remaining steps are skipped. function_6a663c (94 bytes): Searches the eight 0x18-byte slots at +0x43c of the ai globals block (thread-local +0x30) for one whose first dword equals the first argument and, if found, calls function_6a6558 with the slot index; returns true when found.
- Evidence: V

### ai_renew
- Slot: 477 (table entry 0xa1fe20)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a23bc (68 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6c1854(); then returns nothing (void). function_6c1854 (428 bytes): accesses object record: reads +0x10c 32-bit, +0x110 32-bit, +0x37c byte | random math (thread-local +0x658 block/header): reads +0x0 32-bit; writes +0x0 32-bit; calls function_6be174, function_6be220, function_6f01b8, function_49dc4c, function_49e2fc, function_48ef18, function_48ce2c.
- Evidence: V

### ai_force_active
- Slot: 478 (table entry 0xa1fdd0)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a2400 (71 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_6c1a00(a0, a1 (8-bit)); then returns nothing (void). function_6c1a00 (350 bytes): accesses ai globals (thread-local +0x30 block/header): reads +0x1 byte; calls function_6bdea0, function_6be080, function_6984c8, function_6bd848, function_137c4.
- Evidence: V

### ai_force_active_by_unit
- Slot: 479 (table entry 0xa1fbb0)
- Returns: void
- Parameters: a0: unit, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a2448 (170 bytes)
- Behavior: Evaluates 2 arguments. When a0 is not -1 it reads the actor handle at +0x1bc of the unit object record (object array thread-local +0x10, record pointer at element +0x10); when that handle is not -1 it indexes the actor array (thread-local +0x8, 0xd00 bytes per element) with its low 16 bits (the salt is not checked) and, when bit 4 of the actor byte +6 is set, copies the low bit of a1 into bit 5 of that byte. Returns nothing.
- Evidence: V

### ai_exit_limbo
- Slot: 480 (table entry 0xa1fb60)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a24f4 (68 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6c1b60(); then returns nothing (void). function_6c1b60 (180 bytes): accesses object record: reads +0x4 32-bit; calls function_6be174, function_6be220, function_474868, function_6a7d98.
- Evidence: V

### ai_playfight
- Slot: 481 (table entry 0xa1fc90)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: The evaluator is the shared stub function_199364. It evaluates its 2 argument(s) and sets the result to 0; no game state is read or written.
- Evidence: V

### ai_reconnect
- Slot: 482 (table entry 0xa1fc50)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: The evaluator is the shared 9-byte stub function_86cbc. It evaluates no argument and sets the result to 0, so the call has no effect.
- Evidence: V

### ai_berserk
- Slot: 483 (table entry 0xa1fc00)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a2538 (164 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_720cec(the current actor, a1 (8-bit), 0). It then returns nothing (void). function_720cec (905 bytes): accesses actor (thread-local +0x8 x0xd00): reads +0x6 byte, +0x1c 16-bit/32-bit, +0x334 32-bit, +0x35d byte; writes +0x35b byte, +0x35d byte, +0x35e byte, +0x362 16-bit, +0x364 16-bit | object record: reads +0x0 32-bit; writes +0x34e byte | stimulus-data (thread-local +0xf8 x0x54): reads +0x8 32-bit; calls function_6a3224, function_721078, function_5cc74, function_49cc24, function_46d6e0, function_48dce0, function_46f0b0, function_48b518 and 4 more.
- Evidence: V

### ai_set_team
- Slot: 484 (table entry 0xa1fa70)
- Returns: void
- Parameters: a0: ai, a1: team
- Kind: normal
- Status: implemented
- Evaluator: function_1a25dc (71 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_6c1c14(a0, a1); then returns nothing (void). function_6c1c14 (201 bytes): accesses ai globals (thread-local +0x30 block/header): reads +0x1 byte; calls function_6bdea0, function_6be080, function_69c0ec, function_6a7c38, function_69c150, function_691a64.
- Evidence: V

### ai_allow_dormant
- Slot: 485 (table entry 0xa1fa20)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: The evaluator is the shared stub function_199364. It evaluates its 2 argument(s) and sets the result to 0; no game state is read or written.
- Evidence: V

### ai_is_attacking
- Slot: 486 (table entry 0xa1f9d0)
- Returns: boolean
- Parameters: a0: ai
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: The evaluator is the shared stub function_199364. It evaluates its 1 argument(s) and sets the result to 0; no game state is read or written. The call yields 0 (false for boolean).
- Evidence: V

### ai_fighting_count
- Slot: 487 (table entry 0xa1fb10)
- Returns: short
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a2624 (81 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6bfb14(a0); then returns the low 16 bits of the result of function_6bfb14. function_6bfb14 (202 bytes): accesses ai globals (thread-local +0x30 block/header): reads +0x1 byte; touches data at 0xc1a230; calls function_6bd848, function_6a8f4c.
- Evidence: V

### ai_living_count
- Slot: 488 (table entry 0xa1fac0)
- Returns: short
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a2678 (89 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6bf84c(a0, 0, 0, 0); then returns the low 16 bits of the result of function_6bf84c. function_6bf84c (501 bytes): accesses ai globals (thread-local +0x30 block/header): reads +0x1 byte | actor (thread-local +0x8 x0xd00): reads +0x1c 16-bit/32-bit, +0x3d8 32-bit; calls function_6bdea0, function_6be080, function_69c0ec, function_69c150, function_6bd848, function_49dbec.
- Evidence: V

### ai_living_fraction
- Slot: 489 (table entry 0xa1f890)
- Returns: real
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a26d4 (115 bytes)
- Behavior: Evaluates 1 argument. Calls function_6bf84c(a0, 0, pointer to a local 32-bit total, null float output), which returns the number of living actors counted for the reference; the local total is the number it counted against. When the total is positive the result is (living count) / (total) as a real, otherwise 0.0.
- Evidence: V

### ai_in_vehicle_count
- Slot: 490 (table entry 0xa1f840)
- Returns: short
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a2748 (92 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6bf84c(a0, 3, 0, 0); then returns the low 16 bits of the result of function_6bf84c. function_6bf84c (501 bytes): accesses ai globals (thread-local +0x30 block/header): reads +0x1 byte | actor (thread-local +0x8 x0xd00): reads +0x1c 16-bit/32-bit, +0x3d8 32-bit; calls function_6bdea0, function_6be080, function_69c0ec, function_69c150, function_6bd848, function_49dbec.
- Evidence: V

### ai_body_count
- Slot: 491 (table entry 0xa1f7f0)
- Returns: short
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a27a4 (81 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6bfa44(a0); then returns the low 16 bits of the result of function_6bfa44. function_6bfa44 (205 bytes): accesses ai globals (thread-local +0x30 block/header): reads +0x1 byte | objectives (thread-local +0x228 x0x18): reads +0x2 16-bit; touches data at 0xc1a230.
- Evidence: V

### ai_strength
- Slot: 492 (table entry 0xa1f980)
- Returns: real
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a27f8 (101 bytes)
- Behavior: Evaluates 1 argument. Calls function_6bf84c(a0, 0, null, pointer to a local float) with the float initialised to 0.0 and returns that float.
- Evidence: V

### ai_swarm_count
- Slot: 493 (table entry 0xa1f930)
- Returns: short
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a2860 (92 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6bf84c(a0, 1, 0, 0); then returns the low 16 bits of the result of function_6bf84c. function_6bf84c (501 bytes): accesses ai globals (thread-local +0x30 block/header): reads +0x1 byte | actor (thread-local +0x8 x0xd00): reads +0x1c 16-bit/32-bit, +0x3d8 32-bit; calls function_6bdea0, function_6be080, function_69c0ec, function_69c150, function_6bd848, function_49dbec.
- Evidence: V

### ai_nonswarm_count
- Slot: 494 (table entry 0xa1f8e0)
- Returns: short
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a28bc (92 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6bf84c(a0, 2, 0, 0); then returns the low 16 bits of the result of function_6bf84c. function_6bf84c (501 bytes): accesses ai globals (thread-local +0x30 block/header): reads +0x1 byte | actor (thread-local +0x8 x0xd00): reads +0x1c 16-bit/32-bit, +0x3d8 32-bit; calls function_6bdea0, function_6be080, function_69c0ec, function_69c150, function_6bd848, function_49dbec.
- Evidence: V

### ai_actors
- Slot: 495 (table entry 0xa1f700)
- Returns: object_list
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a2918 (68 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6be388(a0); then returns the low 32 bits of the result of function_6be388. function_6be388 (265 bytes): accesses swarm (thread-local +0x238 x0x34): reads +0x18 32-bit; calls function_192960, function_6be174, function_6be220, function_1929cc, function_731b98.
- Evidence: V

### ai_allegiance_broken
- Slot: 496 (table entry 0xa1f6b0)
- Returns: boolean
- Parameters: a0: team, a1: team
- Kind: normal
- Status: implemented
- Evaluator: function_1a295c (188 bytes)
- Behavior: Evaluates 2 arguments (two teams). Builds two 16-bit team pairs {team, 0xff} and calls function_13631c for (a0, a1); when that is false it calls function_13631c for (a1, a0). The result is true when either call returns true, otherwise false.
- Evidence: V

### ai_spawn_count
- Slot: 497 (table entry 0xa1f660)
- Returns: short
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a2a18 (139 bytes)
- Behavior: Evaluates 1 argument. Starts an iteration over the squads of the reference with function_6bdea0 and advances it with function_6be080; the result is the 16-bit sum of the word at +0x2a of every squad visited.
- Evidence: V

### object_get_ai
- Slot: 498 (table entry 0xa1f7a0)
- Returns: ai
- Parameters: a0: object
- Kind: normal
- Status: implemented
- Evaluator: function_1a2aa4 (176 bytes)
- Behavior: Evaluates 1 argument. Returns an AI reference for the object a0: when a0 is not -1 and the object type byte at record +0x8e is 0, 1 or 12 (mask 0x1003), and the actor handle at record +0x1bc is not -1, the result is (actor handle & 0x1fffffff) | 0x60000000, an actor-kind reference (kind 3); in every other case, including a0 == -1, the result is 0 (selects nothing).
- Evidence: V

### ai_set_task
- Slot: 499 (table entry 0xa1f750)
- Returns: boolean
- Parameters: a0: ai, a1: string_id, a2: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a2b54 (87 bytes)
- Behavior: Evaluates 3 argument(s). When all arguments are available it calls function_6fe9d8(a0, a1, a2); then returns the low 8 bits of the result of function_6fe9d8. function_6fe9d8 (161 bytes): calls function_6ff338, function_6ff3a0, function_6bdea0, function_6fe77c, function_6be080.
- Evidence: V

### ai_set_objective
- Slot: 500 (table entry 0xa1f520)
- Returns: boolean
- Parameters: a0: ai, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a2bac (86 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_6fe9d8(a0, a1, 0); then returns the low 8 bits of the result of function_6fe9d8. function_6fe9d8 (161 bytes): calls function_6ff338, function_6ff3a0, function_6bdea0, function_6fe77c, function_6be080.
- Evidence: V

### ai_task_status
- Slot: 501 (table entry 0xa1f4d0)
- Returns: short
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a2c04 (81 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6fedc0(a0); then returns the low 16 bits of the result of function_6fedc0. function_6fedc0 (381 bytes): accesses objectives (thread-local +0x228 x0x18): reads +0x2 16-bit; touches data at 0xc1a230; calls function_6be174, function_6be220, function_6fc400.
- Evidence: V

### ai_set_task_condition
- Slot: 502 (table entry 0xa1f480)
- Returns: boolean
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a2c58 (83 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_6fef40(a0, a1 (8-bit)); then returns the low 8 bits of the result of function_6fef40. function_6fef40 (236 bytes): accesses objectives (thread-local +0x228 x0x18): reads +0x2 16-bit; touches data at 0xc1a230.
- Evidence: V

### ai_leadership
- Slot: 503 (table entry 0xa1f610)
- Returns: boolean
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a2cac (80 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6ff02c(a0); then returns the low 8 bits of the result of function_6ff02c. function_6ff02c (234 bytes): accesses objectives (thread-local +0x228 x0x18): reads +0x2 16-bit; touches data at 0xc1a230; calls function_69c900.
- Evidence: V

### ai_leadership_all
- Slot: 504 (table entry 0xa1f5c0)
- Returns: boolean
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a2cfc (80 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6ff118(a0); then returns the low 8 bits of the result of function_6ff118. function_6ff118 (331 bytes): accesses objectives (thread-local +0x228 x0x18): reads +0x2 16-bit; touches data at 0xc1a230; calls function_6ff494.
- Evidence: V

### ai_task_count
- Slot: 505 (table entry 0xa1f570)
- Returns: short
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a2d4c (81 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6ff264(a0); then returns the low 16 bits of the result of function_6ff264. function_6ff264 (211 bytes): touches data at 0xc1a230; calls function_6ff5b0, function_6ff6d0.
- Evidence: V

### ai_reset_objective
- Slot: 506 (table entry 0xa1f350)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a2da0 (68 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6f8994(a0); then returns nothing (void). function_6f8994 (898 bytes): accesses objectives (thread-local +0x228 x0x18): reads +0x4 16-bit | squad (thread-local +0x40 x0xec): reads +0xe4 16-bit; writes +0x96 16-bit, +0x9a 16-bit, +0xe4 16-bit | ai globals (thread-local +0x30 block/header): reads +0x1 byte; touches data at 0xc1a230; calls function_69c0ec, function_6adca0, function_69c150, function_6fdf1c, function_6f88f4, function_6ff5b0, function_6ff6d0, function_6f87d4 and 1 more.
- Evidence: V

### ai_squad_patrol_objective_disallow
- Slot: 507 (table entry 0xa1f300)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a2de4 (149 bytes)
- Behavior: Evaluates 2 arguments (an ai reference and a boolean). Only references of kind 6 (top 3 bits equal 6) are handled: the low 16 bits index the objective array (thread-local +0x228, 0x18 bytes per element) and bit 0 of the word at +0x14 of that element is set when a1 is non-zero and cleared when a1 is 0. Returns nothing.
- Evidence: V

### ai_place_cue
- Slot: 508 (table entry 0xa1f430)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a2e7c (188 bytes)
- Behavior: Evaluates 1 argument (a name id). Starts an iteration over the ai cue array (function_70c8f8 begins it and function_70c938 advances it; nothing is iterated while the ai-enabled byte is 0). For each element it takes the cue index in the dword at element +4 and compares the name id (dword +0) of the 160-byte entry of the scenario ai cue table (scenario +0x3c0) with a0. At the first match, when the dword at element +8 is -1, it calls function_70c7dc with the iteration index; the search then ends. Returns nothing.
- Evidence: V

### ai_remove_cue
- Slot: 509 (table entry 0xa1f3e0)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a2f38 (68 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_70c5c8(a0); then returns nothing (void). function_70c5c8 (167 bytes): accesses ai_cue (thread-local +0x458 x0xc): reads +0x8 32-bit; writes +0x8 32-bit; touches data at 0xc1a230; calls function_70c8f8, function_70c938, function_6f2864.
- Evidence: V

### generate_pathfinding
- Slot: 510 (table entry 0xa1f3a0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented (constant result)
- Evaluator: function_1a2f7c
- Behavior: Takes no argument and evaluates nothing: the evaluator sets the result to the boolean value true (1).
- Evidence: V

### ai_render_paths_all
- Slot: 511 (table entry 0xa1f220)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: The evaluator is the shared 9-byte stub function_86cbc. It evaluates no argument and sets the result to 0, so the call has no effect.
- Evidence: V

### ai_render_evaluations_shading_none
- Slot: 512 (table entry 0xa1f1e0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: The evaluator is the shared 9-byte stub function_86cbc. It evaluates no argument and sets the result to 0, so the call has no effect.
- Evidence: V

### ai_render_evaluations_shading_all
- Slot: 513 (table entry 0xa1f1a0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: The evaluator is the shared 9-byte stub function_86cbc. It evaluates no argument and sets the result to 0, so the call has no effect.
- Evidence: V

### ai_render_evaluations_shading
- Slot: 514 (table entry 0xa1f150)
- Returns: void
- Parameters: a0: firing_point_evaluator
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: The evaluator is the shared 9-byte stub function_86cbc. It evaluates no argument and sets the result to 0, so the call has no effect.
- Evidence: V

### ai_activity_set
- Slot: 515 (table entry 0xa1f2b0)
- Returns: void
- Parameters: a0: ai, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a2f94 (199 bytes)
- Behavior: Evaluates 2 arguments (an ai reference and an activity id). Resolves a1 with function_71b490(a1, pointer to x, pointer to y) into two 16-bit values (both -1 when unresolved); when it returns true, for each actor of a0 it calls function_71b570(actor, x, y, -1, -1) with x the word at the second pointer and y the word at the third. Returns nothing.
- Evidence: V

### ai_activity_abort
- Slot: 516 (table entry 0xa1f260)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a305c (139 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_71b6bc(the current actor). It then returns nothing (void). function_71b6bc (109 bytes): Clears the actor activity: sets words +0x578, +0x57a and +0x57c of the actor (thread-local +0x8, 0xd00 bytes) to -1 and releases the handle at +0x584 with function_6f28d8, setting it to -1.
- Evidence: V

### ai_object_set_team
- Slot: 517 (table entry 0xa1f010)
- Returns: void
- Parameters: a0: object, a1: team
- Kind: normal
- Status: implemented
- Evaluator: function_1a30e8 (169 bytes)
- Behavior: Evaluates 2 argument(s). Looks up a record with function_6c1ce0(a0) (one of eight 0x18-byte entries at +0x4fc of the AI globals block; null when none matches) and does nothing more when there is none. When a1 is not -1: if the first dword of the record is not a0 the record is reset (dword +8 and word +0xc cleared, dword +0 set to a0, dword +0x14 set to 0xff7fffff); then byte +4 is set to the low 8 bits of a1 and function_69170c is called with a1 as its second argument (its first argument is not one of the script arguments; what it stands for was not determined). When a1 is -1 and the first dword of the record is not -1, function_69170c is called with -1 as its second argument, then dword +0 and byte +4 are set to -1. Returns nothing (void). function_6c1ce0 (144 bytes): accesses ai globals (thread-local +0x30 block table x0x18): reads +0x4fc 32-bit. function_69170c (328
  bytes): accesses ai globals (thread-local +0x30 block/header): reads +0x1 byte | prop (thread-local +0x50 x0xb0): reads +0x20 32-bit; calls function_73a358, function_69c1c4, function_1361f8, function_707b78, function_73a3c4, function_738fc4, function_73a314.
- Evidence: V

### ai_object_set_targeting_bias
- Slot: 518 (table entry 0xa1efc0)
- Returns: void
- Parameters: a0: object, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a3194 (119 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_6c1ce0(a0); then if 1 <= max(a1, -1) then stores 1 to the record returned by function_6c1ce0 at +0x8; then returns nothing (void). When 1 > max(a1, -1) it instead stores max(a1, -1) to the record returned by function_6c1ce0 at +0x8. function_6c1ce0 (144 bytes): accesses ai globals (thread-local +0x30 block table x0x18): reads +0x4fc 32-bit.
- Evidence: V

### ai_object_set_targeting_ranges
- Slot: 519 (table entry 0xa1ef70)
- Returns: void
- Parameters: a0: object, a1: real, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a320c (138 bytes)
- Behavior: Evaluates 3 argument(s). When all arguments are available it calls function_6c1ce0(a0); then if a2 (float) >= a1 (float) then stores abs(a2) to the record returned by function_6c1ce0 at +0x14; then stores abs(a1) to the record returned by function_6c1ce0 at +0x10; then returns nothing (void). When a2 (float) < a1 (float) the remaining steps are skipped. function_6c1ce0 (144 bytes): accesses ai globals (thread-local +0x30 block table x0x18): reads +0x4fc 32-bit.
- Evidence: V

### ai_object_enable_targeting_from_vehicle
- Slot: 520 (table entry 0xa1f100)
- Returns: void
- Parameters: a0: object, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a3298 (91 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_6c1ce0(a0); then stores a1 (8-bit) to the record returned by function_6c1ce0 at +0xc; then returns nothing (void). function_6c1ce0 (144 bytes): accesses ai globals (thread-local +0x30 block table x0x18): reads +0x4fc 32-bit.
- Evidence: V

### ai_object_enable_grenade_attack
- Slot: 521 (table entry 0xa1f0b0)
- Returns: void
- Parameters: a0: object, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a32f4 (91 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_6c1ce0(a0); then stores a1 (8-bit) to the record returned by function_6c1ce0 at +0xd; then returns nothing (void). function_6c1ce0 (144 bytes): accesses ai globals (thread-local +0x30 block table x0x18): reads +0x4fc 32-bit.
- Evidence: V

### ai_vehicle_get
- Slot: 522 (table entry 0xa1f060)
- Returns: vehicle
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a3350 (199 bytes)
- Behavior: Evaluates 1 argument. Returns the handle of the vehicle carrying the actor named by a0, or -1. The reference must be of kind 3 or 4 (top 3 bits); it is resolved with function_6bd848 to an actor handle (-1 gives -1), looked up in the actor array with function_137c4 (null gives -1), the unit object index is the word at actor +0x1c, the dword at +0x14 of that unit record is taken as the parent handle, and the parent is returned only when its record byte +0x8e equals 1 (object type 1); otherwise -1.
- Evidence: V

### ai_vehicle_get_from_starting_location
- Slot: 523 (table entry 0xa1ee80)
- Returns: vehicle
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a3418 (88 bytes)
- Behavior: Evaluates 1 argument. Returns -1 unless a0 is an AI reference of kind 4 (top 3 bits equal 4), in which case the result is the value returned by function_6bda90(a0). Used by two natives with the same behavior.
- Evidence: V

### ai_vehicle_get_from_spawn_point
- Slot: 524 (table entry 0xa1ee30)
- Returns: vehicle
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a3418 (88 bytes)
- Behavior: Evaluates 1 argument. Returns -1 unless a0 is an AI reference of kind 4 (top 3 bits equal 4), in which case the result is the value returned by function_6bda90(a0). Used by two natives with the same behavior.
- Evidence: V

### ai_vehicle_get_squad_count
- Slot: 525 (table entry 0xa1ede0)
- Returns: short
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a3470 (224 bytes)
- Behavior: Evaluates 1 argument. Returns the number of objects in the vehicle list of a squad: a0 must be a squad reference (kind 1, mask 0xe0000000 == 0x20000000) whose index (low 16 bits, signed) is not negative and below the dword at +0x398 of the scenario data; the squad (thread-local +0x40, 0xec bytes per element) dword +0xa8 is the first object handle, and the list is followed through the dword at +0xb74 of each object record until -1. Any other reference, an out-of-range index or an empty list gives 0. The result is a 16-bit count.
- Evidence: V

### ai_vehicle_get_from_squad
- Slot: 526 (table entry 0xa1ef20)
- Returns: vehicle
- Parameters: a0: ai, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a3550 (94 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it if (a0 & 3758096384) == 0x20000000 then calls function_6bda90(a0, a1 (16-bit)); then returns the low 32 bits of the result of function_6bda90. When (a0 & 3758096384) != 0x20000000 the remaining steps are skipped. function_6bda90 (428 bytes): accesses ai globals (thread-local +0x30 block/header): reads +0x1 byte | squad (thread-local +0x40 x0xec): reads +0xa8 32-bit | object record: reads +0xb74 32-bit, +0xb78 32-bit; touches data at 0xc1a230.
- Evidence: V

### ai_vehicle_reserve_seat
- Slot: 527 (table entry 0xa1eed0)
- Returns: boolean
- Parameters: a0: vehicle, a1: unit_seat_mapping, a2: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a35b0 (87 bytes)
- Behavior: Evaluates 3 argument(s). When all arguments are available it calls function_6c1d70(a0, a1, a2 (8-bit)); then returns the low 8 bits of the result of function_6c1d70. function_6c1d70 (223 bytes): uses thread-local fields +0x10 (object); calls function_2367e4.
- Evidence: V

### ai_vehicle_reserve
- Slot: 528 (table entry 0xa1eca0)
- Returns: boolean
- Parameters: a0: vehicle, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a3608 (83 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_6c1e50(a0, a1 (8-bit)); then returns the low 8 bits of the result of function_6c1e50. function_6c1e50 (220 bytes): accesses object (thread-local +0x10 x0x18): reads +0x4 byte | object record: writes +0xb80 64-bit; calls function_49572c.
- Evidence: V

### ai_player_get_vehicle_squad
- Slot: 529 (table entry 0xa1ec50)
- Returns: ai
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_1a365c (68 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6bdc3c(a0); then returns the low 32 bits of the result of function_6bdc3c. function_6bdc3c (176 bytes): accesses object record: reads +0x14 32-bit, +0x8e byte, +0x336 16-bit, +0xb70 32-bit | object (thread-local +0x10 x0x18): reads +0x4 byte; calls function_473d70.
- Evidence: V

### ai_vehicle_count
- Slot: 530 (table entry 0xa1ec00)
- Returns: short
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a36a0 (81 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6bddc0(a0); then returns the low 16 bits of the result of function_6bddc0. function_6bddc0 (221 bytes): calls function_6be174, function_78932a, function_6be220.
- Evidence: V

### ai_carrying_player
- Slot: 531 (table entry 0xa1ed90)
- Returns: boolean
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a36f4 (172 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference a0 (see AI references above) and returns true as soon as an actor has a non-zero byte at +0x3d4 of its actor record; returns false when no actor does or when a0 is -1.
- Evidence: V

### player_in_vehicle
- Slot: 532 (table entry 0xa1ed40)
- Returns: boolean
- Parameters: a0: vehicle
- Kind: normal
- Status: implemented
- Evaluator: function_1a37a0 (80 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6bdcec(); then returns the low 8 bits of the result of function_6bdcec. function_6bdcec (212 bytes): accesses object record: reads +0x14 32-bit; calls function_473d70, function_1381c, function_4a1a8.
- Evidence: V

### ai_player_needs_vehicle
- Slot: 533 (table entry 0xa1ecf0)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1a37f0 (105 bytes)
- Behavior: Evaluates 1 argument (a player). When a0 is -1 the result is false. Otherwise it finds the player in the eight 0x3c-byte entries of the ai player state (thread-local +0x1c0) with function_68c4d0, which returns an entry index or 0xffff when the player is not in the table, and returns function_68c558 of that 16-bit index. function_68c558 takes the 16-bit index as signed, so the not-found value 0xffff reads the 0x3c bytes before the table.
- Evidence: V

### ai_player_any_needs_vehicle
- Slot: 534 (table entry 0xa1ead0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1a385c (179 bytes)
- Behavior: Takes no arguments (the evaluator reads none). Loops over the eight 0x3c-byte entries of the ai player state (thread-local +0x1c0); an entry is skipped when its first dword is -1 or when the player it names (low 16 bits, players array thread-local +0x18, 0x490 bytes per element) has dword +0x28 equal to -1; for the first usable entry it calls function_68c558(entry index) and stops when that returns true. The result is the last value returned by function_68c558 (false when no entry qualified), stored with function_85de0.
- Evidence: V

### ai_vehicle_enter (slot 535)
- Slot: 535 (table entry 0xa1ea80)
- Returns: void
- Parameters: a0: ai, a1: unit, a2: unit_seat_mapping
- Kind: normal
- Status: implemented
- Evaluator: function_1a3910 (78 bytes)
- Behavior: Evaluates 3 argument(s). When all arguments are available it calls function_6c0dcc(a0, a1, a2, 0); then returns nothing (void). function_6c0dcc (261 bytes): returns early when a0 == -1; calls function_4739cc, function_473d70, function_2367e4, function_6be174, function_6be220, function_6c0218.
- Evidence: V

### ai_vehicle_enter (slot 536)
- Slot: 536 (table entry 0xa1ebb0)
- Returns: void
- Parameters: a0: ai, a1: unit
- Kind: normal
- Status: implemented
- Evaluator: function_1a3960 (78 bytes)
- Behavior: Evaluates 2 arguments (an ai reference and a unit). Calls function_6c0dcc(a0, a1, -1, 0). Returns nothing.
- Evidence: V

### ai_vehicle_enter_immediate (slot 537)
- Slot: 537 (table entry 0xa1eb60)
- Returns: void
- Parameters: a0: ai, a1: unit, a2: unit_seat_mapping
- Kind: normal
- Status: implemented
- Evaluator: function_1a39b0 (78 bytes)
- Behavior: Evaluates 3 argument(s). When all arguments are available it calls function_6c0dcc(a0, a1, a2, 1); then returns nothing (void). function_6c0dcc (261 bytes): returns early when a0 == -1; calls function_4739cc, function_473d70, function_2367e4, function_6be174, function_6be220, function_6c0218.
- Evidence: V

### ai_vehicle_enter_immediate (slot 538)
- Slot: 538 (table entry 0xa1eb10)
- Returns: void
- Parameters: a0: ai, a1: unit
- Kind: normal
- Status: implemented
- Evaluator: function_1a3a00 (78 bytes)
- Behavior: Evaluates 2 arguments (an ai reference and a unit). Calls function_6c0dcc(a0, a1, -1, 1); the final 1 is the only difference from the non-immediate native. Returns nothing.
- Evidence: V

### ai_enter_squad_vehicles
- Slot: 539 (table entry 0xa1e990)
- Returns: short
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a3a50 (81 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6c0070(); then returns the low 16 bits of the result of function_6c0070. function_6c0070 (424 bytes): accesses object record: reads +0xb74 32-bit; calls function_86c2d0, function_6bdea0, function_6be080, function_49572c, function_6be174, function_6be220, function_6c0218.
- Evidence: V

### ai_vehicle_exit (slot 540)
- Slot: 540 (table entry 0xa1e940)
- Returns: void
- Parameters: a0: ai, a1: unit_seat_mapping
- Kind: normal
- Status: implemented
- Evaluator: function_1a3aa4 (71 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_6c0ed4(a0, a1); then returns nothing (void). function_6c0ed4 (307 bytes): accesses object record: reads +0x14 32-bit, +0x336 16-bit; calls function_6be174, function_6be220, function_2368e4, function_78932a, function_49f24c.
- Evidence: V

### ai_vehicle_exit (slot 541)
- Slot: 541 (table entry 0xa1e8f0)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a3aec (71 bytes)
- Behavior: Evaluates 1 argument. Calls function_6c0ed4(a0, -1). Returns nothing.
- Evidence: V

### vehicle_overturned
- Slot: 542 (table entry 0xa1ea30)
- Returns: boolean
- Parameters: a0: vehicle
- Kind: normal
- Status: implemented
- Evaluator: function_1a3b34 (97 bytes)
- Behavior: Evaluates 1 argument. Returns false for -1; otherwise returns the low byte of function_4aed10(a0), which compares the up vector of the object against a limit.
- Evidence: V

### vehicle_flip
- Slot: 543 (table entry 0xa1e9e0)
- Returns: void
- Parameters: a0: vehicle
- Kind: normal
- Status: implemented
- Evaluator: function_1a3b98 (117 bytes)
- Behavior: Evaluates 1 argument. Builds a zeroed 0x44-byte unit action request with action id 0x16 and dword +4 = -1 and calls function_49f24c(a0, request). Returns nothing.
- Evidence: V

### ai_squad_group_get_squad
- Slot: 544 (table entry 0xa1e7b0)
- Returns: ai
- Parameters: a0: ai, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a3c10 (162 bytes)
- Behavior: Evaluates 2 arguments (an ai reference and an index). Only a reference of kind 2 (top 3 bits equal 2) is handled: it starts an iteration over its squads with function_6bdea0 and advances it with function_6be080 until the squad with ordinal a1 (16-bit) is reached; the result is the 16-bit squad index of that squad with bit 29 set (a squad reference). Other kinds, or an index beyond the last squad, give 0.
- Evidence: V

### ai_squad_group_get_squad_count
- Slot: 545 (table entry 0xa1e760)
- Returns: short
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a3cb4 (155 bytes)
- Behavior: Evaluates 1 argument. For a reference of kind 2 (top 3 bits equal 2) it counts the squads returned by the iteration function_6bdea0 / function_6be080 and returns the 16-bit count; other kinds give 0.
- Evidence: V

### ai_squad_patrol_enable
- Slot: 546 (table entry 0xa1e710)
- Returns: void
- Parameters: a0: string_id, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a3d50 (71 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_70cc5c(a0, a1 (8-bit)); then returns nothing (void). function_70cc5c (218 bytes): uses thread-local fields +0x2b0 (squad_patrol); touches data at 0xc1a230; calls function_124a90.
- Evidence: V

### ai_combat_status
- Slot: 547 (table entry 0xa1e8a0)
- Returns: short
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a3d98 (168 bytes)
- Behavior: Evaluates 1 argument. Iterates the actors of the reference and returns the largest signed 16-bit value of the word at +0x32a of the actor records, starting from 0.
- Evidence: V

### ai_set_combat_status
- Slot: 548 (table entry 0xa1e850)
- Returns: void
- Parameters: a0: ai, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a3e40 (159 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it stores a1 (16-bit) to the record returned by function_6be220 at +0x32a. It then returns nothing (void).
- Evidence: V

### flock_start
- Slot: 549 (table entry 0xa1e800)
- Returns: boolean
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a3ee0 (146 bytes)
- Behavior: Evaluates 1 argument (a name id). Looks the flock up with function_74c288; when found it sets bit 3 (0x08) of the word at +2 of the 0xfc-byte flock element (thread-local +0xb0) and returns true; otherwise false.
- Evidence: V

### flock_stop
- Slot: 550 (table entry 0xa1e5d0)
- Returns: boolean
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a3f74 (151 bytes)
- Behavior: Evaluates 1 argument (a name id). Looks the flock up with function_74c288; when found it clears bit 3 (mask 0xfff7) of the word at +2 of the flock element (thread-local +0xb0, 0xfc bytes) and returns true; otherwise false.
- Evidence: V

### flock_create
- Slot: 551 (table entry 0xa1e580)
- Returns: boolean
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a400c (80 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6c26c0(a0); then returns the low 8 bits of the result of function_6c26c0. function_6c26c0 (214 bytes): touches data at 0xc1a230, 0x4e2fb2c; calls function_7447d4.
- Evidence: V

### flock_delete
- Slot: 552 (table entry 0xa1e6c0)
- Returns: boolean
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a405c (106 bytes)
- Behavior: Evaluates 1 argument (a name id). Looks the flock up with function_74c288; when found it calls function_74782c(flock index, 0) and returns true; otherwise false.
- Evidence: V

### flock_destroy
- Slot: 553 (table entry 0xa1e670)
- Returns: boolean
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a40c8 (150 bytes)
- Behavior: Evaluates 1 argument (a name id). Looks the flock up with function_74c288; when found it copies the word at +0xb0 of the 0xfc-byte flock element (thread-local +0xb0) to +0xf8 and stores the current game time dword (+0xc of the game time globals, thread-local +0xa0) at +0xf4. Returns nothing.
- Evidence: V

### flock_definition_set
- Slot: 554 (table entry 0xa1e620)
- Returns: boolean
- Parameters: a0: string_id, a1: any_tag
- Kind: normal
- Status: implemented
- Evaluator: function_1a4160 (142 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it if a0 != -1 and a1 != -1 then calls function_74c288(a0); then stores a1 to field +0x8 of the flocks element (thread-local +0xb0 x0xfc); then returns 0. When a1 == -1 the remaining steps are skipped. When a0 == -1 the remaining steps are skipped. Inline state access: flocks (thread-local +0xb0 x0xfc): writes +0x8 32-bit. function_74c288 (176 bytes): accesses ai globals (thread-local +0x30 block/header): reads +0x1 byte; touches data at 0xc1a230; calls function_74c038, function_69c1c4.
- Evidence: V

### flock_unperch
- Slot: 555 (table entry 0xa1e440)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a41f0 (85 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it if a0 != -1 then calls function_74c288(a0); then calls function_74c3f0(); then returns nothing (void). When a0 == -1 the remaining steps are skipped. function_74c288 (176 bytes): accesses ai globals (thread-local +0x30 block/header): reads +0x1 byte; touches data at 0xc1a230; calls function_74c038, function_69c1c4. function_74c3f0 (218 bytes): accesses random math (thread-local +0x658 block/header): reads +0x0 32-bit; writes +0x0 32-bit; calls function_74c1c8, function_74c21c, function_5cc74.
- Evidence: V

### flock_set_targeting_group
- Slot: 556 (table entry 0xa1e3f0)
- Returns: void
- Parameters: a0: string_id, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a4248 (142 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it if a0 != -1 then calls function_74c288(a0); then stores a1 (16-bit) to field +0xc0 of the flocks element (thread-local +0xb0 x0xfc); then returns nothing (void). When a0 == -1 the remaining steps are skipped. Inline state access: flocks (thread-local +0xb0 x0xfc): writes +0xc0 16-bit. function_74c288 (176 bytes): accesses ai globals (thread-local +0x30 block/header): reads +0x1 byte; touches data at 0xc1a230; calls function_74c038, function_69c1c4.
- Evidence: V

### flock_destination_set_enabled
- Slot: 557 (table entry 0xa1e3a0)
- Returns: void
- Parameters: a0: string_id, a1: string_id, a2: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a42d8 (239 bytes)
- Behavior: Evaluates 3 arguments (a flock name id, a destination name id and a boolean). Does nothing when either id is -1, the flock is not found (function_74c288) or the destination is not found (function_74c338 returns -1). Otherwise it edits the 16-bit flag word at +0xc of the 16-byte destination entry of the flock element (thread-local +0xb0, 0xfc bytes): bit 0 is cleared when a2 is non-zero and set when a2 is 0. Returns nothing.
- Evidence: V

### flock_destination_set_position
- Slot: 558 (table entry 0xa1e530)
- Returns: void
- Parameters: a0: string_id, a1: string_id, a2: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_1a43c8 (75 bytes)
- Behavior: Evaluates 3 argument(s). When all arguments are available it calls function_6c2798(a0, a1, a2); then returns nothing (void). function_6c2798 (283 bytes): uses thread-local fields +0xb0 (flocks); touches data at 0xc1a230; calls function_6b2950, function_74c288, function_710e54, function_74c338.
- Evidence: V

### flock_destination_copy_position
- Slot: 559 (table entry 0xa1e4e0)
- Returns: void
- Parameters: a0: string_id, a1: string_id, a2: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a4414 (75 bytes)
- Behavior: Evaluates 3 argument(s). When all arguments are available it calls function_6c28b4(a0, a1, a2); then returns nothing (void). function_6c28b4 (204 bytes): uses thread-local fields +0xb0 (flocks); calls function_74c288, function_74c338.
- Evidence: V

### drop_ai
- Slot: 560 (table entry 0xa1e490)
- Returns: void
- Parameters: a0: string, a1: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: The evaluator is the shared 9-byte stub function_86cbc. It evaluates no argument and sets the result to 0, so the call has no effect.
- Evidence: V

### ai_verify_tags
- Slot: 576 (table entry 0xa1dfb0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: The evaluator is the shared 9-byte stub function_86cbc. It evaluates no argument and sets the result to 0, so the call has no effect.
- Evidence: V

### ai_wall_lean
- Slot: 577 (table entry 0xa1ddd0)
- Returns: boolean
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a44a0 (154 bytes)
- Behavior: Evaluates 1 argument. Resolves a0 with function_6bd848 to a single actor handle (-1 stops with result 0), indexes the actor array (thread-local +0x8, 0xd00 bytes per element) with the low 16 bits and calls function_49f210(unit handle at actor +0x1c, 0x19), which starts unit action id 0x19 through function_49f24c. Returns the low byte of the result of function_49f210 (false when no actor).
- Evidence: V

### ai_fire_dialogue_event
- Slot: 578 (table entry 0xa1dd80)
- Returns: void
- Parameters: a0: ai, a1: string, a2: object
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: The evaluator is the shared stub function_199364. It evaluates its 3 argument(s) and sets the result to 0; no game state is read or written.
- Evidence: V

### ai_play_vocalization
- Slot: 579 (table entry 0xa1dd30)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a453c (71 bytes)
- Behavior: Evaluates 1 argument (a vocalization id). Calls function_69d70c(a0, -1). Returns nothing.
- Evidence: V

### ai_play_vocalization_on_team
- Slot: 580 (table entry 0xa1de70)
- Returns: void
- Parameters: a0: string_id, a1: team
- Kind: normal
- Status: implemented
- Evaluator: function_1a4584 (71 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_69d70c(a0, a1); then returns nothing (void). function_69d70c (414 bytes): accesses actor (thread-local +0x8 x0xd00): reads +0x1c 32-bit | game time globals (T) (thread-local +0xa0 block/header): reads +0xc 32-bit; calls function_69d0e4, function_6a48e0, function_69d530, function_69ce18, function_69fe78.
- Evidence: V

### ai_play_line
- Slot: 581 (table entry 0xa1de20)
- Returns: real
- Parameters: a0: ai, a1: ai_line
- Kind: normal
- Status: implemented
- Evaluator: function_1a45cc (89 bytes)
- Behavior: Evaluates 2 arguments (an ai reference and an ai line). Calls function_6c1fac(a0, a1); the result is the low 16 bits of its return value, sign-extended and converted to a real.
- Evidence: V

### ai_play_line_at_player
- Slot: 582 (table entry 0xa1dbf0)
- Returns: real
- Parameters: a0: ai, a1: ai_line
- Kind: normal
- Status: implemented
- Evaluator: function_1a4628 (89 bytes)
- Behavior: Evaluates 2 arguments (an ai reference and an ai line). Calls function_6c2184(a0, a1); the result is the low 16 bits of its return value, sign-extended and converted to a real.
- Evidence: V

### ai_play_line_on_object
- Slot: 583 (table entry 0xa1dba0)
- Returns: real
- Parameters: a0: object, a1: ai_line
- Kind: normal
- Status: implemented
- Evaluator: function_1a4684 (247 bytes)
- Behavior: Evaluates 2 arguments (an object and an ai line). When a1 is not -1 and the dword at +0x670 of the scenario data (the ai line table count) is positive, it looks the line up with function_711644; when a record is found whose dword +0x10 is not -1 it calls function_bb840 with that sound reference, the object a0, a float constant and an output pointer (the line duration in seconds is written there) and then calls function_71120c with the same reference, the line id (dword +0 of the record) and the duration. The duration is converted with function_81b08 (seconds to game ticks) and the result is that tick value as a real; with no line it is 0.0.
- Evidence: V

### ai_play_line_on_object_for_team
- Slot: 584 (table entry 0xa1db50)
- Returns: real
- Parameters: a0: object, a1: ai_line, a2: mp_team
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_1a477c (72 bytes)
- Behavior: The evaluator is the shared stub function_199364. It evaluates its 3 argument(s) and sets the result to 0; no game state is read or written. The call yields 0 (false for boolean).
- Evidence: V

### ai_play_line_on_point_set (slot 585)
- Slot: 585 (table entry 0xa1dce0)
- Returns: short
- Parameters: a0: string_id, a1: point_reference, a2: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a47c4 (92 bytes)
- Behavior: Evaluates 3 argument(s). When all arguments are available it calls function_6c2454(a0, a1, a2 (16-bit), 0); then returns the low 16 bits of the result of function_6c2454. function_6c2454 (619 bytes): touches data at 0xc1a230; calls function_6c2364, function_689724, function_710e54, function_91a14a, function_91a192, function_71092c, function_71178c, function_81b08.
- Evidence: V

### ai_play_line_on_point_set (slot 586)
- Slot: 586 (table entry 0xa1dc90)
- Returns: short
- Parameters: a0: string_id, a1: point_reference, a2: short, a3: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a4820 (93 bytes)
- Behavior: Evaluates 4 argument(s). When all arguments are available it calls function_6c2454(a0, a1, a2 (16-bit), a3); then returns the low 16 bits of the result of function_6c2454. function_6c2454 (619 bytes): touches data at 0xc1a230; calls function_6c2364, function_689724, function_710e54, function_91a14a, function_91a192, function_71092c, function_71178c, function_81b08.
- Evidence: V

### campaign_metagame_time_pause
- Slot: 587 (table entry 0xa1dc40)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a4880 (124 bytes)
- Behavior: Evaluates 1 argument. Sets bit 0 of the byte at +0x19e of the campaign meta-game block (thread-local +0x190) when a0 is non-zero and clears it when a0 is 0; the evaluator does not check that the block exists. Returns nothing.
- Evidence: V

### campaign_metagame_award_points
- Slot: 588 (table entry 0xa1da10)
- Returns: void
- Parameters: a0: player, a1: long
- Kind: normal
- Status: implemented
- Evaluator: function_1a48fc (76 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it if a0 != -1 then calls function_a099c(a0, a1); then returns nothing (void). When a0 == -1 the remaining steps are skipped. function_a099c (356 bytes): Campaign meta-game point award: does nothing when bit 1 of byte +0x19e of the campaign meta-game globals (thread-local +0x190) is set or function_48a14 returns true; otherwise adds the scaled amount to the player records found by function_a194c and function_a1a20 (+0xc/+0x10 for gains, +0x14/+0x18 for losses) and calls function_3a8f5c.
- Evidence: V

### campaign_metagame_award_skull
- Slot: 589 (table entry 0xa1d9c0)
- Returns: void
- Parameters: a0: player, a1: skull
- Kind: normal
- Status: implemented
- Evaluator: function_1a4948 (71 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_a0b00(a0, a1); then returns nothing (void). function_a0b00 (170 bytes): Campaign meta-game skull award: unless function_58eec is true, for a player with a mapped record sets bit a1 (at most 0x28) in the dword at +0x8c of the 0xab8-byte record and calls function_2c8764 when the value changed.
- Evidence: V

### campaign_metagame_enabled
- Slot: 590 (table entry 0xa1d980)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1a4990 (38 bytes)
- Behavior: When all arguments are available it calls function_a0ff4(); then returns the low 8 bits of the result of function_a0ff4. function_a0ff4 (71 bytes): True when byte +0x1e6 of game globals (thread-local +0x48) is non-zero, the campaign meta-game block (thread-local +0x190) exists and bits 2 and 3 of its byte +0x19e are clear.
- Evidence: V

### campaign_survival_enabled
- Slot: 591 (table entry 0xa1d940)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1a49b8 (38 bytes)
- Behavior: When all arguments are available it calls function_58bbc(); then returns the low 8 bits of the result of function_58bbc. function_58bbc (72 bytes): True when function_588e0 returns true and byte +0x10 of game globals (thread-local +0x48) equals 2.
- Evidence: V

### thespian_performance_test
- Slot: 592 (table entry 0xa1db00)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: The evaluator is the shared stub function_199364. It evaluates its 1 argument(s) and sets the result to 0; no game state is read or written.
- Evidence: V

### thespian_folder_activate
- Slot: 593 (table entry 0xa1dab0)
- Returns: void
- Parameters: a0: folder
- Kind: normal
- Status: implemented
- Evaluator: function_1a49e0 (213 bytes)
- Behavior: Evaluates 1 argument (a folder index). When a0 is not -1 and the performance count (dword at scenario +0x7e8) is positive, it walks the performance table (0x18-byte entries at scenario +0x7ec); for every entry whose signed word at +0xe equals a0 it builds a small request {entry index, index + 1 as a 16-bit value} and calls function_6ea6c8 with it; when that returns false it calls function_6ea9d0 with the same request. Returns nothing.
- Evidence: V

### thespian_folder_deactivate
- Slot: 594 (table entry 0xa1da60)
- Returns: void
- Parameters: a0: folder
- Kind: normal
- Status: implemented
- Evaluator: function_1a4ab8 (68 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6ed940(a0); then returns nothing (void). function_6ed940 (281 bytes): returns early when a0 == -1; uses thread-local fields +0xd0 (performance); touches data at 0xc1a230; calls function_124a90, function_6ead28.
- Evidence: V

### thespian_performance_activate
- Slot: 595 (table entry 0xa1d800)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a4afc (213 bytes)
- Behavior: Evaluates 1 argument (a name id). Does nothing when a0 is 0 or -1. Otherwise it walks the performance table (count dword at scenario +0x7e8; 0x60-byte entries at +0x7ec) for the first entry whose dword +0 equals a0, builds the request {entry index, 1 as a 16-bit value} and calls function_6ea6c8; when that returns false it calls function_6ea9d0 with the same request. Returns nothing.
- Evidence: V

### thespian_performance_setup_and_begin
- Slot: 596 (table entry 0xa1d7b0)
- Returns: boolean
- Parameters: a0: string_id, a1: string_id, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a4bd4 (88 bytes)
- Behavior: Evaluates 3 argument(s). When all arguments are available it calls function_6eda5c(a0, a1) and float in xmm2=a2 (float); then returns the low 8 bits of the result of function_6eda5c. function_6eda5c (503 bytes): accesses ai globals (thread-local +0x30 block/header): reads +0x1 byte | performance (thread-local +0xd0 x0x188): reads +0x1a 16-bit; touches data at 0x98faf8; calls function_6edc54, function_6e8724, function_6ae164, function_6ae194, function_6eeb84, function_6ea558, function_6e87bc, function_6eb404 and 2 more.
- Evidence: V

### performance_new
- Slot: 597 (table entry 0xa1d8f0)
- Returns: long
- Parameters: a0: string_id, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a4c2c (71 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_6edc54(a0, a1 (8-bit)); then returns the low 32 bits of the result of function_6edc54. function_6edc54 (316 bytes): accesses performance (thread-local +0xd0 x0x188): writes +0x186 16-bit; touches data at 0xc1a230; calls function_6ead28, function_124a90, function_6ea9d0.
- Evidence: V

### cast_squad_in_performance
- Slot: 598 (table entry 0xa1d8a0)
- Returns: void
- Parameters: a0: long, a1: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a4c74 (71 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_6edd90(a0, a1); then returns nothing (void). function_6edd90 (231 bytes): returns early when a0 == -1; uses thread-local fields +0xd0 (performance); calls function_6be174, function_6ea558, function_6be220, function_6e87bc, function_6bd7d4, function_6bd5e8.
- Evidence: V

### performance_begin
- Slot: 599 (table entry 0xa1d850)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1a4cbc (68 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6ede78(a0); then returns nothing (void). function_6ede78 (73 bytes): Starts a performance when it is not running yet: returns for handle -1; for the performance element (thread-local +0xd0, 0x188 bytes) it calls function_6eb4b8 only when the dword at +0xc equals -1.
- Evidence: V

### thespian_performance_kill_by_name
- Slot: 600 (table entry 0xa1d6c0)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a4d00 (68 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6edec4(a0); then returns nothing (void). function_6edec4 (190 bytes): uses thread-local fields +0xd0 (performance); calls function_124a90, function_6e8510.
- Evidence: V

### thespian_performance_kill_by_ai
- Slot: 601 (table entry 0xa1d670)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a4d44 (68 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6edf84(); then returns nothing (void). function_6edf84 (217 bytes): uses thread-local fields +0xd0 (performance); calls function_6be174, function_6be220, function_6eb07c, function_124a90.
- Evidence: V

### thespian_fake_task_transition
- Slot: 602 (table entry 0xa1d620)
- Returns: void
- Parameters: a0: string_id, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a4d88 (71 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_6ee060(a0, a1); then returns nothing (void). function_6ee060 (377 bytes): uses thread-local fields +0xd0 (performance), +0x60 (command scripts); touches data at 0xb81974; calls function_124a90, function_6e8510, function_6e8ce4, function_6b02c8, function_6b2878.
- Evidence: V

### performance_play_line_by_id
- Slot: 603 (table entry 0xa1d760)
- Returns: void
- Parameters: a0: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a4dd0 (71 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6ee288(the script thread handle, a0 (16-bit)); then returns nothing (void). function_6ee288 (494 bytes): accesses performance (thread-local +0xd0 x0x188): reads +0xc 32-bit; writes +0x18 16-bit, +0x184 16-bit | random math (thread-local +0x658 block/header): reads +0x0 32-bit; writes +0x0 32-bit | game time globals (T) (thread-local +0xa0 block/header): reads +0xc 32-bit; calls function_6e9814, function_5cc74, function_6e99cc, function_6eb0dc, function_6eb660.
- Evidence: V

### performance_play_line
- Slot: 604 (table entry 0xa1d710)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a4e18 (70 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6ee1dc(the script thread handle, a0); then returns nothing (void). function_6ee1dc (170 bytes): uses thread-local fields +0xd0 (performance); calls function_6e974c, function_6e9814, function_6ee288.
- Evidence: V

### performance_get_actor_by_index
- Slot: 605 (table entry 0xa1d510)
- Returns: ai
- Parameters: a0: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a4e60 (110 bytes)
- Behavior: Evaluates 1 argument (a 16-bit index). Reads the performance handle at +0x28 of the running thread record; when it is not -1 it calls function_6ee478(handle, index) and, when that is not -1, returns (result & 0x1fffffff) | 0x60000000, an actor-kind AI reference. Otherwise returns 0.
- Evidence: V

### performance_get_actor
- Slot: 606 (table entry 0xa1d4c0)
- Returns: ai
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a4ed0 (82 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_85754(the script thread handle); then calls function_6ee4cc(the 32-bit value at +0x28 of the running thread record, a0); then returns the low 32 bits of the result of function_6ee4cc. function_6ee4cc (192 bytes): accesses performance (thread-local +0xd0 x0x188): reads +0x1a 16-bit; calls function_6e8ce4.
- Evidence: V

### performance_get_actor_count
- Slot: 607 (table entry 0xa1d480)
- Returns: short
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1a4f24 (101 bytes)
- Behavior: Takes no argument. Returns the 16-bit word at +0x1a of the 0x188-byte performance element (thread-local +0xd0) named by the performance handle at +0x28 of the running thread record; 0 when the handle is -1.
- Evidence: V

### performance_get_role_count
- Slot: 608 (table entry 0xa1d5e0)
- Returns: short
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1a4f8c (112 bytes)
- Behavior: Takes no argument. Reads the performance handle at +0x28 of the running thread record; when it is not -1 it calls function_6e87bc with the address of the 0x188-byte performance element (thread-local +0xd0) plus 4 and returns the low 16 bits of the result; otherwise returns 0.
- Evidence: V

### performance_get_line_count
- Slot: 609 (table entry 0xa1d5a0)
- Returns: short
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1a4ffc (111 bytes)
- Behavior: Takes no argument. Reads the performance handle at +0x28 of the running thread record; when it is not -1 it calls function_6e974c with the address of the 0x188-byte performance element (thread-local +0xd0) plus 4 and returns the low 16 bits of the result; otherwise returns 0.
- Evidence: V

### performance_get_last_played_line_index
- Slot: 610 (table entry 0xa1d560)
- Returns: short
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1a506c (102 bytes)
- Behavior: Takes no argument. Returns the 16-bit word at +0x18 of the 0x188-byte performance element (thread-local +0xd0) named by the performance handle at +0x28 of the running thread record; -1 when the handle is -1.
- Evidence: V

### thespian_performance_is_blocked
- Slot: 611 (table entry 0xa1d300)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1a50d4 (60 bytes)
- Behavior: Takes no argument. Returns false when the performance handle at +0x28 of the running thread record is -1, otherwise the byte result of function_6ea8cc(handle).
- Evidence: V

### actor_from_performance
- Slot: 612 (table entry 0xa1d2b0)
- Returns: ai
- Parameters: a0: long, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a5110 (71 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_6ee4cc(a0, a1); then returns the low 32 bits of the result of function_6ee4cc. function_6ee4cc (192 bytes): accesses performance (thread-local +0xd0 x0x188): reads +0x1a 16-bit; calls function_6e8ce4.
- Evidence: V

### ai_player_add_fireteam_squad
- Slot: 613 (table entry 0xa1d260)
- Returns: void
- Parameters: a0: unit, a1: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a5158 (71 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_1246bc(a0, a1); then returns nothing (void). function_1246bc (247 bytes): Adds the squad given by the second argument to the fire team of the unit in the first argument: returns when the unit handle is -1 or the unit record (+0x1cc) has no fire team; for a squad reference of kind 1 (top 3 bits) it looks up the squad with function_68c518, creates a fire team when the squad has none (function_1238c8, function_123d04) and adds it with function_123a24; other reference kinds are expanded through function_6bd5e8 first; returns early when a0 == -1.
- Evidence: V

### ai_player_remove_fireteam_squad
- Slot: 614 (table entry 0xa1d430)
- Returns: void
- Parameters: a0: unit, a1: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a51a0 (71 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_1247b4(a0, a1); then returns nothing (void). function_1247b4 (355 bytes): Removes the squad given by the second argument from the fire team of the unit in the first argument: returns when the unit handle is -1 or the unit has no fire team (+0x1cc); for a kind 1 squad reference it looks up the squad (function_68c518), checks it belongs to that team (function_69cb18), clears its team members (function_123e00 over the 0x3c-byte entries of thread-local +0x1c0) and deletes the fire team element (thread-local +0x128, 0xd4 bytes) with function_136f0.
- Evidence: V

### ai_player_set_fireteam_max
- Slot: 615 (table entry 0xa1d3e0)
- Returns: void
- Parameters: a0: unit, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a51e8 (105 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it if a1 (16-bit) >= 0 then calls function_124918(a0); then stores a1 (16-bit) to the record returned by function_124918 at +0xa; then returns nothing (void). When a1 (16-bit) < 0 the remaining steps are skipped. function_124918 (128 bytes): Returns the fire team element (thread-local +0x128, 0xd4 bytes per element) of the unit in the first argument: reads the fire team reference at +0x1cc of the unit record, resolves it with function_68c518 to a squad and takes the index at squad +0x20; returns null for handle -1 or when none exists; returns early when a0 == -1.
- Evidence: V

### ai_player_set_fireteam_no_max
- Slot: 616 (table entry 0xa1d390)
- Returns: void
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_1a5254 (82 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_124918(a0); then stores 8 to the record returned by function_124918 at +0xa; then returns nothing (void). function_124918 (128 bytes): Returns the fire team element (thread-local +0x128, 0xd4 bytes per element) of the unit in the first argument: reads the fire team reference at +0x1cc of the unit record, resolves it with function_68c518 to a squad and takes the index at squad +0x20; returns null for handle -1 or when none exists; returns early when a0 == -1.
- Evidence: V

### ai_player_set_fireteam_max_squad_absorb_distance
- Slot: 617 (table entry 0xa1d340)
- Returns: void
- Parameters: a0: unit, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a52a8 (92 bytes)
- Behavior: Evaluates 2 arguments (a unit and a real). When a1 is greater than 0.0 it finds the fire team element of the unit with function_124918 and, when it exists, stores a1 as the float at +0x24 of that element. Returns nothing.
- Evidence: V

### ai_set_fireteam_absorber
- Slot: 618 (table entry 0xa1d120)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a5304 (71 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_6bf31c(a0, a1 (8-bit)); then returns nothing (void). function_6bf31c (263 bytes): returns early when a0 == -1; accesses ai globals (thread-local +0x30 block/header): reads +0x1 byte | squad (thread-local +0x40 x0xec): reads +0x2 16-bit; writes +0x2 16-bit; calls function_6bdea0, function_6be080, function_6bd5e8.
- Evidence: V

### ai_set_fireteam_fallback_squad
- Slot: 619 (table entry 0xa1d0d0)
- Returns: void
- Parameters: a0: unit, a1: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a534c (167 bytes)
- Behavior: Evaluates 2 arguments (a unit and an ai reference). Finds the fire team element of the unit with function_124918; when it exists and a1 is a squad reference (mask 0xe0000000 equals 0x20000000) it stores the low 16 bits of a1 in the dword at +0xc of that element; for any other kind of reference it calls function_6bd5e8(a1, local buffer) and discards the result. Returns nothing.
- Evidence: V

### ai_is_in_fireteam
- Slot: 620 (table entry 0xa1d080)
- Returns: boolean
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a53f4 (80 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_124998(a0); then returns the low 8 bits of the result of function_124998. function_124998 (247 bytes): Returns true when the AI reference is in a fire team: for a kind 1 reference (top 3 bits) it tests squad dword +0xb0 != -1 (squad array thread-local +0x40, 0xec bytes); for kind 3 it resolves the actor with function_6bd7d4, takes the squad reference at actor +0x3c (actor array thread-local +0x8, 0xd00 bytes) and tests the same field; other kinds are expanded with function_6bd5e8 and give false.
- Evidence: V

### cs_run_command_script
- Slot: 621 (table entry 0xa1d210)
- Returns: void
- Parameters: a0: ai, a1: ai_command_script
- Kind: normal
- Status: implemented
- Evaluator: function_1a5444 (161 bytes)
- Behavior: Evaluates 2 arguments (an ai reference and a command script). The script index is the low 16 bits of a1; when it is not -1 (compared as 16 bits), for each actor of a0 it calls function_6b06f4(actor, script index, -1). Returns nothing.
- Evidence: V

### cs_queue_command_script
- Slot: 622 (table entry 0xa1d1c0)
- Returns: void
- Parameters: a0: ai, a1: ai_command_script
- Kind: normal
- Status: implemented
- Evaluator: function_1a54e8 (161 bytes)
- Behavior: Evaluates 2 arguments (an ai reference and a command script). The script index is the low 16 bits of a1; when it is not -1 (compared as 16 bits), for each actor of a0 it calls function_6b08c0(actor, script index, -1). Returns nothing.
- Evidence: V

### cs_stack_command_script
- Slot: 623 (table entry 0xa1d170)
- Returns: void
- Parameters: a0: ai, a1: ai_command_script
- Kind: normal
- Status: implemented
- Evaluator: function_1a558c (161 bytes)
- Behavior: Evaluates 2 arguments (an ai reference and a command script). The script index is the low 16 bits of a1; when it is not -1 (compared as 16 bits), for each actor of a0 it calls function_6b0808(actor, script index, -1). Returns nothing.
- Evidence: V

### vs_cast (slot 624)
- Slot: 624 (table entry 0xa1cf40)
- Returns: boolean
- Parameters: a0: ai, a1: boolean, a2: short, a3: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a5630 (112 bytes)
- Behavior: Evaluates the arguments (an ai reference a0, a byte a1, a 16-bit value a2 and 1 string id read from slot 3 on) and calls function_6b13c4(script thread handle, a0, a1, a2, pointer to the 1 string id, a count of 1 stored as a 16-bit value in the call frame). Returns the low byte of the result of function_6b13c4 as the boolean result.
- Evidence: V

### vs_cast (slot 625)
- Slot: 625 (table entry 0xa1cef0)
- Returns: boolean
- Parameters: a0: ai, a1: boolean, a2: short, a3: string_id, a4: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a56a0 (123 bytes)
- Behavior: Evaluates the arguments (an ai reference a0, a byte a1, a 16-bit value a2 and 2 string ids read from slot 3 on) and calls function_6b13c4(script thread handle, a0, a1, a2, pointer to the 2 string ids, a count of 2 stored as a 16-bit value in the call frame). Returns the low byte of the result of function_6b13c4 as the boolean result.
- Evidence: V

### vs_cast (slot 626)
- Slot: 626 (table entry 0xa1d030)
- Returns: boolean
- Parameters: a0: ai, a1: boolean, a2: short, a3: string_id, a4: string_id, a5: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a571c (159 bytes)
- Behavior: Evaluates the arguments (an ai reference a0, a byte a1, a 16-bit value a2 and 3 string ids read from slot 3 on) and calls function_6b13c4(script thread handle, a0, a1, a2, pointer to the 3 string ids, a count of 3 stored as a 16-bit value in the call frame). Returns the low byte of the result of function_6b13c4 as the boolean result.
- Evidence: V

### vs_cast (slot 627)
- Slot: 627 (table entry 0xa1cfe0)
- Returns: boolean
- Parameters: a0: ai, a1: boolean, a2: short, a3: string_id, a4: string_id, a5: string_id, a6: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a57bc (142 bytes)
- Behavior: Evaluates the arguments (an ai reference a0, a byte a1, a 16-bit value a2 and 4 string ids read from slot 3 on) and calls function_6b13c4(script thread handle, a0, a1, a2, pointer to the 4 string ids, a count of 4 stored as a 16-bit value in the call frame). Returns the low byte of the result of function_6b13c4 as the boolean result.
- Evidence: V

### vs_cast (slot 628)
- Slot: 628 (table entry 0xa1cf90)
- Returns: boolean
- Parameters: a0: ai, a1: boolean, a2: short, a3: string_id, a4: string_id, a5: string_id, a6: string_id, a7: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a584c (173 bytes)
- Behavior: Evaluates the arguments (an ai reference a0, a byte a1, a 16-bit value a2 and 5 string ids read from slot 3 on) and calls function_6b13c4(script thread handle, a0, a1, a2, pointer to the 5 string ids, a count of 5 stored as a 16-bit value in the call frame). Returns the low byte of the result of function_6b13c4 as the boolean result.
- Evidence: V

### vs_cast (slot 629)
- Slot: 629 (table entry 0xa1cdf0)
- Returns: boolean
- Parameters: a0: ai, a1: boolean, a2: short, a3: string_id, a4: string_id, a5: string_id, a6: string_id, a7: string_id, a8: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a58fc (178 bytes)
- Behavior: Evaluates the arguments (an ai reference a0, a byte a1, a 16-bit value a2 and 6 string ids read from slot 3 on) and calls function_6b13c4(script thread handle, a0, a1, a2, pointer to the 6 string ids, a count of 6 stored as a 16-bit value in the call frame). Returns the low byte of the result of function_6b13c4 as the boolean result.
- Evidence: V

### vs_cast (slot 630)
- Slot: 630 (table entry 0xa1cd90)
- Returns: boolean
- Parameters: a0: ai, a1: boolean, a2: short, a3: string_id, a4: string_id, a5: string_id, a6: string_id, a7: string_id, a8: string_id, a9: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a59b0 (185 bytes)
- Behavior: Evaluates the arguments (an ai reference a0, a byte a1, a 16-bit value a2 and 7 string ids read from slot 3 on) and calls function_6b13c4(script thread handle, a0, a1, a2, pointer to the 7 string ids, a count of 7 stored as a 16-bit value in the call frame). Returns the low byte of the result of function_6b13c4 as the boolean result.
- Evidence: V

### vs_role
- Slot: 631 (table entry 0xa1cd40)
- Returns: ai
- Parameters: a0: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a5a6c (180 bytes)
- Behavior: Evaluates 1 argument (a role number, read as a signed 16-bit value). When a0 is positive it iterates the command script array (thread-local +0x60) with function_1381c and stops at the first element whose dword +0xc equals the running script thread handle and whose word +0x1e equals a0; the result is (dword +4 of that element & 0x1fffffff) | 0x60000000, an actor-kind AI reference. Returns 0 when a0 is not positive or nothing matches.
- Evidence: V

### cs_abort_on_alert (slot 632)
- Slot: 632 (table entry 0xa1cea0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a5b20 (98 bytes)
- Behavior: Evaluates 1 argument. Sets bit 1 (0x02) of the byte at +0x22 of the running thread record when a0 is non-zero and clears it when a0 is zero. Returns nothing.
- Evidence: V

### cs_abort_on_damage (slot 633)
- Slot: 633 (table entry 0xa1ce50)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a5b84 (98 bytes)
- Behavior: Evaluates 1 argument. Sets bit 0 (0x01) of the byte at +0x22 of the running thread record when a0 is non-zero and clears it when a0 is zero. Returns nothing.
- Evidence: V

### cs_abort_on_combat_status (slot 634)
- Slot: 634 (table entry 0xa1cc00)
- Returns: void
- Parameters: a0: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a5be8 (80 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_85754(the script thread handle); then applies or with 4 to the running thread record at +0x22; then stores a0 (16-bit) to the running thread record at +0x23; then returns nothing (void).
- Evidence: V

### cs_abort_on_vehicle_exit (slot 635)
- Slot: 635 (table entry 0xa1cbb0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a5c38 (98 bytes)
- Behavior: Evaluates 1 argument. Sets bit 3 (0x08) of the byte at +0x22 of the running thread record when a0 is non-zero and clears it when a0 is zero. Returns nothing.
- Evidence: V

### cs_abort_on_alert (slot 636)
- Slot: 636 (table entry 0xa1ccf0)
- Returns: void
- Parameters: a0: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a5c9c (264 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (8-bit) to field +0x17 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x17 byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found
  and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_abort_on_alert (slot 637)
- Slot: 637 (table entry 0xa1cca0)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a5c9c (264 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a1 (8-bit) to field +0x17 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x17 byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero
  it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_abort_on_damage (slot 638)
- Slot: 638 (table entry 0xa1cc50)
- Returns: void
- Parameters: a0: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a5da4 (264 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (8-bit) to field +0x18 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x18 byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found
  and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_abort_on_damage (slot 639)
- Slot: 639 (table entry 0xa1ca70)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a5da4 (264 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a1 (8-bit) to field +0x18 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x18 byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero
  it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_abort_on_combat_status (slot 640)
- Slot: 640 (table entry 0xa1ca20)
- Returns: void
- Parameters: a0: short
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a5eac (270 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores 1 to field +0x19 of the command scripts element (thread-local +0x60 x0x1ec); then stores a0 (16-bit) to field +0x1a of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x19 byte, +0x1a 16-bit. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements
  (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_abort_on_combat_status (slot 641)
- Slot: 641 (table entry 0xa1c9d0)
- Returns: void
- Parameters: a0: ai, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a5eac (270 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores 1 to field +0x19 of the command scripts element (thread-local +0x60 x0x1ec); then stores a1 (16-bit) to field +0x1a of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x19 byte, +0x1a 16-bit. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking
  for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_abort_on_vehicle_exit (slot 642)
- Slot: 642 (table entry 0xa1cb60)
- Returns: void
- Parameters: a0: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a5fbc (264 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (8-bit) to field +0x1c of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1c byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found
  and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_abort_on_vehicle_exit (slot 643)
- Slot: 643 (table entry 0xa1cb10)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a5fbc (264 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a1 (8-bit) to field +0x1c of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1c byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero
  it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_command_script_running
- Slot: 644 (table entry 0xa1cac0)
- Returns: boolean
- Parameters: a0: ai, a1: ai_command_script
- Kind: normal
- Status: implemented
- Evaluator: function_1a60c4 (84 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_6c2980(a0, a1 (signed 16-bit)); then returns the low 8 bits of the result of function_6c2980. function_6c2980 (193 bytes): accesses command scripts (thread-local +0x60 x0x1ec): reads +0x8 32-bit; calls function_6be174, function_6be220.
- Evidence: V

### cs_command_script_attached
- Slot: 645 (table entry 0xa1c890)
- Returns: boolean
- Parameters: a0: ai, a1: ai_command_script
- Kind: normal
- Status: implemented
- Evaluator: function_1a6118 (84 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_6c2a44(a0, a1 (signed 16-bit)); then returns the low 8 bits of the result of function_6c2a44. function_6c2a44 (204 bytes): accesses command scripts (thread-local +0x60 x0x1ec): reads +0x8 32-bit, +0x10 32-bit; calls function_6be174, function_6be220.
- Evidence: V

### cs_number_queued
- Slot: 646 (table entry 0xa1c840)
- Returns: short
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a616c (218 bytes)
- Behavior: Evaluates 1 argument. Returns the number of command script elements queued on an actor: a0 must be a reference of kind 3 or 4 (top 3 bits); it is resolved with function_6bd848 to an actor handle (-1 gives 0); the list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes) and the elements (thread-local +0x60, 0x1ec bytes) are followed through the dword at +0x10 until -1. The result is a 16-bit count; other references give 0.
- Evidence: V

### cs_moving (slot 647)
- Slot: 647 (table entry 0xa1c800)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1a6248 (179 bytes)
- Behavior: Evaluates 0 argument(s). Iterates the actors of the 32-bit value at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_717eb0(the current actor). It then returns result of function_717eb0 (low 8 bits). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears
  its byte +0x14; returns the element handle or -1. function_717eb0 (79 bytes): Returns true when the actor (thread-local +0x8, 0xd00 bytes) has byte +0x864 non-zero and word +0x85c equal to 1.
- Evidence: V

### cs_moving (slot 648)
- Slot: 648 (table entry 0xa1c980)
- Returns: boolean
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a6248 (179 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the 32-bit value at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_717eb0(the current actor). It then returns result of function_717eb0 (low 8 bits). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears
  its byte +0x14; returns the element handle or -1. function_717eb0 (79 bytes): Returns true when the actor (thread-local +0x8, 0xd00 bytes) has byte +0x864 non-zero and word +0x85c equal to 1.
- Evidence: V

### cs_fly_to (slot 649)
- Slot: 649 (table entry 0xa1c930)
- Returns: void
- Parameters: a0: point_reference
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a62fc (261 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0x12, 1); then clears the record returned by function_6b0648 at +0x4; then stores a0 to the record returned by function_6b0648 at +0x24; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the
  command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_fly_to (slot 650)
- Slot: 650 (table entry 0xa1c8e0)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_1a62fc (261 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0x12, 1); then clears the record returned by function_6b0648 at +0x4; then stores a2 to the record returned by function_6b0648 at +0x24; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements
  (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_fly_to (slot 651)
- Slot: 651 (table entry 0xa1c6c0)
- Returns: void
- Parameters: a0: point_reference, a1: real
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a6404 (301 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0x12, 1); then stores a1 (float) to the record returned by function_6b0648 at +0x4; then stores a0 to the record returned by function_6b0648 at +0x24; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field
  +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_fly_to (slot 652)
- Slot: 652 (table entry 0xa1c670)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: point_reference, a3: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a6404 (301 bytes)
- Behavior: Evaluates 4 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0x12, 1); then stores a3 (float) to the record returned by function_6b0648 at +0x4; then stores a2 to the record returned by function_6b0648 at +0x24; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script
  elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_fly_to_and_face (slot 653)
- Slot: 653 (table entry 0xa1c620)
- Returns: void
- Parameters: a0: point_reference, a1: point_reference
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a6534 (297 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0x14, 1); then clears the record returned by function_6b0648 at +0x4; then stores a0 to the record returned by function_6b0648 at +0x24; then stores a1 to the record returned by function_6b0648 at +0x28; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8,
  0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_fly_to_and_face (slot 654)
- Slot: 654 (table entry 0xa1c5d0)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: point_reference, a3: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_1a6534 (297 bytes)
- Behavior: Evaluates 4 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0x14, 1); then clears the record returned by function_6b0648 at +0x4; then stores a2 to the record returned by function_6b0648 at +0x24; then stores a3 to the record returned by function_6b0648 at +0x28; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked
  through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_fly_to_and_face (slot 655)
- Slot: 655 (table entry 0xa1c7b0)
- Returns: void
- Parameters: a0: point_reference, a1: point_reference, a2: real
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a6660 (343 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0x14, 1); then stores a2 (float) to the record returned by function_6b0648 at +0x4; then stores a0 to the record returned by function_6b0648 at +0x24; then stores a1 to the record returned by function_6b0648 at +0x28; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array
  thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_fly_to_and_face (slot 656)
- Slot: 656 (table entry 0xa1c760)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: point_reference, a3: point_reference, a4: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a6660 (343 bytes)
- Behavior: Evaluates 5 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0x14, 1); then stores a4 (float) to the record returned by function_6b0648 at +0x4; then stores a2 to the record returned by function_6b0648 at +0x24; then stores a3 to the record returned by function_6b0648 at +0x28; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list
  is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_fly_by (slot 657)
- Slot: 657 (table entry 0xa1c710)
- Returns: void
- Parameters: a0: point_reference
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a67b8 (261 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0x13, 1); then clears the record returned by function_6b0648 at +0x4; then stores a0 to the record returned by function_6b0648 at +0x24; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the
  command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_fly_by (slot 658)
- Slot: 658 (table entry 0xa1c490)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_1a67b8 (261 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0x13, 1); then clears the record returned by function_6b0648 at +0x4; then stores a2 to the record returned by function_6b0648 at +0x24; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements
  (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_fly_by (slot 659)
- Slot: 659 (table entry 0xa1c440)
- Returns: void
- Parameters: a0: point_reference, a1: real
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a68c0 (301 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0x13, 1); then stores a1 (float) to the record returned by function_6b0648 at +0x4; then stores a0 to the record returned by function_6b0648 at +0x24; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field
  +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_fly_by (slot 660)
- Slot: 660 (table entry 0xa1c3f0)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: point_reference, a3: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a68c0 (301 bytes)
- Behavior: Evaluates 4 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0x13, 1); then stores a3 (float) to the record returned by function_6b0648 at +0x4; then stores a2 to the record returned by function_6b0648 at +0x24; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script
  elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_go_to (slot 661)
- Slot: 661 (table entry 0xa1c580)
- Returns: void
- Parameters: a0: point_reference
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a69f0 (261 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 1, 1); then clears the record returned by function_6b0648 at +0x4; then stores a0 to the record returned by function_6b0648 at +0x24; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the
  command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_go_to (slot 662)
- Slot: 662 (table entry 0xa1c530)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_1a69f0 (261 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 1, 1); then clears the record returned by function_6b0648 at +0x4; then stores a2 to the record returned by function_6b0648 at +0x24; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local
  +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_go_to (slot 663)
- Slot: 663 (table entry 0xa1c4e0)
- Returns: void
- Parameters: a0: point_reference, a1: real
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a6af8 (301 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 1, 1); then stores a1 (float) to the record returned by function_6b0648 at +0x4; then stores a0 to the record returned by function_6b0648 at +0x24; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field
  +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_go_to (slot 664)
- Slot: 664 (table entry 0xa1c260)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: point_reference, a3: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a6af8 (301 bytes)
- Behavior: Evaluates 4 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 1, 1); then stores a3 (float) to the record returned by function_6b0648 at +0x4; then stores a2 to the record returned by function_6b0648 at +0x24; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements
  (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_go_by (slot 665)
- Slot: 665 (table entry 0xa1c210)
- Returns: void
- Parameters: a0: point_reference, a1: point_reference
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a6c28 (297 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 2, 1); then clears the record returned by function_6b0648 at +0x4; then stores a0 to the record returned by function_6b0648 at +0x24; then stores a1 to the record returned by function_6b0648 at +0x28; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00
  bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_go_by (slot 666)
- Slot: 666 (table entry 0xa1c1c0)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: point_reference, a3: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_1a6c28 (297 bytes)
- Behavior: Evaluates 4 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 2, 1); then clears the record returned by function_6b0648 at +0x4; then stores a2 to the record returned by function_6b0648 at +0x24; then stores a3 to the record returned by function_6b0648 at +0x28; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through
  the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_go_by (slot 667)
- Slot: 667 (table entry 0xa1c3a0)
- Returns: void
- Parameters: a0: point_reference, a1: point_reference, a2: real
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a6d54 (343 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 2, 1); then stores a2 (float) to the record returned by function_6b0648 at +0x4; then stores a0 to the record returned by function_6b0648 at +0x24; then stores a1 to the record returned by function_6b0648 at +0x28; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array
  thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_go_by (slot 668)
- Slot: 668 (table entry 0xa1c350)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: point_reference, a3: point_reference, a4: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a6d54 (343 bytes)
- Behavior: Evaluates 5 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 2, 1); then stores a4 (float) to the record returned by function_6b0648 at +0x4; then stores a2 to the record returned by function_6b0648 at +0x24; then stores a3 to the record returned by function_6b0648 at +0x28; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is
  walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_go_to_and_face (slot 669)
- Slot: 669 (table entry 0xa1c300)
- Returns: void
- Parameters: a0: point_reference, a1: point_reference
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a6eac (293 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 3, 1); then stores a0 to the record returned by function_6b0648 at +0x24; then stores a1 to the record returned by function_6b0648 at +0x28; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of
  the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_go_to_and_face (slot 670)
- Slot: 670 (table entry 0xa1c2b0)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: point_reference, a3: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_1a6eac (293 bytes)
- Behavior: Evaluates 4 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 3, 1); then stores a2 to the record returned by function_6b0648 at +0x24; then stores a3 to the record returned by function_6b0648 at +0x28; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements
  (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_go_to_and_posture (slot 671)
- Slot: 671 (table entry 0xa1c080)
- Returns: void
- Parameters: a0: point_reference, a1: string_id
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a6fd4 (293 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 4, 1); then stores a0 to the record returned by function_6b0648 at +0x24; then stores a1 to the record returned by function_6b0648 at +0x28; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of
  the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_go_to_and_posture (slot 672)
- Slot: 672 (table entry 0xa1c030)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: point_reference, a3: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a6fd4 (293 bytes)
- Behavior: Evaluates 4 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 4, 1); then stores a2 to the record returned by function_6b0648 at +0x24; then stores a3 to the record returned by function_6b0648 at +0x28; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements
  (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_attach_to_spline (slot 673)
- Slot: 673 (table entry 0xa1bfe0)
- Returns: void
- Parameters: a0: string_id
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a70fc (516 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores (lo32(left(6b02c8)) | 4294967295) to field +0x1e8 of the command scripts element (thread-local +0x60 x0x1ec); then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). Inline state access: actor (thread-local +0x8 x0xd00): reads +0x345 byte, +0x3d8 32-bit | command scripts (thread-local +0x60 x0x1ec): writes +0x1e8 32-bit. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array
  thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_attach_to_spline (slot 674)
- Slot: 674 (table entry 0xa1c170)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a70fc (516 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores (lo32(left(6b02c8)) | 4294967295) to field +0x1e8 of the command scripts element (thread-local +0x60 x0x1ec); then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). Inline state access: actor (thread-local +0x8 x0xd00): reads +0x345 byte, +0x3d8 32-bit | command scripts (thread-local +0x60 x0x1ec): writes +0x1e8 32-bit. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array
  thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_go_to_nearest (slot 675)
- Slot: 675 (table entry 0xa1c120)
- Returns: void
- Parameters: a0: point_reference
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a7300 (723 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is forced to 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 the wait flag and the remaining arguments start at slot 2. For each actor of the AI reference it finds or creates the actor command script element with function_6b02c8(actor, script thread handle, 1); when the element exists and the actor handle is not -1 and the point reference passes function_6b2950, it takes the point set index from the high 16 bits of the point reference, checks it is below the scenario point set count (dword at +0x460) and, over the points of that set (dword +0x20 gives the count; 64-byte point records), calls function_710fac(point, actor +0x398) to get a
  distance and keeps the smallest. When a point was found it creates a command slot with function_6b0648(element, 1, 1) and stores the chosen point reference (set index << 16 | point index) at +0x24 and 0 at +4 of that slot. When the wait flag is set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_go_to_nearest (slot 676)
- Slot: 676 (table entry 0xa1c0d0)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_1a7300 (723 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is forced to 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 the wait flag and the remaining arguments start at slot 2. For each actor of the AI reference it finds or creates the actor command script element with function_6b02c8(actor, script thread handle, 1); when the element exists and the actor handle is not -1 and the point reference passes function_6b2950, it takes the point set index from the high 16 bits of the point reference, checks it is below the scenario point set count (dword at +0x460) and, over the points of that set (dword +0x20 gives the count; 64-byte point records), calls function_710fac(point, actor +0x398) to get a
  distance and keeps the smallest. When a point was found it creates a command slot with function_6b0648(element, 1, 1) and stores the chosen point reference (set index << 16 | point index) at +0x24 and 0 at +4 of that slot. When the wait flag is set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_move_in_direction (slot 677)
- Slot: 677 (table entry 0xa1bea0)
- Returns: void
- Parameters: a0: real, a1: real, a2: real
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a75d4 (517 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the 32-bit value at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 5, 1); then applies or with 0xffffffff to the record returned by function_6b0648 at +0x24; then stores a1 (float) to the record returned by function_6b0648 at +0x4; then stores a0 (float) to the record returned by function_6b0648 at +0x8; then stores 0 to the record returned by function_6b0648 at +0x2; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the
  first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_move_in_direction (slot 678)
- Slot: 678 (table entry 0xa1be50)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: real, a3: real, a4: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a75d4 (517 bytes)
- Behavior: Evaluates 5 argument(s). Iterates the actors of the 32-bit value at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 5, 1); then applies or with 0xffffffff to the record returned by function_6b0648 at +0x24; then stores a1 (float) to the record returned by function_6b0648 at +0x4; then stores a0 (float) to the record returned by function_6b0648 at +0x8; then stores 0 to the record returned by function_6b0648 at +0x2; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the
  first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_move_towards (slot 679)
- Slot: 679 (table entry 0xa1be00)
- Returns: void
- Parameters: a0: object
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a77dc (261 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 6, 1); then stores a0 to the record returned by function_6b0648 at +0x24; then stores 0 to the record returned by function_6b0648 at +0x8; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of
  the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_move_towards (slot 680)
- Slot: 680 (table entry 0xa1bf90)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: object
- Kind: normal
- Status: implemented
- Evaluator: function_1a77dc (261 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 6, 1); then stores a2 to the record returned by function_6b0648 at +0x24; then stores 0 to the record returned by function_6b0648 at +0x8; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements
  (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_move_towards (slot 681)
- Slot: 681 (table entry 0xa1bf40)
- Returns: void
- Parameters: a0: object, a1: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a78e4 (294 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 6, 1); then stores a0 to the record returned by function_6b0648 at +0x24; then stores a1 (8-bit) to the record returned by function_6b0648 at +0x8; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field
  +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_move_towards (slot 682)
- Slot: 682 (table entry 0xa1bef0)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: object, a3: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a78e4 (294 bytes)
- Behavior: Evaluates 4 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 6, 1); then stores a2 to the record returned by function_6b0648 at +0x24; then stores a3 (8-bit) to the record returned by function_6b0648 at +0x8; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements
  (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_move_towards_point (slot 683)
- Slot: 683 (table entry 0xa1bcc0)
- Returns: void
- Parameters: a0: point_reference, a1: real
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a7a0c (323 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b29cc(a0); then calls function_6b0648(result of function_6b02c8, 7, 1); then stores a1 (float) to the record returned by function_6b0648 at +0x4; then stores a0 to the record returned by function_6b0648 at +0x24; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is
  walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b29cc (143 bytes): touches data at 0xc1a230. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_move_towards_point (slot 684)
- Slot: 684 (table entry 0xa1bc70)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: point_reference, a3: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a7a0c (323 bytes)
- Behavior: Evaluates 4 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b29cc(a0); then calls function_6b0648(result of function_6b02c8, 7, 1); then stores a1 (float) to the record returned by function_6b0648 at +0x4; then stores a0 to the record returned by function_6b0648 at +0x24; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is
  walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b29cc (143 bytes): touches data at 0xc1a230. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_swarm_to (slot 685)
- Slot: 685 (table entry 0xa1bc20)
- Returns: void
- Parameters: a0: point_reference, a1: real
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a7b50 (323 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b29cc(a0); then calls function_6b0648(result of function_6b02c8, 0x1c, 1); then stores a1 (float) to the record returned by function_6b0648 at +0x4; then stores a0 to the record returned by function_6b0648 at +0x24; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list
  is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b29cc (143 bytes): touches data at 0xc1a230. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_swarm_to (slot 686)
- Slot: 686 (table entry 0xa1bbd0)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: point_reference, a3: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a7b50 (323 bytes)
- Behavior: Evaluates 4 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b29cc(a0); then calls function_6b0648(result of function_6b02c8, 0x1c, 1); then stores a1 (float) to the record returned by function_6b0648 at +0x4; then stores a0 to the record returned by function_6b0648 at +0x24; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list
  is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b29cc (143 bytes): touches data at 0xc1a230. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_swarm_from (slot 687)
- Slot: 687 (table entry 0xa1bdb0)
- Returns: void
- Parameters: a0: point_reference, a1: real
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a7c94 (323 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b2950(a0); then calls function_6b0648(result of function_6b02c8, 0x1d, 1); then stores a1 (float) to the record returned by function_6b0648 at +0x4; then stores a0 to the record returned by function_6b0648 at +0x24; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list
  is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b2950 (123 bytes): returns early when a0 == -1; touches data at 0xc1a230. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_swarm_from (slot 688)
- Slot: 688 (table entry 0xa1bd60)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: point_reference, a3: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a7c94 (323 bytes)
- Behavior: Evaluates 4 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b2950(a0); then calls function_6b0648(result of function_6b02c8, 0x1d, 1); then stores a1 (float) to the record returned by function_6b0648 at +0x4; then stores a0 to the record returned by function_6b0648 at +0x24; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list
  is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b2950 (123 bytes): returns early when a0 == -1; touches data at 0xc1a230. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_pause (slot 689)
- Slot: 689 (table entry 0xa1bd10)
- Returns: void
- Parameters: a0: real
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a7dd8 (294 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is forced to 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 the wait flag and the remaining arguments start at slot 2. For each actor of the AI reference it finds or creates the actor command script element with function_6b02c8(actor, script thread handle, 1); then creates a command slot of type 0 with function_6b0648(element, 0, 1) and stores the pause time at +4 of the slot as a float converted by function_5cc74 (seconds to a whole number of game ticks, using the tick rate word of the game time globals) and back to a float. When the wait flag is set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_pause (slot 690)
- Slot: 690 (table entry 0xa1ba90)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a7dd8 (294 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is forced to 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 the wait flag and the remaining arguments start at slot 2. For each actor of the AI reference it finds or creates the actor command script element with function_6b02c8(actor, script thread handle, 1); then creates a command slot of type 0 with function_6b0648(element, 0, 1) and stores the pause time at +4 of the slot as a float converted by function_5cc74 (seconds to a whole number of game ticks, using the tick rate word of the game time globals) and back to a float. When the wait flag is set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_grenade (slot 691)
- Slot: 691 (table entry 0xa1ba40)
- Returns: void
- Parameters: a0: point_reference, a1: short
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a7f00 (295 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 8, 1); then stores a0 to the record returned by function_6b0648 at +0x24; then stores a1 (16-bit) to the record returned by function_6b0648 at +0x2; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field
  +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_grenade (slot 692)
- Slot: 692 (table entry 0xa1b9f0)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: point_reference, a3: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a7f00 (295 bytes)
- Behavior: Evaluates 4 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 8, 1); then stores a2 to the record returned by function_6b0648 at +0x24; then stores a3 (16-bit) to the record returned by function_6b0648 at +0x2; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements
  (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_use_equipment (slot 693)
- Slot: 693 (table entry 0xa1bb80)
- Returns: void
- Parameters: a0: real
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a8028 (423 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 9, 1); then calls function_5cc74() and float in xmm0=a0 (float); then stores result of function_5cc74 to the record returned by function_6b0648 at +0x4; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). Inline state access: actor (thread-local +0x8 x0xd00): reads +0x1c 32-bit | object record: reads +0x374 32-bit. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is
  the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a. function_5cc74 (95 bytes): Float to integer conversion using the word at +6 of game time globals (thread-local +0xa0): returns 0 when byte +0 of that block is 0; otherwise multiplies the float argument by the signed word, adds a sign-dependent constant term and truncates to an integer.
- Evidence: V

### cs_use_equipment (slot 694)
- Slot: 694 (table entry 0xa1bb30)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a8028 (423 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 9, 1); then calls function_5cc74() and float in xmm0=a0 (float); then stores result of function_5cc74 to the record returned by function_6b0648 at +0x4; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). Inline state access: actor (thread-local +0x8 x0xd00): reads +0x1c 32-bit | object record: reads +0x374 32-bit. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is
  the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a. function_5cc74 (95 bytes): Float to integer conversion using the word at +6 of game time globals (thread-local +0xa0): returns 0 when byte +0 of that block is 0; otherwise multiplies the float argument by the signed word, adds a sign-dependent constant term and truncates to an integer.
- Evidence: V

### cs_jump (slot 695)
- Slot: 695 (table entry 0xa1bae0)
- Returns: void
- Parameters: a0: real, a1: real
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a81d0 (304 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0xb, 1); then stores a0 (float) to the record returned by function_6b0648 at +0x4; then stores a1 (float) to the record returned by function_6b0648 at +0x8; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link
  field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_jump (slot 696)
- Slot: 696 (table entry 0xa1b860)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: real, a3: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a81d0 (304 bytes)
- Behavior: Evaluates 4 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0xb, 1); then stores a2 (float) to the record returned by function_6b0648 at +0x4; then stores a3 (float) to the record returned by function_6b0648 at +0x8; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script
  elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_jump_to_point (slot 697)
- Slot: 697 (table entry 0xa1b810)
- Returns: void
- Parameters: a0: real, a1: real
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a8300 (304 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0xc, 1); then stores a0 (float) to the record returned by function_6b0648 at +0x4; then stores a1 (float) to the record returned by function_6b0648 at +0x8; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link
  field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_jump_to_point (slot 698)
- Slot: 698 (table entry 0xa1b7c0)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: real, a3: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a8300 (304 bytes)
- Behavior: Evaluates 4 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0xc, 1); then stores a2 (float) to the record returned by function_6b0648 at +0x4; then stores a3 (float) to the record returned by function_6b0648 at +0x8; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script
  elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_vocalize (slot 699)
- Slot: 699 (table entry 0xa1b9a0)
- Returns: void
- Parameters: a0: short
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a8430 (259 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0xf, 1); then stores a0 (16-bit) to the record returned by function_6b0648 at +0x2; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec
  bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_vocalize (slot 700)
- Slot: 700 (table entry 0xa1b950)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a8430 (259 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0xf, 1); then stores a2 (16-bit) to the record returned by function_6b0648 at +0x2; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword
  +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_play_sound (slot 701)
- Slot: 701 (table entry 0xa1b900)
- Returns: void
- Parameters: a0: sound
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a8534 (310 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is treated as 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 is the wait flag and the arguments start at slot 2. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); when the element exists and the actor handle is not -1 it calls function_70f5d4(actor, element, 1, the sound reference a (the first argument after the AI reference and wait flag) and two float constants of 1.0, 0 in the first stack slot). With the wait flag set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_play_sound (slot 702)
- Slot: 702 (table entry 0xa1b8b0)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: sound
- Kind: normal
- Status: implemented
- Evaluator: function_1a8534 (310 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is treated as 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 is the wait flag and the arguments start at slot 2. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); when the element exists and the actor handle is not -1 it calls function_70f5d4(actor, element, 1, the sound reference a (the first argument after the AI reference and wait flag) and two float constants of 1.0, 0 in the first stack slot). With the wait flag set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_play_sound (slot 703)
- Slot: 703 (table entry 0xa1b680)
- Returns: void
- Parameters: a0: sound, a1: real
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a866c (335 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is treated as 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 is the wait flag and the arguments start at slot 2. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); when the element exists and the actor handle is not -1 it calls function_70f5d4(actor, element, 1, the sound reference, then a real taken from the slot after it as the first float and a constant 1.0 as the second, 0 in the first stack slot). With the wait flag set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_play_sound (slot 704)
- Slot: 704 (table entry 0xa1b630)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: sound, a3: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a866c (335 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is treated as 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 is the wait flag and the arguments start at slot 2. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); when the element exists and the actor handle is not -1 it calls function_70f5d4(actor, element, 1, the sound reference, then a real taken from the slot after it as the first float and a constant 1.0 as the second, 0 in the first stack slot). With the wait flag set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_play_sound (slot 705)
- Slot: 705 (table entry 0xa1b5e0)
- Returns: void
- Parameters: a0: sound, a1: real, a2: real
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a87bc (327 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is treated as 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 is the wait flag and the arguments start at slot 2. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); when the element exists and the actor handle is not -1 it calls function_70f5d4(actor, element, 1, the sound reference, then the first real as the first float and the second real as the second float, 0 in the first stack slot). With the wait flag set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_play_sound (slot 706)
- Slot: 706 (table entry 0xa1b770)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: sound, a3: real, a4: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a87bc (327 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is treated as 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 is the wait flag and the arguments start at slot 2. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); when the element exists and the actor handle is not -1 it calls function_70f5d4(actor, element, 1, the sound reference, then the first real as the first float and the second real as the second float, 0 in the first stack slot). With the wait flag set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_action (slot 707)
- Slot: 707 (table entry 0xa1b720)
- Returns: void
- Parameters: a0: point_reference, a1: short
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a8904 (452 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is forced to 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 the wait flag and the remaining arguments start at slot 2. For each actor of the AI reference it finds or creates the actor command script element with function_6b02c8(actor, script thread handle, 1); when the actor handle is not -1 and the point reference passes function_6b2950 it reads the 16-byte point record (position) of the scenario point set (set index in the high 16 bits, point index in the low 16 bits; 14-dword set records at scenario +0x464, 64-byte points at +0x24 of a set) into a request {kind 4, position} and calls function_70f4e0(actor handle, command element, request)
  with the action word a1 stored in the call frame. When the wait flag is set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_action (slot 708)
- Slot: 708 (table entry 0xa1b6d0)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: point_reference, a3: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a8904 (452 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is forced to 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 the wait flag and the remaining arguments start at slot 2. For each actor of the AI reference it finds or creates the actor command script element with function_6b02c8(actor, script thread handle, 1); when the actor handle is not -1 and the point reference passes function_6b2950 it reads the 16-byte point record (position) of the scenario point set (set index in the high 16 bits, point index in the low 16 bits; 14-dword set records at scenario +0x464, 64-byte points at +0x24 of a set) into a request {kind 4, position} and calls function_70f4e0(actor handle, command element, request)
  with the action word a1 stored in the call frame. When the wait flag is set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_action_at_object (slot 709)
- Slot: 709 (table entry 0xa1b4a0)
- Returns: void
- Parameters: a0: object, a1: short
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a8ac8 (320 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is treated as 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 is the wait flag and the arguments start at slot 2. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); when the object a is not -1 it builds a request {kind 6, object handle, zeros} and calls function_70f4e0(actor, element, request) with the 16-bit action value from the following slot. With the wait flag set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_action_at_object (slot 710)
- Slot: 710 (table entry 0xa1b450)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: object, a3: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a8ac8 (320 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is treated as 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 is the wait flag and the arguments start at slot 2. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); when the object a is not -1 it builds a request {kind 6, object handle, zeros} and calls function_70f4e0(actor, element, request) with the 16-bit action value from the following slot. With the wait flag set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_action_at_player (slot 711)
- Slot: 711 (table entry 0xa1b400)
- Returns: void
- Parameters: a0: short
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a8c08 (588 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is forced to 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 the wait flag and the remaining arguments start at slot 2. For each actor of the AI reference it finds or creates the actor command script element with function_6b02c8(actor, script thread handle, 1); when the actor handle is not -1 it iterates the players array (thread-local +0x18) with function_1381c and, for each player whose dword +0x28 is not -1, reads that object position with function_471d38 and measures the squared distance to the actor position (+0x398, +0x39c, +0x3a0 of the actor record); the closest player object handle is kept. When one was found it calls
  function_70f4e0(actor handle, command element, request {kind 6, closest handle}) with the action word a0. When the wait flag is set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_action_at_player (slot 712)
- Slot: 712 (table entry 0xa1b590)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a8c08 (588 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is forced to 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 the wait flag and the remaining arguments start at slot 2. For each actor of the AI reference it finds or creates the actor command script element with function_6b02c8(actor, script thread handle, 1); when the actor handle is not -1 it iterates the players array (thread-local +0x18) with function_1381c and, for each player whose dword +0x28 is not -1, reads that object position with function_471d38 and measures the squared distance to the actor position (+0x398, +0x39c, +0x3a0 of the actor record); the closest player object handle is kept. When one was found it calls
  function_70f4e0(actor handle, command element, request {kind 6, closest handle}) with the action word a0. When the wait flag is set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_custom_animation (slot 713)
- Slot: 713 (table entry 0xa1b540)
- Returns: void
- Parameters: a0: animation_graph, a1: string_id, a2: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a8e54 (380 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is treated as 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 is the wait flag and the arguments start at slot 2. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); then calls function_70f6d0(actor, element, 1, 0) with the animation graph, the animation id and the boolean taken from consecutive slots, -1 for the point reference, a byte of 0, the float -1.0 and the float 0.0 on the stack. With the wait flag set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_custom_animation (slot 714)
- Slot: 714 (table entry 0xa1b4f0)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: animation_graph, a3: string_id, a4: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a8e54 (380 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is treated as 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 is the wait flag and the arguments start at slot 2. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); then calls function_70f6d0(actor, element, 1, 0) with the animation graph, the animation id and the boolean taken from consecutive slots, -1 for the point reference, a byte of 0, the float -1.0 and the float 0.0 on the stack. With the wait flag set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_custom_animation (slot 715)
- Slot: 715 (table entry 0xa1b2c0)
- Returns: void
- Parameters: a0: animation_graph, a1: string_id, a2: boolean, a3: point_reference
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a8fd0 (402 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is treated as 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 is the wait flag and the arguments start at slot 2. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); then calls function_70f6d0(actor, element, 1, 0) with the animation graph, the animation id and the boolean taken from consecutive slots, the point reference in the next slot, a byte of 0, the float -1.0 and the float 0.0 on the stack. With the wait flag set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_custom_animation (slot 716)
- Slot: 716 (table entry 0xa1b270)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: animation_graph, a3: string_id, a4: boolean, a5: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_1a8fd0 (402 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is treated as 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 is the wait flag and the arguments start at slot 2. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); then calls function_70f6d0(actor, element, 1, 0) with the animation graph, the animation id and the boolean taken from consecutive slots, the point reference in the next slot, a byte of 0, the float -1.0 and the float 0.0 on the stack. With the wait flag set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_custom_animation_death (slot 717)
- Slot: 717 (table entry 0xa1b220)
- Returns: void
- Parameters: a0: animation_graph, a1: string_id, a2: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a9164 (380 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is treated as 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 is the wait flag and the arguments start at slot 2. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); then calls function_70f6d0(actor, element, 1, 0) with the animation graph, the animation id and the boolean taken from consecutive slots, -1 for the point reference, a byte of 1, the float -1.0 and the float 0.0 on the stack. With the wait flag set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_custom_animation_death (slot 718)
- Slot: 718 (table entry 0xa1b1d0)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: animation_graph, a3: string_id, a4: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a9164 (380 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is treated as 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 is the wait flag and the arguments start at slot 2. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); then calls function_70f6d0(actor, element, 1, 0) with the animation graph, the animation id and the boolean taken from consecutive slots, -1 for the point reference, a byte of 1, the float -1.0 and the float 0.0 on the stack. With the wait flag set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_custom_animation_death (slot 719)
- Slot: 719 (table entry 0xa1b3b0)
- Returns: void
- Parameters: a0: animation_graph, a1: string_id, a2: boolean, a3: point_reference
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a92e0 (402 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is treated as 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 is the wait flag and the arguments start at slot 2. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); then calls function_70f6d0(actor, element, 1, 0) with the animation graph, the animation id and the boolean taken from consecutive slots, the point reference in the next slot, a byte of 1, the float -1.0 and the float 0.0 on the stack. With the wait flag set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_custom_animation_death (slot 720)
- Slot: 720 (table entry 0xa1b360)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: animation_graph, a3: string_id, a4: boolean, a5: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_1a92e0 (402 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is treated as 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 is the wait flag and the arguments start at slot 2. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); then calls function_70f6d0(actor, element, 1, 0) with the animation graph, the animation id and the boolean taken from consecutive slots, the point reference in the next slot, a byte of 1, the float -1.0 and the float 0.0 on the stack. With the wait flag set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_custom_animation_loop (slot 721)
- Slot: 721 (table entry 0xa1b310)
- Returns: void
- Parameters: a0: animation_graph, a1: string_id, a2: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a9474 (340 bytes)
- Behavior: Command script native without a wait flag. On a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record and the arguments start at slot 0; otherwise a0 is the AI reference and the arguments start at slot 1. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); then calls function_70f6d0(actor, element, 0, 1) with the animation graph, the animation id and the boolean taken from consecutive slots, -1 for the point reference, a byte of 0, the float -1.0 and the float 0.0 on the stack. Nothing is written to the thread record. Returns nothing.
- Evidence: V

### cs_custom_animation_loop (slot 722)
- Slot: 722 (table entry 0xa1b090)
- Returns: void
- Parameters: a0: ai, a1: animation_graph, a2: string_id, a3: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a9474 (340 bytes)
- Behavior: Command script native without a wait flag. On a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record and the arguments start at slot 0; otherwise a0 is the AI reference and the arguments start at slot 1. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); then calls function_70f6d0(actor, element, 0, 1) with the animation graph, the animation id and the boolean taken from consecutive slots, -1 for the point reference, a byte of 0, the float -1.0 and the float 0.0 on the stack. Nothing is written to the thread record. Returns nothing.
- Evidence: V

### cs_custom_animation_loop (slot 723)
- Slot: 723 (table entry 0xa1b040)
- Returns: void
- Parameters: a0: animation_graph, a1: string_id, a2: boolean, a3: point_reference
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a95c8 (351 bytes)
- Behavior: Command script native without a wait flag. On a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record and the arguments start at slot 0; otherwise a0 is the AI reference and the arguments start at slot 1. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); then calls function_70f6d0(actor, element, 0, 1) with the animation graph, the animation id, the boolean and the point reference taken from consecutive slots, a byte of 0, the float -1.0 and the float 0.0 on the stack. Nothing is written to the thread record. Returns nothing.
- Evidence: V

### cs_custom_animation_loop (slot 724)
- Slot: 724 (table entry 0xa1aff0)
- Returns: void
- Parameters: a0: ai, a1: animation_graph, a2: string_id, a3: boolean, a4: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_1a95c8 (351 bytes)
- Behavior: Command script native without a wait flag. On a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record and the arguments start at slot 0; otherwise a0 is the AI reference and the arguments start at slot 1. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); then calls function_70f6d0(actor, element, 0, 1) with the animation graph, the animation id, the boolean and the point reference taken from consecutive slots, a byte of 0, the float -1.0 and the float 0.0 on the stack. Nothing is written to the thread record. Returns nothing.
- Evidence: V

### cs_play_line (slot 725)
- Slot: 725 (table entry 0xa1b180)
- Returns: void
- Parameters: a0: ai_line
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a9728 (264 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_71138c(the current actor, result of function_6b02c8, 1, a0); then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second
  argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_71138c (694 bytes): accesses actor (thread-local +0x8 x0xd00): reads +0x1c 32-bit | object record: reads +0x55e 16-bit; touches data at 0xc1a230, 0xc1a600, 0xc1a238; calls function_49ac18, function_70f5d4, function_71120c.
- Evidence: V

### cs_play_line (slot 726)
- Slot: 726 (table entry 0xa1b130)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: ai_line
- Kind: normal
- Status: implemented
- Evaluator: function_1a9728 (264 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_71138c(the current actor, result of function_6b02c8, 1, a0); then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second
  argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_71138c (694 bytes): accesses actor (thread-local +0x8 x0xd00): reads +0x1c 32-bit | object record: reads +0x55e 16-bit; touches data at 0xc1a230, 0xc1a600, 0xc1a238; calls function_49ac18, function_70f5d4, function_71120c.
- Evidence: V

### cs_die (slot 727)
- Slot: 727 (table entry 0xa1b0e0)
- Returns: void
- Parameters: a0: short
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a9830 (259 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0x10, 1); then stores a0 (16-bit) to the record returned by function_6b0648 at +0x2; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec
  bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_die (slot 728)
- Slot: 728 (table entry 0xa1ae60)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a9830 (259 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0x10, 1); then stores a2 (16-bit) to the record returned by function_6b0648 at +0x2; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword
  +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_deploy_turret (slot 729)
- Slot: 729 (table entry 0xa1ae10)
- Returns: void
- Parameters: a0: point_reference
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a9934 (257 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0x17, 1); then stores a0 to the record returned by function_6b0648 at +0x24; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes)
  looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_deploy_turret (slot 730)
- Slot: 730 (table entry 0xa1adc0)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_1a9934 (257 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0x17, 1); then stores a2 to the record returned by function_6b0648 at +0x24; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc
  equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_approach (slot 731)
- Slot: 731 (table entry 0xa1afa0)
- Returns: void
- Parameters: a0: object, a1: real, a2: real, a3: real
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a9a38 (329 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is treated as 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 is the wait flag and the arguments start at slot 2. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); then calls function_70f420(actor, element, 1, object a, first real, second real, third real) (the reals are passed on the stack). With the wait flag set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_approach (slot 732)
- Slot: 732 (table entry 0xa1af50)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: object, a3: real, a4: real, a5: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a9a38 (329 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is treated as 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 is the wait flag and the arguments start at slot 2. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); then calls function_70f420(actor, element, 1, object a, first real, second real, third real) (the reals are passed on the stack). With the wait flag set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_approach_player (slot 733)
- Slot: 733 (table entry 0xa1af00)
- Returns: void
- Parameters: a0: real, a1: real, a2: real
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a9b84 (313 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is treated as 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 is the wait flag and the arguments start at slot 2. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); then calls function_70f420(actor, element, 1, -1, first real, second real, third real) (the reals are passed on the stack). With the wait flag set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_approach_player (slot 734)
- Slot: 734 (table entry 0xa1aeb0)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: real, a3: real, a4: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a9b84 (313 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is treated as 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 is the wait flag and the arguments start at slot 2. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1); then calls function_70f420(actor, element, 1, -1, first real, second real, third real) (the reals are passed on the stack). With the wait flag set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_go_to_vehicle (slot 735)
- Slot: 735 (table entry 0xa1ac80)
- Returns: void
- Parameters: a0: vehicle
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a9cc0 (261 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0xa, 1); then applies or with 0xffffffff to the record returned by function_6b0648 at +0x28; then stores a0 to the record returned by function_6b0648 at +0x24; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the
  link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_go_to_vehicle (slot 736)
- Slot: 736 (table entry 0xa1ac30)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: vehicle
- Kind: normal
- Status: implemented
- Evaluator: function_1a9cc0 (261 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0xa, 1); then applies or with 0xffffffff to the record returned by function_6b0648 at +0x28; then stores a2 to the record returned by function_6b0648 at +0x24; then stores 0xfffffffd to the running thread record at +0xc; then stores the AI reference to the running thread record at +0x24. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command
  script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_go_to_vehicle (slot 737)
- Slot: 737 (table entry 0xa1abe0)
- Returns: void
- Parameters: a0: vehicle, a1: unit_seat_mapping
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a9dc8 (293 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0xa, 1); then stores a0 to the record returned by function_6b0648 at +0x24; then stores a1 to the record returned by function_6b0648 at +0x28; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10
  of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_go_to_vehicle (slot 738)
- Slot: 738 (table entry 0xa1ad70)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: vehicle, a3: unit_seat_mapping
- Kind: normal
- Status: implemented
- Evaluator: function_1a9dc8 (293 bytes)
- Behavior: Evaluates 4 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_6b0648(result of function_6b02c8, 0xa, 1); then stores a2 to the record returned by function_6b0648 at +0x24; then stores a3 to the record returned by function_6b0648 at +0x28; then stores the AI reference to the running thread record at +0x24; then stores 0xfffffffd to the running thread record at +0xc. It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements
  (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_6b0648 (171 bytes): uses thread-local fields +0x60 (command scripts); calls function_78932a.
- Evidence: V

### cs_set_style (slot 739)
- Slot: 739 (table entry 0xa1ad20)
- Returns: void
- Parameters: a0: style
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1a9ef0 (274 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 to field +0x1b4 of the command scripts element (thread-local +0x60 x0x1ec); then stores 1 to field +0x1b1 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1b1 byte, +0x1b4 32-bit. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local
  +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_set_style (slot 740)
- Slot: 740 (table entry 0xa1acd0)
- Returns: void
- Parameters: a0: ai, a1: style
- Kind: normal
- Status: implemented
- Evaluator: function_1a9ef0 (274 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a1 to field +0x1b4 of the command scripts element (thread-local +0x60 x0x1ec); then stores 1 to field +0x1b1 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1b1 byte, +0x1b4 32-bit. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one
  whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_force_combat_status (slot 741)
- Slot: 741 (table entry 0xa1aaa0)
- Returns: void
- Parameters: a0: short
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1aa004 (203 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70f8e8(a first argument the callee does not read, result of function_6b02c8, a0 (16-bit)). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with
  function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_70f8e8 (69 bytes): Sets the forced combat status word (+0x1b2) of the command script element selected by the second argument (thread-local +0x60, 0x1ec bytes) when the value is at most 3; ignores handle -1 and larger values; returns early when result of function_6b02c8 == -1.
- Evidence: V

### cs_force_combat_status (slot 742)
- Slot: 742 (table entry 0xa1aa50)
- Returns: void
- Parameters: a0: ai, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_1aa004 (203 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70f8e8(a first argument the callee does not read, result of function_6b02c8, a1 (16-bit)). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and
  clears its byte +0x14; returns the element handle or -1. function_70f8e8 (69 bytes): Sets the forced combat status word (+0x1b2) of the command script element selected by the second argument (thread-local +0x60, 0x1ec bytes) when the value is at most 3; ignores handle -1 and larger values; returns early when result of function_6b02c8 == -1.
- Evidence: V

### cs_enable_targeting (slot 743)
- Slot: 743 (table entry 0xa1aa00)
- Returns: void
- Parameters: a0: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1aa0d0 (279 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (8-bit) to field +0x1ab of the command scripts element (thread-local +0x60 x0x1ec); then stores a0 (8-bit) to field +0x1ac of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1ab byte, +0x1ac byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements
  (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_enable_targeting (slot 744)
- Slot: 744 (table entry 0xa1ab90)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1aa0d0 (279 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (8-bit) to field +0x1ab of the command scripts element (thread-local +0x60 x0x1ec); then stores a0 (8-bit) to field +0x1ac of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1ab byte, +0x1ac byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements
  (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_enable_looking (slot 745)
- Slot: 745 (table entry 0xa1ab40)
- Returns: void
- Parameters: a0: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1aa1e8 (267 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (8-bit) to field +0x1ac of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1ac byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is
  found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_enable_looking (slot 746)
- Slot: 746 (table entry 0xa1aaf0)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1aa1e8 (267 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a1 (8-bit) to field +0x1ac of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1ac byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is
  non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_enable_moving (slot 747)
- Slot: 747 (table entry 0xa1a8c0)
- Returns: void
- Parameters: a0: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1aa2f4 (267 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (8-bit) to field +0x1ad of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1ad byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is
  found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_enable_moving (slot 748)
- Slot: 748 (table entry 0xa1a870)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1aa2f4 (267 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a1 (8-bit) to field +0x1ad of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1ad byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is
  non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_enable_dialogue (slot 749)
- Slot: 749 (table entry 0xa1a820)
- Returns: void
- Parameters: a0: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1aa400 (267 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (8-bit) to field +0x1ae of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1ae byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is
  found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_enable_dialogue (slot 750)
- Slot: 750 (table entry 0xa1a7d0)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1aa400 (267 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a1 (8-bit) to field +0x1ae of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1ae byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is
  non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_suppress_activity_termination (slot 751)
- Slot: 751 (table entry 0xa1a9b0)
- Returns: void
- Parameters: a0: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1aa50c (267 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (8-bit) to field +0x1af of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1af byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is
  found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_suppress_activity_termination (slot 752)
- Slot: 752 (table entry 0xa1a960)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1aa50c (267 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a1 (8-bit) to field +0x1af of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1af byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is
  non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_suppress_dialogue_global (slot 753)
- Slot: 753 (table entry 0xa1a910)
- Returns: void
- Parameters: a0: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1aa618 (267 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (8-bit) to field +0x1b0 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1b0 byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is
  found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_suppress_dialogue_global (slot 754)
- Slot: 754 (table entry 0xa1a690)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1aa618 (267 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a1 (8-bit) to field +0x1b0 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1b0 byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is
  non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_look (slot 755)
- Slot: 755 (table entry 0xa1a640)
- Returns: void
- Parameters: a0: boolean, a1: point_reference
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1aa724 (320 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (8-bit) to field +0x170 of the command scripts element (thread-local +0x60 x0x1ec); then stores a1 to field +0x178 of the command scripts element (thread-local +0x60 x0x1ec); then stores 2 to field +0x174 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x170 byte, +0x174 16-bit, +0x178 32-bit. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local
  +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_look (slot 756)
- Slot: 756 (table entry 0xa1a5f0)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_1aa724 (320 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (8-bit) to field +0x170 of the command scripts element (thread-local +0x60 x0x1ec); then stores a1 to field +0x178 of the command scripts element (thread-local +0x60 x0x1ec); then stores 2 to field +0x174 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x170 byte, +0x174 16-bit, +0x178 32-bit. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local
  +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_look_player (slot 757)
- Slot: 757 (table entry 0xa1a780)
- Returns: void
- Parameters: a0: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1aa864 (352 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70f2b8(the current actor); then stores result of function_70f2b8 to field +0x178 of the command scripts element (thread-local +0x60 x0x1ec); then stores 1 to field +0x174 of the command scripts element (thread-local +0x60 x0x1ec); then stores 1 to field +0x170 of the command scripts element (thread-local +0x60 x0x1ec); then calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70f2b8(the current actor); then stores result of function_70f2b8 to field +0x178 of the command scripts element (thread-local +0x60 x0x1ec); then stores 1 to field +0x174 of the command scripts element (thread-local +0x60 x0x1ec);
  then stores 1 to field +0x170 of the command scripts element (thread-local +0x60 x0x1ec); then calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70f2b8(the current actor); then stores result of function_70f2b8 to field +0x178 of the command scripts element (thread-local +0x60 x0x1ec); then stores 1 to field +0x174 of the command scripts element (thread-local +0x60 x0x1ec); then stores 1 to field +0x170 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x170 byte, +0x174 16-bit, +0x178 32-bit. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local
  +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_70f2b8 (358 bytes): accesses actor (thread-local +0x8 x0xd00): reads +0x74 32-bit, +0x38c 32-bit, +0x390 32-bit, +0x394 32-bit; calls function_73a384, function_48a020, function_1381c.
- Evidence: V

### cs_look_player (slot 758)
- Slot: 758 (table entry 0xa1a730)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1aa864 (352 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70f2b8(the current actor); then stores result of function_70f2b8 to field +0x178 of the command scripts element (thread-local +0x60 x0x1ec); then stores 1 to field +0x174 of the command scripts element (thread-local +0x60 x0x1ec); then stores 1 to field +0x170 of the command scripts element (thread-local +0x60 x0x1ec); then calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70f2b8(the current actor); then stores result of function_70f2b8 to field +0x178 of the command scripts element (thread-local +0x60 x0x1ec); then stores 1 to field +0x174 of the command scripts element (thread-local +0x60 x0x1ec);
  then stores 1 to field +0x170 of the command scripts element (thread-local +0x60 x0x1ec); then calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70f2b8(the current actor); then stores result of function_70f2b8 to field +0x178 of the command scripts element (thread-local +0x60 x0x1ec); then stores 1 to field +0x174 of the command scripts element (thread-local +0x60 x0x1ec); then stores 1 to field +0x170 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x170 byte, +0x174 16-bit, +0x178 32-bit. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local
  +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_70f2b8 (358 bytes): accesses actor (thread-local +0x8 x0xd00): reads +0x74 32-bit, +0x38c 32-bit, +0x390 32-bit, +0x394 32-bit; calls function_73a384, function_48a020, function_1381c.
- Evidence: V

### cs_look_object (slot 759)
- Slot: 759 (table entry 0xa1a6e0)
- Returns: void
- Parameters: a0: boolean, a1: object
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1aa9c4 (231 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70f98c(a first argument the callee does not read, result of function_6b02c8, a0 (8-bit), a1). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with
  function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_70f98c (80 bytes): Sets the look target of a command script element (thread-local +0x60, 0x1ec bytes): byte +0x170 gets the flag; when the flag is set also +0x174 = 1 (object target) and +0x178 = the object handle; returns early when result of function_6b02c8 == -1.
- Evidence: V

### cs_look_object (slot 760)
- Slot: 760 (table entry 0xa1a460)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: object
- Kind: normal
- Status: implemented
- Evaluator: function_1aa9c4 (231 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70f98c(a first argument the callee does not read, result of function_6b02c8, a1 (8-bit), a2). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and
  clears its byte +0x14; returns the element handle or -1. function_70f98c (80 bytes): Sets the look target of a command script element (thread-local +0x60, 0x1ec bytes): byte +0x170 gets the flag; when the flag is set also +0x174 = 1 (object target) and +0x178 = the object handle; returns early when result of function_6b02c8 == -1.
- Evidence: V

### cs_aim (slot 761)
- Slot: 761 (table entry 0xa1a410)
- Returns: void
- Parameters: a0: boolean, a1: point_reference
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1aaaac (231 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70f9dc(a first argument the callee does not read, result of function_6b02c8, a0 (8-bit), a1). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with
  function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_70f9dc (163 bytes): returns early when result of function_6b02c8 == -1; accesses command scripts (thread-local +0x60 x0x1ec): writes +0x170 byte, +0x174 16-bit, +0x178 32-bit, +0x184 16-bit, +0x186 byte, +0x187 byte, +0x188 16-bit, +0x18c 32-bit.
- Evidence: V

### cs_aim (slot 762)
- Slot: 762 (table entry 0xa1a3c0)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_1aaaac (231 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70f9dc(a first argument the callee does not read, result of function_6b02c8, a1 (8-bit), a2). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and
  clears its byte +0x14; returns the element handle or -1. function_70f9dc (163 bytes): returns early when result of function_6b02c8 == -1; accesses command scripts (thread-local +0x60 x0x1ec): writes +0x170 byte, +0x174 16-bit, +0x178 32-bit, +0x184 16-bit, +0x186 byte, +0x187 byte, +0x188 16-bit, +0x18c 32-bit.
- Evidence: V

### cs_aim_player (slot 763)
- Slot: 763 (table entry 0xa1a5a0)
- Returns: void
- Parameters: a0: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1aab94 (218 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70faf4(the current actor, result of function_6b02c8, a0 (8-bit)). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second
  argument) and clears its byte +0x14; returns the element handle or -1. function_70faf4 (176 bytes): accesses command scripts (thread-local +0x60 x0x1ec): writes +0x184 byte, +0x185 byte, +0x186 byte/32-bit, +0x18c 32-bit; calls function_70f2b8, function_70f98c.
- Evidence: V

### cs_aim_player (slot 764)
- Slot: 764 (table entry 0xa1a550)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1aab94 (218 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70faf4(the current actor, result of function_6b02c8, a1 (8-bit)). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14;
  returns the element handle or -1. function_70faf4 (176 bytes): accesses command scripts (thread-local +0x60 x0x1ec): writes +0x184 byte, +0x185 byte, +0x186 byte/32-bit, +0x18c 32-bit; calls function_70f2b8, function_70f98c.
- Evidence: V

### cs_aim_object (slot 765)
- Slot: 765 (table entry 0xa1a500)
- Returns: void
- Parameters: a0: boolean, a1: object
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1aac70 (231 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70fba4(a first argument the callee does not read, result of function_6b02c8, a0 (8-bit), a1). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with
  function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_70fba4 (129 bytes): returns early when a1 == -1; result of function_6b02c8 == -1; accesses command scripts (thread-local +0x60 x0x1ec): writes +0x170 byte, +0x184 16-bit, +0x186 byte, +0x187 byte, +0x188 16-bit, +0x18c 32-bit; calls function_70f98c.
- Evidence: V

### cs_aim_object (slot 766)
- Slot: 766 (table entry 0xa1a4b0)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: object
- Kind: normal
- Status: implemented
- Evaluator: function_1aac70 (231 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70fba4(a first argument the callee does not read, result of function_6b02c8, a1 (8-bit), a2). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and
  clears its byte +0x14; returns the element handle or -1. function_70fba4 (129 bytes): returns early when a2 == -1; result of function_6b02c8 == -1; accesses command scripts (thread-local +0x60 x0x1ec): writes +0x170 byte, +0x184 16-bit, +0x186 byte, +0x187 byte, +0x188 16-bit, +0x18c 32-bit; calls function_70f98c.
- Evidence: V

### cs_face (slot 767)
- Slot: 767 (table entry 0xa1a280)
- Returns: void
- Parameters: a0: boolean, a1: point_reference
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1aad58 (231 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70fc28(a first argument the callee does not read, result of function_6b02c8). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1,
  second argument) and clears its byte +0x14; returns the element handle or -1. function_70fc28 (95 bytes): Sets face flags of a command script element: calls function_70f9dc, then, when the flag is set, stores 0x1000101 at +0x184 and clears +0x170, otherwise clears +0x187; returns early when result of function_6b02c8 == -1.
- Evidence: V

### cs_face (slot 768)
- Slot: 768 (table entry 0xa1a230)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_1aad58 (231 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70fc28(a first argument the callee does not read, result of function_6b02c8). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte
  +0x14; returns the element handle or -1. function_70fc28 (95 bytes): Sets face flags of a command script element: calls function_70f9dc, then, when the flag is set, stores 0x1000101 at +0x184 and clears +0x170, otherwise clears +0x187; returns early when result of function_6b02c8 == -1.
- Evidence: V

### cs_face_player (slot 769)
- Slot: 769 (table entry 0xa1a1e0)
- Returns: void
- Parameters: a0: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1aae40 (218 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70fd40(the current actor, result of function_6b02c8, a0 (8-bit)). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second
  argument) and clears its byte +0x14; returns the element handle or -1. function_70fd40 (109 bytes): Sets face-player flags of a command script element: calls function_70faf4, then, when the flag is set, stores 1 at +0x187 and 0x101 at +0x184, otherwise clears +0x187; returns early when result of function_6b02c8 == -1.
- Evidence: V

### cs_face_player (slot 770)
- Slot: 770 (table entry 0xa1a370)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1aae40 (218 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70fd40(the current actor, result of function_6b02c8, a1 (8-bit)). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14;
  returns the element handle or -1. function_70fd40 (109 bytes): Sets face-player flags of a command script element: calls function_70faf4, then, when the flag is set, stores 1 at +0x187 and 0x101 at +0x184, otherwise clears +0x187; returns early when result of function_6b02c8 == -1.
- Evidence: V

### cs_face_object (slot 771)
- Slot: 771 (table entry 0xa1a320)
- Returns: void
- Parameters: a0: boolean, a1: object
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1aaf1c (231 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70fcdc(a first argument the callee does not read, result of function_6b02c8, a0 (8-bit)). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with
  function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_70fcdc (99 bytes): Sets face-object flags of a command script element: calls function_70fba4, then, when the flag is set, stores 1 at +0x187 and 0x101 at +0x184, otherwise clears +0x187; returns early when result of function_6b02c8 == -1.
- Evidence: V

### cs_face_object (slot 772)
- Slot: 772 (table entry 0xa1a2d0)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: object
- Kind: normal
- Status: implemented
- Evaluator: function_1aaf1c (231 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70fcdc(a first argument the callee does not read, result of function_6b02c8, a1 (8-bit)). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and
  clears its byte +0x14; returns the element handle or -1. function_70fcdc (99 bytes): Sets face-object flags of a command script element: calls function_70fba4, then, when the flag is set, stores 1 at +0x187 and 0x101 at +0x184, otherwise clears +0x187; returns early when result of function_6b02c8 == -1.
- Evidence: V

### cs_shoot (slot 773)
- Slot: 773 (table entry 0xa1a0a0)
- Returns: void
- Parameters: a0: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1ab004 (222 bytes)
- Behavior: Command script native without a wait flag. On a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record and the arguments start at slot 0; otherwise a0 is the AI reference and the arguments start at slot 1. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1) (the boolean is the last argument and is read at slot 0 on a thread of script type 3, slot 1 otherwise); then calls function_70fdb0(actor, element, boolean, -1). Returns nothing.
- Evidence: V

### cs_shoot (slot 774)
- Slot: 774 (table entry 0xa1a050)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1ab004 (222 bytes)
- Behavior: Command script native without a wait flag. On a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record and the arguments start at slot 0; otherwise a0 is the AI reference and the arguments start at slot 1. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1) (the boolean is the last argument and is read at slot 0 on a thread of script type 3, slot 1 otherwise); then calls function_70fdb0(actor, element, boolean, -1). Returns nothing.
- Evidence: V

### cs_shoot (slot 775)
- Slot: 775 (table entry 0xa1a000)
- Returns: void
- Parameters: a0: boolean, a1: object
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1ab0e4 (227 bytes)
- Behavior: Command script native without a wait flag. On a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record and the arguments start at slot 0; otherwise a0 is the AI reference and the arguments start at slot 1. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1) (the boolean is read first and the object after it); then calls function_70fdb0(actor, element, boolean, object). Returns nothing.
- Evidence: V

### cs_shoot (slot 776)
- Slot: 776 (table entry 0xa1a190)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: object
- Kind: normal
- Status: implemented
- Evaluator: function_1ab0e4 (227 bytes)
- Behavior: Command script native without a wait flag. On a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record and the arguments start at slot 0; otherwise a0 is the AI reference and the arguments start at slot 1. For each actor of the AI reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1) (the boolean is read first and the object after it); then calls function_70fdb0(actor, element, boolean, object). Returns nothing.
- Evidence: V

### cs_shoot_point (slot 777)
- Slot: 777 (table entry 0xa1a140)
- Returns: void
- Parameters: a0: boolean, a1: point_reference
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1ab1c8 (420 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (8-bit) to field +0x164 of the command scripts element (thread-local +0x60 x0x1ec); then stores a1 to field +0x18c of the command scripts element (thread-local +0x60 x0x1ec); then stores 1 to field +0x186 of the command scripts element (thread-local +0x60 x0x1ec); then stores 2 to field +0x188 of the command scripts element (thread-local +0x60 x0x1ec); then stores 0 to field +0x170 of the command scripts element (thread-local +0x60 x0x1ec); then calls function_70f8e8(2, result of function_6b02c8, 3). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x164 byte, +0x170 byte, +0x186 byte,
  +0x188 16-bit, +0x18c 32-bit | actor (thread-local +0x8 x0xd00): reads +0x32a 16-bit. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_70f8e8 (69 bytes): Sets the forced combat status word (+0x1b2) of the command script element selected by the second argument (thread-local +0x60, 0x1ec bytes) when the value is at most 3;
  ignores handle -1 and larger values; returns early when result of function_6b02c8 == -1.
- Evidence: V

### cs_shoot_point (slot 778)
- Slot: 778 (table entry 0xa1a0f0)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_1ab1c8 (420 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (8-bit) to field +0x164 of the command scripts element (thread-local +0x60 x0x1ec); then stores a1 to field +0x18c of the command scripts element (thread-local +0x60 x0x1ec); then stores 1 to field +0x186 of the command scripts element (thread-local +0x60 x0x1ec); then stores 2 to field +0x188 of the command scripts element (thread-local +0x60 x0x1ec); then stores 0 to field +0x170 of the command scripts element (thread-local +0x60 x0x1ec); then calls function_70f8e8(2, result of function_6b02c8, 3). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x164 byte, +0x170 byte, +0x186 byte,
  +0x188 16-bit, +0x18c 32-bit | actor (thread-local +0x8 x0xd00): reads +0x32a 16-bit. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_70f8e8 (69 bytes): Sets the forced combat status word (+0x1b2) of the command script element selected by the second argument (thread-local +0x60, 0x1ec bytes) when the value is at most 3;
  ignores handle -1 and larger values; returns early when result of function_6b02c8 == -1.
- Evidence: V

### cs_shoot_secondary_trigger (slot 779)
- Slot: 779 (table entry 0xa19ec0)
- Returns: void
- Parameters: a0: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1ab36c (267 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (8-bit) to field +0x165 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x165 byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is
  found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_shoot_secondary_trigger (slot 780)
- Slot: 780 (table entry 0xa19e70)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1ab36c (267 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a1 (8-bit) to field +0x165 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x165 byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is
  non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_lower_weapon (slot 781)
- Slot: 781 (table entry 0xa19e20)
- Returns: void
- Parameters: a0: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1ab478 (267 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (8-bit) to field +0x185 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x185 byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is
  found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_lower_weapon (slot 782)
- Slot: 782 (table entry 0xa19dd0)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1ab478 (267 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a1 (8-bit) to field +0x185 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x185 byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is
  non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_vehicle_speed (slot 783)
- Slot: 783 (table entry 0xa19fb0)
- Returns: void
- Parameters: a0: real
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1ab584 (294 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (float) to field +0x19c of the command scripts element (thread-local +0x60 x0x1ec); then stores 1 to field +0x198 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x198 byte, +0x19c 32-bit. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements
  (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_vehicle_speed (slot 784)
- Slot: 784 (table entry 0xa19f60)
- Returns: void
- Parameters: a0: ai, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1ab584 (294 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (float) to field +0x19c of the command scripts element (thread-local +0x60 x0x1ec); then stores 1 to field +0x198 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x198 byte, +0x19c 32-bit. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements
  (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_vehicle_speed_instantaneous (slot 785)
- Slot: 785 (table entry 0xa19f10)
- Returns: void
- Parameters: a0: real
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1ab6ac (490 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is forced to 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 the wait flag and the remaining arguments start at slot 2. For each actor of the AI reference it finds or creates the actor command script element with function_6b02c8(actor, script thread handle, 1) (this evaluator has no wait flag; a1 is the speed in the ai call form); when the actor byte +0x3d0 is non-zero it calls function_4d9bf8(actor +0x3d8 object handle, speed, 0.0, 0.0), sets byte +0x198 = 1 and float +0x19c = speed in the command script element, and stores a derived float at actor +0x9a8 when the actor word +0x3dc is 3 or at +0x9c4 when it is 5 (0 when the speed magnitude is below a constant, otherwise one of two constants chosen by the sign of the speed).
- Evidence: V

### cs_vehicle_speed_instantaneous (slot 786)
- Slot: 786 (table entry 0xa19c90)
- Returns: void
- Parameters: a0: ai, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1ab6ac (490 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is forced to 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 the wait flag and the remaining arguments start at slot 2. For each actor of the AI reference it finds or creates the actor command script element with function_6b02c8(actor, script thread handle, 1) (this evaluator has no wait flag; a1 is the speed in the ai call form); when the actor byte +0x3d0 is non-zero it calls function_4d9bf8(actor +0x3d8 object handle, speed, 0.0, 0.0), sets byte +0x198 = 1 and float +0x19c = speed in the command script element, and stores a derived float at actor +0x9a8 when the actor word +0x3dc is 3 or at +0x9c4 when it is 5 (0 when the speed magnitude is below a constant, otherwise one of two constants chosen by the sign of the speed).
- Evidence: V

### cs_vehicle_boost (slot 787)
- Slot: 787 (table entry 0xa19c40)
- Returns: void
- Parameters: a0: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1ab898 (267 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (8-bit) to field +0x1a8 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1a8 byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is
  found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_vehicle_boost (slot 788)
- Slot: 788 (table entry 0xa19bf0)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1ab898 (267 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a1 (8-bit) to field +0x1a8 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1a8 byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is
  non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_turn_sharpness (slot 789)
- Slot: 789 (table entry 0xa19d80)
- Returns: void
- Parameters: a0: boolean, a1: real
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1ab9a4 (310 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (8-bit) to field +0x1a0 of the command scripts element (thread-local +0x60 x0x1ec); then stores a1 (float) to field +0x1a4 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1a0 byte, +0x1a4 32-bit. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script
  elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_turn_sharpness (slot 790)
- Slot: 790 (table entry 0xa19d30)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1ab9a4 (310 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (8-bit) to field +0x1a0 of the command scripts element (thread-local +0x60 x0x1ec); then stores a1 (float) to field +0x1a4 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1a0 byte, +0x1a4 32-bit. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script
  elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_enable_pathfinding_failsafe (slot 791)
- Slot: 791 (table entry 0xa19ce0)
- Returns: void
- Parameters: a0: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1abadc (267 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (8-bit) to field +0x1aa of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1aa byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is
  found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_enable_pathfinding_failsafe (slot 792)
- Slot: 792 (table entry 0xa19a70)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1abadc (267 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a1 (8-bit) to field +0x1aa of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1aa byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is
  non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_set_pathfinding_radius (slot 793)
- Slot: 793 (table entry 0xa19a20)
- Returns: void
- Parameters: a0: real
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1abbe8 (165 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the 32-bit value at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_set_pathfinding_radius (slot 794)
- Slot: 794 (table entry 0xa199d0)
- Returns: void
- Parameters: a0: ai, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1abbe8 (165 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_ignore_obstacles (slot 795)
- Slot: 795 (table entry 0xa19ba0)
- Returns: void
- Parameters: a0: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1abc90 (267 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (8-bit) to field +0x1a9 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1a9 byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is
  found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_ignore_obstacles (slot 796)
- Slot: 796 (table entry 0xa19b50)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1abc90 (267 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a1 (8-bit) to field +0x1a9 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1a9 byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is
  non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_approach_stop (slot 797)
- Slot: 797 (table entry 0xa19b10)
- Returns: void
- Parameters: none
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1abd9c (135 bytes)
- Behavior: Evaluates 0 argument(s). Iterates the actors of the 32-bit value at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_75e7e4(result of function_6b02c8). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14;
  returns the element handle or -1. function_75e7e4 (89 bytes): Clears the command script element selected by the argument (thread-local +0x60, 0x1ec bytes): when byte +0x1d4 is non-zero or dword +0x1d8 is not -1, sets +0x1d8 to -1 and clears word +0x1d4 and bytes +0x186 and +0x170.
- Evidence: V

### cs_approach_stop (slot 798)
- Slot: 798 (table entry 0xa19ac0)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1abd9c (135 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the 32-bit value at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_75e7e4(result of function_6b02c8). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14;
  returns the element handle or -1. function_75e7e4 (89 bytes): Clears the command script element selected by the argument (thread-local +0x60, 0x1ec bytes): when byte +0x1d4 is non-zero or dword +0x1d8 is not -1, sets +0x1d8 to -1 and clears word +0x1d4 and bytes +0x186 and +0x170.
- Evidence: V

### cs_push_stance (slot 799)
- Slot: 799 (table entry 0xa19890)
- Returns: void
- Parameters: a0: string_id
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1abe24 (267 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 to field +0x1bc of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1bc 32-bit. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and
  the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_push_stance (slot 800)
- Slot: 800 (table entry 0xa19840)
- Returns: void
- Parameters: a0: ai, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1abe24 (267 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a1 to field +0x1bc of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x1bc 32-bit. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it
  creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_crouch (slot 801)
- Slot: 801 (table entry 0xa197f0)
- Returns: void
- Parameters: a0: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1abf30 (205 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70ff20(a first argument the callee does not read, result of function_6b02c8, a0 (8-bit)). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with
  function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_70ff20 (85 bytes): Sets the crouch byte (+0x169) of a command script element (thread-local +0x60, 0x1ec bytes) and, when the float argument exceeds a small constant, the float at +0x16c to 1 divided by that value; returns early when result of function_6b02c8 == -1.
- Evidence: V

### cs_crouch (slot 802)
- Slot: 802 (table entry 0xa19980)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1abf30 (205 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70ff20(a first argument the callee does not read, result of function_6b02c8, a1 (8-bit)). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and
  clears its byte +0x14; returns the element handle or -1. function_70ff20 (85 bytes): Sets the crouch byte (+0x169) of a command script element (thread-local +0x60, 0x1ec bytes) and, when the float argument exceeds a small constant, the float at +0x16c to 1 divided by that value; returns early when result of function_6b02c8 == -1.
- Evidence: V

### cs_crouch (slot 803)
- Slot: 803 (table entry 0xa19930)
- Returns: void
- Parameters: a0: boolean, a1: real
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1ac000 (232 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70ff20(a first argument the callee does not read, result of function_6b02c8, a0 (8-bit)) and float in xmm3=a1 (float). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it
  creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_70ff20 (85 bytes): Sets the crouch byte (+0x169) of a command script element (thread-local +0x60, 0x1ec bytes) and, when the float argument exceeds a small constant, the float at +0x16c to 1 divided by that value; returns early when result of function_6b02c8 == -1.
- Evidence: V

### cs_crouch (slot 804)
- Slot: 804 (table entry 0xa198e0)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1ac000 (232 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_70ff20(a first argument the callee does not read, result of function_6b02c8, a1 (8-bit)) and float in xmm3=a2 (float). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor,
  -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_70ff20 (85 bytes): Sets the crouch byte (+0x169) of a command script element (thread-local +0x60, 0x1ec bytes) and, when the float argument exceeds a small constant, the float at +0x16c to 1 divided by that value; returns early when result of function_6b02c8 == -1.
- Evidence: V

### cs_walk (slot 805)
- Slot: 805 (table entry 0xa196c0)
- Returns: void
- Parameters: a0: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1ac0e8 (267 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a0 (8-bit) to field +0x168 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x168 byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is
  found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_walk (slot 806)
- Slot: 806 (table entry 0xa19670)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1ac0e8 (267 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then stores a1 (8-bit) to field +0x168 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: command scripts (thread-local +0x60 x0x1ec): writes +0x168 byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is
  non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1.
- Evidence: V

### cs_posture_set (slot 807)
- Slot: 807 (table entry 0xa19620)
- Returns: void
- Parameters: a0: string_id, a1: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1ac1f4 (539 bytes)
- Behavior: Command script native without a wait flag. The AI reference is the dword at +0x24 of the running thread record (a thread whose script type byte, +0x20, equals 3) and the arguments are the posture id (a0) and a boolean (a1). For each actor it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1). When the actor unit handle (+0x1c) is not -1 it searches the 54-entry posture table at RVA 0xa88020 (0x14 bytes per entry, name id at +4) for the last entry whose name id equals the posture id (an index of 0 counts as not found); for a found entry it builds a 0x44-byte action request {action 0xa, byte +0x21 = the boolean, byte +0x22 = table entry byte +0xe, dword +0x1c = posture id} and calls function_49f24c(unit, request); when that returns true it sets byte +0x166 of the command script element to 1. Nothing is written to the thread record. Returns nothing.
- Evidence: V

### cs_posture_set (slot 808)
- Slot: 808 (table entry 0xa197a0)
- Returns: void
- Parameters: a0: ai, a1: string_id, a2: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1ac1f4 (539 bytes)
- Behavior: Command script native without a wait flag. On a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record and the arguments are the posture id (slot 0) and a boolean (slot 1); otherwise a0 is the AI reference, a1 the posture id and a2 the boolean. For each actor it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1). When the actor unit handle (+0x1c) is not -1 it searches the 54-entry posture table at RVA 0xa88020 (0x14 bytes per entry, name id at +4) for the last entry whose name id equals the posture id (an index of 0 counts as not found); for a found entry it builds a 0x44-byte action request {action 0xa, byte +0x21 = the boolean, byte +0x22 = table entry byte +0xe, dword +0x1c = posture id} and calls function_49f24c(unit, request); when that returns true it sets
  byte +0x166 of the command script element to 1. Nothing is written to the thread record. Returns nothing.
- Evidence: V

### cs_posture_exit (slot 809)
- Slot: 809 (table entry 0xa19760)
- Returns: void
- Parameters: none
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1ac410 (317 bytes)
- Behavior: Evaluates 0 argument(s). Iterates the actors of the 32-bit value at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_7211c8(the current actor); then stores 0 to field +0x166 of the command scripts element (thread-local +0x60 x0x1ec); then calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_7211c8(the current actor); then stores 0 to field +0x166 of the command scripts element (thread-local +0x60 x0x1ec); then calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_7211c8(the current actor); then stores 0 to field +0x166 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: actor (thread-local +0x8 x0xd00): reads +0x1c
  16-bit/32-bit | object record: reads +0x1b2 16-bit | command scripts (thread-local +0x60 x0x1ec): writes +0x166 byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_7211c8 (292 bytes): accesses actor (thread-local +0x8 x0xd00): reads +0x6 byte, +0x1c 32-bit, +0x328 16-bit, +0x524 32-bit; calls function_78932a,
  function_73c350, function_17f20, function_49f24c.
- Evidence: V

### cs_posture_exit (slot 810)
- Slot: 810 (table entry 0xa19710)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1ac410 (317 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the 32-bit value at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_7211c8(the current actor); then stores 0 to field +0x166 of the command scripts element (thread-local +0x60 x0x1ec); then calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_7211c8(the current actor); then stores 0 to field +0x166 of the command scripts element (thread-local +0x60 x0x1ec); then calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_7211c8(the current actor); then stores 0 to field +0x166 of the command scripts element (thread-local +0x60 x0x1ec). It then returns nothing (void). Inline state access: actor (thread-local +0x8 x0xd00): reads +0x1c
  16-bit/32-bit | object record: reads +0x1b2 16-bit | command scripts (thread-local +0x60 x0x1ec): writes +0x166 byte. function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_7211c8 (292 bytes): accesses actor (thread-local +0x8 x0xd00): reads +0x6 byte, +0x1c 32-bit, +0x328 16-bit, +0x524 32-bit; calls function_78932a,
  function_73c350, function_17f20, function_49f24c.
- Evidence: V

### cs_stow (slot 811)
- Slot: 811 (table entry 0xa194f0)
- Returns: void
- Parameters: a0: boolean
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1ac550 (223 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_721114(the current actor, a0 (8-bit), 1). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte
  +0x14; returns the element handle or -1. function_721114 (177 bytes): accesses actor (thread-local +0x8 x0xd00): reads +0x1c 32-bit, +0x35b byte, +0x35e byte; writes +0x35e byte | object record: reads +0x34a byte; calls function_48b3d0, function_4c6184.
- Evidence: V

### cs_stow (slot 812)
- Slot: 812 (table entry 0xa194a0)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1ac550 (223 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_721114(the current actor, a1 (8-bit), 1). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or
  -1. function_721114 (177 bytes): accesses actor (thread-local +0x8 x0xd00): reads +0x1c 32-bit, +0x35b byte, +0x35e byte; writes +0x35e byte | object record: reads +0x34a byte; calls function_48b3d0, function_4c6184.
- Evidence: V

### cs_teleport (slot 813)
- Slot: 813 (table entry 0xa19450)
- Returns: void
- Parameters: a0: point_reference, a1: point_reference
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1ac630 (225 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_7100f0(the current actor, a second argument the callee does not read, a0, a1). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1,
  second argument) and clears its byte +0x14; returns the element handle or -1. function_7100f0 (695 bytes): returns early when the current actor == -1; accesses actor (thread-local +0x8 x0xd00): reads +0x1c 32-bit, +0x345 byte; touches data at 0xc1a230, 0x98fa7c, 0x98fa94; calls function_6b2950, function_710e54, function_91a14a, function_91a192, function_1fcfc, function_472060, function_186b4, function_1fb20 and 4 more.
- Evidence: V

### cs_teleport (slot 814)
- Slot: 814 (table entry 0xa19400)
- Returns: void
- Parameters: a0: ai, a1: point_reference, a2: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_1ac630 (225 bytes)
- Behavior: Evaluates 3 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_7100f0(the current actor, a second argument the callee does not read, a1, a2). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte
  +0x14; returns the element handle or -1. function_7100f0 (695 bytes): returns early when the current actor == -1; accesses actor (thread-local +0x8 x0xd00): reads +0x1c 32-bit, +0x345 byte; touches data at 0xc1a230, 0x98fa7c, 0x98fa94; calls function_6b2950, function_710e54, function_91a14a, function_91a192, function_1fcfc, function_472060, function_186b4, function_1fb20 and 4 more.
- Evidence: V

### cs_stop_custom_animation (slot 815)
- Slot: 815 (table entry 0xa195e0)
- Returns: void
- Parameters: none
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1ac714 (295 bytes)
- Behavior: Does not evaluate any argument. When the running thread is a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of its record; otherwise the reference is -1 and nothing is iterated, so the ai call form has no effect outside threads of script type 3. For each actor of the reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1), reads the unit handle (+0x1c) and, when the unit current action record starts with action id 0xb (the word at +0x1b2 of the unit record gives the record offset), calls function_49f210(unit, 2) to start unit action 2. Returns nothing.
- Evidence: V

### cs_stop_custom_animation (slot 816)
- Slot: 816 (table entry 0xa19590)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1ac714 (295 bytes)
- Behavior: Does not evaluate any argument. When the running thread is a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of its record; otherwise the reference is -1 and nothing is iterated, so the ai call form has no effect outside threads of script type 3. For each actor of the reference it finds or creates the command script element with function_6b02c8(actor, script thread handle, 1), reads the unit handle (+0x1c) and, when the unit current action record starts with action id 0xb (the word at +0x1b2 of the unit record gives the record offset), calls function_49f210(unit, 2) to start unit action 2. Returns nothing.
- Evidence: V

### cs_stop_sound (slot 817)
- Slot: 817 (table entry 0xa19540)
- Returns: void
- Parameters: a0: sound
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1ac83c (199 bytes)
- Behavior: Evaluates 1 argument(s). Iterates the actors of the AI reference at +0x24 of the running thread record (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_bd368(a0). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element
  handle or -1. function_bd368 (179 bytes): Stops a scripted sound: for a handle other than -1 logs through function_c1aec, finds the impulse slot with function_bc12c and, if found, clears its three dwords to -1 after function_b947c on the sound reference (table at thread-local +0x3a0, 16-byte records); then, when function_b95b0 and function_3aab9c are true and function_58eec is false, submits simulation event 0x3c with the handle via function_3cd020; returns early when a0 == -1.
- Evidence: V

### cs_stop_sound (slot 818)
- Slot: 818 (table entry 0xa192c0)
- Returns: void
- Parameters: a0: ai, a1: sound
- Kind: normal
- Status: implemented
- Evaluator: function_1ac83c (199 bytes)
- Behavior: Evaluates 2 argument(s). Iterates the actors of the AI reference a0 (see AI references above); for each actor it calls function_6b02c8(the current actor, the script thread handle, 1); then calls function_bd368(a1). It then returns nothing (void). function_6b02c8 (223 bytes): Finds or creates the command script element of an actor for a script thread: the actor index is the low 16 bits of the first argument; the element list head is the dword at actor +0xce0 (actor array thread-local +0x8, 0xd00 bytes); the list is walked through the link field +0x10 of the command script elements (thread-local +0x60, 0x1ec bytes) looking for one whose dword +0xc equals the second argument; when none is found and the third argument is non-zero it creates one with function_6b0808(actor, -1, second argument) and clears its byte +0x14; returns the element handle or -1. function_bd368 (179
  bytes): Stops a scripted sound: for a handle other than -1 logs through function_c1aec, finds the impulse slot with function_bc12c and, if found, clears its three dwords to -1 after function_b947c on the sound reference (table at thread-local +0x3a0, 16-byte records); then, when function_b95b0 and function_3aab9c are true and function_58eec is false, submits simulation event 0x3c with the handle via function_3cd020; returns early when a1 == -1.
- Evidence: V

### cs_player_melee (slot 819)
- Slot: 819 (table entry 0xa19270)
- Returns: void
- Parameters: a0: long
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1ac904 (428 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is forced to 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 the wait flag and the remaining arguments start at slot 2. For each actor of the AI reference it finds or creates the actor command script element with function_6b02c8(actor, script thread handle, 1); when the value a is in 1..3 and the actor unit handle (+0x1c) is not -1 it builds a 0x44-byte action request {action 0x3e, byte +4 = min(a, 3), dword +8 = -1} and calls function_49f24c(unit, request). When the wait flag is set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_player_melee (slot 820)
- Slot: 820 (table entry 0xa19220)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: long
- Kind: normal
- Status: implemented
- Evaluator: function_1ac904 (428 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is forced to 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 the wait flag and the remaining arguments start at slot 2. For each actor of the AI reference it finds or creates the actor command script element with function_6b02c8(actor, script thread handle, 1); when the value a is in 1..3 and the actor unit handle (+0x1c) is not -1 it builds a 0x44-byte action request {action 0x3e, byte +4 = min(a, 3), dword +8 = -1} and calls function_49f24c(unit, request). When the wait flag is set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_melee_direction (slot 821)
- Slot: 821 (table entry 0xa193b0)
- Returns: void
- Parameters: a0: long
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1acab0 (386 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is forced to 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 the wait flag and the remaining arguments start at slot 2. For each actor of the AI reference it finds or creates the actor command script element with function_6b02c8(actor, script thread handle, 1); when the direction value a is at most 5 it creates a command slot of type 0x1a with function_6b0648(element, 0x1a, 1) and, when the actor unit handle (+0x1c) is not -1, builds a 0x44-byte action request {action 0x2d, word +0xc = a} and calls function_49f24c(unit, request). When the wait flag is set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_melee_direction (slot 822)
- Slot: 822 (table entry 0xa19360)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: long
- Kind: normal
- Status: implemented
- Evaluator: function_1acab0 (386 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is forced to 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 the wait flag and the remaining arguments start at slot 2. For each actor of the AI reference it finds or creates the actor command script element with function_6b02c8(actor, script thread handle, 1); when the direction value a is at most 5 it creates a command slot of type 0x1a with function_6b0648(element, 0x1a, 1) and, when the actor unit handle (+0x1c) is not -1, builds a 0x44-byte action request {action 0x2d, word +0xc = a} and calls function_49f24c(unit, request). When the wait flag is set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_smash_direction (slot 823)
- Slot: 823 (table entry 0xa19310)
- Returns: void
- Parameters: a0: long
- Kind: command script (cs_)
- Status: implemented
- Evaluator: function_1acc34 (421 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is forced to 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 the wait flag and the remaining arguments start at slot 2. For each actor of the AI reference it finds or creates the actor command script element with function_6b02c8(actor, script thread handle, 1); when the actor unit handle (+0x1c) is not -1 it creates a command slot of type 0x1b with function_6b0648(element, 0x1b, 1) and builds a 0x44-byte action request {action 0x29, byte +6 = 1, word +4 = a when a is positive and below 2, 2 when a is 2 or more, 0 otherwise, dword +8 = -1} and calls function_49f24c(unit, request). When the wait flag is set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### cs_smash_direction (slot 824)
- Slot: 824 (table entry 0xa190e0)
- Returns: void
- Parameters: a0: ai, a1: boolean, a2: long
- Kind: normal
- Status: implemented
- Evaluator: function_1acc34 (421 bytes)
- Behavior: Command script native with two call forms handled by one evaluator: on a thread whose script type byte (+0x20 of the thread record) equals 3 the AI reference is the dword at +0x24 of that record, the wait flag is forced to 1 and the arguments start at slot 0; otherwise a0 is the AI reference, a1 the wait flag and the remaining arguments start at slot 2. For each actor of the AI reference it finds or creates the actor command script element with function_6b02c8(actor, script thread handle, 1); when the actor unit handle (+0x1c) is not -1 it creates a command slot of type 0x1b with function_6b0648(element, 0x1b, 1) and builds a 0x44-byte action request {action 0x29, byte +6 = 1, word +4 = a when a is positive and below 2, 2 when a is 2 or more, 0 otherwise, dword +8 = -1} and calls function_49f24c(unit, request). When the wait flag is set it stores 0xfffffffd at +0xc and the AI reference at +0x24 of the running thread record. Returns nothing.
- Evidence: V

### camera_control
- Slot: 825 (table entry 0xa19090)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1acddc (68 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_c4c94(a0 (8-bit)); then returns nothing (void). function_c4c94 (264 bytes): Scripted camera control switch: toggles the byte at thread-local +0x5a0; when it changes loops over the four 0x1ac-byte entries of the director block (thread-local +0x188): when enabling calls function_c5834(entry, 6, 0.0), when disabling restores each entry through function_c4dcc and function_c68f4 after validating its saved object handle with function_137c4 on the object array.
- Evidence: V

### camera_set
- Slot: 826 (table entry 0xa19040)
- Returns: void
- Parameters: a0: cutscene_camera_point, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_1ace20 (77 bytes)
- Behavior: Evaluates 2 arguments (a camera point and a 16-bit value). Calls function_1d7e20(low 16 bits of a0, low 16 bits of a1, -1). Returns nothing.
- Evidence: V

### camera_set_relative
- Slot: 827 (table entry 0xa191d0)
- Returns: void
- Parameters: a0: cutscene_camera_point, a1: short, a2: object
- Kind: normal
- Status: implemented
- Evaluator: function_1ace70 (77 bytes)
- Behavior: Evaluates 3 argument(s). When all arguments are available it calls function_1d7e20(a0 (16-bit), a1 (16-bit), a2); then returns nothing (void). function_1d7e20 (129 bytes): touches data at 0xc1a230; calls function_1d7ea4.
- Evidence: V

### camera_set_animation
- Slot: 828 (table entry 0xa19180)
- Returns: void
- Parameters: a0: animation_graph, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1acec0 (106 bytes)
- Behavior: Evaluates 2 arguments (an animation graph and an animation id). Calls function_1d7a00(a0, a1, -1, -1, speed constant, loop byte 0, offset 0.0). Returns nothing.
- Evidence: V

### camera_set_animation_relative
- Slot: 829 (table entry 0xa19130)
- Returns: void
- Parameters: a0: animation_graph, a1: string_id, a2: unit, a3: cutscene_flag
- Kind: normal
- Status: implemented
- Evaluator: function_1acf2c (108 bytes)
- Behavior: Evaluates 4 arguments (graph, animation id, unit, flag). Calls function_1d7a00(a0, a1, a2, low 16 bits of a3, speed constant, loop byte 0, offset 0.0). Returns nothing.
- Evidence: V

### camera_set_animation_with_speed
- Slot: 830 (table entry 0xa18f50)
- Returns: void
- Parameters: a0: animation_graph, a1: string_id, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1acf98 (103 bytes)
- Behavior: Evaluates 3 arguments (graph, animation id, speed). Calls function_1d7a00(a0, a1, -1, -1, a2 as the speed, loop byte 0, offset 0.0). Returns nothing.
- Evidence: V

### camera_set_animation_relative_with_speed
- Slot: 831 (table entry 0xa18f00)
- Returns: void
- Parameters: a0: animation_graph, a1: string_id, a2: unit, a3: cutscene_flag, a4: real
- Kind: normal
- Status: implemented
- Evaluator: function_1ad000 (105 bytes)
- Behavior: Evaluates 5 arguments (graph, animation id, unit, flag, speed). Calls function_1d7a00(a0, a1, a2, low 16 bits of a3, a4 as the speed, loop byte 0, offset 0.0). Returns nothing.
- Evidence: V

### camera_set_animation_relative_with_speed_loop
- Slot: 832 (table entry 0xa18eb0)
- Returns: void
- Parameters: a0: animation_graph, a1: string_id, a2: unit, a3: cutscene_flag, a4: real, a5: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1ad06c (107 bytes)
- Behavior: Evaluates 6 arguments (graph, animation id, unit, flag, speed, loop byte). Calls function_1d7a00(a0, a1, a2, low 16 bits of a3, a4, a5 as the loop byte, offset 0.0). Returns nothing.
- Evidence: V

### camera_set_animation_relative_with_speed_loop_offset
- Slot: 833 (table entry 0xa18ff0)
- Returns: void
- Parameters: a0: animation_graph, a1: string_id, a2: unit, a3: cutscene_flag, a4: real, a5: boolean, a6: real
- Kind: normal
- Status: implemented
- Evaluator: function_1ad0d8 (109 bytes)
- Behavior: Evaluates 7 arguments (graph, animation id, unit, flag, speed, loop byte, offset). Calls function_1d7a00(a0, a1, a2, low 16 bits of a3, a4, a5, a6 as the offset). Returns nothing.
- Evidence: V

### camera_predict_resources_at_frame
- Slot: 834 (table entry 0xa18fa0)
- Returns: void
- Parameters: a0: animation_graph, a1: string_id, a2: unit, a3: cutscene_flag, a4: long
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: The evaluator is the shared stub function_199364. It evaluates its 5 argument(s) and sets the result to 0; no game state is read or written.
- Evidence: V

### camera_predict_resources_at_point
- Slot: 835 (table entry 0xa18d40)
- Returns: void
- Parameters: a0: cutscene_camera_point
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: The evaluator is the shared stub function_199364. It evaluates its 1 argument(s) and sets the result to 0; no game state is read or written.
- Evidence: V

### camera_set_first_person
- Slot: 836 (table entry 0xa18cf0)
- Returns: void
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_1ad148 (113 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it if a0 != -1 then stores 4 to field +0x2 of the scripted camera globals element (thread-local +0x58 block/header); then stores 1 to field +0x1 of the scripted camera globals element (thread-local +0x58 block/header); then stores a0 to field +0x3c of the scripted camera globals element (thread-local +0x58 block/header); then returns nothing (void). When a0 == -1 the remaining steps are skipped. Inline state access: scripted camera globals (thread-local +0x58 block/header): writes +0x1 byte, +0x2 16-bit, +0x3c 32-bit.
- Evidence: V

### camera_set_cinematic
- Slot: 837 (table entry 0xa18cb0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1ad1bc
- Behavior: Takes no argument. Reinitialises the scripted camera block (thread-local +0x58): word +2 = 5, byte +1 = 1, dword +0x40 = -1, dword +0x64 = 0, bytes +0x58 and +0x60 = 0, dword +0xe8 = 0, qword +0xec = 0, and copies constant blocks into +0xbc (8 bytes), +0xc4 (4 bytes), +0xc8 (16 bytes) and +0xd8 (16 bytes). Returns nothing.
- Evidence: V

### camera_set_cinematic_scene
- Slot: 838 (table entry 0xa18e60)
- Returns: void
- Parameters: a0: cinematic_scene_definition, a1: long, a2: cutscene_flag
- Kind: normal
- Status: implemented
- Evaluator: function_1ad244 (76 bytes)
- Behavior: Evaluates 3 argument(s). When all arguments are available it calls function_1d7bd0(a0, a1, a2 (16-bit)); then returns nothing (void). function_1d7bd0 (247 bytes): returns early when a0 == -1; accesses scripted camera globals (thread-local +0x58 block/header): reads +0x2 16-bit; writes +0x1 byte, +0x2 16-bit, +0x40 32-bit, +0x44 32-bit, +0x48 32-bit, +0x4c 32-bit, +0x54 32-bit, +0x58 byte, +0x60 byte, +0x64 32-bit, +0xb0 64-bit, +0xb8 32-bit; touches data at 0xc1a600, 0x98faf8.
- Evidence: V

### camera_place_relative
- Slot: 839 (table entry 0xa18e10)
- Returns: void
- Parameters: a0: object
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: The evaluator is the shared 9-byte stub function_86cbc. It evaluates no argument and sets the result to 0, so the call has no effect.
- Evidence: V

### camera_place_worldspace
- Slot: 840 (table entry 0xa18dd0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: The evaluator is the shared 9-byte stub function_86cbc. It evaluates no argument and sets the result to 0, so the call has no effect.
- Evidence: V

### camera_time
- Slot: 841 (table entry 0xa18d90)
- Returns: short
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1ad290 (89 bytes)
- Behavior: When all arguments are available it calls function_81b08(); then returns the low 16 bits of the result of function_81b08. Inline state access: scripted camera globals (thread-local +0x58 block/header): reads +0x14 32-bit | game time globals (T) (thread-local +0xa0 block/header): reads +0x8 32-bit. function_81b08 (52 bytes): no thread-local or argument access found.
- Evidence: V

### camera_set_field_of_view
- Slot: 842 (table entry 0xa18b70)
- Returns: void
- Parameters: a0: real, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_1ad2ec (220 bytes)
- Behavior: Evaluates 2 arguments (a field of view as a float and a tick count). Works on the scripted camera block (thread-local +0x58): when the float at +0xc equals a constant it first stores the result of function_c8554(true) there; it then stores the current scripted field of view from function_1da498 at +0xc, 0 at +4, a1 divided by a constant (ticks to seconds) at +8 and a0 multiplied by a constant at +0x10. When function_caff4 rejects the new value (not finite or out of range) the two qwords at +4 and +0xc are cleared. Returns nothing.
- Evidence: V

### cinematic_camera_set_easing_in
- Slot: 843 (table entry 0xa18b20)
- Returns: void
- Parameters: a0: real, a1: real, a2: real, a3: real, a4: real, a5: real
- Kind: normal
- Status: implemented
- Evaluator: function_1ad3c8 (107 bytes)
- Behavior: Evaluates 6 reals. Calls function_1da524(a0, a1, a2, a3, a4, a5) with the first four in xmm0 to xmm3 and the last two on the stack. Returns nothing.
- Evidence: V

### cinematic_camera_set_easing_out
- Slot: 844 (table entry 0xa18c60)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: implemented
- Evaluator: function_1ad434 (70 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_1da6b8() and float in xmm0=a0 (float); then returns nothing (void). function_1da6b8 (244 bytes): accesses scripted camera globals (thread-local +0x58 block/header): writes +0x4 32-bit, +0x6c 16-bit, +0x70 32-bit, +0xa0 64-bit, +0xa8 32-bit; touches data at 0x98faf8; calls function_53fcc, function_c84ec, function_a7bec, function_a8354, function_5cc74.
- Evidence: V

### cinematic_print
- Slot: 845 (table entry 0xa18c10)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: The evaluator is the shared stub function_199364. It evaluates its 1 argument(s) and sets the result to 0; no game state is read or written.
- Evidence: V

### camera_set_pan
- Slot: 846 (table entry 0xa18bc0)
- Returns: void
- Parameters: a0: cutscene_camera_point, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_1ad47c (73 bytes)
- Behavior: Evaluates 2 argument(s). When all arguments are available it calls function_1d8178(a0 (16-bit), a1 (16-bit)); then returns nothing (void). function_1d8178 (338 bytes): accesses scripted camera globals (thread-local +0x58 block/header): writes +0x1 byte, +0x2 16-bit, +0x40 64-bit, +0x48 32-bit, +0x5c 32-bit | game time globals (T) (thread-local +0xa0 block/header): reads +0xc 32-bit; touches data at 0xc1a230; calls function_a7f7c, function_a8354, function_1d727c, function_1d7e20.
- Evidence: V

### camera_pan
- Slot: 847 (table entry 0xa18990)
- Returns: void
- Parameters: a0: cutscene_camera_point, a1: cutscene_camera_point, a2: short, a3: short, a4: real, a5: short, a6: real
- Kind: normal
- Status: implemented
- Evaluator: function_1ad4c8 (114 bytes)
- Behavior: Evaluates 7 arguments (two camera points, two 16-bit values, a real, a 16-bit value, a real). Calls function_1d82cc(low 16 bits of a0, a1, a2, a3, a4, a5, a6) with a0 to a3 as 16-bit values and a4, a5, a6 as further arguments. Returns nothing.
- Evidence: V

### debug_camera_save
- Slot: 848 (table entry 0xa18950)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: The evaluator is the shared 9-byte stub function_86cbc. It evaluates no argument and sets the result to 0, so the call has no effect.
- Evidence: V

### debug_camera_load
- Slot: 849 (table entry 0xa18910)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: The evaluator is the shared 9-byte stub function_86cbc. It evaluates no argument and sets the result to 0, so the call has no effect.
- Evidence: V

### debug_camera_save_name
- Slot: 850 (table entry 0xa188c0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: The evaluator is the shared 9-byte stub function_86cbc. It evaluates no argument and sets the result to 0, so the call has no effect.
- Evidence: V

### debug_camera_load_name
- Slot: 851 (table entry 0xa18ad0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: The evaluator is the shared 9-byte stub function_86cbc. It evaluates no argument and sets the result to 0, so the call has no effect.
- Evidence: V

### debug_camera_save_simple_name
- Slot: 852 (table entry 0xa18a80)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: The evaluator is the shared 9-byte stub function_86cbc. It evaluates no argument and sets the result to 0, so the call has no effect.
- Evidence: V

### debug_camera_load_simple_name
- Slot: 853 (table entry 0xa18a30)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: The evaluator is the shared 9-byte stub function_86cbc. It evaluates no argument and sets the result to 0, so the call has no effect.
- Evidence: V

### debug_camera_load_text
- Slot: 854 (table entry 0xa189e0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: The evaluator is the shared 9-byte stub function_86cbc. It evaluates no argument and sets the result to 0, so the call has no effect.
- Evidence: V

### director_debug_camera
- Slot: 855 (table entry 0xa18750)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: The evaluator is the shared 9-byte stub function_86cbc. It evaluates no argument and sets the result to 0, so the call has no effect.
- Evidence: V

### director_print_camera_transform
- Slot: 856 (table entry 0xa18700)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: The evaluator is the shared 9-byte stub function_86cbc. It evaluates no argument and sets the result to 0, so the call has no effect.
- Evidence: V

### director_print_deterministic_camera_transform
- Slot: 857 (table entry 0xa186b0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: The evaluator is the shared 9-byte stub function_86cbc. It evaluates no argument and sets the result to 0, so the call has no effect.
- Evidence: V

### game_difficulty_get
- Slot: 858 (table entry 0xa18670)
- Returns: game_difficulty
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1ad53c (40 bytes)
- Behavior: Takes no arguments. Calls function_58afc and returns its result, except that a result of 1 or less (signed compare) is returned as 1, so the value is never below 1. function_58afc (60 bytes): Returns the signed byte at game globals (thread-local +0x48) +0x1e4 when function_58b5c reports a campaign or survival game, otherwise 1.
- Evidence: V

### game_difficulty_get_real
- Slot: 859 (table entry 0xa18880)
- Returns: game_difficulty
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1ad564 (26 bytes)
- Behavior: When all arguments are available it calls function_58afc(); then returns the low 32 bits of the result of function_58afc. function_58afc (60 bytes): Returns the signed byte at game globals (thread-local +0x48) +0x1e4 when function_58b5c reports a campaign or survival game, otherwise 1.
- Evidence: V

### game_insertion_point_get
- Slot: 860 (table entry 0xa18840)
- Returns: short
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1ad580 (78 bytes)
- Behavior: Takes no argument. When function_58b5c reports a campaign or survival game, returns the word at +0x1f0 of the game globals (thread-local +0x48); otherwise 0.
- Evidence: V

### pvs_set_object
- Slot: 861 (table entry 0xa187f0)
- Returns: void
- Parameters: a0: object
- Kind: normal
- Status: implemented
- Evaluator: function_1ad5d0 (132 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it if a0 != -1 then stores 1 to field +0x1f0d6 of the game globals (GS) element (thread-local +0x48 block/header); then stores a0 to field +0x1f0d8 of the game globals (GS) element (thread-local +0x48 block/header); then returns nothing (void). When a0 == -1 it instead stores 0 to field +0x1f0d6 of the game globals (GS) element (thread-local +0x48 block/header). Inline state access: game globals (GS) (thread-local +0x48 block/header): writes +0x1f0d6 16-bit, +0x1f0d8 32-bit.
- Evidence: V

### pvs_set_camera
- Slot: 862 (table entry 0xa187a0)
- Returns: void
- Parameters: a0: cutscene_camera_point
- Kind: normal
- Status: implemented
- Evaluator: function_1ad654 (69 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_5942c(a0 (16-bit)); then returns nothing (void). function_5942c (177 bytes): Scripted visibility-camera setter: writes the word at game globals (thread-local +0x48) +0x1f0d6 as 0 when the point index (low 16 bits of a0) is -1 or the table lookup through function_145c8 yields -1, otherwise as 2 together with the looked-up word at +0x1f0d8.
- Evidence: V

### pvs_clear
- Slot: 863 (table entry 0xa18500)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1ad69c
- Behavior: When all arguments are available it stores 0 to field +0x1f0d6 of the game globals (GS) element (thread-local +0x48 block/header); then returns nothing (void). Inline state access: game globals (GS) (thread-local +0x48 block/header): writes +0x1f0d6 16-bit.
- Evidence: V

### pvs_reset
- Slot: 864 (table entry 0xa184c0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: The evaluator is the shared 9-byte stub function_86cbc. It evaluates no argument and sets the result to 0, so the call has no effect.
- Evidence: V

### players_unzoom_all
- Slot: 865 (table entry 0xa18480)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1ad6d0 (135 bytes)
- Behavior: Takes no argument. For each of the four local player entries (0x180 bytes each) of the player control block (thread-local +0xd8) it writes -1 to the word at +0xc6 and 0 to the byte at +0x1d4. Returns nothing.
- Evidence: V

### player_enable_input
- Slot: 866 (table entry 0xa18430)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1ad758 (98 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it stores flag (low 8 bits) to field +0x0 of the players globals element (thread-local +0x130 block/header); then returns nothing (void). Inline state access: players globals (thread-local +0x130 block/header): writes +0x0 byte.
- Evidence: V

### player_disable_movement
- Slot: 867 (table entry 0xa18620)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1ad7bc (95 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it stores a0 (8-bit) to field +0x1 of the players globals element (thread-local +0x130 block/header); then returns nothing (void). Inline state access: players globals (thread-local +0x130 block/header): writes +0x1 byte.
- Evidence: V

### player_disable_weapon_pickup
- Slot: 868 (table entry 0xa185d0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1ad81c (95 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it stores a0 (8-bit) to field +0x2 of the players globals element (thread-local +0x130 block/header); then returns nothing (void). Inline state access: players globals (thread-local +0x130 block/header): writes +0x2 byte.
- Evidence: V

### player_night_vision_on
- Slot: 869 (table entry 0xa18590)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1ad87c (126 bytes)
- Behavior: Takes no argument. Iterates the players array (thread-local +0x18) with function_1381c and, for the first player whose unit handle (dword +0x28) leads function_49ac4 to return true (bit 12 of dword +0x1c4 of the unit record), returns true; false otherwise.
- Evidence: V

### unit_night_vision_on
- Slot: 870 (table entry 0xa18540)
- Returns: boolean
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_1ad8fc (80 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_49ac4(a0); then returns the low 8 bits of the result of function_49ac4. function_49ac4 (81 bytes): Returns bit 12 of the dword at +0x1c4 of the object record for the object handle a0 (object array at thread-local +0x10, record pointer at element +0x10; salt not checked); returns 0 for handle -1; returns early when a0 == -1.
- Evidence: V

### player_active_camouflage_on
- Slot: 871 (table entry 0xa182f0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1ad94c (201 bytes)
- Behavior: Takes no argument. Iterates the players array (thread-local +0x18) with function_1381c and returns true for the first player that has a unit (dword +0x28 not -1) whose object record float at +0x49c is greater than a constant; false otherwise.
- Evidence: V

### player_camera_control
- Slot: 872 (table entry 0xa182a0)
- Returns: boolean
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1ada18 (178 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it returns a0 (8-bit). When 1 == -1 the remaining steps are skipped. When 2 == -1 the remaining steps are skipped. When 3 != -1 the remaining steps are skipped.
- Evidence: V

### player_action_test_reset
- Slot: 873 (table entry 0xa18260)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1adacc
- Behavior: Takes no argument. For each of the four 0x20-byte entries of the player control block (thread-local +0xd8) it clears the dwords at +0 and +4. Returns nothing.
- Evidence: V

### player_action_test_primary_trigger
- Slot: 874 (table entry 0xa18220)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1adb34 (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(3); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_grenade_trigger
- Slot: 875 (table entry 0xa183f0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1adb60 (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(5); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_vision_trigger
- Slot: 876 (table entry 0xa183b0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1adb8c (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(0x18); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_rotate_weapons
- Slot: 877 (table entry 0xa18370)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1adbb8 (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(7); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_rotate_grenades
- Slot: 878 (table entry 0xa18330)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1adbe4 (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(8); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_jump
- Slot: 879 (table entry 0xa180e0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1adc10 (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(9); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_equipment
- Slot: 880 (table entry 0xa180a0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1adc3c (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(0xa); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_context_primary
- Slot: 881 (table entry 0xa18060)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1adc68 (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(0xb); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_vehicle_trick_primary
- Slot: 882 (table entry 0xa18020)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1adc94 (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(0xc); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_vehicle_trick_secondary
- Slot: 883 (table entry 0xa181e0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1adcc0 (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(0xd); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_melee
- Slot: 884 (table entry 0xa181a0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1adcec (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(6); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_action
- Slot: 885 (table entry 0xa18160)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1add18 (55 bytes)
- Behavior: When all arguments are available it calls function_65598(0); then calls function_65538(0); then calls function_655f8(0); then returns the low 8 bits of the result of function_655f8. function_65598 (94 bytes): Sets bit a0 in the dword at +4 of each of the four 0x20-byte entries of the player control block (thread-local +0xd8). function_65538 (94 bytes): Sets bit a0 in the dword at +8 of each of the four 0x20-byte entries of the player control block (thread-local +0xd8). function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_accept
- Slot: 886 (table entry 0xa18120)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1add50 (64 bytes)
- Behavior: When all arguments are available it calls function_65598(1); then calls function_65538(1); then calls function_655f8(1); then returns the low 8 bits of the result of function_655f8. function_65598 (94 bytes): Sets bit a0 in the dword at +4 of each of the four 0x20-byte entries of the player control block (thread-local +0xd8). function_65538 (94 bytes): Sets bit a0 in the dword at +8 of each of the four 0x20-byte entries of the player control block (thread-local +0xd8). function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_cancel
- Slot: 887 (table entry 0xa17ee0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1add90 (64 bytes)
- Behavior: When all arguments are available it calls function_65598(2); then calls function_65538(2); then calls function_655f8(2); then returns the low 8 bits of the result of function_655f8. function_65598 (94 bytes): Sets bit a0 in the dword at +4 of each of the four 0x20-byte entries of the player control block (thread-local +0xd8). function_65538 (94 bytes): Sets bit a0 in the dword at +8 of each of the four 0x20-byte entries of the player control block (thread-local +0xd8). function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_look_relative_up
- Slot: 888 (table entry 0xa17ea0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1addd0 (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(0xe); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_look_relative_down
- Slot: 889 (table entry 0xa17e60)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1addfc (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(0xf); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_look_relative_left
- Slot: 890 (table entry 0xa17e20)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1ade28 (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(0x10); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_look_relative_right
- Slot: 891 (table entry 0xa17fe0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1ade54 (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(0x11); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_look_relative_all_directions
- Slot: 892 (table entry 0xa17fa0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1ade80 (47 bytes)
- Behavior: When all arguments are available it calls function_6563c(0xe, 0x11); then returns the low 8 bits of the result of function_6563c. function_6563c (124 bytes): Returns true when any bit in the range a0..a1 is set in any of the 16 action-flag dwords at thread-local +0x560.
- Evidence: V

### player_action_test_move_relative_all_directions
- Slot: 893 (table entry 0xa17f60)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1adeb0 (47 bytes)
- Behavior: When all arguments are available it calls function_6563c(0x12, 0x15); then returns the low 8 bits of the result of function_6563c. function_6563c (124 bytes): Returns true when any bit in the range a0..a1 is set in any of the 16 action-flag dwords at thread-local +0x560.
- Evidence: V

### player_action_test_cinematic_skip
- Slot: 894 (table entry 0xa17f20)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1adee0 (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(0x1b); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_start
- Slot: 895 (table entry 0xa17cc0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1adf0c (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(0x16); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_back
- Slot: 896 (table entry 0xa17c80)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1adf38 (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(0x17); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_dpad_up
- Slot: 897 (table entry 0xa17c40)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1adf64 (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(0x1c); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_dpad_down
- Slot: 898 (table entry 0xa17c00)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1adf90 (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(0x1d); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_dpad_left
- Slot: 899 (table entry 0xa17de0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1adfbc (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(0x1e); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_dpad_right
- Slot: 900 (table entry 0xa17da0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1adfe8 (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(0x1f); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### unit_action_test_reset
- Slot: 901 (table entry 0xa17d50)
- Returns: void
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae014 (120 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it if a0 != -1 then calls function_53b5c(a0); then returns nothing (void). When a0 == -1 the remaining steps are skipped. function_53b5c (44 bytes): Player index to local player lookup: for a player handle other than -1 returns the dword at +0x74 + 4 * (low 16 bits of the handle) of the player mapping block (thread-local +0x158); returns -1 for handle -1.
- Evidence: V

### unit_action_test_primary_trigger
- Slot: 902 (table entry 0xa17d00)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae08c (85 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656b8(a0, 3); then returns the low 8 bits of the result of function_656b8. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_grenade_trigger
- Slot: 903 (table entry 0xa17a70)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae0e4 (85 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656b8(a0, 5); then returns the low 8 bits of the result of function_656b8. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_vision_trigger
- Slot: 904 (table entry 0xa17a20)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae13c (85 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656b8(a0, 0x18); then returns the low 8 bits of the result of function_656b8. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_rotate_weapons
- Slot: 905 (table entry 0xa179d0)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae194 (85 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656b8(a0, 7); then returns the low 8 bits of the result of function_656b8. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_rotate_grenades
- Slot: 906 (table entry 0xa17980)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae1ec (85 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656b8(a0, 8); then returns the low 8 bits of the result of function_656b8. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_jump
- Slot: 907 (table entry 0xa17bb0)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae244 (85 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656b8(a0, 9); then returns the low 8 bits of the result of function_656b8. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_equipment
- Slot: 908 (table entry 0xa17b60)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae29c (85 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656b8(a0, 0xa); then returns the low 8 bits of the result of function_656b8. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_context_primary
- Slot: 909 (table entry 0xa17b10)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae2f4 (85 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656b8(a0, 0xb); then returns the low 8 bits of the result of function_656b8. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_vehicle_trick_primary
- Slot: 910 (table entry 0xa17ac0)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae34c (85 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656b8(a0, 0xc); then returns the low 8 bits of the result of function_656b8. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_vehicle_trick_secondary
- Slot: 911 (table entry 0xa177f0)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae3a4 (85 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656b8(a0, 0xd); then returns the low 8 bits of the result of function_656b8. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_melee
- Slot: 912 (table entry 0xa177a0)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae3fc (85 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656b8(a0, 6); then returns the low 8 bits of the result of function_656b8. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_action
- Slot: 913 (table entry 0xa17750)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae454 (106 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6578c(a0, 0); then calls function_6573c(a0, 0); then calls function_656b8(a0, 0); then returns the low 8 bits of the result of function_656b8. function_6578c (78 bytes): For a player handle other than -1 maps it with function_53b5c; when the result is at most 3 sets bit a1 in the dword at +4 of that local player entry (0x20 bytes) of the player control block (thread-local +0xd8); returns early when a0 == -1. function_6573c (78 bytes): For a player handle other than -1 maps it with function_53b5c; when the result is at most 3 sets bit a1 in the dword at +8 of that local player entry (0x20 bytes) of the player control block (thread-local +0xd8); returns early when a0 == -1. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_accept
- Slot: 914 (table entry 0xa17700)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae4c0 (115 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6578c(a0, 1); then calls function_6573c(a0, 1); then calls function_656b8(a0, 1); then returns the low 8 bits of the result of function_656b8. function_6578c (78 bytes): For a player handle other than -1 maps it with function_53b5c; when the result is at most 3 sets bit a1 in the dword at +4 of that local player entry (0x20 bytes) of the player control block (thread-local +0xd8); returns early when a0 == -1. function_6573c (78 bytes): For a player handle other than -1 maps it with function_53b5c; when the result is at most 3 sets bit a1 in the dword at +8 of that local player entry (0x20 bytes) of the player control block (thread-local +0xd8); returns early when a0 == -1. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_cancel
- Slot: 915 (table entry 0xa17930)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae534 (115 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_6578c(a0, 2); then calls function_6573c(a0, 2); then calls function_656b8(a0, 2); then returns the low 8 bits of the result of function_656b8. function_6578c (78 bytes): For a player handle other than -1 maps it with function_53b5c; when the result is at most 3 sets bit a1 in the dword at +4 of that local player entry (0x20 bytes) of the player control block (thread-local +0xd8); returns early when a0 == -1. function_6573c (78 bytes): For a player handle other than -1 maps it with function_53b5c; when the result is at most 3 sets bit a1 in the dword at +8 of that local player entry (0x20 bytes) of the player control block (thread-local +0xd8); returns early when a0 == -1. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_look_relative_up
- Slot: 916 (table entry 0xa178e0)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae5a8 (85 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656b8(a0, 0xe); then returns the low 8 bits of the result of function_656b8. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_look_relative_down
- Slot: 917 (table entry 0xa17890)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae600 (85 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656b8(a0, 0xf); then returns the low 8 bits of the result of function_656b8. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_look_relative_left
- Slot: 918 (table entry 0xa17840)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae658 (85 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656b8(a0, 0x10); then returns the low 8 bits of the result of function_656b8. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_look_relative_right
- Slot: 919 (table entry 0xa17570)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae6b0 (85 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656b8(a0, 0x11); then returns the low 8 bits of the result of function_656b8. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_look_relative_all_directions
- Slot: 920 (table entry 0xa17520)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae708 (89 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656ec(a0, 0xe, 0x11); then returns the low 8 bits of the result of function_656ec. function_656ec (77 bytes): Returns true when any bit in the range a1..a2 is set in the action-flag dword for player a0 at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_move_relative_all_directions
- Slot: 921 (table entry 0xa174d0)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae764 (89 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656ec(a0, 0x12, 0x15); then returns the low 8 bits of the result of function_656ec. function_656ec (77 bytes): Returns true when any bit in the range a1..a2 is set in the action-flag dword for player a0 at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_cinematic_skip
- Slot: 922 (table entry 0xa17480)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae7c0 (85 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656b8(a0, 0x1b); then returns the low 8 bits of the result of function_656b8. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_start
- Slot: 923 (table entry 0xa176b0)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae818 (85 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656b8(a0, 0x16); then returns the low 8 bits of the result of function_656b8. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_back
- Slot: 924 (table entry 0xa17660)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae870 (85 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656b8(a0, 0x17); then returns the low 8 bits of the result of function_656b8. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_dpad_up
- Slot: 925 (table entry 0xa17610)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae8c8 (85 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656b8(a0, 0x1c); then returns the low 8 bits of the result of function_656b8. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_dpad_down
- Slot: 926 (table entry 0xa175c0)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae920 (85 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656b8(a0, 0x1d); then returns the low 8 bits of the result of function_656b8. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_dpad_left
- Slot: 927 (table entry 0xa17350)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae978 (85 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656b8(a0, 0x1e); then returns the low 8 bits of the result of function_656b8. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_action_test_dpad_right
- Slot: 928 (table entry 0xa17300)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1ae9d0 (85 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_656b8(a0, 0x1f); then returns the low 8 bits of the result of function_656b8. function_656b8 (50 bytes): Returns bit a1 of the action-flag dword for player a0 (index = low 16 bits of the handle) at thread-local +0x560; false for handle -1; returns early when a0 == -1.
- Evidence: V

### unit_confirm_message
- Slot: 929 (table entry 0xa172b0)
- Returns: void
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1aea28 (123 bytes)
- Behavior: Evaluates 1 argument (a player). When a0 is not -1 it maps the player to a local player index with function_53b5c and, when that is not -1, writes 1 to the byte at +0x10 of the 0x20-byte entry of the player control block (thread-local +0xd8) for that local player; there is no upper bound check on the local player index. Returns nothing.
- Evidence: V

### unit_confirm_cancel_message
- Slot: 930 (table entry 0xa17260)
- Returns: void
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1aeaa4 (123 bytes)
- Behavior: Evaluates 1 argument (a player). When a0 is not -1 it maps the player to a local player index with function_53b5c and, when that is not -1, writes 1 to the byte at +0x11 of the 0x20-byte entry of the player control block (thread-local +0xd8) for that local player; there is no upper bound check on the local player index. Returns nothing.
- Evidence: V

### unit_enable_soft_ping_region
- Slot: 931 (table entry 0xa17430)
- Returns: void
- Parameters: a0: unit, a1: damage_region, a2: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1aeb20 (152 bytes)
- Behavior: Evaluates 3 argument(s). When all arguments are available it returns nothing (void). When a2 (8-bit) is non-zero the remaining steps are skipped. When a1 > 0xa the remaining steps are skipped.
- Evidence: V

### unit_print_soft_ping_regions
- Slot: 932 (table entry 0xa173e0)
- Returns: void
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_1aebb8 (68 bytes)
- Behavior: Evaluates 1 argument(s). When all arguments are available it calls function_4899c0(a0); then returns nothing (void). function_4899c0 (236 bytes): returns early when a0 == -1; uses thread-local fields +0x10 (object); calls function_4739cc, function_11918.
- Evidence: V

### player0_looking_up
- Slot: 933 (table entry 0xa173a0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1aebfc (46 bytes)
- Behavior: Takes no argument. Returns true when the float returned by function_65e08 (the float at +0x98 of the control entry of the primary local player) is greater than or equal to a constant.
- Evidence: V

### player0_looking_down
- Slot: 934 (table entry 0xa17110)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1aec2c (53 bytes)
- Behavior: Takes no argument. Returns true when the negated float returned by function_65e08 (the float at +0x98 of the control entry of the primary local player) is greater than or equal to a constant.
- Evidence: V

### player_set_pitch
- Slot: 935 (table entry 0xa170c0)
- Returns: void
- Parameters: a0: player, a1: real, a2: long
- Kind: normal
- Status: implemented
- Evaluator: function_1aec64 (77 bytes)
- Behavior: Evaluates 3 argument(s). When all arguments are available it calls function_65e54(a0, ?, a2) and float in xmm1=a1 (float); then returns nothing (void). function_65e54 (182 bytes): Sets a pitch target on the local player entry selected by function_53b5c(a0): converts the float with a constant scale and clamp, stores the tick count (at least 1) at entry +0x1e8 and the per-tick step at +0x1e4, relative to the current value at +0x98.
- Evidence: V

### player_has_female_voice
- Slot: 936 (table entry 0xa17070)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1aecb4 (147 bytes)
- Behavior: Evaluates 1 argument (a player). Returns bit 0 of the byte at +0xd8 of the player element (players array thread-local +0x18, 0x490 bytes per element, indexed by the low 16 bits of the handle); false when a0 is -1.
- Evidence: V

### player_action_test_lookstick_forward
- Slot: 937 (table entry 0xa17030)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1aed48 (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(0x19); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### player_action_test_lookstick_backward
- Slot: 938 (table entry 0xa17220)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1aed74 (44 bytes)
- Behavior: When all arguments are available it calls function_655f8(0x1a); then returns the low 8 bits of the result of function_655f8. function_655f8 (67 bytes): Returns true when bit a0 is set in any of the 16 action-flag dwords at thread-local +0x560 (0x40-byte block).
- Evidence: V

### debug_teleport_player
- Slot: 939 (table entry 0xa171d0)
- Returns: void
- Parameters: a0: unit, a1: unit
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: The evaluator is the shared 9-byte stub function_86cbc. It evaluates no argument and sets the result to 0, so the call has no effect.
- Evidence: V

### scenario_content_status_reload
- Slot: 940 (table entry 0xa17190)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc
- Behavior: The evaluator is the shared 9-byte stub function_86cbc. It evaluates no argument and sets the result to 0, so the call has no effect.
- Evidence: V
