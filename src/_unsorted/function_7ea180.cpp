struct Object45;
struct Object44;
struct Object40;

struct Object45 {
    unsigned char reserved0[0x28];
    Object44* field_28;
};

struct Object44 {
    unsigned char reserved0[1];
};

struct Object40 {
    unsigned char reserved0[1];
};

extern "C" int function_7eaa60(void *, void *, int, int);

extern "C" int function_7ea180(Object40 *object40, Object45 *object45, int value) {
    return function_7eaa60(object40, object45->field_28, value, 0);
}
