# AI

Each AI character (actor) has a record of 0xd00 bytes. Up to 96 actors exist at once in the Reach list. Squads (0xec bytes each) hold actors. Props (0xb0 bytes) are things an actor knows about, such as an enemy it has seen.

## Behaviors

An actor decides what to do by walking a tree of behaviors. Each behavior has an id, and a record of four functions: check (evaluate), update, begin and end. The records are in a table at 0xb81c30 (185 entries of 0x18 bytes). Check returns 0 or 3. Update returns -2 (keep going), -1 (done) or the id of the next behavior. The tree is built when a level loads (0x6c2fa8).

Each actor keeps a stack of the behaviors it is running, bottom to top, at +0x90 in its record.

Ids seen in play (meaning is a best reading):

- 1: top of the tree.
- 132: idle. 134 and 135: walk around when not fighting.
- 6: move to a place.
- 5: run a script command. 2: do nothing.
- 12: fight (the actor has a target). 29: main fight choices. 30 and 31: get into a firing position.
- 36, 38, 43, 56, 82: decide whether to throw a grenade.
- 65 and 66: notice an enemy. 67 and 69: dodge danger.
- 181: get unstuck.
- 158 and 160: vehicle behavior. 159, 161, 163, 164: fire and move while in a vehicle.
- 184: act together with another actor (scripted pair actions).

## How an AI attack goes

1. A sound or damage event reaches the actor (0x692af4, 0x69340c).
2. The actor makes a prop for what it saw (ai_prop_create).
3. It picks the best target prop (0x7534e0), scores it (0x752fe8) and checks it can fire (prefire check).
4. It builds a fire command (0x751548) and moves (0x6ba2e4, path search 0x71897c).
5. When it dies, the unit is cleaned up (0x6923cc) and the actor deleted (0x6a8828).

Spawning: a squad is placed (0x694cb4), picks spawn points, then each actor is created (0x6a5480) and set up (0x6a4ba0).
