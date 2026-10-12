struct Object2;
struct Object3;

struct Object2 {
    unsigned char reserved0[1];
};

struct Object3 {
    unsigned char reserved0[1];
};

extern "C" int function_7f7200(void *, int, void *, int, int, void *, int, void *, void *);

extern "C" unsigned int function_7f71b0(Object2 *object2, int value, Object3 *object3, int value2, int value3, void * value4, int value5) {
    return function_7f7200(object2, value, object3, value2, value3, value4, value5, 0, 0);
}
