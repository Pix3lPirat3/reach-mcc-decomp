struct Object3;
struct Object2;

struct Object3 {
    unsigned char reserved0[1];
};

struct Object2 {
    unsigned char reserved0[1];
};

extern "C" int function_86ac30(void *, void *, void *, int);

extern "C" int function_86a870(Object2 *object2, Object3 *object3, int value) {
    return function_86ac30(0, object2, object3, value);
}
