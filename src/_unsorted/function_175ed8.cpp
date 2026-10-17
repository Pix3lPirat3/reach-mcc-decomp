struct object_a {
    unsigned char reserved0[0x5c];
    bool field_5c;
};
extern "C" void function_175ed8(object_a* object) {
    object->field_5c = true;
}
