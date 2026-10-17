struct bounds {
    int field_0;
    int field_4;
    unsigned char reserved8[8];
    int field_10;
};

struct range_holder {
    unsigned char reserved0[0x10];
    bounds* field_10;
    int field_18;
};

extern "C" char* function_676710(range_holder* holder, char* result) {
    bounds* limits = holder->field_10;
    *result = holder->field_18 <= (limits->field_10 - 1) * limits->field_0 + limits->field_4;
    return result;
}
