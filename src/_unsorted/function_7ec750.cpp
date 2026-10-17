struct Object32;
struct Object30;

struct Object32 {
    unsigned char reserved0[0x28];
    Object30* field_28;
};

struct Object30 {
    unsigned char reserved0[1];
};

extern "C" int function_807020(void *, void *);

extern "C" int function_7ec750(Object32 *object32, void * value) {
    return function_807020(object32->field_28, value);
}
