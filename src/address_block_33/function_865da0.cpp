struct Object;

struct Object {
    unsigned char reserved0[0x40];
    char* field_40;
};

extern "C" int function_7f44a0(void *, void *, void *, void *);

extern "C" int function_865da0(Object *object, void * value, void * value2, void * value3) {
    return function_7f44a0(value, value2, object->field_40, value3);
}
