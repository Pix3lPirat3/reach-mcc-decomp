struct object_b {
    unsigned char reserved0[0x28];
    unsigned int field_28;
};
extern "C" void function_6dea20(long long, object_b* source) {
    source->field_28 = 0xffffffffu;
}
