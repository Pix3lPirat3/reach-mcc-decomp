struct object_c {
    unsigned char reserved0[8];
    unsigned char field_8;
};
extern "C" bool function_329c0c(long long, long long, object_c* input) {
    return ((unsigned char)(input->field_8 + 1)) <= 5;
}
