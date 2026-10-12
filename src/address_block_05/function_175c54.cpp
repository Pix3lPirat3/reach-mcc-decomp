struct object_a {
    unsigned char reserved0[8];
    unsigned int field_8;
};
extern "C" void function_175c54(object_a* object, unsigned int second) {
    if (object->field_8 == second) {
        object->field_8 = 0xffffffffu;
    }
}
