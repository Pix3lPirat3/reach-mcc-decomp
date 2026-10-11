# Weapons, damage and vehicles

Firing: the weapon update (0x4b8778) checks each trigger (0x4b7f4c, 0x4c0554), then fires (0x4b6318, 0x4c2710), which builds the shot message (0x3a6ab0) and creates projectiles. A projectile moves and checks for hits every tick (0x4f03f0, 0x4f4e88). A hit goes to the impact code (0x4f2d00), which makes damage (0x49e980).

Damage: the amount is worked out (0x4dc274), applied to the object and its parents (0x4dcb30, 0x4dcf10), then to the hit section (0x4e437C, 0x4e08c4). If health is gone the object is marked killed (0x4e41cc).

Reload: starts at 0x505a9c, the magazine begins reloading (0x4c1aa8) and finishes in 0x4b6994.

Grenades: thrown by 0x5069fc, explode through 0x4f5b34, then area damage (0x4f55fc, 0x4e559c).

Melee: 0x50b63c starts it, 0x4919d4 finds the target, 0x4924f0 applies it.

Vehicles: entering picks a seat (0x485c8c), checks it (0x48668c) and attaches the unit (0x4c8f18). Leaving uses 0x4c969c, 0x4c9dbc and 0x4c98d0.

Death and respawn: the unit dies (0x489aac), drops weapons, becomes a dead biped (0x4a6450). On respawn a new unit is made (0x4a0b28) and given the starting items (0x48d7f0).

Weapon record: flags +0x1c8, heat +0x1e0, owner +0x32c. Unit record: weapon slots +0x34a, +0x34b, four weapon handles at +0x350.
