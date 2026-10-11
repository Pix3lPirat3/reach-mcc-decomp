# Forge editing

What happens when a player edits in Forge, in order.

1. Each game tick the editor reads the player's buttons (0x72da8) and makes a command (0x77b54).
2. The command is written to a message (0x77d00) and sent. The same game receives it back (0x3a4a54, read by 0x77f58) and passes it to 0x761fc.
3. Placing an item: 0x76608 checks the player may place (0x751f4), finds a free slot in the quota (0x6e7bc), and takes a free record (0x6e0c8). Then 0x6ed04 builds the object, which calls the general object creation (0x46d6e0).
4. Holding an item: each tick the game finds what the player aims at (0x72b3c), moves the held item (0x71c24) and turns it (0x717ec). Letting go saves the new position into the item's record.
5. Copying and changing properties go through 0x771bc. Deleting releases the item (0x71194).
6. Saving the map writes the header and all item records (0x692c4, 0x103174, 0x706e8).

Item record: 76 bytes each, 651 in the stock game. Byte 0 flags (bit 0 = in use), position at +8, physics in the top two bits of byte +0x46 (0 normal, 1 fixed, 3 phased).

Each player has an editor record of 0x12c bytes: held item +0x04, aimed item +0x08, hold distance +0x0c, aim point +0x10.
