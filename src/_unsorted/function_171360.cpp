extern "C" long long buffered_file_construct_1b8f84(unsigned char* file, int flag, long long extra, int mode);

extern "C" long long function_171360(unsigned char* object, long long, long long extra) {
    buffered_file_construct_1b8f84(object + 0x18, 1, extra, 6);
    return (long long)object;
}
