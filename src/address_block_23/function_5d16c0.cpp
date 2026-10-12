struct source {
    unsigned char reserved0[0x58];
    void* pointer_58;
};

extern "C" int function_5d16c0(source* item, unsigned char* result) {
    *result = item->pointer_58 != 0 ? 1 : 0xFF;
    return 0;
}
