struct Object;

struct Object {
    unsigned char reserved0[1];
};

extern "C" int function_7e4db0(void *, long long, int);

extern "C" int function_7e4bb0(Object *object, int value) {
    return function_7e4db0(object, value, 2);
}
