extern "C" short function_68fedc(void* a, unsigned short b, void* c, unsigned short d, short e, char f, int g, int h, char i, char j, long long k, long long l, void* m);

extern "C" short forward_12_args_to_68fedc_with_zero_690668(void* a, short b, void* c, short d, short e, char f, int g, int h, char i, char j, long long k, long long l) {
    return function_68fedc(a, b, c, d, e, f, g, h, i, j, k, l, 0);
}
