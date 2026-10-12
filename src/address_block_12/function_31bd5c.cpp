struct object_c {
    unsigned int field_0;
    unsigned char reserved4[4];
    unsigned long long field_8;
};
extern "C" bool function_31bd5c(long long, long long, object_c* input) {
    input->field_8 = 0;
    input->field_0 = 9;
    return true;
}
