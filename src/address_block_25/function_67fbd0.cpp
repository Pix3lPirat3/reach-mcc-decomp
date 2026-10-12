struct object_a {
    unsigned long long field_0;
};
extern "C" unsigned long long function_67fbd0(object_a* object, unsigned short second) {
    return (((unsigned long long)second) << 5) + object->field_0;
}
