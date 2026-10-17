struct object_a {
    unsigned char reserved0[0x98f0];
    unsigned long long field_98f0;
};
extern "C" bool function_2380b8(object_a* object) {
    return object->field_98f0 == 0ull;
}
