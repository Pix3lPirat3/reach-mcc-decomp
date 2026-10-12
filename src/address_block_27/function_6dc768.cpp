struct object_b {
    unsigned char reserved0[0x24];
    unsigned int field_24;
};
extern "C" bool function_6dc768(long long, object_b* source) {
    source->field_24 = 0xffffffffu;
    return true;
}
