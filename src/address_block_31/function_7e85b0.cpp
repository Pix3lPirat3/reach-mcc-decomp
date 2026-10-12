struct Object2;
struct Object6;

struct Object2 {
    unsigned char reserved0[1];
};

struct Object6 {
    unsigned char reserved0[0x68];
    Object2* field_68;
};

extern "C" long long function_7fd350(void *, int);

extern "C" long long function_7e85b0(Object6 *object6, int value) {
    return function_7fd350(object6->field_68, value);
}
