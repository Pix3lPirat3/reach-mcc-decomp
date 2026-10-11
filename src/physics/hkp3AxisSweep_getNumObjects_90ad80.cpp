struct sweep {
    unsigned char reserved0[0xA8];
    int field_A8;
};

extern "C" int hkp3AxisSweep_getNumObjects_90ad80(sweep* world) {
    return world->field_A8 - 1;
}
