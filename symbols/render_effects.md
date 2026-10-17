# Render and effects

Part of the MCC Reach system map. Build haloreach.dll, MCC 1.3528 (sha256 738dd2d24ea3aea12e1ee9aa4a61094bf116027d42004c35a19e5048608b0894). See the [system map](SYSTEM-MAP.md).

Render and effects covers the render pipeline and draw submission, and the particle and visual-effects systems. In this build the render tag is thin (most of the actual GPU pipeline is MCC's Unreal renderer), while the effects side has more named Halo content: particles, beams, decals and contrails.

Coverage: 350 of 354 functions carrying this system tag have a name (40 supported, 0 corroborated, 310 inferred). The remaining 4 are tagged to the system but not yet named.

## Subsystems and named functions

### effects

Particle systems and visual effects: particle emitters, beams, decals, light volumes and contrails.

Showing 18 of 293 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x1157c0` | `effect_event_array_set_new_base_address` | supported |
| `0x115888` | `effects_initialize` | supported |
| `0x11ad3c` | `effect_new` | supported |
| `0x11afe4` | `effect_event_create` | supported |
| `0x11b410` | `effect_location_create` | supported |
| `0x11d7e4` | `light_volume_system_create` | supported |
| `0x121b3c` | `effect_message_queue_reset` | supported |
| `0x121ddc` | `effect_deferred_creation_requests_process` | supported |
| `0x15cd0c` | `decal_datum_array_initialize` | supported |
| `0x15d24c` | `decal_systems_destroy_all` | supported |
| `0x15db8c` | `decal_system_create` | supported |
| `0x160044` | `screen_effect_create` | supported |
| `0x1d4b20` | `particle_system_create` | supported |
| `0x1fd63c` | `contrail_system_data_set_new_base_address` | supported |
| `0x1fdf2c` | `contrail_location_create` | supported |
| `0x1fe44c` | `contrail_create` | supported |
| `0x1ff118` | `contrail_profile_create` | supported |
| `0x1ff574` | `particle_location_data_set_new_base_address` | supported |



### render

Render pipeline and draw submission. This tag is small; the heavy renderer is the Unreal host.

Showing 18 of 57 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x2292e0` | `visibility_build_region_from_pvs` | inferred |
| `0x229dcc` | `visibility_volume_build` | inferred |
| `0x2530f0` | `s_setup_lighting__setup_structure_instance_part` | inferred |
| `0x256434` | `c_structure_renderer__render_all_active_bsps` | inferred |
| `0x2581fc` | `c_water_renderer__is_active_ripple_exist` | inferred |
| `0x2593cc` | `c_water_renderer__render_water_part` | inferred |
| `0x25ac70` | `c_imposter_renderer__render_object_imposters_begin` | inferred |
| `0x25affc` | `c_imposter_renderer__render` | inferred |
| `0x25c17c` | `frame_texture_get_source` | inferred |
| `0x25c6e4` | `c_player_window_data__fill_with_defaults` | inferred |
| `0x26162c` | `render_method_submit_dynamic_cubemap` | inferred |
| `0x261b00` | `submit_extern_texture` | inferred |
| `0x262840` | `update_constants` | inferred |
| `0x26625c` | `render_object_invalidate_render_state` | inferred |
| `0x26a0f4` | `c_screen_postprocess__copy` | inferred |
| `0x26ade4` | `c_screen_postprocess__postprocess_final_composite` | inferred |
| `0x26b81c` | `c_screen_postprocess__setup_rasterizer_for_postprocess` | inferred |
| `0x26cfe8` | `c_player_view__submit_attachments` | inferred |


## Data structures

On-disk tag layouts (Assembly plugins; on-disk, not runtime):

- `prt3` (particle model), `effe` (effect), `efsc` (effect scenery), `beam`, `decs` (decal system), `ltvl` (light volume) describe effect content on disk.
- `bitm` (bitmap) and the `rm**` render-method/shader tags describe textures and shaders.

Runtime: effect pools (emitters, beams, light volumes) appear in pools.csv with their counts and element sizes.

## Entry points and call flow

Entry points: effect pools are created at load (see pools.csv). Particle and beam systems are stepped from the render/effects update each frame.

The draw-submission path is mostly the Unreal renderer and is not traced as Halo code here.

## Open questions / not yet mapped

- The render tag is nearly empty because the real pipeline is the Unreal host; what belongs to Halo versus Unreal is not fully separated.
- Particle update internals are named at pool creation but not fully traced.
