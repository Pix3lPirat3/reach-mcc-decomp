struct object_a {
    unsigned char reserved0[0x28];
    unsigned long long field_28;
};
extern "C" bool function_1ba030(object_a* object) {
    return object->field_28 == 0ull;
}
