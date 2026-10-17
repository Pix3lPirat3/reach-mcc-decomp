struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x1240];
    unsigned int field_1240;
};
extern "C" bool function_356754(object_a* object, long long, object_c* input) {
    object->field_1240 = input->field_8;
    return true;
}
