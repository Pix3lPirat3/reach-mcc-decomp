struct Object4;

struct Object4 {
    unsigned char reserved0[1];
};

extern "C" int function_7a8f20(void *, int);

extern "C" int function_7a8ce0(Object4 *object4) {
    return function_7a8f20(object4, 0);
}
