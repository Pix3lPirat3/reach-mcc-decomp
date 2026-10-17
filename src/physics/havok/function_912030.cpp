struct object_a_field_10 {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x10];
    object_a_field_10* field_10;
};
extern "C" unsigned int function_912030(object_a* object) {
    return object->field_10->field_8;
}
