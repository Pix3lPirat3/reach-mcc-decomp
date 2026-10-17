struct object_a {
    void * field_0;
};
extern "C" int function_5da0c0(void *);

extern "C" int function_5dabb0(object_a* object) {
    return function_5da0c0(object->field_0);
}
