struct Object43;
struct Object40;
struct Object9;
struct Object30;

struct Object43 {
    unsigned char reserved0[0x18];
    Object40* field_18;
    Object30* field_20;
    void * field_28;
};

struct Object40 {
    unsigned char reserved0[1];
};

struct Object9 {
    unsigned char reserved0[1];
};

struct Object30 {
    unsigned char reserved0[1];
};

extern "C" int function_7f16b0(void *, void *, void *, void *, void *, void *);

extern "C" int function_7c51b0(Object43 *object43) {
    return function_7f16b0(object43->field_18, object43->field_20, object43->field_28, 0, 0, 0);
}
