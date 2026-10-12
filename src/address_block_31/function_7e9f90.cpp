struct Object4;
struct Object3;

struct Object4 {
    unsigned char reserved0[0x28];
    Object3* field_28;
};

struct Object3 {
    unsigned char reserved0[1];
};

extern "C" int function_7c5dc0(void *);

extern "C" int function_7e9f90(Object4 *object4) {
    return function_7c5dc0(object4->field_28);
}
