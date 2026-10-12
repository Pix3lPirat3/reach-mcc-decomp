struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0xb1];
    bool field_b1;
};
extern "C" bool function_329de4(object_a* object, long long, object_c* input) {
    object->field_b1 = input->field_8;
    return true;
}
