extern "C" long long cpy_univ_7f9690(unsigned int value, unsigned char** cursor) {
    unsigned char* out = *cursor;
    out[0] = (unsigned char)(value >> 0x18);
    out[1] = (unsigned char)(value >> 0x10);
    out[2] = (unsigned char)(value >> 8);
    out[3] = (unsigned char)value;
    *cursor = *cursor + 4;
    return 1;
}
