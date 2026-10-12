struct object_b {
    bool field_0;
};

struct object_a {
    unsigned char reserved0[0x88];
    bool field_88;
};
extern "C" bool function_3e5eec(object_a* object, object_b* source) {
    object->field_88 = source->field_0;
    return true;
}
