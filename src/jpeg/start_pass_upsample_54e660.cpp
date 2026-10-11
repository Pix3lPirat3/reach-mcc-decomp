extern "C" int start_pass_upsample_54e660(unsigned char* decompress) {
    unsigned char* upsample = *(unsigned char**)(decompress + 0x248);
    *(int*)(upsample + 0xb8) = *(int*)(decompress + 0x17c);
    int value = *(int*)(decompress + 0x78);
    *(int*)(upsample + 0xbc) = value;
    return value;
}
