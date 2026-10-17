struct object_a {
    unsigned char reserved0[2];
    unsigned short field_2;
};
extern "C" unsigned long long function_680a90(object_a* object) {
    return ((object->field_2 << 6) + 0x14ull) + ((unsigned long long)(object));
}
