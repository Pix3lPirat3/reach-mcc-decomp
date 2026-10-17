struct object_b {
    unsigned int field_0;
};
extern "C" void function_1be1fc(void *, int, int);

extern "C" void function_1be15c(void * value, object_b* source) {
    function_1be1fc(value, source->field_0, 0);
}
