struct Object32;
struct Object30;

struct Object32 {
    unsigned char reserved0[0x28];
    Object30* field_28;
};

struct Object30 {
    unsigned char reserved0[1];
};

extern "C" int function_8059c0(void *);

extern "C" int function_7ec4b0(Object32 *object32) {
    return function_8059c0(object32->field_28);
}
