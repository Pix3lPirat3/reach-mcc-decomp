struct object_b {
    unsigned int field_0;
};

struct object_a {
    unsigned char reserved0[0x14c];
    unsigned int field_14c;
};
extern "C" void function_2d200c(object_a* object, object_b* source) {
    object->field_14c = source->field_0;
}
