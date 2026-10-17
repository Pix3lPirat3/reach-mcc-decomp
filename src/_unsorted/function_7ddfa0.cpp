struct Object34;
struct Object33;
struct Object32;
struct Object30;

struct Object34 {
    unsigned char reserved0[1];
};

struct Object33 {
    unsigned char reserved0[1];
};

struct Object32 {
    unsigned char reserved0[1];
};

struct Object30 {
    unsigned char reserved0[1];
};

extern "C" long long function_79f260(void *);
extern "C" long long function_7a7100(void *);
extern "C" long long function_818a00(void *, void *, void *);

extern "C" long long function_7ddfa0(Object30 *object30, Object33 *object33, Object34 *object34) {
    function_818a00((Object32 *)(function_7a7100((Object30 *)function_79f260(object30)) + 0x18), object33, object34);
    return 1;
}
