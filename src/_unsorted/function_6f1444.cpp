struct object_a {
    unsigned char reserved0[0x138];
    bool field_138;
};
extern "C" void function_6f1444(object_a* object) {
    object->field_138 = false;
}
