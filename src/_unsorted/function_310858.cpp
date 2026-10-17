struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x85];
    bool field_85;
};
extern "C" bool function_310858(object_a* object, long long, object_c* input) {
    object->field_85 = input->field_8;
    return true;
}
