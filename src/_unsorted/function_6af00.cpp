struct object_a {
    unsigned char reserved0[0xca98];
    unsigned char field_ca98;
};
extern "C" unsigned char* function_6af00(object_a* object) {
    return &object->field_ca98;
}
