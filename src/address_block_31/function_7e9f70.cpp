struct Object3;
struct Object4;
struct Object2;

struct Object3 {
    unsigned char reserved0[8];
    Object2* field_8;
};

struct Object4 {
    unsigned char reserved0[0x28];
    Object3* field_28;
};

struct Object2 {
    unsigned char reserved0[1];
};

extern "C" int function_7a60a0(void *);

extern "C" int function_7e9f70(Object4 *object4) {
    return function_7a60a0(object4->field_28->field_8);
}
