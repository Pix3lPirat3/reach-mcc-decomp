struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x74];
    bool field_74;
};
extern "C" bool function_3366e8(object_a* object, long long, object_c* input) {
    object->field_74 = input->field_8;
    return true;
}
