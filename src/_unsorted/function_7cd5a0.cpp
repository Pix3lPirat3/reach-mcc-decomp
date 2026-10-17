struct Object2;
struct Object5;

struct Object2 {
    unsigned char reserved0[1];
};

struct Object5 {
    unsigned char reserved0[0x10];
    Object2* field_10;
};

extern "C" long long function_7fd480(void *, int);

extern "C" long long function_7cd5a0(Object5 *object5, int value) {
    return function_7fd480(object5->field_10, value);
}
