struct output {
    float field_0;
    float field_4;
    float field_8;
    int field_c;
    float field_10;
    float field_14;
    float field_18;
    int field_1c;
    float field_20;
    float field_24;
    float field_28;
    int field_2c;
};

struct input {
    float field_0;
    float field_4;
    float field_8;
    float field_c;
    float field_10;
    float field_14;
    float field_18;
    float field_1c;
    float field_20;
    float field_24;
    int field_28;
    int field_2c;
    int field_30;
};

extern "C" int function_284e48(output* out, input* in) {
    out->field_0 = in->field_4 * in->field_0;
    out->field_4 = in->field_10 * in->field_0;
    out->field_8 = in->field_1c * in->field_0;
    out->field_c = in->field_28;
    out->field_10 = in->field_8 * in->field_0;
    out->field_14 = in->field_14 * in->field_0;
    out->field_18 = in->field_20 * in->field_0;
    out->field_1c = in->field_2c;
    out->field_20 = in->field_c * in->field_0;
    out->field_24 = in->field_18 * in->field_0;
    out->field_28 = in->field_24 * in->field_0;
    int last = in->field_30;
    out->field_2c = last;
    return last;
}
