struct Object3;
struct Object2;

struct Object3 {
    unsigned char reserved0[0x40];
    Object2* field_40;
};

struct Object2 {
    unsigned char reserved0[1];
};

extern "C" int function_7a60a0(void *);

extern "C" int function_83da80(Object3 *object3) {
    return (int)function_7a60a0(object3->field_40) - 1;
}
