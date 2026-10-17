struct object_a {
    unsigned char reserved0[0x8c];
    unsigned short field_8c;
};

struct object_b {
    unsigned short field_0;
};
extern "C" object_b* function_372b30(object_a* object, object_b* source) {
    source->field_0 = object->field_8c;
    return source;
}
