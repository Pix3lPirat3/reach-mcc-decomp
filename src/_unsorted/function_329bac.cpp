struct object_c {
    unsigned char reserved0[8];
    unsigned long long field_8;
};

struct object_a {
    unsigned char reserved0[0x90];
    unsigned long long field_90;
};
extern "C" bool function_329bac(object_a* object, long long, object_c* input) {
    object->field_90 = input->field_8;
    return true;
}
