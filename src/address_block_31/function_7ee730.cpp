struct Object9;
struct Object7;

struct Object9 {
    unsigned char reserved0[0x28];
    Object7* field_28;
};

struct Object7 {
    unsigned char reserved0[1];
};

extern "C" int function_81ed80(void *, void *);

extern "C" int function_7ee730(Object9 *object9) {
    return function_81ed80(object9->field_28, 0);
}
