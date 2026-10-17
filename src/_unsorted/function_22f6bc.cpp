struct object_b {
    unsigned char reserved0[4];
    char field_4;
};

struct object_a {
    unsigned int field_0;
};

struct object_c {
    unsigned long long field_0;
};
extern "C" void function_22f6bc(object_a* object, object_b* source, object_c* input) {
    object->field_0 = source->field_4;
    input->field_0 += 6ull;
}
