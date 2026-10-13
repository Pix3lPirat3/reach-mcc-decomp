# HaloScript language

HaloScript is the scripting language of the scenario and the console. A script is a tree of parenthesised expressions. The module turns text into a tree of 24-byte syntax nodes, checks the types of every node against the slot it fills, and then runs the tree on script threads (see the execution page). This page describes what the compiler accepts. Types are on the types page, global variables on the globals page and native functions on the natives pages.

Everything here was read from the module code and its strings. Where something was not followed far enough it says "not determined".

## 1. Where scripts come from

- Console and debug text is compiled at run time. The routine for pending console commands is function_1990d8 (it starts and finishes script threads; its steps were not followed in detail). Console text may not use `branch` ("cannot branch from the console.").
- Scenario scripts and script-defined globals are stored in the scenario data as records (see section 8). No routine that reads the text of a `(script ...)` or `(global ...)` definition was found in the module; the scenario carries the compiled form.
- The documentation command (function_82674) writes a file named hs_doc.txt listing "AVAILABLE FUNCTIONS" and "AVAILABLE EXTERNAL GLOBALS". It skips every function whose evaluator is the not-implemented stub (function_86cbc), and every global without a storage cell. Function entries print as `(RETURN_TYPE name PARAM_TYPE ...)`, followed by the usage line when one exists; globals print as `(TYPE name)`.

## 2. Lexical rules

Read from function_1961b8 (whitespace and comments), function_195fc8 and function_195f1c (constants), function_196094 (groups).

- Whitespace is space, tab, line feed (0x0a) and carriage return (0x0d). The parser counts line feeds for error positions.
- A line comment starts with `;` and runs to the end of the line.
- A block comment starts with `;*` and ends at the next `*;`. Block comments do not nest. An unterminated block comment runs to the end of the text.
- A group starts with `(` and ends with `)`. A group may be empty only as an error ("this expression is empty."). A missing `)` is reported as "this left parenthesis is unmatched.".
- An atom is anything that is not a group. Three forms exist:
  - A quoted constant starts with `"` and ends at the next `"`. There are no escape sequences, and line feeds are allowed inside. Unterminated: "this quoted constant is unterminated.".
  - A superstring constant starts with `{` and ends at the next `}`. Unterminated: "this superstring constant is unterminated. (did you forget a '}' ?)".
  - Any other atom is a run of characters that ends at whitespace, `)` or `;`.
- Identifiers, numbers, booleans, names and the player references are all atoms; their meaning depends on the type the slot expects (section 5).

## 3. Syntax nodes

Nodes live in a datum array (data_c1a838). Each node is 0x18 bytes:

| Offset | Size | Meaning |
|---|---|---|
| 0x00 | 2 | datum header (salt) |
| 0x02 | 2 | function index, script index or variable reference (see flags) |
| 0x04 | 2 | type id (0 until the compiler assigns one) |
| 0x06 | 2 | flags: bit 0 atom (not a group), bit 1 the call names a script (not a function), bit 2 variable reference resolved, bit 4 the variable is a script-defined global |
| 0x08 | 4 | next sibling node (-1 at the end of a list) |
| 0x0c | 4 | source offset of the node |
| 0x10 | 4 | first child (groups) or the constant value or variable reference (atoms) |
| 0x14 | 2 | source line |

A group's first child is the function or script name; the remaining children are the arguments. Allocation failure reports "i couldn't allocate a syntax node.".

## 4. Compiling a node

The compiler works top down. Compiling a node means giving it an expected type and checking it fits (function_1962e4):

1. If the node has no type yet it takes the expected type.
2. Atoms go to the atom compiler (function_196338). Groups go to the call compiler (function_196938).
3. The atom compiler rejects the special_form type ("i expected a script or variable definition.") and the void type ("the value of this expression (in a VOID slot) can never be used."). Otherwise it first tries the atom as a variable name, and if that fails it calls the literal parser for the expected type from the parser table (see the types page). A type with no parser reports "expressions of type %s are currently unsupported.".
4. Variable references (function_196444) search the script-defined globals first (function_81cd0, by name) and then the external globals (function_81d8c, a linear search of the 1,716 names). The type of the variable must fit the expected type: "i expected a value of type %s, but the variable %s has type %s". Unknown names report "this is not a valid variable name." (or "this is not a valid global variable." inside `set`).
5. The call compiler (function_196938) resolves the first child as a function or script (function_19669c): functions by name and argument count (function_81e78), scripts by name and parameter count (function_81be8). Failure reports "this is not a valid function or script name.".
6. For a function call, the function's own parser runs. Most functions use function_198f2c, which requires exactly the declared number of arguments ("the "%s" call requires exactly %d arguments.") and compiles each argument against its parameter type. The special forms have their own compile functions (section 6).
7. For a script call only static scripts (script type 3) and stubs (script type 5) can be called by other scripts ("this is not a static script."). The script's return type must fit the expected type ("i expected a %s, but this script returns a %s."). Parameter count mismatches report "wrong number of script arguments" or "wrong number of arguments for script".

