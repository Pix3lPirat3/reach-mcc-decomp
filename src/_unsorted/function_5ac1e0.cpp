struct object_a {
    void * field_0;
};
extern "C" int function_5aa790(void *);

extern "C" int function_5ac1e0(object_a* object) {
    return function_5aa790(object->field_0);
}
