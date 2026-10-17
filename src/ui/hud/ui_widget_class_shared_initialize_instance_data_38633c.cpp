struct Object6;
struct Object3;

struct Object6 {
    Object3* field_0;
    unsigned char reserved8[0x140];
    unsigned long long field_148;
    unsigned long long field_150;
    unsigned int field_158;
    unsigned int field_15c;
};

struct Object3 {
    unsigned char reserved0[8];
};

extern "C" unsigned char data_a378f0;
extern "C" void * function_2f7144(void *, void *, void *);

extern "C" Object6 * function_38633c(Object6 *object6, void * value, void * value2) {
    function_2f7144(object6, value, value2);
    object6->field_148 = 0;
    object6->field_150 = 0;
    object6->field_0 = (Object3 *)&data_a378f0;
    object6->field_158 = 2;
    object6->field_15c = 0x28000B;
    return object6;
}
