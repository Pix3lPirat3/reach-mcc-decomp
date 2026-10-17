struct object_a {
    unsigned char reserved0[8];
    bool field_8;
};
extern "C" void function_89e680(object_a* object) {
    object->field_8 = true;
}
