struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x98];
    bool field_98;
};
extern "C" bool function_354e00(object_a* object, long long, object_c* input) {
    object->field_98 = input->field_8;
    return true;
}
