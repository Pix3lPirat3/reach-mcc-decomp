struct Object33;
struct Object30;

struct Object33 {
    unsigned char reserved0[1];
};

struct Object30 {
    unsigned char reserved0[1];
};

extern "C" long long function_79f260(void *);
extern "C" int function_7fe8d0(void *, long long, long long);

extern "C" int function_7d9d20(Object30 *object30, long long value, long long value2) {
    return function_7fe8d0((Object33 *)*(unsigned long long *)(*(unsigned long long *)(function_79f260(object30) + 40) + 32), value, value2) != 0;
}
