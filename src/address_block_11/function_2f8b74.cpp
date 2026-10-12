struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x390];
    unsigned int field_390;
};
extern "C" bool function_2f8b74(object_a* object, long long, object_c* input) {
    object->field_390 = input->field_8;
    return true;
}
