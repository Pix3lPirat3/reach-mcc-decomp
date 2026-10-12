struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x8a];
    bool field_8a;
};
extern "C" bool function_372f8c(object_a* object, long long, object_c* input) {
    object->field_8a = input->field_8;
    return true;
}
