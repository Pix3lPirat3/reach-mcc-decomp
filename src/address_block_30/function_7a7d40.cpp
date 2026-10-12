struct Object11;
struct Object2;

struct Object11 {
    unsigned char reserved0[0x18];
    Object2* field_18;
};

struct Object2 {
    unsigned char reserved0[1];
};

extern "C" int function_7a60a0(void *);

extern "C" int function_7a7d40(Object11 *object11) {
    return function_7a60a0(object11->field_18);
}
