# HaloScript reference

This reference describes the HaloScript language of the module: how scripts are compiled and run, which types and globals exist, and what each native function does.

## Pages

| Page | Contents |
|---|---|
| language.md | text format, lexical rules, syntax nodes, compile rules, special forms, script records, every compile message |
| types.md | the 89 value types, literal parsers, storage classes, when a value fits a slot, the implicit conversion table, the values of every enumeration |
| execution.md | threads, evaluation stack, sleeping and waking, arguments and results, object references, console execution |
| globals.md | the 1,716 external globals with type, storage cell and initial value |
| natives-000-470.md | slots 0 to 470, grouped by category |
| natives-471-940.md | slots 471 to 940 in table order (slots 561 to 575 are not listed) |
| natives-941-1410.md | slots 941 to 1410 in table order |
| natives-1411-1881.md | slots 1411 to 1881 in table order |

## Facts at a glance

- The function table (RVA 0xa28d40) has 1,882 slots; slots 0 to 35 are special forms, 36 to 38 are plain language functions and 39 onward are engine functions.
- The natives pages list 1,867 entries: 1,218 implemented, 594 not implemented, 54 that evaluate their arguments and do nothing else, and 1 special form (cond) without an evaluator. Slots 561 to 575 are not listed.
- Values are 4-byte slots on an evaluation stack. Numbers are carried as 32-bit floats through arithmetic and comparison.
- Script time is divided by 30.0 and converted to game ticks; the one-tick special case applies to sleep and sleep_until only.
- Player literals are player0 to player15. The compile message says player17, but the table holds 16 names.
- 1,524 of the 1,716 external globals have no storage cell and read as zero, false or none.

## Entry format used on the natives pages

Each native has an entry with the fields Slot, Returns, Parameters, Kind, Status, Evaluator, Behavior and Evidence.

- Slot: the function index, followed by the address of its table entry. A name can occupy several slots (the same name with a different parameter count); the slot is the key, and the heading of such an entry carries the slot number.
- Returns and Parameters: the script types stored in the table entry, in call order. Parameter names are not stored in the module; a0, a1, ... are labels of this reference, counting from zero, and Behavior uses the same labels. Special forms show their usage text instead.
- Kind: special form, normal, or command script (cs_) for the natives of the cs_ family that take their actor from the running thread.
- Status: implemented; implemented (constant result); not implemented (shares one stub that returns 0 without evaluating arguments); arguments evaluated, no effect (shares one routine that evaluates the arguments and returns 0); special form without evaluator.
- Evaluator: the code run for the native, by address, with its size.
- Behavior: what the evaluator does, from its code: which arguments it evaluates, which engine functions it calls (by address, with the values passed when they could be traced), which thread-local blocks and global data it touches, and what it returns. A listed call may depend on the arguments or on state; the text says so where that was checked. "Not determined" marks where the code was not followed.
- Evidence: V is read directly from the module bytes; S is read from the module bytes but a callee was not decoded beyond its call signature; H is a hypothesis (not used on the natives pages).

## Order of the natives pages

natives-000-470.md groups its entries by category, so the slot ranges of the groups overlap. The other three natives pages follow the slot order of the table.

## Open items

- Plain-language roles for the engine functions called by each native are not given everywhere; calls are listed by address, and slots 941 to 1410 name roles for most callees.
- The creation and restart rules for startup and continuous scripts, and the rewrite of cond and branch conditions, were not followed. A dormant script starts its thread with wake code -2.
- Thread-local block offsets are listed by number; only the ones used by the script runtime, the players and object arrays and the blocks in the state tables on the natives pages are named.
- The syntax of script and global declarations is not parsed by the module (scripts are read from compiled scenario data), so the form of a script header is not described.
