struct object_b {
    unsigned char reserved0[0x10];
    void * field_10;
};
extern "C" float function_785bf0(void *, void *);

extern "C" float function_785b50(unsigned char * value, object_b* source) {
    return function_785bf0(value - 0x18, source->field_10);
}
