struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x77];
    bool field_77;
};
extern "C" bool function_2fc930(object_a* object, long long, object_c* input) {
    object->field_77 = input->field_8;
    return true;
}
