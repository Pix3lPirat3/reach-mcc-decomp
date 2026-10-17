struct object_b {
    unsigned int field_0;
};
extern "C" object_b* function_46418c(long long, object_b* source) {
    source->field_0 &= 0xffffffc1u;
    source->field_0 |= 0xc1;
    return source;
}
