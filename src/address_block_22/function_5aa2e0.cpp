struct object_a {
    void * field_0;
};
extern "C" int function_5a9170(void *);

extern "C" int function_5aa2e0(object_a* object) {
    return function_5a9170(object->field_0);
}
