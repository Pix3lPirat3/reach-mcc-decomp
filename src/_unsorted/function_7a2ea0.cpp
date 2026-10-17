struct Object;
struct Object2;

struct Object {
    unsigned char reserved0[1];
};

struct Object2 {
    unsigned char reserved0[1];
};

extern "C" int function_7a30e0(void *, void *);

extern "C" int function_7a2ea0(Object *object, Object2 *object2) {
    return function_7a30e0(object, object2);
}
