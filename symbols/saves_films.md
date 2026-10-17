# Saves and films (Theater)

Part of the MCC Reach system map. Build haloreach.dll, MCC 1.3528 (sha256 738dd2d24ea3aea12e1ee9aa4a61094bf116027d42004c35a19e5048608b0894). See the [system map](SYSTEM-MAP.md).

Saves and films covers save-game persistence and the saved-film (Theater) system. A saved film is a recording of every game update (tick); playing it feeds the recorded updates back through the normal game tick. This is the better-mapped half of the system.

Coverage: 127 of 146 functions carrying this system tag have a name (40 supported, 0 corroborated, 87 inferred). The remaining 19 are tagged to the system but not yet named.

## Subsystems and named functions

### films

Saved-film capture, Theater playback and film data. The duplicate `film`/`saved_film`/`saves_films`/`theater` tags were merged here.

Showing 16 of 19 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x58eec` | `game_options_flag_1da_check` | supported |
| `0x5ab98` | `saved_film_playback_start` | supported |
| `0x5bf64` | `time_speed_request_set_clamped_0_to_3` | supported |
| `0x32c42c` | `mcc_menu_enter_theater` | supported |
| `0x35a3a4` | `mcc_theater_screen_init` | supported |
| `0x35a428` | `mcc_theatre_screen_phase_step` | supported |
| `0x35b0e0` | `mcc_theater_screen_tick` | supported |
| `0x35b1d8` | `mcc_theater_event_handler` | supported |
| `0x35b3ec` | `mcc_theater_play` | supported |
| `0x35b6f4` | `mcc_theatre_cancel_countdown` | supported |
| `0x35b8e8` | `mcc_theatre_select_item_update_file_info` | supported |
| `0x35c2a4` | `mcc_theatre_check_content_entitlement` | supported |
| `0x35c3e0` | `mcc_theater_commit_film` | supported |
| `0x3abdc0` | `saved_film_recording_start` | supported |
| `0x3c2b2c` | `mcc_menu_state_theatre_enter` | supported |
| `0x35c5b8` | `mcc_theatre_screen_event_handler` | inferred |



### saves

Save-game read/write and persistence.

Showing 16 of 108 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x16504` | `game_state_checkpoint_save` | supported |
| `0x16658` | `game_state_checkpoint_load` | supported |
| `0x5a3b8` | `saved_film_initialize_for_new_map` | supported |
| `0x5ab98` | `saved_film_playback_start` | supported |
| `0x5ae74` | `asq_temp_file_path_build` | supported |
| `0x5b328` | `saved_film_playback_active` | supported |
| `0x5bf64` | `time_speed_request_set_clamped_0_to_3` | supported |
| `0x5bf94` | `saved_film_playback_globals_reset` | supported |
| `0x87a88` | `saved_film_header_fill` | supported |
| `0x8839c` | `saved_film_writer_reset` | supported |
| `0x88d38` | `saved_film_writer_stop_and_flush` | supported |
| `0x88fbc` | `saved_film_write_eof_chunk_and_finalize` | supported |
| `0x892bc` | `saved_film_buffered_write` | supported |
| `0x89404` | `saved_film_header_read_game_options` | supported |
| `0x9f5ac` | `hash_lookup3_bytes` | supported |
| `0x9fac0` | `game_state_prepare_for_checkpoint` | supported |


## Data structures

Runtime (from the film notes and direct reading of the code):

- Film header body: 0x1f8a8 bytes. End tick and history span come from the game options (+0x1dc, +0x1e0).
- Film record: a header whose low 30 bits are the length and top 2 bits the type. Type 0 is one game update of 0xd740 bytes (16 player action records of 0xa8 bytes each).
- Checkpoints: every 600 ticks the game saves a full state image of 0xa60000 bytes into a ring of 11 slots.

On-disk tag: `cine` (cinematic) carries scene and shot data.

## Entry points and call flow

Playback: `saved_film_playback_start` builds the file name and opens the file; each recorded update is applied through the normal game tick. Film speed is copied into the game clock and limited to 0 to 3.0. Ending asks the views to stop, unloads the map, disposes the game, stops the recorder and shuts down the network session.

## Open questions / not yet mapped

- Save-game format and persistence are named at entry points but less fully traced than the film path.
- The player-action record fields inside a film update are only partly decoded.
