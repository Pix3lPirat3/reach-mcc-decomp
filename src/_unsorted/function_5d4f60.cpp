struct object_a {
    void * field_0;
};
extern "C" int function_5d4190(void *);

extern "C" int function_5d4f60(object_a* object) {
    return function_5d4190(object->field_0);
}
