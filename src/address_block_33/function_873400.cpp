struct object_a {
    unsigned char reserved0[0x28];
    unsigned int field_28;
};
extern "C" void function_873400(object_a* object) {
    object->field_28 -= 1;
}
