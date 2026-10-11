struct rotation {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
};

extern "C" int hk_rotation_set_transpose_86fc90(rotation* result, rotation* source) {
    result->field_0 = source->field_0;
    result->field_14 = source->field_14;
    result->field_28 = source->field_28;
    result->field_C = 0;
    result->field_1C = 0;
    result->field_2C = 0;
    result->field_4 = source->field_10;
    result->field_10 = source->field_4;
    result->field_8 = source->field_20;
    result->field_20 = source->field_8;
    result->field_18 = source->field_24;
    int last = source->field_18;
    result->field_24 = last;
    return last;
}
