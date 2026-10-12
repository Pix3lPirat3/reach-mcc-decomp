struct key_block {
    unsigned char reserved0[0x30];
    unsigned int field_30;
};

extern "C" int dsa_init_7f3750(key_block* key) {
    key->field_30 = key->field_30 | 1;
    return 1;
}
