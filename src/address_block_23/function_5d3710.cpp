struct object_a {
    void * field_0;
};
extern "C" int function_5d2c00(void *);

extern "C" int function_5d3710(object_a* object) {
    return function_5d2c00(object->field_0);
}
