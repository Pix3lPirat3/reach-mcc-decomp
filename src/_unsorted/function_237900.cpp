struct object_a {
    unsigned char reserved0[0x38];
    unsigned long long field_38;
};
extern "C" bool function_237900(object_a* object) {
    return object->field_38 == 0ull;
}
