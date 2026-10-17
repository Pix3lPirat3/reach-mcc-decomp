struct Object30;

struct Object30 {
    unsigned char reserved0[1];
};

extern "C" void * function_79f250(void *);
extern "C" int function_7a3980(void *, void *, unsigned long long);

extern "C" int function_7fc060(Object30 *object30, void * value, unsigned long long value2) {
    return function_7a3980(function_79f250(object30), value, value2);
}
