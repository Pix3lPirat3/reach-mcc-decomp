struct Object30;

struct Object30 {
    unsigned char reserved0[1];
};

extern "C" void * function_79f250(void *);
extern "C" int function_7a2f50(void *, void *, unsigned long long);

extern "C" int function_7fbfd0(Object30 *object30, void * value, unsigned long long value2) {
    return function_7a2f50(function_79f250(object30), value, value2);
}
