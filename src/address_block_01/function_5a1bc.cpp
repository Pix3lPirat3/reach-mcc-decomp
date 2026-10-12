extern "C" long long function_78932a(long long dest, long long value, long long size);
extern "C" long long string_copy_padded_117b8(long long dest, long long source, unsigned long long size);
extern "C" long long function_35c3c(long long dest, long long source, long long size);

extern "C" long long function_5a1bc(unsigned char* header, long long name, long long extra) {
    function_78932a((long long)(header + 4), 0, 0x204);
    *(int*)header = 1;
    string_copy_padded_117b8((long long)(header + 8), name, 0x100);
    if (extra == 0)
        return (long long)header;
    function_35c3c((long long)(header + 0x108), extra, 0x80);
    return (long long)header;
}
