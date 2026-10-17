struct object_c {
    unsigned char reserved0[0x1e];
    unsigned short field_1e;
};

struct object_a {
    unsigned long long field_0;
    unsigned long long field_8;
};
extern "C" unsigned long long function_8794c0(object_a* object, unsigned long long second, object_c* input) {
    unsigned short loaded = input->field_1e;
    object->field_8 = (unsigned long long)(input);
    object->field_0 = loaded + second;
    return loaded + second;
}
