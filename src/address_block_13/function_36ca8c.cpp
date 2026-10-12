struct Object7;

struct Object7 {
    unsigned char reserved0[0x70];
    unsigned int field_70;
};

extern "C" int function_2f7a70(void *);

extern "C" int function_36ca8c(Object7 *object7) {
    int local1 = (function_2f7a70(object7));
    if (object7->field_70 > 13) {
        return (local1);
    }
    return (local1 + 3);
}
