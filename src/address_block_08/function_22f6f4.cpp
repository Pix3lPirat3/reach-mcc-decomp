struct object_b {
    unsigned char reserved0[4];
    bool field_4;
};

struct object_a {
    unsigned char reserved0[9];
    bool field_9;
};

struct object_c {
    unsigned long long field_0;
};
extern "C" void function_22f6f4(object_a* object, object_b* source, object_c* input) {
    object->field_9 = source->field_4;
    input->field_0 += 6ull;
}
