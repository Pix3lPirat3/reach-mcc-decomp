# Symbols

Function names for haloreach.dll build 738dd2d24ea3aea12e1ee9aa4a61094bf116027d42004c35a19e5048608b0894 (MCC 1.3528). Columns: RVA, size in bytes from the unwind table, name, confidence.

Confidence:

- `supported`: the name rests on a string, a constant or a direct call in this build.
- `corroborated`: two independent readings of this build reached the same name, with nothing measured at run time.
- `inferred`: the name follows from callers and structure.

Names carried over from another build of the game by matching code are not in this file. They are listed in transfer.csv with the tier `transferred`, because they do not follow from this build.

18785 named functions, 4916 supported, 3 corroborated, covering 4620596 bytes.

## Coverage

The unwind table of this build reports 29032 spans. An unwind span is not a proven function extent, so that number is a floor for how many functions the build has, not a denominator for a coverage figure, and no percentage is given here for that reason. Against that floor, 18785 addresses carry a name in symbols.csv and 20281 carry a note of some kind in the reading notes, so the gap between the two columns below is code that is read but not yet named. Addresses with neither are not listed anywhere in this folder.

| System | Addresses with a label | Of those, named here |
| --- | ---: | ---: |
| platform libs | 3771 | 3722 |
| havok | 2877 | 2864 |
| ui hud | 1606 | 1589 |
| audio | 1530 | 1520 |
| unclassified | 1448 | 804 |
| haloscript | 1435 | 1433 |
| ai | 1425 | 1104 |
| netcode replication | 1390 | 1316 |
| objects datums | 1017 | 955 |
| engine core | 681 | 585 |
| generic helper | 590 | 187 |
| weapons damage | 548 | 517 |
| memory regions | 366 | 358 |
| render | 354 | 331 |
| forge map variant | 295 | 265 |
| saves films | 274 | 219 |
| tags map loading | 139 | 134 |
| megalo vm | 131 | 125 |
| spawning | 111 | 94 |
| animation | 87 | 87 |
| stats | 83 | 75 |
| input | 58 | 50 |
| threading sync | 26 | 25 |
| devices | 22 | 22 |
| async io | 17 | 17 |
| named here with no label entry | 387 | 387 |
