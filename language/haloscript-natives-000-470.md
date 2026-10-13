# HaloScript natives, slots 0 to 470

Part of the HaloScript reference (see the index). Each entry describes one slot of the function table at RVA 0xa28d40. Names, return types and parameter types come from the table strings; behavior is read from the evaluator code. Engine functions are given by address (function_RVA) and module globals as data_RVA. "Not determined" marks where the code was not followed far enough to say. Behavior lists the calls an evaluator can make, in order; a listed call may depend on the arguments or on state, and the text says so where that was checked. In Behavior, a0, a1, ... name the arguments in call order starting at zero.

## Groups

Entries follow the slot table order within each group, so the slot ranges of different groups overlap.

- Special forms and operators: 36 entries (slots 0 to 35)
- Language functions: 3 entries (slots 36 to 38)
- Debug and diagnostics: 52 entries (slots 39 to 270)
- Script and thread control: 7 entries (slots 50 to 186)
- Players: 9 entries (slots 55 to 63)
- Miscellaneous: 13 entries (slots 64 to 396)
- Object lists and volumes: 26 entries (slots 65 to 180)
- Effects, damage and physics: 24 entries (slots 80 to 246)
- Objects: 75 entries (slots 96 to 318)
- Rendering and interface: 47 entries (slots 205 to 358)
- Units, vehicles, weapons and devices: 105 entries (slots 271 to 395)
- AI and command scripts: 74 entries (slots 397 to 470)

## Special forms and operators

### begin
- Slot: 0 (table entry 0xa28d00)
- Returns: passthrough
- Parameters: EXPRESSIONS
- Kind: special form
- Status: implemented
- Evaluator: function_83004 (240 bytes)
- Behavior: Evaluates its sub-expressions in order, one after another, and returns the value of the last one. The compiler requires at least one sub-expression ("a begin statement block must contain at least one argument."). Every sub-expression except the last is compiled as a void slot, so its value cannot be used; the block takes the type of its last sub-expression. Evaluation can span several ticks: the thread keeps its place in the list between ticks (function_83004).
- Evidence: V

### begin_random
- Slot: 1 (table entry 0xa28cc0)
- Returns: passthrough
- Parameters: EXPRESSIONS
- Kind: special form
- Status: implemented
- Evaluator: function_833a4 (559 bytes)
- Behavior: Evaluates every sub-expression exactly once, in a random order, and returns the value of the last one evaluated. At most 32 sub-expressions are allowed (compile error otherwise). The evaluator clears a bit per sub-expression, then repeatedly draws a random start position and takes the first unused sub-expression at or after it (wrapping around). The random draw advances a 32-bit linear congruential state (multiplier 0x19660d, increment 0x3c6ef35f) stored in the thread-local block at offset 0x658 (function_833a4).
- Evidence: V

### begin_count
- Slot: 2 (table entry 0xa28b80)
- Returns: passthrough
- Parameters: EXPRESSIONS
- Kind: special form
- Status: implemented
- Evaluator: function_830f4 (685 bytes)
- Behavior: First argument is a long: how many of the following sub-expressions to evaluate (compile error when it is missing: "begin_count and begin_random_count need to specify how many expressions to evaluate"). The evaluator evaluates that many of the remaining sub-expressions (the order of the picks was not followed in detail). Returns the value of the last sub-expression evaluated. Shares function_830f4 with begin_random_count.
- Evidence: V

### begin_random_count
- Slot: 3 (table entry 0xa28b40)
- Returns: passthrough
- Parameters: EXPRESSIONS
- Kind: special form
- Status: implemented
- Evaluator: function_830f4 (685 bytes)
- Behavior: First argument is a long: how many of the following sub-expressions to evaluate. The sub-expressions to run are picked at random without repeats, using the same random state as begin_random (thread-local block offset 0x658). Returns the value of the last one evaluated. At most 32 sub-expressions. Shares function_830f4 with begin_count.
- Evidence: V

### if
- Slot: 4 (table entry 0xa28b00)
- Returns: passthrough
- Parameters: BOOLEAN THEN [ELSE]
- Kind: special form
- Status: implemented
- Evaluator: function_835d4 (354 bytes)
- Behavior: Evaluates the condition (a boolean). When it is true the then-branch is evaluated and its value returned; when it is false the else-branch is evaluated and returned. With no else-branch and a false condition the result is 0. The compiler requires exactly a condition, a then-branch and at most one else-branch ("i expected (if CONDITION THEN [ELSE])."). If the form has no explicit type, it takes the type of its then-branch; the else-branch is compiled to the same type (function_835d4).
- Evidence: V

### cond
- Slot: 5 (table entry 0xa28ac0)
- Returns: passthrough
- Parameters: (BOOLEAN1 RESULT1) [(BOOLEAN2 RESULT2) [...]]
- Kind: special form
- Status: special form without evaluator
- Evaluator: none
- Behavior: Takes pairs written (condition result). Each pair must have a condition and a result ("this argument to cond should be a condition/result pair", "this argument to cond needs a result."). The form has no evaluator (the evaluator pointer in its table entry is null); the compile step (function_194eb4 with function_194c74 for each pair) rewrites it, and the rewritten nodes are what run. The rewrite itself was not followed in detail.
- Evidence: slot entry 0xa28ac0; name from the entry string

### set
- Slot: 6 (table entry 0xa28c80)
- Returns: passthrough
- Parameters: VARIABLE_NAME EXPRESSION
- Kind: special form
- Status: implemented
- Evaluator: function_83738 (471 bytes)
- Behavior: Takes a variable name and an expression. Evaluates the expression, then stores the value into the variable (function_8707c): for an external global the value is also committed to the global's storage cell, for an object-typed variable the stored object is marked as referenced by scripts, and for an object list the list members are marked. Returns the stored value read back from the variable. Compile errors: "i expected a variable to set and a value.", "i expected an assignment value.", "this is not a valid global variable.", and a type mismatch error when the result cannot be passed where the variable type is expected. A debug path formats the stored value into a local text buffer ("[value unavailable]" when a type has no formatter); the text is not passed on by this evaluator. Setting variables is refused in some contexts ("it is illegal to set the value of variables in this context.").
- Evidence: V

### and
- Slot: 7 (table entry 0xa28c40)
- Returns: boolean
- Parameters: BOOLEANS
- Kind: special form
- Status: implemented
- Evaluator: function_83910 (350 bytes)
- Behavior: Evaluates its boolean sub-expressions left to right and stops at the first false one. Returns true only when every sub-expression is true (short-circuit). Needs at least 2 sub-expressions (function_83910, compile step function_195128).
- Evidence: V

### or
- Slot: 8 (table entry 0xa28c00)
- Returns: boolean
- Parameters: BOOLEANS
- Kind: special form
- Status: implemented
- Evaluator: function_83910 (350 bytes)
- Behavior: Evaluates its boolean sub-expressions left to right and stops at the first true one. Returns true when any sub-expression is true (short-circuit). Needs at least 2 sub-expressions (function_83910, compile step function_195128).
- Evidence: V

### +
- Slot: 9 (table entry 0xa28bc0)
- Returns: real
- Parameters: NUMBERS
- Kind: special form
- Status: implemented
- Evaluator: function_83a70 (523 bytes)
- Behavior: Adds its number arguments. All arguments are compiled as real, the sum is a 32-bit float. Needs at least 2 arguments ("the + call requires at least 2 arguments."). Shared evaluator function_83a70.
- Evidence: V

### -
- Slot: 10 (table entry 0xa28980)
- Returns: real
- Parameters: NUMBER NUMBER
- Kind: special form
- Status: implemented
- Evaluator: function_83a70 (523 bytes)
- Behavior: Subtracts the second and later arguments from the first. Arguments are compiled as real; the result is a 32-bit float. Needs at least 2 arguments. Shared evaluator function_83a70.
- Evidence: V

### *
- Slot: 11 (table entry 0xa28940)
- Returns: real
- Parameters: NUMBERS
- Kind: special form
- Status: implemented
- Evaluator: function_83a70 (523 bytes)
- Behavior: Multiplies its number arguments. Arguments are compiled as real; the result is a 32-bit float. Needs at least 2 arguments. Shared evaluator function_83a70.
- Evidence: V

### /
- Slot: 12 (table entry 0xa288f0)
- Returns: real
- Parameters: NUMBER NUMBER
- Kind: special form
- Status: implemented
- Evaluator: function_83a70 (523 bytes)
- Behavior: Divides the first argument by the second. Arguments are compiled as real; the result is a 32-bit float. Takes exactly 2 arguments. When the divisor is within 0.0001 of zero the evaluator stores 0 and does not divide (function_83a70, constants at 0xa7a434 and 0xa8a9b8).
- Evidence: V

### %
- Slot: 13 (table entry 0xa28a80)
- Returns: real
- Parameters: NUMBER NUMBER
- Kind: special form
- Status: implemented
- Evaluator: function_83a70 (523 bytes)
- Behavior: Combines the first argument and the second through function_91a16e (a library math routine taking two floats; that it is the float remainder routine was not verified). Arguments are compiled as real; the result is a 32-bit float. Takes exactly 2 arguments. Shared evaluator function_83a70.
- Evidence: V

### min
- Slot: 14 (table entry 0xa28a40)
- Returns: real
- Parameters: NUMBERS
- Kind: special form
- Status: implemented
- Evaluator: function_83a70 (523 bytes)
- Behavior: Smallest of its number arguments (float compare). Arguments are compiled as real. Needs at least 2 arguments. Shared evaluator function_83a70.
- Evidence: V

### max
- Slot: 15 (table entry 0xa28a00)
- Returns: real
- Parameters: NUMBERS
- Kind: special form
- Status: implemented
- Evaluator: function_83a70 (523 bytes)
- Behavior: Largest of its number arguments (float compare). Arguments are compiled as real. Needs at least 2 arguments. Shared evaluator function_83a70.
- Evidence: V

### =
- Slot: 16 (table entry 0xa289c0)
- Returns: boolean
- Parameters: EXPRESSION EXPRESSION
- Kind: special form
- Status: implemented
- Evaluator: function_83c7c (296 bytes)
- Behavior: Compares two values of the same type for equality and returns a boolean. The type is taken from the first argument. The comparison is a byte compare of the evaluated value (function_794270 on the argument slots); strings are compared as text up to 0x20 characters. Shared evaluator function_83c7c.
- Evidence: V

### !=
- Slot: 17 (table entry 0xa287b0)
- Returns: boolean
- Parameters: EXPRESSION EXPRESSION
- Kind: special form
- Status: implemented
- Evaluator: function_83c7c (296 bytes)
- Behavior: Same comparison as =, with the result inverted. Shared evaluator function_83c7c.
- Evidence: V

### >
- Slot: 18 (table entry 0xa28770)
- Returns: boolean
- Parameters: NUMBER NUMBER
- Kind: special form
- Status: implemented
- Evaluator: function_83da4 (273 bytes)
- Behavior: Greater than. Both arguments are numbers; short and long values are converted to 32-bit float before the comparison. Returns a boolean. Shared evaluator function_83da4.
- Evidence: V

### <
- Slot: 19 (table entry 0xa28730)
- Returns: boolean
- Parameters: NUMBER NUMBER
- Kind: special form
- Status: implemented
- Evaluator: function_83da4 (273 bytes)
- Behavior: Less than. Both arguments are numbers; short and long values are converted to 32-bit float before the comparison. Returns a boolean. Shared evaluator function_83da4.
- Evidence: V

### >=
- Slot: 20 (table entry 0xa286f0)
- Returns: boolean
- Parameters: NUMBER NUMBER
- Kind: special form
- Status: implemented
- Evaluator: function_83da4 (273 bytes)
- Behavior: Greater than or equal. Both arguments are numbers converted to 32-bit float. Returns a boolean. Shared evaluator function_83da4.
- Evidence: V

### <=
- Slot: 21 (table entry 0xa288b0)
- Returns: boolean
- Parameters: NUMBER NUMBER
- Kind: special form
- Status: implemented
- Evaluator: function_83da4 (273 bytes)
- Behavior: Less than or equal. Both arguments are numbers converted to 32-bit float. Returns a boolean. Shared evaluator function_83da4.
- Evidence: V

### sleep
- Slot: 22 (table entry 0xa28870)
- Returns: void
- Parameters: SHORT [SCRIPT]
- Kind: special form
- Status: implemented
- Evaluator: function_84154 (8 bytes)
- Behavior: Suspends the calling thread. The first argument is a short wait. The wake tick is stored in the thread at +0xc as the current game tick (from the game time block, thread-local offset 0xa0, +0xc) plus the wait in game ticks. A negative wait does nothing and returns at once. The wait value is divided by 30.0 and converted to game ticks by function_5cc74, except that a wait of exactly 1 is taken as one game tick. An optional second argument names a script: the sleep is applied to that script's thread (found with function_86740) instead of the calling thread. Evaluator function_84154 sets the plain flag and runs function_83f30. A wait of 0, or any wait that converts to 0 game ticks or fewer, returns without sleeping. When the wake code of the thread being put to sleep is -1 the call changes nothing.
- Evidence: V

### sleep_forever
- Slot: 23 (table entry 0xa28830)
- Returns: void
- Parameters: [SCRIPT]
- Kind: special form
- Status: implemented
- Evaluator: function_83eb8 (120 bytes)
- Behavior: Sets the thread's wake tick to -2, which the per-tick runner never wakes. With a script argument, the thread of that script (function_86740) is put to sleep forever instead of the calling thread. Returns no value (function_83eb8).
- Evidence: V

### sleep_until
- Slot: 24 (table entry 0xa287f0)
- Returns: boolean
- Parameters: BOOLEAN [SHORT]
- Kind: special form
- Status: implemented
- Evaluator: function_84490 (8 bytes)
- Behavior: Evaluates its boolean condition; when it is true the form finishes, otherwise the thread sleeps and re-evaluates the condition after the period. The optional second argument is the period (a short). A period of 1 is used as one game tick; other periods are divided by 30.0 and converted to game ticks by function_5cc74. The condition and period are re-evaluated each wake. Evaluator function_84490 sets the converting flag and runs function_84164. Details read from the code: the period is at least 1 game tick. On the first call the period starts at 30 script time units for a thread without a parent thread and at 0 (one game tick) otherwise; whether a compiled call fills an omitted period with another value was not determined. The frame also holds a timeout value, initially -1 (none); when it is set, the form returns false once the game tick reaches the start tick plus the
  timeout (converted like the period), and the next wake is never later than that tick. Where the timeout value comes from was not determined. The form returns true when the condition became true.
- Evidence: V

### sleep_until_game_ticks
- Slot: 25 (table entry 0xa285b0)
- Returns: boolean
- Parameters: BOOLEAN [SHORT]
- Kind: special form
- Status: implemented
- Evaluator: function_84498 (8 bytes)
- Behavior: Same as sleep_until, except the period is taken directly as game ticks (no division by 30.0). Evaluator function_84498 clears the converting flag and runs function_84164.
- Evidence: V

### wake
- Slot: 26 (table entry 0xa28570)
- Returns: void
- Parameters: SCRIPT_NAME
- Kind: special form
- Status: implemented
- Evaluator: function_844a0 (98 bytes)
- Behavior: Takes a script name. Finds the thread running that script (function_86740) and, when one exists, wakes it (function_864dc). Returns no value. Compile error for static and command scripts: "static or command-script scripts cannot be awakened." (function_844a0).
- Evidence: V

### cinematic_sleep
- Slot: 27 (table entry 0xa28530)
- Returns: void
- Parameters: SHORT [SCRIPT]
- Kind: special form
- Status: implemented
- Evaluator: function_8415c (8 bytes)
- Behavior: Same as sleep, but the wait is always divided by 30.0 and converted to game ticks (a wait of 1 is not special-cased). Evaluator function_8415c sets the cinematic flag and runs function_83f30.
- Evidence: V

### inspect
- Slot: 28 (table entry 0xa284f0)
- Returns: void
- Parameters: EXPRESSION
- Kind: special form
- Status: implemented
- Evaluator: function_845e4 (302 bytes)
- Behavior: Evaluates its expression, formats the value into a local text buffer (0x400 bytes) using the per-type formatter table at data_996530, and returns the evaluated value. No output routine is called on the text in this evaluator, so the formatted text goes unused here (function_845e4).
- Evidence: V

### branch
- Slot: 29 (table entry 0xa286b0)
- Returns: void
- Parameters: CONDITION SCRIPT
- Kind: special form
- Status: implemented
- Evaluator: function_8481c (300 bytes)
- Behavior: Takes a condition and a script. The evaluator looks for a thread already started by this thread for the same script; when there is none it starts a new deterministic thread for the script (function_85638), records the starting thread as its parent (+8) and copies the actor value at +0x28 into it. Returns no value. Compile errors: "branch requires a condition and a script to execute if that condition is met.", "branch requires a script after the branch condition.", and "cannot branch from the console." How the condition is applied (compile step function_195a00) was not followed.
- Evidence: V

### unit
- Slot: 30 (table entry 0xa28670)
- Returns: unit
- Parameters: OBJECT
- Kind: special form
- Status: implemented
- Evaluator: function_84714 (263 bytes)
- Behavior: Returns the object handle unchanged when the object belongs to the unit class (bit test of the object type byte at +0x8e against the class set for unit), otherwise -1 (none). Shared evaluator function_84714.
- Evidence: V

### vehicle
- Slot: 31 (table entry 0xa28630)
- Returns: vehicle
- Parameters: OBJECT
- Kind: special form
- Status: implemented
- Evaluator: function_84714 (263 bytes)
- Behavior: Returns the object handle unchanged when the object belongs to the vehicle class, otherwise -1. Shared evaluator function_84714.
- Evidence: V

