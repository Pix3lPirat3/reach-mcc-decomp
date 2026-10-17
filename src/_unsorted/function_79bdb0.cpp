struct Object8;
struct Object6;

struct Object8 {
    unsigned char reserved0[1];
};

struct Object6 {
    unsigned char reserved0[1];
};

extern "C" int function_79b7d0(void *, void *, void *, void *, void *, int);

extern "C" unsigned int function_79bdb0(Object8 *object8, Object6 *object6, void * value, void * value2, void * value3) {
    return function_79b7d0(object8, object6, value, value2, value3, 0);
}
