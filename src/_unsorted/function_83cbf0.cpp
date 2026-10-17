struct Object2;
struct Object33;

struct Object2 {
    unsigned char reserved0[1];
};

struct Object33 {
    unsigned char reserved0[0x18];
    Object2* field_18;
};

extern "C" int function_7fd3a0(void *, int, int);

extern "C" int function_83cbf0(Object33 *object33, int value, int value2) {
    return function_7fd3a0(object33->field_18, value, value2);
}
