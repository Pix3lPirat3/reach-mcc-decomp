# Gametype binary format

A custom game variant is a bit-packed stream read most significant bit first (reader `function_dd10c` for N bits, `function_54214` for one bit; the reader keeps a 64-bit window that is byte-swapped on refill). The stream is read into a fixed 0xfc04-byte variant object V; the script definition occupies 0x8308 bytes at V+0x63f4. The serialized size is limited to 0x5000 bytes (`function_56824` rejects larger files; `function_37890` encodes and decodes with that window). Decode is `function_deb40`, validation `function_dd904` followed by the definition validator `function_544a4` (V throughout unless marked).

## Stream order

| # | field | width | stored at | notes |
|---|---|---|---|---|
| 1 | version | u32 | V+0x5dc0 | must be 0x6a or 0x6b |
| 2 | marker | u32 | not stored | read and ignored; the encoder writes the dword at RVA 0x2e00e20; meaning unknown |
| 3 | base variant | see below | V+0x2b8 and following | `function_e1148` |
| 4 | trait count | u5 | V+0x5dc4 | validator: at most 16 |
| 4a | per trait: name string index | u7 | record +0x2c | records are 0x30 bytes from V+0x5dcc |
| 4b | per trait: description string index | u7 | record +0x2d | |
| 4c | per trait: trait block | see below | record +0x00 to +0x2b | `function_108d8c` |
| 5 | option count | u5 | V+0x60cc | validator: at most 16 |
| 5a | per option: name index, description index | u7, u7 | record +0, +1 | records are 0x30 bytes from V+0x60d4 |
| 5b | per option: range flag | bool | record +2 | set: a minimum/maximum range; clear: a list of values |
| 5c | per option: default | i10 (range) or u3 (list) | record +4 | |
| 5d | per option: value count | u4 | record +8 | validator: at most 8; forced to 2 for a range |
| 5e | per option: values | range: two i10 values; list: i10 value, u7 name index, u7 description index per entry | record +0x10 + 4*i (value), +0x12, +0x13 | at most 8 entries fill the record exactly |
| 5f | per option: current value | i10 (range) or u3 | V+0x63d4 + 2*index | validator: within range, or below the value count |
| 6 | string count | u7 | V+0x5dbc | validator: at most 0x70 |
| 6a | per string: present flag, then 12 language offsets | bool + 12 x u15 | V+0x738 + language*0xe0 + 2*i | 12 rows of 112 words, initialised to 0xffff |
| 6b | string pool | u15 raw size, bool compressed, u15 stored size, bytes | V+0x738 + 0xa80 (limit 0x4c00) | validator: raw size at most 0x4bff |
| 7 | variant name string index minus one | u7 | V+0xe6fc | -1 or below the string count |
| 8 | small string table A | u1 count, 12 x (bool, u9 offset), pool | V+0xe848 | count at most 1, pool at most 0xbff |
| 9 | small string table B | u1 count, 12 x (bool, u12 offset), pool | V+0xe9e8 | |
| 10 | small string table C | as table A | V+0xf608 | |
| 11 | two u5 values, each minus one | u5, u5 | V+0xf7ac, V+0xf7a8 | validator: each at most 0x1e |
| 12 | list | u6 count, count x i16, bool | V+0xf7b0 (count), V+0xf7b8 (values), V+0xf7f8 (flag) | count at most 0x20 |
| 13 | 15 floats | 15 x u32 | V+0xf7fc | the validator rejects non-finite values |
| 14 | flags | u1, u16, bool, bool | V+0xf838, V+0xf83c, V+0xf83e, V+0xf83f | |
| 15 | two arrays of 40 dwords, two dwords | 40 x u32, 40 x u32, u32, u32 | V+0xe700, V+0xe7a0, V+0xe840, V+0xe844 | meaning unknown |
| 16 | script definition | see below | V+0x63f4 | `function_55044` |
| 17 | trailer, only if version is above 0x6a | u32, five 8-bit quantized floats (`function_dc770`), u8 selecting two more floats | V+0xf840 to V+0xf85c | |

The wrapper `function_e22f8` first resets the variant and also reads a trailer of u2, u2 (second clamped to 0..1), u6 (clamped to at most 0x3c, else 5) and a string into V+0xf860 and following; `function_e1fe0` validates those bytes.

