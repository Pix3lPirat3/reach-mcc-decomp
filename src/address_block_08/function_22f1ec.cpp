struct output {
    char reserved0[0x18];
    int field_18;
    int field_1c;
    int field_20;
};

extern "C" int function_22f1ec(long long, output* out, long long, const int** cursor) {
    const int* data = *cursor;
    out->field_18 = data[0];
    int second = data[1];
    out->field_20 = 0;
    out->field_1c = second;
    *cursor = *cursor + 2;
    return second;
}
