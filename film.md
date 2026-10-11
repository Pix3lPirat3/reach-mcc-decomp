# Saved films (Theater)

A saved film is a recording of every game update (tick). Playing it feeds the recorded updates back into the game.

Opening: saved_film_playback_start (0x5ab98) builds the file name (name.film) and opens it (0x87684). The file header body is 0x1f8a8 bytes. The film length and history span come from the game options (+0x1dc end tick, +0x1e0 history span).

Each tick: the simulation update (0x3aa950) fills the film queue (0x3ab970). Each record has a header whose low 30 bits are the length and top 2 bits the type. Type 0 is one game update of 0xd740 bytes (16 player action records of 0xa8 bytes). The update is applied through the normal game tick (0x575ac).

Time and speed: the film speed value is copied into the game clock (0x5c484). It is set by 0x5bf64 and limited to 0 to 3.0. In Theater the E key changes speed, and pause is a separate bit in the game clock (0x5c980).

Checkpoints: every 600 ticks the game saves a full state image of 0xa60000 bytes into a ring of 11 slots (0x1714d0). Restoring one reloads that image.

Ending: 0x5c020 asks the views to stop. Leaving the film unloads the map (0xa3c74), disposes the game (0x56e64), stops the recorder (0x5b028, 0x88d38) and then shuts down the network session (0x3ae290). This teardown is the largest part of the film code.