### weapon
- Slot: 32 (table entry 0xa285f0)
- Returns: weapon
- Parameters: OBJECT
- Kind: special form
- Status: implemented
- Evaluator: function_84714 (263 bytes)
- Behavior: Returns the object handle unchanged when the object belongs to the weapon class, otherwise -1. Shared evaluator function_84714.
- Evidence: V

### device
- Slot: 33 (table entry 0xa283d0)
- Returns: device
- Parameters: OBJECT
- Kind: special form
- Status: implemented
- Evaluator: function_84714 (263 bytes)
- Behavior: Returns the object handle unchanged when the object belongs to the device class, otherwise -1. Shared evaluator function_84714.
- Evidence: V

### scenery
- Slot: 34 (table entry 0xa28390)
- Returns: scenery
- Parameters: OBJECT
- Kind: special form
- Status: implemented
- Evaluator: function_84714 (263 bytes)
- Behavior: Returns the object handle unchanged when the object belongs to the scenery class, otherwise -1. Shared evaluator function_84714.
- Evidence: V

### effect_scenery
- Slot: 35 (table entry 0xa28350)
- Returns: effect_scenery
- Parameters: OBJECT
- Kind: special form
- Status: implemented
- Evaluator: function_84714 (263 bytes)
- Behavior: Returns the object handle unchanged when the object belongs to the effect scenery class, otherwise -1. Shared evaluator function_84714.
- Evidence: V

## Language functions

### evaluate
- Slot: 36 (table entry 0xa28300)
- Returns: void
- Parameters: a0: script
- Kind: normal
- Status: implemented
- Evaluator: function_199228 (138 bytes)
- Behavior: Evaluates 1 argument (script). Calls function_85fa0 with a0 (script). Reads data_c1a230. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### not
- Slot: 37 (table entry 0xa284a0)
- Returns: boolean
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1992b4 (77 bytes)
- Behavior: Evaluates 1 argument (boolean). Returns true when the argument is false and false when it is true (boolean negation).
- Evidence: V

### pin
- Slot: 38 (table entry 0xa28450)
- Returns: real
- Parameters: a0: real, a1: real, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_199304 (96 bytes)
- Behavior: Evaluates 3 arguments (real, real, real). Returns min(max(a0, a1), a2): a0 limited from below by a1 and from above by a2 (a1 is the low bound and a2 the high bound; when a2 is smaller than the larger of a0 and a1 the result is a2).
- Evidence: V

## Debug and diagnostics

### dummy_function
- Slot: 39 (table entry 0xa28410)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### print
- Slot: 40 (table entry 0xa28170)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (any nested expressions run) and then returns 0. No other action is taken.
- Evidence: V

### print_if
- Slot: 41 (table entry 0xa28120)
- Returns: void
- Parameters: a0: boolean, a1: string
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (any nested expressions run) and then returns 0. No other action is taken.
- Evidence: V

