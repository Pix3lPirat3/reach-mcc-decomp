struct sha512_context {
    unsigned long long state[8];
    unsigned long long length_low;
    unsigned long long length_high;
    unsigned char block[0x80];
    unsigned int block_used;
    unsigned int digest_length;
};

extern "C" long long SHA384_Init_7a2ec0(sha512_context* context) {
    context->state[0] = 0xcbbb9d5dc1059ed8;
    context->digest_length = 0x30;
    context->state[1] = 0x629a292a367cd507;
    context->state[2] = 0x9159015a3070dd17;
    context->state[3] = 0x152fecd8f70e5939;
    context->state[4] = 0x67332667ffc00b31;
    context->state[5] = 0x8eb44a8768581511;
    context->state[6] = 0xdb0c2e0d64f98fa7;
    context->state[7] = 0x47b5481dbefa4fa4;
    context->length_low = 0;
    context->length_high = 0;
    context->block_used = 0;
    return 1;
}
