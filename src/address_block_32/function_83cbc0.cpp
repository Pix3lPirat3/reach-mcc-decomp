struct Object33;
struct Object34;
struct Object2;

struct Object33 {
    unsigned char reserved0[1];
};

struct Object34 {
    unsigned char reserved0[1];
};

struct Object2 {
    unsigned char reserved0[0x18];
    Object2* field_18;
};

extern "C" void* function_7fd290(void *, int, int, void *, int);

extern "C" int function_83cbc0(Object2* object35, int value, int value2, Object34 *object34, int value3) {
    return function_7fd290((Object33 *)&object35->field_18, value, value2, object34, value3) != 0;
}
