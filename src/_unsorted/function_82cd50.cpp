struct Object33;
struct Object30;

struct Object33 {
    unsigned char reserved0[1];
};

struct Object30 {
    unsigned char reserved0[1];
};

extern "C" void * function_79f250(void *);
extern "C" int function_855c40(void *, void *, unsigned long long);

extern "C" int function_82cd50(Object30 *object30, Object33 *object33, unsigned long long value) {
    return function_855c40(function_79f250(object30), object33, value);
}
