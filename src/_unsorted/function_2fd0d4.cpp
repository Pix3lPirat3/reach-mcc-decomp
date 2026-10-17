struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x8c];
    bool field_8c;
};
extern "C" bool function_2fd0d4(object_a* object, long long, object_c* input) {
    object->field_8c = input->field_8;
    return true;
}
