struct Object4;
struct Object3;
struct Object2;
struct Object;

struct Object4 {
    unsigned char reserved0[0x28];
    Object* field_28;
};

struct Object3 {
    unsigned char reserved0[1];
};

struct Object2 {
    unsigned char reserved0[1];
};

struct Object {
    unsigned char reserved0[0x18];
    unsigned int field_18;
};

extern "C" long long function_817eb0(void *, void *);

extern "C" long long function_7dd870(Object4 *object4, Object3 *object3, long long value) {
    Object *local1;
    local1 = object4->field_28;
    *(unsigned long long *)value = 0x10;
    if (object3 == 0) {
        return 1;
    }
    function_817eb0((Object2 *)&local1->field_18, object3);
    return 1;
}
