struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x70];
    bool field_70;
};
extern "C" bool function_332d88(object_a* object, long long, object_c* input) {
    object->field_70 = input->field_8;
    return true;
}
