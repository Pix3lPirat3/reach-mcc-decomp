struct Object5;
struct Object3;
struct Object4;

struct Object5 {
    unsigned char reserved0[0x40];
    Object3* field_40;
};

struct Object3 {
    unsigned char reserved0[1];
};

struct Object4 {
    unsigned char reserved0[1];
};

extern "C" int function_8412f0(void *, void *, void *, void *, void *);

extern "C" int function_83e8e0(Object5 *object5, Object3 *object3, Object3 *object32, Object3 *object33, Object4 *object4) {
    return function_8412f0(object3, object32, object33, object5->field_40, object4);
}
