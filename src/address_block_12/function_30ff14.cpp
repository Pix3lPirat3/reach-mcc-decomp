struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x7c];
    unsigned int field_7c;
};
extern "C" bool function_30ff14(object_a* object, long long, object_c* input) {
    object->field_7c = input->field_8;
    return true;
}