## Base variant (`function_e1148`)

Widths in stream order with the offsets where each value is stored. The meaning of most fields is not decoded; the fields marked "script" can be read by gametype scripts through number scope codes 18 to 42 ([variables](megalo-variables.md)).

| width | stored at | notes |
|---|---|---|
| common header (virtual call, `function_103638`) | | name and description strings; not decoded |
| 5 x bool | V+0x2b8 bit field | bit 0 and bit 3 are readable by scripts (codes 18 and 21) |
| u8 | V+0x2ba | script code 19 (value times 60) |
| u5 | V+0x2bb | script code 20 |
| u4 | V+0x2b9 | script code 22 |
| u7 | V+0x2bc (word) | script code 23 |
| u5 | V+0x2be (word) | script code 24 |
| trait block | V+0x2c0 | `function_e0550`, see below; script codes 25 to 32 read bytes +0x2c1 to +0x2c8 |
| bool, u2 | V+0x2fa (word) | |
| 5 x bool | V+0x2f8 bit field | script codes 33 to 37 |
| u6, string | V+0x2fc, V+0x300 | script codes 38 and 39 read bits of V+0x2fc |
| u8, u8 | V+0x32c, V+0x32e (words) | |
| 3 strings | V+0x330, V+0x35c, V+0x388 | `function_108d8c` strings |
| 3 x u7 | not stored | |
| u3 | V+0x734 (word) | |
| u3, u2 | V+0x3b8, V+0x3b9 | script codes 40 to 42 read V+0x3b4 to +0x3b6 |
| team array | V+0x400, stride 0x58 | per entry: u4 (byte), u1 (dword), a list of 5-bit entries, a `function_e1e3c` block, u4 minus one, u1, three u32, u5; not decoded |
| u2 | V+0x67c | |
| array of (bool, u7, u8, u8, u8, u4) | V+0x680, stride 6 | in groups of 0x1e bytes; not decoded |

### Trait block (`function_e0550`, 9 bytes)

Four bools, then u6, u7, u8, u8, u8, u4, u4 stored at bytes +1 to +7, and a final u6 at +8 with a string at +0xc (`function_108d8c`). Per-trait blocks (`function_108d8c`) hold the sub-blocks `function_107af0` (u4, u3, u4, u3, u4, u4, u2, u3, u2, u2 and a word), `function_1080dc` (u4, u4, u8, u8, u4, six u2, u8), `function_1084f8` (u5, u4, u4, u2, bool, u9 with an upper bound of 0x191) and `function_108820` (u3, u2, u2, u3, u4). The meaning of the individual trait fields is not decoded.

## Script definition (`function_55044`)

All counts are stored as dwords and the decoder does not clamp them to their arrays; `function_544a4` is the only gate. Definition-relative offsets:

