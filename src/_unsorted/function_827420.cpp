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
extern "C" int function_79eba0(void *);
extern "C" void function_82de60(void *, int, void *);

extern "C" long long function_827420(Object8 *object8, Object10 *object10) {
    int local1;
    local1 = function_79eba0(object8);
    function_82de60((Object9 *)function_79eb80(object8), local1, object10);
    return 1;
}
