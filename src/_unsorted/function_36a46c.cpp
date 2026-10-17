struct object_c {
    unsigned char reserved0[8];
    unsigned long long field_8;
};

struct object_a {
    unsigned char reserved0[0x150];
    unsigned long long field_150;
};
extern "C" bool function_36a46c(object_a* object, long long, object_c* input) {
    object->field_150 = input->field_8;
    return true;
}
