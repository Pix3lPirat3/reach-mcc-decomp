struct Object9;
struct Object8;

struct Object9 {
    unsigned char reserved0[1];
};

struct Object8 {
    unsigned char reserved0[1];
};

extern "C" void function_84b370(void *, int, long long);
extern "C" long long function_79eb80(void *);
extern "C" int function_79eba0(void *);

extern "C" long long function_828680(Object9 *object9, long long value) {
    int local1;
    local1 = function_79eba0(object9);
    function_84b370((Object8 *)function_79eb80(object9), local1, value);
    return 1;
}
