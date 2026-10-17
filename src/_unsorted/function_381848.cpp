struct object_a {
    unsigned char reserved0[0x28];
    unsigned char field_28;
    unsigned char reserved29[0x227];
    unsigned int field_250;
};
extern "C" void function_381848(object_a* object) {
    if (object->field_28 == 2) {
        object->field_250 = 0;
    }
}
