struct object_a {
    unsigned char reserved0[0x8a];
    unsigned short field_8a;
};

struct object_d {
    unsigned short field_0;
};
extern "C" int function_3e5d70(object_a* object, long long, long long, object_d* extra) {
    unsigned short loaded = object->field_8a;
    extra->field_0 = (unsigned short)(loaded);
    return loaded;
}
