# HaloScript execution

This page describes how compiled scripts run: threads, stacks, argument passing, sleeping, waking and object references. It was read from the thread code at function_85638 to function_86a9c and the evaluators on the natives page. "Not determined" marks parts that were not followed far enough.

## 1. Threads

Scripts run on threads stored in two datum arrays, both created when the script runtime starts (function_84948):

| Array | Elements | Element size | Thread-local offset | Used for |
|---|---|---|---|---|
| deterministic hs threads ("det hs thread") | 320 | 0x52c | 0x490 | scenario scripts and anything that must run the same on every machine |
| non-deterministic hs threads ("non-det hs thread") | 4 | 0x52c | 0x450 | console and debug commands |

A thread handle is a datum index. Handles of non-deterministic threads have bit 15 set, which is how the runtime tells the two arrays apart (function_85638 sets it). Each element is 0x2c bytes of header plus a 0x500-byte evaluation stack (0x52c in total), so a thread holds at most 0x500 bytes of nested evaluation state.

Thread header fields read by the code:

| Offset | Size | Meaning |
|---|---|---|
| 0x02 | 2 | script index (-1 for console threads) |
| 0x04 | 2 | not determined |
| 0x08 | 4 | parent thread handle (set by `branch`; -1 otherwise) |
| 0x0c | 4 | wake tick or wait code (section 3) |
| 0x10 | 4 | saved wake tick while another thread controls the sleep |
| 0x14 | 2 | offset of the current stack frame within the stack |
| 0x20 | 1 | script type (0 to 5) |
| 0x21 | 1 | flags: bit 0 entry flag passed to evaluators as their first-call flag, bit 1 sleeping on behalf of another thread, bit 6 (0x40) thread is being killed |
| 0x24 | 4 | AI reference of the actor a thread of script type 3 runs for (0 at creation); the cs_ natives read it |
| 0x28 | 4 | owner actor handle (command scripts, -1 at creation) |
| 0x2c | 0x500 | evaluation stack |

New threads start with an empty stack, no parent, wake code 0 (runs on the next pass) and the script's index and type (function_85638). A thread for a dormant script (script type 1) starts with wake code -2 instead and waits until another thread wakes it. Runtime globals (thread-local offset 0x230) hold the handle of the thread that is currently running at +8.

## 2. The evaluation stack

Evaluation is a stack machine over the syntax nodes (function_858a8 evaluates the node at the top; function_85c04 pushes a new node to evaluate).

- A frame holds the node being evaluated, the evaluators' own state for that node, a link to the previous frame, and 4-byte slots for the values of its arguments.
- Pushing a sub-expression suspends the current evaluator. When the sub-expression finishes it stores its value into the next slot of the frame below and the frame below is resumed.
- An evaluator that cannot finish in one pass returns without a value and is called again later. Its first-call flag (the third parameter, passed as r8) is set only on the first call, which is how it knows to set up its state.
- A thread can be suspended between ticks at any frame. All state needed to resume lives in the stack, so evaluation continues exactly where it stopped.
- Object handles held in frames and in globals are reference-tracked (section 6).

## 3. Sleeping and waking

Each thread has a wake code at +0x0c:

| Value | Meaning |
|---|---|
| 0 or more | run when the current game tick (read from the game time block at thread-local offset 0xa0, +0xc) is greater than or equal to this value |
| -1 | not scheduled by tick; the runner skips negative values and `sleep` leaves such a thread unchanged. What sets this value was not determined |
| -2 | sleeping forever, set by sleep_forever |
| -3 | waiting on a condition: each pass function_6b0560 is called with the thread handle; while it returns true the wait continues, and when it returns false the wake code is reset to 0 and the thread runs |
| -4 | waiting on an actor: same pattern with function_6ea8cc and the thread's actor handle (+0x28) |

The per-tick runner (function_84f94) walks the threads and runs each one whose wake tick is not negative and not later than the current game tick, using function_858a8. A thread with its kill flag set is given wake tick 1 so that it runs once and ends. After the pass it calls function_192c28 to release object-list references (section 6).

Time units in `sleep` and the sleep_until family are described on the natives page: values are divided by 30.0 and converted to game ticks by function_5cc74, except that a value of 1 means one game tick for `sleep` and `sleep_until`, and `sleep_until_game_ticks` takes game ticks directly. A `sleep` of 0, or of a wait that converts to 0 ticks, returns without sleeping; `sleep_until` waits at least 1 tick between checks.

`wake` sets another thread's wake code so that it runs on the next pass (function_864dc). `sleep_forever` writes -2 into the target thread. `branch` starts a new thread for a script (function_85638) with the current thread as its parent.

## 4. Script types in the runner

The per-tick runner reads the type byte at +0x20 before it runs a thread:

- type 2 (continuous): sets a flag that makes the runner skip its end-of-pass cleanup call (function_81b3c) for that pass.
- types 3 (static) and 4 (command script): the runner writes context values to a small block at data_fc9c40 to data_fc9c48 before evaluating the thread (an owner value read from +0x24 for type 3 and the actor handle at +0x28 for type 4) and clears them afterwards. The cs_ natives read the same reference at +0x24 of a type 3 thread to find the actor they act on (see the natives pages). What the other evaluators do with the context values was not determined.
- How startup, dormant and continuous threads are created when a map starts, and how a continuous script restarts, were not followed (not determined).

## 5. Arguments and results

Function evaluators get their arguments through function_865e8 and return through function_85de0:

- function_865e8 evaluates a function's arguments one at a time. It checks that each argument node has the parameter's type, pushes it for evaluation, and when all values are in it returns a pointer to the array of 4-byte slots (argument n at byte offset 4 x n, only the low bytes used for 1 and 2 byte types). While arguments are still being evaluated it returns null, and the evaluator returns at once to run again later.
- function_85de0 delivers the evaluator's result. It reads the function's declared return type (or the script's return type for a script call), converts the value to the type the caller slot expects through function_86ba8 (the conversion table on the types page) and stores it in the parent frame's next slot. It then pops the frame.
- Evaluators declared void still hand a value to function_85de0 (usually 0); the slot is a void slot and the value is discarded by the conversion table.
- A native with the not-implemented stub (function_86cbc) returns 0 immediately: it does not evaluate its arguments at all, so side effects written in those arguments never run. A native whose evaluator is function_199364 evaluates its arguments and then returns 0.

## 6. Object references from scripts

- Object handles stored by `set` into object variables, and object lists, are marked by setting bit 27 of the object's flags word (+4 of its datum) (function_8707c).
- The routine at function_85358 takes the handle of a deleted object (and only acts when the object carries that flag). It walks the hs globals array and every thread's frame slots and replaces any handle of that object with -1 (none), and removes it from object lists (function_192a58, function_192bf0). Scripts therefore see a deleted object as none.
- Object lists are datum-backed (function_192960 creates a list, function_1929cc adds a handle), so a list is not bounded by 16 entries.

## 7. Variables

- External globals are read through function_85ee0 and written through function_8707c; see the globals page for how storage cells work.
- Script-defined globals are slots of the hs globals array (0x1000 entries of 8 bytes) after the first 0x6b4 entries; each slot holds the type in its first 4 bytes and the value in the next 4.
- Parameters and locals of a script call live in the frame slots of the call; function_863e4 reads a frame slot by index.

## 8. Console execution

Console commands run on non-deterministic threads. The routine for pending commands (function_1990d8) starts a thread for a compiled command and ends it when it finishes. Commands that block are not allowed from the console ("it is illegal to block in this context.").
