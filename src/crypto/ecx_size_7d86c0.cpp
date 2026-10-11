struct ecx_key_type {
    int nid;
};

struct ecx_key {
    unsigned char reserved0[0x10];
    ecx_key_type* type;
};

extern "C" int ecx_size_7d86c0(ecx_key* key) {
    int nid = key->type->nid;
    if (nid == 0x40a) {
        return 0x20;
    }
    if (nid == 0x43f) {
        return 0x20;
    }
    return (nid != 0x40b) + 0x38;
}
