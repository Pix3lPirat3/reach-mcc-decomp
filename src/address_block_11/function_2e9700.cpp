struct entry {
    unsigned char reserved0[8];
    int field_8;
};

extern "C" char function_2e9700(entry** first, entry** second) {
    return (*first)->field_8 > (*second)->field_8;
}
