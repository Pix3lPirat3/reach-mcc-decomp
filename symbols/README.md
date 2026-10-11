# MCC Reach symbols

Names and notes for haloreach.dll, Master Chief Collection build 1.3528 (sha256 738dd2d24ea3aea12e1ee9aa4a61094bf116027d42004c35a19e5048608b0894).

Files:

- symbols.csv: one line per named function. Columns are address (RVA), size in bytes, name, and confidence.
- pools.csv: fixed-size lists the game keeps (count and size of each entry).
- forge-editing.md, combat.md, ai.md: short notes on how those parts work.

Confidence:

- supported: a text string, a constant or a direct call shows the name.
- inferred: the name follows from who calls the function and what it touches.

Not every name is sure. Functions with no line in symbols.csv are not named yet.
