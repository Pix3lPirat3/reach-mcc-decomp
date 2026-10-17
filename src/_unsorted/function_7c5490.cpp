struct Object3;
struct Object2;

struct Object3 {
    unsigned char reserved0[8];
    Object2* field_8;
};

struct Object2 {
    unsigned char reserved0[1];
};

extern "C" int function_7a60a0(void *);

extern "C" int function_7c5490(Object3 *object3) {
    return function_7a60a0(object3->field_8);
}
