struct object_b {
    unsigned char reserved0[0x2a];
    bool field_2a;
};
extern "C" void function_6ce0c0(long long, object_b* source) {
    source->field_2a = false;
}
