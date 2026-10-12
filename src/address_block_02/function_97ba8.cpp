struct object_a {
    unsigned char reserved0[9];
    bool field_9;
};
extern "C" void function_97ba8(object_a* object) {
    object->field_9 = true;
}
