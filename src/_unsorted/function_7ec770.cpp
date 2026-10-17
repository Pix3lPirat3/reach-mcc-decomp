struct Object43;
struct Object40;
struct Object30;

struct Object43 {
    unsigned char reserved0[0x28];
    Object30* field_28;
};

struct Object40 {
    unsigned char reserved0[1];
};

struct Object30 {
    unsigned char reserved0[1];
};

extern "C" int function_7ecba0(void *, void *, unsigned int, int);

extern "C" int function_7ec770(Object40 *object40, Object43 *object43, int value) {
    return function_7ecba0(object40, object43->field_28, value, 2);
}
