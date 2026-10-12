struct Object2;
struct Object3;

struct Object2 {
    short field_0;
};

struct Object3 {
    unsigned char reserved0[0x18];
    void *field_18;
};

extern "C" void function_35c3c(void *, long long, long long);

extern "C" char function_a5bec(Object3 *object3, Object2 *object2, int value) {
    if (object3->field_18) {
        function_35c3c(object2, (long long)object3->field_18, value);
        return 1;
    }
    object2->field_0 = 0;
    return 1;
}
