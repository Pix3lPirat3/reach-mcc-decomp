struct object_a {
    unsigned char reserved0[0x288];
    unsigned long long field_288;
};
extern "C" unsigned long long function_35f354(object_a* object) {
    return object->field_288;
}
