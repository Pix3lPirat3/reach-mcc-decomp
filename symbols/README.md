# MCC Reach symbols

Names and notes for haloreach.dll, Master Chief Collection build 1.3528 (sha256 738dd2d24ea3aea12e1ee9aa4a61094bf116027d42004c35a19e5048608b0894).

Files:

- symbols.csv: one line per named function. Columns are address (RVA), size in bytes, name, and confidence.
- transfer.csv: names carried over from another build of the game by matching code. Columns are address, size, name, match (high or medium) and basis (string, layout, or layout_and_constants). Not checked by hand yet.
- pools.csv: fixed-size lists the game keeps (count and size of each entry).
- systems.csv: every exactly matched function with its system, name and a short comment. systems.md: matched functions and bytes per system.
- forge-editing.md, combat.md, ai.md: short notes on how those parts work.

Confidence:

- supported: a text string, a constant or a direct call shows the name.
- inferred: the name follows from who calls the function and what it touches.

Names in transfer.csv are about 93% right in testing (high is better than medium). Check one before relying on it.

Not every name is sure. Functions with no line in symbols.csv are not named yet.
