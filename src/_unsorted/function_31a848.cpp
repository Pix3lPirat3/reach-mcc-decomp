struct Object4;
struct Object3;

struct Object4 {
    unsigned char reserved0[8];
    void *field_8;
};

struct Object3 {
    unsigned char reserved0[0xa4];
    short field_a4;
};

extern "C" void *function_35c3c(void *, void *, unsigned long long);

extern "C" char function_31a848(Object3 *object3, int, Object4 *object4) {
    if (object4->field_8) {
        function_35c3c(&object3->field_a4, object4->field_8, 128);
        return 1;
    }
    object3->field_a4 = 0;
    return 1;
}
