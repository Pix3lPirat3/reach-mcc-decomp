struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x72];
    bool field_72;
};
extern "C" bool function_319704(object_a* object, long long, object_c* input) {
    object->field_72 = input->field_8;
    return true;
}
