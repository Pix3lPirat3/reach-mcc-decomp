struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0xa9];
    bool field_a9;
};
extern "C" bool function_329cc4(object_a* object, long long, object_c* input) {
    object->field_a9 = input->field_8;
    return true;
}
