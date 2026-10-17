struct object_a {
    unsigned char reserved0[0x38];
    unsigned int field_38;
};
extern "C" void function_1e0478(object_a* object, unsigned int second) {
    if (object->field_38 == second) {
        object->field_38 = 0xffffffffu;
    }
}
