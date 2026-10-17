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
extern "C" void function_855710(void *, void *);

extern "C" long long function_82c7a0(Object8 *object8, Object9 *object9) {
    function_855710(object9, (Object10 *)function_79eb80(object8));
    return 1;
}
