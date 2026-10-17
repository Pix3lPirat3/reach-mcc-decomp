struct object_a {
    void * field_0;
};
extern "C" int function_5ad840(void *, int);

extern "C" int function_5adeb0(object_a* object, int value2) {
    return function_5ad840(object->field_0, value2);
}
