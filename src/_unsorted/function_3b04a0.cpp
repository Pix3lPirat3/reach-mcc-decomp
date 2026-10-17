struct object_b {
    unsigned int field_0;
};
extern "C" object_b* function_3b04a0(long long, object_b* source) {
    source->field_0 &= 0xffffff81u;
    source->field_0 |= 0x81;
    return source;
}
