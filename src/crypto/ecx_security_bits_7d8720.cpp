struct method_block {
    int field_0;
};

struct key_block {
    unsigned char reserved0[0x10];
    method_block* field_10;
};

extern "C" int ecx_security_bits_7d8720(key_block* key) {
    int id = key->field_10->field_0;
    if (id == 0x40a)
        return 0x80;
    return id != 0x43f ? 0xe0 : 0x80;
}
