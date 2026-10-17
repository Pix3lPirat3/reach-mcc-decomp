extern "C" int function_2f7a70(void *);
extern "C" char function_2f7c0c(void *, int, int, long long);

extern "C" char function_31668c(void *object7, int value, int value2, long long value3) {
    int result = 0;
    if (value < function_2f7a70(object7)) {
        result = function_2f7c0c(object7, value, value2, value3);
    }
    return (char)(result);
}
