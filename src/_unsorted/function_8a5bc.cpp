struct object_a {
    unsigned char reserved0[8];
    bool field_8;
    unsigned char reserved9[3];
    unsigned int field_c;
};
extern "C" void function_8a5bc(object_a* object) {
    object->field_c = 0;
    object->field_8 = false;
}
