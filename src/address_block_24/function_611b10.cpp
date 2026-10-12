struct object_a {
    void * field_0;
};
extern "C" void function_610f30(void *);

extern "C" void function_611b10(object_a* object) {
    function_610f30(object->field_0);
}
