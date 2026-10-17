struct object_a {
    unsigned char reserved0[0x98d8];
    unsigned long long field_98d8;
};
extern "C" bool function_237c48(object_a* object) {
    return object->field_98d8 == 0ull;
}
