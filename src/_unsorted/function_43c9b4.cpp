struct Object4;

struct Object4 {
    unsigned char reserved0[9];
    unsigned char field_9;
};

extern "C" char function_54214(void *, int);

extern "C" int function_43c9b4(Object4 *object4, int value, void *object3) {
    int result = 0;
    if (function_54214(object3, value) != (char)object4->field_9) {
        result = 1;
    }
    return result;
}
