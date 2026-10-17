struct object_a {
    unsigned char reserved0[0x38];
    unsigned long long field_38;
};
extern "C" void function_237898(object_a* object) {
    object->field_38 = 0;
}
