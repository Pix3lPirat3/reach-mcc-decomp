struct object_c {
    unsigned char reserved0[8];
    unsigned long long field_8;
    unsigned long long field_10;
};
extern "C" bool function_42608c(long long, long long, object_c* input) {
    input->field_8 = 0xffffffffffffffffull;
    input->field_10 = 0xffffffffffffffffull;
    return true;
}
