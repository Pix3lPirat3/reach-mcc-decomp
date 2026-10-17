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

extern "C" long long function_79eb80(void *);
extern "C" long long function_82e260(void *, unsigned long long, void *, void *);

extern "C" long long function_827470(Object8 *object8, Object10 *object10, Object10 *object102, long long value) {
    function_82e260((Object9 *)function_79eb80(object8), value, object102, object10);
    return 1;
}
