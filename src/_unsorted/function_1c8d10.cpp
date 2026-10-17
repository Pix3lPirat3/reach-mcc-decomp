struct object_a_field_38 {
    unsigned char reserved0[0x104];
    unsigned int field_104;
};

struct object_a {
    unsigned char reserved0[0x38];
    object_a_field_38* field_38;
};
extern "C" unsigned int function_1c8d10(object_a* object) {
    return object->field_38->field_104;
}
