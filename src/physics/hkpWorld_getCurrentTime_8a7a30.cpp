struct world_time {
    unsigned char reserved0[0x24];
    float psi_time;
    float time;
};

struct world {
    unsigned char reserved0[0x10];
    world_time* times;
};

extern "C" float hkpWorld_getCurrentTime_8a7a30(world* sim_world) {
    return sim_world->times->time;
}
