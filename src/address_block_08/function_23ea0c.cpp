struct object_a {
    unsigned char reserved0[0x10];
    unsigned int field_10;
};
extern "C" unsigned long long function_23ea0c(object_a* object) {
    return (((unsigned long long)object->field_10) << 4) + 7ull;
}
