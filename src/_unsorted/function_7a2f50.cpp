struct Object;

struct Object {
    unsigned char reserved0[1];
};

extern "C" int function_7a3980(void *, void *, unsigned long long);

extern "C" int function_7a2f50(Object *object, void * value, unsigned long long value2) {
    return function_7a3980(object, value, value2);
}
