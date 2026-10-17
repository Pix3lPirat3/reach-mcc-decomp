# Physics (Havok)

Part of the MCC Reach system map. Build haloreach.dll, MCC 1.3528 (sha256 738dd2d24ea3aea12e1ee9aa4a61094bf116027d42004c35a19e5048608b0894). See the [system map](SYSTEM-MAP.md).

Physics is the Havok integration: rigid bodies, character proxies, ragdolls, collision shapes and the physics step. It is the single largest non-host system in the build, and almost all of it is the Havok library itself (class registration, shape math, solver), wrapped by a thin Halo-side layer.

Many names here come from Havok's own class strings baked into the binary (static initializers name their class), which is why a large share are tagged supported. The gameplay-facing wrappers (how Reach drives Havok for bipeds, vehicles and projectiles) are a smaller, less complete slice.

Coverage: 3117 of 3161 functions carrying this system tag have a name (551 supported, 2 corroborated, 2564 inferred). The remaining 44 are tagged to the system but not yet named.

## Subsystems and named functions

### havok

Havok library bindings, the physics step, ragdolls, character proxies and collision. Class-registration and shape names are read from the embedded Havok class strings; the Halo-side driver functions are read from call structure.

Showing 22 of 3117 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x9650` | `static_init_hkvtable_hkBaseObject` | supported |
| `0x9790` | `static_init_hkclass_hkOstream` | supported |
| `0x97e0` | `static_init_hkclass_hkReferencedObject` | supported |
| `0x9840` | `static_init_hkvtable_hkReferencedObject` | supported |
| `0x9880` | `static_init_hkclass_hkBufferedStreamWriter` | supported |
| `0x9940` | `static_init_hkclass_hkArrayStreamWriter` | supported |
| `0x9990` | `static_init_hkclass_hkBaseObject` | supported |
| `0x9a80` | `static_init_hkclass_hkpConvexShape` | supported |
| `0x9af0` | `static_init_hkclass_hkpConvexTransformShapeBase` | supported |
| `0x9b50` | `static_init_hkclass_hkpBvTreeShape` | supported |
| `0x9bc0` | `static_init_hkclass_hkpShapeCollection` | supported |
| `0x9c30` | `static_init_hkclass_hkpShape` | supported |
| `0x9c90` | `static_init_hkclass_hkpSphereRepShape` | supported |
| `0x9ce0` | `static_init_hkclass_hkpShapeContainer` | supported |
| `0x9d30` | `static_init_hkclass_hkpSingleShapeContainer` | supported |
| `0x9d90` | `static_init_hkvtable_hkpSingleShapeContainer` | supported |
| `0x9dd0` | `static_init_hkclass_hkpEntitySmallArraySerializeOverrideType` | supported |
| `0x9e30` | `static_init_hkclass_hkpEntitySpuCollisionCallback` | supported |
| `0x9e90` | `static_init_hkclass_hkpEntityExtendedListeners` | supported |
| `0x9ef0` | `static_init_hkclass_hkpEntity` | supported |
| `0x9f60` | `static_init_hkvtable_hkpEntity` | supported |
| `0x9fa0` | `static_init_hkclass_hkpWorldObject` | supported |


## Data structures

On-disk tag layouts (from the Assembly tag plugins; these describe the tag file on disk and are related to, but not identical to, the runtime Havok objects):

- `phmo` (physics model): Flags, Mass Scale, Mass, deactivation scales, custom shape radius, maximum penetration depth scale, then tag blocks for Damped Spring Motors, Position Motors, Phantom Types and Powered Chains.
- `coll` (collision model): Flags, then tag blocks for Materials, Regions, Pathfinding Spheres and Nodes.

Runtime (from direct reading of the code):

- Havok class and vtable registration happens in static initializers (`static_init_hkclass_*`, `static_init_hkvtable_*`), one per Havok type.
- Shape type numbers match the Havok 2010 `hkpShapeType` enum, which is how several shape functions were identified.

## Entry points and call flow

Entry points are the Havok class registrations that run at load, and the per-tick physics step invoked from the game update. The Halo-side bridge creates rigid bodies for objects (see `projectile_havok_body_build` in objects/weapons) and drives character proxies for bipeds.

The internal Havok call flow (broadphase, narrowphase, solver) is present and partly named from class structure, but it is the stock Havok pipeline rather than Reach-specific logic, so it is documented here by class rather than by a Reach call trace.

## Open questions / not yet mapped

- The boundary between stock Havok and the Halo-side driver is not fully drawn; some wrapper functions are tagged havok because they live in the same address range.
- Ragdoll setup and the character-proxy step are only partly named.
- Runtime object layouts are inferred from the code; the on-disk `phmo`/`coll` field offsets above should not be read as runtime offsets.
