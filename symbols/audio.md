# Audio

Part of the MCC Reach system map. Build haloreach.dll, MCC 1.3528 (sha256 738dd2d24ea3aea12e1ee9aa4a61094bf116027d42004c35a19e5048608b0894). See the [system map](SYSTEM-MAP.md).

Audio is sound playback and mixing. Much of the low-level audio in this build is the FMOD library (named from FMOD symbols) with a Halo-side sound layer and MCC's Unreal/Wwise bindings above it. Sound sources, playback and mixing are the main named content.

Coverage: 354 of 386 functions carrying this system tag have a name (88 supported, 1 corroborated, 265 inferred). The remaining 32 are tagged to the system but not yet named.

## Subsystems and named functions

### audio

Sound sources, playback and mixing. Low-level DSP rows are FMOD library functions; higher rows are the Halo sound layer. Some rows are unnamed byte-family members.

Showing 18 of 354 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x10bb0` | `std_string_move_assign` | supported |
| `0x24ccc` | `sound_sources_datum_array_set_new_base_address` | supported |
| `0x24de0` | `sound_effect_datum_array_initialize` | supported |
| `0x25124` | `sound_dispose` | supported |
| `0x26588` | `sound_impulse_new` | supported |
| `0x26744` | `sound_impulse_new_internal` | supported |
| `0x2957c` | `refresh_sounds` | supported |
| `0x29820` | `prioritize_sounds` | supported |
| `0x29eb0` | `sound_collect_channel_budget_lists` | supported |
| `0x2a230` | `sound_find_channel` | supported |
| `0x2a3c8` | `sound_find_best_channel` | supported |
| `0x2a840` | `sound_compute_priority` | supported |
| `0x2a8b0` | `sound_preempts_sound` | supported |
| `0x2b2fc` | `update_channels` | supported |
| `0x2bdcc` | `channel_refresh_location` | supported |
| `0x32b00` | `sound_unattached_impulse_queue_flush` | supported |
| `0x80be0` | `game_engine_get_current_talker` | supported |
| `0x9ff44` | `sound_mirror_event_initialize` | supported |


## Data structures

On-disk tag layouts (Assembly plugins; on-disk, not runtime):

- `snd!` (sound) carries sound class, pitch ranges, codec and playback indices.
- `snmm`, `sLdT`, `sddt`, `smdt` are related sound-bank and mixing groups.

Runtime: sound source and channel pools appear in pools.csv. The DSP filter functions (fmod_dsp_*) are FMOD internals named from the library.

## Entry points and call flow

Entry points: the audio system is brought up at load; sound sources are played through the Halo sound layer, which hands buffers to FMOD DSP. MCC also routes some audio through Unreal/Wwise (AkAudio) bindings.

The full mix graph is not traced; low-level rows are FMOD, which is documented by the library rather than by a Reach trace.

## Open questions / not yet mapped

- The boundary between the Halo sound layer, FMOD and MCC's Wwise bindings is only partly drawn.
- A share of rows are unnamed byte-family members with no behavior recovered.
