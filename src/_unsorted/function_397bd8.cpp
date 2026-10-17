struct object_b {
    unsigned int field_0;
};
extern "C" unsigned char function_397b64(void *, int);

extern "C" unsigned char function_397bd8(void * value, object_b* source) {
    return function_397b64(value, source->field_0);
}
