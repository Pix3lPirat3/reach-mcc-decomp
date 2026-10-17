struct Object6;
struct Object4;
struct Object5;

struct Object6 {
    unsigned char reserved0[8];
    Object4* field_8;
};

struct Object4 {
    unsigned char reserved0[1];
};

struct Object5 {
    unsigned char reserved0[1];
};

extern "C" long long function_7fd550(void *, void *, int);

extern "C" long long function_7cd700(Object6 *object6, Object5 *object5, int value) {
    return function_7fd550(object6->field_8, object5, value);
}
