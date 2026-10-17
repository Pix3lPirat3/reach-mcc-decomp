struct output {
    char reserved0[0x18];
    int field_18;
    int field_1c;
    int field_20;
};

struct input {
    char reserved0[4];
    int first;
    int second;
};

extern "C" int function_22f700(output* out, input* in, char** cursor) {
    out->field_18 = in->first;
    int second = in->second;
    out->field_20 = 0;
    out->field_1c = second;
    *cursor = *cursor + 0xc;
    return second;
}
