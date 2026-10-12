struct object_b {
    unsigned char reserved0[0x20];
    void * field_20;
};
extern "C" float function_785bf0(void *, void *);

extern "C" float function_785b60(unsigned char * value, object_b* source) {
    return function_785bf0(value - 0x20, source->field_20);
}
