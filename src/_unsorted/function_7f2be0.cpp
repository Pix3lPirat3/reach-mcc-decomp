struct Object2;

struct Object2 {
    unsigned char reserved0[1];
};

extern "C" int function_7f2e80(int, void *, void *);

extern "C" int function_7f2be0(void * value, void * value2) {
    return function_7f2e80(2, (Object2 *)value, (Object2 *)value2);
}
