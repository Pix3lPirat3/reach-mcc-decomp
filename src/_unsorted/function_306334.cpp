struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x150];
    unsigned int field_150;
};
extern "C" bool function_306334(object_a* object, long long, object_c* input) {
    object->field_150 = input->field_8;
    return true;
}
