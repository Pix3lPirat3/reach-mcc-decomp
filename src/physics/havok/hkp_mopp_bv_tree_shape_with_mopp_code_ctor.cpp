struct Object100;
struct Object98;
struct Object101;
struct Object12;

struct Object100 {
    unsigned char reserved0[1];
};

struct Object98 {
    Object12* field_0;
    unsigned char reserved8[0x48];
    unsigned char field_50[16];
};

struct Object101 {
    unsigned char reserved0[8];
};

struct Object12 {
    unsigned char reserved0[8];
    unsigned char reserved8[0x48];
    unsigned char reserved50[8];
};

extern "C" unsigned char data_a2c9b8;
extern "C" void * function_884100(void *, void *, void *);
extern "C" void * function_1c3c88(void *, void *);

extern "C" Object98 * function_884630(Object98 *object98, Object12 *object12, Object100 *object100) {
    function_884100(object98, object12, object100);
    object98->field_0 = (Object12 *)&data_a2c9b8;
    function_1c3c88((Object101 *)object98->field_50, object12);
    return object98;
}
