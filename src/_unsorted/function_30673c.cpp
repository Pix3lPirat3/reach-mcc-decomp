struct Object86;

struct Object86 {
    unsigned char reserved0[1];
};

extern "C" int function_34cbf8(void *);

extern "C" int function_30673c(Object86 *object86) {
    return function_34cbf8(object86) + 1;
}
