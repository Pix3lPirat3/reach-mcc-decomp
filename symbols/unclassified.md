# Unclassified

Part of the MCC Reach system map. Build haloreach.dll, MCC 1.3528 (sha256 738dd2d24ea3aea12e1ee9aa4a61094bf116027d42004c35a19e5048608b0894). See the [system map](SYSTEM-MAP.md).

Unclassified is an honest catch-all for rows whose original tag (`other`) spans several systems and are not yet cleanly placed. It is kept as its own bucket rather than forced into a system. Most members, read individually, belong to physics/havok or objects/object_datums.

Coverage: 46 of 46 functions carrying this system tag have a name (42 supported, 0 corroborated, 4 inferred). The remaining 0 are tagged to the system but not yet named.

## Subsystems and named functions

### mixed

Mixed-system rows awaiting reclassification (havok proxies, object garbage scan, ragdoll create, datum array alloc).

Showing 16 of 46 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x12fcc` | `datum_array_new` | supported |
| `0x48a68` | `unit_died` | supported |
| `0x61a38` | `input_bindings_map_to_actions` | supported |
| `0x93f94` | `object_water_physics_record_acquire` | supported |
| `0x164b94` | `havok_character_proxy_new` | supported |
| `0x1c95b8` | `ragdoll_admission_check` | supported |
| `0x1c96e4` | `ragdoll_create` | supported |
| `0x389dec` | `mcc_local_user_count` | supported |
| `0x43ad74` | `mcc_catalog_variant_node_ctor` | supported |
| `0x43afa8` | `mcc_catalog_variant_node_load` | supported |
| `0x43b744` | `mcc_catalog_node_unload` | supported |
| `0x43b780` | `mcc_catalog_node_build_options` | supported |
| `0x43bb44` | `mcc_catalog_commit_option_changes` | supported |
| `0x43bc38` | `mcc_catalog_revert_options` | supported |
| `0x43c454` | `mcc_catalog_node_load` | supported |
| `0x43cdb8` | `mcc_catalog_scan_games_range` | supported |


## Data structures

No single structure; members touch Havok proxies, object pools and datum arrays.

## Entry points and call flow

No single flow. Each member should be re-tagged from its own name at a later pass.

## Open questions / not yet mapped

- Every row here needs individual reclassification; the bucket exists to avoid false precision.
