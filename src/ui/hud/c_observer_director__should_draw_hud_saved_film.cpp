struct Object;

struct Object {
    unsigned char reserved0[0x194];
    int field_194;
};

extern "C" char function_5b0f8(void *);

extern "C" char function_1db47c(Object *object) {
    int result = 0;
    if (!function_5b0f8(0)) {
        result = object->field_194 == 0;
    }
    return (char)(result);
}
