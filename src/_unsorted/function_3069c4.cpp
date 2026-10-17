struct Object86;

struct Object86 {
    unsigned char reserved0[1];
};

extern "C" int function_34da80(void *);

extern "C" int function_3069c4(Object86 *object86) {
    return function_34da80(object86) - 1;
}
