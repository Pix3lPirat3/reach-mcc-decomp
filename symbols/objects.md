# Objects and datums

Part of the MCC Reach system map. Build haloreach.dll, MCC 1.3528 (sha256 738dd2d24ea3aea12e1ee9aa4a61094bf116027d42004c35a19e5048608b0894). See the [system map](SYSTEM-MAP.md).

Objects is the handle-and-pool model that every game object lives in, plus the items and weapons built on top of it. The `datum_*` layer is the generic machinery: fixed-size pools, handle tables (a handle is an index plus a salt), and the allocate/free/iterate operations. The weapons layer is the firing, damage and item behavior that sits on object instances.

Coverage: 1858 of 2099 functions carrying this system tag have a name (254 supported, 0 corroborated, 1604 inferred). The remaining 241 are tagged to the system but not yet named.

## Subsystems and named functions

### object datums

The datum handle table, object pools and the object instance model: datum arrays, connect/disconnect, iteration and lookup.

Showing 22 of 1502 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x12fcc` | `datum_array_new` | supported |
| `0x1307c` | `data_dispose` | supported |
| `0x130b4` | `data_initialize` | supported |
| `0x13148` | `data_initialize_disconnected` | supported |
| `0x131dc` | `data_connect` | supported |
| `0x13328` | `data_delete_all` | supported |
| `0x13464` | `datum_new` | supported |
| `0x13510` | `datum_new_at_handle` | supported |
| `0x135a0` | `datum_new_at_index` | supported |
| `0x13624` | `datum_new_in_range` | supported |
| `0x136f0` | `datum_delete` | supported |
| `0x137c4` | `datum_get` | supported |
| `0x137f8` | `datum_get_absolute` | supported |
| `0x13870` | `datum_next_handle` | supported |
| `0x138f0` | `datum_initialize` | supported |
| `0x15bb0` | `sync_lock_hierarchy_initialize` | supported |
| `0x16888` | `game_state_load_saved_game` | supported |
| `0x175f0` | `sync_register_named_locks_and_semaphores` | supported |
| `0x19804` | `quaternion_multiply` | supported |
| `0x335cc` | `main_timing_initialize` | supported |
| `0x3cbb4` | `levels_initialize` | supported |
| `0x43440` | `players_initialize` | supported |



### weapons

Weapon objects, firing, damage application and first-person weapons. (Vehicle and melee flow is described in the combat notes.)

Showing 22 of 356 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x188648` | `projectile_havok_body_build` | supported |
| `0x2c6bc4` | `first_person_weapons_initialize` | supported |
| `0x3b0498` | `biped_throw_initiate_event_get_name` | supported |
| `0x3b04d4` | `biped_throw_release_event_get_name` | supported |
| `0x3b04e4` | `biped_melee_initiate_event_get_name` | supported |
| `0x3b050c` | `biped_melee_damage_event_get_name` | supported |
| `0x3b0514` | `biped_melee_clang_event_get_name` | supported |
| `0x3b0594` | `unit_zoom_event_get_name` | supported |
| `0x3b63c4` | `biped_throw_initiate_event_describe_relevance_debug` | supported |
| `0x3b66dc` | `biped_throw_release_event_describe_relevance_debug` | supported |
| `0x3b6be0` | `biped_melee_damage_event_describe_relevance_debug` | supported |
| `0x3b7848` | `biped_melee_initiate_event_describe_relevance_debug` | supported |
| `0x3b7c3c` | `biped_melee_clang_event_describe_relevance_debug` | supported |
| `0x3b8750` | `unit_zoom_event_describe_relevance_debug` | supported |
| `0x434730` | `request_weapon_fire_event_get_name` | supported |
| `0x43475c` | `action_weapon_fire_event_get_name` | supported |
| `0x43476c` | `weapon_reload_event_get_name` | supported |
| `0x434774` | `weapon_pickup_event_get_name` | supported |
| `0x434784` | `weapon_put_away_event_get_name` | supported |
| `0x43478c` | `weapon_drop_event_get_name` | supported |
| `0x434794` | `weapon_effect_event_get_name` | supported |
| `0x43479c` | `weapon_empty_click_event_get_name` | supported |


## Data structures

Runtime (from direct reading of the code and from the pool census):

- Datum arrays: fixed-size pools created at load. Each entry has an in-use marker and a salt so a stale handle can be detected. `datum_array_new`, `data_connect`, `data_initialize` and `data_dispose` are the core operations. The full pool list (name, count, element size) is in pools.csv.
- Object instance: a generic object header followed by type-specific data. From the combat notes, a unit record keeps weapon slot markers at +0x34a/+0x34b and four weapon handles at +0x350; a weapon record keeps flags at +0x1c8, heat at +0x1e0 and owner at +0x32c.

On-disk tag layouts (Assembly plugins; on-disk, not runtime). All object-definition tags share a common object header (Object Type, Flags, Runtime Flags, Bounding Radius, Bounding Offset, acceleration scales):

- `weap` (weapon), `eqip` (equipment), `proj` (projectile), `bipd` (biped), `vehi` (vehicle), `bloc`/`crea`/`mach`/`scen` and others are object definitions. These describe the definition on disk, not the live instance.

## Entry points and call flow

Firing path (names and addresses from the combat notes): the weapon update checks each trigger, fires, builds a shot message and creates a projectile; the projectile moves and tests for hits each tick; a hit produces damage, which is computed, applied to the object and its parents, then to the hit section, and the object is marked killed when health is gone.

Object lifetime: creation runs through the general object-create path (shared by Forge placement and by gameplay spawns); deletion releases the datum back to its pool.

## Open questions / not yet mapped

- Full runtime instance layouts are known only for the fields read so far; most offsets beyond those are not established.
- The mapping from each on-disk object tag to its runtime instance layout is not drawn.
- Damage region and material interactions are named at the entry points but not fully traced.