| # | section | count width | element | storage | validator |
|---|---|---|---|---|---|
| 1 | conditions | u10 | 16-byte record (`function_f6ba8`) | +0xf10, 512 entries, count at +0xf08 | at most 512 |
| 2 | actions | u11 | 20-byte record (`function_f52f4`) | +0x2f18, 1024 entries, count at +0x2f10 | at most 1024; opcode below 0x6b |
| 3 | triggers | u9 | 12-byte record | +0x8, 320 entries, count at +0x0 | at most 320 |
| 4 | statistics | u3 | u7 name index, u2 format, u2 sort order minus one, u1 group flag; 4 bytes | +0x7f20, 4 entries, count at +0x7f18 | at most 4; name index below 0x70 or 0xff |
| 5 | global numbers | u4 | NUM_REF + u2 priority | +0x7f38, 12 entries of 3 bytes, priorities at +0x7f8c, count at +0x7f30 | unchecked |
| 6 | global timers | u4 | NUM_REF | +0x7f64, 8 entries, count at +0x7f5c | unchecked |
| 7 | global teams | u4 | u4 team code minus one + u2 priority | +0x7f84, 8 entries, priorities at +0x7fb0, count at +0x7f7c | codes at most 9 |
| 8 | global players | u4 | u2 priority | priorities at +0x7f98, count at +0x7fb8 | at most 8 |
| 9 | global objects | u5 | u2 priority | priorities at +0x7fa0 (16), count at +0x7fbc | at most 16 |
| 10 | player numbers | u4 | NUM_REF + u2 | +0x7fc8, priorities at +0x8000, count at +0x7fc0 | unchecked |
| 11 | player timers | u3 | NUM_REF | +0x7fe8, 4 entries, count at +0x7fe0 | unchecked |
| 12 | player teams | u3 | u4 minus one + u2 | +0x7ffc, priorities at +0x8010, count at +0x7ff4 | codes at most 9 |
| 13 | player players | u3 | u2 | priorities at +0x8008, count at +0x8014 | at most 4 |
| 14 | player objects | u3 | u2 | priorities at +0x800c, count at +0x8018 | at most 4 |
| 15 | object numbers | u4 | NUM_REF + u2 | +0x8024, priorities at +0x805c, count at +0x801c | unchecked |
| 16 | object timers | u3 | NUM_REF | +0x8044, count at +0x803c | unchecked |
| 17 | object teams | u3 | u4 minus one + u2 | +0x8058, priorities at +0x806c, count at +0x8050 | codes at most 9 |
| 18 | object players | u3 | u2 | priorities at +0x8064, count at +0x8070 | at most 4 |
| 19 | object objects | u3 | u2 | priorities at +0x8068, count at +0x8074 | at most 4 |
| 20 | team numbers | u4 | NUM_REF + u2 | +0x8080, priorities at +0x80b8, count at +0x8078 | unchecked |
| 21 | team timers | u3 | NUM_REF | +0x80a0, count at +0x8098 | unchecked |
| 22 | team teams | u3 | u4 minus one + u2 | +0x80b4, priorities at +0x80ca, count at +0x80ac | codes at most 9 |
| 23 | team players | u3 | u2 | priorities at +0x80c0, count at +0x80d0 | at most 4 |
| 24 | team objects | u3 | u2 | priorities at +0x80c4 (6), count at +0x80d4 | at most 6 |
| 25 | HUD widgets | u3 | u4 position code | +0x80e0, 4 entries, count at +0x80d8 | at most 4; code below 0xc |
| 26 | entry trigger slots | 7 x (u9 minus one) | trigger index or -1 | +0x81ec to +0x8204 | each -1 or below the trigger count |
| 27 | object-type bitmap | 64 x u32 | raw bits | +0x8208, 0x100 bytes | none |
| 28 | labels | u5 | see below | +0x80ec, 16 entries of 16 bytes, count at +0x80e4 | at most 16 |

Definition memory map: trigger count +0x0000, triggers +0x0008 (320 x 12), condition count +0x0f08, conditions +0x0f10 (512 x 16), action count +0x2f10, actions +0x2f18 (1024 x 20), statistics count +0x7f18, statistics +0x7f20, variable declaration groups +0x7f30 to +0x80d8, widget count +0x80d8, widget positions +0x80e0, label count +0x80e4, labels +0x80ec, seven entry slots +0x81ec to +0x8204, object-type bitmap +0x8208 (0x100 bytes).

### Label records (16 bytes, decoder at +0x5588c)

| offset | size | field |
|---|---|---|
| +0 | dword | name string index minus one (u7 stream value, -1 none) |
| +4 | dword | object type (OPT_U11, present when flag bit 0 is set, else -1) |
| +8 | word | number (i16, present when flag bit 2 is set) |
| +0xa | byte | team (u4 minus one, present when flag bit 1 is set, default -1) |
| +0xb | byte | flags (u3: bit 0 type, bit 1 team, bit 2 number) |
| +0xc | word | u7 value (not decoded) |

The matching rule applied by conditions and filters is described in [runtime](megalo-runtime.md).

### Record layouts

Trigger records: see [triggers](megalo-triggers.md). Condition records: see [conditions](megalo-conditions.md). Action records: 20 bytes, arguments at +0 to +0xf, opcode at +0x10 (u7, 0 means none), bytes +0x11 to +0x13 unused ([actions](megalo-actions.md)).

## Not covered

Outer container: the framing around this stream (chunk headers, any hash or signature, and how the stream is located in a saved file) is not covered here and is not determined. The value tables that this format refers to by index (navpoint icons, damage types, incident identifiers, requisition and loadout palettes, sound indexes) are not decoded.