### log_print
- Slot: 42 (table entry 0xa282b0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (any nested expressions run) and then returns 0. No other action is taken.
- Evidence: V

### debug_scripting_show_thread
- Slot: 43 (table entry 0xa28260)
- Returns: void
- Parameters: a0: string, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### debug_script_thread
- Slot: 44 (table entry 0xa28210)
- Returns: void
- Parameters: a0: string_id, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### debug_scripting
- Slot: 45 (table entry 0xa281c0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (any nested expressions run) and then returns 0. No other action is taken.
- Evidence: V

### debug_scripting_globals
- Slot: 46 (table entry 0xa27fb0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (any nested expressions run) and then returns 0. No other action is taken.
- Evidence: V

### debug_scripting_variable
- Slot: 47 (table entry 0xa27f60)
- Returns: void
- Parameters: a0: string, a1: boolean
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (any nested expressions run) and then returns 0. No other action is taken.
- Evidence: V

### debug_scripting_variable_all
- Slot: 48 (table entry 0xa280d0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (any nested expressions run) and then returns 0. No other action is taken.
- Evidence: V

### breakpoint
- Slot: 49 (table entry 0xa28080)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (any nested expressions run) and then returns 0. No other action is taken.
- Evidence: V

### objects_dump_memory
- Slot: 123 (table entry 0xa26860)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### garbage_collect_now
- Slot: 149 (table entry 0xa261e0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_19b99c (47 bytes)
- Behavior: Takes no arguments. Sets the word at +1 of the state block at thread-local offset 0x140 to 1 (the evaluator of the next slot writes 0x101 to the same word). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### garbage_collect_unsafe
- Slot: 150 (table entry 0xa26010)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_19b9cc (47 bytes)
- Behavior: Takes no arguments. Reads the thread-local block at offset 0x140. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### garbage_collect_multiplayer
- Slot: 151 (table entry 0xa25fd0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_19b9fc (27 bytes)
- Behavior: Takes no arguments. Calls function_7ab10. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### havok_debug_start
- Slot: 195 (table entry 0xa25490)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### havok_debug_stop
- Slot: 196 (table entry 0xa25450)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### havok_dump_world
- Slot: 197 (table entry 0xa25400)
- Returns: void
- Parameters: a0: string, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### havok_dump_world_close_movie
- Slot: 198 (table entry 0xa253c0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### havok_profile_start
- Slot: 199 (table entry 0xa25120)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### havok_profile_stop
- Slot: 200 (table entry 0xa250e0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### havok_profile_range
- Slot: 201 (table entry 0xa25090)
- Returns: void
- Parameters: a0: long, a1: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### havok_reset_allocated_state
- Slot: 202 (table entry 0xa25050)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### print_light_state
- Slot: 211 (table entry 0xa24fc0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_texture_camera
- Slot: 240 (table entry 0xa246e0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_cheap_particles
- Slot: 241 (table entry 0xa244b0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_rain_occlusion
- Slot: 242 (table entry 0xa24460)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_rain_fog
- Slot: 243 (table entry 0xa24410)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### debug_rain_toggle
- Slot: 244 (table entry 0xa243d0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### debug_structure_cluster
- Slot: 247 (table entry 0xa24500)
- Returns: void
- Parameters: a0: long, a1: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_structure_cluster_fog
- Slot: 248 (table entry 0xa24240)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_structure_fog_plane
- Slot: 249 (table entry 0xa241f0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_structure_fog_plane_infinite_extent
- Slot: 250 (table entry 0xa241a0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_structure_fog_zone
- Slot: 251 (table entry 0xa24150)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_structure_fog_zone_floodfill
- Slot: 252 (table entry 0xa24380)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_structure_all_fog_planes
- Slot: 253 (table entry 0xa24330)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_structure_all_cluster_errors
- Slot: 254 (table entry 0xa242e0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_structure_line_opacity
- Slot: 255 (table entry 0xa24290)
- Returns: void
- Parameters: a0: real, a1: real, a2: real, a3: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_structure_text_opacity
- Slot: 256 (table entry 0xa23ff0)
- Returns: void
- Parameters: a0: real, a1: real, a2: real, a3: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_structure_opacity
- Slot: 257 (table entry 0xa23fa0)
- Returns: void
- Parameters: a0: real, a1: real, a2: real, a3: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_structure_non_occluded_fog_planes
- Slot: 258 (table entry 0xa23f50)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_structure_lightmaps_use_pervertex
- Slot: 259 (table entry 0xa23f10)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_structure_lightmaps_use_reset
- Slot: 260 (table entry 0xa24110)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_structure_lightmaps_sample_enable
- Slot: 261 (table entry 0xa240d0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_structure_lightmaps_sample_disable
- Slot: 262 (table entry 0xa24090)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_query_object_bitmaps
- Slot: 263 (table entry 0xa24040)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_query_bsp_resources
- Slot: 264 (table entry 0xa23dd0)
- Returns: void
- Parameters: a0: long, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_query_all_object_resources
- Slot: 265 (table entry 0xa23d90)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_text_using_simple_font
- Slot: 266 (table entry 0xa23d40)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_wrinkle_weights_a
- Slot: 268 (table entry 0xa23ec0)
- Returns: void
- Parameters: a0: real, a1: real, a2: real, a3: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_wrinkle_weights_b
- Slot: 269 (table entry 0xa23e70)
- Returns: void
- Parameters: a0: real, a1: real, a2: real, a3: real
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### render_debug_wrinkle_weights_from_console
- Slot: 270 (table entry 0xa23e20)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

## Script and thread control

### kill_active_scripts
- Slot: 50 (table entry 0xa28040)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1993a4 (130 bytes)
- Behavior: Takes no arguments. When the first byte of the hs runtime globals block (thread-local offset 0x230) is set, walks all script threads (function_87188 starts the walk, function_87200 returns the next thread handle) and skips the calling thread (its handle is stored at +8 of that block). Every other thread of script type 0 to 4 whose wake code is neither -1 nor -2 gets the kill flag (0x40 in byte +0x21) and wake code 0, so that it runs once more and ends. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### get_executing_running_thread
- Slot: 51 (table entry 0xa28000)
- Returns: long
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_199428 (42 bytes)
- Behavior: Takes no arguments. Reads the thread-local block at offset 0x230 (hs runtime globals (current thread handle at +8)). Returns a value computed in the body.
- Evidence: V

### kill_thread
- Slot: 52 (table entry 0xa27e90)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_199454 (93 bytes)
- Behavior: Evaluates 1 argument (long). Calls function_85754 with a0 (long). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### script_started
- Slot: 53 (table entry 0xa27e40)
- Returns: boolean
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1994b4 (116 bytes)
- Behavior: Evaluates 1 argument (string_id). Calls function_867a8 with a0 (string_id). Calls function_85754 with the result of function_867a8. Returns a value computed in the body.
- Evidence: V

### script_finished
- Slot: 54 (table entry 0xa27df0)
- Returns: boolean
- Parameters: a0: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_199528 (109 bytes)
- Behavior: Evaluates 1 argument (string_id). Calls function_867a8 with a0 (string_id). Calls function_85754 with the result of function_867a8. Returns a value computed in the body.
- Evidence: V

### script_recompile
- Slot: 185 (table entry 0xa25510)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### script_doc
- Slot: 186 (table entry 0xa254d0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_19c3d8 (27 bytes)
- Behavior: Takes no arguments. Calls function_82674. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

## Players

### local_players
- Slot: 55 (table entry 0xa27db0)
- Returns: object_list
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_199598 (154 bytes)
- Behavior: Takes no arguments. Reads the thread-local block at offset 0x158 (player mapping block). Calls function_192960. Calls function_1929cc with the result of function_192960. Contains a loop. Returns the result of function_192960.
- Evidence: V

### players
- Slot: 56 (table entry 0xa27f20)
- Returns: object_list
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_199634 (254 bytes)
- Behavior: Takes no arguments. Reads the thread-local block at offset 0x18 (players datum array (element size 0x490)). Calls function_192960. Calls function_13870 with a thread-local structure (offset 0x18); -1. Calls function_13870 with a thread-local structure (offset 0x18); the result of function_13870; the result of function_13870. Calls function_1929cc with the result of function_192960; the result of function_13870. Reads the 32-bit field at offset 0x28 of an array element of size 0x490. Contains a loop. Returns the result of function_192960.
- Evidence: V

### players_human
- Slot: 57 (table entry 0xa27ee0)
- Returns: object_list
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_199734 (29 bytes)
- Behavior: Takes no arguments. Calls function_1eb4ac with 0. Returns the result of function_1eb4ac.
- Evidence: V

### players_elite
- Slot: 58 (table entry 0xa27c80)
- Returns: object_list
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_199754 (32 bytes)
- Behavior: Takes no arguments. Calls function_1eb4ac with 1. Returns the result of function_1eb4ac.
- Evidence: V

### player_get
- Slot: 59 (table entry 0xa27c30)
- Returns: unit
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_199774 (120 bytes)
- Behavior: Evaluates one long (a player index). Maps it through the roster mapping (function_486e8; -1 when the index has no player). For a valid player it reads the 32-bit field at offset 0x28 of that player's 0x490-byte entry in the players datum array (thread-local block offset 0x18, element data pointer at +0x50) and returns it (declared as a unit handle). With no mapping it returns -1.
- Evidence: V

### player_in_game_get
- Slot: 60 (table entry 0xa27be0)
- Returns: player
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1997ec (68 bytes)
- Behavior: Evaluates 1 argument (long). Calls function_486e8 with a0 (long). Returns the result of function_486e8.
- Evidence: V

### human_player_in_game_get
- Slot: 61 (table entry 0xa27d60)
- Returns: player
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_199830 (70 bytes)
- Behavior: Evaluates 1 argument (long). Calls function_1eb5cc with 0; a0 (long). Returns the result of function_1eb5cc.
- Evidence: V

### elite_player_in_game_get
- Slot: 62 (table entry 0xa27d10)
- Returns: player
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_199878 (73 bytes)
- Behavior: Evaluates 1 argument (long). Calls function_1eb5cc with 1; a0 (long). Returns the result of function_1eb5cc.
- Evidence: V

### player_is_in_game
- Slot: 63 (table entry 0xa27cc0)
- Returns: boolean
- Parameters: a0: player
- Kind: normal
- Status: implemented
- Evaluator: function_1998c4 (97 bytes)
- Behavior: Evaluates 1 argument (player). A player of -1 gives false and no call is made. Otherwise calls function_4a1a8 with the player and returns its boolean result.
- Evidence: V

## Miscellaneous

### editor_mode
- Slot: 64 (table entry 0xa27ab0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### map_info
- Slot: 181 (table entry 0xa25860)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### position_predict
- Slot: 182 (table entry 0xa25810)
- Returns: void
- Parameters: a0: real, a1: real, a2: real
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (any nested expressions run) and then returns 0. No other action is taken.
- Evidence: V

### shader_predict
- Slot: 183 (table entry 0xa255a0)
- Returns: void
- Parameters: a0: shader
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (any nested expressions run) and then returns 0. No other action is taken.
- Evidence: V

### bitmap_predict
- Slot: 184 (table entry 0xa25550)
- Returns: void
- Parameters: a0: bitmap
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (any nested expressions run) and then returns 0. No other action is taken.
- Evidence: V

### help
- Slot: 187 (table entry 0xa256d0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: implemented
- Evaluator: function_19c3f4 (77 bytes)
- Behavior: Evaluates 1 argument (string). Calls function_1990a0. Calls function_825a4 with the result of function_1990a0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### game_engine_objects
- Slot: 188 (table entry 0xa25690)
- Returns: object_list
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_19c444 (27 bytes)
- Behavior: Takes no arguments. Calls function_192960. Returns the result of function_192960.
- Evidence: V

### random_range
- Slot: 189 (table entry 0xa25640)
- Returns: short
- Parameters: a0: short, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_19c460 (144 bytes)
- Behavior: Evaluates 2 arguments (short, short). Reads the thread-local block at offset 0x658. Returns a value computed in the body.
- Evidence: V

### real_random_range
- Slot: 190 (table entry 0xa255f0)
- Returns: real
- Parameters: a0: real, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_19c4f0 (150 bytes)
- Behavior: Evaluates 2 arguments (real, real). Reads the thread-local block at offset 0x658. Uses read-only constants at data_a8a97c. Returns a value computed in the body.
- Evidence: V

### sync_action_create
- Slot: 302 (table entry 0xa233f0)
- Returns: boolean
- Parameters: a0: unit, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19e59c (83 bytes)
- Behavior: Evaluates 2 arguments (unit, string_id). Calls function_4fa708 with a0 (unit); a1 (string_id). Returns a value computed in the body.
- Evidence: V

### magic_melee_attack
- Slot: 342 (table entry 0xa227b0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_19f56c (132 bytes)
- Behavior: Takes no arguments. Reads the thread-local block at offset 0x158 (player mapping block). Calls function_53c34 with -1. Calls function_78932a (a memset thunk) with 0. Calls function_49f24c. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### drop
- Slot: 393 (table entry 0xa21850)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### update_dropped_tag_permutation
- Slot: 396 (table entry 0xa21760)
- Returns: void
- Parameters: a0: string, a1: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

## Object lists and volumes

### kill_volume_enable
- Slot: 65 (table entry 0xa27a60)
- Returns: void
- Parameters: a0: trigger_volume
- Kind: normal
- Status: implemented
- Evaluator: function_199928 (184 bytes)
- Behavior: Evaluates 1 argument (trigger_volume). Reads the thread-local block at offset 0x4d0. Reads data_c1a230. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### kill_volume_disable
- Slot: 66 (table entry 0xa27a10)
- Returns: void
- Parameters: a0: trigger_volume
- Kind: normal
- Status: implemented
- Evaluator: function_1999e0 (182 bytes)
- Behavior: Evaluates 1 argument (trigger_volume). Reads the thread-local block at offset 0x4d0. Reads data_c1a230. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### volume_teleport_players_not_inside
- Slot: 67 (table entry 0xa279c0)
- Returns: void
- Parameters: a0: trigger_volume, a1: cutscene_flag
- Kind: normal
- Status: implemented
- Evaluator: function_199a98 (73 bytes)
- Behavior: Evaluates 2 arguments (trigger_volume, cutscene_flag). Calls function_1eb854 with a0 (trigger_volume); a1 (cutscene_flag). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### volume_test_object
- Slot: 68 (table entry 0xa27b90)
- Returns: boolean
- Parameters: a0: trigger_volume, a1: object
- Kind: normal
- Status: implemented
- Evaluator: function_199ae4 (88 bytes)
- Behavior: Evaluates 2 arguments (trigger_volume, object). Calls function_9ed7c with a0 (trigger_volume); -1; a1 (object). Returns a value computed in the body.
- Evidence: V

### volume_test_objects
- Slot: 69 (table entry 0xa27b40)
- Returns: boolean
- Parameters: a0: trigger_volume, a1: object_list
- Kind: normal
- Status: implemented
- Evaluator: function_199b3c (87 bytes)
- Behavior: Evaluates 2 arguments (trigger_volume, object_list). Calls function_1eb900 with a0 (trigger_volume); a1 (object_list); 0. Returns a value computed in the body.
- Evidence: V

### volume_test_objects_all
- Slot: 70 (table entry 0xa27af0)
- Returns: boolean
- Parameters: a0: trigger_volume, a1: object_list
- Kind: normal
- Status: implemented
- Evaluator: function_199b94 (87 bytes)
- Behavior: Evaluates 2 arguments (trigger_volume, object_list). Calls function_1eb900 with a0 (trigger_volume); a1 (object_list); 1. Returns a value computed in the body.
- Evidence: V

### volume_test_players
- Slot: 71 (table entry 0xa27880)
- Returns: boolean
- Parameters: a0: trigger_volume
- Kind: normal
- Status: implemented
- Evaluator: function_199bec (225 bytes)
- Behavior: Evaluates 1 argument (trigger_volume). Reads the thread-local block at offset 0x10 (object datum array), offset 0x18 (players datum array (element size 0x490)). Calls function_1381c. Calls function_9e9cc with a0 (trigger_volume); -1. Contains a loop. Returns a value computed in the body.
- Evidence: V

### volume_test_players_all
- Slot: 72 (table entry 0xa27830)
- Returns: boolean
- Parameters: a0: trigger_volume
- Kind: normal
- Status: implemented
- Evaluator: function_199cd0 (81 bytes)
- Behavior: Evaluates 1 argument (trigger_volume). Calls function_9ee8c with a0 (trigger_volume). Returns a value computed in the body.
- Evidence: V

### volume_return_objects
- Slot: 73 (table entry 0xa277e0)
- Returns: object_list
- Parameters: a0: trigger_volume
- Kind: normal
- Status: implemented
- Evaluator: function_199d24 (72 bytes)
- Behavior: Evaluates 1 argument (trigger_volume). Calls function_9efe0 with a0 (trigger_volume); -1. Returns the result of function_9efe0.
- Evidence: V

### volume_return_objects_by_type
- Slot: 74 (table entry 0xa27790)
- Returns: object_list
- Parameters: a0: trigger_volume, a1: long
- Kind: normal
- Status: implemented
- Evaluator: function_199d6c (72 bytes)
- Behavior: Evaluates 2 arguments (trigger_volume, long). Calls function_9efe0 with a0 (trigger_volume); a1 (long). Returns the result of function_9efe0.
- Evidence: V

### volume_return_objects_by_campaign_type
- Slot: 75 (table entry 0xa27970)
- Returns: object_list
- Parameters: a0: trigger_volume, a1: long
- Kind: normal
- Status: implemented
- Evaluator: function_199db4 (72 bytes)
- Behavior: Evaluates 2 arguments (trigger_volume, long). Calls function_9f160 with a0 (trigger_volume); a1 (long). Returns the result of function_9f160.
- Evidence: V

### zone_set_trigger_volume_enable
- Slot: 76 (table entry 0xa27920)
- Returns: void
- Parameters: a0: string_id, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_199dfc (71 bytes)
- Behavior: Evaluates 2 arguments (string_id, boolean). Calls function_499d4 with a0 (string_id); a1 (boolean). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### list_get
- Slot: 77 (table entry 0xa278d0)
- Returns: object
- Parameters: a0: object_list, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_199e44 (113 bytes)
- Behavior: Evaluates 2 arguments (object_list, short). Calls function_192b34 with a0 (object_list). Calls function_192b80 with -1. Contains a loop. Returns the result of function_192b80.
- Evidence: V

### list_count
- Slot: 78 (table entry 0xa27650)
- Returns: short
- Parameters: a0: object_list
- Kind: normal
- Status: implemented
- Evaluator: function_199eb8 (81 bytes)
- Behavior: Evaluates 1 argument (object_list). Calls function_192ce4 with a0 (object_list). Returns a value computed in the body.
- Evidence: V

### list_count_not_dead
- Slot: 79 (table entry 0xa27600)
- Returns: short
- Parameters: a0: object_list
- Kind: normal
- Status: implemented
- Evaluator: function_199f0c (200 bytes)
- Behavior: Evaluates 1 argument (object_list). Reads the thread-local block at offset 0x10 (object datum array). Calls function_192b34 with a0 (object_list). Calls function_192b80 with 16. Contains a loop. Returns a value computed in the body.
- Evidence: V

### objects_delete_by_definition
- Slot: 106 (table entry 0xa26da0)
- Returns: void
- Parameters: a0: object_definition
- Kind: normal
- Status: implemented
- Evaluator: function_19a800 (150 bytes)
- Behavior: Evaluates 1 argument (object_definition). Calls function_1eb650. Calls function_473a78. Calls function_47b720. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### objects_attach
- Slot: 129 (table entry 0xa26680)
- Returns: void
- Parameters: a0: object, a1: string_id, a2: object, a3: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19b200 (194 bytes)
- Behavior: Evaluates 4 arguments (object, string_id, object, string_id). Reads the thread-local block at offset 0x10 (object datum array). Calls function_473dc0 with a0 (object); a thread-local structure (offset 0x10). Calls function_470998. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### objects_detach
- Slot: 131 (table entry 0xa26770)
- Returns: void
- Parameters: a0: object, a1: object
- Kind: normal
- Status: implemented
- Evaluator: function_19b30c (134 bytes)
- Behavior: Evaluates 2 arguments (object, object). Reads the thread-local block at offset 0x10 (object datum array). Calls function_47133c with a1 (object); a thread-local structure (offset 0x10); a0 (object). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### objects_predict
- Slot: 160 (table entry 0xa25e90)
- Returns: void
- Parameters: a0: object_list
- Kind: normal
- Status: implemented
- Evaluator: function_19bdb8 (90 bytes)
- Behavior: Evaluates 1 argument (object_list). Calls function_192b34 with a0 (object_list). Calls function_192b80. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### objects_predict_high
- Slot: 161 (table entry 0xa25cb0)
- Returns: void
- Parameters: a0: object_list
- Kind: normal
- Status: implemented
- Evaluator: function_19bdb8 (90 bytes)
- Behavior: Evaluates 1 argument (object_list). Calls function_192b34 with a0 (object_list). Calls function_192b80. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### objects_predict_low
- Slot: 162 (table entry 0xa25c60)
- Returns: void
- Parameters: a0: object_list
- Kind: normal
- Status: implemented
- Evaluator: function_19bdb8 (90 bytes)
- Behavior: Evaluates 1 argument (object_list). Calls function_192b34 with a0 (object_list). Calls function_192b80. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### objects_can_see_object
- Slot: 176 (table entry 0xa25990)
- Returns: boolean
- Parameters: a0: object_list, a1: object, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_19c234 (88 bytes)
- Behavior: Evaluates 3 arguments (object_list, object, real). Calls function_1eb968 with a0 (object_list); a1 (object). Returns a value computed in the body.
- Evidence: V

### objects_can_see_flag
- Slot: 177 (table entry 0xa25940)
- Returns: boolean
- Parameters: a0: object_list, a1: cutscene_flag, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_19c28c (89 bytes)
- Behavior: Evaluates 3 arguments (object_list, cutscene_flag, real). Calls function_1eba5c with a0 (object_list); a1 (cutscene_flag). Returns a value computed in the body.
- Evidence: V

### objects_distance_to_object
- Slot: 178 (table entry 0xa257c0)
- Returns: real
- Parameters: a0: object_list, a1: object
- Kind: normal
- Status: implemented
- Evaluator: function_19c2e8 (79 bytes)
- Behavior: Evaluates 2 arguments (object_list, object). Calls function_1ebb30 with a0 (object_list); a1 (object). Returns a value computed in the body.
- Evidence: V

### objects_distance_to_flag
- Slot: 179 (table entry 0xa25770)
- Returns: real
- Parameters: a0: object_list, a1: cutscene_flag
- Kind: normal
- Status: implemented
- Evaluator: function_19c338 (80 bytes)
- Behavior: Evaluates 2 arguments (object_list, cutscene_flag). Calls function_1ebbf0 with a0 (object_list); a1 (cutscene_flag). Returns a value computed in the body.
- Evidence: V

### objects_distance_to_point
- Slot: 180 (table entry 0xa25720)
- Returns: real
- Parameters: a0: object_list, a1: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_19c388 (79 bytes)
- Behavior: Evaluates 2 arguments (object_list, point_reference). Calls function_1ebcdc with a0 (object_list); a1 (point_reference). Returns a value computed in the body.
- Evidence: V

## Effects, damage and physics

### effect_new
- Slot: 80 (table entry 0xa275b0)
- Returns: void
- Parameters: a0: effect, a1: cutscene_flag
- Kind: normal
- Status: implemented
- Evaluator: function_199fd4 (72 bytes)
- Behavior: Evaluates 2 arguments (effect, cutscene_flag). Calls function_1ec848 with a0 (effect); a1 (cutscene_flag). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### effect_new_random (slot 81)
- Slot: 81 (table entry 0xa27740)
- Returns: void
- Parameters: a0: effect, a1: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_19a01c (77 bytes)
- Behavior: Evaluates 2 arguments (effect, point_reference). Calls function_1ecd28 with a0 (effect); a1 (point_reference). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### effect_new_random (slot 82)
- Slot: 82 (table entry 0xa276f0)
- Returns: void
- Parameters: a0: effect, a1: point_reference, a2: real, a3: real
- Kind: normal
- Status: implemented
- Evaluator: function_19a06c (81 bytes)
- Behavior: Evaluates 4 arguments (effect, point_reference, real, real). Calls function_1ecd28 with a0 (effect); a1 (point_reference). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### effect_new_at_ai_point
- Slot: 83 (table entry 0xa276a0)
- Returns: void
- Parameters: a0: effect, a1: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_19a0c0 (77 bytes)
- Behavior: Evaluates 2 arguments (effect, point_reference). Calls function_1eca40 with a0 (effect); a1 (point_reference). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### effect_new_at_point_set_point
- Slot: 84 (table entry 0xa274c0)
- Returns: void
- Parameters: a0: effect, a1: point_reference, a2: long
- Kind: normal
- Status: implemented
- Evaluator: function_19a110 (75 bytes)
- Behavior: Evaluates 3 arguments (effect, point_reference, long). Calls function_1ece18 with a0 (effect); a1 (point_reference); a2 (long). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### effect_new_on_object_marker
- Slot: 85 (table entry 0xa27470)
- Returns: void
- Parameters: a0: effect, a1: object, a2: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19a15c (78 bytes)
- Behavior: Evaluates 3 arguments (effect, object, string_id). Calls function_1ecedc with a0 (effect); a1 (object); a2 (string_id); 0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### effect_new_on_object_marker_loop
- Slot: 86 (table entry 0xa27420)
- Returns: void
- Parameters: a0: effect, a1: object, a2: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19a1ac (78 bytes)
- Behavior: Evaluates 3 arguments (effect, object, string_id). Calls function_1ecedc with a0 (effect); a1 (object); a2 (string_id); 1. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### effect_stop_object_marker
- Slot: 87 (table entry 0xa27560)
- Returns: void
- Parameters: a0: effect, a1: object, a2: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19a1fc (75 bytes)
- Behavior: Evaluates 3 arguments (effect, object, string_id). Calls function_1169f0 with a0 (effect); a1 (object); a2 (string_id). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### effect_new_on_ground
- Slot: 88 (table entry 0xa27510)
- Returns: void
- Parameters: a0: effect, a1: object
- Kind: normal
- Status: implemented
- Evaluator: function_19a248 (71 bytes)
- Behavior: Evaluates 2 arguments (effect, object). Calls function_1ecfa0 with a0 (effect); a1 (object). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### damage_new
- Slot: 89 (table entry 0xa272e0)
- Returns: void
- Parameters: a0: damage, a1: cutscene_flag
- Kind: normal
- Status: implemented
- Evaluator: function_19a290 (72 bytes)
- Behavior: Evaluates 2 arguments (damage, cutscene_flag). Calls function_1ed0c8 with a0 (damage); a1 (cutscene_flag). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### damage_object_effect
- Slot: 90 (table entry 0xa27290)
- Returns: void
- Parameters: a0: damage, a1: object
- Kind: normal
- Status: implemented
- Evaluator: function_19a2d8 (71 bytes)
- Behavior: Evaluates 2 arguments (damage, object). Calls function_1ed200 with a0 (damage); a1 (object). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### damage_objects_effect
- Slot: 91 (table entry 0xa27240)
- Returns: void
- Parameters: a0: damage, a1: object_list
- Kind: normal
- Status: implemented
- Evaluator: function_19a320 (111 bytes)
- Behavior: Evaluates 2 arguments (damage, object_list). Calls function_192b34 with a1 (object_list). Calls function_1ed200 with a0 (damage); the result of function_192b34. Calls function_192b80. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### damage_object
- Slot: 92 (table entry 0xa273d0)
- Returns: void
- Parameters: a0: object, a1: string_id, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_19a390 (76 bytes)
- Behavior: Evaluates 3 arguments (object, string_id, real). Calls function_1ed320 with a0 (object); a1 (string_id). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### damage_objects
- Slot: 93 (table entry 0xa27380)
- Returns: void
- Parameters: a0: object_list, a1: string_id, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_19a3dc (129 bytes)
- Behavior: Evaluates 3 arguments (object_list, string_id, real). Calls function_192b34 with a0 (object_list). Calls function_1ed320 with the result of function_192b34; a1 (string_id). Calls function_192b80. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### damage_players
- Slot: 94 (table entry 0xa27330)
- Returns: void
- Parameters: a0: damage
- Kind: normal
- Status: implemented
- Evaluator: function_19a460 (68 bytes)
- Behavior: Evaluates 1 argument (damage). Calls function_1ed4ec with a0 (damage). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### soft_ceiling_enable
- Slot: 95 (table entry 0xa27150)
- Returns: void
- Parameters: a0: string_id, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19a4a4 (71 bytes)
- Behavior: Evaluates 2 arguments (string_id, boolean). Calls function_15619c with a0 (string_id); a1 (boolean). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### physics_constants_reset
- Slot: 191 (table entry 0xa25380)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_19c588 (123 bytes)
- Behavior: Takes no arguments. Reads the thread-local block at offset 0x330. Calls function_91a14a. Uses read-only constants at data_98faf0, data_98faf8, data_a8adc0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### physics_set_gravity
- Slot: 192 (table entry 0xa25330)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: implemented
- Evaluator: function_19c604 (155 bytes)
- Behavior: Evaluates 1 argument (real). Reads the thread-local block at offset 0x330. Calls function_99a80 with a thread-local structure (offset 0x330); 816. Calls function_99558. Writes data_b93615, data_b93617. Writes data_b93615, data_b93617. Uses read-only constants at data_a8b29c. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### physics_set_velocity_frame
- Slot: 193 (table entry 0xa252e0)
- Returns: void
- Parameters: a0: real, a1: real, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_19c6a0 (115 bytes)
- Behavior: Evaluates 3 arguments (real, real, real). Reads the thread-local block at offset 0x330. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### physics_disable_character_ground_adhesion_forces
- Slot: 194 (table entry 0xa25290)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: implemented
- Evaluator: function_19c714 (137 bytes)
- Behavior: Evaluates 1 argument (real). Calls function_5cc74. Uses read-only constants at data_a7a434, data_a8b2c8. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### breakable_surfaces_enable
- Slot: 203 (table entry 0xa25240)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19c7a0 (94 bytes)
- Behavior: Evaluates 1 argument (boolean). Reads the thread-local block at offset 0x120. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### breakable_surfaces_reset
- Slot: 204 (table entry 0xa25200)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_19c800 (27 bytes)
- Behavior: Takes no arguments. Calls function_15a15c. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### weather_animate
- Slot: 245 (table entry 0xa245a0)
- Returns: void
- Parameters: a0: string_id, a1: real, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_19d830 (78 bytes)
- Behavior: Evaluates 3 arguments (string_id, real, real). Calls function_260628 with a0 (string_id). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### weather_animate_force
- Slot: 246 (table entry 0xa24550)
- Returns: void
- Parameters: a0: string_id, a1: real, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_19d880 (78 bytes)
- Behavior: Evaluates 3 arguments (string_id, real, real). Calls function_2606f0 with a0 (string_id). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

## Objects

### object_create
- Slot: 96 (table entry 0xa27100)
- Returns: void
- Parameters: a0: object_name
- Kind: normal
- Status: implemented
- Evaluator: function_19a4ec (81 bytes)
- Behavior: Evaluates 1 argument (object_name). Calls function_1eb6a4 with a0 (object_name); 0; -1. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_create_variant
- Slot: 97 (table entry 0xa270b0)
- Returns: void
- Parameters: a0: object_name, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19a540 (83 bytes)
- Behavior: Evaluates 2 arguments (object_name, string_id). Calls function_1eb6a4 with a0 (object_name); 0; a1 (string_id). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_create_clone
- Slot: 98 (table entry 0xa271f0)
- Returns: void
- Parameters: a0: object_name
- Kind: normal
- Status: implemented
- Evaluator: function_19a594 (81 bytes)
- Behavior: Evaluates 1 argument (object_name). Calls function_1eb6a4 with a0 (object_name); 1; -1. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_create_anew
- Slot: 99 (table entry 0xa271a0)
- Returns: void
- Parameters: a0: object_name
- Kind: normal
- Status: implemented
- Evaluator: function_19a5e8 (69 bytes)
- Behavior: Evaluates 1 argument (object_name). Calls function_1ebdc0 with a0 (object_name). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_create_if_necessary
- Slot: 100 (table entry 0xa26f80)
- Returns: void
- Parameters: a0: object_name
- Kind: normal
- Status: implemented
- Evaluator: function_19a630 (101 bytes)
- Behavior: Evaluates 1 argument (object_name). Calls function_47b49c with a0 (object_name). Calls function_1eb6a4 with 0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_create_folder
- Slot: 101 (table entry 0xa26f30)
- Returns: void
- Parameters: a0: folder
- Kind: normal
- Status: implemented
- Evaluator: function_19a698 (68 bytes)
- Behavior: Evaluates 1 argument (folder). Calls function_1ebf2c with a0 (folder). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_create_folder_anew
- Slot: 102 (table entry 0xa26ee0)
- Returns: void
- Parameters: a0: folder
- Kind: normal
- Status: implemented
- Evaluator: function_19a6dc (91 bytes)
- Behavior: Evaluates 1 argument (folder). Calls function_1ec33c with a0 (folder). Calls function_1ebf2c with a0 (folder). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_destroy
- Slot: 103 (table entry 0xa27060)
- Returns: void
- Parameters: a0: object
- Kind: normal
- Status: implemented
- Evaluator: function_19a738 (97 bytes)
- Behavior: Evaluates 1 argument (object). Calls function_47a854 with a0 (object). Calls function_1eb650 with a0 (object). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_destroy_all
- Slot: 104 (table entry 0xa27020)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_19a79c (30 bytes)
- Behavior: Takes no arguments. Calls function_1ec0b0 with -1. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_destroy_type_mask
- Slot: 105 (table entry 0xa26fd0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_19a7bc (68 bytes)
- Behavior: Evaluates 1 argument (long). Calls function_1ec0b0 with a0 (long). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_destroy_folder
- Slot: 107 (table entry 0xa26d50)
- Returns: void
- Parameters: a0: folder
- Kind: normal
- Status: implemented
- Evaluator: function_19a898 (68 bytes)
- Behavior: Evaluates 1 argument (folder). Calls function_1ec33c with a0 (folder). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_hide
- Slot: 108 (table entry 0xa26d00)
- Returns: void
- Parameters: a0: object, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19a8dc (76 bytes)
- Behavior: Evaluates 2 arguments (object, boolean). Calls function_4716dc with a0 (object); a1 (boolean). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_set_shadowless
- Slot: 109 (table entry 0xa26e90)
- Returns: void
- Parameters: a0: object, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19a928 (87 bytes)
- Behavior: Evaluates 2 arguments (object, boolean). Calls function_473dc0 with a0 (object). Calls function_47192c with the result of function_473dc0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_set_allegiance
- Slot: 110 (table entry 0xa26e40)
- Returns: void
- Parameters: a0: object, a1: team
- Kind: normal
- Status: implemented
- Evaluator: function_19a980 (167 bytes)
- Behavior: Evaluates 2 arguments (object, team). Reads the thread-local block at offset 0x1a0. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_buckling_magnitude_get
- Slot: 111 (table entry 0xa26df0)
- Returns: real
- Parameters: a0: object
- Kind: normal
- Status: implemented
- Evaluator: function_19aa28 (137 bytes)
- Behavior: Evaluates 1 argument (object). Reads the thread-local block at offset 0x10 (object datum array). Calls function_5000c8 with a0 (object); a0 (object); a thread-local structure (offset 0x10). Returns a value computed in the body.
- Evidence: V

### object_function_set
- Slot: 112 (table entry 0xa26c10)
- Returns: void
- Parameters: a0: long, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_19aab4 (134 bytes)
- Behavior: Evaluates 2 arguments (long, real). Reads the thread-local block at offset 0x3c0. Uses read-only constants at data_a7a434, data_a8af18. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_set_function_variable
- Slot: 113 (table entry 0xa26bc0)
- Returns: void
- Parameters: a0: object, a1: string_id, a2: real, a3: real
- Kind: normal
- Status: implemented
- Evaluator: function_19ab3c (81 bytes)
- Behavior: Evaluates 4 arguments (object, string_id, real, real). Calls function_4d97e4 with a0 (object); a1 (string_id). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_set_cinematic_function_variable
- Slot: 114 (table entry 0xa26b70)
- Returns: void
- Parameters: a0: object, a1: string_id, a2: real, a3: real
- Kind: normal
- Status: implemented
- Evaluator: function_19ab90 (81 bytes)
- Behavior: Evaluates 4 arguments (object, string_id, real, real). Calls function_4d9604 with a0 (object); a1 (string_id). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_clear_cinematic_function_variable
- Slot: 115 (table entry 0xa26cb0)
- Returns: void
- Parameters: a0: object, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19abe4 (165 bytes)
- Behavior: Evaluates 2 arguments (object, string_id). Reads the thread-local block at offset 0x248. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_clear_all_cinematic_function_variables
- Slot: 116 (table entry 0xa26c60)
- Returns: void
- Parameters: a0: object
- Kind: normal
- Status: implemented
- Evaluator: function_19ac8c (68 bytes)
- Behavior: Evaluates 1 argument (object). Calls function_4d9774 with a0 (object). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_dynamic_simulation_disable
- Slot: 117 (table entry 0xa26a30)
- Returns: void
- Parameters: a0: object, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19acd0 (186 bytes)
- Behavior: Evaluates 2 arguments (object, boolean). Reads the thread-local block at offset 0x10 (object datum array). Calls function_9a9e0 with a0 (object); 0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_set_phantom_power
- Slot: 118 (table entry 0xa269e0)
- Returns: void
- Parameters: a0: object, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19ad8c (145 bytes)
- Behavior: Evaluates 2 arguments (object, boolean). Reads the thread-local block at offset 0x10 (object datum array). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_wake_physics
- Slot: 119 (table entry 0xa26990)
- Returns: void
- Parameters: a0: object
- Kind: normal
- Status: implemented
- Evaluator: function_19ae20 (75 bytes)
- Behavior: Evaluates 1 argument (object). Calls function_4715f8 with a0 (object); 0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_get_at_rest
- Slot: 120 (table entry 0xa26b20)
- Returns: boolean
- Parameters: a0: object
- Kind: normal
- Status: implemented
- Evaluator: function_19ae6c (150 bytes)
- Behavior: Evaluates 1 argument (object). Reads the thread-local block at offset 0x10 (object datum array). Returns a value computed in the body.
- Evidence: V

### object_set_ranged_attack_inhibited
- Slot: 121 (table entry 0xa26ad0)
- Returns: void
- Parameters: a0: object, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19af04 (135 bytes)
- Behavior: Evaluates 2 arguments (object, boolean). Reads the thread-local block at offset 0x10 (object datum array). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_set_melee_attack_inhibited
- Slot: 122 (table entry 0xa26a80)
- Returns: void
- Parameters: a0: object, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19af8c (135 bytes)
- Behavior: Evaluates 2 arguments (object, boolean). Reads the thread-local block at offset 0x10 (object datum array). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_get_health
- Slot: 124 (table entry 0xa26810)
- Returns: real
- Parameters: a0: object
- Kind: normal
- Status: implemented
- Evaluator: function_19b014 (129 bytes)
- Behavior: Evaluates 1 argument (object). Looks the object up with function_4739cc (type mask -1, any type). When no object is found the result is the constant at data_a8b7e8 (-1.0). When bit 2 of the dword at +0x138 of the object record is set the result is 0.0. Otherwise the result is function_49dbec(object) as a real.
- Evidence: V

### object_get_shield
- Slot: 125 (table entry 0xa267c0)
- Returns: real
- Parameters: a0: object
- Kind: normal
- Status: implemented
- Evaluator: function_19b098 (129 bytes)
- Behavior: Evaluates 1 argument (object). Calls function_4739cc with a0 (object); -1. Calls function_49dcec with a0 (object). Uses read-only constants at data_a8b7e8. Returns a value computed in the body.
- Evidence: V

### object_set_shield_effect
- Slot: 126 (table entry 0xa26940)
- Returns: void
- Parameters: a0: object, a1: real, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_19b11c (78 bytes)
- Behavior: Evaluates 3 arguments (object, real, real). Calls function_4d9920 with a0 (object). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_set_physics
- Slot: 127 (table entry 0xa268f0)
- Returns: void
- Parameters: a0: object, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19b16c (80 bytes)
- Behavior: Evaluates 2 arguments (object, boolean). Calls function_4717b0 with a0 (object); a comparison result. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_get_parent
- Slot: 128 (table entry 0xa268a0)
- Returns: object
- Parameters: a0: object
- Kind: normal
- Status: implemented
- Evaluator: function_19b1bc (68 bytes)
- Behavior: Evaluates 1 argument (object). Calls function_4d99f0 with a0 (object). Returns the result of function_4d99f0.
- Evidence: V

### object_at_marker
- Slot: 130 (table entry 0xa26630)
- Returns: object
- Parameters: a0: object, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19b2c4 (71 bytes)
- Behavior: Evaluates 2 arguments (object, string_id). Calls function_4d9a28 with a0 (object); a1 (string_id). Returns the result of function_4d9a28.
- Evidence: V

### object_set_scale
- Slot: 132 (table entry 0xa26720)
- Returns: void
- Parameters: a0: object, a1: real, a2: short
- Kind: normal
- Status: implemented
- Evaluator: function_19b394 (78 bytes)
- Behavior: Evaluates 3 arguments (object, real, short). Calls function_4d9b38 with a0 (object); a2 (short). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_set_velocity (slot 133)
- Slot: 133 (table entry 0xa266d0)
- Returns: void
- Parameters: a0: object, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_19b3e4 (79 bytes)
- Behavior: Evaluates 2 arguments (object, real). Calls function_4d9bf8 with a0 (object). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_get_bsp
- Slot: 134 (table entry 0xa26540)
- Returns: short
- Parameters: a0: object
- Kind: normal
- Status: implemented
- Evaluator: function_19b434 (136 bytes)
- Behavior: Evaluates 1 argument (object). Reads the thread-local block at offset 0x10 (object datum array). Returns a value computed in the body.
- Evidence: V

### object_set_as_fireteam_target
- Slot: 135 (table entry 0xa264f0)
- Returns: void
- Parameters: a0: object, a1: boolean
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (any nested expressions run) and then returns 0. No other action is taken.
- Evidence: V

### object_is_reserved
- Slot: 136 (table entry 0xa264a0)
- Returns: boolean
- Parameters: a0: object
- Kind: normal
- Status: implemented
- Evaluator: function_19b4bc (150 bytes)
- Behavior: Evaluates 1 argument (object). Reads the thread-local block at offset 0x10 (object datum array). Returns a value computed in the body.
- Evidence: V

### object_set_velocity (slot 137)
- Slot: 137 (table entry 0xa265e0)
- Returns: void
- Parameters: a0: object, a1: real, a2: real, a3: real
- Kind: normal
- Status: implemented
- Evaluator: function_19b554 (83 bytes)
- Behavior: Evaluates 4 arguments (object, real, real, real). Calls function_4d9bf8 with a0 (object). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_set_deleted_when_deactivated
- Slot: 138 (table entry 0xa26590)
- Returns: void
- Parameters: a0: object
- Kind: normal
- Status: implemented
- Evaluator: function_19b5a8 (122 bytes)
- Behavior: Evaluates 1 argument (object). Reads the thread-local block at offset 0x10 (object datum array). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_copy_player_appearance
- Slot: 139 (table entry 0xa26360)
- Returns: void
- Parameters: a0: object, a1: long
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (any nested expressions run) and then returns 0. No other action is taken.
- Evidence: V

### object_model_target_destroyed
- Slot: 140 (table entry 0xa26310)
- Returns: boolean
- Parameters: a0: object, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19b624 (97 bytes)
- Behavior: Evaluates 2 arguments (object, string_id). Calls function_4fae40 with a0 (object); a1 (string_id). Returns a value computed in the body.
- Evidence: V

### object_model_targets_destroyed
- Slot: 141 (table entry 0xa262c0)
- Returns: short
- Parameters: a0: object, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19b688 (84 bytes)
- Behavior: Evaluates 2 arguments (object, string_id). Calls function_4fae40 with a0 (object); a1 (string_id). Returns a value computed in the body.
- Evidence: V

### object_enable_damage_section
- Slot: 142 (table entry 0xa26450)
- Returns: void
- Parameters: a0: object, a1: string_id, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_19b6dc (79 bytes)
- Behavior: Evaluates 3 arguments (object, string_id, real). Calls function_4e7ecc with a0 (object); a1 (string_id); 1. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_disable_damage_section
- Slot: 143 (table entry 0xa26400)
- Returns: void
- Parameters: a0: object, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19b72c (77 bytes)
- Behavior: Evaluates 2 arguments (object, string_id). Calls function_4e7ecc with a0 (object); a1 (string_id); 0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_damage_damage_section
- Slot: 144 (table entry 0xa263b0)
- Returns: void
- Parameters: a0: object, a1: string_id, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_19b77c (88 bytes)
- Behavior: Evaluates 3 arguments (object, string_id, real). Calls function_4e801c with a0 (object); a1 (string_id). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_cannot_die
- Slot: 145 (table entry 0xa26190)
- Returns: void
- Parameters: a0: object, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19b7d4 (71 bytes)
- Behavior: Evaluates 2 arguments (object, boolean). Calls function_4fb064 with a0 (object); a1 (boolean). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_cannot_die_except_kill_volumes
- Slot: 146 (table entry 0xa26140)
- Returns: void
- Parameters: a0: object, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19b81c (154 bytes)
- Behavior: Evaluates 2 arguments (object, boolean). Reads the thread-local block at offset 0x10 (object datum array). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_ignores_emp
- Slot: 147 (table entry 0xa26270)
- Returns: void
- Parameters: a0: object, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19b8b8 (145 bytes)
- Behavior: Evaluates 2 arguments (object, boolean). Reads the thread-local block at offset 0x10 (object datum array). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_vitality_pinned
- Slot: 148 (table entry 0xa26220)
- Returns: boolean
- Parameters: a0: object
- Kind: normal
- Status: implemented
- Evaluator: function_19b94c (80 bytes)
- Behavior: Evaluates 1 argument (object). Calls function_49ef0c with a0 (object). Returns a value computed in the body.
- Evidence: V

### object_cannot_take_damage
- Slot: 152 (table entry 0xa25f80)
- Returns: void
- Parameters: a0: object_list
- Kind: normal
- Status: implemented
- Evaluator: function_19ba18 (76 bytes)
- Behavior: Evaluates 1 argument (object_list). Calls function_4fb0c0 with a0 (object_list); 7; 1. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_get_recent_body_damage
- Slot: 153 (table entry 0xa260f0)
- Returns: real
- Parameters: a0: object
- Kind: normal
- Status: implemented
- Evaluator: function_19ba64 (164 bytes)
- Behavior: Evaluates 1 argument (object). Reads the thread-local block at offset 0x10 (object datum array). Returns a value computed in the body.
- Evidence: V

### object_get_recent_shield_damage
- Slot: 154 (table entry 0xa260a0)
- Returns: real
- Parameters: a0: object
- Kind: normal
- Status: implemented
- Evaluator: function_19bb08 (164 bytes)
- Behavior: Evaluates 1 argument (object). Reads the thread-local block at offset 0x10 (object datum array). Returns a value computed in the body.
- Evidence: V

### object_can_take_damage
- Slot: 155 (table entry 0xa26050)
- Returns: void
- Parameters: a0: object_list
- Kind: normal
- Status: implemented
- Evaluator: function_19bbac (75 bytes)
- Behavior: Evaluates 1 argument (object_list). Calls function_4fb0c0 with a0 (object_list); 0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_immune_to_friendly_damage
- Slot: 156 (table entry 0xa25e40)
- Returns: void
- Parameters: a0: object_list, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19bbf8 (77 bytes)
- Behavior: Evaluates 2 arguments (object_list, boolean). Calls function_4fb0c0 with a0 (object_list); 20; a1 (boolean). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_cinematic_lod
- Slot: 157 (table entry 0xa25df0)
- Returns: void
- Parameters: a0: object, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19bc48 (139 bytes)
- Behavior: Evaluates 2 arguments (object, boolean). Reads the thread-local block at offset 0x10 (object datum array). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_cinematic_collision
- Slot: 158 (table entry 0xa25f30)
- Returns: void
- Parameters: a0: object, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19bcd4 (153 bytes)
- Behavior: Evaluates 2 arguments (object, boolean). Reads the thread-local block at offset 0x10 (object datum array). Calls function_46fd48 with a0 (object); a0 (object). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_cinematic_visibility
- Slot: 159 (table entry 0xa25ee0)
- Returns: void
- Parameters: a0: object, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19bd70 (71 bytes)
- Behavior: Evaluates 2 arguments (object, boolean). Calls function_474d60 with a0 (object); a1 (boolean). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_type_predict_high
- Slot: 163 (table entry 0xa25c10)
- Returns: void
- Parameters: a0: object_definition
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (any nested expressions run) and then returns 0. No other action is taken.
- Evidence: V

### object_type_predict_low
- Slot: 164 (table entry 0xa25da0)
- Returns: void
- Parameters: a0: object_definition
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (any nested expressions run) and then returns 0. No other action is taken.
- Evidence: V

### object_type_predict
- Slot: 165 (table entry 0xa25d50)
- Returns: void
- Parameters: a0: object_definition
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (any nested expressions run) and then returns 0. No other action is taken.
- Evidence: V

### object_teleport
- Slot: 166 (table entry 0xa25d00)
- Returns: void
- Parameters: a0: object, a1: cutscene_flag
- Kind: normal
- Status: implemented
- Evaluator: function_19be14 (72 bytes)
- Behavior: Evaluates 2 arguments (object, cutscene_flag). Calls function_1ec680 with a0 (object); a1 (cutscene_flag). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_teleport_to_ai_point
- Slot: 167 (table entry 0xa25ad0)
- Returns: void
- Parameters: a0: object, a1: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_19be5c (158 bytes)
- Behavior: Evaluates 2 arguments (object, point_reference). Calls function_6b2a5c with a1 (point_reference). Calls function_1ec468 with a0 (object). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_set_facing
- Slot: 168 (table entry 0xa25a80)
- Returns: void
- Parameters: a0: object, a1: cutscene_flag
- Kind: normal
- Status: implemented
- Evaluator: function_19befc (72 bytes)
- Behavior: Evaluates 2 arguments (object, cutscene_flag). Calls function_1ec764 with a0 (object); a1 (cutscene_flag). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_set_shield
- Slot: 169 (table entry 0xa25a30)
- Returns: void
- Parameters: a0: object, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_19bf44 (114 bytes)
- Behavior: Evaluates 2 arguments (object, real). Calls function_49e2fc with a0 (object). Uses read-only constants at data_a8b280. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_set_shield_stun
- Slot: 170 (table entry 0xa25bc0)
- Returns: void
- Parameters: a0: object, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_19bfb8 (90 bytes)
- Behavior: Evaluates 2 arguments (object, real). Calls function_5cc74. Calls function_49e57c with the result of function_5cc74. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_set_shield_stun_infinite
- Slot: 171 (table entry 0xa25b70)
- Returns: void
- Parameters: a0: object
- Kind: normal
- Status: implemented
- Evaluator: function_19c014 (78 bytes)
- Behavior: Evaluates 1 argument (object). Calls function_49e57c with a0 (object); 32767. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_set_permutation
- Slot: 172 (table entry 0xa25b20)
- Returns: void
- Parameters: a0: object, a1: string_id, a2: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19c064 (83 bytes)
- Behavior: Evaluates 3 arguments (object, string_id, string_id). Calls function_4729f4 with a0 (object); a1 (string_id); a2 (string_id); 1. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_set_variant
- Slot: 173 (table entry 0xa258f0)
- Returns: void
- Parameters: a0: object, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19c0b8 (76 bytes)
- Behavior: Evaluates 2 arguments (object, string_id). Calls function_472b70 with a0 (object); a1 (string_id). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_set_region_state
- Slot: 174 (table entry 0xa258a0)
- Returns: void
- Parameters: a0: object, a1: string_id, a2: model_state
- Kind: normal
- Status: implemented
- Evaluator: function_19c104 (202 bytes)
- Behavior: Evaluates 3 arguments (object, string_id, model_state). Reads the thread-local block at offset 0x10 (object datum array). Calls function_1cbf0c with a1 (string_id). Calls function_473110 with a0 (object); the result of function_1cbf0c; a2 (model_state); 1. Reads data_c1a600. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_set_model_state_property
- Slot: 175 (table entry 0xa259e0)
- Returns: void
- Parameters: a0: object, a1: long, a2: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19c1d0 (97 bytes)
- Behavior: Evaluates 3 arguments (object, long, boolean). Calls function_473264 with a0 (object); a1 (long). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_running_sync_action
- Slot: 303 (table entry 0xa233a0)
- Returns: boolean
- Parameters: a0: object, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19e5f0 (173 bytes)
- Behavior: Evaluates 2 arguments (object, string_id). Reads the thread-local block at offset 0x10 (object datum array). Returns a value computed in the body.
- Evidence: V

### object_set_custom_animations_hold_on_last_frame
- Slot: 304 (table entry 0xa23350)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19e6a0 (95 bytes)
- Behavior: Evaluates 1 argument (boolean). Reads the thread-local block at offset 0x140. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_set_custom_animations_prevent_lipsync_head_movement
- Slot: 305 (table entry 0xa23300)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19e700 (95 bytes)
- Behavior: Evaluates 1 argument (boolean). Reads the thread-local block at offset 0x140. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### object_get_turret_count
- Slot: 317 (table entry 0xa22de0)
- Returns: short
- Parameters: a0: object
- Kind: normal
- Status: implemented
- Evaluator: function_19ec1c (223 bytes)
- Behavior: Evaluates 1 argument (object). Reads the thread-local block at offset 0x10 (object datum array). Calls function_4ac1e4 with 16. Contains a loop. Returns a value computed in the body.
- Evidence: V

### object_get_turret
- Slot: 318 (table entry 0xa22d90)
- Returns: vehicle
- Parameters: a0: object, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_19ecfc (72 bytes)
- Behavior: Evaluates 2 arguments (object, short). Calls function_4f9c40 with a0 (object); a1 (short). Returns the result of function_4f9c40.
- Evidence: V

## Rendering and interface

### recording_play
- Slot: 205 (table entry 0xa251b0)
- Returns: boolean
- Parameters: a0: unit, a1: cutscene_recording
- Kind: normal
- Status: implemented
- Evaluator: function_19c81c (87 bytes)
- Behavior: Evaluates 2 arguments (unit, cutscene_recording). Calls function_164288 with a0 (unit); a1 (cutscene_recording); 0. Returns a value computed in the body.
- Evidence: V

### recording_play_and_delete
- Slot: 206 (table entry 0xa25160)
- Returns: boolean
- Parameters: a0: unit, a1: cutscene_recording
- Kind: normal
- Status: implemented
- Evaluator: function_19c874 (90 bytes)
- Behavior: Evaluates 2 arguments (unit, cutscene_recording). Calls function_164288 with a0 (unit); a1 (cutscene_recording); 8. Returns a value computed in the body.
- Evidence: V

### recording_play_and_hover
- Slot: 207 (table entry 0xa24f20)
- Returns: boolean
- Parameters: a0: vehicle, a1: cutscene_recording
- Kind: normal
- Status: implemented
- Evaluator: function_19c8d0 (90 bytes)
- Behavior: Evaluates 2 arguments (vehicle, cutscene_recording). Calls function_164288 with a0 (vehicle); a1 (cutscene_recording); 16. Returns a value computed in the body.
- Evidence: V

### recording_kill
- Slot: 208 (table entry 0xa24ed0)
- Returns: void
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19c92c (80 bytes)
- Behavior: Evaluates 1 argument (unit). Calls function_1646c0 with a0 (unit); 0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### recording_time
- Slot: 209 (table entry 0xa24e80)
- Returns: short
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19c97c (170 bytes)
- Behavior: Evaluates 1 argument (unit). Reads the thread-local block at offset 0xa0 (game time block (current tick at +0xc)). Calls function_1646c0 with a0 (unit); 0. Calls function_81b08 with a thread-local structure (offset 0xa0); the result of function_1646c0; 160. Returns a value computed in the body.
- Evidence: V

### render_lights
- Slot: 210 (table entry 0xa25000)
- Returns: boolean
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19ca28 (107 bytes)
- Behavior: Evaluates 1 argument (boolean). Reads the thread-local block at offset 0x4a8. Returns a value computed in the body.
- Evidence: V

### render_lights_enable_cinematic_shadow
- Slot: 212 (table entry 0xa24f70)
- Returns: void
- Parameters: a0: boolean, a1: object, a2: string_id, a3: real
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (any nested expressions run) and then returns 0. No other action is taken.
- Evidence: V

### texture_camera_set_object_marker
- Slot: 213 (table entry 0xa24d40)
- Returns: void
- Parameters: a0: object, a1: string_id, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_19ca94 (76 bytes)
- Behavior: Evaluates 3 arguments (object, string_id, real). Calls function_25c0a8 with a0 (object); a1 (string_id). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### texture_camera_set_position
- Slot: 214 (table entry 0xa24cf0)
- Returns: void
- Parameters: a0: real, a1: real, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_19cae0 (136 bytes)
- Behavior: Evaluates 3 arguments (real, real, real). Reads the thread-local block at offset 0xb8. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### texture_camera_set_target
- Slot: 215 (table entry 0xa24ca0)
- Returns: void
- Parameters: a0: real, a1: real, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_19cb68 (125 bytes)
- Behavior: Evaluates 3 arguments (real, real, real). Reads the thread-local block at offset 0xb8. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### texture_camera_attach_to_object
- Slot: 216 (table entry 0xa24e30)
- Returns: void
- Parameters: a0: object, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19cbe8 (71 bytes)
- Behavior: Evaluates 2 arguments (object, string_id). Calls function_25c008 with a0 (object); a1 (string_id). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### texture_camera_target_object
- Slot: 217 (table entry 0xa24de0)
- Returns: void
- Parameters: a0: object, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19cc30 (138 bytes)
- Behavior: Evaluates 2 arguments (object, string_id). Reads the thread-local block at offset 0xb8. Calls function_4739cc with a0 (object); -1. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### texture_camera_position_world_offset
- Slot: 218 (table entry 0xa24d90)
- Returns: void
- Parameters: a0: real, a1: real, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_19ccbc (115 bytes)
- Behavior: Evaluates 3 arguments (real, real, real). Reads the thread-local block at offset 0xb8. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### texture_camera_on
- Slot: 219 (table entry 0xa24bc0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_19cd30 (44 bytes)
- Behavior: Takes no arguments. Reads the thread-local block at offset 0xb8. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### texture_camera_bink
- Slot: 220 (table entry 0xa24b80)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_19cd5c (46 bytes)
- Behavior: Takes no arguments. Reads the thread-local block at offset 0xb8. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### texture_camera_off
- Slot: 221 (table entry 0xa24b40)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_19cd8c (45 bytes)
- Behavior: Takes no arguments. Reads the thread-local block at offset 0xb8. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### texture_camera_set_aspect_ratio
- Slot: 222 (table entry 0xa24c50)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: implemented
- Evaluator: function_19cdbc (95 bytes)
- Behavior: Evaluates 1 argument (real). Reads the thread-local block at offset 0xb8. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### texture_camera_set_resolution
- Slot: 223 (table entry 0xa24c00)
- Returns: void
- Parameters: a0: long, a1: long
- Kind: normal
- Status: implemented
- Evaluator: function_19ce1c (143 bytes)
- Behavior: Evaluates 2 arguments (long, long). Reads the thread-local block at offset 0xb8. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### texture_camera_render_mode
- Slot: 224 (table entry 0xa24a00)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_19ceac (110 bytes)
- Behavior: Evaluates 1 argument (long). Reads the thread-local block at offset 0xb8. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### texture_camera_set_fov
- Slot: 225 (table entry 0xa249b0)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: implemented
- Evaluator: function_19cf1c (70 bytes)
- Behavior: Evaluates 1 argument (real). Calls function_25c060. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### texture_camera_set_fov_frame_target
- Slot: 226 (table entry 0xa24960)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: implemented
- Evaluator: function_19cf64 (105 bytes)
- Behavior: Evaluates 1 argument (real). Reads the thread-local block at offset 0xb8. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### texture_camera_enable_dynamic_lights
- Slot: 227 (table entry 0xa24af0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19cfd0 (95 bytes)
- Behavior: Evaluates 1 argument (boolean). Reads the thread-local block at offset 0xb8. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### hud_camera_on
- Slot: 228 (table entry 0xa24aa0)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_19d030 (124 bytes)
- Behavior: Evaluates 1 argument (long). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### hud_camera_off
- Slot: 229 (table entry 0xa24a50)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_19d0ac (124 bytes)
- Behavior: Evaluates 1 argument (long). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### hud_camera_set_position
- Slot: 230 (table entry 0xa24820)
- Returns: void
- Parameters: a0: long, a1: real, a2: real, a3: real
- Kind: normal
- Status: implemented
- Evaluator: function_19d128 (168 bytes)
- Behavior: Evaluates 4 arguments (long, real, real, real). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### hud_camera_set_target
- Slot: 231 (table entry 0xa247d0)
- Returns: void
- Parameters: a0: long, a1: real, a2: real, a3: real
- Kind: normal
- Status: implemented
- Evaluator: function_19d1d0 (168 bytes)
- Behavior: Evaluates 4 arguments (long, real, real, real). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### hud_camera_attach_to_object
- Slot: 232 (table entry 0xa24910)
- Returns: void
- Parameters: a0: long, a1: object, a2: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19d278 (193 bytes)
- Behavior: Evaluates 3 arguments (long, object, string_id). Calls function_4739cc with a1 (object); -1; 976. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### hud_camera_target_object
- Slot: 233 (table entry 0xa248c0)
- Returns: void
- Parameters: a0: long, a1: object, a2: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19d33c (193 bytes)
- Behavior: Evaluates 3 arguments (long, object, string_id). Calls function_4739cc with a1 (object); -1; 976. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### hud_camera_structure
- Slot: 234 (table entry 0xa24870)
- Returns: void
- Parameters: a0: long, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19d400 (155 bytes)
- Behavior: Evaluates 2 arguments (long, boolean). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### hud_camera_highlight_object
- Slot: 235 (table entry 0xa24690)
- Returns: void
- Parameters: a0: long, a1: object, a2: real, a3: real, a4: real, a5: real
- Kind: normal
- Status: implemented
- Evaluator: function_19d49c (169 bytes)
- Behavior: Evaluates 6 arguments (long, object, real, real, real, real). Calls function_25c8c4 with a1 (object). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### hud_camera_clear_objects
- Slot: 236 (table entry 0xa24640)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_19d548 (145 bytes)
- Behavior: Evaluates 1 argument (long). Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### hud_camera_spin_around
- Slot: 237 (table entry 0xa245f0)
- Returns: void
- Parameters: a0: long, a1: object
- Kind: normal
- Status: implemented
- Evaluator: function_19d5dc (219 bytes)
- Behavior: Evaluates 2 arguments (long, object). Calls function_4739cc with a1 (object); -1; 976. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### hud_camera_from_player_view
- Slot: 238 (table entry 0xa24780)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_19d6b8 (124 bytes)
- Behavior: Evaluates 1 argument (long). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### hud_camera_window
- Slot: 239 (table entry 0xa24730)
- Returns: void
- Parameters: a0: long, a1: real, a2: real, a3: real, a4: real
- Kind: normal
- Status: implemented
- Evaluator: function_19d734 (252 bytes)
- Behavior: Evaluates 5 arguments (long, real, real, real, real). Uses read-only constants at data_a8aa84, data_a8aef0, data_a8af18. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### render_postprocess_color_tweaking_reset
- Slot: 267 (table entry 0xa23d00)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_19d8d0 (46 bytes)
- Behavior: Takes no arguments. Writes data_29dba18, data_29dba1c, data_29dba24. Writes data_29dba18, data_29dba1c, data_29dba24. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### custom_animation
- Slot: 289 (table entry 0xa23620)
- Returns: boolean
- Parameters: a0: unit, a1: animation_graph, a2: string_id, a3: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19e078 (91 bytes)
- Behavior: Evaluates 4 arguments (unit, animation_graph, string_id, boolean). Calls function_4fa00c with a0 (unit); a1 (animation_graph); a2 (string_id); a3 (boolean). Returns a value computed in the body.
- Evidence: V

### custom_animation_loop
- Slot: 290 (table entry 0xa237b0)
- Returns: boolean
- Parameters: a0: unit, a1: animation_graph, a2: string_id, a3: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19e0d4 (212 bytes)
- Behavior: Evaluates 4 arguments (unit, animation_graph, string_id, boolean). Calls function_78932a (a memset thunk) with 0. Calls function_49f24c with a0 (unit). Uses read-only constants at data_a8b7e8. Returns a value computed in the body.
- Evidence: V

### custom_animation_relative
- Slot: 291 (table entry 0xa23760)
- Returns: boolean
- Parameters: a0: unit, a1: animation_graph, a2: string_id, a3: boolean, a4: object
- Kind: normal
- Status: implemented
- Evaluator: function_19e1a8 (98 bytes)
- Behavior: Evaluates 5 arguments (unit, animation_graph, string_id, boolean, object). Calls function_4fa0e8 with a0 (unit); a1 (animation_graph); a2 (string_id); a3 (boolean). Returns a value computed in the body.
- Evidence: V

### custom_animation_relative_loop
- Slot: 292 (table entry 0xa23710)
- Returns: boolean
- Parameters: a0: unit, a1: animation_graph, a2: string_id, a3: boolean, a4: object
- Kind: normal
- Status: implemented
- Evaluator: function_19e20c (213 bytes)
- Behavior: Evaluates 5 arguments (unit, animation_graph, string_id, boolean, object). Calls function_78932a (a memset thunk) with 0. Calls function_49f24c with a0 (unit). Uses read-only constants at data_a8b7e8. Returns a value computed in the body.
- Evidence: V

### custom_animation_list
- Slot: 293 (table entry 0xa23490)
- Returns: boolean
- Parameters: a0: object_list, a1: animation_graph, a2: string_id, a3: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19e2e4 (186 bytes)
- Behavior: Evaluates 4 arguments (object_list, animation_graph, string_id, boolean). Calls function_192b34 with a0 (object_list). Calls function_4739cc with 4099. Calls function_4fa00c with a1 (animation_graph); a2 (string_id); a3 (boolean). Calls function_192b80. Contains a loop. Returns a value computed in the body.
- Evidence: V

### animation_capture_set_file_name
- Slot: 298 (table entry 0xa234e0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### animation_capture_set_origin_object_name
- Slot: 299 (table entry 0xa232b0)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### animation_capture_start_recording
- Slot: 300 (table entry 0xa23270)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### animation_capture_stop_recording
- Slot: 301 (table entry 0xa23230)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### preferred_animation_list_add
- Slot: 306 (table entry 0xa230f0)
- Returns: boolean
- Parameters: a0: object, a1: string_id
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (any nested expressions run) and then returns 0. No other action is taken.
- Evidence: V

### preferred_animation_list_clear
- Slot: 307 (table entry 0xa230b0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### animation_stats_dump
- Slot: 358 (table entry 0xa222c0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

## Units, vehicles, weapons and devices

### scenery_animation_start
- Slot: 271 (table entry 0xa23bc0)
- Returns: void
- Parameters: a0: scenery, a1: animation_graph, a2: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19d900 (93 bytes)
- Behavior: Evaluates 3 arguments (scenery, animation_graph, string_id). Calls function_4fdfac with a0 (scenery); a1 (animation_graph); a2 (string_id); 0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### scenery_animation_start_loop
- Slot: 272 (table entry 0xa23b70)
- Returns: void
- Parameters: a0: scenery, a1: animation_graph, a2: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19d960 (93 bytes)
- Behavior: Evaluates 3 arguments (scenery, animation_graph, string_id). Calls function_4fdfac with a0 (scenery); a1 (animation_graph); a2 (string_id); 0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### scenery_animation_start_relative
- Slot: 273 (table entry 0xa23b20)
- Returns: void
- Parameters: a0: scenery, a1: animation_graph, a2: string_id, a3: object
- Kind: normal
- Status: implemented
- Evaluator: function_19d9c0 (95 bytes)
- Behavior: Evaluates 4 arguments (scenery, animation_graph, string_id, object). Calls function_4fdfac with a0 (scenery); a1 (animation_graph); a2 (string_id); 0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### scenery_animation_start_relative_loop
- Slot: 274 (table entry 0xa23cb0)
- Returns: void
- Parameters: a0: scenery, a1: animation_graph, a2: string_id, a3: object
- Kind: normal
- Status: implemented
- Evaluator: function_19da20 (95 bytes)
- Behavior: Evaluates 4 arguments (scenery, animation_graph, string_id, object). Calls function_4fdfac with a0 (scenery); a1 (animation_graph); a2 (string_id); 0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### scenery_animation_start_at_frame
- Slot: 275 (table entry 0xa23c60)
- Returns: void
- Parameters: a0: scenery, a1: animation_graph, a2: string_id, a3: short
- Kind: normal
- Status: implemented
- Evaluator: function_19da80 (95 bytes)
- Behavior: Evaluates 4 arguments (scenery, animation_graph, string_id, short). Calls function_4fdfac with a0 (scenery); a1 (animation_graph); a2 (string_id); a3 (short). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### scenery_animation_start_relative_at_frame
- Slot: 276 (table entry 0xa23c10)
- Returns: void
- Parameters: a0: scenery, a1: animation_graph, a2: string_id, a3: object, a4: short
- Kind: normal
- Status: implemented
- Evaluator: function_19dae0 (97 bytes)
- Behavior: Evaluates 5 arguments (scenery, animation_graph, string_id, object, short). Calls function_4fdfac with a0 (scenery); a1 (animation_graph); a2 (string_id); a4 (short). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### scenery_animation_idle
- Slot: 277 (table entry 0xa239e0)
- Returns: void
- Parameters: a0: scenery
- Kind: normal
- Status: implemented
- Evaluator: function_19db44 (68 bytes)
- Behavior: Evaluates 1 argument (scenery). Calls function_4fdc1c with a0 (scenery). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### scenery_get_animation_time
- Slot: 278 (table entry 0xa23990)
- Returns: short
- Parameters: a0: scenery
- Kind: normal
- Status: implemented
- Evaluator: function_19db88 (81 bytes)
- Behavior: Evaluates 1 argument (scenery). Calls function_4fdcbc with a0 (scenery). Returns a value computed in the body.
- Evidence: V

### unit_can_blink
- Slot: 279 (table entry 0xa23ad0)
- Returns: void
- Parameters: a0: unit, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19dbdc (145 bytes)
- Behavior: Evaluates 2 arguments (unit, boolean). Reads the thread-local block at offset 0x10 (object datum array). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_set_active_camo
- Slot: 280 (table entry 0xa23a80)
- Returns: void
- Parameters: a0: unit, a1: boolean, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_19dc70 (86 bytes)
- Behavior: Evaluates 3 arguments (unit, boolean, real). When the unit is not -1 calls function_494a78(unit, mode), where mode is 3 when the boolean is true and -1 when it is false. The real argument is not read. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_open
- Slot: 281 (table entry 0xa23a30)
- Returns: void
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19dcc8 (68 bytes)
- Behavior: Evaluates 1 argument (unit). Calls function_4f9184 with a0 (unit). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_close
- Slot: 282 (table entry 0xa238a0)
- Returns: void
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19dd0c (125 bytes)
- Behavior: Evaluates 1 argument (unit). Reads the thread-local block at offset 0x10 (object datum array). Calls function_46c854 with a0 (unit); a thread-local structure (offset 0x10). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_kill
- Slot: 283 (table entry 0xa23850)
- Returns: void
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19dd8c (89 bytes)
- Behavior: Evaluates 1 argument (unit). Calls function_47caa8 with a0 (unit); 0; 1; 2. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_kill_silent
- Slot: 284 (table entry 0xa23800)
- Returns: void
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19dde8 (90 bytes)
- Behavior: Evaluates 1 argument (unit). Calls function_47caa8 with a0 (unit); 1; 1; 2. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_is_emitting
- Slot: 285 (table entry 0xa23940)
- Returns: boolean
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19de44 (163 bytes)
- Behavior: Evaluates 1 argument (unit). A unit of -1 gives false. Otherwise the object record is found through the object array (thread-local offset 0x10); when bit 2 of the dword at +0x138 of that record is set the result is false, otherwise the result is the boolean returned by function_49f5b8(unit, 0x25).
- Evidence: V

### unit_is_emp_stunned
- Slot: 286 (table entry 0xa238f0)
- Returns: boolean
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19dee8 (162 bytes)
- Behavior: Evaluates 1 argument (unit). Reads the thread-local block at offset 0x10 (object datum array). Uses read-only constants at data_a7a434. Returns a value computed in the body.
- Evidence: V

### unit_get_custom_animation_time
- Slot: 287 (table entry 0xa236c0)
- Returns: short
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19df8c (153 bytes)
- Behavior: Evaluates 1 argument (unit). Calls function_4c6ce0 with a0 (unit). Calls function_4c6e48. Calls function_81b08. Returns a value computed in the body.
- Evidence: V

### unit_stop_custom_animation
- Slot: 288 (table entry 0xa23670)
- Returns: void
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19e028 (78 bytes)
- Behavior: Evaluates 1 argument (unit). Calls function_49f210 with a0 (unit); 2. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_custom_animation_at_frame
- Slot: 294 (table entry 0xa23440)
- Returns: boolean
- Parameters: a0: unit, a1: animation_graph, a2: string_id, a3: boolean, a4: short
- Kind: normal
- Status: implemented
- Evaluator: function_19e3a0 (158 bytes)
- Behavior: Evaluates 5 arguments (unit, animation_graph, string_id, boolean, short). Calls function_4fa00c with a0 (unit); a1 (animation_graph); a2 (string_id); a3 (boolean). Calls function_4cba50 with a0 (unit). Uses read-only constants at data_a8b3d8. Returns a value computed in the body.
- Evidence: V

### unit_custom_animation_relative_at_frame
- Slot: 295 (table entry 0xa235d0)
- Returns: boolean
- Parameters: a0: unit, a1: animation_graph, a2: string_id, a3: string_id, a4: boolean, a5: short
- Kind: normal
- Status: implemented
- Evaluator: function_19e440 (167 bytes)
- Behavior: Evaluates 6 arguments (unit, animation_graph, string_id, string_id, boolean, short). Calls function_4fa0e8 with a0 (unit); a1 (animation_graph); a2 (string_id); a4 (boolean). Calls function_4cba50 with a0 (unit). Uses read-only constants at data_a8b3d8. Returns a value computed in the body.
- Evidence: V

### unit_is_playing_custom_animation
- Slot: 296 (table entry 0xa23580)
- Returns: boolean
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19e4e8 (100 bytes)
- Behavior: Evaluates 1 argument (unit). Calls function_49f5b8 with a0 (unit). Returns a value computed in the body.
- Evidence: V

### unit_has_mandibles_hidden
- Slot: 297 (table entry 0xa23530)
- Returns: boolean
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19e54c (80 bytes)
- Behavior: Evaluates 1 argument (unit). Calls function_4fa274 with a0 (unit). Returns a value computed in the body.
- Evidence: V

### unit_get_team_index
- Slot: 308 (table entry 0xa23060)
- Returns: short
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19e760 (101 bytes)
- Behavior: Evaluates 1 argument (unit). Calls function_4739cc with a0 (unit); 4099. Returns a value computed in the body.
- Evidence: V

### unit_aim_without_turning
- Slot: 309 (table entry 0xa231e0)
- Returns: void
- Parameters: a0: unit, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19e7c8 (145 bytes)
- Behavior: Evaluates 2 arguments (unit, boolean). Reads the thread-local block at offset 0x10 (object datum array). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_set_enterable_by_player
- Slot: 310 (table entry 0xa23190)
- Returns: void
- Parameters: a0: unit, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19e85c (145 bytes)
- Behavior: Evaluates 2 arguments (unit, boolean). Reads the thread-local block at offset 0x10 (object datum array). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_get_enterable_by_player
- Slot: 311 (table entry 0xa23140)
- Returns: boolean
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19e8f0 (144 bytes)
- Behavior: Evaluates 1 argument (unit). Reads the thread-local block at offset 0x10 (object datum array). Returns a value computed in the body.
- Evidence: V

### unit_only_takes_damage_from_players_team
- Slot: 312 (table entry 0xa22f20)
- Returns: void
- Parameters: a0: unit, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19e980 (145 bytes)
- Behavior: Evaluates 2 arguments (unit, boolean). Reads the thread-local block at offset 0x10 (object datum array). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_enter_vehicle
- Slot: 313 (table entry 0xa22ed0)
- Returns: void
- Parameters: a0: unit, a1: vehicle, a2: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19ea14 (78 bytes)
- Behavior: Evaluates 3 arguments (unit, vehicle, string_id). Calls function_4f97bc with a0 (unit); a1 (vehicle); a2 (string_id); 0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_enter_vehicle_immediate
- Slot: 314 (table entry 0xa23010)
- Returns: void
- Parameters: a0: unit, a1: vehicle, a2: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19ea64 (78 bytes)
- Behavior: Evaluates 3 arguments (unit, vehicle, string_id). Calls function_4f97bc with a0 (unit); a1 (vehicle); a2 (string_id); 1. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_falling_damage_disable
- Slot: 315 (table entry 0xa22fc0)
- Returns: void
- Parameters: a0: unit, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19eab4 (145 bytes)
- Behavior: Evaluates 2 arguments (unit, boolean). Reads the thread-local block at offset 0x10 (object datum array). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_in_vehicle_type
- Slot: 316 (table entry 0xa22f70)
- Returns: boolean
- Parameters: a0: unit, a1: long
- Kind: normal
- Status: implemented
- Evaluator: function_19eb48 (209 bytes)
- Behavior: Evaluates 2 arguments (unit, long). Reads the thread-local block at offset 0x10 (object datum array). Calls function_473d70 with a thread-local structure (offset 0x10); a0 (unit). Calls function_a17cc with the result of function_473d70. Returns a value computed in the body.
- Evidence: V

### unit_board_vehicle
- Slot: 319 (table entry 0xa22d40)
- Returns: void
- Parameters: a0: unit, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19ed44 (71 bytes)
- Behavior: Evaluates 2 arguments (unit, string_id). Calls function_4f9994 with a0 (unit); a1 (string_id). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_set_emotion
- Slot: 320 (table entry 0xa22e80)
- Returns: void
- Parameters: a0: unit, a1: long, a2: real, a3: real
- Kind: normal
- Status: implemented
- Evaluator: function_19ed8c (86 bytes)
- Behavior: Evaluates 4 arguments (unit, long, real, real). Calls function_4ce668 with a0 (unit); a1 (long). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_set_emotion_by_name
- Slot: 321 (table entry 0xa22e30)
- Returns: void
- Parameters: a0: unit, a1: string_id, a2: real, a3: real
- Kind: normal
- Status: implemented
- Evaluator: function_19ede4 (86 bytes)
- Behavior: Evaluates 4 arguments (unit, string_id, real, real). Calls function_4ce700 with a0 (unit); a1 (string_id). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_enable_eye_tracking
- Slot: 322 (table entry 0xa22c00)
- Returns: void
- Parameters: a0: unit, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19ee3c (164 bytes)
- Behavior: Evaluates 2 arguments (unit, boolean). Reads the thread-local block at offset 0x10 (object datum array). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_set_integrated_flashlight
- Slot: 323 (table entry 0xa22bb0)
- Returns: void
- Parameters: a0: unit, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19eee0 (71 bytes)
- Behavior: Evaluates 2 arguments (unit, boolean). Calls function_4f9294 with a0 (unit); a1 (boolean). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_in_vehicle
- Slot: 324 (table entry 0xa22b60)
- Returns: boolean
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19ef28 (80 bytes)
- Behavior: Evaluates 1 argument (unit). Calls function_4f9368 with a0 (unit). Returns a value computed in the body.
- Evidence: V

### unit_get_vehicle
- Slot: 325 (table entry 0xa22cf0)
- Returns: vehicle
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19ef78 (183 bytes)
- Behavior: Evaluates 1 argument (unit). Reads the thread-local block at offset 0x10 (object datum array). Calls function_473dc0 with a0 (unit); 16. Calls function_4ac1e4 with the result of function_473dc0. Returns a value computed in the body.
- Evidence: V

### vehicle_set_player_interaction
- Slot: 326 (table entry 0xa22ca0)
- Returns: void
- Parameters: a0: vehicle, a1: unit_seat_mapping, a2: boolean, a3: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19f030 (79 bytes)
- Behavior: Evaluates 4 arguments (vehicle, unit_seat_mapping, boolean, boolean). Calls function_4f953c with a0 (vehicle); a1 (unit_seat_mapping); a2 (boolean); a3 (boolean). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### vehicle_set_unit_interaction
- Slot: 327 (table entry 0xa22c50)
- Returns: void
- Parameters: a0: vehicle, a1: unit_seat_mapping, a2: boolean, a3: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19f030 (79 bytes)
- Behavior: Evaluates 4 arguments (vehicle, unit_seat_mapping, boolean, boolean). Calls function_4f953c with a0 (vehicle); a1 (unit_seat_mapping); a2 (boolean); a3 (boolean). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### vehicle_test_seat_unit_list
- Slot: 328 (table entry 0xa22a20)
- Returns: boolean
- Parameters: a0: vehicle, a1: unit_seat_mapping, a2: object_list
- Kind: normal
- Status: implemented
- Evaluator: function_19f080 (87 bytes)
- Behavior: Evaluates 3 arguments (vehicle, unit_seat_mapping, object_list). Calls function_4f9688 with a0 (vehicle); a1 (unit_seat_mapping); a2 (object_list). Returns a value computed in the body.
- Evidence: V

### vehicle_test_seat_unit
- Slot: 329 (table entry 0xa229d0)
- Returns: boolean
- Parameters: a0: vehicle, a1: unit_seat_mapping, a2: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19f0d8 (87 bytes)
- Behavior: Evaluates 3 arguments (vehicle, unit_seat_mapping, unit). Calls function_4f9474 with a0 (vehicle); a1 (unit_seat_mapping); a2 (unit). Returns a value computed in the body.
- Evidence: V

### vehicle_test_seat
- Slot: 330 (table entry 0xa22980)
- Returns: boolean
- Parameters: a0: vehicle, a1: unit_seat_mapping
- Kind: normal
- Status: implemented
- Evaluator: function_19f130 (83 bytes)
- Behavior: Evaluates 2 arguments (vehicle, unit_seat_mapping). Calls function_4f941c with a0 (vehicle); a1 (unit_seat_mapping). Returns a value computed in the body.
- Evidence: V

### unit_set_prefer_tight_camera_track
- Slot: 331 (table entry 0xa22b10)
- Returns: void
- Parameters: a0: unit, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19f184 (118 bytes)
- Behavior: Evaluates 2 arguments (unit, boolean). Calls function_4739cc with a0 (unit); 4099. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_test_seat
- Slot: 332 (table entry 0xa22ac0)
- Returns: boolean
- Parameters: a0: unit, a1: unit_seat_mapping
- Kind: normal
- Status: implemented
- Evaluator: function_19f130 (83 bytes)
- Behavior: Evaluates 2 arguments (unit, unit_seat_mapping). Calls function_4f941c with a0 (unit); a1 (unit_seat_mapping). Returns a value computed in the body.
- Evidence: V

### unit_exit_vehicle (slot 333)
- Slot: 333 (table entry 0xa22a70)
- Returns: void
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19f1fc (70 bytes)
- Behavior: Evaluates 1 argument (unit). Calls function_4f9a74 with a0 (unit); 0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_exit_vehicle (slot 334)
- Slot: 334 (table entry 0xa22840)
- Returns: void
- Parameters: a0: unit, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_19f244 (72 bytes)
- Behavior: Evaluates 2 arguments (unit, short). Calls function_4f9a74 with a0 (unit); a1 (short). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_set_maximum_vitality
- Slot: 335 (table entry 0xa227f0)
- Returns: void
- Parameters: a0: unit, a1: real, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_19f28c (78 bytes)
- Behavior: Evaluates 3 arguments (unit, real, real). Calls function_4f8ee8 with a0 (unit). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### units_set_maximum_vitality
- Slot: 336 (table entry 0xa22930)
- Returns: void
- Parameters: a0: object_list, a1: real, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_19f2dc (133 bytes)
- Behavior: Evaluates 3 arguments (object_list, real, real). Calls function_192b34 with a0 (object_list). Calls function_4f8ee8 with the result of function_192b34. Calls function_192b80. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_set_current_vitality
- Slot: 337 (table entry 0xa228e0)
- Returns: void
- Parameters: a0: unit, a1: real, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_19f364 (78 bytes)
- Behavior: Evaluates 3 arguments (unit, real, real). Calls function_4f8f4c with a0 (unit). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### units_set_current_vitality
- Slot: 338 (table entry 0xa22890)
- Returns: void
- Parameters: a0: object_list, a1: real, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_19f3b4 (133 bytes)
- Behavior: Evaluates 3 arguments (object_list, real, real). Calls function_192b34 with a0 (object_list). Calls function_4f8f4c with the result of function_192b34. Calls function_192b80. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### vehicle_load_magic
- Slot: 339 (table entry 0xa22710)
- Returns: short
- Parameters: a0: object, a1: unit_seat_mapping, a2: object_list
- Kind: normal
- Status: implemented
- Evaluator: function_19f43c (88 bytes)
- Behavior: Evaluates 3 arguments (object, unit_seat_mapping, object_list). Calls function_4f9cf8 with a0 (object); a1 (unit_seat_mapping); a2 (object_list). Returns a value computed in the body.
- Evidence: V

### vehicle_unload
- Slot: 340 (table entry 0xa226c0)
- Returns: short
- Parameters: a0: object, a1: unit_seat_mapping
- Kind: normal
- Status: implemented
- Evaluator: function_19f494 (84 bytes)
- Behavior: Evaluates 2 arguments (object, unit_seat_mapping). Calls function_4f9f38 with a0 (object); a1 (unit_seat_mapping). Returns a value computed in the body.
- Evidence: V

### unit_set_animation_mode
- Slot: 341 (table entry 0xa22670)
- Returns: void
- Parameters: a0: unit, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_19f4e8 (132 bytes)
- Behavior: Evaluates 2 arguments (unit, string_id). Reads the thread-local block at offset 0x10 (object datum array). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### vehicle_riders
- Slot: 343 (table entry 0xa22760)
- Returns: object_list
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19f5f0 (68 bytes)
- Behavior: Evaluates 1 argument (unit). Calls function_4f9b78 with a0 (unit). Returns the result of function_4f9b78.
- Evidence: V

### vehicle_driver
- Slot: 344 (table entry 0xa22530)
- Returns: unit
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19f634 (85 bytes)
- Behavior: Evaluates 1 argument (unit). Calls function_4739cc with a0 (unit); 4099. Returns a value computed in the body.
- Evidence: V

### vehicle_gunner
- Slot: 345 (table entry 0xa224e0)
- Returns: unit
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19f68c (85 bytes)
- Behavior: Evaluates 1 argument (unit). Calls function_4739cc with a0 (unit); 4099. Returns a value computed in the body.
- Evidence: V

### unit_get_health
- Slot: 346 (table entry 0xa22490)
- Returns: real
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19b014 (129 bytes)
- Behavior: Evaluates 1 argument (unit). Calls function_4739cc with a0 (unit); -1. Calls function_49dbec with a0 (unit). Uses read-only constants at data_a8b7e8. Returns a value computed in the body.
- Evidence: V

### unit_get_shield
- Slot: 347 (table entry 0xa22620)
- Returns: real
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19b098 (129 bytes)
- Behavior: Evaluates 1 argument (unit). Calls function_4739cc with a0 (unit); -1. Calls function_49dcec with a0 (unit). Uses read-only constants at data_a8b7e8. Returns a value computed in the body.
- Evidence: V

### unit_get_total_grenade_count
- Slot: 348 (table entry 0xa225d0)
- Returns: short
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19f6e4 (123 bytes)
- Behavior: Evaluates 1 argument (unit). Calls function_4739cc with a0 (unit); 4099. Contains a loop. Returns a value computed in the body.
- Evidence: V

### unit_has_weapon
- Slot: 349 (table entry 0xa22580)
- Returns: boolean
- Parameters: a0: unit, a1: object_definition
- Kind: normal
- Status: implemented
- Evaluator: function_19f760 (105 bytes)
- Behavior: Evaluates 2 arguments (unit, object_definition). Calls function_48e2c0 with a0 (unit); a1 (object_definition). Returns a value computed in the body.
- Evidence: V

### unit_has_weapon_readied
- Slot: 350 (table entry 0xa22350)
- Returns: boolean
- Parameters: a0: unit, a1: object_definition
- Kind: normal
- Status: implemented
- Evaluator: function_19f7cc (83 bytes)
- Behavior: Evaluates 2 arguments (unit, object_definition). Calls function_4f906c with a0 (unit); a1 (object_definition). Returns a value computed in the body.
- Evidence: V

### unit_has_any_equipment
- Slot: 351 (table entry 0xa22300)
- Returns: boolean
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19f820 (144 bytes)
- Behavior: Evaluates 1 argument (unit). Reads the thread-local block at offset 0x10 (object datum array). Returns a value computed in the body.
- Evidence: V

### unit_has_equipment
- Slot: 352 (table entry 0xa22440)
- Returns: boolean
- Parameters: a0: unit, a1: object_definition
- Kind: normal
- Status: implemented
- Evaluator: function_19f8b0 (184 bytes)
- Behavior: Evaluates 2 arguments (unit, object_definition). Reads the thread-local block at offset 0x10 (object datum array). Returns a value computed in the body.
- Evidence: V

### unit_lower_weapon
- Slot: 353 (table entry 0xa223f0)
- Returns: void
- Parameters: a0: unit, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_19f968 (72 bytes)
- Behavior: Evaluates 2 arguments (unit, short). Calls function_4f91d0 with a0 (unit); a1 (short). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_raise_weapon
- Slot: 354 (table entry 0xa223a0)
- Returns: void
- Parameters: a0: unit, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_19f9b0 (171 bytes)
- Behavior: Evaluates 2 arguments (unit, short). Reads the thread-local block at offset 0x6a0. Calls function_4ce3a0 with a0 (unit). Calls function_2afd70. Calls function_2b5598 with the result of function_2afd70; a1 (short). Uses read-only constants at data_a8b3d8. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_drop_support_weapon
- Slot: 355 (table entry 0xa221d0)
- Returns: void
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19fa5c (228 bytes)
- Behavior: Evaluates 1 argument (unit). Reads the thread-local block at offset 0x10 (object datum array). Calls function_48b3d0 with a0 (unit). Calls function_49f210 with 48. Reads data_c1a600. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_spew_action
- Slot: 356 (table entry 0xa22180)
- Returns: void
- Parameters: a0: unit
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (any nested expressions run) and then returns 0. No other action is taken.
- Evidence: V

### unit_force_reload
- Slot: 357 (table entry 0xa22130)
- Returns: void
- Parameters: a0: unit
- Kind: normal
- Status: implemented
- Evaluator: function_19fb40 (145 bytes)
- Behavior: Evaluates 1 argument (unit). Reads the thread-local block at offset 0x10 (object datum array). Calls function_48b3d0 with a0 (unit); a thread-local structure (offset 0x10). Calls function_4bd290 with the result of function_48b3d0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_animation_forced_seat
- Slot: 359 (table entry 0xa22270)
- Returns: void
- Parameters: a0: string_id
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### unit_doesnt_drop_items
- Slot: 360 (table entry 0xa22220)
- Returns: void
- Parameters: a0: object_list
- Kind: normal
- Status: implemented
- Evaluator: function_19fbd4 (115 bytes)
- Behavior: Evaluates 1 argument (object_list). Calls function_192b34 with a0 (object_list). Calls function_4739cc with the result of function_192b34; 4099. Calls function_192b80. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_impervious
- Slot: 361 (table entry 0xa22040)
- Returns: void
- Parameters: a0: object_list, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19fc48 (145 bytes)
- Behavior: Evaluates 2 arguments (object_list, boolean). Calls function_192b34 with a0 (object_list). Calls function_4739cc with the result of function_192b34; 4099. Calls function_192b80. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_suspended
- Slot: 362 (table entry 0xa21ff0)
- Returns: void
- Parameters: a0: unit, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19fcdc (168 bytes)
- Behavior: Evaluates 2 arguments (unit, boolean). Reads the thread-local block at offset 0x10 (object datum array). Uses read-only constants at data_98faf0, data_98faf8. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### unit_add_equipment
- Slot: 363 (table entry 0xa21fa0)
- Returns: void
- Parameters: a0: unit, a1: starting_profile, a2: boolean, a3: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19fd84 (156 bytes)
- Behavior: Evaluates 4 arguments (unit, starting_profile, boolean, boolean). Calls function_131f50. Calls function_48d570 with a1 (starting_profile). Calls function_48d7f0 with a0 (unit); a2 (boolean); a3 (boolean). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### weapon_set_primary_barrel_firing
- Slot: 364 (table entry 0xa220e0)
- Returns: void
- Parameters: a0: weapon, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19fe20 (167 bytes)
- Behavior: Evaluates 2 arguments (weapon, boolean). Reads the thread-local block at offset 0x10 (object datum array). Calls function_46c854 with a0 (weapon); a0 (weapon). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### weapon_hold_trigger
- Slot: 365 (table entry 0xa22090)
- Returns: void
- Parameters: a0: weapon, a1: long, a2: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19fec8 (234 bytes)
- Behavior: Evaluates 3 arguments (weapon, long, boolean). Reads the thread-local block at offset 0x10 (object datum array). Calls function_46c854 with a0 (weapon); a0 (weapon). Reads data_c1a600. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### weapon_enable_warthog_chaingun_light
- Slot: 366 (table entry 0xa21e60)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_19ffb4 (99 bytes)
- Behavior: Evaluates 1 argument (boolean). Reads the thread-local block at offset 0x3c0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### device_set_never_appears_locked
- Slot: 367 (table entry 0xa21e10)
- Returns: void
- Parameters: a0: device, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a0018 (121 bytes)
- Behavior: Evaluates 2 arguments (device, boolean). Calls function_4739cc with a0 (device); 128. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### device_set_power
- Slot: 368 (table entry 0xa21dc0)
- Returns: void
- Parameters: a0: device, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a0094 (73 bytes)
- Behavior: Evaluates 2 arguments (device, real). Calls function_4d2988 with a0 (device). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### device_set_position_transition_time
- Slot: 369 (table entry 0xa21f50)
- Returns: void
- Parameters: a0: device, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a00e0 (149 bytes)
- Behavior: Evaluates 2 arguments (device, real). Reads the thread-local block at offset 0x10 (object datum array). Uses read-only constants at data_a8ab30, data_a8af18. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### device_get_power
- Slot: 370 (table entry 0xa21f00)
- Returns: real
- Parameters: a0: device
- Kind: normal
- Status: implemented
- Evaluator: function_1a0178 (135 bytes)
- Behavior: Evaluates 1 argument (device). Reads the thread-local block at offset 0x10 (object datum array). Returns a value computed in the body.
- Evidence: V

### device_set_position
- Slot: 371 (table entry 0xa21eb0)
- Returns: boolean
- Parameters: a0: device, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a0200 (85 bytes)
- Behavior: Evaluates 2 arguments (device, real). Calls function_4d2910 with a0 (device). Returns a value computed in the body.
- Evidence: V

### device_get_position
- Slot: 372 (table entry 0xa21c80)
- Returns: real
- Parameters: a0: device
- Kind: normal
- Status: implemented
- Evaluator: function_1a0258 (135 bytes)
- Behavior: Evaluates 1 argument (device). Reads the thread-local block at offset 0x10 (object datum array). Returns a value computed in the body.
- Evidence: V

### device_set_position_immediate
- Slot: 373 (table entry 0xa21c30)
- Returns: void
- Parameters: a0: device, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a02e0 (73 bytes)
- Behavior: Evaluates 2 arguments (device, real). Calls function_4d2b90 with a0 (device). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### device_group_get
- Slot: 374 (table entry 0xa21d70)
- Returns: real
- Parameters: a0: device_group
- Kind: normal
- Status: implemented
- Evaluator: function_1a032c (117 bytes)
- Behavior: Evaluates 1 argument (device_group). Reads the thread-local block at offset 0x210. Returns a value computed in the body.
- Evidence: V

### device_group_set
- Slot: 375 (table entry 0xa21d20)
- Returns: boolean
- Parameters: a0: device, a1: device_group, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a03a4 (86 bytes)
- Behavior: Evaluates 3 arguments (device, device_group, real). Calls function_4d2a04 with a1 (device_group). Returns a value computed in the body.
- Evidence: V

### device_group_set_immediate
- Slot: 376 (table entry 0xa21cd0)
- Returns: void
- Parameters: a0: device_group, a1: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a03fc (73 bytes)
- Behavior: Evaluates 2 arguments (device_group, real). Calls function_4d2c50 with a0 (device_group). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### device_one_sided_set
- Slot: 377 (table entry 0xa21b40)
- Returns: void
- Parameters: a0: device, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a0448 (116 bytes)
- Behavior: Evaluates 2 arguments (device, boolean). Calls function_4739cc with a0 (device); 128. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### device_ignore_player_set
- Slot: 378 (table entry 0xa21af0)
- Returns: void
- Parameters: a0: device, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a04bc (143 bytes)
- Behavior: Evaluates 2 arguments (device, boolean). Calls function_4739cc with a0 (device); 128. Calls function_46c854 with a0 (device). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### device_operates_automatically_set
- Slot: 379 (table entry 0xa21aa0)
- Returns: void
- Parameters: a0: device, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a054c (141 bytes)
- Behavior: Evaluates 2 arguments (device, boolean). Calls function_4739cc with a0 (device); 128. Calls function_46c854 with a0 (device). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### device_closes_automatically_set
- Slot: 380 (table entry 0xa21be0)
- Returns: void
- Parameters: a0: device, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a05dc (141 bytes)
- Behavior: Evaluates 2 arguments (device, boolean). Calls function_4739cc with a0 (device); 128. Calls function_46c854 with a0 (device). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### device_group_change_only_once_more_set
- Slot: 381 (table entry 0xa21b90)
- Returns: void
- Parameters: a0: device_group, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a066c (71 bytes)
- Behavior: Evaluates 2 arguments (device_group, boolean). Calls function_4d2e10 with a0 (device_group); a1 (boolean). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### device_set_position_track
- Slot: 382 (table entry 0xa21940)
- Returns: boolean
- Parameters: a0: device, a1: string_id, a2: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a06b4 (88 bytes)
- Behavior: Evaluates 3 arguments (device, string_id, real). Calls function_4d3b60 with a0 (device); a1 (string_id). Returns a value computed in the body.
- Evidence: V

### device_set_overlay_track
- Slot: 383 (table entry 0xa218f0)
- Returns: boolean
- Parameters: a0: device, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a070c (83 bytes)
- Behavior: Evaluates 2 arguments (device, string_id). Calls function_4d421c with a0 (device); a1 (string_id). Returns a value computed in the body.
- Evidence: V

### device_animate_position
- Slot: 384 (table entry 0xa218a0)
- Returns: void
- Parameters: a0: device, a1: real, a2: real, a3: real, a4: real, a5: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a0760 (101 bytes)
- Behavior: Evaluates 6 arguments (device, real, real, real, real, boolean). Calls function_4d432c with a0 (device). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### device_animate_overlay
- Slot: 385 (table entry 0xa21a50)
- Returns: void
- Parameters: a0: device, a1: real, a2: real, a3: real, a4: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a07c8 (175 bytes)
- Behavior: Evaluates 5 arguments (device, real, real, real, real). Calls function_4739cc with a0 (device); 400. Calls function_4d3498. Calls function_46c854 with a0 (device). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### cheat_all_weapons
- Slot: 386 (table entry 0xa21a10)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### cheat_all_vehicles
- Slot: 387 (table entry 0xa219d0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### cheat_teleport_to_camera
- Slot: 388 (table entry 0xa21990)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### cheat_active_camouflage
- Slot: 389 (table entry 0xa21710)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### cheat_active_camouflage_by_player
- Slot: 390 (table entry 0xa216c0)
- Returns: void
- Parameters: a0: player, a1: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### cheats_load
- Slot: 391 (table entry 0xa21680)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### drop_safe
- Slot: 392 (table entry 0xa21630)
- Returns: void
- Parameters: a0: any_tag
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### drop_variant
- Slot: 394 (table entry 0xa21800)
- Returns: void
- Parameters: a0: string, a1: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### drop_permutation
- Slot: 395 (table entry 0xa217b0)
- Returns: void
- Parameters: a0: string, a1: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

## AI and command scripts

### ai_enable
- Slot: 397 (table entry 0xa214f0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a0878 (94 bytes)
- Behavior: Evaluates 1 argument (boolean). Reads the thread-local block at offset 0x30. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_enabled
- Slot: 398 (table entry 0xa214b0)
- Returns: boolean
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1a08d8 (55 bytes)
- Behavior: Takes no arguments. Reads the thread-local block at offset 0x30. Returns a value computed in the body.
- Evidence: V

### ai_grenades
- Slot: 399 (table entry 0xa215e0)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a0910 (98 bytes)
- Behavior: Evaluates 1 argument (boolean). Reads the thread-local block at offset 0x30. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_dialogue_enable
- Slot: 400 (table entry 0xa21590)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a0974 (95 bytes)
- Behavior: Evaluates 1 argument (boolean). Reads the thread-local block at offset 0x30. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_dialogue_updating_enable
- Slot: 401 (table entry 0xa21540)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a09d4 (95 bytes)
- Behavior: Evaluates 1 argument (boolean). Reads the thread-local block at offset 0x30. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_player_dialogue_enable
- Slot: 402 (table entry 0xa21370)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a0a34 (95 bytes)
- Behavior: Evaluates 1 argument (boolean). Reads the thread-local block at offset 0x30. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_actor_dialogue_enable
- Slot: 403 (table entry 0xa21320)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a0a94 (118 bytes)
- Behavior: Evaluates 2 arguments (ai, boolean). Reads the thread-local block at offset 0x30. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_actor_dialogue_effect_enable
- Slot: 404 (table entry 0xa212d0)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a0b0c (118 bytes)
- Behavior: Evaluates 2 arguments (ai, boolean). Reads the thread-local block at offset 0x30. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_infection_suppress
- Slot: 405 (table entry 0xa21460)
- Returns: void
- Parameters: a0: long
- Kind: normal
- Status: implemented
- Evaluator: function_1a0b84 (131 bytes)
- Behavior: Evaluates 1 argument (long). Reads the thread-local block at offset 0x30. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_fast_and_dumb
- Slot: 406 (table entry 0xa21410)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a0c08 (95 bytes)
- Behavior: Evaluates 1 argument (boolean). Reads the thread-local block at offset 0x30. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_lod_full_detail_actors (slot 407)
- Slot: 407 (table entry 0xa213c0)
- Returns: void
- Parameters: a0: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a0c68 (97 bytes)
- Behavior: Evaluates 1 argument (short). Reads the thread-local block at offset 0x30. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_lod_full_detail_actors (slot 408)
- Slot: 408 (table entry 0xa21160)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### ai_force_full_lod
- Slot: 409 (table entry 0xa21110)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a0ccc (73 bytes)
- Behavior: Evaluates 1 argument (ai). Calls function_70ab58 with a0 (ai); 1. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_force_low_lod
- Slot: 410 (table entry 0xa21280)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a0d18 (73 bytes)
- Behavior: Evaluates 1 argument (ai). Calls function_70ab58 with a0 (ai); 3. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_clear_lod
- Slot: 411 (table entry 0xa21230)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a0d64 (70 bytes)
- Behavior: Evaluates 1 argument (ai). Calls function_70ab58 with a0 (ai); 0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_dialogue_log_reset
- Slot: 412 (table entry 0xa211f0)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### ai_dialogue_log_dump
- Slot: 413 (table entry 0xa211a0)
- Returns: void
- Parameters: a0: string
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### ai_get_object
- Slot: 414 (table entry 0xa20fd0)
- Returns: object
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a0dac (68 bytes)
- Behavior: Evaluates 1 argument (ai). Calls function_6be7d8 with a0 (ai). Returns the result of function_6be7d8.
- Evidence: V

### ai_get_unit
- Slot: 415 (table entry 0xa20f80)
- Returns: unit
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a0dac (68 bytes)
- Behavior: Evaluates 1 argument (ai). Calls function_6be7d8 with a0 (ai). Returns the result of function_6be7d8.
- Evidence: V

### ai_get_squad
- Slot: 416 (table entry 0xa210c0)
- Returns: ai
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a0df0 (164 bytes)
- Behavior: Evaluates 1 argument (ai). Reads the thread-local block at offset 0x8. Calls function_6bd848 with a0 (ai). Reads the 16-bit field at offset 0x3c of an array element of size 0xd00. Returns a value computed in the body.
- Evidence: V

### ai_get_turret_ai
- Slot: 417 (table entry 0xa21070)
- Returns: ai
- Parameters: a0: ai, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a0e94 (72 bytes)
- Behavior: Evaluates 2 arguments (ai, short). Calls function_6be834 with a0 (ai); a1 (short). Returns the result of function_6be834.
- Evidence: V

### ai_random_smart_point
- Slot: 418 (table entry 0xa21020)
- Returns: point_reference
- Parameters: a0: point_reference, a1: real, a2: real, a3: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a0edc (83 bytes)
- Behavior: Evaluates 4 arguments (point_reference, real, real, real). Calls function_6be980 with a0 (point_reference). Returns the result of function_6be980.
- Evidence: V

### ai_nearest_point
- Slot: 419 (table entry 0xa20e40)
- Returns: point_reference
- Parameters: a0: object, a1: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_1a0f30 (71 bytes)
- Behavior: Evaluates 2 arguments (object, point_reference). Calls function_6bee28 with a0 (object); a1 (point_reference). Returns the result of function_6bee28.
- Evidence: V

### ai_get_point_count
- Slot: 420 (table entry 0xa20df0)
- Returns: long
- Parameters: a0: point_reference
- Kind: normal
- Status: implemented
- Evaluator: function_1a0f78 (188 bytes)
- Behavior: Evaluates 1 argument (point_reference). Reads data_c1a230. Returns a value computed in the body.
- Evidence: V

### ai_point_set_get_point
- Slot: 421 (table entry 0xa20da0)
- Returns: point_reference
- Parameters: a0: point_reference, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a1034 (236 bytes)
- Behavior: Evaluates 2 arguments (point_reference, short). Reads data_c1a230. Returns a value computed in the body.
- Evidence: V

### ai_debug_dump_behavior_tree
- Slot: 422 (table entry 0xa20f30)
- Returns: void
- Parameters: a0: boolean
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### ai_place (slot 423)
- Slot: 423 (table entry 0xa20ee0)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a1120 (74 bytes)
- Behavior: Evaluates 1 argument (ai). Calls function_6c2b10 with a0 (ai); -1; 0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_place (slot 424)
- Slot: 424 (table entry 0xa20e90)
- Returns: void
- Parameters: a0: ai, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a116c (75 bytes)
- Behavior: Evaluates 2 arguments (ai, short). Calls function_6c2b10 with a0 (ai); a1 (short); 0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_place_in_limbo (slot 425)
- Slot: 425 (table entry 0xa20c60)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a11b8 (74 bytes)
- Behavior: Evaluates 1 argument (ai). Calls function_6c2b10 with a0 (ai); -1; 1. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_place_in_limbo (slot 426)
- Slot: 426 (table entry 0xa20c10)
- Returns: void
- Parameters: a0: ai, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a1204 (75 bytes)
- Behavior: Evaluates 2 arguments (ai, short). Calls function_6c2b10 with a0 (ai); a1 (short); 1. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_place_in_vehicle
- Slot: 427 (table entry 0xa20d50)
- Returns: void
- Parameters: a0: ai, a1: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a1250 (71 bytes)
- Behavior: Evaluates 2 arguments (ai, ai). Calls function_6be724 with a0 (ai); a1 (ai). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_cannot_die
- Slot: 428 (table entry 0xa20d00)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a1298 (71 bytes)
- Behavior: Evaluates 2 arguments (ai, boolean). Calls function_6be554 with a0 (ai); a1 (boolean). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_vitality_pinned
- Slot: 429 (table entry 0xa20cb0)
- Returns: boolean
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a12e0 (80 bytes)
- Behavior: Evaluates 1 argument (ai). Calls function_6be630 with a0 (ai). Returns a value computed in the body.
- Evidence: V

### ai_place_wave (slot 430)
- Slot: 430 (table entry 0xa20b20)
- Returns: void
- Parameters: a0: long, a1: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a1330 (78 bytes)
- Behavior: Evaluates 2 arguments (long, ai). Calls function_70bec8 with a0 (long); a1 (ai); -1; 0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_place_wave (slot 431)
- Slot: 431 (table entry 0xa20ad0)
- Returns: void
- Parameters: a0: long, a1: ai, a2: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a1380 (79 bytes)
- Behavior: Evaluates 3 arguments (long, ai, short). Calls function_70bec8 with a0 (long); a1 (ai); a2 (short); 0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_place_wave_in_limbo (slot 432)
- Slot: 432 (table entry 0xa20a80)
- Returns: void
- Parameters: a0: long, a1: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a13d0 (78 bytes)
- Behavior: Evaluates 2 arguments (long, ai). Calls function_70bec8 with a0 (long); a1 (ai); -1; 1. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_place_wave_in_limbo (slot 433)
- Slot: 433 (table entry 0xa20bc0)
- Returns: void
- Parameters: a0: long, a1: ai, a2: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a1420 (79 bytes)
- Behavior: Evaluates 3 arguments (long, ai, short). Calls function_70bec8 with a0 (long); a1 (ai); a2 (short); 1. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_set_clump
- Slot: 434 (table entry 0xa20b70)
- Returns: void
- Parameters: a0: ai, a1: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a1470 (150 bytes)
- Behavior: Evaluates 2 arguments (ai, short). Calls function_6be174 with a0 (ai). Calls function_6be220. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_designer_clump_perception_range
- Slot: 435 (table entry 0xa20940)
- Returns: void
- Parameters: a0: real
- Kind: normal
- Status: implemented
- Evaluator: function_1a1508 (101 bytes)
- Behavior: Evaluates 1 argument (real). Reads the thread-local block at offset 0x30. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_designer_clump_targeting_group
- Slot: 436 (table entry 0xa208f0)
- Returns: void
- Parameters: a0: short
- Kind: normal
- Status: implemented
- Evaluator: function_1a1570 (103 bytes)
- Behavior: Evaluates 1 argument (short). Reads the thread-local block at offset 0x30. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_index_from_spawn_formation
- Slot: 437 (table entry 0xa208a0)
- Returns: ai
- Parameters: a0: ai, a1: string_id
- Kind: normal
- Status: implemented
- Evaluator: function_1a15d8 (71 bytes)
- Behavior: Evaluates 2 arguments (ai, string_id). Calls function_6be494 with a0 (ai); a1 (string_id). Returns the result of function_6be494.
- Evidence: V

### ai_resurrect
- Slot: 438 (table entry 0xa20a30)
- Returns: void
- Parameters: a0: object
- Kind: normal
- Status: implemented
- Evaluator: function_1a1620 (196 bytes)
- Behavior: Evaluates 1 argument (object). Reads the thread-local block at offset 0x10 (object datum array), offset 0x30. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_kill
- Slot: 439 (table entry 0xa209e0)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a16e4 (73 bytes)
- Behavior: Evaluates 1 argument (ai). Calls function_6c2d28 with a0 (ai); 0; 1. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_kill_silent
- Slot: 440 (table entry 0xa20990)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a1730 (74 bytes)
- Behavior: Evaluates 1 argument (ai). Calls function_6c2d28 with a0 (ai); 1; 1. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_kill_no_statistics
- Slot: 441 (table entry 0xa20770)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a177c (73 bytes)
- Behavior: Evaluates 1 argument (ai). Calls function_6c2d28 with a0 (ai); 1; 0. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_erase
- Slot: 442 (table entry 0xa20720)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a17c8 (213 bytes)
- Behavior: Evaluates 1 argument (ai). Calls function_6be174 with a0 (ai). Calls function_6aa324 with 0. Calls function_6be220. Calls function_6bdea0 with a0 (ai). Calls function_6bef60. Calls function_6be080. Reads data_b817b4. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_erase_all
- Slot: 443 (table entry 0xa20860)
- Returns: void
- Parameters: none
- Kind: normal
- Status: implemented
- Evaluator: function_1a18a0 (103 bytes)
- Behavior: Takes no arguments. Reads the thread-local block at offset 0x30. Calls function_68f558 with -1; 0. Calls function_69c068 with 48. Calls function_6bef60. Calls function_69c094. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_disposable
- Slot: 444 (table entry 0xa20810)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a1908 (71 bytes)
- Behavior: Evaluates 2 arguments (ai, boolean). Calls function_6bf01c with a0 (ai); a1 (boolean). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_select
- Slot: 445 (table entry 0xa207c0)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (any nested expressions run) and then returns 0. No other action is taken.
- Evidence: V

### ai_deselect
- Slot: 446 (table entry 0xa20640)
- Returns: void
- Parameters: none
- Kind: normal
- Status: not implemented
- Evaluator: function_86cbc (9 bytes)
- Behavior: Not implemented. The evaluator returns 0 as soon as it is called; it does not evaluate its arguments and does not touch any engine state. A script that calls it gets a zero result (false for boolean, 0 for numbers, none for handles); calls with arguments that have side effects do not run those arguments.
- Evidence: V

### ai_set_deaf
- Slot: 447 (table entry 0xa205f0)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a1950 (71 bytes)
- Behavior: Evaluates 2 arguments (ai, boolean). Calls function_6bf0ec with a0 (ai); a1 (boolean). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_set_blind
- Slot: 448 (table entry 0xa205a0)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a1998 (71 bytes)
- Behavior: Evaluates 2 arguments (ai, boolean). Calls function_6bf204 with a0 (ai); a1 (boolean). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_set_weapon_up
- Slot: 449 (table entry 0xa206d0)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a19e0 (156 bytes)
- Behavior: Evaluates 2 arguments (ai, boolean). Calls function_6be174 with a0 (ai). Calls function_6be220. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_flood_disperse
- Slot: 450 (table entry 0xa20680)
- Returns: void
- Parameters: a0: ai, a1: ai
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (any nested expressions run) and then returns 0. No other action is taken.
- Evidence: V

### ai_add_navpoint
- Slot: 451 (table entry 0xa20460)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a1a7c (71 bytes)
- Behavior: Evaluates 2 arguments (ai, boolean). Calls function_6c2e68 with a0 (ai); a1 (boolean). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_magically_see
- Slot: 452 (table entry 0xa20410)
- Returns: void
- Parameters: a0: ai, a1: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a1ac4 (71 bytes)
- Behavior: Evaluates 2 arguments (ai, ai). Calls function_6bf424 with a0 (ai); a1 (ai). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_magically_see_object
- Slot: 453 (table entry 0xa203c0)
- Returns: void
- Parameters: a0: ai, a1: object
- Kind: normal
- Status: implemented
- Evaluator: function_1a1b0c (71 bytes)
- Behavior: Evaluates 2 arguments (ai, object). Calls function_6bf58c with a0 (ai); a1 (object). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_set_active_camo
- Slot: 454 (table entry 0xa20550)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a1b54 (177 bytes)
- Behavior: Evaluates 2 arguments (ai, boolean). Calls function_6be174 with a0 (ai). Calls function_6be220. Calls function_6aaf48. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_suppress_combat
- Slot: 455 (table entry 0xa20500)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a1c08 (151 bytes)
- Behavior: Evaluates 2 arguments (ai, boolean). Calls function_6be174 with a0 (ai). Calls function_6be220. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_engineer_explode
- Slot: 456 (table entry 0xa204b0)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a1ca0 (68 bytes)
- Behavior: Evaluates 1 argument (ai). Calls function_6bf794 with a0 (ai). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_grunt_kamikaze
- Slot: 457 (table entry 0xa202d0)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a1ce4 (68 bytes)
- Behavior: Evaluates 1 argument (ai). Calls function_6bf6dc with a0 (ai). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_squad_enumerate_immigrants
- Slot: 458 (table entry 0xa20280)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: arguments evaluated, no effect
- Evaluator: function_199364 (61 bytes)
- Behavior: Evaluates its arguments (any nested expressions run) and then returns 0. No other action is taken.
- Evidence: V

### ai_migrate
- Slot: 459 (table entry 0xa20230)
- Returns: void
- Parameters: a0: ai, a1: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a1d28 (89 bytes)
- Behavior: Evaluates 2 arguments (ai, ai). Calls function_6bfd80 with a0 (ai); a1 (ai). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_migrate_persistent
- Slot: 460 (table entry 0xa20370)
- Returns: void
- Parameters: a0: ai, a1: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a1d28 (89 bytes)
- Behavior: Evaluates 2 arguments (ai, ai). Calls function_6bfd80 with a0 (ai); a1 (ai). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_allegiance
- Slot: 461 (table entry 0xa20320)
- Returns: void
- Parameters: a0: team, a1: team
- Kind: normal
- Status: implemented
- Evaluator: function_1a1d84 (71 bytes)
- Behavior: Evaluates 2 arguments (team, team). Calls function_6bff6c with a0 (team); a1 (team). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_allegiance_remove
- Slot: 462 (table entry 0xa200f0)
- Returns: void
- Parameters: a0: team, a1: team
- Kind: normal
- Status: implemented
- Evaluator: function_1a1dcc (81 bytes)
- Behavior: Evaluates 2 arguments (team, team). Calls function_1365f0 with a0 (team); a1 (team). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_allegiance_break
- Slot: 463 (table entry 0xa200a0)
- Returns: void
- Parameters: a0: team, a1: team
- Kind: normal
- Status: implemented
- Evaluator: function_1a1e20 (87 bytes)
- Behavior: Evaluates 2 arguments (team, team). Calls function_136708 with a0 (team); a1 (team); 3. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_braindead
- Slot: 464 (table entry 0xa20050)
- Returns: void
- Parameters: a0: ai, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a1e78 (161 bytes)
- Behavior: Evaluates 2 arguments (ai, boolean). Calls function_6be174 with a0 (ai). Calls function_6ab104 with a1 (boolean). Calls function_6be220. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_braindead_by_unit
- Slot: 465 (table entry 0xa201e0)
- Returns: void
- Parameters: a0: object_list, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a1f1c (71 bytes)
- Behavior: Evaluates 2 arguments (object_list, boolean). Calls function_6c1008 with a0 (object_list); a1 (boolean). Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_disregard
- Slot: 466 (table entry 0xa20190)
- Returns: void
- Parameters: a0: object_list, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a1f64 (143 bytes)
- Behavior: Evaluates 2 arguments (object_list, boolean). Calls function_192b34 with a0 (object_list). Calls function_4739cc with the result of function_192b34; 4099. Calls function_192b80. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_disregard_orphans
- Slot: 467 (table entry 0xa20140)
- Returns: void
- Parameters: a0: ai
- Kind: normal
- Status: implemented
- Evaluator: function_1a1ff4 (139 bytes)
- Behavior: Evaluates 1 argument (ai). Calls function_6be174 with a0 (ai). Calls function_73c09c. Calls function_6be220. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_prefer_target
- Slot: 468 (table entry 0xa1ff10)
- Returns: void
- Parameters: a0: object_list, a1: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a2080 (143 bytes)
- Behavior: Evaluates 2 arguments (object_list, boolean). Calls function_192b34 with a0 (object_list). Calls function_4739cc with the result of function_192b34; 4099. Calls function_192b80. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_prefer_target_team
- Slot: 469 (table entry 0xa1fec0)
- Returns: void
- Parameters: a0: ai, a1: team
- Kind: normal
- Status: implemented
- Evaluator: function_1a2110 (151 bytes)
- Behavior: Evaluates 2 arguments (ai, team). Calls function_6be174 with a0 (ai). Calls function_6be220. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V

### ai_prefer_target_ai
- Slot: 470 (table entry 0xa20000)
- Returns: void
- Parameters: a0: ai, a1: ai, a2: boolean
- Kind: normal
- Status: implemented
- Evaluator: function_1a21a8 (156 bytes)
- Behavior: Evaluates 3 arguments (ai, ai, boolean). Calls function_6be174 with a0 (ai). Calls function_6be220. Contains a loop. Returns no value (the evaluator passes 0 to the return helper).
- Evidence: V
