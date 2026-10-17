struct target {
    unsigned char reserved0[0x22];
    unsigned char field_22;
};

struct constraint {
    unsigned char reserved0[0x60];
    target* field_60;
};

extern "C" long long hkpWorld_addConstraintToIslandAndNotify_8af640(void* world, constraint* link);

extern "C" target* function_8d7e90(void* world, constraint* link, int flags) {
    hkpWorld_addConstraintToIslandAndNotify_8af640(world, link);
    target* result = link->field_60;
    result->field_22 = (unsigned char)(result->field_22 | flags);
    return result;
}
