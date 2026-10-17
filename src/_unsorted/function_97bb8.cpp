struct object_a {
    unsigned char reserved0[0xb];
    bool field_b;
};
extern "C" void function_97bb8(object_a* object) {
    object->field_b = true;
}
