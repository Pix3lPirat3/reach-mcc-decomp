struct Object30;
struct Object33;
struct Object32;

struct Object30 {
    unsigned char reserved0[1];
};

struct Object33 {
    unsigned char reserved0[1];
};

struct Object32 {
    unsigned char reserved0[1];
};

extern "C" int function_7c6430(void *, void *, long long);
extern "C" long long function_79f260(void *);

extern "C" int function_7d55a0(Object30 *object30, Object33 *object33, long long value) {
    return function_7c6430((Object32 *)*(unsigned long long *)(function_79f260(object30) + 40), object33, value) != 0;
}
