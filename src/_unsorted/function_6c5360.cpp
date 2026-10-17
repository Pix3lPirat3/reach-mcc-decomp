struct object_b {
    unsigned char reserved0[4];
    unsigned int field_4;
};

struct object_a {
    unsigned char reserved0[0x24];
    unsigned int field_24;
};
extern "C" void function_6c5360(object_a* object, object_b* source) {
    object->field_24 = source->field_4;
}
