struct object_a {
    unsigned short field_0;
    unsigned char reserved2[6];
    unsigned long long field_8;
};
extern "C" object_a* function_3cfb3c(object_a* object) {
    object->field_0 = 0;
    object->field_8 = 0ull;
    return object;
}
