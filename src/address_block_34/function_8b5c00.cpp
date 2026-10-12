struct input_a {
    float field_0;
    int field_4;
    float field_8;
    float field_c;
    int field_10;
    int field_14;
};

struct input_b {
    int field_0;
    float field_4;
    float field_8;
};

struct output_a {
    float field_0;
    float field_4;
    int field_8;
    int field_c;
    int field_10;
};

struct output_b {
    unsigned char reserved0[0x1C];
    float field_1c;
};

extern "C" float function_8b5c00(input_a* a, input_b* b, output_b* out_b, output_a* out_a) {
    out_a->field_0 = a->field_8 * b->field_4;
    out_a->field_4 = a->field_c * b->field_4;
    out_a->field_8 = a->field_4;
    out_a->field_c = a->field_10;
    out_a->field_10 = a->field_14;
    float product = b->field_8 * a->field_0;
    out_b->field_1c = product;
    return product;
}
