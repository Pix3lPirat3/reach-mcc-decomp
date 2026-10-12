struct object_a {
    unsigned char reserved0[0x88];
    unsigned short field_88;
};

struct object_c {
    unsigned short field_0;
};
extern "C" int function_3e5d54(object_a* object, long long, object_c* input) {
    unsigned short loaded = object->field_88;
    input->field_0 = (unsigned short)(loaded);
    return loaded;
}
