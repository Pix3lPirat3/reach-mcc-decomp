extern "C" long long cpy_bmp_7f9670(unsigned int code_point, unsigned char** cursor) {
    unsigned char* out = *cursor;
    out[0] = (unsigned char)(code_point >> 8);
    out[1] = (unsigned char)code_point;
    *cursor = *cursor + 2;
    return 1;
}
