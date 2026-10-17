struct object_b {
    unsigned char reserved0[4];
    char field_4;
};

struct object_a {
    unsigned char reserved0[4];
    unsigned short field_4;
};

struct object_c {
    unsigned long long field_0;
};
extern "C" void function_22f6c8(object_a* object, object_b* source, object_c* input) {
    object->field_4 = (unsigned short)(source->field_4);
    input->field_0 += 6ull;
}
