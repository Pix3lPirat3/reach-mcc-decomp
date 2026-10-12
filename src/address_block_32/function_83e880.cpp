struct Object6;
struct Object3;
struct Object4;
struct Object5;

struct Object6 {
    unsigned char reserved0[0x48];
    unsigned int field_48;
};

struct Object3 {
    unsigned char reserved0[1];
};

struct Object4 {
    unsigned char reserved0[1];
};

struct Object5 {
    unsigned char reserved0[1];
};

extern "C" int function_841c00(void *, void *, void *, void *, void *);

extern "C" int function_83e880(Object6 *object6, Object3 *object3, Object3 *object32, Object3 *object33, Object5 *object5) {
    return function_841c00(object3, object32, object33, (Object4 *)&object6->field_48, object5);
}
