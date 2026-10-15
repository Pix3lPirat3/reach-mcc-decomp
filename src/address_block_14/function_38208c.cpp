struct Object82;
struct Object3;

struct Object82 {
    Object3* field_0;
    unsigned char reserved8[0x68];
    unsigned long long field_70;
    unsigned short field_78;
};

struct Object3 {
    unsigned char reserved0[8];
};

extern "C" unsigned char data_a360d0;
extern "C" void * function_2f79cc(void *, void *, void *);

extern "C" Object82 * function_38208c(Object82 *object82, void * value, void * value2) {
    function_2f79cc(object82, value, value2);
    object82->field_0 = (Object3 *)&data_a360d0;
    object82->field_70 = 0;
    object82->field_78 = 0;
    return object82;
}
