struct block16 {
    unsigned long long low;
    unsigned long long high;
};

extern "C" block16* function_8c804(unsigned char* object, block16* dest) {
    *dest = *(block16*)(*(unsigned char**)(object + 8) + 0x114620);
    return dest;
}
