struct object_b {
    unsigned long long field_0;
};

struct object_a {
    unsigned char reserved0[0x88];
    unsigned long long field_88;
};
extern "C" bool function_3e5580(object_a* object, object_b* source) {
    object->field_88 = source->field_0;
    return true;
}
