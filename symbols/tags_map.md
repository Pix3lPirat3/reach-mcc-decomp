# Tags and map loading

Part of the MCC Reach system map. Build haloreach.dll, MCC 1.3528 (sha256 738dd2d24ea3aea12e1ee9aa4a61094bf116027d42004c35a19e5048608b0894). See the [system map](SYSTEM-MAP.md).

Tags and map loading is the tag system (how the game looks up a tag instance and reads its blocks) and map/cache loading (loading a map cache file, zone sets and tag streaming). It is a small but foundational system: everything else reads its content through tags.

Coverage: 129 of 131 functions carrying this system tag have a name (24 supported, 0 corroborated, 105 inferred). The remaining 2 are tagged to the system but not yet named.

## Subsystems and named functions

### tags

Tag instance lookup and tag block access.

Showing 16 of 129 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0xdb08` | `port64_reserve_address_space_and_init` | supported |
| `0x143a8` | `tag_system_dispose_all_tags` | supported |
| `0x15278` | `tag_resource_range_change_notify_callbacks` | supported |
| `0x154bc` | `scenario_zone_set_switch_from_masks` | supported |
| `0x20554` | `crypto_rsa_verify_signature_with_key_table` | supported |
| `0x2f0a0` | `tag_cache_header_validate_report` | supported |
| `0x31ae8` | `tag_get_by_group_and_index` | supported |
| `0x31d64` | `tag_iterator_next` | supported |
| `0x3f9fc` | `cache_file_path_build_from_index` | supported |
| `0x41890` | `map_file_path_from_name` | supported |
| `0x41a20` | `tag_memory_cap_for_scenario_type` | supported |
| `0x8b2c4` | `cache_file_arrays_size_for_load` | supported |
| `0x8b4b0` | `cache_page_list_resolve_shared_pages` | supported |
| `0x8bc8c` | `runtime_resource_locations_initialize` | supported |
| `0x8f1fc` | `scenario_zone_set_selection_write` | supported |
| `0x92044` | `tag_load_postprocess_per_tag` | supported |


## Data structures

The on-disk tag layouts for 75 tag groups (from the Assembly plugins) describe how each tag type is laid out on disk. These are the layouts the other systems' structure sections cite. They are on-disk layouts, not runtime offsets.

Runtime: a loaded map exposes a tag instance table; tag lookups resolve a tag id to its loaded block.

## Entry points and call flow

Entry points: map load reads the cache header, loads the active zone set and streams tag data. Tag lookups go through the tag instance table.

The zone-set and streaming paths are named only in part.

## Open questions / not yet mapped

- Tag streaming and zone-set switching are only partly named.
- The runtime tag instance table layout is not fully recovered.
