struct object_a {
    unsigned char reserved0[0x98];
    unsigned int field_98;
};

struct object_b {
    unsigned int field_0;
};
extern "C" object_b* function_2ff900(object_a* object, object_b* source) {
    source->field_0 = object->field_98;
    return source;
}
