struct object_a {
    unsigned char reserved0[8];
    unsigned int field_8;
    unsigned char reservedc[0xc];
    unsigned int field_18;
};
extern "C" void function_12d94c(object_a* object) {
    object->field_18 = 0;
    object->field_8 = 0x7f7fffee;
}
