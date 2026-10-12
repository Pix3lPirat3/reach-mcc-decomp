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

extern "C" int function_863e50(Object3 *object3) {
    return function_7a60a0(object3->field_40);
}
