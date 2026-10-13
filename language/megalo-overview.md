# Gametype scripting overview

A custom game variant carries a small program for the gametype VM ("Megalo") together with its settings. The program is not bytecode: it is a table of conditions and actions grouped into triggers. Each action is a record with an opcode and typed arguments; the engine executes it by jumping to a block of code per opcode (the action dispatcher `function_f2dac`). Conditions are evaluated by a second dispatcher (`function_f6524`). There are 17 condition types and 106 action opcodes.

## Building blocks

- **Values.** Numbers (32-bit signed), timers, teams, players and objects ([variables](megalo-variables.md)). Every value lives in a scope: global, player, object or team, so a variable is addressed by scope, kind and index. Temporaries exist per trigger run.
- **References.** Arguments are not values but typed references: a literal, a variable, a property of another entity, or a computed reference (the unit of a player, the team of an object, and so on). There are twelve reference encodings.
- **Triggers.** A trigger names a range of conditions and a range of actions and a loop kind (once, for each player, team or object, optionally in random order or restricted to objects with a label) ([triggers](megalo-triggers.md)). Seven entry slots name triggers run on engine events.
- **Conditions and actions.** Conditions gate every action they cover; AND and OR grouping is expressed by group numbers ([conditions](megalo-conditions.md), [actions](megalo-actions.md)).
- **Declarations.** Each scope declares how many variables of each kind it owns, their initial values and a network priority.
- **UI.** Four HUD widgets, per-object and per-player navpoints and boundaries, objective texts and messages.
- **Settings.** Options (up to 16 with up to 8 values each), traits (16), strings in twelve languages (112), statistics (4) and labels (16) are part of the file ([variant format](megalo-variant-format.md)).

## How a trigger runs

1. The engine event (round start, host migration, object death, new map or the per-tick executor) starts a trigger with a fresh temporary frame.
2. The trigger's loop kind sets the current player, team or object for each pass.
3. For every action of the trigger the conditions that apply to it are evaluated in order; the action runs when the combined result is true.
4. An action can run another trigger (operation 20) or an inline range (operation 99), which nests without limit.

## Reading the pages

- [variant-format](megalo-variant-format.md): the stream layout of the file.
- [variables](megalo-variables.md): value kinds, scopes, references and number scope codes.
- [triggers](megalo-triggers.md): trigger records, loops, selectors and entry slots.
- [conditions](megalo-conditions.md): the 17 condition types and the evaluation rules.
- [actions](megalo-actions.md): the 106 action opcodes, one section each.
- [properties](megalo-properties.md): what each entity exposes to scripts.
- [enums](megalo-enums.md): operators, comparison codes, visibility modes, timer rates and other codes.
- [runtime](megalo-runtime.md): the state blocks the script reads and writes.
- [limits](megalo-limits.md): every capacity limit.
- [halo-script](megalo-haloscript.md): the scenario script language and how the two interact.
- [evidence-table](megalo-evidence-table.md): the evidence level of each claim.

## Evidence levels

V: read directly in the module's code. S: derived from a static match with another build of the same code (names, mainly). H: hypothesis from structure or position. U: not decoded. Function names are given as `function_RVA` with the relative virtual address of the module; offsets are bytes.

The module analysed is `haloreach.dll` with SHA-256 `738dd2d24ea3aea12e1ee9aa4a61094bf116027d42004c35a19e5048608b0894`.
