struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x89];
    bool field_89;
};
extern "C" bool function_35f344(object_a* object, long long, object_c* input) {
    object->field_89 = input->field_8;
    return true;
}
