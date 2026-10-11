struct entity {
    unsigned char reserved0[0x108];
    unsigned short constraint_count_a;
    unsigned char reserved10a[0xE];
    int constraint_count_b;
};

extern "C" int hkpEntity_getNumConstraints_8a6a50(entity* body) {
    return body->constraint_count_a + body->constraint_count_b;
}
