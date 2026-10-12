struct object_a {
    unsigned char reserved0[0x74];
    unsigned short field_74;
};

struct object_b {
    unsigned short field_0;
};
extern "C" object_b* function_33be64(object_a* object, object_b* source) {
    source->field_0 = object->field_74;
    return source;
}
