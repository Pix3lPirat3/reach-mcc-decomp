# MCC Reach symbols

Names and notes for haloreach.dll, Master Chief Collection build 1.3528 (sha256 738dd2d24ea3aea12e1ee9aa4a61094bf116027d42004c35a19e5048608b0894).

Files:

- symbols.csv: one line per named function. Columns are address (RVA), size in bytes, name, and confidence.
- SYMBOLS.md: what the confidence words mean, and how much of the build the names cover, per part of the engine.
- transfer.csv: names carried over from another build of the game by matching code, kept out of symbols.csv because they do not follow from this build. Columns are address, size, name, confidence (transferred, transfer_high or transfer_medium) and basis (string, layout, layout_and_constants or code_match).
- pools.csv: fixed-size lists the game keeps (count and size of each entry).
- systems.csv: every exactly matched function with its system, name and a short comment. systems.md: matched functions and bytes per system.
- SYSTEM-MAP.md: the entry point to the per-system map, with one page per engine system (networking.md, physics.md, ai.md and so on) giving the tree, coverage and key named functions.
- combat.md, film.md, forge-editing.md: short notes on parts of the engine.

Confidence in symbols.csv:

- supported: a text string, a constant or a direct call shows the name.
- corroborated: two separate readings of this build ended up with the same name, and nothing was measured while the game ran.
- inferred: the name follows from who calls the function and what it touches.

Transferred names were checked against the names read from this build at the 151 addresses where both exist: 123 agreed, about 81 in 100. Nearly all of the rest are one mix up between two similar tables that carry the same text, so a transferred name on a reflection or type table is the weakest case. Check one before relying on it.

Not every name is sure. Functions with no line in symbols.csv are not named yet.
