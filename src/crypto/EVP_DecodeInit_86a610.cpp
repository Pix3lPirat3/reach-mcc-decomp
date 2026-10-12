struct decode_context {
    long long field_0;
    unsigned char reserved8[0x50];
    long long field_58;
};

extern "C" int EVP_DecodeInit_86a610(decode_context* context) {
    context->field_0 = 0;
    context->field_58 = 0;
    return 0;
}
