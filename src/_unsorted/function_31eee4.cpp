struct object_c {
    unsigned int field_0;
    unsigned char reserved4[4];
    bool field_8;
};
extern "C" bool function_31eee4(long long, long long, object_c* input) {
    input->field_0 = 0;
    input->field_8 = true;
    return true;
}
