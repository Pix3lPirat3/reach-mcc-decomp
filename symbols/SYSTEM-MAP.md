# MCC Reach system map

A reverse-engineering map of Halo: Reach as it runs inside the Master Chief Collection. The subject is one file, `haloreach.dll`, from MCC build 1.3528 (sha256 `738dd2d24ea3aea12e1ee9aa4a61094bf116027d42004c35a19e5048608b0894`). This folder groups what has been read out of that binary into real engine systems, so a reader can start from a part of the game they care about (networking, physics, AI, Forge) and find the functions, data structures and call flow that make it work.

Everything here is read from this one build. Nothing is taken from leaked source, and nothing is run in a way that matters to the descriptions: the evidence is the binary's own code, strings, constants and reflection data.

## What is in this map, and how the pieces relate

Three kinds of knowledge sit behind these docs:

- **Symbols**: a name for a function at a given address (RVA). The name set is large (on the order of 18,000 named functions across the binary). A symbol is a label plus a confidence tier; it does not by itself mean the function's behavior is fully understood.
- **Sources**: a reconstruction of the code as readable C++, one function per file, organized by the same system tree used here. Sources are the long-term goal; most named functions do not yet have a finished source file.
- **Matched-function ledger**: the subset of functions whose reconstructed source compiles to the exact same bytes as this build (around 3,600 functions, roughly 113,000 bytes). A byte-exact match is the strongest possible evidence that a function is understood correctly. The ledger is small on purpose: it counts only proven matches, not names.

So a function can be: unnamed; named at some confidence; named and reconstructed as source; or named, reconstructed and byte-exact matched. These docs report names and structure; the matched ledger is where certainty is highest.

## Confidence tiers (read these carefully)

Every function list in these docs shows a confidence word. They mean:

- **supported / observed**: the name rests on something measured or verified in this build: a text string, a constant, a direct call, reflection data, or a verified disassembly reading. This is the firm tier.
- **corroborated**: two independent static readings of this build reached the same name, with nothing measured at run time. Rare.
- **inferred**: the name follows from who calls the function and what it touches, or from library and vtable structure. **Inferred is provisional.** It is a working hypothesis, not a fact, and it is where mistakes live. Treat an inferred name as a lead to check, not an answer.

Where a name comes from the published symbols set, its tier is the curated symbols tier. Where a name comes only from a research note (for parts of the binary not yet in the published symbols set, such as much of the Unreal host), the tier is that note's own reading, normalized to the three words above. When in doubt, assume inferred.

## Scope: a lot of this binary is not Reach

Two giants dominate the function count and are not Halo gameplay code:

- **Unreal Engine 4 host**: MCC runs Reach inside UE4. The engine-host system below is mostly the UE4 reflected runtime (Kismet and Blueprint libraries, the Gameplay Ability System, actors and components, media players, Wwise audio). Its names are read from Unreal's reflection data. This is the shell, not the game.
- **Xbox Live online stack**: the networking system's online half is the Xbox Authentication Library, the Xbox Services library, a web transport (libHttpClient, websockets, cpprest) and a task queue. More than half of it is an unnamed cluster tail; most online names are inferred from structure.

Reach's own engine logic (objects, physics driver, AI, scripting, game rules, Forge) is the smaller, more interesting remainder. The system map keeps the host and the online stack visible and honestly labeled so the scope is clear, rather than hiding them.

## How to navigate

The systems index below gives the full tree and per-system coverage. Each system has its own page with a plain description, its subsystems, the key named functions (name, RVA, confidence) grouped by subsystem, the data structures it touches, known entry points and call flow, and an honest list of what is not yet mapped.

High-value systems to start with: [Networking](networking.md), [Physics](physics.md), [Game scripting](game_scripting.md), [Objects](objects.md), [Players](players.md), [AI](ai.md).

## A note on data structures

Two kinds of structure appear in these docs. **Runtime** layouts (field offsets in a live object) are recovered from this build's own code and are stated as such. **On-disk tag** layouts come from the community Assembly tag plugin definitions and describe the tag file on disk. On-disk tag offsets are related to, but not identical to, the runtime object layout. These docs never present a tag offset as a runtime offset; a runtime offset is claimed only where direct reading of the code confirms it.

## Honesty

These pages prefer fewer correct statements over broad speculation. Where something is not known, it is listed under open questions rather than guessed. Counts, coverage lines and confidence words are generated from the data, not estimated. A named function is not a solved function; an inferred name is a hypothesis; a byte-exact match in the ledger is the only full proof.

## Systems index

The MCC Reach map is organized into 15 engine systems plus an honest `unclassified` bucket. The tree below folds the raw per-function tags into one home each. Coverage is how many functions carrying a system's tag currently have a name; a low number means open work, not a small system. See the confidence tiers section above for what the confidence words mean.

