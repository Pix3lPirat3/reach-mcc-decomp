struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x76];
    bool field_76;
};
extern "C" bool function_2fc914(object_a* object, long long, object_c* input) {
    object->field_76 = input->field_8;
    return true;
}