Function lookup (function_81e78) compares the name with every table entry in order and also compares the parameter count. Special forms match any count. Inside a command script the lookup prefers the cs_ entry of a name; outside one, a cs_ function needs an extra leading actor index and an optional boolean for blocking atoms ("if a cs_ command atom is called outside a command script, it needs an actor index and optionally a boolean (for blocking atoms)"). Some calls are refused by context: "it is illegal to call this function from a script file", "it is illegal to set the value of variables in this context.", "it is illegal to block in this context.".

## 5. Literals by type

- boolean: the atom `true` or `false` ("i expected "true" or "false".").
- real: a decimal number ("this is not a valid real number.").
- short: an integer in the range -32767 to 32768 ("shorts must be in the range [-32767, 32768]."); long: an integer ("this is not a valid integer.").
- string and string_id: any atom, taken as text ("this is not a valid string parameter.").
- script: the name of a script ("this is not a valid script name.").
- player: exactly `player0` to `player15` (16 names). The error text says "player0 through player17", but the compiler's table holds only 16 names. A player reference can also fill an object, unit or object list slot, where it converts to that player's unit.
- Object names: a name that exists in the scenario ("no object exists with this name.", "this is not a valid object name.", "this is not an object of type %s."). Typed names (unit_name and so on) also check the object type.
- Tag references (ids 35 to 51): a tag name that is loaded ("not a loaded tag", "no scenario loaded"). tag path and enum atoms are parsed by their own functions ("%s must be ", "corrupt enum expression").
- Scenario block names (trigger volume, flags, camera points, titles, recordings), device group, zone set, designer zone, point reference, style, editor folder, lightprobe and AI names: a name looked up in the scenario ("this is not a valid zone set name.", "this is not a valid point reference", "invalid style", "folder not found", "this is not a lightprobe name.", "this is not a valid ai squad or squad group.").
- unit_seat_mapping: a substring of a seat name ("no units match this seat substring (try reloading Sapien)", "too many units match this seat substring").
- ai_orders: deprecated ("orders are DEPRECATED"); ai_command_list never parses; ai_behavior is refused in builds above test ("_hs_type_ai_behavior not supported in builds greater than test").
- Casts: an atom may be used where an object type is expected only when the atom's own type allows ("this is not a valid cast.").

## 6. Special forms

Special forms are table entries with kind 2 (36 entries, slots 0 to 35). They have their own compile step and an evaluator that walks the nodes itself. Full behavior is in the natives page; the compile rules are:

| Form | Usage | Compile rule |
|---|---|---|
| begin, begin_random | expression(s) | at least 1 argument; every argument but the last is a void slot; begin_random allows at most 32 |
| begin_count, begin_random_count | count, expression(s) | first argument is a long count; same rules as above |
| if | condition then [else] | condition is boolean; the then and else branches share the form's type |
| cond | (condition result) ... | every argument must be a condition and result pair |
| set | variable value | the value must fit the variable's type |
| and, or | boolean(s) | at least 2 arguments, all boolean |
| +, -, *, min, max | number(s) | at least 2 arguments, all compiled as real |
| /, % | number number | exactly 2 arguments |
| =, != | expression expression | two arguments of the same type ("invalid arguments to inequality operator." for a mismatch) |
| >, <, >=, <= | number number | two arguments |
| sleep, cinematic_sleep | short [script] | a time and, optionally, a script name |
| sleep_forever | [script] | optional script name |
| sleep_until, sleep_until_game_ticks | boolean [short] | a condition and optionally a period |
| wake | script name | not allowed for static or command scripts |
| inspect | expression | one expression |
| branch | condition script | needs a condition and a script; not allowed from the console |
| unit, vehicle, weapon, device, scenery, effect_scenery | object | one object expression; returns the object when it belongs to the class |

Argument counts report "the %s call requires %d arguments." (exact) or "the %s call requires at least 2 arguments." (minimum), and extra arguments report "i didn't expect this argument.".

## 7. Script types

The six script types (names at data_995f08 and neighbours) are startup, dormant, continuous, static, command_script and stub, with ids 0 to 5. Only static and stub scripts can be called from other scripts. `wake` is refused for static and command scripts. The way each type is started and restarted is covered on the execution page; the compile rules for definitions are not determined because the definition text is not parsed by the module.

## 8. Script and global records in scenario data

The compiler and runtime read scripts from an array in the scenario data (count at +0x430, array at +0x434 of the scenario block pointed to by data_c1a230). Each script record is 0x18 bytes:

