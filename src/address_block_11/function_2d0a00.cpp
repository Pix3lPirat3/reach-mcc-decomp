struct object_a_field_8 {
    unsigned int field_0;
};

struct object_a {
    unsigned char reserved0[8];
    object_a_field_8* field_8;
};
extern "C" unsigned int function_2d0a00(object_a* object) {
    return object->field_8->field_0 + 1;
}
