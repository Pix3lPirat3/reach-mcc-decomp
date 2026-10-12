struct object_a {
    void * field_0;
};
extern "C" int function_5d6ae0(void *, int);

extern "C" int function_5d7340(object_a* object, int value2) {
    return function_5d6ae0(object->field_0, value2);
}