| Offset | Size | Meaning |
|---|---|---|
| 0x00 | 4 | name as a string id |
| 0x04 | 2 | script type (0 to 5) |
| 0x06 | 2 | return type id |
| 0x08 | 4 | not determined (read when the script runs) |
| 0x0c | 4 | parameter count |
| 0x10 | 4 | handle of the parameter list; each parameter entry is 0x24 bytes and starts with the parameter name |

Script-defined globals use variable references without bit 15, indexing the runtime globals array after its first 0x6b4 entries. The hs globals array has 0x1000 entries of 8 bytes.

## 9. Compile messages

All messages the compiler can report, with the condition read from the code where known:

| Message | Reported when |
|---|---|
| a %s statement block must contain at least one argument. | begin family with no arguments |
| begin_count and begin_random_count need to specify how many expressions to evaluate | missing count |
| begin_random (or random_count) can take a maximum of 32 arguments | more than 32 sub-expressions |
| this argument to cond needs a result. | pair without a result |
| this argument to cond should be a condition/result pair | cond argument is not a pair |
| i couldn't allocate a syntax node. | node datum array full |
| i expected (if CONDITION THEN [ELSE]). | wrong number of arguments to if |
| i didn't expect this argument. | extra arguments |
| this is not a valid global variable. | set target is not a global |
| you cannot pass the result of this set (type %s) to a function that expects type %s. | set result used in the wrong type slot |
| the %s call requires at least 2 arguments. / the %s call requires %s2 arguments. / the %s call requires %d arguments. | argument count rules above |
| i expected a variable to set and a value. / i expected an assignment value. | set form shape |
| the sleep call requires a time and, optionally, a script name. | sleep shape |
| the sleep_until call requires a condition and, optionally, a period. | sleep_until shape |
| invalid arguments to inequality operator. | comparison operand types |
| cannot branch from the console. | branch in console text |
| this is not a global variable reference, function call, or script call. | atom or group that cannot be resolved |
| static or command-script scripts cannot be awakened. | wake on those types |
| branch requires a condition and a script to execute if that condition is met. / branch requires a script after the branch condition. | branch shape |
| this quoted constant is unterminated. / this superstring constant is unterminated. (did you forget a '}' ?) | unterminated constants |
| i expected a script or variable definition. | special_form slot reached as an atom |
| this expression is empty. / this left parenthesis is unmatched. | group errors |
| i expected a value of type %s, but the variable %s has type %s | variable type mismatch |
| expressions of type %s are currently unsupported. | type without a literal parser |
| the value of this expression (in a VOID slot) can never be used. | atom in a void slot |
| this is not a static script. | calling a script that is not static or stub |
| i expected a %s, but this script returns a %s. / i expected a %s, but this function returns a %s. | return type mismatch |
| wrong number of script arguments / wrong number of arguments for script / wrong number of arguments for function | parameter count mismatch |
| this is not a valid variable name. | unknown variable |
| it is illegal to call this function from a script file | context restriction |
| if a cs_ command atom is called outside a command script, it needs an actor index and optionally a boolean (for blocking atoms) | cs_ calls outside command scripts |
| it is illegal to set the value of variables in this context. / it is illegal to block in this context. | context restrictions |
| this is not a valid function or script name. | name not found |
| i expected "true" or "false". | boolean literal |
| i expected %s, but i got an expression. with "a function name" or ""script" or "global"" | an atom was expected where a group was written |
| this is not a valid script name. | script literal |
| shorts must be in the range [-32767, 32768]. / this is not a valid integer. / this is not a valid real number. | number literals |
| no scenario loaded | name lookup before a scenario exists |
| no units match this seat substring (try reloading Sapien) / too many units match this seat substring | seat substring |
| this is not a valid string parameter. / this is not a valid string for '%s' | string literal |
| %s must be / not a loaded tag / this is not a valid %s name | tag reference literal |
| corrupt enum expression (type %d constant-type %d) | enum literal |
| _hs_type_ai_behavior not supported in builds greater than test / orders are DEPRECATED | deprecated types |
| this is not a valid command list script / script is not a command-script | command script names |
| this is not a valid ai squad or squad group. | AI names |
| this is not a valid zone set name. / this is not a valid cast. | zone set and cast |
| this is not a valid player (player0 through player17). | player literal |
| this object no longer exists in the scenario. / this is not an object of type %s. | object names |
| invalid byteswap type, | not determined |
| this is not a lightprobe name. / this is not a valid point reference / this is not a valid %s | scenario names |
| this is not a valid object name. / no object exists with this name. | object names |
| cannot parse editor folder, no scenario loaded / folder not found / invalid style | folders and styles |
