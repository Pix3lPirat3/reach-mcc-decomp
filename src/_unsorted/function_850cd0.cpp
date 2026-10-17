struct Object3;
struct Object2;
struct Object;

struct Object3 {
    unsigned char reserved0[1];
};

struct Object2 {
    unsigned char reserved0[0x110];
    unsigned int field_110;
};

struct Object {
    unsigned char reserved0[1];
};

extern "C" void function_8685f0(int, void *, void *, void *);

extern "C" void function_850cd0(Object *object, Object3 *object3, Object2 *object2) {
    return function_8685f0(object2->field_110, object, object2, object3);
}
