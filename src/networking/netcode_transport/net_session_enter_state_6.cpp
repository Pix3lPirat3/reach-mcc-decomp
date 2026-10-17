struct Object5;

struct Object5 {
    unsigned char reserved0[0x4464];
    int field_4464;
    unsigned char reserved4468[0x5ca90];
    unsigned int field_60ef8;
};

extern "C" void function_396020(void *, unsigned char);
extern "C" void function_4025f8(void *, int, int, void *);

extern "C" void function_4029a0(Object5 *object5) {
    if ((object5->field_60ef8 - 6) <= 3) {
        return (function_4025f8(object5, 6, 0, 0));
    }
    if (object5->field_60ef8) {
        function_396020(object5, 1);
        *(unsigned int *)((char *)object5 + 64) = object5->field_4464;
        return (function_4025f8(object5, 6, 0, 0));
    }
    return (function_4025f8(object5, 6, 0, 0));
}
