struct third_block {
    unsigned int field_0;
};

struct second_block {
    third_block* field_0;
};

struct first_block {
    unsigned char reserved0[0x18];
    second_block* field_18;
};

extern "C" unsigned int EC_KEY_can_sign_7c4610(first_block* key) {
    second_block* second = key->field_18;
    if (second == 0)
        return 0;
    third_block* third = second->field_0;
    if (third == 0)
        return 0;
    return ~(third->field_0 >> 2) & 1;
}
