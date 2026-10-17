struct object_a {
    unsigned char reserved0[0x138];
    unsigned long long field_138;
};
extern "C" unsigned long long function_2f7370(object_a* object) {
    return object->field_138;
}
