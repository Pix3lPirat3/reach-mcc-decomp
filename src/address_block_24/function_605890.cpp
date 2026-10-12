struct object_a {
    void * field_0;
};
extern "C" int function_605160(void *);

extern "C" int function_605890(object_a* object) {
    return function_605160(object->field_0);
}
