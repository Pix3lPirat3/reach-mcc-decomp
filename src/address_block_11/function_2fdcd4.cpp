struct object_c {
    unsigned char reserved0[8];
    unsigned long long field_8;
};

struct object_a {
    unsigned char reserved0[0x140];
    unsigned long long field_140;
};
extern "C" bool function_2fdcd4(object_a* object, long long, object_c* input) {
    object->field_140 = input->field_8;
    return true;
}
