struct inner {
    unsigned char reserved0[0x50];
    long long field_50;
};

struct owner {
    unsigned char reserved0[0x20];
    inner* field_20;
};

extern "C" char* function_912be0(owner* self, char* out) {
    *out = self->field_20->field_50 != 0;
    return out;
}