| System | Named | Tagged | Page |
| --- | ---: | ---: | --- |
| Networking | 2368 | 4585 | [networking.md](networking.md) |
| Physics (Havok) | 3117 | 3161 | [physics.md](physics.md) |
| Game scripting | 1620 | 1623 | [game_scripting.md](game_scripting.md) |
| Objects and datums | 1858 | 2099 | [objects.md](objects.md) |
| Players | 249 | 262 | [players.md](players.md) |
| AI | 1467 | 1710 | [ai.md](ai.md) |
| Game engine | 924 | 936 | [game_engine.md](game_engine.md) |
| Forge | 230 | 236 | [forge.md](forge.md) |
| User interface | 3654 | 3753 | [ui.md](ui.md) |
| Render and effects | 350 | 354 | [render_effects.md](render_effects.md) |
| Audio | 354 | 386 | [audio.md](audio.md) |
| Engine host (UE4) | 4372 | 5070 | [engine_host.md](engine_host.md) |
| Tags and map loading | 129 | 131 | [tags_map.md](tags_map.md) |
| Saves and films | 127 | 146 | [saves_films.md](saves_films.md) |
| Launch | 51 | 55 | [launch.md](launch.md) |
| Unclassified | 46 | 46 | [unclassified.md](unclassified.md) |
| **Total** | **20916** | **24553** | |

Named / Tagged counts are unique function addresses computed from the function rows that carry a system tag. They are internal to this map and are not the same denominator as the published symbols coverage table, which counts differently.

## The tree

```
engine_host
  ue_runtime         UE4 reflected runtime: Kismet/Blueprint libraries, Gameplay Ability System, actors, components, media and Wwise audio bindings.
  engine_core        Halo side engine core glue that is not UE reflection.
  memory             Allocators, pools, heap and memory region bookkeeping.
  platform           OS and store platform services (Steam, product ids, platform libs).
game_engine
  core               Core game engine loop and game-mode dispatch.
  scoring            Score, standings, stats and scoreboard bookkeeping.
  rules_timing       Round and match timers, time limits and end conditions.
  variants           Game variant wrappers, gametype option records and player traits.
  settings           Gameplay settings and option storage.
  spawning           Respawn and spawn-point selection rules.
game_scripting
  haloscript         HaloScript (hsc) engine functions bank: Bungie script VM and built-ins.
  megalo             Megalo gametype scripting VM used by multiplayer variants.
objects
  object_datums      datum_* handle table, object pools and the object instance model.
  weapons            Weapon objects, firing and damage application.
physics
  havok              Havok library bindings, physics step, ragdolls and collision.
players
  player             Player datum, player state and player-facing control code.
  camera             Player camera manager and view construction.
  input              Controller and device input sampling.
networking
  session            net_session state, flow state machine and life-cycle transitions.
  membership_join    Joining, invites, party and lobby membership.
  replication        State replication and sync of networked objects.
  netcode_transport  Packet/channel transport, net messages and bitstream encoding.
  online_services    Xbox Live / XAL / web-transport online stack and MCC online glue.
  host_migration     Host selection, migration and network manager.
  privacy_policy     Join privacy modes and anti-cheat (EAC) gating.
ai
  ai                 Core AI actor behavior and perception.
  squad              Squad grouping and coordination.
audio
  audio              Sound sources, playback and audio mixing.
render_effects
  render             Render pipeline and draw submission.
  effects            Particle systems and visual effects.
tags_map
  tags               Tag instance lookup and tag block access.
  map_loading        Map cache load, zone sets and tag streaming.
forge
  forge_core         Forge object placement and editor runtime.
  forge_ui           Forge editor UI and object menus.
  map_variant        Map-variant placement records and serialization.
ui
  hud                Combat HUD (chud), navpoints and in-game overlays.
  umg                UMG/Slate widget runtime (SdWidget and friends).
  screens            Menu screens and screen flow.
  controller         Controller-driven UI navigation.
saves_films
  saves              Save-game read/write and persistence.
  films              Saved film capture, theater playback and film data.
launch
  boot               Launcher handoff and game boot sequence.
unclassified
  mixed              Mixed-system grab bag awaiting reclassification.
```

## Two giants, split by name rule

Two systems are too large and too generic to leave as one bucket, so their functions are split into subsystems by name pattern:

- **engine_host / ue_runtime** is the Unreal Engine 4 reflected runtime (Kismet libraries, Gameplay Ability System, actors, components, media, Wwise). It is the host MCC wraps Reach in, not Reach code.
- **networking / online_services** is the Xbox Live online stack (XAL, Xbox Services, web transport, task queue). More than half of it is still an unnamed cluster tail, and the split says so rather than inventing structure.
