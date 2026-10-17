struct object_a {
    unsigned char reserved0[0x58];
    bool field_58;
    unsigned char reserved59[3];
    unsigned int field_5c;
};
extern "C" void function_4005ac(object_a* object, unsigned int second) {
    object->field_58 = true;
    object->field_5c = second;
}
