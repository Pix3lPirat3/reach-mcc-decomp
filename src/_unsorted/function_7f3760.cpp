struct Object3;
struct Object2;

struct Object3 {
    unsigned char reserved0[0x38];
    Object2* field_38;
};

struct Object2 {
    unsigned char reserved0[1];
};

extern "C" void function_7b6410(void *);

extern "C" long long function_7f3760(Object3 *object3) {
    function_7b6410(object3->field_38);
    return 1;
}
