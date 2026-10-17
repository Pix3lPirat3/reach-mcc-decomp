struct object_b {
    unsigned char reserved0[8];
    unsigned long long field_8;
};

struct object_a {
    unsigned char reserved0[0x10];
    unsigned long long field_10;
};

struct object_c {
    unsigned long long field_0;
};
extern "C" void function_22f6d8(object_a* object, object_b* source, object_c* input) {
    object->field_10 = source->field_8;
    input->field_0 += 0x10ull;
}
