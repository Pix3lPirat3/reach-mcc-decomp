struct object_b {
    unsigned int field_0;
};
extern "C" object_b* function_3b0408(long long, object_b* source) {
    source->field_0 &= 0xffffff82u;
    source->field_0 |= 0x82;
    return source;
}
