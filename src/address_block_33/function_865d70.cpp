struct Object;

struct Object {
    unsigned char reserved0[0x40];
    void* field_40;
};

extern "C" int function_7f43e0(void *, void *, void *, void *, void *);

extern "C" int function_865d70(Object *object, void * value, void * value2, void * value3, void * value4) {
    return function_7f43e0(value, value2, value3, object->field_40, value4);
}
