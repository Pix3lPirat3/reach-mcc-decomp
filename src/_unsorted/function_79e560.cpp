struct Object9;
struct Object8;

struct Object9 {
    unsigned char reserved0[1];
};

struct Object8 {
    unsigned char reserved0[1];
};

extern "C" void function_7b2ac0(void *);
extern "C" long long function_79eb80(void *);

extern "C" long long function_79e560(Object9 *object9) {
    function_7b2ac0((Object8 *)(function_79eb80(object9) + 0x1F8));
    return 1;
}
