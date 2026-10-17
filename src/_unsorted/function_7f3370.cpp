struct Object11;
struct Object13;
struct Object12;
struct Object10;

struct Object11 {
    unsigned char reserved0[1];
};

struct Object13 {
    unsigned char reserved0[1];
};

struct Object12 {
    unsigned char reserved0[1];
};

struct Object10 {
    unsigned char reserved0[1];
};

extern "C" int function_7f3790(void *, void *, void *, void *, void *, int);

extern "C" unsigned int function_7f3370(Object10 *object10, Object11 *object11, Object12 *object12, Object13 *object13) {
    return function_7f3790(object10, object11, object12, object13, 0, 0);
}
