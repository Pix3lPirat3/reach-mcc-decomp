struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0xaa];
    bool field_aa;
};
extern "C" bool function_329cec(object_a* object, long long, object_c* input) {
    object->field_aa = input->field_8;
    return true;
}
