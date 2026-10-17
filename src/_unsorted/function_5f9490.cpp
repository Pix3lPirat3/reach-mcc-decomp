struct object_a {
    void * field_0;
};
extern "C" int function_5f8900(void *);

extern "C" int function_5f9490(object_a* object) {
    return function_5f8900(object->field_0);
}
