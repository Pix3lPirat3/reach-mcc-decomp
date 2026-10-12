struct object_a {
    void * field_0;
};
extern "C" int function_625c10(void *);

extern "C" int function_626910(object_a* object) {
    return function_625c10(object->field_0);
}
