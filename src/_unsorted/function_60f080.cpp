struct object_a {
    void * field_0;
};
extern "C" int function_60de10(void *, int);

extern "C" int function_60f080(object_a* object, int value2) {
    return function_60de10(object->field_0, value2);
}
