struct object_a {
    unsigned char reserved0[0x2870];
    unsigned int field_2870;
};
extern "C" unsigned int function_3541fc(object_a* object) {
    return object->field_2870;
}
