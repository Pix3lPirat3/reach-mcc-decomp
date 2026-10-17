struct Object32;
struct Object30;

struct Object32 {
    unsigned char reserved0[1];
};

struct Object30 {
    unsigned char reserved0[1];
};

extern "C" long long function_79f260(void *);
extern "C" long long function_7a7100(void *);
extern "C" long long function_8180a0(void *, long long, unsigned long long);

extern "C" long long function_7dd980(Object30 *object30, long long value, long long value2) {
    function_8180a0((Object32 *)(function_7a7100((Object30 *)function_79f260(object30)) + 0x18), value, value2);
    return 1;
}
