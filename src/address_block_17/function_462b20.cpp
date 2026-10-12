struct object_b {
    unsigned int field_0;
};
extern "C" object_b* function_462b20(long long, object_b* source) {
    source->field_0 &= 0xffffffc2u;
    source->field_0 |= 0xc2;
    return source;
}
