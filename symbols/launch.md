# Launch

Part of the MCC Reach system map. Build haloreach.dll, MCC 1.3528 (sha256 738dd2d24ea3aea12e1ee9aa4a61094bf116027d42004c35a19e5048608b0894). See the [system map](SYSTEM-MAP.md).

Launch is the process boot and launcher handoff: the small amount of code that brings the game up from the launcher into a running session. It is the smallest system.

Coverage: 51 of 55 functions carrying this system tag have a name (48 supported, 0 corroborated, 3 inferred). The remaining 4 are tagged to the system but not yet named.

## Subsystems and named functions

### boot

Launcher handoff and the game boot sequence.

Showing 16 of 51 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x1e423c` | `mcc_library_load_module` | supported |
| `0x1e45a0` | `mcc_library_unload_module` | supported |
| `0x1e4788` | `mcc_library_queue_load` | supported |
| `0x1e4980` | `mcc_library_queue_unload` | supported |
| `0x1e4a20` | `mcc_library_available_bitmask` | supported |
| `0x1e4a8c` | `mcc_game_id_to_install_slot` | supported |
| `0x1e4ad8` | `mcc_library_install_dll_path` | supported |
| `0x1e4c28` | `mcc_library_relative_dll_path` | supported |
| `0x1e4c90` | `mcc_library_loader_busy` | supported |
| `0x1e4d0c` | `mcc_library_call_set_library_settings` | supported |
| `0x1e4eb4` | `mcc_library_manager_ctor` | supported |
| `0x1e5064` | `mcc_library_index_to_product_index` | supported |
| `0x1e50b4` | `mcc_library_index_validate` | supported |
| `0x1e5104` | `mcc_library_worker_loop` | supported |
| `0x1e52bc` | `mcc_library_queue_enqueue` | supported |
| `0x1e6330` | `mcc_launch_request_init` | supported |


## Data structures

No dedicated tag or large runtime structure; launch code reads startup parameters and hands off to the engine init path.

## Entry points and call flow

Entry points: the boot path initializes the engine and session, then hands control to the game loop. Only part of the sequence is named.

## Open questions / not yet mapped

- The boot sequence is only partly named; most rows carry a system tag but no clean name yet.
