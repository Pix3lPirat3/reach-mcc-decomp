struct source {
    char reserved0[0x168];
    long long field_168;
};

struct output {
    int kind;
    char reserved4[4];
    long long value;
};

extern "C" char function_2d2e1c(source* in, long long, output* out) {
    out->value = in->field_168;
    out->kind = 4;
    return 1;
}
