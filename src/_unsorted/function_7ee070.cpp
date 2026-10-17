struct Object50;
struct Object40;

struct Object50 {
    unsigned char reserved0[1];
};

struct Object40 {
    unsigned char reserved0[1];
};

extern "C" int function_7ee750(void *, void *, int, int);

extern "C" int function_7ee070(Object40 *object40, Object50 *object50, int value) {
    return function_7ee750(object40, object50, value, 0);
}
