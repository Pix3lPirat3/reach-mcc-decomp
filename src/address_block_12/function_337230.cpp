struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x84];
    unsigned int field_84;
};
extern "C" bool function_337230(object_a* object, long long, object_c* input) {
    object->field_84 = input->field_8;
    return true;
}
