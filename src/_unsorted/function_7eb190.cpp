struct Object44;
struct Object43;
struct Object40;

struct Object44 {
    unsigned char reserved0[0x28];
    Object43* field_28;
};

struct Object43 {
    unsigned char reserved0[1];
};

struct Object40 {
    unsigned char reserved0[1];
};

extern "C" int function_7ebc60(void *, void *, int, int);

extern "C" int function_7eb190(Object40 *object40, Object44 *object44, int value) {
    return function_7ebc60(object40, object44->field_28, value, 2);
}
