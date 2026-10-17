struct Object2;
struct Object6;

struct Object2 {
    unsigned char reserved0[1];
};

struct Object6 {
    unsigned char reserved0[0x68];
    Object2* field_68;
};

extern "C" int function_7fd3a0(void *, int, int);

extern "C" int function_7e85d0(Object6 *object6, int value, int value2) {
    return function_7fd3a0(object6->field_68, value, value2);
}
