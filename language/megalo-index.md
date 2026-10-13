# Gametype script reference (Megalo)

Reference for the gametype scripting language of the 64-bit Halo: Reach module (`haloreach.dll`, SHA-256 `738dd2d24ea3aea12e1ee9aa4a61094bf116027d42004c35a19e5048608b0894`), reconstructed from the module's code.

| page | content |
|---|---|
| [overview](megalo-overview.md) | what a gametype script is and how it runs |
| [variant-format](megalo-variant-format.md) | binary layout of a custom game variant and of the script definition |
| [variables](megalo-variables.md) | value kinds, scopes, reference encodings, code tables, number scope codes |
| [triggers](megalo-triggers.md) | trigger records, loop kinds, selectors, entry slots, event context |
| [conditions](megalo-conditions.md) | the 17 condition types and the evaluation rules |
| [actions](megalo-actions.md) | the 106 action opcodes, one section each (data in [actions.json](actions.json)) |
| [properties](megalo-properties.md) | what each entity exposes to scripts |
| [enums](megalo-enums.md) | operator, comparison, visibility, timer rate and other codes |
| [runtime](megalo-runtime.md) | script state, player, team, object and widget records |
| [limits](megalo-limits.md) | capacity limits of the file and of the runtime |
| [halo-script](megalo-haloscript.md) | scenario scripts and their link to gametypes |
| [evidence-table](megalo-evidence-table.md) | evidence level per claim |

Evidence levels: V read in the module's code, S static match with another build (names), H hypothesis, U not decoded.
