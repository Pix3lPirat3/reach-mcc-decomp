struct object_a {
    unsigned char reserved0[0x10];
    unsigned int field_10;
};
extern "C" unsigned long long function_23e9cc(object_a* object) {
    return (((unsigned long long)object->field_10) << 6) + 7ull;
}
