struct output {
    int field_0;
    int field_4;
    int field_8;
    int field_c;
    int field_10;
    int field_14;
    int field_18;
    int field_1c;
    int field_20;
    int field_24;
    int field_28;
    int field_2c;
    int field_30;
};

struct input {
    int field_0;
    int field_4;
    int field_8;
    int field_c;
    int field_10;
    int field_14;
    int field_18;
    int field_1c;
    int field_20;
    int field_24;
    int field_28;
    int field_2c;
};

extern "C" input* function_24f2dc(output* out, input* in) {
    out->field_4 = in->field_0;
    out->field_10 = in->field_4;
    out->field_1c = in->field_8;
    out->field_8 = in->field_10;
    out->field_14 = in->field_14;
    out->field_20 = in->field_18;
    out->field_c = in->field_20;
    out->field_18 = in->field_24;
    out->field_24 = in->field_28;
    out->field_28 = in->field_c;
    out->field_2c = in->field_1c;
    out->field_30 = in->field_2c;
    out->field_0 = 0x3F800000;
    return in;
}
