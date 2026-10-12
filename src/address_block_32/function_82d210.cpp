struct Object3;

struct Object3 {
    unsigned char reserved0[1];
};

extern "C" int function_82d490(void *, char);

extern "C" int function_82d210(Object3 *object3) {
    return function_82d490(object3, 6);
}
