struct method_block {
    int field_0;
};

struct key_block {
    unsigned char reserved0[0x10];
    method_block* field_10;
};

extern "C" int ecx_bits_7d86f0(key_block* key) {
    int id = key->field_10->field_0;
    if (id == 0x40a)
        return 0xfd;
    if (id == 0x43f)
        return 0xfd;
    return id == 0x40b ? 0x1c0 : 0x1c8;
}
