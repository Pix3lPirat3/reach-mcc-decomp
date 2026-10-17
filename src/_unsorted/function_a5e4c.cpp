struct entry_state {
    unsigned char field_0;
    unsigned char reserved1[0x107];
    unsigned char field_108;
    unsigned char reserved109[0x10F];
    int field_218;
    unsigned char reserved21c[0x24];
};

extern "C" entry_state* function_a5e4c(entry_state* entry) {
    entry->field_0 = 0;
    entry->field_108 = 0;
    entry->field_218 = 0;
    return entry;
}
