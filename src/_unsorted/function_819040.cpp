struct Object;

struct Object {
    unsigned char reserved0[4];
    int field_4;
};

extern "C" int function_7e3660(void *, void *);

extern "C" int function_819040(Object *object) {
    return (object->field_4 != 23 ? 0 : function_7e3660(0, object));
}
