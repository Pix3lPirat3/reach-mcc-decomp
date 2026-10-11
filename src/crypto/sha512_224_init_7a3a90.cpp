struct sha512_context {
    unsigned long long hash0;
    unsigned long long hash1;
    unsigned long long hash2;
    unsigned long long hash3;
    unsigned long long hash4;
    unsigned long long hash5;
    unsigned long long hash6;
    unsigned long long hash7;
    unsigned long long count_low;
    unsigned long long count_high;
    unsigned char block[0x80];
    unsigned int block_used;
    unsigned int digest_length;
};

extern "C" long long sha512_224_init_7a3a90(sha512_context* context) {
    context->digest_length = 0x1C;
    context->hash0 = 0x8C3D37C819544DA2;
    context->hash1 = 0x73E1996689DCD4D6;
    context->hash2 = 0x1DFAB7AE32FF9C82;
    context->hash3 = 0x679DD514582F9FCF;
    context->hash4 = 0xF6D2B697BD44DA8;
    context->hash5 = 0x77E36F7304C48942;
    context->hash6 = 0x3F9D85A86A1D36C8;
    context->hash7 = 0x1112E6AD91D692A1;
    context->count_low = 0;
    context->count_high = 0;
    context->block_used = 0;
    return 1;
}
