struct object_a {
    unsigned char reserved0[0x88];
    unsigned short field_88;
};

struct object_b {
    unsigned short field_0;
};
extern "C" object_b* function_36e860(object_a* object, object_b* source) {
    source->field_0 = object->field_88;
    return source;
}
