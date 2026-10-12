struct object_a {
    unsigned char reserved0[0x9c];
    bool field_9c;
};
extern "C" void function_6f1454(object_a* object) {
    object->field_9c = false;
}
