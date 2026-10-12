struct Object2;
struct Object;

struct Object2 {
    unsigned char reserved0[1];
};

struct Object {
    unsigned char reserved0[1];
};

extern "C" int function_7a1c70(void *, void *, unsigned long long);

extern "C" int function_7a18c0(Object *object, Object2 *object2, unsigned long long value) {
    return function_7a1c70(object, object2, value);
}
