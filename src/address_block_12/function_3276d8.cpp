struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x55c];
    unsigned int field_55c;
};
extern "C" bool function_3276d8(object_a* object, long long, object_c* input) {
    object->field_55c = input->field_8;
    return true;
}
