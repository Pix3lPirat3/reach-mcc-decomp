struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x80];
    bool field_80;
};
extern "C" bool function_31ae50(object_a* object, long long, object_c* input) {
    object->field_80 = input->field_8;
    return true;
}
