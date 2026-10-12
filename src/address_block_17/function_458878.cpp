extern "C" int function_dd10c(void *, int);
extern "C" char function_54214(void *, int);

extern "C" char function_458878(long long, int value, char *object2, void *object3) {
    int local1;
    local1 = function_54214(object3, value) != 0 ? 0xFFFFFFFF : function_dd10c(object3, 4);
    *(unsigned short *)object2 = (unsigned short)(local1);
    return 1;
}
