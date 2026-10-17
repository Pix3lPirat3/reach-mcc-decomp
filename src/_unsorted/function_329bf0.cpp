struct object_c {
    unsigned int field_0;
    unsigned char reserved4[4];
    unsigned int field_8;
};
extern "C" bool function_329bf0(long long, long long, object_c* input) {
    input->field_8 = 0xffffffffu;
    input->field_0 = 1;
    return true;
}
