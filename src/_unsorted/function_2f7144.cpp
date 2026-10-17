struct Object82;
struct Object3;

struct Object82 {
    Object3* field_0;
    unsigned char reserved8[0x128];
    unsigned long long field_130;
    unsigned long long field_138;
    unsigned int field_140;
};

struct Object3 {
    unsigned char reserved0[8];
};

extern "C" unsigned char data_a36290;
extern "C" void * function_2d4b60(void *, void *, void *, int);

extern "C" Object82 * function_2f7144(Object82 *object82, void * value, void * value2) {
    function_2d4b60(object82, value, value2, 0x200);
    object82->field_0 = (Object3 *)&data_a36290;
    object82->field_130 = 0;
    object82->field_138 = 0;
    object82->field_140 = 0;
    return object82;
}
