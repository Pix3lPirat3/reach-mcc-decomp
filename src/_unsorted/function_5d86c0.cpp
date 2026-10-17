struct object_a {
    void * field_0;
};
extern "C" int function_5d8140(void *, int);

extern "C" int function_5d86c0(object_a* object, int value2) {
    return function_5d8140(object->field_0, value2);
}
