struct Object6;
struct Object5;
struct Object3;

struct Object6 {
    unsigned char reserved0[0x230];
    unsigned int field_230;
    unsigned int field_234;
    unsigned int field_238;
    unsigned int field_23c;
};

struct Object5 {
    Object3* field_0;
    unsigned char reserved8[0x228];
    unsigned int field_230;
    unsigned int field_234;
    unsigned int field_238;
    unsigned int field_23c;
};

struct Object3 {
    unsigned char reserved0[8];
};

extern "C" unsigned char data_a39698;
extern "C" void * function_34c36c(void *, void *);

extern "C" Object5 * function_30c55c(Object5 *object5, Object6 *object6) {
    function_34c36c(object5, object6);
    object5->field_0 = (Object3 *)&data_a39698;
    object5->field_230 = object6->field_230;
    object5->field_234 = object6->field_234;
    object5->field_238 = object6->field_238;
    object5->field_23c = object6->field_23c;
    return object5;
}
