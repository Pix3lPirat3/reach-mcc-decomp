struct Object5;
struct Object3;

struct Object5 {
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
extern "C" void * function_2d4c4c(void *, void *);

extern "C" Object5 * function_2f71c0(Object5 *object5, void * value) {
    function_2d4c4c(object5, value);
    object5->field_0 = (Object3 *)&data_a36290;
    object5->field_130 = 0;
    object5->field_138 = 0;
    object5->field_140 = 0;
    return object5;
}
