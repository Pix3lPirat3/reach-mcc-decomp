struct Object7;
struct Object6;

struct Object7 {
    unsigned char reserved0[0x28];
    Object6* field_28;
};

struct Object6 {
    unsigned char reserved0[1];
};

extern "C" int function_7a7cd0(void *);

extern "C" int function_7ee030(Object7 *object7) {
    return function_7a7cd0(object7->field_28);
}
