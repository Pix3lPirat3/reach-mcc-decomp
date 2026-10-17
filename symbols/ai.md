# AI

Part of the MCC Reach system map. Build haloreach.dll, MCC 1.3528 (sha256 738dd2d24ea3aea12e1ee9aa4a61094bf116027d42004c35a19e5048608b0894). See the [system map](SYSTEM-MAP.md).

AI is the actor behavior system: each AI character (an actor) walks a tree of behaviors to decide what to do, grouped into squads, perceiving the world through props (things an actor knows about, such as an enemy it has seen). This is campaign and Firefight AI; it is a large, mostly native system.

Coverage: 1467 of 1710 functions carrying this system tag have a name (99 supported, 0 corroborated, 1368 inferred). The remaining 243 are tagged to the system but not yet named.

## Subsystems and named functions

### ai

Core AI actor behavior and perception: the behavior tree, targeting, firing, movement and pathfinding, and actor lifetime.

Showing 22 of 1450 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x1232cc` | `fireteam_member_join_event_log` | supported |
| `0x1c4248` | `point2d_closest_point_on_polygon_edges` | supported |
| `0x68d56c` | `actor_get_character_definition_properties_68d56c` | supported |
| `0x68d75c` | `ai_module_initialize` | supported |
| `0x6972d4` | `squad_vehicle_change_squad` | supported |
| `0x69c990` | `ai_squad_is_in_squad_group` | supported |
| `0x69ca08` | `squad_get_by_name` | supported |
| `0x69ca8c` | `ai_scenario_find_squad_group_index_by_name` | supported |
| `0x6ab5a0` | `actors_update_single_actor` | supported |
| `0x6af754` | `actor_get_character_definition_properties_6af754` | supported |
| `0x6af9c8` | `actor_get_character_definition_properties_6af9c8` | supported |
| `0x6aff00` | `ai_location_find_character_definition_block_a8` | supported |
| `0x6affb8` | `ai_location_find_character_definition_block_144` | supported |
| `0x6b1f6c` | `command_script_atom_update_dispatch` | supported |
| `0x6b3e5c` | `character_properties_weight_list_find_entry` | supported |
| `0x6b96a8` | `ai_movement_weights_apply_pass1` | supported |
| `0x6bd038` | `actor_get_character_definition_properties_6bd038` | supported |
| `0x6bd5e8` | `ai_ref_format_debug_name` | supported |
| `0x6be324` | `ai_command_scripts_clear_owner` | supported |
| `0x6c2fa8` | `ai_behavior_tree_build` | supported |
| `0x6c3368` | `ai_behavior_update_level` | supported |
| `0x6c3588` | `ai_behavior_evaluate_child` | supported |



### squad

Squad grouping and coordination. A few rows here are MCC-side squad/join UI glue rather than engine AI.

Showing 17 of 17 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x2da868` | `mcc_squad_queue_join` | supported |
| `0x2dab08` | `mcc_squad_get` | supported |
| `0x2dab1c` | `mcc_squad_set_deferred_join` | supported |
| `0x39c3f4` | `mcc_ui_state_singleton_get` | supported |
| `0x39c780` | `mcc_squad_request_join` | supported |
| `0x39c96c` | `mcc_squad_join_gate` | supported |
| `0x39cad0` | `mcc_squad_leave` | supported |
| `0x39cdb4` | `mcc_squad_promote_host` | supported |
| `0x39ce8c` | `mcc_squad_session_state_watch` | supported |
| `0x39d0a4` | `mcc_squad_update` | supported |
| `0x39e6a4` | `mcc_squad_create_session_done` | supported |
| `0x39e958` | `mcc_squad_adopt_session` | supported |
| `0x39eb88` | `mcc_squad_set_state` | supported |
| `0x39fad4` | `mcc_squad_create_steam_lobby` | supported |
| `0x3a0888` | `mcc_squad_publish_joinability` | supported |
| `0x472ce8` | `mcc_flow_set_squad_mode` | supported |
| `0x39e47c` | `net_session_membership_apply_update_message` | inferred |


## Data structures

Runtime (from the AI notes and direct reading of the code):

- Actor record: 0xd00 bytes. Up to 96 actors exist at once. Each actor keeps a stack of the behaviors it is running at +0x90.
- Squad: 0xec bytes, holds actors. Prop: 0xb0 bytes, one per thing an actor knows about.
- Behavior table: 185 entries of 0x18 bytes at 0xb81c30. Each entry has an id and four function pointers (check, update, begin, end). The tree is built when a level loads.

Behavior ids seen in play (meanings are a best reading): 1 top of tree; 132 idle; 134/135 wander; 6 move to a place; 12 fight; 29 main fight choices; 65/66 notice an enemy; 158-164 vehicle behavior.

On-disk tag layouts: unit definitions (`bipd`, `crea`) and `scnr` squad placement describe AI content on disk, not the runtime actor.

## Entry points and call flow

How an AI attack goes (names and addresses from the AI notes): a sound or damage event reaches the actor; the actor makes a prop for what it saw; it picks the best target prop, scores it and checks it can fire; it builds a fire command and moves (with path search); when the unit dies it is cleaned up and the actor deleted.

Spawning: a squad is placed, picks spawn points, then each actor is created and set up (`ai_module_initialize` brings the system up at load).

## Open questions / not yet mapped

- The four-function behavior records are named by role, but the exact logic inside most behaviors is inferred from call structure.
- Behavior id meanings are a best reading, not proven.
- Perception scoring and pathfinding are named at entry points but not fully traced.
