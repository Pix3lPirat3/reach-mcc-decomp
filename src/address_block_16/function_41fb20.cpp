struct Object141;

struct Object141 {
    unsigned char reserved0[0x18];
    void *field_18;
};

extern "C" char function_395090(void *, int, int);
extern "C" int function_395d10(void *, void *);

extern "C" char function_41fb20(Object141 *object141, void *object140, int value) {
    char result = 0;
    int local1 = function_395d10(object141->field_18, object140);
    if (local1 != -1) {
        result = function_395090(object141->field_18, local1, value);
    }
    return result;
}
