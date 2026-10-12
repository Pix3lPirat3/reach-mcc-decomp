struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0xa8];
    bool field_a8;
};
extern "C" bool function_329c9c(object_a* object, long long, object_c* input) {
    object->field_a8 = input->field_8;
    return true;
}
