struct sha512_256_context {
    unsigned long long h0;
    unsigned long long h1;
    unsigned long long h2;
    unsigned long long h3;
    unsigned long long h4;
    unsigned long long h5;
    unsigned long long h6;
    unsigned long long h7;
    unsigned long long length_low;
    unsigned long long length_high;
    unsigned char buffer[0x80];
    unsigned int buffered_length;
    unsigned int digest_length;
};

extern "C" long long sha512_256_init_7a3b20(sha512_256_context* context) {
    context->digest_length = 0x20;
    context->h0 = 0x22312194FC2BF72CULL;
    context->h1 = 0x9F555FA3C84C64C2ULL;
    context->h2 = 0x2393B86B6F53B151ULL;
    context->h3 = 0x963877195940EABDULL;
    context->h4 = 0x96283EE2A88EFFE3ULL;
    context->h5 = 0xBE5E1E2553863992ULL;
    context->h6 = 0x2B0199FC2C85B8AAULL;
    context->h7 = 0x0EB72DDC81C52CA2ULL;
    context->length_low = 0;
    context->length_high = 0;
    context->buffered_length = 0;
    return 1;
}
