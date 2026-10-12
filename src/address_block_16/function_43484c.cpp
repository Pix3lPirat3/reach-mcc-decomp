extern "C" char function_4390b4(long long, int, void *, int, void *);
extern "C" void *function_78932a(void *, int, unsigned long long);

extern "C" char function_43484c(long long value, int, void *object, int, void *object2) {
    char result = 0;
    function_78932a(object2, 0, 0x230);
    if (function_4390b4(value, 20, object, 0x224, object2)) {
        result = 1;
    }
    return result;
}
