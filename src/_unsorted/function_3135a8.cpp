struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x28c];
    bool field_28c;
};
extern "C" bool function_3135a8(object_a* object, long long, object_c* input) {
    object->field_28c = input->field_8;
    return true;
}
