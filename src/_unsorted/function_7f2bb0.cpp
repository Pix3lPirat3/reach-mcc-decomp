struct Object2;

struct Object2 {
    unsigned char reserved0[1];
};

extern "C" int function_7f2c30(int, void *, int, int, int);

extern "C" int function_7f2bb0(long long value, int value2, int value3, int value4) {
    return function_7f2c30(2, (Object2 *)value, value2, value3, value4);
}
