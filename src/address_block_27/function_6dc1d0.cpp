struct object_b {
    unsigned char reserved0[0x24];
    bool field_24;
};
extern "C" bool function_6dc1d0(long long, object_b* source) {
    source->field_24 = false;
    return true;
}
