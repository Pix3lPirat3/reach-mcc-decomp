struct object_a {
    unsigned char reserved0[0x70];
    unsigned short field_70;
};

struct object_b {
    unsigned short field_0;
};
extern "C" object_b* function_359750(object_a* object, object_b* source) {
    source->field_0 = object->field_70;
    return source;
}
