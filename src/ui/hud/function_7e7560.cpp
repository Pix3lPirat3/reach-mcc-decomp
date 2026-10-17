struct Object4;

struct Object4 {
    unsigned char reserved0[1];
};

extern "C" int function_7e7310(void *, void *, void *);

extern "C" int function_7e7560(void * value, void * value2, Object4 *object4) {
    return function_7e7310(value, value2, object4);
}
