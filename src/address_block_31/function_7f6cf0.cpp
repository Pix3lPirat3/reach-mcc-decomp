struct Object2;

struct Object2 {
    unsigned char reserved0[1];
};

extern "C" int function_7f6d30(void *, int, void *, int, void *, int, void *, void *);

extern "C" unsigned int function_7f6cf0(Object2 *object2, int value, void * value2, int value3, void * value4, int value5) {
    return function_7f6d30(object2, value, value2, value3, value4, value5, 0, 0);
}
