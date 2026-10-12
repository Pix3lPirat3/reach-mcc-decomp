struct Object2;
struct Object3;

struct Object2 {
    short field_0;
};

struct Object3 {
    unsigned char reserved0[0x10];
    void *field_10;
};

extern "C" void function_35c3c(void *, long long, long long);

extern "C" char function_a5bc0(Object3 *object3, Object2 *object2, int value) {
    if (object3->field_10) {
        function_35c3c(object2, (long long)object3->field_10, value);
        return 1;
    }
    object2->field_0 = 0;
    return 1;
}
