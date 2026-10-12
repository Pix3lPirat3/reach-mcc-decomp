struct Object10;
struct Object9;
struct Object8;

struct Object10 {
    unsigned char reserved0[1];
};

struct Object9 {
    unsigned char reserved0[1];
};

struct Object8 {
    unsigned char reserved0[1];
};

extern "C" void function_84ca30(void *, int, void *);
extern "C" long long function_79eb80(void *);
extern "C" int function_79eba0(void *);

extern "C" long long function_828af0(Object10 *object10, Object9 *object9) {
    int local1;
    local1 = function_79eba0(object10);
    function_84ca30((Object8 *)function_79eb80(object10), local1, object9);
    return 1;
}
