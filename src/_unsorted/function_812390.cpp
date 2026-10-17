struct Object4;
struct Object3;
struct Object2;

struct Object4 {
    unsigned char reserved0[1];
};

struct Object3 {
    unsigned char reserved0[1];
};

struct Object2 {
    unsigned char reserved0[1];
};

extern "C" int function_814ea0(void *, void *, void *);

extern "C" int function_812390(Object2 *object2, Object4 *object4, Object3 *object3) {
    return function_814ea0(object2, object3, object4) == -1;
}
