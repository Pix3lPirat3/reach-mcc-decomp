struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x75];
    bool field_75;
};
extern "C" bool function_2fc8f8(object_a* object, long long, object_c* input) {
    object->field_75 = input->field_8;
    return true;
}
