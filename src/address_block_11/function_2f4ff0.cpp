struct entry {
    unsigned char reserved0[0x10];
    int field_10;
    unsigned char reserved14[4];
    unsigned long long field_18;
};

extern "C" char function_2f4ff0(entry** first, entry** second) {
    entry* left = *first;
    entry* right = *second;
    if (left->field_10 > right->field_10)
        return 1;
    if (left->field_10 != right->field_10)
        return 0;
    if (left->field_18 > right->field_18)
        return 1;
    return 0;
}
