struct target {
    unsigned char reserved0[0xE8];
    long long (*handler)(target* self);
};

struct owner {
    unsigned char reserved0[0x60];
    target* field_60;
};

extern "C" long long function_58ffb0(owner* item) {
    target* inner = item->field_60;
    if (inner == 0)
        return 0x13;
    if (inner->handler == 0)
        return 0x13;
    return inner->handler(inner);
}
