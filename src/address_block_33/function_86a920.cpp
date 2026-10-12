struct encode_context {
    int field_0;
    int field_4;
    unsigned char reserved8[0x50];
    long long field_58;
};

extern "C" int function_86a920(encode_context* context) {
    context->field_4 = 0x30;
    context->field_0 = 0;
    context->field_58 = 0;
    return 0;
}
