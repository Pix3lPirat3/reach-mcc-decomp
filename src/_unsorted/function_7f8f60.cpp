struct Object3;
struct Object2;

struct Object3 {
    unsigned char reserved0[1];
};

struct Object2 {
    unsigned char reserved0[1];
};

extern "C" int function_7f8f90(void *, void *, int, int, int, int, int);

extern "C" int function_7f8f60(Object2 *object2, Object3 *object3, int value, int value2, int value3) {
    return function_7f8f90(object2, object3, value, value2, value3, 0, 0);
}
