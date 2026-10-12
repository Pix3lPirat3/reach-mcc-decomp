struct source {
    unsigned char reserved0[0x10];
    int field_10;
};

struct target {
    unsigned char reserved0[0x24];
    int field_24;
    int field_28;
};

struct holder {
    unsigned char reserved0[0x10];
    target* field_10;
};

extern "C" int function_8c7a10(source* from, holder* to) {
    target* dest = to->field_10;
    dest->field_24 = from->field_10;
    int value = from->field_10;
    dest->field_28 = value;
    return value;
}
